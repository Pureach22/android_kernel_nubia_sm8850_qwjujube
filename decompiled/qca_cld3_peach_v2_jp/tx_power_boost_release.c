__int64 __fastcall tx_power_boost_release(
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
    0x33u,
    8u,
    "%s: TPB: Device successfully closed",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "tx_power_boost_release");
  return 0;
}
