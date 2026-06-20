__int64 __fastcall gen8_gmu_load_fw(__int64 a1)
{
  __int64 **v1; // x22
  __int64 *v2; // x8
  __int64 v3; // x9
  unsigned int *v4; // x25
  __int64 v5; // x21
  __int64 v7; // x0
  __int64 v8; // x3
  __int64 v9; // x1
  unsigned int *v10; // x20
  int vma_block; // w0
  __int64 memdesc; // x0

  v1 = (__int64 **)(a1 - 1816);
  v2 = *(__int64 **)(a1 - 1816);
  v3 = *v2;
  v4 = (unsigned int *)v2[1];
  if ( v4 >= (unsigned int *)((char *)v4 + *v2) )
  {
LABEL_14:
    __dsb(0xEu);
    return 0;
  }
  v5 = *(_QWORD *)(a1 + 1544);
  while ( 1 )
  {
    v10 = v4 + 4;
    if ( !v4[1] )
      goto LABEL_6;
    vma_block = gmu_core_find_vma_block(a1, *v4);
    if ( vma_block < 0 )
    {
      dev_err(v5 + 16, "Unknown block in GMU FW addr:0x%x size:0x%x\n", *v4, v4[1]);
      return 4294967274LL;
    }
    if ( vma_block != 2 )
      break;
    v7 = a1 + 13200;
    v8 = v4[1] >> 2;
    v9 = ((*v4 - *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 48LL)) >> 2) + 115712;
LABEL_4:
    kgsl_regmap_bulk_write(v7, v9, v4 + 4, v8);
LABEL_5:
    v2 = *v1;
    v3 = **v1;
    v10 = (unsigned int *)((char *)v10 + v4[1]);
LABEL_6:
    v4 = v10;
    if ( (unsigned __int64)v10 >= v2[1] + v3 )
      goto LABEL_14;
  }
  if ( !vma_block )
  {
    v7 = a1 + 13200;
    v8 = v4[1] >> 2;
    v9 = ((*v4 - **(_DWORD **)(a1 + 8224)) >> 2) + 111616;
    goto LABEL_4;
  }
  memdesc = gmu_core_find_memdesc(a1, *v4, v4[1]);
  if ( memdesc )
  {
    memcpy((void *)(*(_QWORD *)(memdesc + 8) + *v4 - *(_DWORD *)(memdesc + 184)), v4 + 4, v4[1]);
    goto LABEL_5;
  }
  dev_err(v5 + 16, "No backing memory for GMU FW block addr:0x%x size:0x%x\n", *v4, v4[1]);
  return 4294967274LL;
}
