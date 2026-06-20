__int64 __fastcall qcom_notify_early_ssr_clients(__int64 a1)
{
  return srcu_notifier_call_chain(*(_QWORD *)(a1 + 96) + 528LL, 2, 0);
}
