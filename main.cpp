#include <Windows.h>

DWORD* player_base;
DWORD* game_base;
DWORD* gold;
DWORD ret_address = 0xCCAF90;

__declspec(naked) void codecave() {
	__asm {
		pushad
	}

	player_base = (DWORD*)0x017EED18;
	game_base = (DWORD*)(*player_base + 0xA90);
	gold = (DWORD*)(*game_base + 4);
	*gold = 888;

	_asm {
		popad
		mov eax, dword ptr ds:[ecx]
		lea esi,dword ptr ds:[esi]
		jmp ret_address
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	DWORD old_protect;
	unsigned char* hook_location = (unsigned char*)0x00CCAF8A;

	if (fdwReason == DLL_PROCESS_ATTACH) {
		VirtualProtect((void*)hook_location, 6, PAGE_EXECUTE_READWRITE, &old_protect);
		*hook_location = 0xE9;
		*(DWORD*)(hook_location + 1) = (DWORD)&codecave - ((DWORD)hook_location + 5);
		*(hook_location + 5) = 0x90;
	}

	return true;
} 
