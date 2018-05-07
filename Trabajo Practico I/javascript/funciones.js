function ValidarCamposVacios(input) {
    if (document.getElementById(input).value == "") {
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
    if (ValidarCamposVacios("txtNombre") == false) {
        AdministrarSpanError("spanNombre", false);
    }
    else {
        AdministrarSpanError("spanNombre", true);
    }
    if (ValidarCamposVacios("txtApellido") == false) {
        AdministrarSpanError("spanApellido", false);
    }
    else {
        AdministrarSpanError("spanApellido", true);
    }
    if (ValidarCamposVacios("txtDni") == false) {
        AdministrarSpanError("spanDni", false);
    }
    else {
        AdministrarSpanError("spanDni", true);
    }
    if (ValidarCamposVacios("txtLegajo") == false) {
        AdministrarSpanError("spanLegajo", false);
    }
    else {
        AdministrarSpanError("spanLegajo", true);
    }
    if (ValidarCamposVacios("txtSueldo") == false) {
        AdministrarSpanError("spanSueldo", false);
    }
    else {
        AdministrarSpanError("spanSueldo", true);
    }
    if (ValidarCamposVacios("foto") == false) {
        AdministrarSpanError("spanFoto", false);
    }
    else {
        AdministrarSpanError("spanFoto", true);
    }
    var DNI = Number(document.getElementById("txtDni").value);
    var legajo = Number(document.getElementById("txtLegajo").value);
    if (ValidarRangoNumerico(DNI, 1000000, 50000000) == false) {
        AdministrarSpanError("spanDni", false);
    }
    else {
        AdministrarSpanError("spanDni", true);
    }
    if (ValidarRangoNumerico(legajo, 100, 550) == false) {
        AdministrarSpanError("spanLegajo", false);
    }
    else {
        AdministrarSpanError("spanLegajo", true);
    }
    if (ValidarCombo("cboSexo", "---") == false) {
        AdministrarSpanError("spanSexo", false);
    }
    else {
        AdministrarSpanError("spanSexo", true);
    }
    var Turno = ObtenerTurnoSeleccionado();
    var SueldoIngresado = Number(document.getElementById("txtSueldo").value);
    if (ValidarRangoNumerico(SueldoIngresado, 8000, 25000) == false) {
        AdministrarSpanError("spanSueldo", false);
    }
    else {
        AdministrarSpanError("spanSueldo", true);
    }
    var SueldoMaximo = ObtenerSueldoMaximo(Turno);
    return VerificarValidacionesIndex();
}
function AdministrarValidacionesLogin() {
    var DNI = Number(document.getElementById("txtDNI").value);
    if (ValidarCamposVacios("txtDNI") == false || ValidarRangoNumerico(DNI, 1000000, 50000000) == false) {
        AdministrarSpanError("spanDNI", false);
    }
    else {
        AdministrarSpanError("spanDNI", true);
    }
    if (ValidarCamposVacios("txtApellido") == false) {
        AdministrarSpanError("spanApellido", false);
    }
    else {
        AdministrarSpanError("spanApellido", true);
    }
    return VerificarValidacionesLogin();
}
function AdministrarSpanError(campo, valor) {
    if (valor == false) {
        document.getElementById(campo).setAttribute("style", "display:block");
    }
    else {
        document.getElementById(campo).setAttribute("style", "display:none");
    }
}
function VerificarValidacionesLogin() {
    if (document.getElementById("spanDNI").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanApellido").getAttribute("style") == "display:block") {
        return false;
    }
    return true;
}
function VerificarValidacionesIndex() {
    if (document.getElementById("spanNombre").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanApellido").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanDni").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanSexo").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanLegajo").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanSueldo").getAttribute("style") == "display:block") {
        return false;
    }
    if (document.getElementById("spanFoto").getAttribute("style") == "display:block") {
        return false;
    }
    return true;
}
function AdministrarModificar(dni) {
    alert("llego al admin");
    document.getElementById('modificar').setAttribute('value', dni.toString());
    document.getElementById('formulario').submit();
}
