<?php
include_once "persona.php";
include_once "empleado.php";
include_once "Fabrica.php";
$idiomas=array("Español","Ingles","Frances");
$empleado = new Empleado("Nicolas","Tagliafico",41564568,"M",23745,15000.00,"Tarde");
$empleado2 = new Empleado("Fabricio","Bustos",41564570,"M",23746,15000.00,"Tarde");
$empleado3 = new Empleado("Alan","Franco",41564568,"M",23749,15000.00,"Tarde");
$empleado4 = new Empleado("Martin","Campaña",41564585,"M",23741,15000.00,"Tarde");
$empleado5 = new Empleado("Juan","Sanchez Miño",41564435,"M",23748,15000.00,"Tarde");
$empleado6 = new Empleado("Emanuel","Gigliotti",41564475,"M",23740,15000.00,"Tarde");
echo $empleado->ToString();
echo $empleado->Hablar($idiomas),"<br>";

$fabrica = new Fabrica("Sancor");
if($fabrica->AgregarEmpleado($empleado)==false)
{
    echo "Fabrica Llena","<br>";
}
if($fabrica->AgregarEmpleado($empleado2)==false)
{
    echo "Fabrica Llena","<br>";
}
if($fabrica->AgregarEmpleado($empleado3)==false)
{
    echo "Fabrica Llena","<br>";
}
if($fabrica->AgregarEmpleado($empleado4)==false)
{
    echo "Fabrica Llena","<br>";
}
echo $fabrica->ToString();
if($fabrica->AgregarEmpleado($empleado5)==false)
{
    echo "Fabrica Llena","<br>";
}
echo $fabrica->ToString();
if($fabrica->AgregarEmpleado($empleado5)==false)
{
    echo "Fabrica Llena","<br>";
}
if($fabrica->AgregarEmpleado($empleado6)==false)
{
    echo "Fabrica Llena","<br>";
}
echo "<br>";
echo $fabrica->ToString();
echo $fabrica->CalcularSueldos(),"<br>";

?>