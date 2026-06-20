unsigned __int16 *tethering_stats_poll_queue()
{
  unsigned __int16 *result; // x0
  __int64 v1; // x0

  result = rmnet_ipa_get_stats_and_update();
  if ( qword_201788 )
  {
    v1 = _msecs_to_jiffies((unsigned int)(1000 * qword_201788));
    return (unsigned __int16 *)queue_delayed_work_on(32, system_wq, &ipa_tether_stats_poll_wakequeue_work, v1);
  }
  return result;
}
