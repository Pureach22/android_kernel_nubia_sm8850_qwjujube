__int64 __fastcall gh_panic_notifier_register(__int64 a1)
{
  return srcu_notifier_chain_register(&gh_panic_notifier, a1);
}
