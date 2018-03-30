#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "SDK.h"

#pragma warning(disable : 4996)


std::vector<std::vector<std::string>> LevelNames = {
{"Levels/FrontEnd/FrontEnd", "In Main Menu", "none"},
{"\0", "In Loading Screen", "none"},
{"Levels/MP/Tatooine_01/Tatooine_01", "Mos Eisley, Tatooine", "orig"},
{"Levels/MP/Yavin_01/Yavin_01", "The Greate Temple, Yavin IV", "orig"},
{"Levels/MP/Kamino_01/Kamino_01", "Cloning Facility, Kamino", "preq"},
{"Levels/MP/Naboo_01/Naboo_01", "Theed, Naboo", "preq"},
{"Levels/MP/StarKiller_01/StarKiller_01", "Command Center, Starkiller Base", "new"},
{"Levels/MP/Takodana_01/Takodana_01", "Maz's Castle, Takodana", "new"},
{"Levels/MP/Endor_01/Endor_01", "Research Station 9, Endor", "orig"},
{"Levels/MP/Kashyyyk_01/Kashyyyk_01", "Kachirho Beach, Kashyyyk", "preq"},
{"Levels/MP/Jakku_01/Jakku_01", "The Graveyard, Jakku", "new"},
{"Levels/MP/Deathstar_02/Deathstar_02", "Command Sector North, Death Star II", "orig"},
{"Levels/MP/Hoth_01/Hoth_01", "Outpost Delta, Hoth", "orig"},
{"S2/Levels/Crait_01/Crait_01", "Abandoned Rebel Outpost, Crait", "new" },
{"S2/Levels/CloudCity_01/CloudCity_01", "Administrator's Palace, Bespin", "orig" }
};

