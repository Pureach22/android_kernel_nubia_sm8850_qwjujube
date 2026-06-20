__int64 __fastcall hdd_setup_tsf_sync(__int64 a1)
{
  unsigned int v1; // w20
  unsigned int started; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( (*(_BYTE *)(a1 + 39144) & 1) != 0 )
  {
    return 0;
  }
  else
  {
    started = hdd_start_tsf_sync();
    if ( started )
    {
      v1 = started;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init capture timer, ret: %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_setup_tsf_sync",
        started);
    }
    else
    {
      v1 = qdf_mc_timer_init(a1 + 38976, 0, (__int64)hdd_capture_req_timer_expired_handler, a1);
      if ( v1 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to init capture timer, ret: %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hdd_setup_tsf_sync",
          v1);
        hdd_stop_tsf_sync(a1, v20, v21, v22, v23, v24, v25, v26, v27);
      }
      *(_BYTE *)(a1 + 39144) = 1;
    }
  }
  return v1;
}
