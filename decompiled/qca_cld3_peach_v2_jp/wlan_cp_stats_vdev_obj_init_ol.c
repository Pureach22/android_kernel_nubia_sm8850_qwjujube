__int64 __fastcall wlan_cp_stats_vdev_obj_init_ol(__int64 a1)
{
  *(_DWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  wlan_cp_stats_vdev_cs_init();
  return 0;
}
