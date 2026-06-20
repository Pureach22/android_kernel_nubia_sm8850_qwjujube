__int64 __fastcall dp_mon_filter_setup_tx_mon_mode_2_0(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  int v21; // w9
  void (__fastcall *v22)(_QWORD); // x8
  char v23; // w11
  char v24; // w12
  char v25; // w9
  char v26; // w10
  const char *v27; // x2
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int128 v37; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v38; // [xsp+10h] [xbp-A0h]
  _QWORD src[19]; // [xsp+18h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(src, 0, 144);
  if ( !a1 )
  {
    v27 = "%s: pdev Context is null";
LABEL_11:
    result = qdf_trace_msg(0x73u, 2u, v27, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_setup_tx_mon_mode_2_0");
    goto LABEL_16;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v27 = "%s: Soc Context is null";
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(a1 + 96456);
  if ( !v9 )
  {
    v27 = "%s: Monitor pdev context is null";
    goto LABEL_11;
  }
  v10 = v9 + 36864;
  BYTE4(src[17]) = *(_BYTE *)(v9 + 39336) != 0;
  qdf_mem_set((char *)&src[11] + 4, 4u, 0);
  qdf_mem_set(&src[12], 0xCu, 0);
  qdf_mem_set((char *)&src[13] + 4, 0x14u, 0);
  *(_DWORD *)((char *)&src[16] + 2) = 65537;
  HIDWORD(src[11]) |= 0xC7u;
  HIWORD(src[16]) = 1;
  src[12] |= 0x3C03BFC380076FDuLL;
  v20 = *(unsigned __int8 *)(v10 + 2473);
  LODWORD(v38) = 0;
  v37 = 0u;
  v21 = v20 & 7 | (BYTE3(src[17]) << 24) | (v20 << 6) | (8 * (v20 & 7));
  v22 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 1128LL) + 74392LL) + 1712LL);
  LODWORD(src[17]) = v21 | 0xFFFE00;
  if ( v22 )
  {
    if ( *((_DWORD *)v22 - 1) != 251140989 )
      __break(0x8228u);
    v22(&v37);
    v23 = v38;
    v24 = BYTE1(v38);
    HIDWORD(src[13]) = v37;
    LOBYTE(v22) = BYTE2(v38);
    LOWORD(src[14]) = WORD2(v37);
    v25 = BYTE14(v37);
    *(_QWORD *)((char *)&src[14] + 2) = *(_QWORD *)((char *)&v37 + 6);
    v26 = HIBYTE(v37);
  }
  else
  {
    v25 = -1;
    v23 = -1;
    *(_QWORD *)((char *)&src[14] + 2) = -1;
    v24 = -1;
    *(_QWORD *)((char *)&src[13] + 4) = -1;
    v26 = -1;
  }
  BYTE2(src[15]) = v25;
  BYTE3(src[15]) = v26;
  BYTE4(src[15]) = v23;
  BYTE5(src[15]) = v24;
  LOBYTE(src[16]) = (_BYTE)v22;
  qdf_trace_msg(0x73u, 8u, "TX MON RING TLV FILTER CONFIG:", v12, v13, v14, v15, v16, v17, v18, v19, v37, v38);
  qdf_trace_msg(0x73u, 8u, "[Mode %d]: Valid: %d", v29, v30, v31, v32, v33, v34, v35, v36, 0, BYTE4(src[17]));
  if ( BYTE4(src[17]) == 1 )
    dp_tx_mon_filter_show_filter(src);
  result = (__int64)memcpy((void *)(**(_QWORD **)(v10 + 2464) + 576LL), src, 0x90u);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
