__int64 __fastcall arm_smmu_of_xlate(__int64 a1, __int64 a2)
{
  int v2; // w8
  int v3; // w19
  int v4; // w8
  __int64 v5; // x20
  int variable_u32_array; // w8
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a2 + 8);
  v8[0] = 0;
  if ( v2 < 1 )
  {
    v3 = 0;
  }
  else
  {
    v3 = *(unsigned __int16 *)(a2 + 12);
    LODWORD(v8[0]) = v3;
    if ( v2 != 1 )
    {
      v4 = *(_DWORD *)(a2 + 16);
LABEL_7:
      LODWORD(v8[0]) = v3 | (v4 << 16);
      goto LABEL_8;
    }
  }
  v5 = a1;
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)a2, "stream-match-mask", (char *)v8 + 4, 1, 0);
  a1 = v5;
  if ( (variable_u32_array & 0x80000000) == 0 )
  {
    v4 = HIDWORD(v8[0]);
    goto LABEL_7;
  }
LABEL_8:
  result = iommu_fwspec_add_ids(a1, v8, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
