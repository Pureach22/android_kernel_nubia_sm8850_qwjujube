__int64 __fastcall zte_power_supply_reg_notifier(__int64 a1)
{
  return atomic_notifier_chain_register(&zte_power_supply_notifier, a1);
}
