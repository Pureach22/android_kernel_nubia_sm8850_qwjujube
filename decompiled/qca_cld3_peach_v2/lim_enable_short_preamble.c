__int64 __fastcall lim_enable_short_preamble(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x22
  __int64 v14; // x21
  char v15; // w20
  const char *v16; // x2
  __int16 v17; // w8

  v12 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v12 + 1298) == 1 && *(_BYTE *)(v12 + 5603) == 1 && *(_DWORD *)(a4 + 88) == 1 )
  {
    if ( a2 )
    {
      if ( !*(_BYTE *)(a4 + 7160) )
      {
        v13 = a4;
        v14 = a3;
        v15 = 1;
        v16 = "%s: ===> Short Preamble Enabled";
LABEL_9:
        qdf_trace_msg(0x35u, 8u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "lim_enable_short_preamble");
        *(_BYTE *)(v13 + 7160) = v15;
        v17 = *(_WORD *)(v14 + 14);
        *(_BYTE *)(v14 + 1) = v15;
        *(_WORD *)(v14 + 14) = v17 | 2;
      }
    }
    else if ( *(_BYTE *)(a4 + 7160) == 1 )
    {
      v13 = a4;
      v14 = a3;
      v15 = 0;
      v16 = "%s: ===> Short Preamble Disabled";
      goto LABEL_9;
    }
  }
  return 0;
}
