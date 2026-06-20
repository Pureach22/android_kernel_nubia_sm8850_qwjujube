__int64 __fastcall lim_enable_ht_obss_protection(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
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
  int v14; // w20
  int v15; // w19
  __int64 v16; // x22
  __int64 v17; // x23
  char v18; // w24
  const char *v19; // x2
  __int64 v20; // x19
  __int64 v21; // x21
  __int64 v22; // x21

  if ( !*(_BYTE *)(a5 + 155) )
    return 0;
  v13 = *(_DWORD *)(a5 + 88);
  v14 = a3;
  v15 = a2;
  if ( a3 )
  {
    if ( v13 == 1 )
      goto LABEL_4;
LABEL_12:
    if ( a2 )
    {
      if ( *(_BYTE *)(a5 + 7168) )
        return 0;
      v20 = a4;
      v21 = a5;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: =>obss protection enabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_enable_ht_obss_protection");
      *(_BYTE *)(v21 + 7168) = 1;
    }
    else
    {
      if ( *(_BYTE *)(a5 + 7168) != 1 )
        return 0;
      v20 = a4;
      v22 = a5;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ===> obss Protection disabled",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_enable_ht_obss_protection");
      *(_BYTE *)(v22 + 7168) = 0;
    }
    *(_WORD *)(v20 + 14) |= 0x400u;
    return 0;
  }
  if ( v13 != 1 )
  {
    if ( *(__int16 *)(a1 + 8880) < 0 )
      goto LABEL_12;
LABEL_11:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: protection from Obss is disabled",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_enable_ht_obss_protection");
    return 0;
  }
  if ( (*(__int16 *)(a5 + 432) & 0x80000000) == 0 )
    goto LABEL_11;
LABEL_4:
  if ( a2 )
  {
    if ( *(_BYTE *)(a5 + 7168) )
      goto LABEL_18;
    v16 = a4;
    v17 = a5;
    v18 = 1;
    v19 = "%s: =>obss protection enabled";
  }
  else
  {
    if ( *(_BYTE *)(a5 + 7168) != 1 )
      goto LABEL_18;
    v16 = a4;
    v17 = a5;
    v18 = 0;
    v19 = "%s: ===> obss Protection disabled";
  }
  qdf_trace_msg(0x35u, 8u, v19, a6, a7, a8, a9, a10, a11, a12, a13, "lim_enable_ht_obss_protection");
  *(_BYTE *)(v17 + 7168) = v18;
  a5 = v17;
  *(_WORD *)(v16 + 14) |= 0x400u;
LABEL_18:
  if ( !(v14 | v15) )
    *(_BYTE *)(a5 + 1227) = 0;
  return 0;
}
