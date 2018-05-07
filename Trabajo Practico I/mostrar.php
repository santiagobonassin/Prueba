<?php
session_start();
include "validarSesion.php";
include_once "Empleado.php";
include_once "Fabrica.php";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <script src="javascript/funciones.js"></script>
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

$fab=new Fabrica("Sancor");
$fab->TraerDeArchivo("archivos/empleados.txt");
$empleados=array();
$empleados=$fab->GetEmpleados();
foreach($empleados as $emp)
{
    ?>
        <tr>
        <td>
            <?php echo $emp->ToString()?>
        </td>
        <td>
            <img src="<?php echo $emp->GetPathFoto() ?>"           
            style="width:90px;height:90px;"/>
        </td>
        <td>
            <a href="eliminar.php/?legajo=<?php echo $emp->GetLegajo()?>">Eliminar</a>
        </td>
        <td>
            <input type="button" value="Modificar" onclick="AdministrarModificar(<?php echo $emp->GetDni(); ?>)">
        </td>
        <td>
            <form action="./index.php" method="POST" id="formulario">
                <input type="hidden" id="modificar" name="modificar">
            </form>
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
