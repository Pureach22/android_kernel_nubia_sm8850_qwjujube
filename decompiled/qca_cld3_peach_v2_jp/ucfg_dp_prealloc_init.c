__int64 __fastcall ucfg_dp_prealloc_init(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  result = ((__int64 (*)(void))dp_prealloc_init)();
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: prealloc_init failed for %d times",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "ucfg_dp_prealloc_init",
      0);
    result = dp_prealloc_init(a1);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: prealloc_init failed for %d times",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "ucfg_dp_prealloc_init",
        1);
      result = dp_prealloc_init(a1);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x45u,
          3u,
          "%s: prealloc_init failed for %d times",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "ucfg_dp_prealloc_init",
          2);
        result = dp_prealloc_init(a1);
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x45u,
            3u,
            "%s: prealloc_init failed for %d times",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "ucfg_dp_prealloc_init",
            3);
          return 16;
        }
      }
    }
  }
  return result;
}
