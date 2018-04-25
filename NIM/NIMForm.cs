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

        public NIMForm()
        {
            Application.Idle += HandleApplicationIdle;
            InitializeComponent();

            //Set the default text box name
            myNameTextBox.Text = Environment.UserName;

            //Run initial scan for servers
            ClientScanForServers();

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
            if (currentMode == Mode.Waiting)
            {

            }
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


        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            if (NIMNetwork.GUI_challengeServer(serverListBox.SelectedIndex))
            {
                //get the game board
                currentBoard = NIMNetwork.GUI_getInitialBoard();
                int test = 5;
            }
        }
    }
}
