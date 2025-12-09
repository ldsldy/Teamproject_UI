// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Teamproject_UI : ModuleRules
{
	public Teamproject_UI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
