__int64 rmnet_shs_pb_hdr_handler()
{
  rmnet_shs_pb_boost_cpus();
  if ( (hrtimer_active(&unk_18FF0) & 1) != 0 )
    hrtimer_cancel(&unk_18FF0);
  return hrtimer_start_range_ns(&unk_18FF0, (unsigned int)(1000000 * rmnet_shs_pb_boost_timer_ms), 0, 1);
}
