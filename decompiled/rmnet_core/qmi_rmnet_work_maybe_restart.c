__int64 __fastcall qmi_rmnet_work_maybe_restart(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 lock; // x0
  unsigned __int64 v13; // x8

  result = rmnet_get_qmi_pt(a1);
  if ( result )
  {
    if ( rmnet_work_inited )
    {
      _X9 = (unsigned __int64 *)(result + 64);
      __asm { PRFM            #0x11, [X9] }
      do
        v13 = __ldxr(_X9);
      while ( __stlxr(v13 | 1, _X9) );
      __dmb(0xBu);
      if ( (v13 & 1) == 0 )
      {
        *(_BYTE *)(result + 74) = 0;
        lock = _rcu_read_lock();
        if ( (rmnet_work_quit & 1) == 0 )
          lock = queue_delayed_work_on(32, rmnet_ps_wq, rmnet_work, 0);
        result = _rcu_read_unlock(lock);
        if ( a2 | a3 )
          return rmnet_module_hook_aps_data_active(a2, a3);
      }
    }
  }
  return result;
}
