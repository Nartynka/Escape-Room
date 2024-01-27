// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "InventoryItem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_USTRUCT_BODY()

	FORCEINLINE FInventoryItem();

	// what explicit was doing?
	explicit FORCEINLINE FInventoryItem(FName name, UTexture* thumbnail, FGameplayTag item_tag);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture* ItemThumbnail;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FGameplayTag ItemTag;

	FORCEINLINE bool operator==(const FInventoryItem& otherItem);
	FORCEINLINE bool operator==(const FName otherName);
};

FORCEINLINE FInventoryItem::FInventoryItem(FName name, UTexture* thumbnail, FGameplayTag item_tag) : ItemName(name), ItemThumbnail(thumbnail), ItemTag(item_tag)
{
	if (GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("dupa")); }
	if (GEngine){GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Cyan, FString::Printf(TEXT("%s, func: %s"), *ItemTag.ToString(), *item_tag.ToString()));}
}

FORCEINLINE FInventoryItem::FInventoryItem()
{
	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("dupa2")); }
}

FORCEINLINE bool FInventoryItem::operator==(const FName otherName)
{
	if (ItemName == otherName)
		return true;
	return false;
}

FORCEINLINE bool FInventoryItem::operator==(const FInventoryItem& otherItem)
{
	if (ItemName == otherItem.ItemName)
		return true;
	return false;
}
