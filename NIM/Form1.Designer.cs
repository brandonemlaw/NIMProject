namespace NIM
{
    partial class Form1
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
            this.label1 = new System.Windows.Forms.Label();
            this.connectButton = new System.Windows.Forms.Button();
            this.updateButton = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.myNameTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.gameBox = new System.Windows.Forms.GroupBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 66);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(180, 25);
            this.label1.TabIndex = 2;
            this.label1.Text = "Avaliable Servers";
            // 
            // connectButton
            // 
            this.connectButton.Location = new System.Drawing.Point(235, 234);
            this.connectButton.Name = "connectButton";
            this.connectButton.Size = new System.Drawing.Size(109, 34);
            this.connectButton.TabIndex = 3;
            this.connectButton.Text = "Connect";
            this.connectButton.UseVisualStyleBackColor = true;
            // 
            // updateButton
            // 
            this.updateButton.Location = new System.Drawing.Point(87, 234);
            this.updateButton.Name = "updateButton";
            this.updateButton.Size = new System.Drawing.Size(133, 34);
            this.updateButton.TabIndex = 4;
            this.updateButton.Text = "Update List";
            this.updateButton.UseVisualStyleBackColor = true;
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 25;
            this.listBox1.Location = new System.Drawing.Point(17, 95);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(327, 129);
            this.listBox1.TabIndex = 5;
            // 
            // myNameTextBox
            // 
            this.myNameTextBox.Location = new System.Drawing.Point(136, 12);
            this.myNameTextBox.Name = "myNameTextBox";
            this.myNameTextBox.Size = new System.Drawing.Size(208, 31);
            this.myNameTextBox.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(103, 25);
            this.label2.TabIndex = 7;
            this.label2.Text = "My Name";
            // 
            // gameBox
            // 
            this.gameBox.Location = new System.Drawing.Point(395, 13);
            this.gameBox.Name = "gameBox";
            this.gameBox.Size = new System.Drawing.Size(859, 453);
            this.gameBox.TabIndex = 8;
            this.gameBox.TabStop = false;
            this.gameBox.Text = "Current Game";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1281, 550);
            this.Controls.Add(this.gameBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.myNameTextBox);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.updateButton);
            this.Controls.Add(this.connectButton);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "NIM";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.Button updateButton;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TextBox myNameTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox gameBox;
    }
}

