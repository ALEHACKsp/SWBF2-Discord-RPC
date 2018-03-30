#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

#pragma warning(disable : 4996)




std::vector<std::vector<std::string>> LevelNames = {
	{"Levels/FrontEnd/FrontEnd", "In Main Menu"},
	{"\0", "In Loading Screen"},
	{"Levels/MP/Tatooine_01/Tatooine_01", "Mos Eisley, Tatooine"},
	{"Levels/MP/Yavin_01/Yavin_01", "The Greate Temple, Yavin IV"},
	{"Levels/MP/Kamino_01/Kamino_01", "Cloning Facility, Kamino"},
	{"Levels/MP/Naboo_01/Naboo_01", "Theed, Naboo"},
	{"Levels/MP/StarKiller_01/StarKiller_01", "Command Center, Starkiller Base"},
	{"Levels/MP/Takodana_01/Takodana_01", "Maz's Castle, Takodana"},
	{"Levels/MP/Endor_01/Endor_01", "Research Station 9, Endor"},
	{"Levels/MP/Kashyyyk_01/Kashyyyk_01", "Kachirho Beach, Kashyyyk"},
	{"Levels/MP/Jakku_01/Jakku_01", "The Graveyard, Jakku"},
	{"Levels/MP/Deathstar_02/Deathstar_02", "Command Sector North, Death Star II"},
	{"Levels/MP/Hoth_01/Hoth_01", "Outpost Delta, Hoth"},
	{"S2/Levels/Crait_01/Crait_01", "Abandoned Rebel Outpost, Crait"},
	{"S2/Levels/CloudCity_01/CloudCity_01", "Administrator's Palace, Bespin"}
};





char* Translate(char* inchar) {
	for (int i = 0; i < LevelNames.size(); i++) {
		if (strcmp(inchar, LevelNames[i][0].c_str()) == 0) return (char*)LevelNames[i][1].c_str();
	}
	//if (strcmp(inchar, "Levels/FrontEnd/FrontEnd") == 0) return new char[9] {"In Menus"};
	return inchar;
}



class ClientLevel
{
public:
	char pad_0000[56]; //0x0000
	char* LevelName; //0x0038
	char pad_0040[264]; //0x0040
	char* GetLevelName() {
		if (this != nullptr && this->LevelName != nullptr) {
			return this->LevelName;
		}
		return (char*)"\0";
	}
}; //Size: 0x0148


class GameContext
{
public:
	char pad_0000[56]; //0x0000
	class ClientLevel* clientLevel; //0x0038
	char pad_0040[1032]; //0x0040
	ClientLevel* GetClientLevel() {
		if (this->clientLevel != nullptr) {
			return this->clientLevel;
		}
	}
}; //Size: 0x0448


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


DiscordRichPresence GetUpdate(const char* map, int score) {

	char buffer[256];
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = map;
//	sprintf(buffer, "Score:  %d", score);
	//discordPresence.details = buffer;
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
		updatePresence(&GetUpdate(Translate(pGC->GetGameContext()->GetClientLevel()->GetLevelName()), 100));
		
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