using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.PP
{
    public class Producto
    {
        public string nombre;
        public int stock;

        public Producto(string nombre, int stock)
        {
            this.nombre = nombre;
            this.stock = stock;
        }
    }
}
