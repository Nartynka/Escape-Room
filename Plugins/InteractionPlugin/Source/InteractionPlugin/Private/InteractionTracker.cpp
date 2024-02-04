// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionTracker.h"
#include "InteractionSphere.h"
#include "DrawDebugHelpers.h"

#define PRINT(msg) if (GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT(msg));}
#define PRINTS(str) if (GEngine){GEngine->AddOnScreenDebugMessage(-1, -1.0f, FColor::Cyan, FString::Printf(TEXT("%s"), *str));}
#define PRINTSK(key, str) if (GEngine){GEngine->AddOnScreenDebugMessage(key, -1.0f, FColor::Cyan, FString::Printf(TEXT("%s"), *str));}

// Sets default values for this component's properties
UInteractionTracker::UInteractionTracker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionTracker::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionTracker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult HitResult;
	FVector start = GetForwardVector() + GetComponentLocation();
	FVector end = GetForwardVector() * Distance + GetComponentLocation();
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Owner: %s, Comp: %s"), *GetOwner()->GetActorLocation().ToString(), *GetComponentLocation().ToString()));
	if (UWorld* World = GetWorld())
	{
		FCollisionQueryParams Params;
		//Params.AddIgnoredComponent((const UPrimitiveComponent*)this);
		Params.AddIgnoredActor(GetOwner());
		World->LineTraceSingleByChannel(HitResult, start, end, ECollisionChannel::ECC_Camera, Params);
		DrawDebugLine(World, start, end, FColor::Emerald);
	}

	if (HitResult.bBlockingHit)
	{
		check(HitResult.GetActor());
		//PRINTSK(3, HitResult.GetActor()->GetActorLabel());
		UInteractionSphere* FoundIS = HitResult.GetActor()->GetComponentByClass<UInteractionSphere>();
		//UInteractionSphere* a = HitResult.GetActor()->GetComponentByClass(UInteractionSphere::StaticClass());
		if (FoundIS)
		{
			FoundInteractionSphere = FoundIS;
			//PRINTSK(2, FoundIS->GetName());
		}
		else
		{
			FoundInteractionSphere = nullptr;
		}
	}
	else
	{
		FoundInteractionSphere = nullptr;
	}
}

FGameplayTagContainer UInteractionTracker::CheckForTags() const
{
	// do i need IsInteractionAvailable func if i check for IS here anyway
	if (FoundInteractionSphere)
	{
		return FoundInteractionSphere->RequiredTags;
	}
	else
	{
		FGameplayTagContainer EmptyTagContainer;
		return EmptyTagContainer;
		//return FGameplayTag::EmptyTag;
	}
}

void UInteractionTracker::Interact(FGameplayTag InteractionTag)
{
	if (FoundInteractionSphere)
	{
		FoundInteractionSphere->Interact(InteractionTag);
	}
}

bool UInteractionTracker::IsInteractionAvailable() const
{
	if (FoundInteractionSphere)
		return true;
	return false;
}

