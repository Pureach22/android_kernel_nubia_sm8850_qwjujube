__int64 *__fastcall wma_vdev_set_he_bss_params(
        __int64 *result,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( *a3 )
  {
    result = (__int64 *)wma_vdev_set_param(*result, a2, 0x8003u, *a3, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( (_DWORD)result )
      return (__int64 *)qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: Failed to set HE OPs",
                          v11,
                          v12,
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          "wma_vdev_set_he_bss_params");
  }
  return result;
}
