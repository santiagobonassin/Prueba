using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.PP
{
    public class EntidadesFinancieras<T> where T : new()
    {
        private List<T> _elementos;
        private int _capacidad;

        private EntidadesFinancieras()
        {
            _elementos = new List<T>();
        }
        public EntidadesFinancieras(int capacidad):this()
        {
            this._capacidad = capacidad;
        }
       

    }
}
