__int64 __fastcall lim_update_11a_protection(
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
  __int64 result; // x0
  int v14; // w8
  int v15; // w8
  unsigned int v17; // w21
  __int64 v18; // x22
  __int64 v19; // x19
  __int64 v20; // x0
  __int64 v21; // x24
  __int64 v22; // x20
  __int64 v23; // x19
  __int64 v24; // x20
  unsigned int v25; // w1
  int v26; // w8
  unsigned int v28; // w22
  __int64 v29; // x19
  __int64 v30; // x20
  __int64 v31; // x21
  __int64 v33; // x19
  __int64 v34; // x0
  __int64 v35; // x1

  if ( !a5 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: session is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "lim_update_11a_protection");
    return 16;
  }
  if ( !(_BYTE)a3 && *(_DWORD *)(a5 + 88) == 1 && (*(_WORD *)(a5 + 432) & 0x100) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: protection from 11a is disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_update_11a_protection");
    return 0;
  }
  if ( !a2 )
  {
    if ( !*(_BYTE *)(a5 + 7161) )
      return 0;
    if ( *(_DWORD *)(a5 + 88) != 1 )
    {
      v23 = a5;
      v24 = a4;
      v25 = 8;
LABEL_23:
      qdf_trace_msg(
        0x35u,
        v25,
        "%s: ===> Protection from 11A Disabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_disable_11a_protection");
      result = 0;
      *(_BYTE *)(v24 + 6) = 0;
      *(_BYTE *)(v23 + 7161) = 0;
      goto LABEL_30;
    }
    if ( (_BYTE)a3 )
    {
      v15 = *(unsigned __int8 *)(a5 + 155);
      *(_BYTE *)(a5 + 1229) = 0;
      if ( !v15 || *(_BYTE *)(a5 + 1231) || *(_BYTE *)(a5 + 1233) || *(_DWORD *)(a1 + 12232) != 1 )
        goto LABEL_37;
      v17 = a3;
      v18 = a4;
      v19 = a5;
      lim_enable_ht_rifs_protection(a1, 0, a3, a4, a5);
      v20 = a1;
      v21 = a1;
      v22 = v18;
      lim_enable_ht_obss_protection(v20, 0, v17, v18, v19);
      a5 = v19;
      if ( *(_BYTE *)(v19 + 445) )
        *(_DWORD *)(v21 + 12232) = 2;
      else
        *(_DWORD *)(v21 + 12232) = 0;
    }
    else
    {
      *(_BYTE *)(a5 + 439) = 0;
      v22 = a4;
      v33 = a5;
      lim_enable_ht_obss_protection(a1, 0, 0, a4, a5);
      if ( *(_BYTE *)(v33 + 1229) || *(_BYTE *)(v33 + 1231) || *(_BYTE *)(v33 + 1233) )
      {
        v34 = a1;
        v35 = 1;
        *(_DWORD *)(a1 + 12232) = 1;
        *(_DWORD *)(v33 + 280) = 1;
      }
      else
      {
        v34 = a1;
        if ( *(_BYTE *)(v33 + 445) )
        {
          *(_DWORD *)(a1 + 12232) = 2;
          *(_DWORD *)(v33 + 280) = 2;
        }
        else
        {
          *(_DWORD *)(a1 + 12232) = 0;
          *(_DWORD *)(v33 + 280) = 0;
        }
        v35 = 0;
      }
      lim_enable_ht_rifs_protection(v34, v35, 0, v22, v33);
      a5 = v33;
    }
    a4 = v22;
LABEL_37:
    if ( *(_BYTE *)(a5 + 1229) || *(_BYTE *)(a5 + 439) )
      return 0;
    v23 = a5;
    v24 = a4;
    v25 = 3;
    goto LABEL_23;
  }
  if ( *(_DWORD *)(a5 + 88) != 1 || *(_BYTE *)(a5 + 155) != 1 )
    goto LABEL_27;
  if ( (_BYTE)a3 )
  {
    v14 = 1;
    *(_BYTE *)(a5 + 1229) = 1;
    if ( (*(_DWORD *)(a1 + 12232) | 2) != 3 )
      goto LABEL_26;
  }
  else
  {
    v26 = *(_DWORD *)(a5 + 280);
    *(_BYTE *)(a5 + 439) = 1;
    if ( v26 != 3 )
    {
      v14 = 3;
LABEL_26:
      *(_DWORD *)(a1 + 12232) = v14;
      *(_DWORD *)(a5 + 280) = v14;
      v28 = a3;
      v29 = a4;
      v30 = a5;
      lim_enable_ht_rifs_protection(a1, 1, a3, a4, a5);
      lim_enable_ht_obss_protection(a1, 1, v28, v29, v30);
      a5 = v30;
      a4 = v29;
    }
  }
LABEL_27:
  if ( *(_BYTE *)(a5 + 7161) )
    return 0;
  v24 = a4;
  v31 = a5;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s:  => protection from 11A Enabled",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_enable_11a_protection");
  result = 0;
  *(_BYTE *)(v24 + 6) = 1;
  *(_BYTE *)(v31 + 7161) = 1;
LABEL_30:
  *(_WORD *)(v24 + 14) |= 8u;
  return result;
}
