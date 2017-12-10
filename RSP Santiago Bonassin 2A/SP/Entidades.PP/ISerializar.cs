using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace Entidades.PP
{
    public interface ISerializar
    {
        bool Xml(string path);
    }
}
