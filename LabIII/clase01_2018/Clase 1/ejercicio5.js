"use strict";
var nombre = "tomas";
var apellido = "angelo";
function MostrarNombreApellido(param1, param2) {
    param2 = param2.toUpperCase();
    param1 = param1.charAt(0).toUpperCase() + param1.slice(1).toLowerCase();
    console.log(param2 + ", " + param1);
}
MostrarNombreApellido(nombre, apellido);
//# sourceMappingURL=ejercicio5.js.map