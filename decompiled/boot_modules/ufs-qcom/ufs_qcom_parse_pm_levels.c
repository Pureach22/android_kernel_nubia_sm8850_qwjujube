__int64 __fastcall ufs_qcom_parse_pm_levels(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned int v4; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = *(_QWORD *)(result + 184);
    v2 = *(_QWORD *)(*(_QWORD *)(result + 64) + 744LL);
    v4 = 7;
    v5 = 7;
    if ( v2 && (*(_BYTE *)(v1 + 418) & 1) == 0 )
    {
      v3 = result;
      if ( (of_property_read_variable_u32_array(v2, "rpm-level", &v5, 1, 0) & 0x80000000) == 0 && v5 <= 6 )
        *(_DWORD *)(v3 + 88) = v5;
      result = of_property_read_variable_u32_array(v2, "spm-level", &v4, 1, 0);
      if ( (result & 0x80000000) == 0 && v4 <= 6 )
        *(_DWORD *)(v3 + 92) = v4;
      *(_BYTE *)(v1 + 418) = 1;
    }
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    __break(0x800u);
    return ufs_qcom_parse_limits(0);
  }
  return result;
}
