// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameplayTagContainer.h"

#include "InteractionSphere.generated.h"

//@TODO: Implement Delegate OnInteract
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractSignature, FGameplayTag, SearchedTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractSignature);

UENUM(BlueprintType)
enum class EInteraction
{
	EI_Push UMETA(DisplayName = "Push"),
	EI_Pull UMETA(DisplayName = "Pull"),
	EI_Open UMETA(DisplayName = "Open"),
};


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONPLUGIN_API UInteractionSphere : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionSphere();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Interaction Type"))
	EInteraction Interaction;

	UPROPERTY(BlueprintAssignable)
	FOnInteractSignature OnInteractDelegate;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Required Tag (Optional)", ToolTip = "Optional Tag Required For Interaction"))
	FGameplayTag RequiredTag;

	void Interact();

	// @TODO: Pass Gameplay tag
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, meta = (AllowPrivateAcces = true))
	//void OnInteraction(FGameplayTag Tag);
	//virtual void Interact() PURE_VIRTUAL(UInteractionSphere::Interact, );
};
