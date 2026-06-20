__int64 __fastcall p2p_process_mgmt_tx_cancel(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x1
  __int64 tx_ctx; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x9
  __int64 result; // x0
  __int64 roc_by_tx_ctx; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  __int64 v33; // [xsp+8h] [xbp-18h]
  char v34[4]; // [xsp+10h] [xbp-10h] BYREF
  char v35[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = 0;
  v34[0] = 0;
  v32 = 0;
  v33 = 0;
  if ( a1 && (v9 = a1[1]) != 0 )
  {
    tx_ctx = p2p_find_tx_ctx(*a1, v9, v35, v34);
    if ( !tx_ctx )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Failed to find tx ctx by cookie, cookie %llx",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "p2p_process_mgmt_tx_cancel",
        a1[1],
        v32,
        v33);
      roc_by_tx_ctx = p2p_find_roc_by_tx_ctx(*a1, a1[1]);
      if ( !roc_by_tx_ctx )
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: Failed to find roc by tx ctx",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "p2p_process_mgmt_tx_cancel");
        result = 4;
        goto LABEL_14;
      }
      v31 = roc_by_tx_ctx;
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: tx ctx:%llx, roc:%pK",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "p2p_process_mgmt_tx_cancel",
        a1[1],
        roc_by_tx_ctx);
      v32 = *a1;
      v33 = v31;
      goto LABEL_9;
    }
    if ( v35[0] == 1 )
    {
      v20 = *(_QWORD *)(tx_ctx + 32);
      v32 = *a1;
      v33 = v20;
      p2p_remove_tx_context(tx_ctx, v12, v13, v14, v15, v16, v17, v18, v19);
LABEL_9:
      result = p2p_process_cancel_roc_req(&v32);
      goto LABEL_14;
    }
    if ( v34[0] == 1 )
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Waiting for ack, cookie %llx",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "p2p_process_mgmt_tx_cancel",
        a1[1],
        v32,
        v33);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      4u,
      "%s: invalid cancel info",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_mgmt_tx_cancel",
      v32,
      v33);
    result = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
