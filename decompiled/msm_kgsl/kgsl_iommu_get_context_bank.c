__int64 __fastcall kgsl_iommu_get_context_bank(__int64 a1, __int64 a2)
{
  __int64 v2; // x9

  if ( a2 && (*(_BYTE *)(a2 + 203) & 0x20) != 0 )
    v2 = 696;
  else
    v2 = 136;
  return qcom_iommu_get_context_bank_nr(*(_QWORD *)(*(_QWORD *)(a1 + 112) + v2));
}
