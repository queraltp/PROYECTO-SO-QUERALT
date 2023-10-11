using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System;

namespace cliente_ej_guia_forms
{
    public partial class Program
    {
        Socket server;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form_load (object sender, EventArgs e)
        {
          
        }
        private void button2_Click(object sender, EventArgs e)
        {
            // Creamos un IPEndPoint con el ip del servidor y puerto del servidor al que deseamos conectarnos
            IPAdress direc = IPAdress.Parse("192.98.75.102");
            IPEndPointPoint ipep = new IPEndPoint(direc, 9070);

            //Creamos el socket
            server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                server.Connect(ipep); //Intentamos conectar el socket
                this.BackColor = Color.Green;
            // MessageBox.Show ("Conectado);
                if (Longitud.checked)
                {
                        string mensaje = "1/" + nombre.Text;
                        //enviamos servidor nombre tecleado
                        byet[] msg = System.Text.Encoding:ASCII.GetBytes(mensaje);
                        server.Send(msg);

                        //recibimos respuesta servidor
                        byet[] msg2 = new byte[80];
                        server.Recive(msg2);
                        mensaje = Encoding.ASCII.GetString(mgs2).Split('\0')[0];
                        MessageBox.Show("La longitud de tu nombre es: " + mensaje);

                }
                else
                {
                        string mensaje = "2/" + nombre.Text;
                        //enviamos servidor nombre tecleado
                        byet[] msg = System.Text.Encoding:ASCII.GetBytes(mensaje);
                        server.Send(msg);

                        //recibimos respuesta servidor
                        byet[] msg2 = new byte[80];
                        server.Recive(msg2);
                        mensaje = Encoding.ASCII.GetString(mgs2).Split('\0')[0];

                        if (mensaje == "SI")
                            MessageBox.Show("Tu nombre es bonito");
                        else
                            MessageBox.Show("Tu nombre no es bonito");


                }
                 // se termin el servicio
                 //nos desconectamos
                 this.BackColour = Color.Grey;
                    server.Shutdown(SocketShutdown.Both);
                    server.Close();

            }

        }
    }
}
