namespace PicUSB
{
    partial class PicUSB
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PicUSB));
            this.avatar = new System.Windows.Forms.PictureBox();
            this.led_rojo = new System.Windows.Forms.Button();
            this.led_verde = new System.Windows.Forms.Button();
            this.leds_off = new System.Windows.Forms.Button();
            this.PICsuma = new System.Windows.Forms.Button();
            this.resultado = new System.Windows.Forms.TextBox();
            this.sumando2 = new System.Windows.Forms.TextBox();
            this.sumando1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.avatar)).BeginInit();
            this.SuspendLayout();
            // 
            // avatar
            // 
            this.avatar.AutoSize = true;
            this.avatar.Cursor = System.Windows.Forms.Cursors.Hand;
            this.avatar.Image = ((System.Drawing.Image)(resources.GetObject("avatar.Image")));
            this.avatar.Location = new System.Drawing.Point(137, 68);
            this.avatar.Name = "avatar";
            this.avatar.Size = new System.Drawing.Size(75, 66);
            this.avatar.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.avatar.TabIndex = 34;
            this.avatar.TabStop = false;
            this.avatar.Click += new System.EventHandler(this.avatar_Click);
            // 
            // led_rojo
            // 
            this.led_rojo.Location = new System.Drawing.Point(12, 119);
            this.led_rojo.Name = "led_rojo";
            this.led_rojo.Size = new System.Drawing.Size(95, 25);
            this.led_rojo.TabIndex = 33;
            this.led_rojo.Text = "LED ROJO ON";
            this.led_rojo.Click += new System.EventHandler(this.led_rojo_Click);
            // 
            // led_verde
            // 
            this.led_verde.Location = new System.Drawing.Point(12, 87);
            this.led_verde.Name = "led_verde";
            this.led_verde.Size = new System.Drawing.Size(95, 25);
            this.led_verde.TabIndex = 32;
            this.led_verde.Text = "LED VERDE ON";
            this.led_verde.Click += new System.EventHandler(this.led_verde_Click);
            // 
            // leds_off
            // 
            this.leds_off.Location = new System.Drawing.Point(12, 56);
            this.leds_off.Name = "leds_off";
            this.leds_off.Size = new System.Drawing.Size(95, 25);
            this.leds_off.TabIndex = 31;
            this.leds_off.Text = "LEDS OFF";
            this.leds_off.Click += new System.EventHandler(this.leds_off_Click);
            // 
            // PICsuma
            // 
            this.PICsuma.Location = new System.Drawing.Point(108, 9);
            this.PICsuma.Name = "PICsuma";
            this.PICsuma.Size = new System.Drawing.Size(75, 25);
            this.PICsuma.TabIndex = 30;
            this.PICsuma.Text = "PIC Suma!";
            this.PICsuma.Click += new System.EventHandler(this.PICsuma_Click);
            // 
            // resultado
            // 
            this.resultado.Location = new System.Drawing.Point(199, 12);
            this.resultado.MaxLength = 3;
            this.resultado.Name = "resultado";
            this.resultado.Size = new System.Drawing.Size(29, 20);
            this.resultado.TabIndex = 29;
            // 
            // sumando2
            // 
            this.sumando2.Location = new System.Drawing.Point(62, 12);
            this.sumando2.MaxLength = 2;
            this.sumando2.Name = "sumando2";
            this.sumando2.Size = new System.Drawing.Size(29, 20);
            this.sumando2.TabIndex = 27;
            // 
            // sumando1
            // 
            this.sumando1.Location = new System.Drawing.Point(12, 12);
            this.sumando1.MaxLength = 2;
            this.sumando1.Name = "sumando1";
            this.sumando1.Size = new System.Drawing.Size(29, 20);
            this.sumando1.TabIndex = 26;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(47, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(9, 14);
            this.label1.TabIndex = 35;
            this.label1.Text = "+";
            // 
            // PicUSB
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(240, 154);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.avatar);
            this.Controls.Add(this.led_rojo);
            this.Controls.Add(this.led_verde);
            this.Controls.Add(this.leds_off);
            this.Controls.Add(this.PICsuma);
            this.Controls.Add(this.resultado);
            this.Controls.Add(this.sumando2);
            this.Controls.Add(this.sumando1);
            this.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.MaximizeBox = false;
            this.Name = "PicUSB";
            this.Text = "PicUSB";
            ((System.ComponentModel.ISupportInitialize)(this.avatar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox avatar;
        private System.Windows.Forms.Button led_rojo;
        private System.Windows.Forms.Button led_verde;
        private System.Windows.Forms.Button leds_off;
        private System.Windows.Forms.Button PICsuma;
        private System.Windows.Forms.TextBox resultado;
        private System.Windows.Forms.TextBox sumando2;
        private System.Windows.Forms.TextBox sumando1;
        private System.Windows.Forms.Label label1;


    }
}

