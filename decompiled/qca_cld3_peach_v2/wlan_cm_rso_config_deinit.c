__int64 __fastcall wlan_cm_rso_config_deinit(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 248);
  if ( v2 )
  {
    _qdf_mem_free(v2);
    *(_QWORD *)(a2 + 248) = 0;
    *(_DWORD *)(a2 + 240) = 0;
  }
  v4 = *(_QWORD *)(a2 + 264);
  if ( v4 )
  {
    _qdf_mem_free(v4);
    *(_QWORD *)(a2 + 264) = 0;
    *(_DWORD *)(a2 + 256) = 0;
  }
  v5 = *(_QWORD *)(a2 + 848);
  if ( v5 )
    _qdf_mem_free(v5);
  *(_QWORD *)(a2 + 848) = 0;
  *(_BYTE *)(a2 + 840) = 0;
  cm_flush_roam_channel_list(a2 + 112);
  cm_flush_roam_channel_list(a2 + 168);
  result = qdf_mutex_destroy(a2);
  *(_BYTE *)(a2 + 1382) = 0;
  return result;
}
