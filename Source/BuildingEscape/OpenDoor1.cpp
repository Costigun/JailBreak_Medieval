// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor1.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor1::UOpenDoor1()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor1::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UOpenDoor1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);
	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator OpenDoor(0.f, TargetYaw, 0.f);

	OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw,DeltaTime,2);
	

	GetOwner()->SetActorRotation(OpenDoor);
	

	


}

