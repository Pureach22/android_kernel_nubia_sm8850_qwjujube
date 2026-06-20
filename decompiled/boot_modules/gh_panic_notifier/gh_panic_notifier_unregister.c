__int64 __fastcall gh_panic_notifier_unregister(__int64 a1)
{
  return srcu_notifier_chain_unregister(&gh_panic_notifier, a1);
}
