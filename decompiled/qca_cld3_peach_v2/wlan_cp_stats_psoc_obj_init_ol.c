__int64 __fastcall wlan_cp_stats_psoc_obj_init_ol(__int64 a1)
{
  *(_DWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  wlan_cp_stats_psoc_cs_init();
  return 0;
}
