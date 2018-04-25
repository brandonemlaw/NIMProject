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
    };

    class NIMNetwork
    {
        [DllImport(@"NIMCore.dll")]
        public static extern void GUI_getServerList(StringBuilder serverList);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_challengeServer(int serverNumber);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_setMyName(string name);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_isMyTurn();

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_sendMessage(string message);

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_getMessage(StringBuilder serverList, int length);

        [DllImport(@"NIMCore.dll")]
        public static extern BoardReturn GUI_getBoard();

        [DllImport(@"NIMCore.dll")]
        public static extern BoardReturn GUI_getInitialBoard();

        [DllImport(@"NIMCore.dll")]
        public static extern bool GUI_makeMove(int row, int number);

    }
}
