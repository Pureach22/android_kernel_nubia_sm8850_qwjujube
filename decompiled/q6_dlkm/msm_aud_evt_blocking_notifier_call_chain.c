__int64 __fastcall msm_aud_evt_blocking_notifier_call_chain(__int64 a1, __int64 a2)
{
  return blocking_notifier_call_chain(&msm_aud_evt_blocking_notifier_list, a1, a2);
}
