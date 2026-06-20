__int64 __fastcall util_find_mlie_by_variant(__int64 a1, unsigned __int64 a2, _QWORD *a3, unsigned __int64 *a4, int a5)
{
  __int64 result; // x0
  unsigned __int64 v9; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 v20; // x9
  unsigned int v21; // w10
  unsigned int v22; // w19
  unsigned __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF

  result = 29;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && a3 && a4 )
  {
    if ( a5 <= 4 )
    {
      v9 = 0;
      v23 = 0;
      v24[0] = 0;
      *a3 = 0;
      *a4 = 0;
      while ( 1 )
      {
        result = util_find_mlie((unsigned __int8 *)(a1 + v9), a2 - v9, v24, &v23);
        if ( (_DWORD)result )
          goto LABEL_23;
        if ( !v24[0] )
        {
          result = 0;
          goto LABEL_23;
        }
        v20 = v23;
        if ( !v23 )
          break;
        if ( v23 < 5 || *(unsigned __int8 *)v24[0] != 255 || *(_BYTE *)(v24[0] + 2LL) != 107 )
        {
          v22 = 4;
LABEL_22:
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Unable to get Multi-link element variant",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "util_find_mlie_by_variant");
          result = v22;
          goto LABEL_23;
        }
        v21 = *(_WORD *)(v24[0] + 3LL) & 7;
        if ( v21 >= 5 )
        {
          v22 = 27;
          goto LABEL_22;
        }
        if ( v21 == a5 )
        {
          result = 0;
          *a3 = v24[0];
          *a4 = v20;
          goto LABEL_23;
        }
        v9 = v24[0] + v23 - a1;
        if ( v9 >= a2 )
        {
          result = 4;
          goto LABEL_23;
        }
      }
      v22 = 29;
      goto LABEL_22;
    }
    result = 27;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
