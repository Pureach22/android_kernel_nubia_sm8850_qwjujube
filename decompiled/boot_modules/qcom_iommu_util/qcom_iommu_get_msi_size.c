__int64 __fastcall qcom_iommu_get_msi_size(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v5; // x0
  int variable_u32_array; // w0
  __int64 result; // x0
  _QWORD v8[11]; // [xsp+8h] [xbp-58h] BYREF

  v8[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 744);
  if ( v3
    && ((memset(v8, 0, 80), !(unsigned int)_of_parse_phandle_with_args(v3, "qcom,iommu-group", 0, 0, 0, v8))
     && (v5 = v8[0]) != 0
     || (v5 = *(_QWORD *)(a1 + 744)) != 0) )
  {
    variable_u32_array = of_property_read_variable_u32_array(v5, "qcom,iommu-msi-size", a2, 1, 0);
    result = variable_u32_array & (unsigned int)(variable_u32_array >> 31);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
