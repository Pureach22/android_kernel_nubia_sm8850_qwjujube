__int64 __fastcall wlan_cp_stats_peer_cs_deinit(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 8);
  _qdf_mem_free(*(_QWORD *)(v1 + 24));
  v3 = *(_QWORD *)(v1 + 16);
  *(_QWORD *)(v1 + 24) = 0;
  _qdf_mem_free(v3);
  *(_QWORD *)(v1 + 16) = 0;
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  *(_QWORD *)(a1 + 8) = 0;
  return 0;
}
