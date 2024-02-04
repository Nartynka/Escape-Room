// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "InteractionSphere.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Inventory.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	RootComponent = Root;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Mesh->SetupAttachment(RootComponent);

	InteractionSphere = CreateDefaultSubobject<UInteractionSphere>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(RootComponent);
	
	// This is copied from GameMode.cpp, should the static keyword be here?
	// And what it is doing here, in this scenario :eyes:
	//static ConstructorHelpers::FClassFinder<ACharacter> PlayerClassAsset(TEXT("/Game/Blueprints/Player/BP_Player.BP_Player"));
	//
	//if (PlayerClassAsset.Succeeded())
	//{
	//	PlayerClass = PlayerClassAsset.Class;
	//}

}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
	InteractionSphere->OnInteractDelegate.AddUniqueDynamic(this, &ThisClass::OnInteraction);
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseItem::OnInteraction(FGameplayTag InteractionTag)
{
	// Pick up the item
	//ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		//UInventory* InvComp = Player->GetComponentByClass<UInventory>();
		if (UInventory* InvComp = Player->GetComponentByClass<UInventory>())
		{
			InvComp->AddItem(ItemType);
			Destroy();
		}
	}
}
