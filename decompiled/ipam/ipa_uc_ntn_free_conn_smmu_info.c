__int64 __fastcall ipa_uc_ntn_free_conn_smmu_info(__int64 a1)
{
  kfree(*(_QWORD *)(a1 + 64));
  *(_QWORD *)(a1 + 64) = 0;
  ipa_smmu_free_sgt((_QWORD **)(a1 + 56));
  return ipa_smmu_free_sgt((_QWORD **)(a1 + 24));
}
