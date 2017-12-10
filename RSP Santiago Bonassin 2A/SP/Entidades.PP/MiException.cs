using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.PP
{
    public class MiException:Exception
    {
        static string mensaje = "Excepcion Lanzada";
        public MiException():base(mensaje)
        {

        }
    }
}
