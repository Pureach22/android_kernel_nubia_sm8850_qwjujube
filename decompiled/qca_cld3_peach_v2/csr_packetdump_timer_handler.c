__int64 __fastcall csr_packetdump_timer_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Invoking packetdump deregistration API",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "csr_packetdump_timer_handler");
  return wlan_deregister_txrx_packetdump();
}
