__int64 __fastcall populate_dot11f_he_6ghz_cap(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  int v12; // w10
  unsigned int v13; // w10
  __int16 v14; // w9
  __int16 v15; // w9
  __int16 v16; // w9
  int v17; // w10
  __int16 v18; // w10
  __int16 v19; // w9

  if ( !a2 || *(_BYTE *)(a2 + 8764) == 1 )
  {
    v11 = *(_QWORD *)(a1 + 8);
    v12 = *(unsigned __int16 *)(a3 + 1);
    *(_BYTE *)a3 = 1;
    v13 = v12 & 0xFFFFFFF8 | (*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1270LL) >> 2) & 7;
    v14 = v13 & 0xE7FF;
    *(_WORD *)(a3 + 1) = v13;
    if ( a2 )
    {
      v15 = (*(_WORD *)(a2 + 7266) << 9) & 0x1800 | v14;
      *(_WORD *)(a3 + 1) = v15;
      v16 = v15 & 0xFFC7;
      v17 = (*(_DWORD *)(a2 + 7268) >> 20) & 0x38;
    }
    else
    {
      v18 = (*(_WORD *)(v11 + 1268) << 9) & 0x1800 | v14;
      *(_WORD *)(a3 + 1) = v18;
      LOWORD(v17) = v18 & 0xFFC7;
      v16 = 8 * (*(_BYTE *)(v11 + 2673) & 7);
    }
    v19 = v17 | v16;
    *(_WORD *)(a3 + 1) = v19;
    *(_WORD *)(a3 + 1) = v19 & 0x18FF | ((*(_BYTE *)(v11 + 2674) & 7) << 8);
    lim_log_he_6g_cap(a4, a5, a6, a7, a8, a9, a10, a11, a1, a3);
  }
  return 0;
}
