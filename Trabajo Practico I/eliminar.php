<?php
require_once "Empleado.php";
require_once "Fabrica.php";

$legajo=$_GET['legajo'];
$archivo=fopen("archivos/empleados.txt","r");
$empleados="";
$listado=array();
$flag=0;
while(!feof($archivo))
{
    $empleados=trim(fgets($archivo));
    if($empleados)
    {
        $listado=explode("-",$empleados);
        if($listado!=null && $listado[4]==$legajo)
        {
            $emp=new Empleado($listado[0],$listado[1],$listado[2],$listado[3],$listado[4],$listado[5],$listado[6]);
            $emp->SetPathFoto($listado[7]);
            $fabrica=new Fabrica("Sancor");
            $fabrica->TraerDeArchivo("archivos/empleados.txt");
            if($fabrica->EliminarEmpleado($emp)==true)
            {
                $fabrica->GuardarEnArchivo("archivos/empleados.txt");
                unlink($emp->GetPathFoto());
                echo "El empleado ha sido eliminado";
                $flag=1;
                break;
            }
            echo "El empleado no se encuentra en la Fabrica";
            $flag=1;
            break;
        }
    }
    
}
fclose($archivo);
if($flag==0)
{
    echo "El empleado no se encuentra en el archivo";
}
echo"</br>
<a href=../mostrar.php>Listar</a>
<a href=../index.html>Volver al Formulario</a>";
?>