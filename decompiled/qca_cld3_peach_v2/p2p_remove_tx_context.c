__int64 __fastcall p2p_remove_tx_context(
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
  __int64 v10; // x20
  _QWORD *tx_ctx; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w1
  __int64 result; // x0
  _BYTE v32[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v33[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 16);
  v33[0] = 0;
  v32[0] = 0;
  qdf_trace_msg(0x4Eu, 8u, "%s: tx context:%pK", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_remove_tx_context", a1);
  tx_ctx = (_QWORD *)p2p_find_tx_ctx(v10, a1, v33, v32);
  if ( !tx_ctx )
  {
    v29 = "%s: Do not find tx context from queue";
    v30 = 8;
    goto LABEL_9;
  }
  v20 = tx_ctx;
  if ( v33[0] == 1 && (unsigned int)qdf_list_remove_node(v10 + 32, tx_ctx) )
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Failed to  tx context from wait roc req queue",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "p2p_remove_tx_context");
  if ( v32[0] == 1 && (unsigned int)qdf_list_remove_node(v10 + 56, v20) )
  {
    v29 = "%s: Failed to  tx context from wait ack req queue";
    v30 = 2;
LABEL_9:
    qdf_trace_msg(0x4Eu, v30, v29, v12, v13, v14, v15, v16, v17, v18, v19, "p2p_remove_tx_context");
  }
  if ( !*(_QWORD *)(a1 + 32) )
    qdf_idr_remove(v10 + 224, *(_DWORD *)(a1 + 40));
  _qdf_mem_free(*(_QWORD *)(a1 + 48));
  result = _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
