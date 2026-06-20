void qdf_nbuf_stop_replenish_timer()
{
  if ( dword_716AD0 )
  {
    dword_716AD0 = 0;
    if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)&alloc_track_timer) == 21 )
      qdf_mc_timer_stop((__int64)&alloc_track_timer);
  }
}
