__int64 __fastcall p2p_ready_to_tx_frame(
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
  __int64 result; // x0
  _QWORD *v21; // x26
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w27
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD *v47[2]; // [xsp+0h] [xbp-10h] BYREF

  v47[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v47[0] = nullptr;
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
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 32), v47) )
    goto LABEL_2;
  while ( v47[0][4] != a2 )
  {
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 32), v47[0], v47) )
      goto LABEL_2;
  }
  v21 = v47[0];
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
  if ( !v21 )
  {
LABEL_2:
    result = 0;
  }
  else
  {
    while ( 1 )
    {
      qdf_trace_msg(0x4Eu, 8u, "%s: tx_ctx:%pK", v22, v23, v24, v25, v26, v27, v28, v29, "p2p_ready_to_tx_frame", v21);
      v30 = p2p_execute_tx_action_frame(v21);
      if ( v30 )
      {
        p2p_send_tx_conf(v21, 0);
        p2p_remove_tx_context(v21);
      }
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Start to find tx ctx, p2p soc_obj:%pK, cookie:%llx",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "p2p_find_tx_ctx_by_roc",
        a1,
        a2,
        0);
      if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 32), v47) )
        break;
      while ( v47[0][4] != a2 )
      {
        if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 32), v47[0], v47) )
          goto LABEL_15;
      }
      v21 = v47[0];
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: find tx ctx, cookie:%llx",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "p2p_find_tx_ctx_by_roc",
        a2);
      result = v30;
      if ( !v21 )
        goto LABEL_3;
    }
LABEL_15:
    result = v30;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
