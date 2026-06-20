__int64 __fastcall iommu_debug_functional_arm_dma_api_show(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w2
  __int64 *v5; // x21
  int v6; // w22
  int v7; // w0
  __int64 v8; // x1
  int v9; // w24
  _QWORD *v10; // x25
  __int64 v11; // x1
  __int64 v12; // t1
  int v13; // w0
  int v14; // w22
  _QWORD *v15; // x23
  unsigned int v16; // w26
  __int64 v17; // x1
  const char *v18; // x1
  __int64 v19; // x1
  __int64 v20; // [xsp+0h] [xbp-40h] BYREF
  __int64 v21; // [xsp+8h] [xbp-38h]
  _QWORD v22[6]; // [xsp+10h] [xbp-30h] BYREF

  v22[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v22[0] = 4096;
  v22[1] = 0x10000;
  v22[2] = 0x200000;
  v22[3] = 12582912;
  v22[4] = 0;
  mutex_lock(v2 + 56);
  if ( !iommu_debug_usecase_reset(v2) )
  {
    mutex_unlock(v2 + 56);
    v3 = -22;
    goto LABEL_3;
  }
  v5 = *(__int64 **)(v2 + 32);
  v6 = _functional_dma_api_alloc_test(v5, a1);
  v7 = _functional_dma_api_basic_test(v5, a1);
  v8 = v5[14];
  if ( !v8 )
    v8 = *v5;
  v9 = v7 | v6;
  printk(&unk_CBA4, v8);
  seq_printf(a1, "Map SG DMA API test");
  v10 = v22;
  v11 = 4096;
  do
  {
    v20 = 0;
    v21 = 0;
    v13 = ((__int64 (__fastcall *)(__int64 *, __int64))iommu_debug_build_phoney_sg_table)(&v20, v11);
    if ( v13 )
    {
      v14 = v13;
      seq_write(a1, "couldn't build phoney sg table! bailing...\n", 43);
      goto LABEL_22;
    }
    if ( (unsigned int)dma_map_sg_attrs(v5, v20, (unsigned int)v21, 0, 0) )
    {
      v14 = iommu_debug_check_mapping_sg_flags(
              v5,
              v20,
              ((unsigned int)(*(_DWORD *)(v20 + 8) + *(_DWORD *)(v20 + 12) + 4095) >> 12) - 1,
              (unsigned int)v21,
              1,
              0);
      dma_unmap_sg_attrs(v5, v20, (unsigned int)v21, 0, 0);
      if ( !(_DWORD)v21 )
        goto LABEL_8;
    }
    else
    {
      v14 = -22;
      if ( !(_DWORD)v21 )
        goto LABEL_8;
    }
    v15 = (_QWORD *)v20;
    v16 = 0;
    do
    {
      _free_pages(*v15 & 0xFFFFFFFFFFFFFFFCLL, 0);
      ++v16;
      v15 = (_QWORD *)sg_next(v15);
    }
    while ( v16 < (unsigned int)v21 );
LABEL_8:
    sg_free_table(&v20);
    v12 = v10[1];
    ++v10;
    v11 = v12;
  }
  while ( v12 );
  if ( !v14 )
  {
    v17 = v5[14];
    if ( !v17 )
      v17 = *v5;
    printk(&unk_CFA4, v17);
    v14 = 0;
    v18 = "  -> SUCCEEDED\n";
    goto LABEL_25;
  }
LABEL_22:
  v19 = v5[14];
  if ( !v19 )
    v19 = *v5;
  printk(&unk_D054, v19);
  v18 = "  -> FAILED\n";
LABEL_25:
  seq_printf(a1, v18);
  mutex_unlock(v2 + 56);
  v3 = v9 | v14;
  if ( !(v9 | v14) )
  {
    seq_write(a1, "SUCCESS\n", 8);
    goto LABEL_4;
  }
LABEL_3:
  seq_printf(a1, "FAIL %d\n", v3);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return 0;
}
