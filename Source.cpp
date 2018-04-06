#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "SDK.h"
#include <time.h>

#pragma warning(disable : 4996)


std::vector<std::vector<std::string>> LevelNames = {
{"Levels/FrontEnd/FrontEnd", "In Main Menu", "none", "\0"},
{"\0", "In Loading Screen", "none", "\0" },
{"Levels/MP/Tatooine_01/Tatooine_01", "Mos Eisley, Tatooine", "orig", "tatooine"},
{"Levels/MP/Yavin_01/Yavin_01", "The Greate Temple, Yavin IV", "orig", "yavin4"},
{"Levels/MP/Kamino_01/Kamino_01", "Cloning Facility, Kamino", "preq", "kamino"},
{"Levels/MP/Naboo_01/Naboo_01", "Theed, Naboo", "preq", "naboo"},
{"Levels/MP/StarKiller_01/StarKiller_01", "Command Center, Starkiller Base", "new", "starkillerbase"},
{"Levels/MP/Takodana_01/Takodana_01", "Maz's Castle, Takodana", "new", "takodana"},
{"Levels/MP/Endor_01/Endor_01", "Research Station 9, Endor", "orig", "endor"},
{"Levels/MP/Kashyyyk_01/Kashyyyk_01", "Kachirho Beach, Kashyyyk", "preq", "kashyyyk"},
{"Levels/MP/Jakku_01/Jakku_01", "The Graveyard, Jakku", "new", "jakku"},
{"Levels/MP/DeathStar02_01/DeathStar02_01", "Command Sector North, Death Star II", "orig", "deathstar2"},
{"Levels/MP/Hoth_01/Hoth_01", "Outpost Delta, Hoth", "orig", "hoth"},
{"S1/Levels/Crait_01/Crait_01", "Abandoned Rebel Outpost, Crait", "new", "crait" },
{"S2/Levels/CloudCity_01/CloudCity_01", "Administrator's Palace, Bespin", "orig" , "bespin"},


{ "Levels/Space/SB_Kamino_01/SB_Kamino_01", "Kamino - Research Outpost", "preq", "kamino" },
{ "Levels/Space/SB_DroidBattleShip_01/SB_DroidBattleShip_01", "Ryloth - Lucrehulk-Class Battleship", "preq", "none" },
{ "Levels/Space/SB_Resurgent_01/SB_Resurgent_01", "Unknown Regions - Resurgent-Class Star Destroyer", "new", "none" },
{ "Levels/Space/SB_Fondor_01/SB_Fondor_01", "Fondor - Imperial Shipyard", "orig", "none" },
{ "S1/Levels/Space/SB_SpaceBear_01/SB_SpaceBear_01", "D'Qar - Resistance Base Evacuation", "new", "none"} // I like spacebears too

};

