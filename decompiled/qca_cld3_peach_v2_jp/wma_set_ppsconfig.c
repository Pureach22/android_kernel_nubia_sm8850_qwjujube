__int64 __fastcall wma_set_ppsconfig(
        unsigned __int8 a1,
        __int16 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  __int64 *v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  context = _cds_get_context(54, (__int64)"wma_set_ppsconfig", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 4;
  if ( (unsigned __int16)(a2 - 1) > 2u )
  {
    qdf_trace_msg(0x36u, 2u, "%s: INVALID PPS CONFIG", v15, v16, v17, v18, v19, v20, v21, v22, "wma_set_ppsconfig");
    return 16;
  }
  else
  {
    v23 = dword_A18338[(unsigned __int16)(a2 - 1)] | (a3 << 31);
    v24 = context;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id:%d val:0x%x pps_val:0x%x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_set_ppsconfig",
      a1,
      a3,
      v23);
    return 16
         * (unsigned int)((unsigned int)wma_vdev_set_param(*v24, a1, 0x2Eu, v23, v25, v26, v27, v28, v29, v30, v31, v32) != 0);
  }
}
