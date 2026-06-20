char *__fastcall ipa_release_uc_smmu_mappings(
        unsigned int a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        float a6)
{
  char *result; // x0
  __int64 v8; // x13
  char *v9; // x19
  __int64 v10; // x22
  __int64 v11; // x20
  unsigned __int64 v12; // x26
  char *v13; // x25
  unsigned int v14; // w27

  result = ipa3_get_smmu_ctx(3u, a2, a3, a4, a5, a6);
  v9 = result;
  if ( a1 <= 0x85 && (a1 & 1) != 0 )
  {
    v10 = 11;
    v11 = 8;
  }
  else
  {
    v11 = 0;
    if ( *(_BYTE *)(ipa3_ctx + 32263) )
      v10 = 4;
    else
      v10 = 2;
  }
  do
  {
    if ( ((16 * v11) | 0xCuLL) > 0x140 )
      goto LABEL_22;
    v12 = 16 * v11;
    v13 = (char *)&wdi_res + 16 * v11;
    if ( v13[12] == 1 )
    {
      if ( (v12 | 8) > 0x140 )
        goto LABEL_22;
      if ( *((_DWORD *)v13 + 2) )
      {
        v14 = 0;
        while ( v12 <= 0x13F )
        {
          result = (char *)iommu_unmap(
                             *((_QWORD *)v9 + 2),
                             *(_QWORD *)(*(_QWORD *)v13 + 32LL * (int)v14 + 8),
                             *(_QWORD *)(*(_QWORD *)v13 + 32LL * (int)v14 + 16));
          ++v14;
          --*(_DWORD *)(ipa3_ctx + 43320);
          if ( v14 >= *((_DWORD *)v13 + 2) )
            goto LABEL_8;
        }
LABEL_22:
        __break(1u);
        *(_QWORD *)result = v8;
        return (char *)ipa3_disconnect_gsi_wdi_pipe(result + 217);
      }
LABEL_8:
      if ( v12 > 0x13F )
        goto LABEL_22;
      result = (char *)kfree(*(_QWORD *)v13);
      *(_QWORD *)v13 = 0;
      v13[12] = 0;
    }
    ++v11;
  }
  while ( v11 != v10 );
  if ( !*(_DWORD *)(ipa3_ctx + 43320) )
    *((_QWORD *)v9 + 3) = *((unsigned int *)v9 + 10);
  return result;
}
