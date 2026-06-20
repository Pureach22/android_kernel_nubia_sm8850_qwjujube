__int64 __fastcall wma_wait_for_ready_event(
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
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w19

  v9 = *(_QWORD *)(a1 + 24);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 2800)) == 0 )
  {
    qdf_trace_msg(0x36u, 2u, "%s: target psoc info is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wma_wait_for_ready_event");
    return 4;
  }
  v11 = qdf_wait_for_event_completion(v10 + 512, 0x1770u);
  if ( (*(_BYTE *)(v10 + 485) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Error in pdev creation",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_wait_for_ready_event");
    if ( (cds_get_driver_state(v21, v22, v23, v24, v25, v26, v27, v28) & 8) != 0 )
      cds_is_fw_down(v29, v30, v31, v32, v33, v34, v35, v36);
    return 4;
  }
  if ( v11 )
  {
    if ( v11 == 15 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Timeout waiting for FW ready event",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wma_wait_for_ready_event");
      return 15;
    }
    else
    {
      v37 = v11;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to wait for FW ready event; status:%u",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wma_wait_for_ready_event",
        v11);
      return v37;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      4u,
      "%s: FW ready event received",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_wait_for_ready_event");
    return 0;
  }
}
