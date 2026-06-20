__int64 __fastcall wlan_cp_stats_psoc_cs_init(__int64 a1)
{
  __int64 v2; // x8

  v2 = _qdf_mem_malloc(0x1D8u, "wlan_cp_stats_psoc_cs_init", 325);
  *(_QWORD *)(a1 + 40) = v2;
  return 2 * (unsigned int)(v2 == 0);
}
