__int64 __fastcall lim_update_lost_link_rssi(
        __int64 result,
        char a2,
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

  if ( !result )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: mac is null",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_update_lost_link_rssi",
             v10,
             v11);
  *(_BYTE *)(result + 12208) = a2;
  return result;
}
