// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define UETEST_ASSERT(exp) verify( (exp) )

//DECLARE_LOG_CATEGORY_EXTERN(UETESTLog, Log, All);
DEFINE_LOG_CATEGORY_STATIC(UETESTLog, Log, All);

//FDateTime::UtcNow().ToString(TEXT("[%Y-%m-%d %H:%M:%S %N]")));

// see also: Engine\Source\Runtime\Core\Public\Logging\LogVerbosity.h
#define UETEST_DEBUG(msg, ...)   UE_LOG(UETESTLog, Log, msg, __VA_ARGS__);
#define UETEST_INFO(msg, ...)    UE_LOG(UETESTLog, Display, msg, __VA_ARGS__);
#define UETEST_WARNING(msg, ...) UE_LOG(UETESTLog, Warning, msg, __VA_ARGS__);
#define UETEST_ERROR(msg, ...)   UE_LOG(UETESTLog, Error, msg, __VA_ARGS__);
#define UETEST_FATAL(msg, ...)   UE_LOG(UETESTLog, Fatal, msg, __VA_ARGS__);
#define UETEST_DISPLAY(msg, ...) UE_LOG(UETESTLog, Display, msg, __VA_ARGS__);
#define UETEST_VERBOSE(msg, ...) UE_LOG(UETESTLog, Verbose, msg, __VA_ARGS__);