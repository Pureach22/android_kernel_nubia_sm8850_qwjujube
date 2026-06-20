__int64 __fastcall zte_power_supply_deferred_register_work(__int64 a1)
{
  __int64 *v1; // x21
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x20

  v1 = (__int64 *)(a1 - 848);
  v3 = *(_QWORD *)(a1 - 848);
  if ( v3 )
  {
    while ( 1 )
    {
      result = mutex_trylock(v3 + 160);
      if ( (_DWORD)result )
        break;
      if ( (*(_BYTE *)(a1 + 110) & 1) != 0 )
        return result;
      msleep(10);
      v3 = *v1;
    }
  }
  v5 = raw_spin_lock_irqsave(a1 + 104);
  *(_BYTE *)(a1 + 108) = 1;
  pm_stay_awake(a1 - 944);
  raw_spin_unlock_irqrestore(a1 + 104, v5);
  result = queue_work_on(32, system_wq, a1 - 32);
  if ( *v1 )
    return mutex_unlock(*v1 + 160);
  return result;
}
