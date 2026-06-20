__int64 __fastcall ipa_pm_get_scaling_bw_levels(_DWORD *a1)
{
  __int64 v1; // x8

  v1 = ipa_pm_ctx;
  if ( !ipa_pm_ctx || *(int *)(ipa_pm_ctx + 1112) < 3 )
    return 4294967274LL;
  a1[1] = **(_DWORD **)(ipa_pm_ctx + 1144);
  a1[2] = *(_DWORD *)(*(_QWORD *)(v1 + 1144) + 4LL);
  a1[3] = *(_DWORD *)(*(_QWORD *)(v1 + 1144) + 8LL);
  return 0;
}
