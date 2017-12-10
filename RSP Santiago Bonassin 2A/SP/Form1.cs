﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.IO;
using Entidades.PP;

namespace SP
{

    //DESARROLLAR DENTRO DEL NAMESPACE RAIZ ENTIDADES.SP EN UN PROYECTO DE TIPO CLASS LIBRARY


    public partial class frmRSP : Form
    {
        private BancoNacional _bn;
        private BancoProvincial _bp;
        private BancoMunicipal _bm;

        public frmRSP()
        {
            InitializeComponent();
        }

        private void frmFinal_Load(object sender, EventArgs e)
        {
            MessageBox.Show("Bonassin Santiago 2A");
        }

        //Crear dos objetos de tipo Deposito, cada uno de estos objetos contiene un Array de la clase Producto.
        //Un constructor por default (inicializa en 3 productos) y una sobrecarga que reciba la cantidad de productos 
        //del depósito (REUTILIZAR CODIGO). 
        //La clase Producto tiene dos atributos: nombre y stock y un único constructor.
        //Se debe poder sumar los Array de los dos depósitos (con la sobrecarga de un operador en la clase Deposito) y guardar 
        //el valor que retorna en un Array de Productos, recordar que si un producto está en los dos Arrays, 
        //se debe sumar el stock y no agregar dos veces al mismo producto.
        //Mostrar el contenido del array resultante (nombre y stock)
        private void btnPunto1_Click(object sender, EventArgs e)
        {
            Producto p1 = new Producto("tomate", 10);
            Producto p2 = new Producto("azucar", 25);
            Producto p3 = new Producto("yerba", 30);

            Deposito d1 = new Deposito(4);
            Deposito d2 = new Deposito();

            d1.productos[0] = p1;
            d1.productos[1] = p2;
            d1.productos[2] = p3;
            d1.productos[3] = p3;

            d2.productos[0] = p1;
            d2.productos[1] = p1;
            d2.productos[2] = p2;

            Producto[] aux = d1 + d2;

            String s = "";
            foreach (Producto item in d1.productos)
            {
                s += (item.nombre + " - " + item.stock + "\n");
            }

            MessageBox.Show(s);
        }

        //Crear jerarquía que contenga los siguientes constructores (1 por clase):
        //Banco(nombre)
        //BancoNacional(nombre, pais)
        //BancoProvincial(bancoNacional, provincia)
        //BancoMunicipal(bancoProvincial, municipio)
        //Crear una instancia de cada clase e inicializar los atributos del form _bancoNacional, _bancoProvincial y _bancoMunicipal. 
        private void btnPunto2_Click(object sender, EventArgs e)
        {
            BancoNacional bn = new BancoNacional("Banco de la Alegría", "Argentina");
            BancoProvincial bp = new BancoProvincial(bn, "Buenos Aires");
            BancoMunicipal bm = new BancoMunicipal(bp, "Avellaneda");

            this._bn = bn;
            this._bp = bp;
            this._bm = bm;
        }

        //Agregar en Banco el método Mostrar():string y Mostrar(Banco):string, ambos abstractos.
        //El método que no recibe parámetros, retornará el nombre, mientras que el otro
        //retornará todas las características de la instancia que recibe como parametro. REUTILIZAR CODIGO.
        private void btnPunto3_Click(object sender, EventArgs e)
        {
            MessageBox.Show(this._bn.Mostrar() + "\n" + this._bn.Mostrar(this._bn));
            MessageBox.Show(this._bp.Mostrar() + "\n" + this._bn.Mostrar(this._bp));
            MessageBox.Show(this._bm.Mostrar() + "\n" + this._bn.Mostrar(this._bm));
        }

