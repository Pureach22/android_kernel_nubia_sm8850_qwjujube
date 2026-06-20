__int64 __fastcall lim_enable_ht20_protection(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v13; // w8
  int v14; // w9
  __int64 v15; // x19
  __int64 v16; // x20
  int v17; // w8
  int v18; // w8
  unsigned int v20; // w22
  __int64 v21; // x19
  __int64 v22; // x20
  __int64 v23; // x0
  __int64 v24; // x2
  int v25; // w8
  __int64 v27; // x20
  __int64 v28; // x21
  __int16 v29; // w9
  int v30; // w8
  __int64 v32; // x19
  __int64 v33; // x20
  __int16 v34; // w8
  __int64 v35; // x19
  __int64 v36; // x20
  __int16 v37; // w8

  if ( !*(_BYTE *)(a5 + 155) )
    return 0;
  if ( !(_BYTE)a3 )
  {
    if ( *(_DWORD *)(a5 + 88) == 1 )
    {
      if ( (*(_WORD *)(a5 + 432) & 0x800) != 0 )
        goto LABEL_3;
    }
    else if ( (*(_WORD *)(a1 + 8880) & 0x800) != 0 )
    {
      goto LABEL_3;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: protection from HT20 is disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_enable_ht20_protection");
    return 0;
  }
LABEL_3:
  if ( a2 )
  {
    v13 = *(_DWORD *)(a5 + 88);
    if ( (_BYTE)a3 && v13 == 1 )
    {
      v14 = *(_DWORD *)(a5 + 280) | 2;
      *(_BYTE *)(a5 + 1231) = 1;
      if ( v14 == 3 )
        goto LABEL_27;
      *(_DWORD *)(a5 + 280) = 1;
      v15 = a4;
      v16 = a5;
      lim_enable_ht_rifs_protection(a1, 1, a3, a4, a5);
    }
    else
    {
      if ( (_BYTE)a3 || v13 != 1 || (v25 = *(_DWORD *)(a5 + 280), *(_BYTE *)(a5 + 445) = 1, v25) )
      {
LABEL_27:
        if ( !*(_BYTE *)(a5 + 7164) )
        {
          v27 = a4;
          v28 = a5;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: => Protection from HT20 Enabled",
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            "lim_handle_ht20protection_enabled");
          *(_BYTE *)(v28 + 7164) = 1;
          v29 = *(_WORD *)(v27 + 14);
          *(_BYTE *)(v27 + 9) = 1;
          *(_WORD *)(v27 + 14) = v29 | 0x40;
        }
        return 0;
      }
      if ( *(_BYTE *)(a5 + 160) )
        *(_DWORD *)(a5 + 280) = 2;
      v15 = a4;
      v16 = a5;
      lim_enable_ht_rifs_protection(a1, 0, 0, a4, a5);
      lim_enable_ht_obss_protection(a1, 0, 0, v15, v16);
    }
    a5 = v16;
    a4 = v15;
    goto LABEL_27;
  }
  if ( *(_BYTE *)(a5 + 7164) != 1 )
    return 0;
  v17 = *(_DWORD *)(a5 + 88);
  if ( (_BYTE)a3 && v17 == 1 )
  {
    v18 = *(unsigned __int8 *)(a5 + 1225);
    *(_BYTE *)(a5 + 1231) = 0;
    if ( !v18 && !*(_BYTE *)(a5 + 1227) && !*(_BYTE *)(a5 + 1233) && *(_DWORD *)(a5 + 280) == 1 )
    {
      if ( !*(_BYTE *)(a5 + 445) )
      {
        *(_DWORD *)(a5 + 280) = 0;
        goto LABEL_36;
      }
      v20 = a3;
      v21 = a4;
      v22 = a5;
      *(_DWORD *)(a5 + 280) = 2 * (*(_BYTE *)(a5 + 160) != 0);
      lim_enable_ht_rifs_protection(a1, 0, a3, a4, a5);
      v23 = a1;
      v24 = v20;
      goto LABEL_35;
    }
  }
  else if ( !(_BYTE)a3 && v17 == 1 )
  {
    v30 = *(_DWORD *)(a5 + 280);
    *(_BYTE *)(a5 + 445) = 0;
    if ( v30 == 2 )
    {
      *(_DWORD *)(a5 + 280) = 0;
      v21 = a4;
      v22 = a5;
      lim_enable_ht_rifs_protection(a1, 0, 0, a4, a5);
      v23 = a1;
      v24 = 0;
LABEL_35:
      lim_enable_ht_obss_protection(v23, 0, v24, v21, v22);
      a5 = v22;
      a4 = v21;
    }
  }
LABEL_36:
  if ( *(_DWORD *)(a5 + 88) != 1 )
    goto LABEL_38;
  v32 = a4;
  v33 = a5;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ===> Protection from HT 20 Disabled",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_handle_ht20coexist_ht20protection");
  *(_BYTE *)(v33 + 7164) = 0;
  a5 = v33;
  a4 = v32;
  v34 = *(_WORD *)(v32 + 14);
  *(_BYTE *)(v32 + 9) = 0;
  *(_WORD *)(v32 + 14) = v34 | 0x40;
  if ( *(_DWORD *)(v33 + 88) != 1 )
  {
LABEL_38:
    v35 = a4;
    v36 = a5;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ===> Protection from HT20 Disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_handle_ht20coexist_ht20protection");
    *(_BYTE *)(v36 + 7164) = 0;
    v37 = *(_WORD *)(v35 + 14);
    *(_BYTE *)(v35 + 9) = 0;
    *(_WORD *)(v35 + 14) = v37 | 0x40;
  }
  return 0;
}
