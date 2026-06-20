__int64 __fastcall msm_aud_evt_unregister_client(__int64 a1)
{
  return atomic_notifier_chain_unregister(&msm_aud_evt_notifier_list, a1);
}
