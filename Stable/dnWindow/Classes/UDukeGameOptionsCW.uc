/*-----------------------------------------------------------------------------
	UDukeGameOptionsCW
	Author: Brandon Reinhart
-----------------------------------------------------------------------------*/
class UDukeGameOptionsCW extends UDukePageWindow;

// Shield Control
var UWindowLabelControl ShieldControlLabel;
var UWindowComboControl ShieldControlCombo;
var localized string ShieldControlText;
var localized string ShieldControlHelp;
var localized string ShieldMode[2];

// View Bob
var UWindowLabelControl ViewBobLabel;
var UWindowHSliderControl ViewBobSlider;
var localized string ViewBobText;
var localized string ViewBobHelp;

// Field Of View -x
var UWindowLabelControl FovLabel;
var UWindowHSliderControl FovSlider;
var localized string FovText;
var localized string FovHelp;

// Weapon Sway -x
var UWindowLabelControl SwayLabel;
var UWindowHSliderControl SwaySlider;
var localized string SwayText;
var localized string SwayHelp;

// Weapon Lag -x
var UWindowLabelControl LagLabel;
var UWindowHSliderControl LagSlider;
var localized string LagText;
var localized string LagHelp; 

// Hide Weapon
var UWindowLabelControl HideWeaponLabel;
var UWindowCheckbox HideWeaponCheck;
var localized string HideWeaponText;
var localized string HideWeaponHelp;

// LOD On/Off
var UWindowLabelControl UseLODLabel;
var UWindowCheckbox UseLODCheck;
var localized string UseLODText;
var localized string UseLODHelp;

// Facial noise On/Off
var UWindowLabelControl FacialNoiseLabel;
var UWindowCheckbox FacialNoiseCheck;
var localized string FacialNoiseText;
var localized string FacialNoiseHelp;

// Parental Lock
var UWindowSmallButton		ParentalLockButton;
var localized string		ParentalLockText;
var localized string		ParentalLockHelp;

var UWindowWindow PLock;

var float ControlOffset;

