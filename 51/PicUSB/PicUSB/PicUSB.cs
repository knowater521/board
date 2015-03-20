using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics; //Clase para abrir página web

namespace PicUSB
{
    public partial class PicUSB : Form
    {
        PicUSBAPI usbapi = new PicUSBAPI();
        
        public PicUSB()
        {
            InitializeComponent();
        }

        private void leds_off_Click(object sender, EventArgs e)
        {
            usbapi.LedPIC(0x00);    //codigo para apagar los leds
        }

        private void led_verde_Click(object sender, EventArgs e)
        {
            usbapi.LedPIC(0x01);    //codigo para encender led verde
        }

        private void led_rojo_Click(object sender, EventArgs e)
        {
            usbapi.LedPIC(0x02);    //codigo para encender led rojo
        }

        private void PICsuma_Click(object sender, EventArgs e)
        {
            usbapi.SumaPIC(uint.Parse(sumando1.Text), uint.Parse(sumando2.Text));
            resultado.Text = (usbapi.ResultadoPIC()).ToString();
        }

        private void avatar_Click(object sender, EventArgs e)
        {
            Process.Start("http://www.hobbypic.com");
        }
    }
}