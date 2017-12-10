using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.PP
{
    public class BancoNacional:Banco
    {
        public string pais;

        public BancoNacional(string nombre, string pais):base(nombre)
        {
            this.pais = pais;
        }
        public override string Mostrar()
        {
            return "Nombre del Banco: " + this.nombre + "\n";
        }
        public override string Mostrar(Banco b1)
        {
            return this.Mostrar() + "Pais: " + this.pais + "\n";
        }
    }
}
