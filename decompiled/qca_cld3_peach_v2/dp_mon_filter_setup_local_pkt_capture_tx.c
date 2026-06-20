void *__fastcall dp_mon_filter_setup_local_pkt_capture_tx(
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
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  void (__fastcall *v14)(_QWORD); // x8
  char v15; // w11
  char v16; // w12
  char v17; // w9
  char v18; // w10
  int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  void *result; // x0
  __int128 v37; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v38; // [xsp+10h] [xbp-A0h]
  _QWORD src[19]; // [xsp+18h] [xbp-98h] BYREF

  src[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 96456);
  v10 = v9 + 37074;
  memset(src, 0, 144);
  *(_DWORD *)(v9 + 39352) = 1;
  *(_DWORD *)(v9 + 41928) = 1;
  *(_WORD *)(v9 + 39336) = 1025;
  v11 = *(_QWORD *)(a1 + 8);
  LODWORD(src[17]) = 0x1000000;
  HIDWORD(src[11]) = 199;
  v12 = *(_QWORD *)(v11 + 1128);
  BYTE4(src[17]) = 1;
  LODWORD(v38) = 0;
  v13 = *(_QWORD *)(v12 + 74392);
  v37 = 0u;
  src[12] = 0x3C03BFC380076FDLL;
  v14 = *(void (__fastcall **)(_QWORD))(v13 + 1712);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 251140989 )
      __break(0x8228u);
    v14(&v37);
    v15 = v38;
    v16 = BYTE1(v38);
    HIDWORD(src[13]) = v37;
    LOBYTE(v14) = BYTE2(v38);
    LOWORD(src[14]) = WORD2(v37);
    v17 = BYTE14(v37);
    *(_QWORD *)((char *)&src[14] + 2) = *(_QWORD *)((char *)&v37 + 6);
    v18 = HIBYTE(v37);
  }
  else
  {
    v17 = -1;
    v15 = -1;
    *(_QWORD *)((char *)&src[14] + 2) = -1;
    v16 = -1;
    *(_QWORD *)((char *)&src[13] + 4) = -1;
    v18 = -1;
  }
  BYTE2(src[15]) = v17;
  BYTE3(src[15]) = v18;
  BYTE4(src[15]) = v15;
  BYTE5(src[15]) = v16;
  LOBYTE(src[16]) = (_BYTE)v14;
  if ( *(_WORD *)v10 )
  {
    v19 = 18882052;
    WORD1(src[16]) = -1;
    LODWORD(src[17]) = 18882052;
    if ( !*(_WORD *)(v10 + 2) )
      goto LABEL_9;
    goto LABEL_8;
  }
  v19 = 0x1000000;
  if ( *(_WORD *)(v10 + 2) )
  {
LABEL_8:
    HIWORD(src[16]) = -1;
    v19 |= 0x41E020u;
    LODWORD(src[17]) = v19;
  }
LABEL_9:
  if ( *(_WORD *)(v10 + 4) )
  {
    WORD2(src[16]) = -1;
    LODWORD(src[17]) = v19 & 0xFF61FE3F | 0x9E0100;
  }
  qdf_trace_msg(0x73u, 8u, "TX MON RING TLV FILTER CONFIG:", a2, a3, a4, a5, a6, a7, a8, a9, v37, v38);
  qdf_trace_msg(0x73u, 8u, "[Mode %d]: Valid: %d", v20, v21, v22, v23, v24, v25, v26, v27, 0, 1);
  dp_tx_mon_filter_show_filter((__int64)src, v28, v29, v30, v31, v32, v33, v34, v35);
  result = memcpy((void *)(**(_QWORD **)(v10 + 2254) + 576LL), src, 0x90u);
  _ReadStatusReg(SP_EL0);
  return result;
}
