<?php
include_once "Empleado.php";
require_once "Fabrica.php";
if(isset($_FILES['selectFoto']))
{
    echo"-";
    $foto=pathinfo($_FILES['selectFoto']['name']);
    var_dump($_FILES);
    if($foto['extension']!='jpg' && $foto['extension']!='bmp' && $foto['extension']!='gif' && $foto['extension']!='png' && $foto['extension']!='jpeg')
    {
    echo"La imagen tiene una extension no soportada";
    }
    if($_FILES['selectFoto']['size']>1048576)
    {
    echo"El tamaño de la imagen es demasiado grande";
    }
    $ruta="./fotos/".$_POST['txtDni'].".".$_POST['txtApellido'].$foto['extension'];
    if($ruta)
    {   
        echo"La imagen ya existe";
    }
    else
    {
    $emp=new Empleado($_POST['txtNombre'],$_POST['txtApellido'],$_POST['txtDni'],$_POST['cboSexo'],$_POST['txtLegajo'],$_POST['txtSueldo'],$_POST['rdoTurno']);
    $fabrica=new Fabrica("Sancor");
    $fabrica->TraerDeArchivo("archivos/empleados.txt");

    if($fabrica->AgregarEmpleado($emp))
    {
        $fabrica->GuardarEnArchivo("archivos/empleados.txt");
        move_uploaded_file($_FILES['selectFoto']['tmp_name'],$ruta);
        echo "<a href=mostrar.php>Listar</a>";
    }
    else
    {
        echo "<a href=index.php>No se pudo cargar el empleado</a>";   
    }
    }
}
else
{
    echo"ccc";
}
?>