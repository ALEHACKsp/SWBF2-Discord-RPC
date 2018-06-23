#pragma once

#include <time.h>
#include <vector>
#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>


#pragma warning(disable : 4996)

#define OFFSET_DXRENDERER 0x144521DB0
#define OFFSET_GAMERENDERER 0x144523DE0
#define OFFSET_WORLDRENDERER 0x14443383F
#define OFFSET_GAMETIMESETTINGS 0x144028DD0
#define OFFSET_CAMERAUPDATE 0x140911280
#define OFFSET_MOUSEHOOK 0x1410A4150
#define OFFSET_DRAWOUTLINE 0x141E2F470
#define OFFSET_RESOURCEMANAGER 0x1401EF531
#define OFFSET_CLIENTGAMECONTEXT 0x1443046D0
#define OFFSET_FIRSTTYPEINFO 0x1440293E0
#define OFFSET_VIEWANGLEFUNC 0x141639933
#define OFFSET_MAIN 0x144028BE8  // the real one lol
#define OFFSET_SPREADPATCH 0x1416025A9
#define OFFSET_RECOILPATCH 0x14160634F

class VehicleEntityData
{
public:
	char pad_0000[568]; //0x0000
	char* VehicleName; //0x0238
	char pad_0240[520]; //0x0240
	
	char* GetName() {
		if (this != nullptr && this->VehicleName != nullptr) {
			return this->VehicleName;
		}
		return (char*)"\0";
	}
}; //Size: 0x0448

class AttachedControllable
{
public:
	char pad_0000[48]; //0x0000
	class VehicleEntityData* vehicleEntity; //0x0030
	char pad_0038[560]; //0x0038


	VehicleEntityData* GetVehicleEntityData() {
		if (this != nullptr && this->vehicleEntity != nullptr) {
			return this->vehicleEntity;
		}
	}
	
}; //Size: 0x1058


class SoldierBlueprint
{
public:
	char pad_0000[24]; //0x0000
	char* Name; //0x0018
	char pad_0020[40]; //0x0020
	char* GetName() {
		if (this != nullptr && this->Name != nullptr) {
			return this->Name;
		}
		return (char*)"\0";
	}
}; //Size: 0x0048

class ClientSoldierEntity
{
public:
	char pad_0000[760]; //0x0000
	class SoldierBlueprint* soldierBlueprint; //0x02D8
	char pad_02E0[1376]; //0x02E0

	SoldierBlueprint* GetSoldierBlueprint() {
		if (this != nullptr && this->soldierBlueprint != nullptr) {
			return this->soldierBlueprint;
		}
	}
}; //Size: 0x0840

class MatchInfo
{
public:
	char pad_0000[8]; //0x0000
	char* GameMode; //0x0008
	char pad_0010[1080]; //0x0010
	char* GetMatchMode() {
		if (this != nullptr && this->GameMode != nullptr) {
			return this->GameMode;
		}
		return (char*)"Menu";
	}
}; //Size: 0x0448

class ClientLevel
{
public:
	char pad_0000[48]; //0x0000
	class MatchInfo* matchInfo; //0x0030
	char* LevelName; //0x0038
	char pad_0040[1032]; //0x0040
	char* GetLevelName() {
		if (this != nullptr && this->LevelName != nullptr) {
			return this->LevelName;
		}
		return (char*)"\0";
	}
	MatchInfo* GetMatchInfo()
	{
		if (this != nullptr && this->matchInfo != nullptr)
		{
			return this->matchInfo;
		}
	}
}; //Size: 0x0148


class ClientPlayer
{
public:
	char pad_0000[24]; //0x0000
	char* Name; //0x0018
	char pad_0020[56]; //0x0020
	uint32_t Team; //0x0058
	char pad_005C[420]; //0x005C
	class AttachedControllable* attachedControllable; //0x0200
	char pad_0208[8]; //0x0208
	class ClientSoldierEntity* controlledControllable; //0x0210
	char pad_0218[4660]; //0x0218
	int32_t Score; //0x144c
	int32_t Unknown; //0x1450
	int32_t Kills; //0x1454
	int32_t Assists; //0x1458
	int32_t Deaths; //0x145C
	char pad_1460[3040]; //0x1460


	

	ClientSoldierEntity* GetClientSoldier() {
		if (this != nullptr && this->attachedControllable == nullptr && this->controlledControllable != nullptr) {
			return this->controlledControllable;
		}
	}


	AttachedControllable* GetAttachedControllable() {
		if (this != nullptr && this->attachedControllable != nullptr) {
			return this->attachedControllable;
		}

	}
	uint32_t GetTeam() {
		if (this != nullptr && &this->Team != nullptr) {
			return this->Team;
		}
	}

	char* GetName() {
		if (this != nullptr && this->Name != nullptr) {
			return this->Name;
		}
		return (char*)"\0";
	}

	bool IsValid() {
		if (this != nullptr &&
			this->attachedControllable == nullptr  &&
			this->controlledControllable != nullptr )
			return true;
		return false;
	}
	char* GetPlayerClassName() {
		if (IsValid()) {
			return this->GetClientSoldier()->GetSoldierBlueprint()->GetName();
		}
		//if (strcmp(outchar, "\0")) return outchar;
		return this->GetAttachedControllable()->GetVehicleEntityData()->GetName();

	}

}; //Size: 0x1040

class MppPlayer
{
public:
	class ClientPlayer* PlayerArray[40]; //0x0000
	char pad_01E0[64]; //0x01E0

	ClientPlayer* GetPlayerByID(int ID) {
		if (this != nullptr && this->PlayerArray[ID] != nullptr && this->PlayerArray[ID]->IsValid()) {
			return this->PlayerArray[ID];
		}
		return nullptr;
	}
}; //Size: 0x0220

class PlayerManager
{
public:
	char pad_0000[1384]; //0x0000
	class ClientPlayer* LocalPlayer; //0x0568
	char pad_0570[504]; //0x0570
	class MppPlayer* mppPlayer; //0x0768
	char pad_0770[6888]; //0x0770

	ClientPlayer* GetLocalPlayer() {
		if (this != nullptr && this->LocalPlayer != nullptr) {
			return this->LocalPlayer;
		}
	}
	MppPlayer* GetmPPlayer() {
		if (this != nullptr && this->mppPlayer != nullptr) {
			return this->mppPlayer;
		}
	}

}; //Size: 0x2258

class GameContext
{
public:
	char pad_0000[56]; //0x0000
	class ClientLevel* clientLevel; //0x0038
	char pad_0040[24]; //0x0040
	class PlayerManager* playerManager; //0x0058
	char pad_0060[232]; //0x0060

	ClientLevel* GetClientLevel() {
		if (this->clientLevel != nullptr) {
			return this->clientLevel;
		}
	}

	PlayerManager* GetPlayerManager() {
		if (this != nullptr && this->playerManager != nullptr) {
			return this->playerManager;
		}
	}
}; //Size: 0x0148



class StaticGameContext
{
public:
	class GameContext* gameContext; //0x0000
	char pad_0008[56]; //0x0008
	GameContext* GetGameContext() {
		if (this->gameContext != nullptr) {
			return this->gameContext;
		}
	}
}; //Size: 0x0040
