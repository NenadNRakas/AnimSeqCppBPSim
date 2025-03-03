// A.i.Cloud® by Nenad Rakas © 2020

#include "AA_Pyramid.h"

// Sets default values
AAA_Pyramid::AAA_Pyramid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/* Constructor to Initialize the Class with New StaticMashComponent referencing VisibleMash attaching it to Actor &
	Setting it with Starter Cube Mesh Asset */
	VisibleMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloaterMesh"));
	VisibleMash->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid"));

	if (CubeVisualAsset.Succeeded())
	{
		VisibleMash->SetStaticMesh(CubeVisualAsset.Object);
		VisibleMash->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AAA_Pyramid::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AAA_Pyramid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/* Real-Time code execution for simultaneous object rotation and bounce*/
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	// No editor controls for Height scale factor & Degrees per secound rotation 
	// NewLocation.Z += DeltaHeight * 20.0f;	
	// float DeltaRotation = DeltaTime * 20.0f;

	// Editor Adjustable Scale Hight by FloatVelocity & Rotate every second 
	NewLocation.Z += DeltaHeight * FloatVelocity;
	float DeltaRotation = DeltaTime * RotationVelocity;
	NewRotation.Yaw += DeltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);
}

