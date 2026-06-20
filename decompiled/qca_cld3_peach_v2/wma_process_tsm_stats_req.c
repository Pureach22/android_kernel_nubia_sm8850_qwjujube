__int64 __fastcall wma_process_tsm_stats_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w21
  __int64 *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x22
  void (**v23)(void); // x8
  void (*v24)(void); // x8
  __int64 v25; // x8
  __int64 v26; // x8
  _DWORD *v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  _DWORD *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  int v40; // w9
  __int16 v41; // w10
  __int16 v42; // w11
  __int16 v43; // w12
  __int16 v44; // w8
  __int16 v45; // w10
  int v46; // w8
  __int16 v47; // w10
  __int64 result; // x0
  _WORD v49[2]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v50; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v51; // [xsp+10h] [xbp-20h]
  __int64 v52; // [xsp+18h] [xbp-18h] BYREF
  int v53; // [xsp+20h] [xbp-10h]
  __int64 v54; // [xsp+28h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a2 + 4);
  v51 = 0;
  v52 = 0;
  v50 = 0;
  v49[0] = 0;
  v53 = 0;
  context = _cds_get_context(71, (__int64)"wma_process_tsm_stats_req", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_tx_delay");
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v31, v32, v33, v34, v35, v36, v37, v38, "cdp_tx_delay_hist");
    goto LABEL_25;
  }
  v22 = context;
  if ( *context && (v23 = *(void (***)(void))(*context + 144)) != nullptr )
  {
    v24 = *v23;
    if ( v24 )
    {
      if ( *((_DWORD *)v24 - 1) != 46271851 )
        __break(0x8228u);
      v24();
    }
    v25 = *v22;
    if ( !*v22 )
      goto LABEL_18;
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_tx_delay");
    v25 = *v22;
    if ( !*v22 )
      goto LABEL_18;
  }
  v26 = *(_QWORD *)(v25 + 144);
  if ( v26 )
  {
    v27 = *(_DWORD **)(v26 + 8);
    if ( v27 )
    {
      if ( *(v27 - 1) != 993153776 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 *, _QWORD, __int64 *, _QWORD))v27)(v22, 0, &v52, v12);
    }
    v28 = *v22;
    if ( !*v22 )
      goto LABEL_25;
    goto LABEL_19;
  }
LABEL_18:
  qdf_trace_msg(0x45u, 1u, "%s invalid instance", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_tx_delay_hist");
  v28 = *v22;
  if ( !*v22 )
  {
LABEL_25:
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_tx_packet_count");
    goto LABEL_26;
  }
LABEL_19:
  v29 = *(_QWORD *)(v28 + 144);
  if ( !v29 )
    goto LABEL_25;
  v30 = *(_DWORD **)(v29 + 16);
  if ( v30 )
  {
    if ( *(v30 - 1) != -897104896 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64 *, _QWORD, __int16 *, _WORD *, _QWORD))v30)(v22, 0, &v50, v49, v12);
  }
LABEL_26:
  v39 = _qdf_mem_malloc(0x38u, "wma_process_tsm_stats_req", 4123);
  if ( v39 )
  {
    v40 = *(_DWORD *)(a2 + 5);
    v41 = *(_WORD *)(a2 + 9);
    v42 = WORD2(v51);
    v43 = v52;
    *(_WORD *)(v39 + 24) = WORD1(v52);
    v44 = WORD2(v52);
    *(_WORD *)(v39 + 16) = v41;
    *(_QWORD *)(v39 + 48) = a2;
    *(_WORD *)(v39 + 26) = v44;
    v45 = HIWORD(v52);
    *(_DWORD *)(v39 + 8) = 16;
    *(_DWORD *)(v39 + 12) = v40;
    *(_WORD *)(v39 + 20) = v42;
    *(_WORD *)(v39 + 28) = v45;
    v46 = v51;
    LOWORD(v40) = v49[0];
    v47 = v50;
    *(_WORD *)(v39 + 22) = v43;
    *(_DWORD *)(v39 + 32) = v46;
    *(_WORD *)(v39 + 36) = v40;
    *(_WORD *)(v39 + 38) = v47;
    wma_send_msg(a1, 4261, v39, 0);
    result = 0;
  }
  else
  {
    _qdf_mem_free(a2);
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
