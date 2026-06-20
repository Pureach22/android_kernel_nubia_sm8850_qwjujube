__int64 __fastcall sysmon_notify(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_DWORD *)(a1 - 144) == 1 && strcmp(*(const char **)(a3 + 128), *(const char **)(a1 - 72)) )
    ((void (__fastcall *)(__int64, __int64))send_event)(a1 - 200, a3);
  return 0;
}
