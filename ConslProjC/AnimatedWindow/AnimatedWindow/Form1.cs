using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace AnimatedWindow
{
    public class WinAPIClass
    {
        #region Анимация окна
        /// <summary>
        /// Тип анимации окна. Перечисление возвращает тип данных int
        /// после приведения. Каждому элементу перечисления присвоено 
        /// свое значение типа int.
        /// </summary>	
        [Flags]
        public enum AnimateWindowFlags : int
        {
            AW_HOR_POSITIVE = 1,
            AW_HOR_NEGATIVE = 2,
            AW_VER_POSITIVE = 4,
            AW_VER_NEGATIVE = 8,
            AW_CENTER = 16,
            AW_HIDE = 65536,
            AW_ACTIVATE = 131072,
            AW_SLIDE = 262144,
            AW_BLEND = 524288
        };

        /// <summary>
        /// Анимация окна.
        /// </summary>
        /// <param name="hwnd">Окно.</param>
        /// <param name="dwTime">Время.</param>
        /// <param name="dwFlags">Тип анимации. Если в неуправляемом 
        /// коде используется перечисление, то его нужно конвертировать
        /// в тип данных int. </param>			
        /// <returns></returns>
        [DllImportAttribute("user32.dll", EntryPoint = "AnimateWindow", SetLastError = true)]
        public static extern bool AnimateWindow(IntPtr hwnd, int dwTime, int dwFlags);

        /// <summary>
        /// Анимация окна.
        /// </summary>
        /// <param name="ctrl">Окно.</param>
        /// <param name="dwTime">Время.</param>
        /// <param name="Flags">Флаги.</param>		
        /// <returns></returns>
        public static bool AnimateWindow(Control ctrl, int dwTime, AnimateWindowFlags Flags)
        {
            return AnimateWindow(ctrl.Handle, dwTime, (int)Flags);
        }
        #endregion
    }
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            base.Hide();
            WinAPIClass.AnimateWindow(this, 3000, WinAPIClass.AnimateWindowFlags.AW_ACTIVATE | WinAPIClass.AnimateWindowFlags.AW_BLEND);
            this.button1.Invalidate();
            this.button2.Invalidate();
            this.button3.Invalidate();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            base.Hide();
            WinAPIClass.AnimateWindow(this, 3000, WinAPIClass.AnimateWindowFlags.AW_HOR_POSITIVE | WinAPIClass.AnimateWindowFlags.AW_SLIDE);
            this.button1.Invalidate();
            this.button2.Invalidate();
            this.button3.Invalidate();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            base.Hide();
            WinAPIClass.AnimateWindow(this, 3000, WinAPIClass.AnimateWindowFlags.AW_CENTER | WinAPIClass.AnimateWindowFlags.AW_SLIDE);
            this.button1.Invalidate();
            this.button2.Invalidate();
            this.button3.Invalidate();
        }
    }
}
