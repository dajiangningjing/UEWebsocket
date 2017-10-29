// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class UEWebsocketServerTarget : TargetRules
{
    public UEWebsocketServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		bUsesSteam = false;
		ExtraModuleNames.Add("UEWebsocket");
	}
}
