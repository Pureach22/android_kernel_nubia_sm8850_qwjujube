__int64 __fastcall rmnet_ctl_get_stats(void *a1, int a2)
{
  void *lock; // x0

  lock = (void *)_rcu_read_lock();
  if ( a2 >= 1 && ctl_ep )
  {
    if ( (unsigned int)a2 >= 5 )
      a2 = 5;
    lock = memcpy(a1, (const void *)(ctl_ep + 8), (unsigned int)(8 * a2));
  }
  _rcu_read_unlock(lock);
  return (unsigned int)a2;
}
