function funcion(param1:number,param2?:String):void
{
    if(param2!=null)
    {
        for(var i=0;i<param1;i++)
        {
            console.log(param2 + "\n");
        }
    }
    else
    {
        console.log("El numero inverso al ingresado es: " + (param1*-1));
    }


}

funcion(5);