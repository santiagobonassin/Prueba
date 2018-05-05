<?php
session_start();
include "validarSesion.php";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>HTML5 - Listado de Empleados</title>
</head>
<body>
    <h2>Listado de Empleados</h2>
    <table>
        <tr>
            <td>
                <h4>Info</h4>
            </td>
        </tr>
        <tr>
            <td colspan="2"><hr></td>
        </tr>

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
    ?>
    <tr>
        <td>
            <?php echo $empleado->ToString() ?>
        </td>
        <td>
            <a href="eliminar.php/?legajo=<?php echo $emp->GetLegajo()?>">Eliminar</a>
        </td>
    </tr>
    
<?php
}
?>
<tr>
    <td colspan="2"><hr></td>
</tr>
</table>
</body>
</html>
<?php
echo "<a href='index.html'>Formulario</a>";
echo "<br>";
echo "<a href='cerrarSesion.php'>Cerrar Sesion</a>"
?>    
