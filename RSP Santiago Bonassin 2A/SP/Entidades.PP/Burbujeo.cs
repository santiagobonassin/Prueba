using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Entidades.PP
{
    public class Burbujeo
    {
        int flag = 0;
        public void Excepcion()
        {                               
                StreamWriter sw = new StreamWriter("Burbujeo.txt", true);
                sw.WriteLine("Metodo de Instancia" + DateTime.Now);
                sw.Close();
                throw new MiException();     
        }
        public static void MetodoClase()
        {
            try
            {
                Burbujeo excepcion = new Burbujeo();
                excepcion.Excepcion(); 
            }
            catch
            {
                StreamWriter sw = new StreamWriter("Burbujeo.txt", true);
                sw.WriteLine("Metodo estatico" + DateTime.Now);
                sw.Close();
            }
                           
        }
       
        public static string LeerArchivoDeTexto()
        {
            string retorno;
            StreamReader sr = new StreamReader("Burbujeo.txt", true);
            retorno = sr.ReadToEnd();
            sr.Close();
            return retorno;
        }
    }
}
