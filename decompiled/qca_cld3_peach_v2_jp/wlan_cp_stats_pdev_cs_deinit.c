__int64 __fastcall wlan_cp_stats_pdev_cs_deinit(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  *(_QWORD *)(a1 + 8) = 0;
  return 0;
}
