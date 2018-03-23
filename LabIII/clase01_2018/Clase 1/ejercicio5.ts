let nombre : string = "tomas";
let apellido : string = "angelo";

function MostrarNombreApellido(param1 : string, param2 : string):void
{
    param2=param2.toUpperCase();
    param1=param1.charAt(0).toUpperCase()+param1.slice(1).toLowerCase();
    console.log(param2 + ", " + param1);
}
MostrarNombreApellido(nombre,apellido);