using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace NIM
{
    struct BoardReturn
    {
        public ulong row1;
        public ulong row2;
        public ulong row3;
        public ulong row4;
        public ulong row5;
        public ulong row6;
        public ulong row7;
        public ulong row8;
        public ulong row9;

        public ulong getRow(int row)
        {
            switch (row)
            {
                case 0:
                    return row1;
                case 1:
                    return row2;
                case 2:
                    return row3;
                case 3:
                    return row4;
                case 4:
                    return row5;
                case 5:
                    return row6;
                case 6:
                    return row7;
                case 7:
                    return row8;
                case 8:
                    return row9;
                default: return 0;
            }
            
        }
        public ulong decreaseRow(int row, ulong n)
        {
            switch (row)
            {
                case 0:
                    return row1 -= n;
                case 1:
                    return row2 -= n;
                case 2:
                    return row3 -= n;
                case 3:
                    return row4 -= n;
                case 4:
                    return row5 -= n;
                case 5:
                    return row6 -= n;
                case 6:
                    return row7 -= n;
                case 7:
                    return row8 -= n;
                case 8:
                    return row9 -= n;
                default: return 0;
            }

        }
    };

    class NIMNetwork
    {
        public static int DATA_BUFFER_SIZE = 2048;
        public static int MAX_NAME = 2080;

        [DllImport(@"NIMCore.dll")]
        public static extern void GUI_getServerList(StringBuilder serverList);

        [DllImport(@"NIMCore.dll")]
        public static extern void GUI_getClient(StringBuilder clientName);

        [DllImport(@"NIMCore.dll")]
        public static extern int GUI_acceptClient();        

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_challengeServer(int serverNumber);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_setMyName(string name);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_isMyTurn();

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_sendMessage(string message);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_getMessage(StringBuilder serverList);

        [DllImport(@"NIMCore.dll")]
        public static extern BoardReturn GUI_getBoard();

        [DllImport(@"NIMCore.dll")]
        public static extern BoardReturn GUI_getAIMoveBoard();


        [DllImport(@"NIMCore.dll")]
        public static extern BoardReturn GUI_getInitialBoard();

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_makeMove(int row, int number);


        [DllImport(@"NIMCore.dll")]
        public static extern int GUI_gameStatus();

        [DllImport(@"NIMCore.dll")]
        public static extern void GUI_forfeit();

    }
}
