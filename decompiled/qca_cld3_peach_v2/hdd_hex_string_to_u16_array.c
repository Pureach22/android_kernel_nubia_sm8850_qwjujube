__int64 __fastcall hdd_hex_string_to_u16_array(
        const char *a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  unsigned int v16; // w25
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  char *v26; // x8
  unsigned int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  result = 4;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( a1 && a2 && a3 )
  {
    v16 = a4;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: str %pK intArray %pK intArrayMaxLen %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_hex_string_to_u16_array",
      a1,
      a2,
      a4);
    *a3 = 0;
    while ( *a3 < v16 )
    {
      if ( sscanf(a1, "%x", &v27) == 1 )
      {
        v25 = v27;
        *(_WORD *)(a2 + 2LL * *a3) = v27;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: s %pK val %x intArray[%d]=0x%x",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "hdd_hex_string_to_u16_array",
          a1,
          v25,
          *a3,
          *(unsigned __int16 *)(a2 + 2LL * *a3));
        ++*a3;
      }
      v26 = strchr(a1, 32);
      result = 0;
      if ( v26 )
      {
        a1 = v26 + 1;
        if ( v26 != (char *)-1LL )
          continue;
      }
      goto LABEL_12;
    }
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
