__int64 __fastcall util_add_bw_ind(
        __int64 a1,
        char a2,
        char a3,
        unsigned int a4,
        __int16 a5,
        _DWORD *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  char v14; // w10
  unsigned __int64 v15; // x8
  unsigned int v16; // w8
  char v17; // w9

  if ( a1 )
  {
    if ( a6 )
    {
      *(_BYTE *)a1 = -1;
      *a6 = 9;
      v14 = *(_BYTE *)(a1 + 4);
      *(_BYTE *)(a1 + 5) = a2;
      v15 = 0x400000003020100uLL >> (8 * (unsigned __int8)a4);
      *(_BYTE *)(a1 + 6) = a3;
      *(_WORD *)(a1 + 1) = -30969;
      if ( a4 >= 8 )
        LOBYTE(v15) = 0;
      *(_BYTE *)(a1 + 4) = v14 & 0xF8 | v15;
      v16 = 0;
      v17 = *(_BYTE *)(a1 + 3);
      if ( a5 )
      {
        *(_WORD *)(a1 + 7) = a5;
        *(_BYTE *)(a1 + 3) = v17 | 2;
      }
      else
      {
        *(_BYTE *)(a1 + 1) = 5;
        *(_BYTE *)(a1 + 3) = v17 & 0xFD;
        *a6 -= 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Length of bandwidth indaication element is Zero",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "util_add_bw_ind");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Pointer to bandwidth indiaction element is NULL",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "util_add_bw_ind");
    return 29;
  }
  return v16;
}
