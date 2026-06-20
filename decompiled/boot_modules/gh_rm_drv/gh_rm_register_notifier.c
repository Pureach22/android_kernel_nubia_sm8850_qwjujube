__int64 __fastcall gh_rm_register_notifier(__int64 a1)
{
  return srcu_notifier_chain_register(&gh_rm_notifier, a1);
}
