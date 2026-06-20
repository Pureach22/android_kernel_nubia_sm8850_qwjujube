__int64 __fastcall core_ctl_notifier_register(__int64 a1)
{
  return atomic_notifier_chain_register(&core_ctl_notifier, a1);
}
