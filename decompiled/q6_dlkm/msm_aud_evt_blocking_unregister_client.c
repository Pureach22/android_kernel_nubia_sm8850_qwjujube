__int64 __fastcall msm_aud_evt_blocking_unregister_client(__int64 a1)
{
  return blocking_notifier_chain_unregister(&msm_aud_evt_blocking_notifier_list, a1);
}
