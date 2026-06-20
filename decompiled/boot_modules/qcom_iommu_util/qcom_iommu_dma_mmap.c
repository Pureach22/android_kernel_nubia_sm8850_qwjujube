__int64 __fastcall qcom_iommu_dma_mmap(__int64 a1, _QWORD *a2, unsigned __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x22
  _QWORD *v11; // x23
  unsigned __int64 v12; // x9
  __int64 v13; // x0
  __int64 v14; // x1

  v5 = a2[3];
  v6 = (unsigned __int64)(a5 + 4095) >> 12;
  v7 = a2[10];
  if ( (*(_BYTE *)(a1 + 844) & 0x20) == 0 )
    v5 = v5 & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
  a2[3] = v5;
  if ( v6 <= v7 || v6 - v7 < (a2[1] - *a2) >> 12 )
    return 4294967290LL;
  if ( (is_vmalloc_addr(a3) & 1) != 0 )
  {
    mutex_lock(&rbtree_lock);
    v11 = (_QWORD *)*root;
    if ( *root )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v12 = v11[3];
          if ( v12 <= a3 )
            break;
          v11 = (_QWORD *)v11[2];
          if ( !v11 )
            goto LABEL_13;
        }
        if ( v12 >= a3 )
          break;
        v11 = (_QWORD *)v11[1];
        if ( !v11 )
          goto LABEL_13;
      }
      mutex_unlock(&rbtree_lock);
      v14 = v11[4];
      if ( v14 )
        return vm_map_pages(a2, v14, v6);
    }
    else
    {
LABEL_13:
      mutex_unlock(&rbtree_lock);
    }
    v13 = vmalloc_to_pfn(a3);
  }
  else
  {
    v13 = (__int64)(((__int64)memstart_addr >> 12 << 6)
                  + ((unsigned __int64)(((__int64)(a3 << 8) >> 8) + 0x8000000000LL) >> 6)) >> 6;
  }
  return remap_pfn_range(a2, *a2, v13 + v7, a2[1] - *a2, a2[3]);
}
