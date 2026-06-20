__int64 __fastcall hdd_config_channel_avoidance_ind(
        __int64 a1,
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
  unsigned int v10; // w20
  __int64 v11; // x19

  v10 = *(unsigned __int8 *)(a2 + 4);
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: set_value: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_channel_avoidance_ind",
    *(unsigned __int8 *)(a2 + 4));
  return hdd_enable_disable_ca_event(v11, v10);
}
