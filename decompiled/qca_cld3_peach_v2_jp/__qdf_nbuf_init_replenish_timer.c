__int64 _qdf_nbuf_init_replenish_timer()
{
  return qdf_mc_timer_init((__int64)&alloc_track_timer, 0, (__int64)qdf_replenish_expire_handler, 0);
}
