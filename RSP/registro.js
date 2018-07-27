var Test;
(function (Test) {
    var Registradora = /** @class */ (function () {
        function Registradora() {
        }
        Registradora.Registrar = function () {
            if (Registradora.ValidarCampos()) {
                var email_1 = document.getElementById('email').value;
                var clave = document.getElementById('clave').value;
                var apellido = document.getElementById('apellido').value;
                var legajo = document.getElementById('legajo').value;
                var nombre = document.getElementById('nombre').value;
                var confirmar = document.getElementById('confirmar').value;
                var foto = document.getElementById('foto').value;
                var perfil = document.getElementById('perfil').value;
                var stringJSON = JSON.stringify({
                    "correo": email_1,
                    "clave": clave,
                    "nombre": nombre,
                    "apellido": apellido,
                    "legajo": legajo,
                    "perfil": perfil,
                    "foto": foto.split('\\').pop()
                });
                var seEncontro_1 = false;
                var stringusers = localStorage.getItem("JWTKey");
                if (stringusers) {
                    var usuarios = JSON.parse(stringusers);
                    usuarios.forEach(function (element) {
                        console.log(element);
                        if (element.correo == email_1) {
                            document.getElementById('mostrarErrores').innerHTML = "<div class=\"alert alert-danger\" role=\"alert\">\n                              El usuario ya esta registrado\n                            </div>";
                            seEncontro_1 = true;
                        }
                    });
                }
                if (!seEncontro_1) {
                    usuarios.push(stringJSON);
                    if (this.SubirFoto()) {
                        console.log("entra a subirFoto");
                    }
                    else {
                        console.log("no entra a subirFoto");
                    }
                    localStorage.setItem("JWTKey", JSON.stringify(usuarios));
                    window.location.assign('./login.html');
                }
            }
        };
        Registradora.Limpiar = function () {
            Registradora.BorrarErrores();
            document.getElementById('apellido').value = "";
            document.getElementById('nombre').value = "";
            document.getElementById('email').value = "";
            document.getElementById('legajo').value = "";
            document.getElementById('perfil').value = "";
            document.getElementById('foto').value = "";
            document.getElementById('clave').value = "";
            document.getElementById('confirmar').value = "";
        };
        Registradora.BorrarErrores = function () {
            document.getElementById('errorApellido').innerHTML = "";
            document.getElementById('mostrarErrorApellido').innerHTML = "<div class=\"alert alert-danger\" role=\"alert\" style=\"display:none\">\n            </div>";
            document.getElementById('errorClave').innerHTML = "";
            document.getElementById('mostrarErrorClave').innerHTML = "<div class=\"alert alert-warning\" role=\"alert\" style=\"display:none\">\n            </div>";
            document.getElementById('errorNombre').innerHTML = "";
            document.getElementById('mostrarErrorNombre').innerHTML = "<div class=\"alert alert-warning\" role=\"alert\" style=\"display:none\">\n            </div>";
            document.getElementById('errorEmail').innerHTML = "";
            document.getElementById('mostrarErrorEmail').innerHTML = "<div class=\"alert alert-warning\" role=\"alert\" style=\"display:none\">\n            </div>";
            document.getElementById('errorLegajo').innerHTML = "";
            document.getElementById('mostrarErrorLegajo').innerHTML = "<div class=\"alert alert-warning\" role=\"alert\" style=\"display:none\">\n            </div>";
            document.getElementById('errorFoto').innerHTML = "";
            document.getElementById('mostrarErrorFoto').innerHTML = "<div class=\"alert alert-warning\" role=\"alert\" style=\"display:none\">\n            </div>";
        };
        Registradora.ValidarCampos = function () {
            Registradora.BorrarErrores();
            var email = document.getElementById('email').value;
            var clave = document.getElementById('clave').value;
            var apellido = document.getElementById('apellido').value;
            var legajo = parseInt(document.getElementById('legajo').value);
            var nombre = document.getElementById('nombre').value;
            var confirmar = document.getElementById('confirmar').value;
            var foto = document.getElementById('foto').value;
            var retorno = true;
            var emailRegex = /^[-\w.%+]{1,64}@(?:[A-Z0-9-]{1,63}\.){1,125}[A-Z]{2,63}$/i;
            if (apellido == "") {
                document.getElementById('errorApellido').innerHTML = "*";
                document.getElementById('mostrarErrorApellido').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El apellido se encuentra vacio\n              </div>";
                retorno = false;
            }
            else if (apellido.length > 15) {
                document.getElementById('errorApellido').innerHTML = "*";
                document.getElementById('mostrarErrorApellido').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El apellido no puede ser de mas de 15 caracteres\n              </div>";
                retorno = false;
            }
            if (nombre == "") {
                document.getElementById('errorNombre').innerHTML = "*";
                document.getElementById('mostrarErrorNombre').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El nombre se encuentra vacio\n              </div>";
                retorno = false;
            }
            else if (nombre.length > 10) {
                document.getElementById('errorNombre').innerHTML = "*";
                document.getElementById('mostrarErrorNombre').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El nombre no puede ser de mas de 10 caracteres\n              </div>";
                retorno = false;
            }
            if (email == "") {
                document.getElementById('errorEmail').innerHTML = "*";
                document.getElementById('mostrarErrorEmail').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El email se encuentra vacio\n              </div>";
                retorno = false;
            }
            else if (!emailRegex.test(email)) {
                document.getElementById('errorEmail').innerHTML = "*";
                document.getElementById('mostrarErrorEmail').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El email no tiene un formato valido.\n              </div>";
                retorno = false;
            }
            if (legajo == 0) {
                document.getElementById('errorLegajo').innerHTML = "*";
                document.getElementById('mostrarErrorLegajo').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El legajo se encuentra vacio\n              </div>";
                retorno = false;
            }
            else if (!isNaN(legajo) && (legajo < 3 || legajo > 6)) {
                document.getElementById('errorLegajo').innerHTML = "*";
                document.getElementById('mostrarErrorLegajo').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                El legajo debe ser un numero entre 3 y 6.\n              </div>";
                retorno = false;
            }
            var fotoExt = foto.split('.').pop();
            console.log(fotoExt);
            console.log(foto);
            if (!(fotoExt == 'jpg' || fotoExt == 'png')) {
                document.getElementById('errorFoto').innerHTML = "*";
                document.getElementById('mostrarErrorFoto').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                No es una extension valida\n              </div>";
                retorno = false;
            }
            if (clave == "") {
                document.getElementById('errorClave').innerHTML = "*";
                document.getElementById('mostrarErrorClave').innerHTML += "<div class=\"alert alert-danger\" role=\"alert\">\n                La clave se encuentra vacia\n              </div>";
                retorno = false;
            }
            else if (clave.length < 4 || clave.length > 8) {
                document.getElementById('errorClave').innerHTML = "*";
                document.getElementById('mostrarErrorClave').innerHTML = "<div class=\"alert alert-danger\" role=\"alert\">\n                La clave tiene que ser entre 4 y 8 caracteres\n              </div>";
                retorno = false;
            }
            else if (clave != confirmar) {
                document.getElementById('errorClave').innerHTML = "*";
                document.getElementById('mostrarErrorClave').innerHTML = "<div class=\"alert alert-danger\" role=\"alert\">\n                Error al confirmar la clave.\n              </div>";
                retorno = false;
            }
            return retorno;
        };
        Registradora.SubirFoto = function () {
            var xhttp = new XMLHttpRequest();
            var foto = document.getElementById('foto');
            var form = new FormData();
            var flag = true;
            form.append('foto', foto.files[0]);
            form.append('op', "subirFoto");
            xhttp.open('POST', './uploader.php', true);
            xhttp.setRequestHeader("enctype", "multipart/form-data");
            xhttp.send(form);
            console.log("llego a SubirFoto()");
            xhttp.onreadystatechange = function () {
                if (xhttp.readyState == 4 && xhttp.status == 200) {
                    console.log(xhttp.responseText);
                    var retJSON = JSON.parse(xhttp.responseText);
                    if (!retJSON.Ok) {
                        console.error("NO se subió la foto!!!");
                        flag = false;
                    }
                    else {
                        console.info("Foto subida OK!!!");
                        flag = true;
                    }
                }
            };
            return flag;
        };
        return Registradora;
    }());
    Test.Registradora = Registradora;
})(Test || (Test = {}));
