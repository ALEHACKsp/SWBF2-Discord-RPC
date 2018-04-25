#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "SDK.h"
#include <time.h>

#pragma warning(disable : 4996)



enum Trilogy {
	Prequil,
	Original,
	NewEra, 
	None
};


class MapObject {
public:
	MapObject(std::string m_baseName, std::string m_mapTitle, Trilogy m_trilogy, std::string m_imageName)
		: baseName(m_baseName), mapTitle(m_mapTitle), trilogy(m_trilogy), imageName(m_imageName){}
	std::string baseName;
	std::string mapTitle;
	Trilogy trilogy;
	std::string imageName;
};


class PlayerObject {
public:
	std::string baseName;
	std::string playerName;
	std::string imageName;
	PlayerObject(std::string m_baseName, std::string m_playerName, std::string m_imageName) 
		: baseName(m_baseName), playerName(m_playerName), imageName(m_imageName) {}
};

std::vector<MapObject> maplist = {
	//Menus
	MapObject("Levels/FrontEnd/FrontEnd", "In Main Menu", Trilogy::None, "\0"),
	MapObject("\0", "In Loading Screen", Trilogy::None, "\0"),

	//galactic assault
	MapObject("Levels/MP/Tatooine_01/Tatooine_01", "Mos Eisley, Tatooine", Trilogy::Original, "tatooine"),
	MapObject("Levels/MP/Yavin_01/Yavin_01", "The Greate Temple, Yavin IV", Trilogy::Original, "yavin4"),
	MapObject("Levels/MP/Kamino_01/Kamino_01", "Cloning Facility, Kamino", Trilogy::Prequil, "kamino"),
	MapObject("Levels/MP/Naboo_01/Naboo_01", "Theed, Naboo", Trilogy::Prequil, "naboo"),
	MapObject("Levels/MP/StarKiller_01/StarKiller_01", "Command Center, Starkiller Base", Trilogy::NewEra, "starkillerbase"),
	MapObject("Levels/MP/Takodana_01/Takodana_01", "Maz's Castle, Takodana", Trilogy::NewEra, "takodana"),
	MapObject("Levels/MP/Endor_01/Endor_01", "Research Station 9, Endor", Trilogy::Original, "endor"),
	MapObject("Levels/MP/Kashyyyk_01/Kashyyyk_01", "Kachirho Beach, Kashyyyk", Trilogy::Prequil, "kashyyyk"),
	MapObject("Levels/MP/Jakku_01/Jakku_01", "The Graveyard, Jakku", Trilogy::NewEra, "jakku"),
	MapObject("Levels/MP/DeathStar02_01/DeathStar02_01", "Command Sector North, Death Star II", Trilogy::Original, "deathstar2"),
	MapObject("Levels/MP/Hoth_01/Hoth_01", "Outpost Delta, Hoth", Trilogy::Original, "hoth"),
	MapObject("S1/Levels/Crait_01/Crait_01", "Abandoned Rebel Outpost, Crait", Trilogy::NewEra, "crait"),
	MapObject("S2/Levels/CloudCity_01/CloudCity_01", "Administrator's Palace, Bespin", Trilogy::Original , "bespin"),

	//starfighter assault
	MapObject("Levels/Space/SB_Kamino_01/SB_Kamino_01", "Kamino - Research Outpost", Trilogy::Prequil, "kamino"),
	MapObject("Levels/Space/SB_DroidBattleShip_01/SB_DroidBattleShip_01", "Ryloth - Lucrehulk-Class Battleship", Trilogy::Prequil, "none"),
	MapObject("Levels/Space/SB_Resurgent_01/SB_Resurgent_01", "Unknown Regions - Resurgent-Class Star Destroyer", Trilogy::NewEra, "none"),
	MapObject("Levels/Space/SB_Fondor_01/SB_Fondor_01", "Fondor - Imperial Shipyard", Trilogy::Original, "none"),
	MapObject("S1/Levels/Space/SB_SpaceBear_01/SB_SpaceBear_01", "D'Qar - Resistance Base Evacuation", Trilogy::NewEra, "none")
};



