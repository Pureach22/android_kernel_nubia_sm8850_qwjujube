__int64 __fastcall aps_set_inactive_time(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  if ( (unsigned int)kstrtouint(a1, 10, &v5) )
  {
    result = 4294967274LL;
  }
  else
  {
    raw_spin_lock_bh(&dl_activity_lock);
    if ( v5 )
    {
      inactive_ktime = 1000000LL * (unsigned int)(1000 * v5);
      last_inactive_ts = ktime_get_coarse_with_offset(1);
      rmnet_module_hook_register(&aps_data_activity_hooks, 2);
    }
    else
    {
      inactive_ktime = 0;
      rmnet_module_hook_unregister_no_sync(&aps_data_activity_hooks, 2);
    }
    raw_spin_unlock_bh(&dl_activity_lock);
    result = param_set_uint(a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
