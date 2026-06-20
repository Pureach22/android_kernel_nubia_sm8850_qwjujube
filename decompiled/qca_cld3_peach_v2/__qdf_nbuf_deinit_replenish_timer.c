__int64 _qdf_nbuf_deinit_replenish_timer()
{
  if ( dword_7CF500 )
  {
    dword_7CF500 = 0;
    if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)&alloc_track_timer) == 21 )
      qdf_mc_timer_stop((__int64)&alloc_track_timer);
  }
  return qdf_mc_timer_destroy((__int64)&alloc_track_timer);
}
