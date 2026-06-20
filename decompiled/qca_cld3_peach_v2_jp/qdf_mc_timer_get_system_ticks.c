unsigned __int64 qdf_mc_timer_get_system_ticks()
{
  return (unsigned int)jiffies_to_msecs(jiffies) / 0xAuLL;
}