function Created()
{
	local int I, S;

	Super.Created();

	// Shield Control
	ShieldControlLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	ShieldControlLabel.SetText(ShieldControlText);
	ShieldControlLabel.SetFont(F_Normal);
	ShieldControlLabel.Align = TA_Right;

	ShieldControlCombo = UWindowComboControl(CreateControl(class'UWindowComboControl', 1, 1, 1, 1));
	ShieldControlCombo.SetHelpText(ShieldControlHelp);
	ShieldControlCombo.SetFont(F_Normal);
	ShieldControlCombo.SetEditable(False);
	ShieldControlCombo.AddItem(ShieldMode[0], "Hold");
	ShieldControlCombo.AddItem(ShieldMode[1], "Toggle");
	ShieldControlCombo.Align = TA_Right;
	switch(GetPlayerOwner().ShieldMode)
	{
		case SM_Hold:
			ShieldControlCombo.SetSelectedIndex(0);
			break;
		case SM_Toggle:
			ShieldControlCombo.SetSelectedIndex(1);
			break;
	}

	// View Bob
	ViewBobLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	ViewBobLabel.SetText(ViewBobText);
	ViewBobLabel.SetFont(F_Normal);
	ViewBobLabel.Align = TA_Right;

	ViewBobSlider = UWindowHSliderControl(CreateControl(class'UWindowHSliderControl', 1, 1, 1, 1));
	ViewBobSlider.SetRange(0, 8, 1);
	ViewBobSlider.SetValue(GetPlayerOwner().Bob*1000);
	ViewBobSlider.SetHelpText(ViewBobHelp);
	ViewBobSlider.SetFont(F_Normal);
	ViewBobSlider.Align = TA_Right;

	// Field Of View -x
	FovLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	FovLabel.SetText(FovText);
	FovLabel.SetFont(F_Normal);
	FovLabel.Align = TA_Right;

	FovSlider = UWindowHSliderControl(CreateControl(class'UWindowHSliderControl', 1, 1, 1, 1));
	FovSlider.SetRange(90, 150, 1);
	FovSlider.SetValue(GetPlayerOwner().DefaultFOV);
	FovSlider.SetHelpText(FovHelp);
	FovSlider.SetFont(F_Normal);
	FovSlider.Align = TA_Right;
	
	// Weapon Sway -x
	SwayLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	SwayLabel.SetText(SwayText);
	SwayLabel.SetFont(F_Normal);
	SwayLabel.Align = TA_Right;

	SwaySlider = UWindowHSliderControl(CreateControl(class'UWindowHSliderControl', 1, 1, 1, 1));
	SwaySlider.SetRange(0, 100, 1);
	SwaySlider.SetValue((GetPlayerOwner().SwayIntensity / 50.f) * 100.f);
	SwaySlider.SetHelpText(SwayHelp);
	SwaySlider.SetFont(F_Normal);
	SwaySlider.Align = TA_Right;

	// Weapon Lag -x
	LagLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	LagLabel.SetText(LagText);
	LagLabel.SetFont(F_Normal);
	LagLabel.Align = TA_Right;

	LagSlider = UWindowHSliderControl(CreateControl(class'UWindowHSliderControl', 1, 1, 1, 1));
	LagSlider.SetRange(0, 100, 1);
	LagSlider.SetValue((GetPlayerOwner().LagIntensity / 0.001.f) * 100.f);
	LagSlider.SetHelpText(LagHelp);
	LagSlider.SetFont(F_Normal);
	LagSlider.Align = TA_Right;

	/*
	// Hide Weapon
	HideWeaponLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	HideWeaponLabel.SetText(HideWeaponText);
	HideWeaponLabel.SetFont(F_Normal);
	HideWeaponLabel.Align = TA_Right;

	HideWeaponCheck = UWindowCheckbox(CreateControl(class'UWindowCheckbox', 1, 1, 1, 1));
	HideWeaponCheck.bChecked = false;
	HideWeaponCheck.SetHelpText(HideWeaponHelp);
	HideWeaponCheck.SetFont(F_Normal);
	HideWeaponCheck.Align = TA_Right;
	*/

	// LOD Enable
	UseLODLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	UseLODLabel.SetText(UseLODText);
	UseLODLabel.SetFont(F_Normal);
	UseLODLabel.Align = TA_Right;

	UseLODCheck = UWindowCheckbox(CreateControl(class'UWindowCheckbox', 1, 1, 1, 1));
	UseLODCheck.bChecked = bool(GetPlayerOwner().ConsoleCommand("GetLodActive"));
	UseLODCheck.SetHelpText(UseLODHelp);
	UseLODCheck.SetFont(F_Normal);
	UseLODCheck.Align = TA_Right;

	// FacialNoise Label
	FacialNoiseLabel = UWindowLabelControl(CreateControl(class'UWindowLabelControl', 1, 1, 1, 1));
	FacialNoiseLabel.SetText(FacialNoiseText);
	FacialNoiseLabel.SetFont(F_Normal);
	FacialNoiseLabel.Align = TA_Right;

	FacialNoiseCheck = UWindowCheckbox(CreateControl(class'UWindowCheckbox', 1, 1, 1, 1));
	if (GetLevel().Game != None)
		FacialNoiseCheck.bChecked = GetLevel().bPawnFacialNoise;
	else
		FacialNoiseCheck.bChecked = true;
	FacialNoiseCheck.SetHelpText(FacialNoiseHelp);
	FacialNoiseCheck.SetFont(F_Normal);
	FacialNoiseCheck.Align = TA_Right;

	// Parental Lock
	ParentalLockButton = UWindowSmallButton( CreateControl( class'UWindowSmallButton', 1, 1, 1, 1 ) );
	ParentalLockButton.SetText(ParentalLockText);
	ParentalLockButton.SetHelpText(ParentalLockHelp);

	ResizeFrames = 30;
}

