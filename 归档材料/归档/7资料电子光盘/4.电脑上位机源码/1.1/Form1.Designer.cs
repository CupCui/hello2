namespace _1._1
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnOpen = new System.Windows.Forms.Button();
            this.cmbPort = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cmbBaud = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.label4 = new System.Windows.Forms.Label();
            this.DIS2 = new System.Windows.Forms.RichTextBox();
            this.DIS1 = new System.Windows.Forms.RichTextBox();
            this.DIS3 = new System.Windows.Forms.RichTextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.DIS4 = new System.Windows.Forms.RichTextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.DIS9 = new System.Windows.Forms.RichTextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.DIS5 = new System.Windows.Forms.RichTextBox();
            this.DIS6 = new System.Windows.Forms.RichTextBox();
            this.DIS8 = new System.Windows.Forms.RichTextBox();
            this.DIS7 = new System.Windows.Forms.RichTextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.编辑ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem,
            this.编辑ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(464, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(44, 21);
            this.文件ToolStripMenuItem.Text = "文件";
            // 
            // btnOpen
            // 
            this.btnOpen.Location = new System.Drawing.Point(350, 28);
            this.btnOpen.Name = "btnOpen";
            this.btnOpen.Size = new System.Drawing.Size(93, 29);
            this.btnOpen.TabIndex = 1;
            this.btnOpen.Text = "打开串口";
            this.btnOpen.UseVisualStyleBackColor = true;
            this.btnOpen.Click += new System.EventHandler(this.btnOpen_Click);
            // 
            // cmbPort
            // 
            this.cmbPort.FormattingEnabled = true;
            this.cmbPort.Location = new System.Drawing.Point(59, 33);
            this.cmbPort.Name = "cmbPort";
            this.cmbPort.Size = new System.Drawing.Size(101, 20);
            this.cmbPort.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "串口：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(175, 36);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 5;
            this.label2.Text = "波特率：";
            // 
            // cmbBaud
            // 
            this.cmbBaud.FormattingEnabled = true;
            this.cmbBaud.Items.AddRange(new object[] {
            "9600",
            "115200"});
            this.cmbBaud.Location = new System.Drawing.Point(234, 33);
            this.cmbBaud.Name = "cmbBaud";
            this.cmbBaud.Size = new System.Drawing.Size(101, 20);
            this.cmbBaud.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 128);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 7;
            this.label3.Text = "厨余垃圾：";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 166);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 9;
            this.label4.Text = "其他垃圾：";
            // 
            // DIS2
            // 
            this.DIS2.Location = new System.Drawing.Point(83, 163);
            this.DIS2.Name = "DIS2";
            this.DIS2.ReadOnly = true;
            this.DIS2.Size = new System.Drawing.Size(145, 23);
            this.DIS2.TabIndex = 8;
            this.DIS2.Text = "";
            // 
            // DIS1
            // 
            this.DIS1.Location = new System.Drawing.Point(83, 125);
            this.DIS1.Name = "DIS1";
            this.DIS1.ReadOnly = true;
            this.DIS1.Size = new System.Drawing.Size(145, 23);
            this.DIS1.TabIndex = 10;
            this.DIS1.Text = "";
            // 
            // DIS3
            // 
            this.DIS3.Location = new System.Drawing.Point(83, 201);
            this.DIS3.Name = "DIS3";
            this.DIS3.ReadOnly = true;
            this.DIS3.Size = new System.Drawing.Size(145, 23);
            this.DIS3.TabIndex = 14;
            this.DIS3.Text = "";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 242);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(65, 12);
            this.label5.TabIndex = 13;
            this.label5.Text = "可回收物：";
            // 
            // DIS4
            // 
            this.DIS4.Location = new System.Drawing.Point(83, 239);
            this.DIS4.Name = "DIS4";
            this.DIS4.ReadOnly = true;
            this.DIS4.Size = new System.Drawing.Size(145, 23);
            this.DIS4.TabIndex = 12;
            this.DIS4.Text = "";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 204);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(65, 12);
            this.label6.TabIndex = 11;
            this.label6.Text = "有害垃圾：";
            // 
            // DIS9
            // 
            this.DIS9.Location = new System.Drawing.Point(83, 86);
            this.DIS9.Name = "DIS9";
            this.DIS9.ReadOnly = true;
            this.DIS9.Size = new System.Drawing.Size(145, 23);
            this.DIS9.TabIndex = 16;
            this.DIS9.Text = "";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 89);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 15;
            this.label7.Text = "指令数：";
            // 
            // DIS5
            // 
            this.DIS5.Location = new System.Drawing.Point(305, 125);
            this.DIS5.Name = "DIS5";
            this.DIS5.ReadOnly = true;
            this.DIS5.Size = new System.Drawing.Size(140, 23);
            this.DIS5.TabIndex = 17;
            this.DIS5.Text = "";
            // 
            // DIS6
            // 
            this.DIS6.Location = new System.Drawing.Point(305, 163);
            this.DIS6.Name = "DIS6";
            this.DIS6.ReadOnly = true;
            this.DIS6.Size = new System.Drawing.Size(138, 23);
            this.DIS6.TabIndex = 18;
            this.DIS6.Text = "";
            // 
            // DIS8
            // 
            this.DIS8.Location = new System.Drawing.Point(305, 239);
            this.DIS8.Name = "DIS8";
            this.DIS8.ReadOnly = true;
            this.DIS8.Size = new System.Drawing.Size(138, 23);
            this.DIS8.TabIndex = 20;
            this.DIS8.Text = "";
            // 
            // DIS7
            // 
            this.DIS7.Location = new System.Drawing.Point(305, 201);
            this.DIS7.Name = "DIS7";
            this.DIS7.ReadOnly = true;
            this.DIS7.Size = new System.Drawing.Size(138, 23);
            this.DIS7.TabIndex = 19;
            this.DIS7.Text = "";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(234, 128);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(65, 12);
            this.label8.TabIndex = 21;
            this.label8.Text = "打开次数：";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(232, 166);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(65, 12);
            this.label9.TabIndex = 22;
            this.label9.Text = "打开次数：";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(232, 204);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(65, 12);
            this.label10.TabIndex = 23;
            this.label10.Text = "打开次数：";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(232, 242);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(65, 12);
            this.label11.TabIndex = 24;
            this.label11.Text = "打开次数：";
            // 
            // 编辑ToolStripMenuItem
            // 
            this.编辑ToolStripMenuItem.Name = "编辑ToolStripMenuItem";
            this.编辑ToolStripMenuItem.Size = new System.Drawing.Size(44, 21);
            this.编辑ToolStripMenuItem.Text = "编辑";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(464, 296);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.DIS8);
            this.Controls.Add(this.DIS7);
            this.Controls.Add(this.DIS6);
            this.Controls.Add(this.DIS5);
            this.Controls.Add(this.DIS9);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.DIS3);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.DIS4);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.DIS1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.DIS2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.cmbBaud);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cmbPort);
            this.Controls.Add(this.btnOpen);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "我";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.ComboBox cmbPort;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cmbBaud;
        private System.Windows.Forms.Label label3;
        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RichTextBox DIS2;
        private System.Windows.Forms.RichTextBox DIS1;
        private System.Windows.Forms.RichTextBox DIS3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.RichTextBox DIS4;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.RichTextBox DIS9;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.RichTextBox DIS5;
        private System.Windows.Forms.RichTextBox DIS6;
        private System.Windows.Forms.RichTextBox DIS8;
        private System.Windows.Forms.RichTextBox DIS7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ToolStripMenuItem 编辑ToolStripMenuItem;
    }
}

