__int64 __fastcall lim_enable_ht_rifs_protection(
        __int64 a1,
        char a2,
        char a3,
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
  __int64 v13; // x20
  __int16 v15; // w8
  __int16 v16; // w8
  __int16 v18; // w9

  if ( !*(_BYTE *)(a5 + 155) )
    return 0;
  if ( !a3 )
  {
    if ( *(_DWORD *)(a5 + 88) == 1 )
    {
      if ( (*(_WORD *)(a5 + 432) & 0x4000) != 0 )
        goto LABEL_3;
    }
    else if ( (*(_WORD *)(a1 + 8880) & 0x4000) != 0 )
    {
      goto LABEL_3;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: protection from Rifs is disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_enable_ht_rifs_protection");
    return 0;
  }
LABEL_3:
  if ( a2 )
  {
    if ( *(_BYTE *)(a5 + 7166) == 1 )
    {
      v13 = a4;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ===> Rifs Protection Enabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_enable_ht_rifs_protection");
      *(_BYTE *)(a5 + 7166) = 0;
      v15 = *(_WORD *)(v13 + 14);
      *(_BYTE *)(v13 + 12) = 0;
      v16 = v15 | 0x100;
LABEL_11:
      *(_WORD *)(v13 + 14) = v16;
    }
  }
  else if ( !*(_BYTE *)(a5 + 7166) )
  {
    v13 = a4;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s:  => Rifs protection Disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_enable_ht_rifs_protection");
    *(_BYTE *)(a5 + 7166) = 1;
    v18 = *(_WORD *)(v13 + 14);
    *(_BYTE *)(v13 + 12) = 1;
    v16 = v18 | 0x100;
    goto LABEL_11;
  }
  return 0;
}
