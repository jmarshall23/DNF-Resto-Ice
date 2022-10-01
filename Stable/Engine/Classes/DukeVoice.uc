/*-----------------------------------------------------------------------------
	DukeVoice
	Author: Brandon Reinhart
-----------------------------------------------------------------------------*/
class DukeVoice extends Info;

function DukeSay( sound Phrase, optional float fPitch )
{
	local float Pitch;

	// hacky method for 'default value' -x
	if (fPitch == 0.0)
		fPitch = 1.0;

	if ( Owner.DrawScale < 0.5 )
		Pitch = 1.5 * fPitch;
	else
		Pitch = 1.0 * fPitch;

	if ( Level.NetMode == NM_Standalone )
	{
		PlayOwnedSound(Phrase, SLOT_Talk,,,,Pitch,true);
		PlayOwnedSound(Phrase, SLOT_Ambient,,,,Pitch,true);
		PlayOwnedSound(Phrase, SLOT_Interface,,,,Pitch,true);
	}
	else
	{
		if ( PlayerPawn( Owner ) != None )
		{
			// Need to propogate this to everyone
			Owner.PlaySound(Phrase, SLOT_Talk,,,,Pitch,true);
		}
	}
}

defaultproperties
{
	RemoteRole=ROLE_None
}