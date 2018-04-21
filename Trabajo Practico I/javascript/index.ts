function ValidarCamposVacios(input:string):boolean
{
    if((<HTMLInputElement>document.getElementById(input)).value=="")
    {
        alert("Un campo esta incompleto");
        return false;
    }
    return true;
}
function ValidarRangoNumerico(valor:number,min:number,max:number):boolean
{
    if(valor<min || valor>max)
    {       
        return false;
    }
    return true;
}
function ValidarCombo(valor:string, error:string):boolean
{
    if((<HTMLInputElement>document.getElementById(valor)).value==error)
    {
        alert ("El sexo indicado es invalido, debe elegir Femenino o Masculino");
        return false;
    }
    return true;
}
function ObtenerTurnoSeleccionado():string
{
    if((<HTMLInputElement>document.getElementById("rdoTurnoMañana")).checked)
    {
        return "Mañana";
    }
    else
    {
        if((<HTMLInputElement>document.getElementById("rdoTurnoTarde")).checked)
        {
            return "Tarde";
        }
        else
        {
            if((<HTMLInputElement>document.getElementById("rdoTurnoNoche")).checked)
            {
                return "Noche";
            }
            else
            {
                return "";
            }
        }
    }
}
function ObtenerSueldoMaximo(valor:string):number
{
    if(valor=="Mañana")
    {
        return 20000;
    }
    else
    {
        if(valor=="Tarde")
        {
            return 18500;
        }
        else
        {
            if(valor=="Mañana")
            {
                return 25000;
            }
            else
            {
                return 0;
            }
        }
    }
}
function AdministrarValidaciones()
{
    if(ValidarCamposVacios("txtNombre")==false || ValidarCamposVacios("txtApellido")==false || ValidarCamposVacios("txtDni")==false || ValidarCamposVacios("txtLegajo")==false || ValidarCamposVacios("txtSueldo")==false)
    {
        alert("Por favor complete los campos vacios");
        return false;
    }
    let DNI=Number((<HTMLInputElement>document.getElementById("txtDni")).value);
    if(ValidarRangoNumerico(DNI,1000000,50000000)==false)
    {
        alert("El DNI ingresado ("+DNI+") no esta dentro del rango permitido (1.000.000-50.000.000)")
        return false;
    }
    if(ValidarCombo("cboSexo","---")==false)
    {
        return false;
    }
    let Turno=ObtenerTurnoSeleccionado();
    let SueldoIngresado=Number((<HTMLInputElement>document.getElementById("txtSueldo")).value);
    if(ValidarRangoNumerico(SueldoIngresado,8000,25000)==false)
    {
        alert("El Sueldo ingresado ("+SueldoIngresado+") no esta dentro del rango permitido (8000-25000)")
        return false;
    }
    let SueldoMaximo=ObtenerSueldoMaximo(Turno);
    return true;
}
