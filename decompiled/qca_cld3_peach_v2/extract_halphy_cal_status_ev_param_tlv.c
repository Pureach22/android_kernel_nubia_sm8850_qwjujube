__int64 __fastcall extract_halphy_cal_status_ev_param_tlv(
        __int64 a1,
        __int64 *a2,
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
  __int64 v11; // x20
  __int64 (*v13)(void); // x8
  int v14; // w8
  __int16 v15; // w8
  int v16; // w9
  __int16 v17; // w8
  int v18; // w9
  __int16 v19; // w8
  int v20; // w9
  __int16 v21; // w8
  int v22; // w9
  __int16 v23; // w8
  int v24; // w9
  __int16 v25; // w8
  int v26; // w9
  __int16 v27; // w8
  int v28; // w9
  __int16 v29; // w8
  int v30; // w9
  __int16 v31; // w8
  int v32; // w9

  if ( a2 )
  {
    v11 = *a2;
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
    if ( *((_DWORD *)v13 - 1) != -2112860426 )
      __break(0x8228u);
    *(_DWORD *)a3 = v13();
    v14 = *(_DWORD *)(v11 + 8);
    if ( v14 )
      LOWORD(v14) = *(_DWORD *)(v11 + 12) != 0;
    v15 = *(_WORD *)(a3 + 4) & 0xFFFE | v14;
    *(_WORD *)(a3 + 4) = v15;
    v16 = *(_DWORD *)(v11 + 8);
    if ( v16 )
      LOWORD(v16) = 2 * (*(_DWORD *)(v11 + 12) != 0);
    v17 = v16 | v15 & 0xFFFD;
    *(_WORD *)(a3 + 4) = v17;
    v18 = *(_DWORD *)(v11 + 8);
    if ( v18 )
      LOWORD(v18) = 4 * (*(_DWORD *)(v11 + 12) != 0);
    v19 = v18 | v17 & 0xFFFB;
    *(_WORD *)(a3 + 4) = v19;
    v20 = *(_DWORD *)(v11 + 8);
    if ( v20 )
      LOWORD(v20) = 8 * (*(_DWORD *)(v11 + 12) != 0);
    v21 = v20 | v19 & 0xFFF7;
    *(_WORD *)(a3 + 4) = v21;
    v22 = *(_DWORD *)(v11 + 8);
    if ( v22 )
      LOWORD(v22) = 16 * (*(_DWORD *)(v11 + 12) != 0);
    v23 = v22 | v21 & 0xFFEF;
    *(_WORD *)(a3 + 4) = v23;
    v24 = *(_DWORD *)(v11 + 8);
    if ( v24 )
      LOWORD(v24) = 32 * (*(_DWORD *)(v11 + 12) != 0);
    v25 = v24 | v23 & 0xFFDF;
    *(_WORD *)(a3 + 4) = v25;
    v26 = *(_DWORD *)(v11 + 8);
    if ( v26 )
      LOWORD(v26) = (*(_DWORD *)(v11 + 12) != 0) << 6;
    v27 = v26 | v25 & 0xFFBF;
    *(_WORD *)(a3 + 4) = v27;
    v28 = *(_DWORD *)(v11 + 8);
    if ( v28 )
      LOWORD(v28) = (*(_DWORD *)(v11 + 12) != 0) << 7;
    v29 = v28 | v27 & 0xFF7F;
    *(_WORD *)(a3 + 4) = v29;
    v30 = *(_DWORD *)(v11 + 8);
    if ( v30 )
      LOWORD(v30) = (*(_DWORD *)(v11 + 12) != 0) << 8;
    v31 = v30 | v29 & 0xFEFF;
    *(_WORD *)(a3 + 4) = v31;
    v32 = *(_DWORD *)(v11 + 8);
    if ( v32 )
      LOWORD(v32) = (*(_DWORD *)(v11 + 12) != 0) << 9;
    *(_WORD *)(a3 + 4) = v32 | v31 & 0xFDFF;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid get halphy cal status event",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_halphy_cal_status_ev_param_tlv");
    return 4;
  }
}
