__int64 __fastcall sch_set_beacon_interval(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w4

  v12 = *(unsigned __int16 *)(a2 + 7158);
  if ( (unsigned int)(v12 - 10001) <= 0xFFFFD8F8 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: Invalid beacon interval %d (should be [%d,%d]",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "sch_set_beacon_interval",
             v10,
             v11);
  *(_WORD *)(result + 12448) = v12;
  return result;
}
