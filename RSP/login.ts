window.onload = function (): void {
    if (localStorage.getItem('JWTKey')) {
        console.log("Ya existen elementos en el local storage: " + localStorage.getItem('JWTKey'));
    }
    else {
        var usuarios = [{
            "correo": "adsouad@gmail.com",
            "clave": "123",
            "nombre": "Juan",
            "apellido": "Masoe",
            "legajo": 12345,
            "perfil": "Aaiouadsd",
            "foto": "exdi.jpg"
        },
        {
            "correo": "qweqwieasd@hotmail.com",
            "clave": "123",
            "nombre": "Carlos",
            "apellido": "Pena",
            "legajo": 675,
            "perfil": "wqewqeg",
            "foto": "qweqds.jpg"
        },
        {
            "correo": "lucasmassa@gmail.com",
            "clave": "12345",
            "nombre": "Lucas",
            "apellido": "Massa",
            "legajo": 123456,
            "perfil": "asdsad",
            "foto": "qweo0iqweda.jpg"
        },
        {
            "correo": "prattsekisde@yahoo.com",
            "clave": "123",
            "nombre": "Ricardo",
            "apellido": "Ruben",
            "legajo": 6546456,
            "perfil": "qdqed",
            "foto": "qwewqeofias.png"
        },
        {
            "correo": "qw0oedadiqa@alkeada.com",
            "clave": "123",
            "nombre": "Marto",
            "apellido": "Melo",
            "legajo": 600600,
            "perfil": "qwewqe",
            "foto": "aiasdusad.jpeg"
        },]
        localStorage.setItem('JWTKey', JSON.stringify(usuarios));
        console.log(localStorage.getItem('JWTKey'));
    }
};
