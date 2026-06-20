__int64 __fastcall wlan_hdd_get_set_client_info_id(
        __int64 a1,
        int a2,
        _DWORD *a3,
        __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  int *v14; // x8
  int v16; // w10

  v14 = (int *)(a1 + 52104);
  if ( *(_BYTE *)(a1 + 52112) != 1 )
    goto LABEL_13;
  if ( *(_DWORD *)(a1 + 52108) == a2 )
  {
LABEL_3:
    *a3 = *v14;
    *((_WORD *)v14 + 5) = a4;
    return 0;
  }
  v14 = (int *)(a1 + 52120);
  if ( *(_BYTE *)(a1 + 52128) != 1 )
    goto LABEL_13;
  if ( *(_DWORD *)(a1 + 52124) == a2 )
    goto LABEL_3;
  v14 = (int *)(a1 + 52136);
  if ( *(_BYTE *)(a1 + 52144) != 1 )
    goto LABEL_13;
  if ( *(_DWORD *)(a1 + 52140) == a2 )
    goto LABEL_3;
  v14 = (int *)(a1 + 52152);
  if ( *(_BYTE *)(a1 + 52160) != 1 )
    goto LABEL_13;
  if ( *(_DWORD *)(a1 + 52156) == a2 )
    goto LABEL_3;
  v14 = (int *)(a1 + 52168);
  if ( *(_BYTE *)(a1 + 52176) == 1 )
  {
    if ( *(_DWORD *)(a1 + 52172) == a2 )
      goto LABEL_3;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Max client ID reached",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_get_set_client_info_id",
      v12,
      v13);
    return 4;
  }
  else
  {
LABEL_13:
    v16 = *v14;
    v14[1] = a2;
    *((_BYTE *)v14 + 8) = 1;
    *a3 = v16;
    *((_WORD *)v14 + 5) = a4;
    *((_BYTE *)v14 + 12) = 0;
    return 0;
  }
}
