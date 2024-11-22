// Copyright Epic Games, Inc. All Rights Reserved.

#include "HokoriBPLibrary.h"
#include "Hokori.h"


#if PLATFORM_ANDROID && USE_ANDROID_JNI

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#endif

UHokoriBPLibrary::UHokoriBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{ }

void UHokoriBPLibrary::handle_vibration()
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI

	JNIEnv* env = FAndroidApplication::GetJavaEnv(true);

	if (env)
	{
		jclass activity = FJavaWrapper::GameActivityClassID;
		if (activity)
		{
			jobject activity_obj = FJavaWrapper::GameActivityThis;
			if (activity_obj)
			{
				jmethodID method = FJavaWrapper::FindMethod(env, activity, "game_activity_handle_vibration", "()V", true);
				if (method)
				{
					FJavaWrapper::CallVoidMethod(env, activity_obj, method);
				}
			}
		}
	}
#endif
}