__int64 __fastcall populate_dot11f_wpa(__int64 a1, unsigned __int16 *a2, _WORD *a3)
{
  int v3; // w8
  unsigned int v4; // w11
  unsigned __int16 *v5; // x9
  int v6; // w10
  bool v7; // vf
  __int64 result; // x0
  int v9; // w4
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v3 = *a2;
  if ( !*a2 )
    return 0;
  v4 = 0;
  v5 = a2 + 1;
  v6 = *((unsigned __int8 *)a2 + 3) + 2;
  while ( *((unsigned __int8 *)v5 + v4) != 221 )
  {
    v7 = __OFSUB__(v3, v6);
    v3 -= v6;
    if ( (v3 < 0) ^ v7 | (v3 == 0) )
      return 0;
    if ( v4 != 256 )
    {
      v6 = *((unsigned __int8 *)v5 + v4 + 1) + 2;
      v4 += v6;
      if ( v4 < 0x101 )
        continue;
    }
    goto LABEL_7;
  }
  if ( v4 >= 0x100 )
  {
LABEL_7:
    __break(0x5512u);
    return 0;
  }
  v9 = dot11f_unpack_ie_wpa(a1, (char *)v5 + v4 + 6, *((_BYTE *)v5 + v4 + 1) - 4, a3);
  result = 0;
  if ( (v9 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Parse failure in Populate Dot11fWPA (0x%08x)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "populate_dot11f_wpa");
    return 16;
  }
  return result;
}
