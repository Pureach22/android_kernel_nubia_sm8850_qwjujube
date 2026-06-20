__int64 __fastcall ipa_wigig_read_smmu_status(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x22
  int v9; // w0
  int v10; // w9
  int v11; // w23
  __int64 v12; // x0
  int v13; // w0
  int v14; // w0
  __int64 v15; // x19

  v7 = _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 4096);
  v8 = v7;
  if ( !v7 )
    return -12;
  if ( ipa_wigig_ctx )
  {
    if ( *(_BYTE *)(ipa_wigig_ctx + 908) == 1 )
    {
      v9 = scnprintf(v7, 4096, "SMMU enabled\n");
      v10 = 4096 - v9;
      v11 = v9;
      v12 = v8 + v9;
      if ( *(_BYTE *)(ipa_wigig_ctx + 909) == 1 )
        v13 = scnprintf(v12, v10, "CB shared\n");
      else
        v13 = scnprintf(v12, v10, "CB not shared\n");
      v14 = v13 + v11;
    }
    else
    {
      v14 = scnprintf(v7, 4096, "SMMU in S1 bypass\n");
    }
  }
  else
  {
    v14 = scnprintf(v7, 4096, "IPA WIGIG not initialized\n");
  }
  v15 = simple_read_from_buffer(a2, a3, a4, v8, v14);
  kfree(v8);
  return v15;
}
