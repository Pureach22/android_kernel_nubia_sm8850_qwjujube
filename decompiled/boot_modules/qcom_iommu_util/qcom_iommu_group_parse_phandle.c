__int64 __fastcall qcom_iommu_group_parse_phandle(__int64 a1)
{
  __int64 result; // x0
  _QWORD v3[11]; // [xsp+8h] [xbp-58h] BYREF

  v3[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *(_QWORD *)(a1 + 744);
  if ( result )
  {
    memset(v3, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(result, "qcom,iommu-group", 0, 0, 0, v3) || (result = v3[0]) == 0 )
      result = *(_QWORD *)(a1 + 744);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