std::vector<std::vector<std::string>> ClassNames = {
{"Gameplay/Characters/StormTrooperShared", "Soldier", "orig" },
{"Gameplay/Characters/StormTrooperShared_B1", "Soldier", "preq"},

{"Gameplay/Characters/heroes/Specializations/Hero_Weapon_WookieWarrior", "Wookie Warrior", "wookiewarrior" },
{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_RebelJumpTrooper", "Jump Trooper", "rebelrockettrooper" },
{"Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_Clone_JumpTrooper", "Jet Trooper", "clonejettrooper" },


{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Luke", "Luke Skywalker", "lukeskywalker" },	// note the difference in capitolization...
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Lando", "Lando Calrissian", "landocalrissian" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Leia", "Leia Organa", "leiaorgana" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Rey", "Rey", "rey" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Hansolo", "Han Solo", "hansolo" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Yoda", "Yoda", "yoda" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Chewbacca", "Chewbacca", "chewbacca" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Finn", "Finn" , "finn"},




{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_DeathTrooper", "Death Trooper", "deathtrooper" },
{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_B2", "B2 Battle Droid", "b2" },
{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_B2RP", "B2-RP Rocket Droid", "b2rprocketdroid" },
{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_JumpTrooper", "Rocket Trooper", "skytrooper" },
{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_FirstOrder_JumpTrooper", "Jump Trooper", "firstorderrockettrooper" },
{ "Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_Flametrooper", "Flame Trooper", "flametrooper" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_BobaFett", "Boba Fett" , "bobafett"},
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_KyloRen", "Kylo Ren", "kyloren" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Maul", "Darth Maul", "darthmaul" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Bossk", "Bossk", "bossk" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_DarthVader", "Darth Vader", "darthvader" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Iden", "Iden Versio", "idenversio" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Emperor", "Emperor Palpatine", "palpatine" },
{ "Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Phasma", "Captain Phasma", "phasma" },


//vehicles

{"Gameplay/Vehicles/Air/AirSpeeder/Vehicle_Air_AirSpeeder", "Air Speeder",  "airspeeder"},
{ "Gameplay/Vehicles/Air/AWing/Vehicle_Air_AWing", "A-Wing",  "awing" },
{ "Gameplay/Vehicles/Air/AWingRZ3/Vehicle_Air_AWingRZ3", "A-Wing RZ3",  "awing" },

{ "Gameplay/Vehicles/Air/BTLYwing/Vehicle_Air_BTLYWing", "BTL-B Y-Wing",  "btlbywing" },
{ "Gameplay/Vehicles/Air/Ywing/Vehicle_Air_YWing", "Y-Wing",  "btlaywing" },
{ "Gameplay/Vehicles/Air/XWing_T65/Vehicle_Air_XWing_T65", "X-Wing",  "xwingt65" },


{ "Gameplay/Vehicles/Air/DroidTriFighter/Vehicle_Air_DroidTriFighter", "Tri-Fighter",  "trifighter" },
{ "Gameplay/Vehicles/Air/VultureDroid/Vehicle_Air_VultureDroid", "Vulture Droid",  "vulturedroid" },
{ "Gameplay/Vehicles/Air/HyeneBomber/Vehicle_Air_HyeneBomber", "Hyene Bomber",  "hyenabomber" },
{ "Gameplay/Vehicles/Air/HyenaBomber/Vehicle_Air_HyenaBomber", "Hyene Bomber",  "hyenabomber" }, //excelent naming conventions DICE

{ "Gameplay/Vehicles/Air/ARC170/Vehicle_Air_ARC170", "ARC170",  "arc170" },
{ "Gameplay/Vehicles/Air/Vwing/Vehicle_Air_Vwing", "V-Wing",  "vwing" },


{ "Gameplay/Vehicles/Air/TieFighterSpecialForces/Vehicle_Air_TieFighterSpecialForces", "Special Forces Tie Fighter",  "tiefightersf" },
{ "Gameplay/Vehicles/Air/TieFighterFirstOrder/Vehicle_Air_TieFighterFirstOrder", "First Order Tie Fighter",  "tiefighterfo" },

{ "Gameplay/Vehicles/Air/XWing_T70/Vehicle_Air_XWing_T70", "T70 X-Wing",  "xwingt70" },

{ "Gameplay/Vehicles/Air/TieFighter/Vehicle_Air_TieFighter", "Tie Fighter",  "tiefighter" },
{ "Gameplay/Vehicles/Air/TieInterceptor/Vehicle_Air_TieInterceptor", "Tie Interceptor",  "tieinterceptor" },
{ "Gameplay/Vehicles/Air/TieBomber/Vehicle_Air_TieBomber", "Tie Bomber",  "tiebomber" },



};

time_t starttime = time(0);



char* TranslateLevel(char* inchar) {
	for (int i = 0; i < LevelNames.size(); i++) {
		if (strcmp(inchar, LevelNames[i][0].c_str()) == 0) {
			return (char*)LevelNames[i][1].c_str();
		}
	}
	return (char*)"\0";
}


char* TranslateClass(char* inchar) {
	for (int i = 0; i < ClassNames.size(); i++) {
		if (strcmp(inchar, ClassNames[i][0].c_str()) == 0) {
			return (char*)ClassNames[i][1].c_str();
		}
	}
//	return (char*)"\0";
	return inchar;
}

char* TranslateImage(char* inchar) {
	for (int i = 0; i < ClassNames.size(); i++) {
		if (strcmp(inchar, ClassNames[i][0].c_str()) == 0) {
			return (char*)ClassNames[i][2].c_str();
		}
	}
	return (char*)"default";
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
		else {
			return TranslateClass(classname);
		}
	}
	return (char*)"\0";
}

char* TranslateLevelImage(char* inchar) {
	for (int i = 0; i < LevelNames.size(); i++) {
		if (strcmp(inchar, LevelNames[i][1].c_str()) == 0) {
			if (strcmp(LevelNames[i][1].c_str(), "none")) return(char*)"\0";
			return (char*)LevelNames[i][3].c_str();
		}
	}	return (char*)"\0";
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


DiscordRichPresence GetUpdate(char* data, const char* faction, const char* image) {

	char buffer[256];
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = data;
//	sprintf(buffer, "Score:  %d", score);
	discordPresence.details = faction;
	discordPresence.largeImageKey = image;
	discordPresence.largeImageText = faction;

	discordPresence.smallImageKey = TranslateLevelImage(data);
	discordPresence.smallImageText = data;

	discordPresence.startTimestamp = starttime;
	discordPresence.instance = 0;
	return discordPresence;
}


typedef void(cdecl *f_Initialize)(const char* appid, int shit, bool autoRegister, const char* steamId);

typedef void(cdecl *f_UpdatePresence)(const DiscordRichPresence* presence);

typedef void(cdecl *f_RunCallbacks)();

typedef void(cdecl *f_Shutdown)();



char* oldname = new char[256];

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
		char* Classname = pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetPlayerClassName();
		char* Levelname = pGC->GetGameContext()->GetClientLevel()->GetLevelName();
		int PlayerTeam = pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetTeam();


		updatePresence(&GetUpdate(TranslateLevel(Levelname), GetFaction(Levelname, PlayerTeam, Classname),  TranslateImage(Classname)));
		
		if (GetAsyncKeyState(VK_END)) {
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