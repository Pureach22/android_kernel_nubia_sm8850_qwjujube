__int64 __fastcall wlan_cfg80211_mc_cp_stats_dealloc(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  int v11; // w20
  __int64 *v12; // x21
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0

  if ( !a1 )
    return qdf_trace_msg(
             0x48u,
             2u,
             "%s: stats is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_cfg80211_mc_cp_stats_dealloc");
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  _qdf_mem_free(*(_QWORD *)(a1 + 24));
  _qdf_mem_free(*(_QWORD *)(a1 + 40));
  _qdf_mem_free(*(_QWORD *)(a1 + 80));
  _qdf_mem_free(*(_QWORD *)(a1 + 96));
  _qdf_mem_free(*(_QWORD *)(a1 + 128));
  _qdf_mem_free(*(_QWORD *)(a1 + 56));
  v10 = *(_QWORD *)(a1 + 160);
  if ( v10 )
  {
    if ( *(_DWORD *)(a1 + 156) )
    {
      v11 = 0;
      v12 = (__int64 *)(v10 + 112);
      do
      {
        _qdf_mem_free(*v12);
        v13 = v12[1];
        *v12 = 0;
        _qdf_mem_free(v13);
        *v12 = 0;
        v12 += 17;
        ++v11;
      }
      while ( *(_DWORD *)(a1 + 156) > (unsigned int)(unsigned __int16)v11 );
      v10 = *(_QWORD *)(a1 + 160);
    }
    _qdf_mem_free(v10);
    *(_QWORD *)(a1 + 160) = 0;
  }
  v14 = *(_QWORD *)(a1 + 112);
  *(_DWORD *)(a1 + 156) = 0;
  _qdf_mem_free(v14);
  v15 = *(_QWORD *)(a1 + 192);
  *(_QWORD *)(a1 + 112) = 0;
  _qdf_mem_free(v15);
  return _qdf_mem_free(*(_QWORD *)(a1 + 208));
}
