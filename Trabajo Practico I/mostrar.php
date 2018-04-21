<?php
include_once "Empleado.php";
$archivo=fopen("archivos/empleados.txt","r");
$empleados="";
$listado=array();
while(!feof($archivo))
{
    $empleados=fgets($archivo);
    $empleados=explode("-",$empleados);
    if(trim($empleados[0])!="")
    {
        $emp=new Empleado($empleados[0],$empleados[1],$empleados[2],$empleados[3],$empleados[4],$empleados[5],$empleados[6]);
        array_push($listado,$emp);
    }
}
fclose($archivo);
foreach($listado as $empleado)
{
    echo $empleado->ToString()."<a href=eliminar.php>Eliminar</a>"."<br>";
}
echo "<a href='index.html'>Formulario</a>";
?>