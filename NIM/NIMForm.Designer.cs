namespace NIM
{
    partial class NIMForm
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
            this.serverListBox = new System.Windows.Forms.ListBox();
            this.myNameTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.gameBox = new System.Windows.Forms.GroupBox();
            this.statusLabel = new System.Windows.Forms.Label();
            this.ForfeitButton = new System.Windows.Forms.Button();
            this.MessageTB = new System.Windows.Forms.TextBox();
            this.MessageSendButton = new System.Windows.Forms.Button();
            this.MessageTextBox = new System.Windows.Forms.Label();
            this.MessageLabel = new System.Windows.Forms.Label();
            this.AICheckBox = new System.Windows.Forms.CheckBox();
            this.HostGameButton = new System.Windows.Forms.Button();
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
            this.connectButton.Location = new System.Drawing.Point(208, 234);
            this.connectButton.Name = "connectButton";
            this.connectButton.Size = new System.Drawing.Size(136, 48);
            this.connectButton.TabIndex = 3;
            this.connectButton.Text = "Connect";
            this.connectButton.UseVisualStyleBackColor = true;
            this.connectButton.Click += new System.EventHandler(this.connectButton_Click);
            // 
            // updateButton
            // 
            this.updateButton.Location = new System.Drawing.Point(50, 234);
            this.updateButton.Name = "updateButton";
            this.updateButton.Size = new System.Drawing.Size(152, 48);
            this.updateButton.TabIndex = 4;
            this.updateButton.Text = "Update List";
            this.updateButton.UseVisualStyleBackColor = true;
            this.updateButton.Click += new System.EventHandler(this.updateButton_Click);
            // 
            // serverListBox
            // 
            this.serverListBox.FormattingEnabled = true;
            this.serverListBox.ItemHeight = 25;
            this.serverListBox.Location = new System.Drawing.Point(17, 95);
            this.serverListBox.Name = "serverListBox";
            this.serverListBox.Size = new System.Drawing.Size(327, 129);
            this.serverListBox.TabIndex = 5;
            // 
            // myNameTextBox
            // 
            this.myNameTextBox.Location = new System.Drawing.Point(136, 12);
            this.myNameTextBox.Name = "myNameTextBox";
            this.myNameTextBox.Size = new System.Drawing.Size(208, 31);
            this.myNameTextBox.TabIndex = 6;
            this.myNameTextBox.TextChanged += new System.EventHandler(this.myNameTextBox_TextChanged);
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
            this.gameBox.Location = new System.Drawing.Point(395, 56);
            this.gameBox.Name = "gameBox";
            this.gameBox.Size = new System.Drawing.Size(859, 385);
            this.gameBox.TabIndex = 8;
            this.gameBox.TabStop = false;
            this.gameBox.Text = "Current Game";
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Location = new System.Drawing.Point(390, 12);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(86, 25);
            this.statusLabel.TabIndex = 9;
            this.statusLabel.Text = "Starting";
            // 
            // ForfeitButton
            // 
            this.ForfeitButton.Location = new System.Drawing.Point(1118, 12);
            this.ForfeitButton.Name = "ForfeitButton";
            this.ForfeitButton.Size = new System.Drawing.Size(136, 48);
            this.ForfeitButton.TabIndex = 10;
            this.ForfeitButton.Text = "Forefeit";
            this.ForfeitButton.UseVisualStyleBackColor = true;
            this.ForfeitButton.Click += new System.EventHandler(this.ForfeitButton_Click);
            // 
            // MessageTB
            // 
            this.MessageTB.Location = new System.Drawing.Point(395, 507);
            this.MessageTB.Name = "MessageTB";
            this.MessageTB.Size = new System.Drawing.Size(735, 31);
            this.MessageTB.TabIndex = 11;
            // 
            // MessageSendButton
            // 
            this.MessageSendButton.Location = new System.Drawing.Point(1136, 503);
            this.MessageSendButton.Name = "MessageSendButton";
            this.MessageSendButton.Size = new System.Drawing.Size(118, 39);
            this.MessageSendButton.TabIndex = 12;
            this.MessageSendButton.Text = "Send";
            this.MessageSendButton.UseVisualStyleBackColor = true;
            this.MessageSendButton.Click += new System.EventHandler(this.MessageSendButton_Click);
            // 
            // MessageTextBox
            // 
            this.MessageTextBox.AutoSize = true;
            this.MessageTextBox.Location = new System.Drawing.Point(395, 459);
            this.MessageTextBox.Name = "MessageTextBox";
            this.MessageTextBox.Size = new System.Drawing.Size(18, 25);
            this.MessageTextBox.TabIndex = 13;
            this.MessageTextBox.Text = " ";
            // 
            // MessageLabel
            // 
            this.MessageLabel.AutoSize = true;
            this.MessageLabel.Location = new System.Drawing.Point(395, 459);
            this.MessageLabel.Name = "MessageLabel";
            this.MessageLabel.Size = new System.Drawing.Size(18, 25);
            this.MessageLabel.TabIndex = 14;
            this.MessageLabel.Text = " ";
            // 
            // AICheckBox
            // 
            this.AICheckBox.AutoSize = true;
            this.AICheckBox.Location = new System.Drawing.Point(17, 509);
            this.AICheckBox.Name = "AICheckBox";
            this.AICheckBox.Size = new System.Drawing.Size(236, 29);
            this.AICheckBox.TabIndex = 16;
            this.AICheckBox.Text = "Make Moves with AI";
            this.AICheckBox.UseVisualStyleBackColor = true;
            // 
            // HostGameButton
            // 
            this.HostGameButton.Enabled = false;
            this.HostGameButton.Location = new System.Drawing.Point(208, 288);
            this.HostGameButton.Name = "HostGameButton";
            this.HostGameButton.Size = new System.Drawing.Size(136, 48);
            this.HostGameButton.TabIndex = 17;
            this.HostGameButton.Text = "Host Game";
            this.HostGameButton.UseVisualStyleBackColor = true;
            this.HostGameButton.Click += new System.EventHandler(this.HostGameButton_Click);
            // 
            // NIMForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1281, 550);
            this.Controls.Add(this.HostGameButton);
            this.Controls.Add(this.AICheckBox);
            this.Controls.Add(this.MessageLabel);
            this.Controls.Add(this.MessageTextBox);
            this.Controls.Add(this.MessageSendButton);
            this.Controls.Add(this.MessageTB);
            this.Controls.Add(this.ForfeitButton);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.gameBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.myNameTextBox);
            this.Controls.Add(this.serverListBox);
            this.Controls.Add(this.updateButton);
            this.Controls.Add(this.connectButton);
            this.Controls.Add(this.label1);
            this.Name = "NIMForm";
            this.Text = "NIM";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.Button updateButton;
        private System.Windows.Forms.ListBox serverListBox;
        private System.Windows.Forms.TextBox myNameTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox gameBox;
        private System.Windows.Forms.Label statusLabel;
        private System.Windows.Forms.Button ForfeitButton;
        private System.Windows.Forms.TextBox MessageTB;
        private System.Windows.Forms.Button MessageSendButton;
        private System.Windows.Forms.Label MessageTextBox;
        private System.Windows.Forms.Label MessageLabel;
        private System.Windows.Forms.CheckBox AICheckBox;
        private System.Windows.Forms.Button HostGameButton;
    }
}

