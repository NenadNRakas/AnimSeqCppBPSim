// A.i.Cloud® by Nenad Rakas © 2020

using UnrealBuildTool;
using System.Collections.Generic;

public class AdvBPSequencerEditorTarget : TargetRules
{
	public AdvBPSequencerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "AdvBPSequencer" } );
	}
}
