__int64 __fastcall gh_rm_unregister_notifier(__int64 a1)
{
  return srcu_notifier_chain_unregister(&gh_rm_notifier, a1);
}
