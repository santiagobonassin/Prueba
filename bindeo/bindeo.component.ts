import { Component, OnInit } from '@angular/core';
import { Mascota } from 'src/app/clases/mascota/mascota';

@Component({
  selector: 'app-bindeo',
  templateUrl: './bindeo.component.html',
  styleUrls: ['./bindeo.component.css']
})
export class BindeoComponent implements OnInit {

    nombre: string;
    srcGatito: string;
    lista: Array<Mascota> = [];
    constructor() {}

    ngOnInit() {
        this.nombre = "Juan";
        this.srcGatito = "https://www.purina.es/sites/g/files/mcldtz1656/files/2017-11/Bringing-Your-Kitten-Home_2.jpg";

    }

    public enviar (event): void {
        
        this.lista.push(new Mascota(this.nombre, this.srcGatito, 'Gato' ));
    }

    public sacarTurno (e) {
        console.log(e);
    }
}
