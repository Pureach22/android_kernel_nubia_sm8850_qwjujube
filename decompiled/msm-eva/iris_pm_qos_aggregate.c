__int64 __fastcall iris_pm_qos_aggregate(__int64 a1)
{
  __int64 v2; // x20
  __int64 *v3; // x22
  unsigned int v4; // w21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    v2 = *(_QWORD *)(cvp_driver + 48);
    mutex_lock(v2);
    v3 = *(__int64 **)(v2 + 280);
    v4 = 0x7FFFFFFF;
    while ( v3 != (__int64 *)(v2 + 280) )
    {
      raw_spin_lock(v3 + 22);
      if ( *((_DWORD *)v3 + 45) == 2 && v4 >= *((_DWORD *)v3 + 3852) )
        v4 = *((_DWORD *)v3 + 3852);
      raw_spin_unlock(v3 + 22);
      v3 = (__int64 *)*v3;
    }
    mutex_unlock(v2);
    if ( v4 != *(_DWORD *)(a1 + 2696) )
    {
      mutex_lock(a1 + 80);
      if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
        printk(&unk_9597B, &unk_8DA84, "iris_pm_qos_aggregate", v4);
      if ( v4 > *(_DWORD *)(v2 + 996) )
      {
        *(_DWORD *)(a1 + 2696) = v4;
        cvp_pm_qos_update(a1, 1);
      }
      mutex_unlock(a1 + 80);
    }
    return 0;
  }
  else
  {
    result = 4294967277LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_94F45, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967277LL;
    }
  }
  return result;
}
