__int64 __fastcall mlo_link_recfg_timer_deinit(__int64 a1)
{
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 3288) == 21 )
    qdf_mc_timer_stop(a1 + 3288);
  return qdf_mc_timer_destroy(a1 + 3288);
}
