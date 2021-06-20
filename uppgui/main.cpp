#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <Ranksys/main.lay>
#include <CtrlCore/lay.h>

#define IMAGECLASS Images
#define IMAGEFILE <Ranksys/images.iml>
#include <Draw/iml.h>

int candidates = 50; //just a replacement so that the arrayctrl can be seen properly

struct menuDlg : Withmenu<TopWindow> {
	menuDlg();
};

menuDlg::menuDlg()
{
	CtrlLayout(*this, "Ranksys");
	displaybutton << [=] {
	    Withdisplayranking<TopWindow> dlg;
		CtrlLayout(dlg, "");
		dlg.searchbutton.SetImage(Images::searchicon());
		dlg.array.AddColumn("Rank");
		dlg.array.AddColumn("Name");
		dlg.array.AddColumn("Class");
		dlg.array.ColumnWidths("51 120 60");
		for(int i = 0; i < candidates; i++){
			dlg.array.Add(i+1);
		}
		dlg.searchbar.WhenEnter = [&] {
			dlg.searchbutton.PseudoPush();
		};
		dlg.searchbutton.WhenPush = [&] {
			//search function
			dlg.searchbar.Clear();
		};
		dlg.Zoomable().Execute();
    };
}



GUI_APP_MAIN
{
    menuDlg().Run();
}