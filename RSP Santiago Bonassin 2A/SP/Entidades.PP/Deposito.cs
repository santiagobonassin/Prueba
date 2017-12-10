using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace Entidades.PP
{
    [XmlInclude(typeof(DepositoHeredado))]
    [Serializable]

    public class Deposito
    {
        public int capacidad;
        public Producto[] productos;

        public Deposito()
        {
            this.capacidad = 3;
            this.productos = new Producto[capacidad];
        }
        public Deposito(int capacidad):this()
        {
            this.capacidad = capacidad;
            this.productos = new Producto[capacidad];
        }
        public static Producto[] operator +(Deposito d1, Deposito d2)
        {
            int i;
            int j;
            int total=0;     
            total=d1.capacidad+d2.capacidad;
            Producto[] retorno= new Producto[total];

            for (i = 0; i < d1.capacidad; i++)
            {
                for (j = 1; j < d2.capacidad+1; j++)
                {
                    if (d1.productos[i] != d2.productos[j])
                    {
                        retorno.SetValue(d1.productos[i], i);
                        retorno.SetValue(d2.productos[j], j);
                    }
                    else
                    {
                        retorno.SetValue(d1.productos[i], i);
                        retorno[i].stock++;
                    }
                }
            }
            return retorno;
        }
    }
}
