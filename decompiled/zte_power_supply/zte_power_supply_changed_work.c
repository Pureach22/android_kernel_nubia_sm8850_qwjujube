__int64 __fastcall zte_power_supply_changed_work(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 v4; // x20
  __int64 v5; // x0

  v2 = raw_spin_lock_irqsave(a1 + 136);
  v3 = *(unsigned __int8 *)(a1 + 140);
  v4 = v2;
  if ( v3 == 1 )
  {
    *(_BYTE *)(a1 + 140) = 0;
    raw_spin_unlock_irqrestore(a1 + 136, v2);
    class_for_each_device(zte_power_supply_class, 0, a1 - 968, _zte_power_supply_changed_work);
    atomic_notifier_call_chain(&zte_power_supply_notifier, 0, a1 - 968);
    kobject_uevent(a1 - 912, 2);
    v5 = raw_spin_lock_irqsave(a1 + 136);
    LOBYTE(v3) = *(_BYTE *)(a1 + 140);
    v4 = v5;
  }
  if ( (v3 & 1) == 0 )
    pm_relax(a1 - 912);
  return raw_spin_unlock_irqrestore(a1 + 136, v4);
}
