__int64 __fastcall populate_dot11f_rrm_sta_stats_report(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  int v13; // w14
  int v14; // w12
  int v15; // w13
  int v16; // w9
  int v17; // w11
  int v18; // w8
  int v19; // w10
  char v20; // w15
  int v21; // w4
  char v22; // w9
  bool v23; // w14

  v13 = *(_DWORD *)(a11 + 28);
  v15 = *(_DWORD *)(a11 + 4);
  v14 = *(_DWORD *)(a11 + 8);
  v16 = *(_DWORD *)(a11 + 12);
  v17 = *(_DWORD *)(a11 + 16);
  v19 = *(_DWORD *)(a11 + 20);
  v18 = *(_DWORD *)(a11 + 24);
  *(_WORD *)(a10 + 4) = *(_WORD *)a11;
  v20 = *(_BYTE *)(a11 + 2);
  *(_BYTE *)(a10 + 60) = 0;
  *(_BYTE *)(a10 + 6) = v20;
  v21 = *(unsigned __int8 *)(a11 + 2);
  if ( v21 == 10 )
  {
    *(_DWORD *)(a10 + 8) = v15;
    *(_BYTE *)(a10 + 12) = v14;
    *(_WORD *)(a10 + 14) = HIWORD(v14);
    *(_BYTE *)(a10 + 16) = v16;
    return 0;
  }
  if ( v21 == 1 )
  {
    v23 = v15 != 0;
    if ( v15 )
      *(_BYTE *)(a10 + 61) |= 0x40u;
    *(_DWORD *)(a10 + 8) = v15;
    if ( v14 )
    {
      v23 = 1;
      *(_BYTE *)(a10 + 61) |= 4u;
    }
    *(_DWORD *)(a10 + 12) = v14;
    if ( v16 )
    {
      v23 = 1;
      *(_BYTE *)(a10 + 61) |= 8u;
    }
    *(_DWORD *)(a10 + 16) = v16;
    *(_DWORD *)(a10 + 20) = v17;
    if ( v19 )
    {
      v23 = 1;
      *(_BYTE *)(a10 + 61) |= 0x10u;
    }
    *(_DWORD *)(a10 + 24) = v19;
    if ( v18 )
    {
      *(_BYTE *)(a10 + 61) |= 0x20u;
      *(_DWORD *)(a10 + 28) = v18;
    }
    else
    {
      *(_DWORD *)(a10 + 28) = 0;
      if ( !v23 )
        return 0;
    }
    goto LABEL_23;
  }
  if ( *(_BYTE *)(a11 + 2) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: group id not supported %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "populate_dot11f_rrm_sta_stats_report",
      v11,
      v12);
    return 0;
  }
  *(_DWORD *)(a10 + 8) = v15;
  *(_DWORD *)(a10 + 12) = v14;
  if ( v16 )
    *(_BYTE *)(a10 + 61) |= 1u;
  *(_DWORD *)(a10 + 16) = v16;
  *(_DWORD *)(a10 + 20) = v13;
  *(_DWORD *)(a10 + 24) = v17;
  if ( v19 )
  {
    v22 = *(_BYTE *)(a10 + 61);
    *(_DWORD *)(a10 + 28) = v19;
    *(_BYTE *)(a10 + 61) = v22 | 2;
    *(_DWORD *)(a10 + 32) = v18;
LABEL_23:
    *(_BYTE *)(a10 + 60) = 1;
    return 0;
  }
  *(_DWORD *)(a10 + 28) = 0;
  *(_DWORD *)(a10 + 32) = v18;
  if ( v16 )
    goto LABEL_23;
  return 0;
}
