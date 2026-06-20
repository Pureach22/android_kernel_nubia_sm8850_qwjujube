void __fastcall hdd_medium_assess_ssr_reinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x29
  __int64 v9; // x30
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( timer_enable == 1 && ssr_flag == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: medium assess init timer in ssr",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "hdd_medium_assess_ssr_reinit",
      v8,
      v9);
    if ( (unsigned int)qdf_mc_timer_init(
                         (__int64)&hdd_medium_assess_timer,
                         0,
                         (__int64)hdd_medium_assess_expire_handler,
                         0) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: medium assess init timer failed in ssr",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "hdd_medium_assess_ssr_reinit");
    }
    else
    {
      ssr_flag = 0;
      qdf_mc_timer_start((__int64)&hdd_medium_assess_timer, 0x3E8u);
    }
  }
}
