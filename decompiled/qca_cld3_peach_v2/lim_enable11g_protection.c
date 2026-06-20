__int64 __fastcall lim_enable11g_protection(
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
  int v16; // w8
  unsigned int v17; // w22
  int v18; // w8
  int v19; // w8
  int v20; // w8
  unsigned int v21; // w22
  __int16 v22; // w9
  __int16 v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  __int64 v33; // x1
  __int16 v34; // w8
  __int16 v35; // w8
  int v37; // w8

  if ( !(_BYTE)a3 )
  {
    if ( *(_DWORD *)(a5 + 88) == 1 )
    {
      if ( (*(_WORD *)(a5 + 432) & 0x200) != 0 )
        goto LABEL_2;
    }
    else if ( (*(_WORD *)(a1 + 8880) & 0x200) != 0 )
    {
      goto LABEL_2;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: protection from 11b is disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_enable11g_protection");
    return 0;
  }
LABEL_2:
  if ( a2 )
  {
    v16 = *(_DWORD *)(a5 + 88);
    if ( (_BYTE)a3 && v16 == 1 )
    {
      v17 = a3;
      *(_BYTE *)(a5 + 1225) = 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: protection from olbc is enabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_handle_enable11g_protection_enabled");
      if ( *(_BYTE *)(a5 + 155) != 1 )
        goto LABEL_29;
      if ( (*(_DWORD *)(a5 + 280) | 2) == 3 )
        goto LABEL_28;
      v18 = 1;
    }
    else
    {
      if ( (_BYTE)a3
        || v16 != 1
        || (v17 = a3,
            *(_BYTE *)(a5 + 437) = 1,
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: protection from 11b is enabled",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "lim_handle_enable11g_protection_enabled"),
            *(_BYTE *)(a5 + 155) != 1)
        || *(_DWORD *)(a5 + 280) == 3 )
      {
LABEL_29:
        if ( !*(_BYTE *)(a5 + 7162) )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: => 11G Protection Enabled",
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            "lim_handle_enable11g_protection_enabled");
          *(_BYTE *)(a5 + 7162) = 1;
          v22 = *(_WORD *)(a4 + 14);
          *(_BYTE *)(a4 + 7) = 1;
          v23 = v22 | 0x10;
LABEL_47:
          *(_WORD *)(a4 + 14) = v23;
          return 0;
        }
        return 0;
      }
      v18 = 3;
    }
    *(_DWORD *)(a5 + 280) = v18;
LABEL_28:
    lim_enable_ht_rifs_protection(a1, 1, v17, a4, a5);
    lim_enable_ht_obss_protection(a1, 1, v17, a4, a5);
    goto LABEL_29;
  }
  if ( *(_BYTE *)(a5 + 7162) == 1 )
  {
    v19 = *(_DWORD *)(a5 + 88);
    if ( (_BYTE)a3 && v19 == 1 )
    {
      v20 = *(unsigned __int8 *)(a5 + 155);
      *(_BYTE *)(a5 + 1225) = 0;
      if ( v20
        && !*(_BYTE *)(a5 + 1227)
        && !*(_BYTE *)(a5 + 1231)
        && !*(_BYTE *)(a5 + 1233)
        && *(_DWORD *)(a5 + 280) == 1 )
      {
        v21 = a3;
        lim_enable_ht_rifs_protection(a1, 0, a3, a4, a5);
        lim_enable_ht_obss_protection(a1, 0, v21, a4, a5);
        if ( *(_BYTE *)(a5 + 445) && *(_BYTE *)(a5 + 160) )
          *(_DWORD *)(a5 + 280) = 2;
        else
          *(_DWORD *)(a5 + 280) = 0;
      }
    }
    else if ( !(_BYTE)a3 && v19 == 1 )
    {
      *(_BYTE *)(a5 + 437) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ===> 11B Protection Disabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_handle_11g_protection_for_11bcoexist");
      if ( !*(_BYTE *)(a5 + 441) )
      {
        lim_enable_ht_obss_protection(a1, 0, 0, a4, a5);
        if ( *(_BYTE *)(a5 + 1225) || *(_BYTE *)(a5 + 1227) || *(_BYTE *)(a5 + 1231) || *(_BYTE *)(a5 + 1233) )
        {
          *(_DWORD *)(a5 + 280) = 1;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ===> 11G Protection Disabled",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "lim_handle_11g_protection_for_11bcoexist");
          v32 = a1;
          v33 = 1;
        }
        else
        {
          v37 = *(unsigned __int8 *)(a5 + 445);
          *(_DWORD *)(a5 + 280) = 0;
          if ( v37 )
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: ===> 11G Protection Disabled",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "lim_handle_11g_protection_for_11bcoexist");
          v32 = a1;
          v33 = 0;
        }
        lim_enable_ht_rifs_protection(v32, v33, 0, a4, a5);
      }
    }
    if ( *(_DWORD *)(a5 + 88) != 1
      || !*(_BYTE *)(a5 + 1225)
      && !*(_BYTE *)(a5 + 437)
      && (qdf_trace_msg(
            0x35u,
            8u,
            "%s: ===> 11G Protection Disabled",
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            "lim_handle_11g_protection_for_11bcoexist"),
          *(_BYTE *)(a5 + 7162) = 0,
          v34 = *(_WORD *)(a4 + 14),
          *(_BYTE *)(a4 + 7) = 0,
          *(_WORD *)(a4 + 14) = v34 | 0x10,
          *(_DWORD *)(a5 + 88) != 1) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ===> 11G Protection Disabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_handle_11g_protection_for_11bcoexist");
      *(_BYTE *)(a5 + 7162) = 0;
      v35 = *(_WORD *)(a4 + 14);
      *(_BYTE *)(a4 + 7) = 0;
      v23 = v35 | 0x10;
      goto LABEL_47;
    }
  }
  return 0;
}
