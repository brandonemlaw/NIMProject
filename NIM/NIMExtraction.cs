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
        ulong row1;
        ulong row2;
        ulong row3;
        ulong row4;
        ulong row5;
        ulong row6;
        ulong row7;
        ulong row8;
        ulong row9;
    };

    class NIMExtraction
    {
        [DllImport(@"NIM.dll")]
        public static extern void GUI_getServerList(StringBuilder serverList, int length);

        [DllImport(@"NIM.dll")]
        public static extern bool GUI_challengeServer(string serverName);

        [DllImport(@"NIM.dll")]
        public static extern bool GUI_setMyName(string name);

        [DllImport(@"NIM.dll")]
        public static extern bool GUI_isMyTurn();

        [DllImport(@"NIM.dll")]
        public static extern bool GUI_sendMessage(string message);

        [DllImport(@"NIM.dll")]
        public static extern bool GUI_getMessage(StringBuilder serverList, int length);

        [DllImport(@"NIM.dll")]
        public static extern BoardReturn GUI_getBoard();

        [DllImport(@"NIM.dll")]
        public static extern bool GUI_makeMove(int row, int number);

    }
}
