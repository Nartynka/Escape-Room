// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryItem.h"

#include "BaseItem.generated.h"

class UInteractionSphere;

UCLASS()
class ESCAPEROOM_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//FGameplayTag Tag;
	UFUNCTION()
	void OnInteraction();

	//TSubclassOf<ACharacter> PlayerClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditDefaultsOnly)
	USceneComponent* Root;
	
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	UInteractionSphere* InteractionSphere;

	UPROPERTY(EditAnywhere)
	FInventoryItem ItemType;
};
