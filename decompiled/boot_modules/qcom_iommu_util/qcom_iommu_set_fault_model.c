__int64 __fastcall qcom_iommu_set_fault_model(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 result; // x0
  _DWORD *v7; // x8

  v4 = xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(a1 + 8));
  if ( !v4 )
    return 4294967274LL;
  v5 = v4;
  result = 4294967274LL;
  if ( a2 <= 0xF )
  {
    v7 = *(_DWORD **)(v5 + 48);
    if ( v7 )
    {
      if ( *(v7 - 1) != -794516176 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD))v7)(a1, a2);
    }
  }
  return result;
}
