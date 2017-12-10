using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.PP
{
    public delegate void ElementoPar(object obj, EventArgs args);
    public class EntidadesFinancieras<T> 
    {
        private List<T> _elementos;
        private int _capacidad;
        public event ElementoPar ElementosParesEvent;

        private EntidadesFinancieras()
        {
            _elementos = new List<T>();
        }
        public EntidadesFinancieras(int capacidad):this()
        {
            this._capacidad = capacidad;
        }
        public void Add(T b1)
        {
            if(this._elementos.Count<this._capacidad)
            {
                this._elementos.Add(b1);  
                if(this._elementos.IndexOf(b1)%2==0)
                {

                }
                
            }
        }
        
    }
}
