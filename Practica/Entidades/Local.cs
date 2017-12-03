using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Xml.Serialization;

namespace Entidades
{
    public class Local
    {
        int idProducto;
        string nombreProducto;
        int precio;
        TipoProducto producto;
        public Lista imprimir = new Lista(Guardar);
        public Lista xml = new Lista(Serializar);

        public enum TipoProducto
        {
            Procesador, PlacaDeVideo, Gabinete, RAM, Nulo
        }

        public Local()
        {
            this.idProducto = 0;
            this.nombreProducto = " ";
            this.precio = 0;
            this.producto = TipoProducto.Nulo;
        }
        public Local(int id, string nombreProducto, int precio, TipoProducto producto):this()
        {
            this.idProducto = id;
            this.nombreProducto = nombreProducto;
            this.precio = precio;
            this.producto = producto;
        }

        public override string ToString()
        {
            return "ID del producto: " + this.idProducto + "\nNombre del producto: " + this.nombreProducto + "\nTipo de producto: " + this.producto + "\nPrecio: " + this.precio + "\n";
        }

        public static void Guardar(object obj, EventArgs args)
        {
            try
            {
                StreamWriter escritor = new StreamWriter("Productos.txt", false);
                escritor.WriteLine("Productos en el carro: "+Environment.NewLine + ((Local)obj).ToString());
                escritor.Close();
            }
            catch (Exception e)
            {

            }
        }
        public static void Serializar(object obj, EventArgs args)
        {

            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(Local));
                StreamWriter sw = new StreamWriter("Serializacion.xml", false);
                serializer.Serialize(sw, (Local)obj);
                sw.Close();
            }
            catch(Exception e)
            {

            }           
        }
        public delegate void Lista(object obj, EventArgs args);
    }
}
