<?php
include_once "Empleado.php";
require_once "Fabrica.php";
$emp=new Empleado($_POST['txtNombre'],$_POST['txtApellido'],$_POST['txtDni'],$_POST['cboSexo'],$_POST['txtLegajo'],$_POST['txtSueldo'],$_POST['rdoTurno']);
$fabrica=new Fabrica("Sancor");
$fabrica->TraerDeArchivo("archivos/empleados.txt");

if($fabrica->AgregarEmpleado($emp))
{
    $fabrica->GuardarEnArchivo("archivos/empleados.txt");
    echo "<a href=mostrar.php>Listar</a>";
}
else
{
    echo "<a href=index.php>No se pudo cargar el empleado</a>";   
}
?>