function BeforePaint( Canvas C, float X, float Y )
{
	local int CenterWidth;
	local int CColLeft, CColRight;

	Super.BeforePaint( C, X, Y );

	if ( ResizeFrames == 0 )
		return;
	ResizeFrames--;

	CenterWidth = (WinWidth/4)*3;
	CColLeft = (WinWidth / 2) - 7;
	CColRight = (WinWidth / 2) + 7;

	// Shield Control
	ShieldControlCombo.SetSize( 200, ShieldControlCombo.WinHeight );
	ShieldControlCombo.WinLeft = CColRight;
	ShieldControlCombo.WinTop = ControlOffset;

	ShieldControlLabel.AutoSize( C );
	ShieldControlLabel.WinLeft = CColLeft - ShieldControlLabel.WinWidth;
	ShieldControlLabel.WinTop = ShieldControlCombo.WinTop + 8;

	// View Bob
	ViewBobSlider.SetSize( CenterWidth, ViewBobSlider.WinHeight );
	ViewBobSlider.WinLeft = CColRight;
	ViewBobSlider.SliderWidth = 150;
	ViewBobSlider.WinTop = ShieldControlCombo.WinTop + ShieldControlCombo.WinHeight + ControlOffset;

	ViewBobLabel.AutoSize( C );
	ViewBobLabel.WinLeft = CColLeft - ViewBobLabel.WinWidth;
	ViewBobLabel.WinTop = ViewBobSlider.WinTop + 4;

	// Field Of View -x
	FovSlider.SetSize( CenterWidth, FovSlider.WinHeight );
	FovSlider.WinLeft = CColRight;
	FovSlider.SliderWidth = 150;
	FovSlider.WinTop = ViewBobSlider.WinTop + ViewBobSlider.WinHeight + ControlOffset;

	FovLabel.AutoSize( C );
	FovLabel.WinLeft = CColLeft - FovLabel.WinWidth;
	FovLabel.WinTop = FovSlider.WinTop + 4;

	// Weapon Sway -x
	SwaySlider.SetSize( CenterWidth, SwaySlider.WinHeight );
	SwaySlider.WinLeft = CColRight;
	SwaySlider.SliderWidth = 150;
	SwaySlider.WinTop = FovSlider.WinTop + FovSlider.WinHeight + ControlOffset;

	SwayLabel.AutoSize( C );
	SwayLabel.WinLeft = CColLeft - SwayLabel.WinWidth;
	SwayLabel.WinTop = SwaySlider.WinTop + 4;

	// Weapon Lag -x
	LagSlider.SetSize( CenterWidth, LagSlider.WinHeight );
	LagSlider.WinLeft = CColRight;
	LagSlider.SliderWidth = 150;
	LagSlider.WinTop = SwaySlider.WinTop + SwaySlider.WinHeight + ControlOffset;

	LagLabel.AutoSize( C );
	LagLabel.WinLeft = CColLeft - LagLabel.WinWidth;
	LagLabel.WinTop = LagSlider.WinTop + 4;

	// LOD On/Off
	UseLODCheck.SetSize( CenterWidth-90+16, UseLODCheck.WinHeight );
	UseLODCheck.WinLeft = CColRight;
	UseLODCheck.WinTop = LagSlider.WinTop + LagSlider.WinHeight + ControlOffset + UseLODCheck.GetHeightAdjust();

	UseLODLabel.AutoSize( C );
	UseLODLabel.WinLeft = CColLeft - UseLODLabel.WinWidth;
	UseLODLabel.WinTop = UseLODCheck.WinTop + 10;

	// Facial noise On/Off
	FacialNoiseCheck.SetSize( CenterWidth-90+16, FacialNoiseCheck.WinHeight );
	FacialNoiseCheck.WinLeft = CColRight;
	FacialNoiseCheck.WinTop = UseLODLabel.WinTop + LagSlider.WinHeight + ControlOffset + FacialNoiseCheck.GetHeightAdjust();
							// ^ This is 'Label' rather than the 'Check' itself, breaks otherwise. YAY CONSISTENCY :DDD 

	FacialNoiseLabel.AutoSize( C );
	FacialNoiseLabel.WinLeft = CColLeft - FacialNoiseLabel.WinWidth;
	FacialNoiseLabel.WinTop = FacialNoiseCheck.WinTop + 10;

	/*
	// Hide Weapon
	HideWeaponCheck.SetSize( CenterWidth-90+16, HideWeaponCheck.WinHeight );
	HideWeaponCheck.WinLeft = CColRight;
	HideWeaponCheck.WinTop = FacialNoiseCheck.WinTop + UseLODCheck.WinHeight + ControlOffset + HideWeaponCheck.GetHeightAdjust()*2;

	HideWeaponLabel.AutoSize( C );
	HideWeaponLabel.WinLeft = CColLeft - HideWeaponLabel.WinWidth;
	HideWeaponLabel.WinTop = HideWeaponCheck.WinTop + 10;
	*/

	// Parental Lock
	ParentalLockButton.AutoSize( C );
	ParentalLockButton.WinLeft = (WinWidth - ParentalLockButton.WinWidth) / 2;
	ParentalLockButton.WinTop = FacialNoiseCheck.WinTop + FacialNoiseCheck.WinHeight + ControlOffset;

	DesiredWidth = 220;
	DesiredHeight = ParentalLockButton.WinTop + ParentalLockButton.WinHeight + ControlOffset;
	// it still doesnt make the window taller, there's probably something else responsible for that then? -x
}

