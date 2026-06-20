__int64 __fastcall p2p_cancel_tx_frame_by_roc(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v21; // x26
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _QWORD *v62[2]; // [xsp+0h] [xbp-10h] BYREF

  v62[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v62[0] = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: Start to find tx ctx, p2p soc_obj:%pK, cookie:%llx",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "p2p_find_tx_ctx_by_roc",
    a1,
    a2);
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 32), v62) )
  {
    while ( v62[0][4] != a2 )
    {
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 32), v62[0], v62) )
        goto LABEL_2;
    }
    v21 = v62[0];
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: find tx ctx, cookie:%llx",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_find_tx_ctx_by_roc",
      a2);
    while ( v21 )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: tx_ctx:%pK",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "p2p_cancel_tx_frame_by_roc",
        v21);
      p2p_send_tx_conf((__int64)v21, 0, v30, v31, v32, v33, v34, v35, v36, v37);
      p2p_remove_tx_context((__int64)v21, v38, v39, v40, v41, v42, v43, v44, v45);
      v62[0] = nullptr;
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Start to find tx ctx, p2p soc_obj:%pK, cookie:%llx",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "p2p_find_tx_ctx_by_roc",
        a1,
        a2);
      if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 32), v62) )
        break;
      while ( v62[0][4] != a2 )
      {
        if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 32), v62[0], v62) )
          goto LABEL_2;
      }
      v21 = v62[0];
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: find tx ctx, cookie:%llx",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "p2p_find_tx_ctx_by_roc",
        a2);
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return 0;
}
