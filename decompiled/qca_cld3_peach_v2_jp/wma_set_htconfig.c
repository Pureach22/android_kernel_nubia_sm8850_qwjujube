__int64 __fastcall wma_set_htconfig(
        unsigned __int8 a1,
        unsigned __int16 a2,
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
  __int64 *v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x0
  unsigned int v34; // w1
  unsigned int v35; // w2

  context = _cds_get_context(54, (__int64)"wma_set_htconfig", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 4;
  if ( a2 > 6u )
  {
    if ( a2 == 7 )
    {
      v33 = *context;
      v34 = a1;
      v35 = 30;
      return wma_vdev_set_param(v33, v34, v35, a3, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    if ( a2 == 8 )
    {
      v33 = *context;
      v34 = a1;
      v35 = 31;
      return wma_vdev_set_param(v33, v34, v35, a3, v15, v16, v17, v18, v19, v20, v21, v22);
    }
LABEL_14:
    qdf_trace_msg(0x36u, 2u, "%s: INVALID HT CONFIG", v15, v16, v17, v18, v19, v20, v21, v22, "wma_set_htconfig");
    return 16;
  }
  if ( (unsigned int)a2 - 5 >= 2 )
  {
    if ( !a2 )
    {
      v33 = *context;
      v34 = a1;
      v35 = 29;
      return wma_vdev_set_param(v33, v34, v35, a3, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    goto LABEL_14;
  }
  v23 = context;
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: ht_capab = %d, value = %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wma_set_htconfig",
    a2,
    a3);
  result = wma_vdev_set_param(*v23, a1, 0x1Cu, a3, v24, v25, v26, v27, v28, v29, v30, v31);
  if ( !(_DWORD)result )
    *(_DWORD *)(v23[65] + 488LL * a1 + 32) = a3;
  return result;
}