std::vector<PlayerObject> playerList = {
	//shared
	PlayerObject("Gameplay/Characters/StormTrooperShared", "Soldier", "orig"),
	PlayerObject("Gameplay/Characters/StormTrooperShared_B1", "Soldier", "preq"),
	
	//enforcer
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_WookieWarrior", "Wookie Warrior", "wookiewarrior"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_Flametrooper", "Flame Trooper", "flametrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_B2", "B2 Battle Droid", "b2"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_DeathTrooper", "Death Trooper", "deathtrooper"),

	//aerial
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_Clone_JumpTrooper", "Jet Trooper", "clonejettrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_RebelJumpTrooper", "Jump Trooper", "rebelrockettrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_FirstOrder_JumpTrooper", "Jump Trooper", "firstorderrockettrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_JumpTrooper", "Rocket Trooper", "skytrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_B2RP", "B2-RP Rocket Droid", "b2rprocketdroid"),


	//heroes
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Luke", "Luke Skywalker", "lukeskywalker"),	// note the difference in capitolization...
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Lando", "Lando Calrissian", "landocalrissian"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Leia", "Leia Organa", "leiaorgana"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Rey", "Rey", "rey"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Hansolo", "Han Solo", "hansolo"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Yoda", "Yoda", "yoda"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Chewbacca", "Chewbacca", "chewbacca"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Finn", "Finn" , "finn"),

	//villians
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_BobaFett", "Boba Fett" , "bobafett"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_KyloRen", "Kylo Ren", "kyloren"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Maul", "Darth Maul", "darthmaul"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Bossk", "Bossk", "bossk"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_DarthVader", "Darth Vader", "darthvader"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Iden", "Iden Versio", "idenversio"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Emperor", "Emperor Palpatine", "palpatine"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Phasma", "Captain Phasma", "phasma"),

	//vehicles
	PlayerObject("Gameplay/Vehicles/Air/AirSpeeder/Vehicle_Air_AirSpeeder", "Air Speeder",  "airspeeder"),
	PlayerObject("Gameplay/Vehicles/Air/AWing/Vehicle_Air_AWing", "A-Wing",  "awing"),
	PlayerObject("Gameplay/Vehicles/Air/AWingRZ3/Vehicle_Air_AWingRZ3", "A-Wing RZ3",  "awing"),
	PlayerObject("Gameplay/Vehicles/Air/BTLYwing/Vehicle_Air_BTLYWing", "BTL-B Y-Wing",  "btlbywing"),
	PlayerObject("Gameplay/Vehicles/Air/Ywing/Vehicle_Air_YWing", "Y-Wing",  "btlaywing"),
	PlayerObject("Gameplay/Vehicles/Air/XWing_T65/Vehicle_Air_XWing_T65", "X-Wing",  "xwingt65"),
	PlayerObject("Gameplay/Vehicles/Air/DroidTriFighter/Vehicle_Air_DroidTriFighter", "Tri-Fighter",  "trifighter"),
	PlayerObject("Gameplay/Vehicles/Air/VultureDroid/Vehicle_Air_VultureDroid", "Vulture Droid",  "vulturedroid"),
	PlayerObject("Gameplay/Vehicles/Air/HyeneBomber/Vehicle_Air_HyeneBomber", "Hyene Bomber",  "hyenabomber"),
	PlayerObject("Gameplay/Vehicles/Air/HyenaBomber/Vehicle_Air_HyenaBomber", "Hyene Bomber",  "hyenabomber"), //excelent naming conventions DICE
	PlayerObject("Gameplay/Vehicles/Air/ARC170/Vehicle_Air_ARC170", "ARC170",  "arc170"),
	PlayerObject("Gameplay/Vehicles/Air/Vwing/Vehicle_Air_Vwing", "V-Wing",  "vwing"),
	PlayerObject("Gameplay/Vehicles/Air/TieFighterSpecialForces/Vehicle_Air_TieFighterSpecialForces", "Special Forces Tie Fighter",  "tiefightersf"),
	PlayerObject("Gameplay/Vehicles/Air/TieFighterFirstOrder/Vehicle_Air_TieFighterFirstOrder", "First Order Tie Fighter",  "tiefighterfo"),
	PlayerObject("Gameplay/Vehicles/Air/XWing_T70/Vehicle_Air_XWing_T70", "T70 X-Wing",  "xwingt70"),
	PlayerObject("Gameplay/Vehicles/Air/TieFighter/Vehicle_Air_TieFighter", "Tie Fighter",  "tiefighter"),
	PlayerObject("Gameplay/Vehicles/Air/TieInterceptor/Vehicle_Air_TieInterceptor", "Tie Interceptor",  "tieinterceptor"),
	PlayerObject("Gameplay/Vehicles/Air/TieBomber/Vehicle_Air_TieBomber", "Tie Bomber",  "tiebomber")
};


