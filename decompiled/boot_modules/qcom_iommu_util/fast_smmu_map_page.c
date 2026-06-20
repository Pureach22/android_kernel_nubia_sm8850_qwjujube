__int64 __fastcall fast_smmu_map_page(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v13; // x20
  __int64 lock_irqsave; // x1
  __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x20
  unsigned __int64 v18; // x24
  __int64 v19; // x27
  int v20; // w25
  char v21; // w23
  __int64 v22; // x21
  unsigned __int64 v23; // x0
  __int64 v24; // x22

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v13 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v15 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = *(_QWORD *)(v15 - 128);
          if ( v16 <= v13 )
            break;
          v15 = *(_QWORD *)(v15 + 16);
          if ( !v15 )
            goto LABEL_8;
        }
        if ( v16 >= v13 )
          break;
        v15 = *(_QWORD *)(v15 + 8);
        if ( !v15 )
          goto LABEL_8;
      }
      v17 = v15 - 136;
    }
    else
    {
LABEL_8:
      v17 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v17 = -22;
  }
  v18 = a3 + ((a2 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
  v19 = a4 + (v18 & 0xFFF) + 4095;
  if ( (a6 & 0x8000) != 0 )
  {
    v21 = qcom_dma_info_to_prot(a5, 1, a6);
  }
  else
  {
    if ( (a6 & 0x10000) != 0 )
      LOBYTE(v20) = 0;
    else
      v20 = (*(unsigned __int8 *)(a1 + 844) >> 5) & 1;
    v21 = qcom_dma_info_to_prot(a5, v20, a6);
    if ( (a6 & 0x20) == 0 && (v20 & 1) == 0 )
      qcom_arch_sync_dma_for_device(v18, a4, a5);
  }
  v22 = raw_spin_lock_irqsave(v17 + 104);
  v23 = _fast_smmu_alloc_iova(v17, v19 & 0xFFFFFFFFFFFFF000LL);
  if ( v23 != -1 )
  {
    v24 = v23;
    if ( !(unsigned int)av8l_fast_map_public(
                          *(_QWORD *)(v17 + 96),
                          v23,
                          v18 & 0xFFFFFFFFFFFFF000LL,
                          v19 & 0xFFFFFFFFFFFFF000LL,
                          v21) )
    {
      raw_spin_unlock_irqrestore(v17 + 104, v22);
      return v24 + (v18 & 0xFFF);
    }
    _fast_smmu_free_iova(v17, v24, a4);
  }
  raw_spin_unlock_irqrestore(v17 + 104, v22);
  return -1;
}
