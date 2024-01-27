// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventory::AddItem(FInventoryItem Item)
{
	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Adding item %s to inventory"), *Item.ItemName.ToString())); }
	Items.Push(Item);
}

void UInventory::RemoveItem(FInventoryItem Item)
{
	Items.Remove(Item);
}

bool UInventory::HasRequiredItem(FGameplayTag RequiredItemTag)
{
	for (FInventoryItem item : Items)
	{
		if (item.ItemTag == RequiredItemTag)
		{
			return true;
		}
	}

	return false;
}

