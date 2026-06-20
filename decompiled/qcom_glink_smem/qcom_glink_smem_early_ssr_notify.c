__int64 __fastcall qcom_glink_smem_early_ssr_notify(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 952);
  if ( result )
    return qcom_glink_early_ssr_notify();
  return result;
}
