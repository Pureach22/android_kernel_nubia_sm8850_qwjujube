__int64 __fastcall core_ctl_notifier_unregister(__int64 a1)
{
  return atomic_notifier_chain_unregister(&core_ctl_notifier, a1);
}
