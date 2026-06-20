__int64 __fastcall zte_power_supply_changed(__int64 a1)
{
  __int64 v2; // x20

  v2 = raw_spin_lock_irqsave(a1 + 1104);
  *(_BYTE *)(a1 + 1108) = 1;
  pm_stay_awake(a1 + 56);
  raw_spin_unlock_irqrestore(a1 + 1104, v2);
  return queue_work_on(32, system_wq, a1 + 968);
}
