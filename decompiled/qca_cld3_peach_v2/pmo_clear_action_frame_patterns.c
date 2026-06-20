__int64 __fastcall pmo_clear_action_frame_patterns(__int64 a1)
{
  _QWORD *v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v2 = (_QWORD *)_qdf_mem_malloc(0x428u, "pmo_clear_action_frame_patterns", 558);
  if ( v2 )
  {
    v11 = (__int64)v2;
    *v2 = *(unsigned __int8 *)(a1 + 168);
    v12 = pmo_tgt_send_action_frame_pattern_req(a1, v2);
    if ( v12 )
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to clear wow action frame map, ret %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "pmo_clear_action_frame_patterns",
        v12);
    _qdf_mem_free(v11);
  }
  else
  {
    v12 = 2;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: memory allocation failed for wakeup set params",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "pmo_clear_action_frame_patterns");
  }
  return v12;
}
