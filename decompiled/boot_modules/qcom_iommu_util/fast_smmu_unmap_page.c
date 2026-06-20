__int64 __fastcall fast_smmu_unmap_page(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned int a4, int a5)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v11; // x24
  __int64 lock_irqsave; // x1
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x24
  unsigned __int64 v16; // x25
  int v17; // w8
  unsigned __int64 v18; // x0
  __int64 v19; // x20

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
  }
  else
  {
    v15 = -22;
  }
  v16 = a3 + (a2 & 0xFFF) + 4095;
  if ( (a5 & 0x8000) == 0 )
  {
    if ( (a5 & 0x10000) != 0 )
    {
      LOBYTE(v17) = 0;
      if ( (a5 & 0x20) != 0 )
        goto LABEL_21;
    }
    else
    {
      v17 = (*(unsigned __int8 *)(a1 + 844) >> 5) & 1;
      if ( (a5 & 0x20) != 0 )
        goto LABEL_21;
    }
    if ( (v17 & 1) == 0 )
    {
      v18 = av8l_fast_iova_to_phys_public(*(_QWORD *)(v15 + 96), a2);
      if ( !v18 )
        __break(0x800u);
      qcom_arch_sync_dma_for_cpu(v18, a3, a4);
    }
  }
LABEL_21:
  v19 = raw_spin_lock_irqsave(v15 + 104);
  if ( av8l_fast_unmap_public(*(_QWORD *)(v15 + 96), a2, v16 & 0xFFFFFFFFFFFFF000LL) )
  {
    _bitmap_clear(*(_QWORD *)(v15 + 56), (a2 - *(_QWORD *)(v15 + 24)) >> 12, v16 >> 12);
    *(_BYTE *)(v15 + 80) = 1;
  }
  return raw_spin_unlock_irqrestore(v15 + 104, v19);
}
