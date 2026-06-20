__int64 __fastcall wlan_get_chan_by_bssid_from_rnr(__int64 a1, int a2, __int64 a3, _BYTE *a4, _BYTE *a5)
{
  void *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  unsigned int rnr; // w23
  __int64 i; // x8
  __int64 v22; // x9
  int v23; // w11
  int v24; // w9
  __int64 v26; // x8

  *a4 = 0;
  v10 = (void *)_qdf_mem_malloc(0x3A0u, "wlan_get_chan_by_bssid_from_rnr", 3003);
  if ( v10 )
  {
    v19 = (__int64)v10;
    rnr = wlan_cm_get_rnr(a1, a2, v10, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( !rnr )
    {
      for ( i = 0; i != 924; i += 28 )
      {
        v22 = v19 + i;
        if ( *(_DWORD *)(v19 + i + 8) )
        {
          v23 = *(_DWORD *)(v22 + 16);
          v24 = *(unsigned __int16 *)(v22 + 20);
          if ( *(_DWORD *)a3 == v23 && *(unsigned __int16 *)(a3 + 4) == v24 )
          {
            v26 = v19 + i;
            rnr = 0;
            *a4 = *(_DWORD *)(v26 + 8);
            *a5 = *(_DWORD *)(v26 + 12);
            goto LABEL_14;
          }
        }
      }
      rnr = 0;
    }
LABEL_14:
    _qdf_mem_free(v19);
  }
  else
  {
    return 2;
  }
  return rnr;
}
