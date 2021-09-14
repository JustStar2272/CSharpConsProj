using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace GetUserName
{
    public partial class Form1 : Form
    {
        //public string username;
        public Form1()
        {
            InitializeComponent();
        }
       
        [DllImport("secur32.dll", CharSet = CharSet.Auto)]
        public static extern int GetUserNameEx(int nameFormat, StringBuilder userName, ref uint userNameSize);
        private void button1_Click(object sender, EventArgs e)
        {


            StringBuilder stringBuilder = new StringBuilder(100);
            uint num = 100U;
            GetUserNameEx(2, stringBuilder, ref num);
            this.label1.Text = string.Format("Имя пользователя: {0}", stringBuilder.ToString());
            //
            // IntPtr.Zero
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    
        public class WinAPIClass
        {
            #region Получение имени текущего пользователя
            /// <summary>
            /// Получение имени текущего пользователя.
            /// </summary>
            /// <param name="nameFormat">Формат имени из перечисления NameFormat.</param>
            /// <param name="userName">Выходной параметр - имя.пользователя</param>
            /// <param name="userNameSize">Количество символов в имени.</param>
            /// <returns></returns>
          

            /// <summary>
            /// Формат имени.
            /// </summary>
            public enum NameFormat : int
            {
                NameUnknown = 0,
                NameFullyQualifiedDN = 1,
                NameSamCompatible = 2,
                NameDisplay = 3,
                NameUniqueId = 6,
                NameCanonical = 7,
                NameUserPrincipal = 8,
                NameCanonicalEx = 9,
                NameServicePrincipal = 10,
                NameDnsDomain = 12
            };
            #endregion

        }
    }


}

