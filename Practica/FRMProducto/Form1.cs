using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace FRMProducto
{
    public partial class FRMProducto : Form
    {
        public Local producto;
        public int id;
        public string nombreProducto;
        public int precio;
        public Local.TipoProducto tipoProducto;       

        public FRMProducto()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 compraProducto = new Form2();
            compraProducto.ShowDialog();
            if(compraProducto.DialogResult == DialogResult.OK)
            {
                id = compraProducto.id;
                nombreProducto = compraProducto.nombre;
                precio = compraProducto.precio;
                tipoProducto = compraProducto.producto;
                producto = new Local(id, nombreProducto, precio, tipoProducto);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Local.Guardar(producto, EventArgs.Empty);
        }

        private void FRMProducto_Load(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                Local.Serializar(producto, EventArgs.Empty);
            }
            catch(Exception)
            {
                
            }             
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                Local l1 = Local.Deserealizar(producto, EventArgs.Empty);
                if(l1!=null)
                {
                   this.listBox1.Items.Add(l1.ToString());
                }
                
            }
            catch(Exception)
            {
                
            }
        }
    }
}
