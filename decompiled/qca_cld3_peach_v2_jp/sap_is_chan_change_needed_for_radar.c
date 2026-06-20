__int64 __fastcall sap_is_chan_change_needed_for_radar(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: phy mode: 0x%x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "sap_is_chan_change_needed_for_radar",
    *(unsigned int *)(a1 + 1484));
  return 1;
}
