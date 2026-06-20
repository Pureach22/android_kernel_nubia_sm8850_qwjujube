unsigned __int64 __fastcall qcom_register_early_ssr_notifier(const char *a1, __int64 a2)
{
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x20

  result = qcom_ssr_get_subsys(a1);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = result + 528;
    srcu_notifier_chain_register(result + 528, a2);
    return v4;
  }
  return result;
}
