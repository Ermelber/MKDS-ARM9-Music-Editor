/*
  GLORIOUS MKDS ARM9 MUSIC TABLE EDITOR 1.0!!! 
  MADE BY ERMELBER AND FIXED BY YAMI AND MKDASHER!!!
  Yeah, I know this may suck and not work properly, but well, it's my first tool :3
  Can be optimized.
*/


#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <streambuf>
#include <cerrno>
#include <cstdlib>
#include <ctype.h>

using namespace std;

string get_file_contents(const char *filename) {
	ifstream in (filename, ios::in | ios::binary);
	if (in) {
		ostringstream contents;
		contents << in.rdbuf();
		in.close();
		
		return (contents.str());
	}  else {
				cout << "There isn't a valid file called ''arm9.bin'' in your directory.\nCheck if it really is there.\n";
				cin.ignore();			
				exit(1);
			}
}

int min(int a, int b){
 if (a < b) return a;
 else return b;
}

int main() {
    const int offset = 1388909;
    int selected;
    int newvalue;
    char choice;
    string tracks[53];
    int a[211];
    tracks[0] = "Unknown";
    tracks[1] = "Course Intro 2";
    tracks[2] = "Course Intro 1";
    tracks[3] = "Course Intro 3";
    tracks[4] = "Course Intro 1";
    tracks[5] = "Battle Mode Intro";
    tracks[6] = "Boss Intro";
    tracks[7] = "Figure-8 Circuit";
    tracks[8] = "GCN Luigi Circuit";
    tracks[9] = "GCN Yoshi Circuit";
    tracks[10] = "Cheep Cheep Beach";
    tracks[11] = "Yoshi Falls";
    tracks[12] = "GCN Baby Park";
    tracks[13] = "N64 Moo Moo Farm";
    tracks[14] = "N64 Frappe Snowland";
    tracks[15] = "Delfino Sqare";
    tracks[16] = "Airship Fortress";
    tracks[17] = "Wario Stadium";
    tracks[18] = "GCN Mushroom Bridge";
    tracks[19] = "Peach Gardens";
    tracks[20] = "Luigi's Mansion";
    tracks[21] = "SNES Mario Circuit 1";
    tracks[22] = "SNES Koopa Beach 2";
    tracks[23] = "SNES Donut Plains 1";
    tracks[24] = "SNES Choco Island 2";
    tracks[25] = "GBA Peach Circuit";
    tracks[26] = "GBA Luigi Circuit";
    tracks[27] = "Shroom Ridge";
    tracks[28] = "N64 Choco Mountain";
    tracks[29] = "N64 Banshee Boardwalk";
    tracks[30] = "DK Pass";
    tracks[31] = "Desert Hills";
    tracks[32] = "Waluigi Pinball";
    tracks[33] = "Tick-Tock Clock";
    tracks[34] = "Mario Circuit";
    tracks[35] = "Rainbow Road";
    tracks[36] = "GBA Bowser Castle 2";
    tracks[37] = "Bowser Castle";
    tracks[38] = "GBA Sky Garden";
    tracks[39] = "Battle Stage Theme";
    tracks[40] = "Boss Battle Theme";
    tracks[41] = "Jingle";
    tracks[42] = "GP Results";
    tracks[43] = "Credits";
    tracks[44] = "Credits True";
    tracks[45] = "Wi-Fi Menu";
    tracks[46] = "Multiplayer Menu";
    tracks[47] = "Records Menu";
    tracks[48] = "Options Menu";
    tracks[49] = "Intro";
    tracks[50] = "Singleplayer Menu";
    tracks[51] = "Unknown";
    tracks[52] = "Mario Circuit";
    //Start
    printf("Mario Kart DS ARM9 Music Table Editor by Ermelber\n\nPress any key to start the program.\n");
    cin.ignore();    
    //Get arm9.bin
    string text = get_file_contents("arm9.bin");
    for (int i = offset; i < min(text.size(), offset + 211); i++)
        a[i-offset] = (int) text[i];       
    do
    {
        //Print Tracks       
        for (int i = 0; i < 53; i++){
            cout << i << ") "<< tracks[i] <<" [" << a[i*4] <<"]" << endl;
        }
        //Select slot
        do{
            printf("\n\nSelect a slot to change [0..52]: ");
            scanf("%d",&selected);        
        }while (selected <0 || selected>52); 
    
        //Confirm
        while (true) {
            cout << "\nDo you want to change Slot " << selected << "'s (" << tracks[selected] << ") SEQ value? [Y/N] ";
            cin >> choice;
        //Choices
            if ((choice == 'Y') || (choice == 'y')) {
                do{
                    //New value
                    cout << "\nInsert the new SEQ value (Old value was " << a[selected*4] << ") [-1..75]=";
                    scanf("%d",&newvalue);
                }while (newvalue <-1 || newvalue>75);
                a[selected*4]=newvalue;
                break;
            }
            else if ((choice == 'N') || (choice == 'n')) {
                break;
            }
            else {
                cout << "\nThe Choice isn't valid.";
            }
        }
    
        
        while (true) {
            cout << "\nDo you want to edit it furthermore? [Y/N] ";
            cin >> choice;

            if ((choice == 'Y') || (choice == 'y')) {
                break;
            }
            else if ((choice == 'N') || (choice == 'n')) {
                break;
            }
            else {
                cout << "\nThe Choice isn't valid.";
            }
        }
    }
    while (choice == 'Y' || choice == 'y'); 
    
    /*//Prints array (Testing purposes)
    for (int i=0; i<211; i++)
        cout << a[i] << endl;
    cin.ignore();*/
    
    //Make backup and overwrite arm9.bin
    ofstream out( "arm9.bin.bak", std::ios_base::binary | std::ios_base::out );
    out << text;
    out.close();
    for (int i = offset; i < min(text.size(), offset + 211); i++)
        text[i] = a[i-offset];    
    out.open( "arm9.bin", std::ios_base::binary | std::ios_base::out );
    out << text;
    out.close();
    	
	cout << "\nSuccessfully saved edited_arm9.bin in your folder!\nPress ENTER to exit the program :3\n";
    cin.ignore();
    cin.ignore();    
    //end
    return 0;
}
