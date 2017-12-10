using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.PP
{
    public class BancoMunicipal:BancoProvincial
    {
        public string municipio;

        public BancoMunicipal(BancoProvincial bm, string municipio):base(bm,bm.provincia)
        {
            this.municipio = municipio;
        }

        public override string Mostrar(Banco b1)
        {
            return this.Mostrar((BancoProvincial)b1) + "Municipio: " + this.municipio + "\n";
        }
    }
}
