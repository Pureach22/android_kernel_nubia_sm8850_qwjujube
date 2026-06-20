__int64 __fastcall wlan_get_chan_by_link_id_from_rnr(__int64 a1, int a2, char a3, _BYTE *a4, _BYTE *a5)
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
  int v22; // w10

  *a4 = 0;
  v10 = (void *)_qdf_mem_malloc(0x424u, "wlan_get_chan_by_link_id_from_rnr", 3054);
  if ( v10 )
  {
    v19 = (__int64)v10;
    rnr = wlan_cm_get_rnr(a1, a2, v10, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( !rnr )
    {
      for ( i = 0; i != 1056; i += 32 )
      {
        if ( v19 + i != -4 )
        {
          v22 = *(_DWORD *)(v19 + i + 8);
          if ( v22 )
          {
            if ( (*(_WORD *)(v19 + i + 32) & 0xF) == a3 )
            {
              *a4 = v22;
              rnr = 0;
              *a5 = *(_DWORD *)(v19 + i + 12);
              goto LABEL_11;
            }
          }
        }
      }
      rnr = 0;
    }
LABEL_11:
    _qdf_mem_free(v19);
  }
  else
  {
    return 2;
  }
  return rnr;
}
