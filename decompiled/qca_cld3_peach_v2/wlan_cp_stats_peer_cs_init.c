__int64 __fastcall wlan_cp_stats_peer_cs_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x0

  v2 = _qdf_mem_malloc(0x58u, "wlan_cp_stats_peer_cs_init", 376);
  if ( v2 )
  {
    v3 = v2;
    v4 = _qdf_mem_malloc(0x18u, "wlan_cp_stats_peer_cs_init", 381);
    *(_QWORD *)(v3 + 24) = v4;
    if ( v4 )
    {
      v5 = _qdf_mem_malloc(0x20u, "wlan_cp_stats_peer_cs_init", 390);
      *(_QWORD *)(v3 + 16) = v5;
      if ( v5 )
      {
        *(_QWORD *)(a1 + 8) = v3;
        return 0;
      }
      _qdf_mem_free(*(_QWORD *)(v3 + 24));
      *(_QWORD *)(v3 + 24) = 0;
    }
    _qdf_mem_free(v3);
  }
  return 2;
}
