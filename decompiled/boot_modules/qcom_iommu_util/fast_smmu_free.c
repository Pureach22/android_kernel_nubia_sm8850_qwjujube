__int64 __fastcall fast_smmu_free(__int64 a1, __int64 a2, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v9; // x23
  __int64 lock_irqsave; // x1
  __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x24
  unsigned __int64 v14; // x23
  __int64 v15; // x22
  __int64 result; // x0
  __int64 pages; // x0
  __int64 *v18; // x22
  __int64 v19; // x19
  __int64 *v20; // x20
  __int64 v21; // t1
  unsigned __int64 v22; // x8
  __int64 v23; // x21

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v9 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v11 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v12 = *(_QWORD *)(v11 - 128);
          if ( v12 <= v9 )
            break;
          v11 = *(_QWORD *)(v11 + 16);
          if ( !v11 )
            goto LABEL_8;
        }
        if ( v12 >= v9 )
          break;
        v11 = *(_QWORD *)(v11 + 8);
        if ( !v11 )
          goto LABEL_8;
      }
      v13 = v11 - 136;
    }
    else
    {
LABEL_8:
      v13 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v13 = -22;
  }
  v14 = a2 + 4095;
  v15 = raw_spin_lock_irqsave(v13 + 104);
  if ( !av8l_fast_unmap_public(*(_QWORD *)(v13 + 96), a4, v14 & 0xFFFFFFFFFFFFF000LL) )
    return raw_spin_unlock_irqrestore(v13 + 104, v15);
  _bitmap_clear(*(_QWORD *)(v13 + 56), (a4 - *(_QWORD *)(v13 + 24)) >> 12, (unsigned int)(v14 >> 12));
  *(_BYTE *)(v13 + 80) = 1;
  raw_spin_unlock_irqrestore(v13 + 104, v15);
  result = qcom_dma_free_from_pool(a1, a3, v14 & 0xFFFFFFFFFFFFF000LL);
  if ( (result & 1) == 0 )
  {
    result = is_vmalloc_addr(a3);
    if ( (result & 1) != 0 )
    {
      pages = qcom_dma_common_find_pages(a3);
      if ( pages )
      {
        v18 = (__int64 *)pages;
        qcom_dma_common_free_remap(a3);
        if ( (int)(v14 >> 12) >= 1 )
        {
          v19 = (v14 >> 12) & 0x7FFFFFFF;
          v20 = v18;
          do
          {
            v21 = *v20++;
            _free_pages(v21, 0);
            --v19;
          }
          while ( v19 );
        }
        return kvfree(v18);
      }
      v23 = vmalloc_to_page(a3);
      result = qcom_dma_common_free_remap(a3);
      if ( !v23 )
        return result;
    }
    else
    {
      v22 = (unsigned __int64)(((__int64)(a3 << 8) >> 8) + 0x8000000000LL) >> 12;
      v23 = (v22 << 6) - 0x140000000LL;
      if ( v22 << 6 == 0x140000000LL )
        return result;
    }
    return qcom_dma_free_contiguous(a1, v23, v14 & 0xFFFFFFFFFFFFF000LL);
  }
  return result;
}
