__int64 __fastcall extract_tbttoffset_update_params_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10,
        unsigned __int8 a11,
        _DWORD *a12)
{
  unsigned int v12; // w9
  __int64 v13; // x8
  int v14; // w10
  bool v15; // cc
  __int64 v17; // x9
  __int64 v18; // x9

  if ( a10 )
  {
    v12 = *(_DWORD *)(*a10 + 4LL);
    if ( v12 )
    {
      v13 = 0;
      v14 = 0;
      while ( 1 )
      {
        v14 += v12 & 1;
        if ( v14 == a11 + 1 )
          break;
        v15 = v12 > 1;
        ++v13;
        v12 >>= 1;
        if ( !v15 )
          goto LABEL_6;
      }
      *a12 = v13;
      if ( (_DWORD)v13 == 255 )
      {
        return 4;
      }
      else
      {
        a12[1] = *(_DWORD *)(a10[2] + 4 * v13);
        v17 = a10[4];
        if ( v17 )
          a12[2] = *(_DWORD *)(v17 + 4 * v13);
        v18 = a10[6];
        if ( v18 )
          a12[3] = *(_DWORD *)(v18 + 4 * v13);
        return 0;
      }
    }
    else
    {
LABEL_6:
      *a12 = 255;
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid tbtt update event buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_tbttoffset_update_params_tlv");
    return 4;
  }
}
