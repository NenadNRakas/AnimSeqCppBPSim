// A.i.Cloud® by Nenad Rakas © 2020

using UnrealBuildTool;
using System.Collections.Generic;

public class AdvBPSequencerTarget : TargetRules
{
	public AdvBPSequencerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "AdvBPSequencer" } );
	}
}
