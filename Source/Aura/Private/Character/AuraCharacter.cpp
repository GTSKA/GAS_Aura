// No copyright on test


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter() : Super()
{
	
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
}
