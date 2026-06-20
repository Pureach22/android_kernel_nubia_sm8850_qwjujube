__int64 *__fastcall wma_set_he_txbf_cfg(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v11; // x20
  __int64 *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x9
  unsigned __int64 v22; // x8
  int v23; // w10
  unsigned int v24; // w20
  int v25; // w21
  unsigned int v26; // w19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1317LL);
  result = _cds_get_context(54, (__int64)"wma_set_he_txbf_params", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = (v11 >> 17) & 1;
    v22 = (v11 & 0x20000) >> 15;
    if ( (v11 & 0x10000) != 0 )
      v23 = 50;
    else
      v23 = 48;
    v24 = ((unsigned int)v11 >> 15) & 8;
    v25 = v23 | v21 | v22;
    v26 = wma_vdev_set_param(*result, a2, 0x8002u, v25 | v24, v13, v14, v15, v16, v17, v18, v19, v20);
    result = (__int64 *)qdf_trace_msg(
                          0x36u,
                          8u,
                          "%s: set HEMU_MODE (hemu_mode = 0x%x)",
                          v27,
                          v28,
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          "wma_set_he_txbf_params",
                          v25 | v24);
    if ( v26 )
      return (__int64 *)qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: failed to set HEMU_MODE(status = %d)",
                          v35,
                          v36,
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          v42,
                          "wma_set_he_txbf_params",
                          v26);
  }
  return result;
}
