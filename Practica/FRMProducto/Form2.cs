
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
    public partial class Form2 : Form
    {
        public int id;
        public string nombre;
        public int precio;
        public Local.TipoProducto producto;

        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            id = int.Parse(this.textBox1.Text);
            nombre = this.textBox2.Text;
            precio = int.Parse(this.textBox3.Text);

            if (this.comboBox1.Text == "CPU")
            {
                producto = Local.TipoProducto.Procesador;
            }
            else if (this.comboBox1.Text == "Placa de Video")
            {
                producto = Local.TipoProducto.PlacaDeVideo;
            }
            else if (this.comboBox1.Text == "RAM")
            {
                producto = Local.TipoProducto.RAM;
            }
            else if (this.comboBox1.Text == "Gabinete")
            {
                producto = Local.TipoProducto.Gabinete;
            }
            this.DialogResult = DialogResult.OK;
        }
    }
}
