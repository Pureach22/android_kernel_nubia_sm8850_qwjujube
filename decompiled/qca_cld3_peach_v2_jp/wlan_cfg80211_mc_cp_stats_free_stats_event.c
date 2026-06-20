__int64 __fastcall wlan_cfg80211_mc_cp_stats_free_stats_event(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  int v3; // w20
  __int64 *v4; // x21
  __int64 v5; // x0
  __int64 v6; // x0

  if ( result )
  {
    v1 = result;
    _qdf_mem_free(*(_QWORD *)(result + 8));
    _qdf_mem_free(*(_QWORD *)(v1 + 40));
    _qdf_mem_free(*(_QWORD *)(v1 + 80));
    _qdf_mem_free(*(_QWORD *)(v1 + 96));
    _qdf_mem_free(*(_QWORD *)(v1 + 128));
    _qdf_mem_free(*(_QWORD *)(v1 + 56));
    _qdf_mem_free(*(_QWORD *)(v1 + 112));
    v2 = *(_QWORD *)(v1 + 160);
    *(_QWORD *)(v1 + 112) = 0;
    if ( v2 )
    {
      if ( *(_DWORD *)(v1 + 156) )
      {
        v3 = 0;
        v4 = (__int64 *)(v2 + 112);
        do
        {
          _qdf_mem_free(*v4);
          v5 = v4[1];
          *v4 = 0;
          _qdf_mem_free(v5);
          *v4 = 0;
          v4 += 17;
          ++v3;
        }
        while ( *(_DWORD *)(v1 + 156) > (unsigned int)(unsigned __int16)v3 );
        v2 = *(_QWORD *)(v1 + 160);
      }
      _qdf_mem_free(v2);
      *(_QWORD *)(v1 + 160) = 0;
    }
    v6 = *(_QWORD *)(v1 + 192);
    *(_DWORD *)(v1 + 156) = 0;
    _qdf_mem_free(v6);
    _qdf_mem_free(*(_QWORD *)(v1 + 208));
    return _qdf_mem_free(v1);
  }
  return result;
}
