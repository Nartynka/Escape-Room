// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionSphere.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UInteractionSphere::UInteractionSphere()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	this->bHiddenInGame = false;
	//this->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	//this->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Block);
	//this->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	this->SetCollisionProfileName(TEXT("CameraOnly"));
}


// Called when the game starts
void UInteractionSphere::BeginPlay()
{
	Super::BeginPlay();
	//if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("%f"), SphereRadius)); }
	//DrawDebugSphere(GetWorld(), GetComponentLocation(), Radius, 12, FColor::Black, true);

}


// Called every frame
void UInteractionSphere::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractionSphere::Interact(FGameplayTag InteractionTag)
{
	OnInteractDelegate.Broadcast(InteractionTag);
}

//void UInteractionSphere::OnInteraction_Implementation()
//{
//	if (GEngine) 
//	{ 
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("PLEASE OVERRIDE THIS FUNCTION IN BLUEPRINTS")); 
//	}
//}