__int64 __fastcall qptm_data_update_notifier_unregister(__int64 a1)
{
  return blocking_notifier_chain_unregister(&qptm_update_notifier, a1);
}
