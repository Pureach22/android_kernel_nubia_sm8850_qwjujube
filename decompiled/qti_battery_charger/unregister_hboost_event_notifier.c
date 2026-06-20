__int64 __fastcall unregister_hboost_event_notifier(__int64 a1)
{
  return raw_notifier_chain_unregister(&hboost_notifier, a1);
}
