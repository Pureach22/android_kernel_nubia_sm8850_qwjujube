__int64 __fastcall a6xx_gmu_load_fw(__int64 a1)
{
  __int64 **v1; // x22
  unsigned int v3; // w9
  __int64 *v4; // x8
  bool v5; // cc
  int v6; // w9
  unsigned int *v7; // x20
  __int64 v10; // x9
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x0
  unsigned int *v14; // x21
  int vma_block; // w0
  __int64 memdesc; // x0

  v1 = (__int64 **)(a1 - 1640);
  v3 = **(_DWORD **)(a1 + 14264) - 615;
  v4 = *(__int64 **)(a1 - 1640);
  v5 = v3 > 0xF;
  v6 = (1 << v3) & 0x801B;
  v7 = (unsigned int *)v4[1];
  if ( !v5 && v6 != 0 )
  {
    if ( (unsigned __int64)*v4 > 0x8000 )
      return 4294967274LL;
    gmu_core_blkwrite(a1, 111616, v4[1]);
    __dsb(0xEu);
    return 0;
  }
  v10 = *v4;
  if ( v7 >= (unsigned int *)((char *)v7 + *v4) )
  {
LABEL_21:
    __dsb(0xEu);
    return 0;
  }
  while ( 1 )
  {
    v14 = v7 + 4;
    if ( !v7[1] )
      goto LABEL_13;
    vma_block = gmu_core_find_vma_block(a1, *v7);
    if ( vma_block < 0 )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unknown block in GMU FW addr:0x%x size:0x%x\n", *v7, v7[1]);
      return 4294967274LL;
    }
    if ( vma_block != 2 )
      break;
    v11 = a1 + 13200;
    v12 = ((*v7 - *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 48LL)) >> 2) + 115712;
LABEL_11:
    v13 = kgsl_regmap_virt(v11, v12);
    _memcpy_toio(v13, v7 + 4, v7[1]);
LABEL_12:
    v4 = *v1;
    v10 = **v1;
    v14 = (unsigned int *)((char *)v14 + v7[1]);
LABEL_13:
    v7 = v14;
    if ( (unsigned __int64)v14 >= v4[1] + v10 )
      goto LABEL_21;
  }
  if ( !vma_block )
  {
    v11 = a1 + 13200;
    v12 = ((*v7 - **(_DWORD **)(a1 + 8224)) >> 2) + 111616;
    goto LABEL_11;
  }
  memdesc = gmu_core_find_memdesc(a1, *v7, v7[1]);
  if ( memdesc )
  {
    memcpy((void *)(*(_QWORD *)(memdesc + 8) + *v7 - *(_DWORD *)(memdesc + 184)), v7 + 4, v7[1]);
    goto LABEL_12;
  }
  dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "No backing memory for GMU FW block addr:0x%x size:0x%x\n", *v7, v7[1]);
  return 4294967274LL;
}
