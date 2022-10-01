class UDukeDialogClientWindow extends UWindowDialogClientWindow;

// FairFriend: Shouldn't be local so that child can access it.
var UWindowFramedWindow FramedParent;

function Notify( UWindowDialogControl C, byte E )
{	
	Super.Notify( C, E );

	if ( ParentWindow != None )
	{
		FramedParent = UWindowFramedWindow(ParentWindow);
		if ( (FramedParent == None) && (ParentWindow.ParentWindow != None) )
			FramedParent = UWindowFramedWindow(ParentWindow.ParentWindow);
	}

	if ( FramedParent == None )
		return;

	if ( E == DE_MouseMove )
		FramedParent.StatusBarText = C.HelpText;

	if ( E == DE_HelpChanged && C.MouseIsOver() )
		FramedParent.StatusBarText = C.HelpText;

	if ( E == DE_MouseLeave )
		FramedParent.StatusBarText = "";
}
