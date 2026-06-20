__int64 *__fastcall hdd_validate_next_adapter(
        __int64 *result,
        _QWORD *a2,
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
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 *v13; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( *result )
  {
    if ( *result == *a2 )
    {
      v13 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Validation failed",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "hdd_validate_next_adapter",
        v11,
        v12);
      result = (__int64 *)hdd_adapter_dev_put_debug(*v13, a3, v16, v17, v18, v19, v20, v21, v22, v23);
      *v13 = 0;
      *a2 = 0;
    }
  }
  return result;
}
