__int64 *__fastcall wma_set_he_txbf_params(
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
  int v26; // w10
  int v27; // w9
  int v28; // w11
  int v29; // w21
  int v30; // w20
  unsigned int v31; // w19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  result = _cds_get_context(54, (__int64)"wma_set_he_txbf_params", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    if ( (a4 & 1) != 0 )
      v25 = 8;
    else
      v25 = 0;
    v26 = a3 & 1;
    if ( (a3 & 1) != 0 )
      v27 = 4;
    else
      v27 = 0;
    if ( (a2 & 1) != 0 )
      v28 = 50;
    else
      v28 = 48;
    v29 = v27 | v25;
    v30 = v28 | v26;
    v31 = wma_vdev_set_param(
            *result,
            a1,
            0x8002u,
            v28 | v26 | v27 | (unsigned int)v25,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    result = (__int64 *)qdf_trace_msg(
                          0x36u,
                          8u,
                          "%s: set HEMU_MODE (hemu_mode = 0x%x)",
                          v32,
                          v33,
                          v34,
                          v35,
                          v36,
                          v37,
                          v38,
                          v39,
                          "wma_set_he_txbf_params",
                          v30 | (unsigned int)v29);
    if ( v31 )
      return (__int64 *)qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: failed to set HEMU_MODE(status = %d)",
                          v40,
                          v41,
                          v42,
                          v43,
                          v44,
                          v45,
                          v46,
                          v47,
                          "wma_set_he_txbf_params",
                          v31);
  }
  return result;
}
