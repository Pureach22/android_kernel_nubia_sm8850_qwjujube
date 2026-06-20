__int64 __fastcall bcl_pmic5_notifier_unregister(__int64 a1)
{
  return blocking_notifier_chain_unregister(&bcl_pmic5_notifier, a1);
}
