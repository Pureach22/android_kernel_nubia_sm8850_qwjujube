__int64 __fastcall util_parse_bw_ind(
        _BYTE *a1,
        _BYTE *a2,
        _BYTE *a3,
        unsigned int *a4,
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
  __int64 v13; // x29
  __int64 v14; // x30
  unsigned int v15; // w8
  unsigned int v16; // w8
  __int16 v18; // w8
  __int16 v19; // w8

  if ( a1 )
  {
    *a2 = a1[5];
    *a3 = a1[6];
    v15 = (a1[4] & 7) - 1;
    if ( v15 > 3 )
      v16 = 0;
    else
      v16 = dword_B35A08[v15];
    *a4 = v16;
    if ( (a1[3] & 2) != 0 )
    {
      *(_WORD *)a5 = *(unsigned __int8 *)(a5 + 1) << 8;
      v19 = (unsigned __int8)a1[7];
      *(_WORD *)a5 = v19;
      v18 = v19 | ((unsigned __int8)a1[8] << 8);
    }
    else
    {
      v18 = 0;
    }
    *(_WORD *)a5 = v18;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Pointer to bandwidth indiaction element is NULL",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "util_parse_bw_ind",
      v13,
      v14);
    return 29;
  }
}
