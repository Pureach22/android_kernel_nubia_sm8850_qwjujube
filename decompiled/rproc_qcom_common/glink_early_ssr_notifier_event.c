__int64 __fastcall glink_early_ssr_notifier_event(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v2; // x1

  v1 = *(__int64 **)(*(_QWORD *)(a1 - 24) + 96LL);
  v2 = v1[14];
  if ( !v2 )
    v2 = *v1;
  qcom_glink_smem_early_ssr_notify(*(_QWORD *)(a1 - 8), v2);
  return 0;
}
