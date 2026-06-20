__int64 cds_shutdown_notifier_purge()
{
  __int64 v0; // x9
  __int64 *v1; // x20
  __int64 **v2; // x8
  __int64 *v3; // x23

  v0 = raw_spin_lock_irqsave(&ssr_protect_lock);
  v1 = (__int64 *)shutdown_notifier_head;
  if ( (__int64 *)shutdown_notifier_head != &shutdown_notifier_head )
  {
    do
    {
      v3 = (__int64 *)*v1;
      v2 = (__int64 **)v1[1];
      if ( *v2 == v1 && (__int64 *)v3[1] == v1 )
      {
        v3[1] = (__int64)v2;
        *v2 = v3;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_irqrestore(&ssr_protect_lock, v0);
      _qdf_mem_free((__int64)v1);
      v0 = raw_spin_lock_irqsave(&ssr_protect_lock);
      v1 = v3;
    }
    while ( v3 != &shutdown_notifier_head );
  }
  return raw_spin_unlock_irqrestore(&ssr_protect_lock, v0);
}
