__int64 __fastcall tdls_get_mlme_ch_power(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w8
  __int64 v13; // x8

  v12 = *(unsigned __int8 *)(a1 + 533);
  if ( !*(_BYTE *)(a1 + 533) )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 636) == a2 )
  {
    v13 = 0;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 1 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 644) == a2 )
  {
    v13 = 1;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 2 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 652) == a2 )
  {
    v13 = 2;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 3 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 660) == a2 )
  {
    v13 = 3;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 4 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 668) == a2 )
  {
    v13 = 4;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 5 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 676) == a2 )
  {
    v13 = 5;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 6 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 684) == a2 )
  {
    v13 = 6;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 7 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 692) == a2 )
  {
    v13 = 7;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 8 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 700) == a2 )
  {
    v13 = 8;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 9 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 708) == a2 )
  {
    v13 = 9;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 10 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 716) == a2 )
  {
    v13 = 10;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 11 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 724) == a2 )
  {
    v13 = 11;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 12 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 732) == a2 )
  {
    v13 = 12;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 13 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 740) == a2 )
  {
    v13 = 13;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 14 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 748) == a2 )
  {
    v13 = 14;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 15 )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 756) == a2 )
  {
    v13 = 15;
    return *(unsigned __int8 *)(a1 + 636 + 8 * v13 + 4);
  }
  if ( v12 == 16 )
  {
LABEL_6:
    qdf_trace_msg(
      0,
      8u,
      "%s: channel %d not present in reg power info",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_get_mlme_ch_power",
      a2,
      v10,
      v11);
    return 0;
  }
  else
  {
    __break(0x5512u);
    return tdls_pe_add_peer(a1);
  }
}
