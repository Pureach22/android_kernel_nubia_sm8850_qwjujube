__int64 __fastcall ipa3_uc_unregister_ready_cb(__int64 a1)
{
  return blocking_notifier_chain_unregister(&uc_loaded_notifier, a1);
}
