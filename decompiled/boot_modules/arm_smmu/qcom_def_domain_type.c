__int64 __fastcall qcom_def_domain_type(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  const char *v4; // x19
  int v5; // w8
  __int64 result; // x0
  const char *v7; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v8[11]; // [xsp+8h] [xbp-58h] BYREF

  v8[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 744);
  v7 = nullptr;
  memset(v8, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "qcom,iommu-group", 0, 0, 0, v8) || (v3 = v8[0]) == 0 )
    v3 = *(_QWORD *)(a1 + 744);
  if ( (unsigned int)of_property_read_string(v3, "qcom,iommu-dma", &v7) )
  {
    v4 = "default";
    v7 = "default";
  }
  else
  {
    v4 = v7;
  }
  if ( !strcmp(v4, "fastmap") || !strcmp(v4, "bypass") )
  {
    result = 1;
  }
  else
  {
    v5 = strcmp(v4, "atomic");
    result = 3;
    if ( v5 )
    {
      if ( !strcmp(v4, "disabled") )
        result = 4;
      else
        result = 3;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
