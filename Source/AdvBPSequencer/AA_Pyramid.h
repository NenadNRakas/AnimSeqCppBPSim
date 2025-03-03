// A.i.Cloud® by Nenad Rakas © 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA_Pyramid.generated.h"

UCLASS()
class ADVBPSEQUENCER_API AAA_Pyramid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAA_Pyramid();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisibleMash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floaters")
		float FloatVelocity = 63.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floaters")
		float RotationVelocity = 63.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};