namespace Test {
    export class Registradora {
        public static Registrar() {
            if (Registradora.ValidarCampos()) {
                let email = (<HTMLInputElement>document.getElementById('email')).value;
                let clave = (<HTMLInputElement>document.getElementById('clave')).value;
                let apellido = (<HTMLInputElement>document.getElementById('apellido')).value;
                let legajo = (<HTMLInputElement>document.getElementById('legajo')).value;
                let nombre = (<HTMLInputElement>document.getElementById('nombre')).value;
                let confirmar = (<HTMLInputElement>document.getElementById('confirmar')).value;
                let foto = (<HTMLInputElement>document.getElementById('foto')).value;
                let perfil = (<HTMLInputElement>document.getElementById('perfil')).value;   
                
                let stringJSON = JSON.stringify({
                    "correo": email,
                    "clave": clave,
                    "nombre": nombre,
                    "apellido": apellido,
                    "legajo": legajo,
                    "perfil": perfil,
                    "foto": foto.split('\\').pop()
                });

                

                let seEncontro = false;
                let stringusers = localStorage.getItem("JWTKey");

                if (stringusers)
                {
                    var usuarios = JSON.parse(stringusers);

                    //busca cada uno de los usuarios por si hay coincidencias
                    usuarios.forEach((element: any) => {

                        console.log(element);
                        if (element.correo == email)
                        {
                            (<HTMLDivElement>document.getElementById('mostrarErrores')).innerHTML = `<div class="alert alert-danger" role="alert">
                              El usuario ya esta registrado
                            </div>`
                            seEncontro = true;
                        }
                    });
                }

                if (!seEncontro)
                {                 
                    //si no en contro el usuario, lo agrega con PUSH al array de JSON con el resto de los usuarios
                    usuarios.push(stringJSON);
                    //llama a la funcion para guardar la foto
                    if(this.SubirFoto())
                    {
                        console.log("entra a subirFoto");
                    }
                    else
                    {
                        console.log("no entra a subirFoto");
                    }
                    //sobreescribe el token anterior con el nuevo, incluyendo el usuario recien agregado
                    localStorage.setItem("JWTKey", JSON.stringify(usuarios));
                    //vuelve a login.html
                    window.location.assign('./login.html');
                }
            }
        }
        public static Limpiar():void
        {
            Registradora.BorrarErrores();
            (<HTMLInputElement>document.getElementById('apellido')).value="";
            (<HTMLInputElement>document.getElementById('nombre')).value="";
            (<HTMLInputElement>document.getElementById('email')).value="";
            (<HTMLInputElement>document.getElementById('legajo')).value="";
            (<HTMLInputElement>document.getElementById('perfil')).value="";
            (<HTMLInputElement>document.getElementById('foto')).value="";
            (<HTMLInputElement>document.getElementById('clave')).value="";
            (<HTMLInputElement>document.getElementById('confirmar')).value="";
        }
        public static BorrarErrores():void
        {
            (<HTMLSpanElement>document.getElementById('errorApellido')).innerHTML = "";
            (<HTMLDivElement>document.getElementById('mostrarErrorApellido')).innerHTML = `<div class="alert alert-danger" role="alert" style="display:none">
            </div>`;
            (<HTMLSpanElement>document.getElementById('errorClave')).innerHTML = "";
            (<HTMLDivElement>document.getElementById('mostrarErrorClave')).innerHTML = `<div class="alert alert-warning" role="alert" style="display:none">
            </div>`;
            (<HTMLSpanElement>document.getElementById('errorNombre')).innerHTML = "";
            (<HTMLDivElement>document.getElementById('mostrarErrorNombre')).innerHTML = `<div class="alert alert-warning" role="alert" style="display:none">
            </div>`;
            (<HTMLSpanElement>document.getElementById('errorEmail')).innerHTML = "";
            (<HTMLDivElement>document.getElementById('mostrarErrorEmail')).innerHTML = `<div class="alert alert-warning" role="alert" style="display:none">
            </div>`;
            (<HTMLSpanElement>document.getElementById('errorLegajo')).innerHTML = "";
            (<HTMLDivElement>document.getElementById('mostrarErrorLegajo')).innerHTML = `<div class="alert alert-warning" role="alert" style="display:none">
            </div>`;
            (<HTMLSpanElement>document.getElementById('errorFoto')).innerHTML = "";
            (<HTMLDivElement>document.getElementById('mostrarErrorFoto')).innerHTML = `<div class="alert alert-warning" role="alert" style="display:none">
            </div>`;             
        }
        public static ValidarCampos(): Boolean {
            Registradora.BorrarErrores();
            let email = (<HTMLInputElement>document.getElementById('email')).value;
            let clave = (<HTMLInputElement>document.getElementById('clave')).value;
            let apellido = (<HTMLInputElement>document.getElementById('apellido')).value;
            let legajo = parseInt((<HTMLInputElement>document.getElementById('legajo')).value);
            let nombre = (<HTMLInputElement>document.getElementById('nombre')).value;
            let confirmar = (<HTMLInputElement>document.getElementById('confirmar')).value;
            let foto = (<HTMLInputElement>document.getElementById('foto')).value;
            let retorno = true;
            let emailRegex = /^[-\w.%+]{1,64}@(?:[A-Z0-9-]{1,63}\.){1,125}[A-Z]{2,63}$/i;
            if(apellido=="")
            {
                (<HTMLSpanElement>document.getElementById('errorApellido')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorApellido')).innerHTML += `<div class="alert alert-danger" role="alert">
                El apellido se encuentra vacio
              </div>`
                retorno = false;
            }
            else if (apellido.length > 15) {
                (<HTMLSpanElement>document.getElementById('errorApellido')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorApellido')).innerHTML += `<div class="alert alert-danger" role="alert">
                El apellido no puede ser de mas de 15 caracteres
              </div>`
                retorno = false;
            }
            if(nombre=="")
            {
                (<HTMLSpanElement>document.getElementById('errorNombre')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorNombre')).innerHTML += `<div class="alert alert-danger" role="alert">
                El nombre se encuentra vacio
              </div>`
                retorno = false;
            }
            else if (nombre.length > 10) {
                (<HTMLSpanElement>document.getElementById('errorNombre')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorNombre')).innerHTML += `<div class="alert alert-danger" role="alert">
                El nombre no puede ser de mas de 10 caracteres
              </div>`
                retorno = false;
            }
            if(email=="")
            {
                (<HTMLSpanElement>document.getElementById('errorEmail')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorEmail')).innerHTML += `<div class="alert alert-danger" role="alert">
                El email se encuentra vacio
              </div>`
                retorno = false;
            }
            else if(!emailRegex.test(email)) {
                (<HTMLSpanElement>document.getElementById('errorEmail')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorEmail')).innerHTML += `<div class="alert alert-danger" role="alert">
                El email no tiene un formato valido.
              </div>`
                retorno = false;
            }           
            if(legajo==0)
            {
                (<HTMLSpanElement>document.getElementById('errorLegajo')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorLegajo')).innerHTML += `<div class="alert alert-danger" role="alert">
                El legajo se encuentra vacio
              </div>`
                retorno = false;
            }
            else if (!isNaN(legajo) && (legajo < 3 || legajo > 6)) {
                (<HTMLSpanElement>document.getElementById('errorLegajo')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorLegajo')).innerHTML += `<div class="alert alert-danger" role="alert">
                El legajo debe ser un numero entre 3 y 6.
              </div>`
                retorno = false;
            }            
            let fotoExt = foto.split('.').pop();
            console.log(fotoExt);
            console.log(foto);
            if (!(fotoExt == 'jpg'||fotoExt=='png')) 
            {
                (<HTMLSpanElement>document.getElementById('errorFoto')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorFoto')).innerHTML += `<div class="alert alert-danger" role="alert">
                No es una extension valida
              </div>`
                retorno = false;
            }
            if(clave=="")
            {
                (<HTMLSpanElement>document.getElementById('errorClave')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorClave')).innerHTML += `<div class="alert alert-danger" role="alert">
                La clave se encuentra vacia
              </div>`
                retorno = false;
            }
            else if (clave.length < 4 || clave.length > 8) {
                (<HTMLSpanElement>document.getElementById('errorClave')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorClave')).innerHTML = `<div class="alert alert-danger" role="alert">
                La clave tiene que ser entre 4 y 8 caracteres
              </div>`
                retorno = false;
            }
            else if (clave != confirmar) {
                (<HTMLSpanElement>document.getElementById('errorClave')).innerHTML = "*";
                (<HTMLDivElement>document.getElementById('mostrarErrorClave')).innerHTML = `<div class="alert alert-danger" role="alert">
                Error al confirmar la clave.
              </div>`
                retorno = false;
            }
            return retorno;
        }
        public static SubirFoto() : boolean
        {
            let xhttp : XMLHttpRequest = new XMLHttpRequest();
            let foto : any = (<HTMLInputElement> document.getElementById('foto'));
            let form : FormData = new FormData();
            let flag = true;
    
            form.append('foto', foto.files[0]);       
            form.append('op', "subirFoto");       
            xhttp.open('POST', './uploader.php', true);   
            xhttp.setRequestHeader("enctype", "multipart/form-data");
    
            xhttp.send(form);

            console.log("llego a SubirFoto()");       
            xhttp.onreadystatechange = () => {       
                if (xhttp.readyState == 4 && xhttp.status == 200)
                {        
                    console.log(xhttp.responseText);                   
                    let retJSON = JSON.parse(xhttp.responseText);
                    if(!retJSON.Ok)
                    {
                        console.error("NO se subió la foto!!!");
                        flag = false;
                    }
                    else
                    {
                        console.info("Foto subida OK!!!");
                        flag = true;
                    }
                }
            };
            return flag;
        }
    }
}