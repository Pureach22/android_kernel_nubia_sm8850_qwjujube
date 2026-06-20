__int64 __fastcall zte_power_supply_unreg_notifier(__int64 a1)
{
  return atomic_notifier_chain_unregister(&zte_power_supply_notifier, a1);
}
