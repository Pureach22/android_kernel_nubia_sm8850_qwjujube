__int64 __fastcall mlo_link_recfg_timer_init(__int64 a1)
{
  return qdf_mc_timer_init(a1 + 3288, 0, (__int64)mlo_link_recfg_rx_rsp_timeout_cb, a1);
}