        //Crear la clase DepositoHeredado, que derive de Desposito y que implemente: 
        //ISerializar(Xml(string):bool) de forma implicita y
        //IDeserializar(Xml(string, out Deposito):bool) de forma explícita
        private void btnPunto4_Click(object sender, EventArgs e)
        {
            Producto p1 = new Producto("tomate", 10);
            Producto p2 = new Producto("azucar", 25);
            Producto p3 = new Producto("yerba", 30);

            DepositoHeredado dh = new DepositoHeredado();
            DepositoHeredado aux = null;

            dh.productos[0] = p1;
            dh.productos[1] = p2;
            dh.productos[2] = p3;

            bool serializar = dh.Xml("Serializacion.xml");// implementar serializar depositoHeredado
            if (serializar)
            {
                MessageBox.Show("Serializado OK");
            }
            else
            {
                MessageBox.Show("NO Serializado");
            }

            bool deserializar = ((IDeserealizar)dh).Xml("Serializacion.xml",out aux);// implementar deserializar depositoHeredado
            if (deserializar)
            {
                MessageBox.Show("Deserializado OK");

                String s = "";
                foreach (Producto item in aux.productos)
                {
                    s += (item.nombre + " - " + item.stock + "\n");
                }

                MessageBox.Show(s);
            }
            else
            {
                MessageBox.Show("NO Deserializado");
            }

        }
        //Realizar el burbujeo de una excepción propia (MiException), comenzando en un método de instancia (de la clase Burbujeo),
        //pasando por un método de estático (de la misma clase) y capturado por última vez en el método que lo inició (manejador _click).
        //En cada paso, agregar en un único archivo de texto (burbujeo.txt)
        //el lugar por donde se paso junto con la hora, minuto y segundo de la accion. 
        //Atrapar la excepción y relanzarla en cada ocasión, al finalizar, leer el archivo y mostrarlo por MessageBox
        private void btnPunto5_Click(object sender, EventArgs e)
        {
            string aux;
            try
            {
                Burbujeo.MetodoClase();
            }
            catch (MiException ex)
            {
                StreamWriter sw = new StreamWriter("Burbujeo.txt", true);
                sw.WriteLine("Evento click" + DateTime.Now);
                sw.Close();                                                //Implementar escribir en archivo de texto
            }
            finally
            {
                aux = Burbujeo.LeerArchivoDeTexto();
                MessageBox.Show(this,aux);                                                //Implementar leer en archivo de texto
            }
        }

        //Agregar metodo de extension (clase Extensora) en Producto= MostrarBD():string.
        //MostrarBD retornara una cadena (Nombre y Stock) de todos los registros de la BD.
        //Base de Datos (productosDB) -> Tabla productos (nombre - stock)
        private void btnPunto6_Click(object sender, EventArgs e)
        {
            //Producto p = new Producto("", 0);
            //MessageBox.Show(p.MostrarBD());
        }

        //Generar la clase genérica EntidadesFinancieras. Dicha clase tendrá el atributo _elementos:List del tipo genérico.
        //(este sólo se podrá inicializar en el constructor por defecto, que además será privado)
        //y _capacidad:int (generar un constructor que lo reciba como parámetros). Realizar validaciones necesarias
        //Realizar el método Add, que permite agregar un elemento a la colección. 
        //Cada elemento par agregado en la clase EntidadesFinacieras, disparará un evento (ElementosParesEvent).
        //Asociar el manejador del evento anterior a un método de instancia del formulario. 
        //Mostrar en dicho manejador las características por MessageBox.
        private void btnPunto7_Click(object sender, EventArgs e)
        {
            EntidadesFinancieras<BancoMunicipal> ef = new EntidadesFinancieras<BancoMunicipal>(2);
            EntidadesFinancieras<Banco> ef1 = new EntidadesFinancieras<Banco>(2);

            //Asociar manejador de eventos

            ef.Add(this._bm);
            ef.Add(new BancoMunicipal(this._bp, "Quilmes"));

            ef1.Add(this._bn);
            ef1.Add(this._bp);
            ef1.Add(this._bm);
        }

        private void ManejadorPares(object sender, EventArgs e) 
        {
            MessageBox.Show("Se agregó un elemento par!!!\n");
            //Mostrar detalle.
        }

    }
}
