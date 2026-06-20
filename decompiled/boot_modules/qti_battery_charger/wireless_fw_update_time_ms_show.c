__int64 __fastcall wireless_fw_update_time_ms_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", *(_DWORD *)(a1 + 1080));
}
