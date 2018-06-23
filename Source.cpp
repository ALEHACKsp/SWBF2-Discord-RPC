#include "Translations.h"
#include "discord_rpc.h"

#pragma warning(disable : 4996)

/*
typedef struct DiscordRichPresence {
	const char* state;   
	const char* details; 
	int64_t startTimestamp;
	int64_t endTimestamp;
	const char* largeImageKey;  
	const char* largeImageText; 
	const char* smallImageKey;  
	const char* smallImageText; 
	const char* partyId;        
	int partySize;
	int partyMax;
	const char* matchSecret;    
	const char* joinSecret;     
	const char* spectateSecret; 
	int8_t instance;
} DiscordRichPresence; */

time_t starttime = time(0);

DiscordRichPresence GetUpdate(const char* data, const char* playername, const char* faction, const char* image, const char* GameMode) {

	char buffer[256];
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = GameMode;
	discordPresence.details = playername;
	discordPresence.largeImageKey = image;
	discordPresence.largeImageText = faction;
	char* smallimg = TranslateLevelImage(data);
	if (strcmp(smallimg, "none") != 0) {
		discordPresence.smallImageKey = smallimg;
	}
	discordPresence.smallImageText = data;
	discordPresence.startTimestamp = starttime;
	discordPresence.instance = 0;
	return discordPresence;
}

/*
typedef void(cdecl *f_Initialize)(const char* appid, int shit, bool autoRegister, const char* steamId);

typedef void(cdecl *f_UpdatePresence)(const DiscordRichPresence* presence);

typedef void(cdecl *f_RunCallbacks)();

typedef void(cdecl *f_Shutdown)();*/


std::string bigNumberWithCommas(std::string str)
{
	if (str.length() < 5)
		return str;
	std::size_t pos = str.length() % 3;
	if (pos == 0)
		pos = 3;
	while (pos < str.length())
	{
		str.insert(pos, 1, ',');
		pos += 4;
	}
	return str;
}

//#define console
DWORD WINAPI Looper(LPVOID lpParam)
{
#ifdef console
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
#endif

	/*f_Initialize ititialize = (f_Initialize)GetProcAddress(hGetProcIDDLL, "Discord_Initialize");
	f_UpdatePresence updatePresence = (f_UpdatePresence)GetProcAddress(hGetProcIDDLL, "Discord_UpdatePresence");
	f_RunCallbacks runCallbacks = (f_RunCallbacks)GetProcAddress(hGetProcIDDLL, "Discord_RunCallbacks");
	f_Shutdown shutdown = (f_Shutdown)GetProcAddress(hGetProcIDDLL, "Discord_Shutdown");*/
	Discord_Initialize("420031141777768470", NULL, true, NULL);
	while (true)
	{
		Sleep(500);

		if (GetAsyncKeyState(VK_END)) {
			FreeConsole();
			Discord_Shutdown();
			FreeLibraryAndExitThread((HMODULE)lpParam, 0);
		}

		StaticGameContext* pGC = (StaticGameContext*)(DWORD64*)(OFFSET_CLIENTGAMECONTEXT);
		if ((pGC == nullptr)
		|| (pGC->gameContext == nullptr)
		|| (pGC->GetGameContext() == nullptr)

		|| (pGC->GetGameContext()->clientLevel == nullptr)
		|| (pGC->GetGameContext()->GetClientLevel() == nullptr)

		|| (pGC->GetGameContext()->GetClientLevel()->matchInfo == nullptr) 
		|| (pGC->GetGameContext()->GetClientLevel()->GetMatchInfo() == nullptr)

		|| (pGC->GetGameContext()->GetClientLevel()->GetMatchInfo()->GameMode == nullptr)

		|| (pGC->GetGameContext()->GetClientLevel()->LevelName == nullptr) 
		|| (pGC->GetGameContext()->GetPlayerManager() == nullptr)

		|| (pGC->GetGameContext()->GetPlayerManager()->LocalPlayer == nullptr) 
		|| (pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer() == nullptr)

		|| (pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->Name == nullptr)


		|| (pGC->GetGameContext()->GetPlayerManager()->GetmPPlayer() == nullptr) 
		|| (pGC->GetGameContext()->GetPlayerManager()->GetmPPlayer()->PlayerArray[1] == nullptr)) {

			Discord_UpdatePresence(&GetUpdate("Menus", "In Menus", "In Menus", "default", "\0"));
			continue;
		}


		if ((pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->attachedControllable == nullptr) && (pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->controlledControllable == nullptr))
		{
			Discord_UpdatePresence(&GetUpdate("Menus", "In Menus", "In Menus", "default", "\0"));
			continue;
		}

		if (pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->controlledControllable == nullptr)
		{
			if ((pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetAttachedControllable()->vehicleEntity == nullptr) ||
				(pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetAttachedControllable()->GetVehicleEntityData()->VehicleName == nullptr))
			{
				Discord_UpdatePresence(&GetUpdate("Menus", "In Menus", "In Menus", "default", "\0"));
				continue;
			}
		}

		char* Classname = pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetPlayerClassName();
		char* Levelname = pGC->GetGameContext()->GetClientLevel()->GetLevelName();
		int PlayerTeam = pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetTeam();

		char* PlayerName = new char[256];
		strcpy(PlayerName, "Origin ID: ");
		strcat (PlayerName, pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->GetName());


		char* Stats = new char[256];
		int kills =(pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->Kills + pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->Assists);
		int deaths = (pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->Deaths);
		if (deaths == 0) deaths = 1;
		std::string score = bigNumberWithCommas(std::to_string(pGC->GetGameContext()->GetPlayerManager()->GetLocalPlayer()->Score));
		std::string kdr = std::to_string((float)kills / (float)deaths);
		kdr = kdr.erase(kdr.find_first_of(".") + 3);
		
		strcpy(Stats, "Score: ");
		strcat(Stats, score.c_str());
		strcat(Stats, " KDR: ");
		strcat(Stats, kdr.c_str());


		char* GameMode = new char[256];
		//strcpy(GameMode, "Playing ");
		strcpy(GameMode, TranslateMode(pGC->GetGameContext()->GetClientLevel()->GetMatchInfo()->GetMatchMode()));

#ifdef console
		std::cout << TranslateLevel(Levelname) << std::endl;
		std::cout << Stats << std::endl;
		std::cout << GetFaction(Levelname, PlayerTeam, Classname) << std::endl;
		std::cout << TranslateImage(Levelname, PlayerTeam, Classname) << std::endl;
		std::cout << GameMode << std::endl;
		std::cout << "--------------" << std::endl << std::endl;
#endif
		Discord_UpdatePresence(&GetUpdate(TranslateLevel(Levelname), Stats, GetFaction(Levelname, PlayerTeam, Classname),  TranslateImage(Levelname, PlayerTeam, Classname), GameMode));

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