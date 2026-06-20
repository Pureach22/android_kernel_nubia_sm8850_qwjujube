__int64 __fastcall hal_set_ba_aging_timeout_be_generic(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x2
  __int64 v12; // x1

  if ( a2 > 1u )
  {
    if ( a2 == 2 )
    {
      v11 = (unsigned int)(1000 * a3);
      v12 = 10718004;
      return hal_write32_mb_1(a1, v12, v11);
    }
    if ( a2 == 3 )
    {
      v11 = (unsigned int)(1000 * a3);
      v12 = 10718008;
      return hal_write32_mb_1(a1, v12, v11);
    }
    return qdf_trace_msg(0x45u, 2u, "Invalid AC: %d\n", a4, a5, a6, a7, a8, a9, a10, a11, a2);
  }
  if ( !a2 )
  {
    v11 = (unsigned int)(1000 * a3);
    v12 = 10717996;
    return hal_write32_mb_1(a1, v12, v11);
  }
  if ( a2 != 1 )
    return qdf_trace_msg(0x45u, 2u, "Invalid AC: %d\n", a4, a5, a6, a7, a8, a9, a10, a11, a2);
  v11 = (unsigned int)(1000 * a3);
  v12 = 10718000;
  return hal_write32_mb_1(a1, v12, v11);
}