time_t starttime = time(0);



char* TranslateLevel(char* inchar) {
	for (int i = 0; i < maplist.size(); i++) {
		if (strcmp(inchar, maplist[i].baseName.c_str()) == 0) {
			return (char*)maplist[i].mapTitle.c_str();
		}
	}
	return (char*)"\0";
}


char* TranslateClass(char* inchar) {
	for (int i = 0; i < playerList.size(); i++) {
		if (strcmp(inchar, playerList[i].baseName.c_str()) == 0) {
			return (char*)playerList[i].playerName.c_str();
		}
	}
//	return (char*)"\0";
	return inchar;
}

char* TranslateImage(char* inchar) {
	for (int i = 0; i < playerList.size(); i++) {
		if (strcmp(inchar, playerList[i].baseName.c_str()) == 0) {
			return (char*)playerList[i].imageName.c_str();
		}
	}
	return (char*)"default";
}

char* GetFaction(char* map, int TeamID, char* classname) {
	if (TeamID == 0) return (char*)"\0";
	for (int i = 0; i < maplist.size(); i++) {
		if (strcmp(map, maplist[i].baseName.c_str()) == 0) {
			char* str = new char[128];
			if (strcmp(TranslateClass(classname), "Soldier") == 0) {

				if (maplist[i].trilogy == Trilogy::Prequil) {
					strcpy(str, (TeamID == 1) ? (char*)"Galactic Republic" : (char*)"Confederacy");
				}
				if (maplist[i].trilogy == Trilogy::Original) {
					strcpy(str, (TeamID == 1) ? (char*)"Rebel Alliance" : (char*)"Galactic Empire");
				}
				if (maplist[i].trilogy == Trilogy::NewEra) {
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
	for (int i = 0; i < maplist.size(); i++) {
		if (strcmp(inchar, maplist[i].mapTitle.c_str()) == 0) {
			if (strcmp(maplist[i].mapTitle.c_str(), "none")) return(char*)"\0";
			return (char*)maplist[i].imageName.c_str();
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
	HINSTANCE hGetProcIDDLL = LoadLibrary("./cmods/discord-rpc/discord-rpc.dll");	//updated for use in the mod manager
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

	ititialize("420031141777768470", NULL, true, NULL);
	while (true)
	{
		Sleep(500);
		StaticGameContext* pGC = (StaticGameContext*)(DWORD64*)(OFFSET_ClientGameContext);
		char* Classname = pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetPlayerClassName();
		char* Levelname = pGC->GetGameContext()->GetClientLevel()->GetLevelName();
		int PlayerTeam = pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetTeam();


		updatePresence(&GetUpdate(TranslateLevel(Levelname), GetFaction(Levelname, PlayerTeam, Classname),  TranslateImage(Classname)));
		
		if (GetAsyncKeyState(VK_END)) {
			FreeConsole();
			shutdown();
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