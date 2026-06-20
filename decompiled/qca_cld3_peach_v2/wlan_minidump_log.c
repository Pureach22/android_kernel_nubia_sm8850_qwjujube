__int64 __fastcall wlan_minidump_log(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 result; // x0

  if ( !a11 )
    return qdf_trace_msg(
             0x38u,
             8u,
             "%s: Minidump: Psoc is NULL",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "wlan_minidump_log",
             v11,
             v12);
  return result;
}
