__int64 *__fastcall wma_set_eht_txbf_params(
        unsigned __int8 a1,
        char a2,
        char a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  __int64 v26; // x0
  int v27; // w20
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  result = _cds_get_context(54, (__int64)"wma_set_eht_txbf_params", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v25 = 2;
    else
      v25 = 0;
    v26 = *result;
    if ( (a3 & 1) != 0 )
      v25 |= 5u;
    if ( (a4 & 1) != 0 )
      v27 = v25 | 8;
    else
      v27 = v25;
    v28 = wma_vdev_set_param(v26, a1, 0x8005u, v27 | 0x30u, v17, v18, v19, v20, v21, v22, v23, v24);
    result = (__int64 *)qdf_trace_msg(
                          0x36u,
                          8u,
                          "%s: set EHTMU_MODE (ehtmu_mode = 0x%x)",
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          v35,
                          v36,
                          "wma_set_eht_txbf_params",
                          v27 | 0x30u);
    if ( v28 )
      return (__int64 *)qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: failed to set EHTMU_MODE(status = %d)",
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          v42,
                          v43,
                          v44,
                          "wma_set_eht_txbf_params",
                          v28);
  }
  return result;
}
