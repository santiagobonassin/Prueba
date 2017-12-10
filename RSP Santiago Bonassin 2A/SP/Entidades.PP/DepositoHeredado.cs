using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace Entidades.PP
{
    public class DepositoHeredado:Deposito, ISerializar, IDeserealizar
    {
        public bool Xml(string path)
        {
            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(DepositoHeredado));
                StreamWriter sw = new StreamWriter(path, false);
                serializer.Serialize(sw, this);
                sw.Close();
                return true;
            }
            catch (Exception e)
            {
                return false;
            }
        }
        bool IDeserealizar.Xml(string path, out DepositoHeredado d1)
        {
            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(DepositoHeredado));
                StreamReader sr = new StreamReader(path);
                d1= (DepositoHeredado)serializer.Deserialize(sr);
                sr.Close();
                return true;
            }
            catch (Exception e)
            {
                d1 = null;
                return false;
            }
        }
    }
}
