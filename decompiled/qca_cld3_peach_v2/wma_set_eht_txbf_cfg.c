__int64 *__fastcall wma_set_eht_txbf_cfg(
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
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 *result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  unsigned int v23; // w8
  int v24; // w20
  unsigned int v25; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1501LL);
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1509LL);
  result = _cds_get_context(54, (__int64)"wma_set_eht_txbf_params", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v22 = *result;
    v23 = ((unsigned int)v12 >> 20) & 2;
    if ( (v12 & 0x400000) != 0 )
      v23 |= 5u;
    if ( (v11 & 0x70000) != 0 )
      v24 = v23 | 8;
    else
      v24 = v23;
    v25 = wma_vdev_set_param(v22, a2, 0x8005u, v24 | 0x30u, v14, v15, v16, v17, v18, v19, v20, v21);
    result = (__int64 *)qdf_trace_msg(
                          0x36u,
                          8u,
                          "%s: set EHTMU_MODE (ehtmu_mode = 0x%x)",
                          v26,
                          v27,
                          v28,
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          "wma_set_eht_txbf_params",
                          v24 | 0x30u);
    if ( v25 )
      return (__int64 *)qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: failed to set EHTMU_MODE(status = %d)",
                          v34,
                          v35,
                          v36,
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          "wma_set_eht_txbf_params",
                          v25);
  }
  return result;
}
