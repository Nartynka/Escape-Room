// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"

#include "InteractionTracker.generated.h"

class UInteractionSphere;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONPLUGIN_API UInteractionTracker : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractionTracker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UInteractionSphere* FoundInteractionSphere;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// const-correctness? :eyes:
	UFUNCTION(BlueprintCallable)
	bool IsInteractionAvailable() const;

	UFUNCTION(BlueprintCallable)
	FGameplayTagContainer CheckForTags() const;

	UFUNCTION(BlueprintCallable)
	void Interact(FGameplayTag InteractionTag);

	UPROPERTY(EditAnywhere)
	float Distance;
};