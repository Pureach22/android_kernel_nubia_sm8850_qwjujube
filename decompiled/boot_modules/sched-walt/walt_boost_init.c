__int64 walt_boost_init()
{
  __int64 result; // x0

  if ( (walt_disabled & 1) == 0 )
  {
    mutex_lock(&boost_mutex);
    sched_set_boost(1);
    return mutex_unlock(&boost_mutex);
  }
  return result;
}