function Notify(UWindowDialogControl C, byte E)
{
	switch(E)
	{
	case DE_Change:
		switch(C)
		{
		case ShieldControlCombo:
			ShieldControlChanged();
			break;
		case ViewBobSlider:
			ViewBobChanged();
			break;
		case FovSlider:
			FovChanged();
			break;
		case SwaySlider:
			SwayChanged();
			break;
		case LagSlider:
			LagChanged();
			break;
		case UseLODCheck:
			LODChanged();
			break;
		case FacialNoiseCheck:
			FacialNoiseChanged();
			break;
		case HideWeaponCheck:
			HideWeaponChanged();
			break;
		}
	case DE_Click:
		switch(C)
		{
		case ParentalLockButton:
			ParentalLockPressed();
			break;
		}
	}
	Super.Notify(C, E);
}

function ParentalLockPressed()
{
	PLock = Root.CreateWindow( class'UDukeParentLockWindow', 1, 1, 1, 1, Root );
	ParentWindow.ParentWindow.ShowModal( PLock );
}

function HideWeaponChanged()
{
//	GetPlayerOwner().ChangeSetHand(WeaponHandCombo.GetValue2());
}

function ShieldControlChanged()
{
	switch (ShieldControlCombo.GetValue2())
	{
		case "Hold":
			GetPlayerOwner().ShieldMode = SM_Hold;
			break;
		case "Toggle":
			GetPlayerOwner().ShieldMode = SM_Toggle;
			break;
	}
}

function ViewBobChanged()
{
	GetPlayerOwner().UpdateBob((ViewBobSlider.Value) / 1000);
}

function FovChanged()
{
	GetPlayerOwner().FOV(FovSlider.Value);
}

function SwayChanged()
{
	GetPlayerOwner().UpdateSway(SwaySlider.Value);
}

function LagChanged()
{
	GetPlayerOwner().UpdateLag(LagSlider.Value);
}

function LODChanged()
{
	if (UseLODCheck.bChecked)
		GetPlayerOwner().ConsoleCommand("mesh_lodactive 1");
	else
		GetPlayerOwner().ConsoleCommand("mesh_lodactive 0");
}

function FacialNoiseChanged()
{
	if ( GetLevel().Game != None )
	{
		if (FacialNoiseCheck.bChecked)
			GetLevel().bPawnFacialNoise = true;
		else
			GetLevel().bPawnFacialNoise = false;
	}
}

function SaveConfigs()
{
	GetPlayerOwner().SaveConfig();
	if ( GetLevel().Game != None )
	{
		GetLevel().Game.SaveConfig();
		GetLevel().Game.GameReplicationInfo.SaveConfig();
	}
	class'GameInfo'.static.StaticSaveConfig();
	Super.SaveConfigs();
}

defaultproperties
{
	HideWeaponText="Hide Weapon"
	HideWeaponHelp="Set whether the weapon view model is visible."
	ShieldControlText="Riot Shield Control"
	ShieldControlHelp="Select how the use key affects Riot Shield functionality."
	ShieldMode(0)="Hold"
	ShieldMode(1)="Toggle"
	ViewBobText="View Bob"
	ViewBobHelp="Adjust the amount your view will bob when moving."

	FovText = "Field Of View"
	FovHelp = "Adjust the field of view."

	SwayText = "Weapon Sway"
	SwayHelp = "Adjust the amount your weapon will sway when looking around."

	LagText = "Weapon Lag"
	LagHelp = "Adjust the amount your weapon will lag behind when moving."

	ControlOffset=10
	UseLODText="Level of Detail"
	UseLODHelp="Toggle dynamic mesh level of detail control."
	FacialNoiseText="Facial Noise"
	FacialNoiseHelp="Toggle facial noise on characters."
	ParentalLockText="Parental Lock"
	ParentalLockHelp="Configure content control lock."
}