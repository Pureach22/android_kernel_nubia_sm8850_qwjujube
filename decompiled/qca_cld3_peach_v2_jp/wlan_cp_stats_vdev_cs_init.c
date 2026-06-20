__int64 __fastcall wlan_cp_stats_vdev_cs_init(__int64 a1)
{
  __int64 v2; // x8

  v2 = _qdf_mem_malloc(0xE0u, "wlan_cp_stats_vdev_cs_init", 341);
  *(_QWORD *)(a1 + 8) = v2;
  return 2 * (unsigned int)(v2 == 0);
}
