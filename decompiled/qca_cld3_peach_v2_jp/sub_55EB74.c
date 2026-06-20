__int64 __fastcall sub_55EB74(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // s16
  int v6; // s26

  *(_DWORD *)(a5 - 140) = v6;
  *(_DWORD *)(a5 - 136) = v5;
  return hdd_send_get_thermal_stats_cmd(a1, a2, a3, a4);
}
