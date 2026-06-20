__int64 __fastcall _hwfence_regs_unmap(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x1
  __int64 v8; // x1
  unsigned __int64 StatusReg; // x8

  result = msm_cvp_smem_get_context_bank(*(_QWORD *)(a1 + 2208), 0);
  if ( result )
  {
    v3 = *(_QWORD *)(a1 + 2208);
    v4 = result;
    v5 = *(_QWORD *)(v3 + 48);
    if ( v5 )
    {
      result = iommu_unmap(*(_QWORD *)(result + 48), v5, *(unsigned int *)(v3 + 64));
      v3 = *(_QWORD *)(a1 + 2208);
    }
    v6 = *(_QWORD *)(v3 + 72);
    if ( v6 )
    {
      result = iommu_unmap(*(_QWORD *)(v4 + 48), v6, *(unsigned int *)(v3 + 88));
      v3 = *(_QWORD *)(a1 + 2208);
    }
    v7 = *(_QWORD *)(v3 + 96);
    if ( v7 )
    {
      result = iommu_unmap(*(_QWORD *)(v4 + 48), v7, *(unsigned int *)(v3 + 112));
      v3 = *(_QWORD *)(a1 + 2208);
    }
    v8 = *(_QWORD *)(v3 + 120);
    if ( v8 )
      return iommu_unmap(*(_QWORD *)(v4 + 48), v8, *(unsigned int *)(v3 + 136));
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_87695, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
