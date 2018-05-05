<?php
session_start();
if(isset($_POST['txtDNI']) && isset($_POST['txtApellido']))
{
    $dni=$_POST['txtDNI'];
    $apellido=$_POST['txtApellido'];

    $archivo=fopen("archivos/empleados.txt","r");
    $empleado=array();
    $datos;
    if($archivo!=null)
    {
        while(!feof($archivo))
        {
            $empleado=trim(fgets($archivo));
            if($empleado)
            {
                $dato=explode("-",$empleado);
                if($dato[1]==$apellido && $dato[2]==$dni)
                {
                    $_SESSION['DNIEmpleado']=$dni;
                    header("Location: ./mostrar.php");
                }
            }
        }   
    }
    fclose($archivo);
    echo "No se encontro el usuario ingresado"."<br>";
}
echo "</br><a href='login.html'>Volver al Login</a>";
?>