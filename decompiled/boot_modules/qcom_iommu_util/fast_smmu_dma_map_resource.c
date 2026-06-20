__int64 __fastcall fast_smmu_dma_map_resource(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v10; // x22
  __int64 lock_irqsave; // x1
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x22
  unsigned __int64 v15; // x23
  __int64 v16; // x25
  __int64 v17; // x24
  int v18; // w0
  __int64 v19; // x19

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v10 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v12 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v13 = *(_QWORD *)(v12 - 128);
          if ( v13 <= v10 )
            break;
          v12 = *(_QWORD *)(v12 + 16);
          if ( !v12 )
            goto LABEL_8;
        }
        if ( v13 >= v10 )
          break;
        v12 = *(_QWORD *)(v12 + 8);
        if ( !v12 )
          goto LABEL_8;
      }
      v14 = v12 - 136;
    }
    else
    {
LABEL_8:
      v14 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v14 = -22;
  }
  v15 = ((a3 + (a2 & 0xFFF) - 1) | 0xFFF) + 1;
  v16 = raw_spin_lock_irqsave(v14 + 104);
  v17 = _fast_smmu_alloc_iova(v14, v15);
  raw_spin_unlock_irqrestore(v14 + 104, v16);
  if ( v17 == -1 )
    return -1;
  v18 = qcom_dma_info_to_prot(a4, 0, a5);
  if ( (unsigned int)iommu_map(*(_QWORD *)(v14 + 8), v17, a2 & 0xFFFFFFFFFFFFF000LL, v15, v18 | 0x10u, 2080) )
  {
    v19 = raw_spin_lock_irqsave(v14 + 104);
    _bitmap_clear(*(_QWORD *)(v14 + 56), (unsigned __int64)(v17 - *(_QWORD *)(v14 + 24)) >> 12, v15 >> 12);
    *(_BYTE *)(v14 + 80) = 1;
    raw_spin_unlock_irqrestore(v14 + 104, v19);
    return -1;
  }
  return v17 + (a2 & 0xFFF);
}
