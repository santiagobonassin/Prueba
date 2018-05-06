<?php
include_once "Empleado.php";
include_once "Fabrica.php";
include_once "validarSesion.php";
if(isset($_POST['modificar']))
{
    $fab=new Fabrica("Sancor");
    $lisado=array();
    $fab->TraerDeArchivo("archivos/empleados.txt");
    $lisado=$fab->GetEmpleados();
    foreach($lisado as $emp)
    {
        if($_POST['modificar']==$emp->GetDni())
        {
            ?><
            !DOCTYPE html>
            <html>
                <head>
                    <meta charset="utf-8" />
                    <meta http-equiv="X-UA-Compatible" content="IE=edge">
                    <title>HTML 5 - Formulario Modificar Empleado</title>
                    <meta name="viewport" content="width=device-width, initial-scale=1">
                    <script type="text/javascript" src="javascript/funciones.js"></script>
                </head>
                <body>
                <h2>Modificacion de Empleado</h2>
                <form method="POST" action="administracion.php" enctype="multipart/form-data">
                    <table align="center">
                        <tr>
                            <td><h4>Datos Personales</h4></td>
                        </tr>
                        <tr>
                            <td colspan="2"><hr></td>
                        </tr>
                        <tr>
                            <td>DNI:</td>
                            <td><input type="number" id=txtDni name=txtDni min="1000000"<?php echo "value='".$emp->GetDni()."'";?>readonly></td>
                            <td>
                                <span style="display:none" id="spanDni">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td>Apellido:</td>
                            <td><input type="text" id=txtApellido name=txtApellido <?php echo "value='".$emp->GetApellido()."'";?>></td>
                            <td>
                                <span style="display:none" id="spanApellido">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td>Nombre:</td>
                            <td><input type="text" id=txtNombre name=txtNombre <?php echo "value='".$emp->GetNombre()."'";?>></td>
                            <td>
                                <span style="display:none" id="spanNombre">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td>Sexo:</td>
                            <td>
                                <select name="cboSexo" id="cboSexo" name="cboSexo">
                                    <option value="---">Seleccione</option>
                                    <option value="M" 
                                    <?php 
                                    if($emp->GetSexo()=="M")
                                    {
                                        echo "selected";
                                    }
                                    ?>
                                    >Masculino</option>
                                    <option value="F"
                                    <?php 
                                    if($emp->GetSexo()=="F")
                                    {
                                        echo "selected";
                                    }
                                    ?>
                                    >Femenino</option>
                                </select>
                            </td>
                            <td>
                                <span style="display:none" id="spanSexo">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td><h4>Datos Laborales</h4></td>
                        </tr>
                        <tr>
                            <td colspan="2"><hr></td>
                        </tr>
                        <tr>
                            <td>Legajo:</td>
                            <td><input type="number" id=txtLegajo name=txtLegajo <?php echo "value='".$emp->GetLegajo()."'";?>readonly></td>
                            <td>
                                <span style="display:none" id="spanLegajo">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td>Sueldo:</td>
                            <td><input type="number" id=txtSueldo name=txtSueldo step="500"<?php echo "value='".$emp->GetSueldo()."'";?>></td>
                            <td>
                                <span style="display:none" id="spanSueldo">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td>Turno:</td>
                        </tr>
                        <tr>
                            <td align="right"><input type="radio" value="mañana" id=rdoTurnoMañana name=rdoTurno 
                            <?php 
                                    if($emp->GetTurno()=="mañana")
                                    {
                                        echo "checked";
                                    }
                            ?>>Mañana</td>

                        </tr>
                        <tr>
                            <td align="right"><input type="radio" value="tarde" id=rdoTurnoTarde name=rdoTurno
                            <?php 
                                    if($emp->GetTurno()=="tarde")
                                    {
                                        echo "checked";
                                    }
                            ?>>Tarde</td>                
                        </tr>
                        <tr>
                            <td align="right"><input type="radio" value="noche" id=rdoTurnoNoche name=rdoTurno
                            <?php 
                                    if($emp->GetTurno()=="noche")
                                    {
                                        echo "checked";
                                    }
                            ?>>Noche</td>
                        </tr>
                        <tr>
                            <td colspan="2"><hr></td>
                        </tr>
                        <tr>
                            <td>
                                Foto:
                            </td>
                            <td>
                                <input type="file" name="foto" id="foto">
                                <span style="display:none" id="spanFoto">*</span>
                            </td>
                        </tr>
                        <tr>
                            <td colspan="2">
                                <hr>
                            </td>
                        </tr>
                        <tr>
                            <td align="right" colspan="2"><input type="reset" value="Limpiar"></td>
                        </tr>
                        <tr>
                            <td align="right" colspan="2"><button type="submit" name="btnEnviar" id="btnEnviar" onclick="return AdministrarValidaciones()">Modificar</button></td>
                            <td><input type="hidden" name="hdnModificar"></td>
                        </tr>
                    </table>
                </form>
                <a href="./cerrarSesion.php">Cerrar Sesion</a>
            </body>
            </html>
            <?php
        break;
        }
    }
}
else
{
    ?>
        <!DOCTYPE html>
        <html>
        <head>
            <meta charset="utf-8" />
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <title>HTML 5 - Formulario Alta Empleado</title>
            <meta name="viewport" content="width=device-width, initial-scale=1">

            <script type="text/javascript" src="javascript/funciones.js"></script>
        </head>
        <body>
            <h2>Alta de Empleados</h2>
            <form method="POST" action="administracion.php" enctype="multipart/form-data">
                <table align="center">
                    <tr>
                        <td><h4>Datos Personales</h4></td>
                    </tr>
                    <tr>
                        <td colspan="2"><hr></td>
                    </tr>
                    <tr>
                        <td>DNI:</td>
                        <td><input type="number" id=txtDni name=txtDni min="1000000"></td>
                        <td>
                            <span style="display:none" id="spanDni">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td>Apellido:</td>
                        <td><input type="text" id=txtApellido name=txtApellido></td>
                        <td>
                            <span style="display:none" id="spanApellido">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td>Nombre:</td>
                        <td><input type="text" id=txtNombre name=txtNombre></td>
                        <td>
                            <span style="display:none" id="spanNombre">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td>Sexo:</td>
                        <td>
                            <select name="cboSexo" id="cboSexo" name="cboSexo">
                                <option value="---">Seleccione</option>
                                <option value="M">Masculino</option>
                                <option value="F">Femenino</option>
                            </select>
                        </td>
                        <td>
                            <span style="display:none" id="spanSexo">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td><h4>Datos Laborales</h4></td>
                    </tr>
                    <tr>
                        <td colspan="2"><hr></td>
                    </tr>
                    <tr>
                        <td>Legajo:</td>
                        <td><input type="number" id=txtLegajo name=txtLegajo></td>
                        <td>
                            <span style="display:none" id="spanLegajo">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td>Sueldo:</td>
                        <td><input type="number" id=txtSueldo name=txtSueldo step="500"></td>
                        <td>
                            <span style="display:none" id="spanSueldo">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td>Turno:</td>
                    </tr>
                    <tr>
                        <td align="right"><input type="radio" value="mañana" id=rdoTurnoMañana name=rdoTurno>Mañana</td>

                    </tr>
                    <tr>
                        <td align="right"><input type="radio" value="tarde" id=rdoTurnoTarde name=rdoTurno>Tarde</td>                
                    </tr>
                    <tr>
                        <td align="right"><input type="radio" value="noche" id=rdoTurnoNoche name=rdoTurno>Noche</td>
                    </tr>
                    <tr>
                        <td colspan="2"><hr></td>
                    </tr>
                    <tr>
                        <td>
                            Foto:
                        </td>
                        <td>
                            <input type="file" name="foto" id="foto">
                            <span style="display:none" id="spanFoto">*</span>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">
                            <hr>
                        </td>
                    </tr>
                    <tr>
                        <td align="right" colspan="2"><input type="reset" value="Limpiar"></td>
                    </tr>
                    <tr>
                        <td align="right" colspan="2"><button type="submit" name="btnEnviar" id="btnEnviar" onclick="return AdministrarValidaciones()">Enviar</button></td>
                    </tr>
                </table>
            </form>
            <a href="./cerrarSesion.php">Cerrar Sesion</a>
        </body>
        </html>
<?php
}
?>





