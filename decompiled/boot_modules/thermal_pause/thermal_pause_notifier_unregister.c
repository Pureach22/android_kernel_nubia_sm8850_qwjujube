__int64 __fastcall thermal_pause_notifier_unregister(__int64 a1)
{
  return blocking_notifier_chain_unregister(&thermal_pause_notifier, a1);
}
