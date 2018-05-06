<?php

require_once "Fabrica.php";

$foto=pathinfo($_FILES["foto"]["name"]);
$ruta="./fotos/".$_POST['txtDni'].".".$_POST['txtApellido'].".jpg";
if(($foto['extension']!='jpg' && $foto['extension']!='bmp' && $foto['extension']!='gif' && $foto['extension']!='png' && $foto['extension']!='jpeg')||$_FILES["foto"]['size']>1048576||file_exists($ruta))
{
    echo "<a href=index.html>La imagen tiene una extension no soportada o es demasiado grande o ya existe</a>";
}
else
{
    $emp=new Empleado($_POST['txtNombre'],$_POST['txtApellido'],$_POST['txtDni'],$_POST['cboSexo'],$_POST['txtLegajo'],$_POST['txtSueldo'],$_POST['rdoTurno']);
    $fabrica=new Fabrica("Sancor");
    $fabrica->TraerDeArchivo("archivos/empleados.txt");
    $emp->SetPathFoto($ruta);
    if($fabrica->AgregarEmpleado($emp))
    {
        
        $fabrica->GuardarEnArchivo("archivos/empleados.txt");
        
        move_uploaded_file($_FILES["foto"]['tmp_name'],$ruta);
        echo $emp->ToString();
        echo "<a href=mostrar.php>Listar</a>";
    }
    else
    {
        echo "<a href=index.html>No se pudo cargar el empleado</a>";   
    }
}
?>