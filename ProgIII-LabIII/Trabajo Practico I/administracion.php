<?php

require_once "Fabrica.php";

$foto=pathinfo($_FILES["foto"]["name"]);
if($foto['extension']!='jpg' && $foto['extension']!='bmp' && $foto['extension']!='gif' && $foto['extension']!='png' && $foto['extension']!='jpeg')
{
    echo "<a href=index.html>La imagen tiene una extension no soportada</a>";
}
if($_FILES["foto"]['size']>1048576)
{
    echo "<a href=index.html>El tamaño de la imagen es demasiado grande</a>";
}
$ruta="./fotos/".$_POST['txtDni'].".".$_POST['txtApellido'].".jpg";
if(file_exists($ruta))
{
    echo "<a href=index.html>La imagen ya existe</a>";
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