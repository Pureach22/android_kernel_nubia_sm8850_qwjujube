__int64 __fastcall wlan_dp_rx_aggr_dis_req(
        __int64 result,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a2 >= 2 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Invalid client id: %u",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dp_rx_aggr_dis_req",
             a2);
  if ( !a2 && (*(_BYTE *)(*(_QWORD *)result + 221LL) & 1) == 0 )
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: wlm rx aggregation control feature not enabled",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dp_rx_aggr_dis_req");
  if ( *(_BYTE *)(result + 3728 + a2) != (a3 & 1) )
  {
    *(_BYTE *)(result + 3728 + a2) = a3 & 1;
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: Module: %u disable: %u",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dp_rx_aggr_dis_req");
  }
  return result;
}
