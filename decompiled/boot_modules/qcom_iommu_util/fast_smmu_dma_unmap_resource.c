__int64 __fastcall fast_smmu_dma_unmap_resource(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v6; // x21
  __int64 lock_irqsave; // x1
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x21
  unsigned __int64 v11; // x20
  __int64 v12; // x0
  unsigned __int64 v13; // x8
  __int64 v14; // x19

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v6 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v8 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = *(_QWORD *)(v8 - 128);
          if ( v9 <= v6 )
            break;
          v8 = *(_QWORD *)(v8 + 16);
          if ( !v8 )
            goto LABEL_8;
        }
        if ( v9 >= v6 )
          break;
        v8 = *(_QWORD *)(v8 + 8);
        if ( !v8 )
          goto LABEL_8;
      }
      v10 = v8 - 136;
    }
    else
    {
LABEL_8:
      v10 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v10 = -22;
  }
  v11 = ((a3 + (a2 & 0xFFF) - 1) | 0xFFF) + 1;
  iommu_unmap(*(_QWORD *)(v10 + 8), a2 & 0xFFFFFFFFFFFFF000LL, v11);
  v12 = raw_spin_lock_irqsave(v10 + 104);
  v13 = a2 - *(_QWORD *)(v10 + 24);
  v14 = v12;
  _bitmap_clear(*(_QWORD *)(v10 + 56), v13 >> 12, v11 >> 12);
  *(_BYTE *)(v10 + 80) = 1;
  return raw_spin_unlock_irqrestore(v10 + 104, v14);
}
