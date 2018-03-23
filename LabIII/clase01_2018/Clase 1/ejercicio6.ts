let numero : number = 5;

function CalcularCubo(param1 : number):void
{
    let cubo : number = (param1 * param1 * param1);
    MostrarNumero(cubo,param1);
}
function MostrarNumero(param1 : number, param2:number):void
{
    console.log("El cubo de " + param2 + " es: " + param1 + "\n");
}
CalcularCubo(numero);