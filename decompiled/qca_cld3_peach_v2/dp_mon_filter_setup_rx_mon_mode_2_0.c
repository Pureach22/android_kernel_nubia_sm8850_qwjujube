__int64 __fastcall dp_mon_filter_setup_rx_mon_mode_2_0(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  unsigned __int64 v11; // x8
  __int64 v12; // x13
  __int64 v13; // x12
  __int64 v14; // x14
  __int64 v15; // x15
  __int64 v16; // x17
  __int64 v17; // x10
  unsigned __int64 v18; // x8
  const char *v19; // x2
  __int64 result; // x0
  _QWORD src[19]; // [xsp+8h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(src, 0, 144);
  if ( !a1 )
  {
    v19 = "%s: pdev Context is null";
LABEL_9:
    result = qdf_trace_msg(0x73u, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_setup_rx_mon_mode_2_0");
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v19 = "%s: Soc Context is null";
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(a1 + 96456);
  if ( !v9 )
  {
    v19 = "%s: mon_pdev Context is null";
    goto LABEL_9;
  }
  v10 = v9 + 36864;
  v11 = *(unsigned __int8 *)(v9 + 37072);
  v12 = *(unsigned __int16 *)(v10 + 220);
  v13 = *(unsigned __int16 *)(v10 + 212);
  v14 = *(unsigned __int16 *)(v10 + 214);
  v15 = *(unsigned __int16 *)(v10 + 218);
  WORD1(src[3]) = *(_WORD *)(v10 + 210);
  v16 = *(unsigned __int16 *)(v10 + 216);
  HIWORD(src[3]) = v13;
  LOWORD(src[4]) = v15;
  WORD1(src[4]) = v14;
  LOBYTE(src[0]) = 1;
  WORD2(src[9]) = 1;
  v17 = v13 | (v14 << 32);
  WORD2(src[3]) = v16;
  *(_QWORD *)((char *)&src[1] + 4) = (v12 << 48) | (v15 << 16) | v17;
  WORD2(src[4]) = v12;
  *(_QWORD *)((char *)src + 4) = (((v11 >> 1) & 1) << 16)
                               | ((v11 & 1) << 14)
                               | ((unsigned __int64)WORD1(src[3]) << 32)
                               | (v16 << 48)
                               | 0x3FBF;
  *(_DWORD *)((char *)&src[9] + 6) = 1023;
  if ( (v11 & 2) != 0 )
  {
    *(_QWORD *)((char *)&src[1] + 4) = v17 | 0xFFFF0000FFFF0000LL;
    WORD2(src[3]) = -1;
    LOWORD(src[4]) = -1;
    WORD2(src[4]) = -1;
    v18 = ((((v11 >> 1) & 1) << 16) | ((v11 & 1) << 14)) & 0xFFFFFFD47FBFLL
        | ((unsigned __int64)WORD1(src[3]) << 32) & 0xFFFFFFD67FBFLL
        | 0x3FBF
        | ((v11 & 1) << 17) & 0xFFFFFFD67FBFLL
        | 0xFFFF000000090000LL;
  }
  else
  {
    v18 = ((((v11 >> 1) & 1) << 16) | ((v11 & 1) << 14)) & 0xFFFFFFFFFFD47FBFLL
        | ((unsigned __int64)WORD1(src[3]) << 32)
        | (v16 << 48)
        | 0x3FBF
        | ((v11 & 1) << 17) & 0xFFFFFFFFFFD67FBFLL;
  }
  *(_QWORD *)((char *)src + 4) = v18;
  dp_mon_filter_show_rx_filter_be(0, src);
  result = (__int64)memcpy((void *)(**(_QWORD **)(v10 + 2464) + 432LL), src, 0x90u);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
