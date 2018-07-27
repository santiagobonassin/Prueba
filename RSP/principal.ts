namespace Funciones
{
    export class Listadora
    {
        public static Listar():void
        {
            let miToken = localStorage.getItem('JWTKey');
            var stringTabla = '<tbody>';

            console.log("validarJWT: "+this.ValidarJWT())

            if(this.ValidarJWT())
            {
                console.log("llega a Listar propietario");                
    
                if(miToken)
                {
                    //hace el parse y el foreach juntos
                    let usuarios = JSON.parse(miToken);

                    usuarios.forEach((element: any) => {
                        console.log(element);                  

                        stringTabla+=
                        '<tr><td>'+element.correo+'</td><td>'+element.apellido+'</td><td>'+element.nombre+'</td><td>'+element.perfil+'</td><td>'+element.legajo+'</td><td><img src='+"../fotos/"+element.foto+' class="img-thumbnail" height="50" width="50"></td><td><button type="button" class="btn btn-danger" onclick="Test.Manejadora.Deslogear()">Deslogearse</button></td><td></tr>';
                    
                    });

                    stringTabla+="</tbody></table>";
                    (<HTMLDivElement>document.getElementById('laTabla')).innerHTML+=stringTabla;
                }               

            }
            else
            {
                if(miToken)
                {
                    //hace el parse y el foreach juntos
                    let usuarios = JSON.parse(miToken);
                    console.log("llega a Listar normal");                

                    usuarios.forEach((element: any) => {
                        console.log(element);                  

                        stringTabla+=
                        '<tr><td>'+element.correo+'</td><td>'+element.apellido+'</td><td>'+element.nombre+'</td><td>'+element.perfil+'</td><td>'+element.legajo+'</td><td><img src='+"../fotos/"+element.foto+' class="img-thumbnail" height="50" width="50"></td><td></tr>';
                    
                    });

                    stringTabla+="</tbody></table>";
                    (<HTMLDivElement>document.getElementById('laTabla')).innerHTML+=stringTabla;
                }
                
            }            
        }

        public static ValidarJWT():boolean
        {
            let xmlhttp: XMLHttpRequest = new XMLHttpRequest();
            let JWT = localStorage.getItem('JWT');
            let esPropietario = false;

            xmlhttp.open("POST", "../php/validar", true);
            xmlhttp.setRequestHeader("enctype","multipart/form-data");
            xmlhttp.setRequestHeader('JWT','JWT');
            
            xmlhttp.send();

            xmlhttp.onreadystatechange = function ()
            {
                if (xmlhttp.readyState == 4)
                {
                    if (xmlhttp.status == 200)
                    {
                        //let perfil = xmlhttp.responseText.replace(/"propietario"/g,'propietario');

                        //console.log("perfil: "+perfil);

                        console.log("JWT todavia valido<br/>");

                        //if(perfil == "propietario")
                        //{
                            esPropietario = true;                        
                        //}
                        
                    }
                    else
                    {
                        console.error("JWT no valido<br/>");
                        window.location.assign('../html/login.html');
                    }
                }

            };

            return esPropietario;

        }
        
    }
}