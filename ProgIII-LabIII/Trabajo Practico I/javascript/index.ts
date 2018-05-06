function ValidarCamposVacios(input:string):boolean
{
    if((<HTMLInputElement>document.getElementById(input)).value=="")
    {       
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
    if(ValidarCamposVacios("txtNombre")==false)    
    {
        AdministrarSpanError("spanNombre",false);
    }
    else
    {
        AdministrarSpanError("spanNombre",true); 
    }
    if(ValidarCamposVacios("txtApellido")==false)    
    {
        AdministrarSpanError("spanApellido",false);
    }
    else
    {
        AdministrarSpanError("spanApellido",true); 
    }
    if(ValidarCamposVacios("txtDni")==false)    
    {
        AdministrarSpanError("spanDni",false);
    }
    else
    {
        AdministrarSpanError("spanDni",true); 
    }
    if(ValidarCamposVacios("txtLegajo")==false)    
    {
        AdministrarSpanError("spanLegajo",false);
    }
    else
    {
        AdministrarSpanError("spanLegajo",true); 
    }
    if(ValidarCamposVacios("txtSueldo")==false)    
    {
        AdministrarSpanError("spanSueldo",false);
    }
    else
    {
        AdministrarSpanError("spanSueldo",true); 
    }
    if(ValidarCamposVacios("foto")==false)    
    {
        AdministrarSpanError("spanFoto",false);
    }
    else
    {
        AdministrarSpanError("spanFoto",true); 
    }
    let DNI=Number((<HTMLInputElement>document.getElementById("txtDni")).value);
    let legajo=Number((<HTMLInputElement>document.getElementById("txtLegajo")).value);
    if(ValidarRangoNumerico(DNI,1000000,50000000)==false)
    {
        AdministrarSpanError("spanDni",false);
    }
    else
    {
        AdministrarSpanError("spanDni",true);
    }
    if(ValidarRangoNumerico(legajo,100,550)==false)
    {
        AdministrarSpanError("spanLegajo",false);
    }
    else
    {
        AdministrarSpanError("spanLegajo",true);
    }
    if(ValidarCombo("cboSexo","---")==false)
    {
        AdministrarSpanError("spanSexo",false);
    }
    else
    {
        AdministrarSpanError("spanSexo",true);
    }
    let Turno=ObtenerTurnoSeleccionado();
    let SueldoIngresado=Number((<HTMLInputElement>document.getElementById("txtSueldo")).value);
    if(ValidarRangoNumerico(SueldoIngresado,8000,25000)==false)
    {
        AdministrarSpanError("spanSueldo",false);
    }
    else
    {
        AdministrarSpanError("spanSueldo",true);
    }
    let SueldoMaximo=ObtenerSueldoMaximo(Turno);
    
    return VerificarValidacionesIndex();
}
function AdministrarValidacionesLogin():boolean
{
    let DNI=Number((<HTMLInputElement>document.getElementById("txtDNI")).value);
    if(ValidarCamposVacios("txtDNI")==false || ValidarRangoNumerico(DNI,1000000,50000000)==false)
    {
        AdministrarSpanError("spanDNI",false);
    }
    else
    {
        AdministrarSpanError("spanDNI",true);
    }
    if(ValidarCamposVacios("txtApellido")==false)
    {
        AdministrarSpanError("spanApellido",false);
    }
    else
    {
        AdministrarSpanError("spanApellido",true);
    }
    return VerificarValidacionesLogin();
}
function AdministrarSpanError(campo:string,valor:boolean):void
{
    if(valor==false)
    {
        (<HTMLSpanElement>document.getElementById(campo)).setAttribute("style","display:block");
    }
    else
    {
        (<HTMLSpanElement>document.getElementById(campo)).setAttribute("style","display:none");
    }
}
function VerificarValidacionesLogin():boolean
{
    if((<HTMLSpanElement>document.getElementById("spanDNI")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanApellido")).getAttribute("style")=="display:block")
    {
        return false;
    }
    return true;
}
function VerificarValidacionesIndex():boolean
{
    if((<HTMLSpanElement>document.getElementById("spanNombre")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanApellido")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanDni")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanSexo")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanLegajo")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanSueldo")).getAttribute("style")=="display:block")
    {
        return false;
    }
    if((<HTMLSpanElement>document.getElementById("spanFoto")).getAttribute("style")=="display:block")
    {
        return false;
    }
    return true;
}
function AdministrarModificar(Valor:string):void
{
    (<HTMLInputElement>document.getElementById("modificar")).value=Valor;
    (<HTMLFormElement>document.getElementById("modificar")).submit();
}