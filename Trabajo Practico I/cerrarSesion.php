<?php
session_start();
if(isset($_SESSION['DNIEmpleado']))
{
    session_unset();
    session_destroy();
    header("Location: ./Login.html");
}
?>