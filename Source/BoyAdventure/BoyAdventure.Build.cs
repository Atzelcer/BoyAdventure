// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BoyAdventure : ModuleRules
{
	public BoyAdventure(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
