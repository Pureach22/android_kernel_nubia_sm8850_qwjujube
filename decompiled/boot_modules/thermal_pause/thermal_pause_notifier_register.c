__int64 __fastcall thermal_pause_notifier_register(__int64 a1)
{
  return blocking_notifier_chain_register(&thermal_pause_notifier, a1);
}
