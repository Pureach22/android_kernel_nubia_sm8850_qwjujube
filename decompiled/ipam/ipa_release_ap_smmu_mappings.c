char *__fastcall ipa_release_ap_smmu_mappings(
        unsigned int a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        float a6)
{
  char *result; // x0
  char v8; // b26
  char *v9; // x19
  __int64 v10; // x9
  __int64 v11; // x20
  __int64 v12; // x22
  unsigned __int64 v14; // x26
  char *v15; // x25
  unsigned int v16; // w27

  result = ipa3_get_smmu_ctx(0, a2, a3, a4, a5, a6);
  v9 = result;
  if ( a1 <= 0x85 && (a1 & 1) != 0 )
  {
    result = (char *)ipa_get_wdi_version();
    v11 = 8;
    if ( (int)result <= 1 )
      v12 = 10;
    else
      v12 = 11;
  }
  else
  {
    v10 = 32263;
    if ( (*(_BYTE *)(ipa3_ctx + 32263) & 1) != 0 )
    {
      v11 = 0;
      v12 = 3;
    }
    else
    {
      result = (char *)ipa_get_wdi_version();
      v11 = 0;
      if ( (int)result <= 1 )
        v12 = 1;
      else
        v12 = 3;
    }
  }
  do
  {
    if ( ((16 * v11) | 0xCuLL) > 0x140 )
      goto LABEL_26;
    v14 = 16 * v11;
    v15 = (char *)&wdi_res + 16 * v11;
    if ( v15[12] == 1 )
    {
      if ( (v14 | 8) > 0x140 )
        goto LABEL_26;
      if ( *((_DWORD *)v15 + 2) )
      {
        v16 = 0;
        while ( v14 <= 0x13F )
        {
          iommu_unmap(
            *((_QWORD *)v9 + 2),
            *(_QWORD *)(*(_QWORD *)v15 + 32LL * (int)v16 + 8),
            *(_QWORD *)(*(_QWORD *)v15 + 32LL * (int)v16 + 16));
          ++v16;
          v10 = (unsigned int)(*(_DWORD *)(ipa3_ctx + 43320) - 1);
          *(_DWORD *)(ipa3_ctx + 43320) = v10;
          if ( v16 >= *((_DWORD *)v15 + 2) )
            goto LABEL_12;
        }
LABEL_26:
        __break(1u);
        *(_BYTE *)(v10 + 3022) = v8;
        return (char *)ipa_connect_wdi_pipe();
      }
LABEL_12:
      if ( v14 > 0x13F )
        goto LABEL_26;
      result = (char *)kfree(*(_QWORD *)v15);
      *(_QWORD *)v15 = 0;
      v15[12] = 0;
    }
  }
  while ( v11++ != v12 );
  if ( !*(_DWORD *)(ipa3_ctx + 43320) )
    *((_QWORD *)v9 + 3) = *((unsigned int *)v9 + 10);
  return result;
}
