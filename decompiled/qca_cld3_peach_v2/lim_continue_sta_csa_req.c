__int64 __fastcall lim_continue_sta_csa_req(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  qdf_trace_msg(
    0x35u,
    4u,
    "%s: Continue CSA for STA vdev id %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_continue_sta_csa_req",
    (unsigned __int8)a2);
  return lim_process_channel_switch(a1, a2);
}
