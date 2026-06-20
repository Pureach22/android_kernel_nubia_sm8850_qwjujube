__int64 __fastcall bcl_pmic5_notifier_register(__int64 a1)
{
  return blocking_notifier_chain_register(&bcl_pmic5_notifier, a1);
}
