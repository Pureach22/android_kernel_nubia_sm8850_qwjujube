__int64 __fastcall qcom_unregister_ssr_notifier(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return srcu_notifier_chain_unregister(a1, a2, a3, a4);
}
