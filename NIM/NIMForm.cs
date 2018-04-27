using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace NIM
{
    


    public partial class NIMForm : Form
    {

        //Constants
        private int SERVER_LIST_LENGTH = 10000;

        //Mode enum
        enum Mode {Abort, Waiting, Client, Server};

        //Class attributes
        Mode currentMode = Mode.Waiting;
        NIM.BoardReturn currentBoard;
        string opponentName = "";

        public NIMForm()
        {
            Application.Idle += HandleApplicationIdle;
            InitializeComponent();

            //Set the default text box name
            myNameTextBox.Text = Environment.UserName;

            //Set name
            NIMNetwork.GUI_setMyName(myNameTextBox.Text);

            //Run initial scan for servers
            ClientScanForServers();

        }

        void SelectMove(int row, int number)
        {
            NIMNetwork.GUI_makeMove(row, number);
            currentBoard.decreaseRow(row, (ulong)number);
            UpdateDisplayBoard();
        }

        void UpdateDisplayBoard()
        {
            gameBox.Controls.Clear();

            for (int j = 0; j < 9; j++)
            {
                ulong stonesInRow = currentBoard.getRow(j);
                for (ulong i = 0; i < stonesInRow; i++)
                {
                    RadioButton temp = new RadioButton();
                    //temp.Location = new Point(100 + (int)i * 3, j * 3);
                    int row = j;
                    int stones = (int)(stonesInRow - i);
                    temp.Location = new Point(5 + 20 * (int)i, 20 + 20 * j);
                    temp.Size = new Size(20, 20);
                    temp.Click += delegate { SelectMove(row, stones); };
                    gameBox.Controls.Add(temp);
                }
                //gameBox.Controls.Add(row);
            }
        }

        void ClientScanForServers()
        {
            //Get the servers from the DLL
            StringBuilder serverList = new StringBuilder(SERVER_LIST_LENGTH);
            NIMNetwork.GUI_getServerList(serverList);

            //Separate the list
            String listResult = serverList.ToString();
            String[] serverArray = listResult.Split('\n');

            //Clear the list box
            serverListBox.Items.Clear();

            //Add each server to the listBox
            for (int i = 0; i < serverArray.Length - 1; i++)
            {
                serverListBox.Items.Add(serverArray[i]);
            }
        }

        //This is the main update loop
        void MyUpdate()
        {
            //If we are operating as a client
            if (currentMode == Mode.Client)
            {
                //check for messages
                StringBuilder messageString = new StringBuilder(NIMNetwork.DATA_BUFFER_SIZE);
                NIMNetwork.GUI_getMessage(messageString);
                if (messageString.ToString() != "")
                {
                    MessageLabel.Text = messageString.ToString();
                }


                //check game status
                int status = NIMNetwork.GUI_gameStatus();
                if (status == 0)
                {

                    if (!NIMNetwork.GUI_isMyTurn())
                    {
                        statusLabel.Text = "Waiting for opponent.";
                        gameBox.Enabled = false;
                        currentBoard = NIMNetwork.GUI_getBoard();
                        if (NIMNetwork.GUI_isMyTurn())
                        {
                            UpdateDisplayBoard();
                        }
                    }
                    else
                    {
                        if (AICheckBox.Checked)
                        {
                            currentBoard = NIMNetwork.GUI_getAIMoveBoard();
                            if (!NIMNetwork.GUI_isMyTurn())
                            {
                                UpdateDisplayBoard();
                            }
                        }
                        else
                        {
                            statusLabel.Text = "Please make a move.";
                            gameBox.Enabled = true;
                        }

                    }
                }
                else if (status == 1)
                {
                    endGame("Congrats! You won!");
                }
                else
                {
                    endGame("Sorry. You lost.");
                }
            }
        }

        void endGame(string message)
        {
            System.Windows.Forms.MessageBox.Show(message);
            statusLabel.Text = message; currentMode = Mode.Waiting;

            serverListBox.Enabled = true;
            connectButton.Enabled = true;
            updateButton.Enabled = true;
            ForfeitButton.Enabled = false;
            MessageSendButton.Enabled = false;
        }

        void MyRender()
        {
            // ...
        }

        
        //The main game loop structure
        void HandleApplicationIdle(object sender, EventArgs e)
        {
            while (IsApplicationIdle())
            {
                MyUpdate();
                MyRender();
            }
        }

        //Returns true if the application is idle
        static bool IsApplicationIdle()
        {
            NativeMessage result;
            return PeekMessage(out result, IntPtr.Zero, (uint)0, (uint)0, (uint)0) == 0;
        }


        //Allow checking of the mssage buffer
        [StructLayout(LayoutKind.Sequential)]
        public struct NativeMessage
        {
            public IntPtr Handle;
            public uint Message;
            public IntPtr WParameter;
            public IntPtr LParameter;
            public uint Time;
            public Point Location;
        }

        [DllImport("user32.dll")]
        public static extern int PeekMessage(out NativeMessage message, IntPtr window, uint filterMin, uint filterMax, uint remove);



        private void myNameTextBox_TextChanged(object sender, EventArgs e)
        {
            //TODO!!!

        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            if (NIMNetwork.GUI_challengeServer(serverListBox.SelectedIndex))
            {
                //get the game board
                currentBoard = NIMNetwork.GUI_getInitialBoard();
                statusLabel.Text = "Playing against " + serverListBox.SelectedItem.ToString();
                UpdateDisplayBoard();
                currentMode = Mode.Client;
                serverListBox.Enabled = false;
                connectButton.Enabled = false;
                updateButton.Enabled = false;
                HostGameButton.Enabled = false;
                ForfeitButton.Enabled = true;
                MessageSendButton.Enabled = true;

            }
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            ClientScanForServers();
        }

        private void ForfeitButton_Click(object sender, EventArgs e)
        {
            NIMNetwork.GUI_forfeit();
            endGame("You forfeited.");
        }

        private void MessageSendButton_Click(object sender, EventArgs e)
        {
            NIMNetwork.GUI_sendMessage(MessageTB.Text);
            MessageTB.Text = "";
        }

        private void HostGameButton_Click(object sender, EventArgs e)
        {
            serverListBox.Enabled = false;
            connectButton.Enabled = false;
            updateButton.Enabled = false;
            ForfeitButton.Enabled = false;
            MessageSendButton.Enabled = false;
            currentMode = Mode.Server;
            StringBuilder clientName = new StringBuilder(NIMNetwork.MAX_NAME);
            NIMNetwork.GUI_getClient(clientName);

            if (NIMNetwork.GUI_acceptClient() == 1)
            {
                opponentName = clientName.ToString();
                currentMode = Mode.Client;

                serverListBox.Enabled = false;
                connectButton.Enabled = false;
                updateButton.Enabled = false;
                HostGameButton.Enabled = false;
                ForfeitButton.Enabled = true;
                MessageSendButton.Enabled = true;

            }



        }
    }
}
