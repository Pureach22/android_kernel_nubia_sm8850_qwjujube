__int64 __fastcall wlan_cp_stats_psoc_cs_deinit(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 40));
  *(_QWORD *)(a1 + 40) = 0;
  return 0;
}
