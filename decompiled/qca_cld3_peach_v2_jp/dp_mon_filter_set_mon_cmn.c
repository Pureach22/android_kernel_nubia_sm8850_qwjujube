__int64 __fastcall dp_mon_filter_set_mon_cmn(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x8
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  __int64 v8; // x10
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x10
  __int64 v13; // x20
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 (*v25)(void); // x8
  int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 (*v37)(void); // x8

  v3 = *(_QWORD *)(a2 + 4) & 0xFFFFFFFFFFFFD000LL | 0x207F;
  v4 = *(_QWORD *)(a1 + 95560) + 36864LL;
  *(_QWORD *)(a2 + 4) = v3;
  v5 = v3 & 0xFFFFFFFFFFFFBFFFLL | ((unsigned __int64)(*(_BYTE *)(v4 + 208) & 1) << 14);
  *(_QWORD *)(a2 + 4) = v5;
  v6 = v5 & 0xFFFFFFFFFFFEF07FLL | ((((unsigned __int64)*(unsigned __int8 *)(v4 + 208) >> 1) & 1) << 16);
  *(_QWORD *)(a2 + 4) = v6;
  v7 = v6 & 0xFFFF0000FFFFFFFFLL | ((unsigned __int64)*(unsigned __int16 *)(v4 + 210) << 32);
  v8 = *(_QWORD *)(a2 + 12);
  *(_QWORD *)(a2 + 4) = v7;
  v9 = v8 & 0xFFFFFFFFFFFF0000LL | *(unsigned __int16 *)(v4 + 212);
  *(_QWORD *)(a2 + 12) = v9;
  v10 = v9 & 0xFFFF0000FFFFFFFFLL | ((unsigned __int64)*(unsigned __int16 *)(v4 + 214) << 32);
  *(_QWORD *)(a2 + 12) = v10;
  v11 = v7 & 0xFFFFFFFFFFFFLL | ((unsigned __int64)*(unsigned __int16 *)(v4 + 216) << 48);
  *(_QWORD *)(a2 + 4) = v11;
  v12 = v10 & 0xFFFFFFFF0000FFFFLL | ((unsigned __int64)*(unsigned __int16 *)(v4 + 218) << 16);
  *(_QWORD *)(a2 + 12) = v12;
  LOWORD(v4) = *(_WORD *)(v4 + 220);
  *(_QWORD *)(a2 + 4) = v11 & 0xFFFFFFFFFFDFFFFFLL;
  *(_QWORD *)(a2 + 12) = v12 & 0xFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int16)v4 << 48);
  v13 = *(_QWORD *)(a1 + 8);
  result = hal_get_target_type(*(__int64 **)(v13 + 1128));
  if ( (unsigned int)result <= 0x2B && ((1LL << result) & 0xD2480000000LL) != 0 )
  {
    *(_QWORD *)(a2 + 4) &= 0xFFFFFFFFFFFFFF8DLL;
    v23 = *(_QWORD *)(v13 + 1128);
    if ( v23 && (v24 = *(_QWORD *)(v23 + 74392)) != 0 )
    {
      v25 = *(__int64 (**)(void))(v24 + 1008);
      if ( *((_DWORD *)v25 - 1) != -605791253 )
        __break(0x8228u);
      v26 = v25();
    }
    else
    {
      qdf_trace_msg(
        0x46u,
        2u,
        "%s: hal handle is NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hal_rx_msdu_end_wmask_get");
      v26 = 0;
    }
    *(_DWORD *)(a2 + 72) = v26;
    v35 = *(_QWORD *)(v13 + 1128);
    if ( v35 && (v36 = *(_QWORD *)(v35 + 74392)) != 0 )
    {
      v37 = *(__int64 (**)(void))(v36 + 1016);
      if ( *((_DWORD *)v37 - 1) != -605791253 )
        __break(0x8228u);
      result = v37();
    }
    else
    {
      qdf_trace_msg(
        0x46u,
        2u,
        "%s: hal handle is NULL",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hal_rx_mpdu_start_wmask_get");
      result = 0;
    }
    *(_DWORD *)(a2 + 64) = result;
  }
  return result;
}
