__int64 __fastcall wlan_tdls_notify_channel_switch_start(
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
    0,
    8u,
    "%s: Send Channel Switch start to TDLS module",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_tdls_notify_channel_switch_start");
  return wlan_tdls_post_set_off_channel_mode(a1);
}
