__int64 __fastcall wma_set_dtim_period(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  __int64 v11; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0

  v10 = *a2;
  v11 = *(_QWORD *)(a1 + 520);
  if ( (wma_is_vdev_valid(v10, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    return qdf_trace_msg(0x36u, 2u, "%s: invalid VDEV", v13, v14, v15, v16, v17, v18, v19, v20, "wma_set_dtim_period");
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: set dtim_period %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_set_dtim_period",
             a2[1]);
  *(_BYTE *)(v11 + 488LL * v10 + 178) = a2[1];
  return result;
}
