__int64 __fastcall wma_send_link_speed(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x21
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x19
  void (*v30)(void); // x8

  context = _cds_get_context(53, (__int64)"wma_send_link_speed", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    v20 = _qdf_mem_malloc(0xCu, "wma_send_link_speed", 3521);
    if ( v20 )
    {
      *(_DWORD *)(v20 + 8) = a1;
      v29 = v20;
      v30 = (void (*)(void))v19[1629];
      if ( v30 )
      {
        if ( *((_DWORD *)v30 - 1) != 1191253612 )
          __break(0x8228u);
        v30();
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: link_speed_cb is null",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "wma_send_link_speed");
      }
      _qdf_mem_free(v29);
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 8u, "%s: NULL mac ptr. Exiting", v11, v12, v13, v14, v15, v16, v17, v18, "wma_send_link_speed");
    return 4;
  }
}