std::vector<std::vector<std::string>> ClassNames = {
{"Gameplay/Characters/StormTrooperShared", "Soldier", "orig" },
{"Gameplay/Characters/StormTrooperShared_B1", "Soldier", "preq"},

{"Gameplay/Characters/Heroes/Specializations/Hero_Weapon_WookieWar", "Wookie Warrior", "wookiewarrior" },
{"Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Special_R", "Rocket Trooper", "rockettrooper" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Luke", "Luke Skywalker", "lukeskywalker" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Lando", "Lando Calrissian", "landocalrissian" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Leia", "Leia Organa", "leiaorgana" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Rey", "Rey", "rey" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Hansolo", "Han Solo", "hansolo" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Yoda", "Yoda", "yoda" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Chewbacca", "Chewbacca", "chewbacca" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Finn", "Finn" , "finn"},

{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Special_D", "Death Trooper", "deathtrooper" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Special_J", "Rocket Trooper", "rocketrooper" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_BobaFett", "Boba Fett" , "bobafett"},
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_KyloRen", "Kylo Ren", "kyloren" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Maul", "Darth Maul", "darthmaul" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Bossk", "Bossk", "bossk" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Darth", "Darth Vader", "darthvader" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Iden", "Iden Versio", "idenversio" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Emper", "Emperor Palpatine", "emperorpalpatine" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Phasma", "Captain Phasma", "captainphasma" },

};



char* TranslateLevel(char* inchar) {
	for (int i = 0; i < LevelNames.size(); i++) {
		if (strcmp(inchar, LevelNames[i][0].c_str()) == 0) {
			return (char*)LevelNames[i][1].c_str();
		}
	}
	return inchar;
}


char* TranslateClass(char* inchar) {
	for (int i = 0; i < ClassNames.size(); i++) {
		if (strcmp(inchar, ClassNames[i][0].c_str()) == 0) {
			return (char*)ClassNames[i][1].c_str();
		}
	}
	return inchar;
}

char* TranslateImage(char* inchar) {
	for (int i = 0; i < ClassNames.size(); i++) {
		if (strcmp(inchar, ClassNames[i][0].c_str()) == 0) {
			return (char*)ClassNames[i][2].c_str();
		}
	}
	return inchar;
}

char* GetFaction(char* map, int TeamID, char* classname) {
	if (TeamID == 0) return (char*)"\0";
	for (int i = 0; i < LevelNames.size(); i++) {
		if (strcmp(map, LevelNames[i][0].c_str()) == 0) {
			char* str = new char[128];
			if (strcmp(TranslateClass(classname), "Soldier") == 0) {

				if (LevelNames[i][2] == "preq") {
					strcpy(str, (TeamID == 1) ? (char*)"Galactic Republic" : (char*)"Confederacy");
				}
				if (LevelNames[i][2] == "orig") {
					strcpy(str, (TeamID == 1) ? (char*)"Rebel Alliance" : (char*)"Galactic Empire");
				}
				if (LevelNames[i][2] == "new") {
					strcpy(str, (TeamID == 1) ? (char*)"Resistance" : (char*)"First Order");
				}
			}
			else {
				strcpy(str, TranslateClass(classname));
			}
			return str;
		}
	}
	return (char*)"\0";
}


typedef struct DiscordRichPresence {
	const char* state;   /* max 128 bytes */
	const char* details; /* max 128 bytes */
	int64_t startTimestamp;
	int64_t endTimestamp;
	const char* largeImageKey;  /* max 32 bytes */
	const char* largeImageText; /* max 128 bytes */
	const char* smallImageKey;  /* max 32 bytes */
	const char* smallImageText; /* max 128 bytes */
	const char* partyId;        /* max 128 bytes */
	int partySize;
	int partyMax;
	const char* matchSecret;    /* max 128 bytes */
	const char* joinSecret;     /* max 128 bytes */
	const char* spectateSecret; /* max 128 bytes */
	int8_t instance;
} DiscordRichPresence;


DiscordRichPresence GetUpdate(const char* data, const char* faction, const char* image) {

	char buffer[256];
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = data;
//	sprintf(buffer, "Score:  %d", score);
	discordPresence.details = faction;
	discordPresence.largeImageKey = image;
	discordPresence.largeImageText = faction;
	discordPresence.smallImageKey = image;
	discordPresence.instance = 0;
	return discordPresence;
}


typedef void(cdecl *f_Initialize)(const char* appid, int shit, bool autoRegister, const char* steamId);

typedef void(cdecl *f_UpdatePresence)(const DiscordRichPresence* presence);

typedef void(cdecl *f_RunCallbacks)();

typedef void(cdecl *f_Shutdown)();


DWORD WINAPI Looper(LPVOID lpParam)
{
//	AllocConsole();
	//freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	HINSTANCE hGetProcIDDLL = LoadLibrary("discord-rpc.dll");
	std::cout << std::hex << hGetProcIDDLL << std::endl;
	if (!hGetProcIDDLL) {
		MessageBox(NULL, "discord-rpc.dll not found", "Failure!", MB_OK);
		FreeConsole();
		FreeLibraryAndExitThread((HMODULE)lpParam, 0);
		return EXIT_FAILURE;
	}
	f_Initialize ititialize = (f_Initialize)GetProcAddress(hGetProcIDDLL, "Discord_Initialize");
	f_UpdatePresence updatePresence = (f_UpdatePresence)GetProcAddress(hGetProcIDDLL, "Discord_UpdatePresence");
	f_RunCallbacks runCallbacks = (f_RunCallbacks)GetProcAddress(hGetProcIDDLL, "Discord_RunCallbacks");
	f_Shutdown shutdown = (f_Shutdown)GetProcAddress(hGetProcIDDLL, "Discord_Shutdown");
	std::cout <<std::hex<< ititialize << std::endl;

	ititialize("420031141777768470", NULL, true, NULL); // put your appid there
	while (true)
	{
		Sleep(500);
		StaticGameContext* pGC = (StaticGameContext*)(DWORD64*)(0x14428A188);
		updatePresence(&GetUpdate(TranslateLevel(pGC->GetGameContext()->GetClientLevel()->GetLevelName()),
			GetFaction(pGC->GetGameContext()->GetClientLevel()->GetLevelName(), pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetTeam(),
				pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetClientSoldier()->GetSoldierBlueprint()->GetName()), 
			TranslateImage(pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetClientSoldier()->GetSoldierBlueprint()->GetName())));
		
		if (GetAsyncKeyState(VK_END)) {
			MessageBox(NULL, "Ejecting SWBF2 RPC", "Ejecting", MB_OK);
			FreeConsole();
			FreeLibraryAndExitThread((HMODULE)lpParam, 0);
		}
	}
	return 1;
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
	if (dwAttached == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, Looper, hModule, 0, NULL);
	}
	return 1;
}