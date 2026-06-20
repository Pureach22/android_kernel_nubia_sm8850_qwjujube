__int64 __fastcall register_hboost_event_notifier(__int64 a1)
{
  return raw_notifier_chain_register(&hboost_notifier, a1);
}
