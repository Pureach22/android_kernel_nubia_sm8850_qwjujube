__int64 __fastcall hdd_reset_tsf_sync(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( *(_BYTE *)(a1 + 39144) == 1 )
  {
    v2 = hdd_stop_tsf_sync();
    if ( v2 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to stop tsf sync, ret: %d",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "hdd_reset_tsf_sync",
        v2);
    v11 = qdf_mc_timer_stop(a1 + 38976);
    if ( v11 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to stop capture timer, ret: %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_reset_tsf_sync",
        v11);
    v20 = qdf_mc_timer_destroy(a1 + 38976);
    if ( v20 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to destroy capture timer, ret: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "hdd_reset_tsf_sync",
        v20);
    *(_BYTE *)(a1 + 39144) = 0;
  }
  else
  {
    return 0;
  }
  return v20;
}
