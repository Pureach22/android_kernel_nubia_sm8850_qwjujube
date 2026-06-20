__int64 __fastcall lim_enable_ht_protection_from11g(
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
  const char *v15; // x2
  int v16; // w8
  unsigned int v18; // w22
  __int64 v19; // x20
  int v20; // w9
  int v21; // w8
  int v22; // w8
  unsigned int v24; // w22
  __int64 v25; // x20
  __int16 v26; // w8
  int v27; // w8
  __int64 v29; // x20
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x20

  if ( !*(_BYTE *)(a5 + 155) )
    return 0;
  v13 = *(_DWORD *)(a5 + 88);
  if ( !(_BYTE)a3 )
  {
    if ( v13 == 1 )
    {
      if ( (*(_WORD *)(a5 + 432) & 0x400) != 0 )
        goto LABEL_8;
    }
    else if ( (*(_WORD *)(a1 + 8880) & 0x400) != 0 )
    {
      goto LABEL_25;
    }
    v15 = "%s: protection from 11g is disabled";
    goto LABEL_24;
  }
  if ( v13 == 1 )
  {
    if ( (*(_WORD *)(a5 + 432) & 4) == 0 )
    {
      v15 = "%s: overlap protection from 11g is disabled";
LABEL_24:
      qdf_trace_msg(0x35u, 8u, v15, a6, a7, a8, a9, a10, a11, a12, a13, "lim_enable_ht_protection_from11g");
      return 0;
    }
LABEL_8:
    v16 = 1;
    if ( !a2 )
      goto LABEL_9;
LABEL_26:
    if ( !v16 )
      goto LABEL_34;
    if ( (_BYTE)a3 )
    {
      v20 = *(_DWORD *)(a5 + 280) | 2;
      v21 = 1;
      *(_BYTE *)(a5 + 1227) = 1;
      if ( v20 == 3 )
      {
LABEL_33:
        v24 = a3;
        v25 = a5;
        lim_enable_ht_rifs_protection(a1, 1, a3, a4, a5);
        lim_enable_ht_obss_protection(a1, 1, v24, a4, v25);
        a5 = v25;
LABEL_34:
        if ( *(_BYTE *)(a5 + 7163) )
        {
          if ( *(_BYTE *)(a5 + 1227) != 1 )
            return 0;
          v26 = *(_WORD *)(a4 + 14);
        }
        else
        {
          *(_BYTE *)(a5 + 7163) = 1;
          v26 = *(_WORD *)(a4 + 14);
          *(_BYTE *)(a4 + 8) = 1;
        }
LABEL_48:
        *(_WORD *)(a4 + 14) = v26 | 0x20;
        return 0;
      }
    }
    else
    {
      v22 = *(_DWORD *)(a5 + 280);
      *(_BYTE *)(a5 + 441) = 1;
      if ( v22 == 3 )
        goto LABEL_34;
      a3 = 0;
      v21 = 3;
    }
    *(_DWORD *)(a5 + 280) = v21;
    goto LABEL_33;
  }
LABEL_25:
  v16 = 0;
  if ( a2 )
    goto LABEL_26;
LABEL_9:
  if ( *(_BYTE *)(a5 + 7163) != 1 )
    return 0;
  if ( !v16 )
  {
LABEL_47:
    v32 = a5;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ===> Protection from 11G Disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_enable_ht_protection_from11g");
    *(_BYTE *)(v32 + 7163) = 0;
    v26 = *(_WORD *)(a4 + 14);
    *(_BYTE *)(a4 + 8) = 0;
    goto LABEL_48;
  }
  if ( !(_BYTE)a3 )
  {
    v27 = *(unsigned __int8 *)(a5 + 437);
    *(_BYTE *)(a5 + 441) = 0;
    if ( !v27 )
    {
      v29 = a5;
      lim_enable_ht_obss_protection(a1, 0, 0, a4, a5);
      if ( *(_BYTE *)(v29 + 1225) || *(_BYTE *)(v29 + 1227) || *(_BYTE *)(v29 + 1231) || *(_BYTE *)(v29 + 1233) )
      {
        v30 = a1;
        v31 = 1;
        *(_DWORD *)(v29 + 280) = 1;
      }
      else
      {
        v30 = a1;
        v31 = 0;
        *(_DWORD *)(v29 + 280) = 0;
      }
      lim_enable_ht_rifs_protection(v30, v31, 0, a4, v29);
      a5 = v29;
    }
LABEL_45:
    if ( *(_BYTE *)(a5 + 1227) )
      return 0;
    goto LABEL_46;
  }
  if ( !*(_BYTE *)(a5 + 440) )
    *(_BYTE *)(a5 + 1227) = 0;
  if ( *(_BYTE *)(a5 + 1225) || *(_BYTE *)(a5 + 1231) || *(_BYTE *)(a5 + 1233) || *(_DWORD *)(a5 + 280) != 1 )
    goto LABEL_45;
  v18 = a3;
  v19 = a5;
  lim_enable_ht_rifs_protection(a1, 0, a3, a4, a5);
  lim_enable_ht_obss_protection(a1, 0, v18, a4, v19);
  a5 = v19;
  if ( !*(_BYTE *)(v19 + 445) || !*(_BYTE *)(v19 + 160) )
  {
    *(_DWORD *)(v19 + 280) = 0;
    if ( *(_BYTE *)(v19 + 1227) )
      return 0;
LABEL_46:
    if ( *(_BYTE *)(a5 + 441) )
      return 0;
    goto LABEL_47;
  }
  *(_DWORD *)(v19 + 280) = 2;
  if ( !*(_BYTE *)(v19 + 1227) )
    goto LABEL_46;
  return 0;
}
