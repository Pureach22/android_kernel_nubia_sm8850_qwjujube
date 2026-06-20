__int64 __fastcall qcom_glink_ssr_notify(__int64 a1)
{
  return blocking_notifier_call_chain(&ssr_notifiers, 0, a1);
}
