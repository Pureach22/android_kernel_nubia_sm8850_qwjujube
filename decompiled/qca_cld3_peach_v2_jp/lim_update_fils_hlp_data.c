int *__fastcall lim_update_fils_hlp_data(
        int *result,
        int *a2,
        unsigned __int16 a3,
        const void *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x24
  unsigned int v15; // w23
  int *v17; // x22
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

  v13 = *(_QWORD *)(a5 + 9976);
  if ( !v13 )
    return (int *)qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Not a fils connection",
                    a6,
                    a7,
                    a8,
                    a9,
                    a10,
                    a11,
                    a12,
                    a13,
                    "lim_update_fils_hlp_data");
  v15 = a3;
  if ( a3 && a4 )
  {
    v17 = result;
    _qdf_mem_free(*(_QWORD *)(v13 + 1608));
    result = (int *)_qdf_mem_malloc(a3, "lim_update_fils_hlp_data", 2306);
    *(_QWORD *)(v13 + 1608) = result;
    if ( result )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: FILS: hlp_data_len:%d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "lim_update_fils_hlp_data",
        v15);
      return (int *)cds_copy_hlp_info(
                      a2,
                      v17,
                      a3,
                      a4,
                      v13 + 1589,
                      v13 + 1595,
                      (unsigned __int16 *)(v13 + 1602),
                      *(void **)(v13 + 1608),
                      v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33,
                      v34);
    }
  }
  return result;
}
