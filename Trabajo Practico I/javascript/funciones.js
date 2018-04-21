function ValidarCamposVacios(input) {
    if (document.getElementById(input).value == "") {
        alert("Un campo esta incompleto");
        return false;
    }
    return true;
}
function ValidarRangoNumerico(valor, min, max) {
    if (valor < min || valor > max) {
        return false;
    }
    return true;
}
function ValidarCombo(valor, error) {
    if (document.getElementById(valor).value == error) {
        alert("El sexo indicado es invalido, debe elegir Femenino o Masculino");
        return false;
    }
    return true;
}
function ObtenerTurnoSeleccionado() {
    if (document.getElementById("rdoTurnoMañana").checked) {
        return "Mañana";
    }
    else {
        if (document.getElementById("rdoTurnoTarde").checked) {
            return "Tarde";
        }
        else {
            if (document.getElementById("rdoTurnoNoche").checked) {
                return "Noche";
            }
            else {
                return "";
            }
        }
    }
}
function ObtenerSueldoMaximo(valor) {
    if (valor == "Mañana") {
        return 20000;
    }
    else {
        if (valor == "Tarde") {
            return 18500;
        }
        else {
            if (valor == "Mañana") {
                return 25000;
            }
            else {
                return 0;
            }
        }
    }
}
function AdministrarValidaciones() {
    if (ValidarCamposVacios("txtNombre") == false || ValidarCamposVacios("txtApellido") == false || ValidarCamposVacios("txtDni") == false || ValidarCamposVacios("txtLegajo") == false || ValidarCamposVacios("txtSueldo") == false) {
        alert("Por favor complete los campos vacios");
        return false;
    }
    var DNI = Number(document.getElementById("txtDni").value);
    if (ValidarRangoNumerico(DNI, 1000000, 50000000) == false) {
        alert("El DNI ingresado (" + DNI + ") no esta dentro del rango permitido (1.000.000-50.000.000)");
        return false;
    }
    if (ValidarCombo("cboSexo", "---") == false) {
        return false;
    }
    var Turno = ObtenerTurnoSeleccionado();
    var SueldoIngresado = Number(document.getElementById("txtSueldo").value);
    if (ValidarRangoNumerico(SueldoIngresado, 8000, 25000) == false) {
        alert("El Sueldo ingresado (" + SueldoIngresado + ") no esta dentro del rango permitido (8000-25000)");
        return false;
    }
    var SueldoMaximo = ObtenerSueldoMaximo(Turno);
    return true;
}
