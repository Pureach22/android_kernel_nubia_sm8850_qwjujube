__int64 __fastcall _fast_smmu_alloc_contiguous(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 *a3,
        __int16 a4,
        unsigned int a5)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v11; // x22
  __int64 lock_irqsave; // x1
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x22
  int v16; // w25
  char v17; // w0
  unsigned __int64 v18; // x24
  char v19; // w27
  __int64 v20; // x28
  unsigned int v21; // w8
  __int64 v22; // x2
  __int64 result; // x0
  __int64 v24; // x23
  __int64 v25; // x20
  unsigned __int64 v26; // x26
  void *v27; // x21
  __int64 v28; // x0
  unsigned __int64 *v29; // [xsp+8h] [xbp-8h]

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v11 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v13 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v14 = *(_QWORD *)(v13 - 128);
          if ( v14 <= v11 )
            break;
          v13 = *(_QWORD *)(v13 + 16);
          if ( !v13 )
            goto LABEL_8;
        }
        if ( v14 >= v11 )
          break;
        v13 = *(_QWORD *)(v13 + 8);
        if ( !v13 )
          goto LABEL_8;
      }
      v15 = v13 - 136;
    }
    else
    {
LABEL_8:
      v15 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
    if ( (a5 & 0x8000) == 0 )
      goto LABEL_13;
  }
  else
  {
    v15 = -22;
    if ( (a5 & 0x8000) == 0 )
    {
LABEL_13:
      if ( (a5 & 0x10000) != 0 )
        v16 = 0;
      else
        v16 = (*(unsigned __int8 *)(a1 + 844) >> 5) & 1;
      goto LABEL_16;
    }
  }
  v16 = 1;
LABEL_16:
  v17 = qcom_dma_info_to_prot(0, v16, a5);
  v18 = a2 >> 12;
  v19 = v17;
  if ( arm64_use_ng_mappings )
    v20 = 0x68000000000F0BLL;
  else
    v20 = 0x6800000000070BLL;
  v21 = 64 - __clz((a2 - 1) >> 12);
  if ( a2 - 1 >= 0x1000 )
    v22 = v21;
  else
    v22 = 0;
  result = qcom_dma_alloc_from_contiguous(a1, a2 >> 12, v22, (a4 & 0x2000) != 0);
  if ( result )
  {
    v24 = result;
    v29 = a3;
    v25 = raw_spin_lock_irqsave(v15 + 104);
    v26 = _fast_smmu_alloc_iova(v15, a2);
    raw_spin_unlock_irqrestore(v15 + 104, v25);
    if ( v26 == -1 )
    {
LABEL_26:
      qcom_dma_release_from_contiguous(a1, v24, v18);
      return 0;
    }
    if ( (unsigned int)av8l_fast_map_public(
                         *(_QWORD *)(v15 + 96),
                         v26,
                         ((v24 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL,
                         a2,
                         v19) )
    {
LABEL_25:
      _bitmap_clear(*(_QWORD *)(v15 + 56), (v26 - *(_QWORD *)(v15 + 24)) >> 12, (unsigned int)v18);
      *(_BYTE *)(v15 + 80) = 1;
      goto LABEL_26;
    }
    if ( v16 )
    {
      v27 = (void *)(((v24 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL);
    }
    else
    {
      v28 = qcom_dma_common_contiguous_remap(v24, a2, v20);
      if ( !v28 )
      {
        av8l_fast_unmap_public(*(_QWORD *)(v15 + 96), v26, a2);
        goto LABEL_25;
      }
      v27 = (void *)v28;
      qcom_arch_dma_prep_coherent(v24, a2);
    }
    memset(v27, 0, a2);
    *v29 = v26;
    return (__int64)v27;
  }
  return result;
}
