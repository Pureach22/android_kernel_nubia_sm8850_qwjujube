__int64 __fastcall qcom_glink_ssr_remove(__int64 a1)
{
  return blocking_notifier_chain_unregister(&ssr_notifiers, *(_QWORD *)(a1 + 152) + 16LL);
}
