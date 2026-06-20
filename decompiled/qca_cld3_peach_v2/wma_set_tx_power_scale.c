__int64 __fastcall wma_set_tx_power_scale(
        unsigned int a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x0
  __int64 *v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19

  context = _cds_get_context(54, (__int64)"wma_set_tx_power_scale", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 16;
  v13 = context;
  if ( (wma_is_vdev_up(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id %d is not up",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wma_set_tx_power_scale",
      (unsigned __int8)a1);
    return 16;
  }
  result = wma_vdev_set_param(*v13, (unsigned __int8)a1, 0x50u, a2, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( (_DWORD)result )
  {
    v31 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Set tx power scale failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_set_tx_power_scale");
    return v31;
  }
  return result;
}
