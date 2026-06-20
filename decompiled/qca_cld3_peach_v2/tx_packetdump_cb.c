__int64 __fastcall tx_packetdump_cb(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( result )
  {
    if ( gtx_count == 32 || grx_count == 32 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s gtx_count: %d grx_count: %d deregister packetdump",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "check_txrx_packetdump_count",
        (unsigned __int8)gtx_count,
        (unsigned __int8)grx_count);
      return wlan_deregister_txrx_packetdump();
    }
    else
    {
      return send_packetdump();
    }
  }
  return result;
}
