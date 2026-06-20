__int64 __fastcall hdd_txpb_issue_app_stop_ready(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)hdd_txpb_inference_app_stop() )
  {
    v15 = "%s: TPB: %s: Failed to send CMD_ABORT for %s";
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TPB: %s: Send CMD_ABORT for %s successful",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_txpb_issue_app_stop_ready",
      a3,
      a4);
    v24 = ucfg_reg_txpb_send_inference_cmd(*(_QWORD *)(a1 + 8), v16, v17, v18, v19, v20, v21, v22, v23);
    if ( !v24 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: TPB: %s: Send CMD_READY for %s successful",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_txpb_issue_app_stop_ready",
        a3,
        a4,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0);
      result = 0;
      *(_BYTE *)(a1 + 8568) = 1;
      goto LABEL_6;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TPB: sme_txpb_send_inference_cmd failed: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_txpb_issue_boost_ready",
      v24,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0);
    v15 = "%s: TPB: %s: Failed to send CMD_READY for %s";
  }
  qdf_trace_msg(0x33u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_txpb_issue_app_stop_ready", a3, a4);
  result = 16;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
