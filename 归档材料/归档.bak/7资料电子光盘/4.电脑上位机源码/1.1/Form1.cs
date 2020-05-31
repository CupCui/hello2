using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._1
{
    public partial class MainForm : Form
    {
        bool isOpened = false;//串口状态标志

        public MainForm()
        {
            InitializeComponent();
            System.Windows.Forms.Control.CheckForIllegalCrossThreadCalls = false;//设置该属性 为false
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            RegistryKey keyCom = Registry.LocalMachine.OpenSubKey("Hardware\\DeviceMap\\SerialComm");
            if (keyCom != null)
            {
                string[] sSubKeys = keyCom.GetValueNames();
                cmbPort.Items.Clear();
                foreach (string sName in sSubKeys)
                {
                    string sValue = (string)keyCom.GetValue(sName);
                    cmbPort.Items.Add(sValue);
                }
                if (cmbPort.Items.Count > 0)
                    cmbPort.SelectedIndex = 0;
            }
            cmbBaud.Text = "9600";
        }

        /*************打开串口处理函数***********/
        private void btnOpen_Click(object sender, EventArgs e)
        {
            if (!isOpened)
            {
                serialPort.PortName = cmbPort.Text;
                serialPort.BaudRate = Convert.ToInt32(cmbBaud.Text, 10);
                try
                {
                    serialPort.Open();     //打开串口
                    btnOpen.Text = "关闭串口";
                    cmbPort.Enabled = false;//关闭使能
                    cmbBaud.Enabled = false;
                    isOpened = true;
                    serialPort.DataReceived += new SerialDataReceivedEventHandler(post_DataReceived);//串口接收处理函数
                }
                catch
                {
                    MessageBox.Show("串口打开失败！");
                }
            }
            else
            {
                try
                {
                    serialPort.Close();     //关闭串口
                    btnOpen.Text = "打开串口";
                    cmbPort.Enabled = true;//打开使能
                    cmbBaud.Enabled = true;
                    isOpened = false;
                }
                catch
                {
                    MessageBox.Show("串口关闭失败！");
                }
            }
        }

        /*************串口接收数据处理函数***********/
        private void post_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            byte[] ReadBuff = new byte[128];//接收数据缓存
            int len = 0;

            Array.Clear(ReadBuff, 0, 128);

            while (true)
            {
                if (serialPort.BytesToRead != 0)
                    ReadBuff[len++] = (byte)serialPort.ReadByte();
                else
                    break;
            }
            if (ReadBuff[0] == 'L' && ReadBuff[1] == 'J')//包认证
            {
                if (ReadBuff[2] == '1')
                {
                    DIS1.Text = "打开";
                }
                else
                {
                    DIS1.Text = "关闭";
                }

                if (ReadBuff[3] == '1')
                {
                    DIS2.Text = "打开";
                }
                else
                {
                    DIS2.Text = "关闭";
                }

                if (ReadBuff[4] == '1')
                {
                    DIS3.Text = "打开";
                }
                else
                {
                    DIS3.Text = "关闭";
                }

                if (ReadBuff[5] == '1')
                {
                    DIS4.Text = "打开";
                }
                else
                {
                    DIS4.Text = "关闭";
                }

                DIS5.Text = ReadBuff[6].ToString();
                DIS6.Text = ReadBuff[7].ToString();
                DIS7.Text = ReadBuff[8].ToString();
                DIS8.Text = ReadBuff[9].ToString();
                DIS9.Text = ReadBuff[10].ToString();
            }
        }  
    }
}
