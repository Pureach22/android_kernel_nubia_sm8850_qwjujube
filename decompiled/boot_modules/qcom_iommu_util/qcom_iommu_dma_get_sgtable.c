__int64 __fastcall qcom_iommu_dma_get_sgtable(
        __int64 a1,
        unsigned __int64 **a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5)
{
  _QWORD *v9; // x22
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x21
  __int64 result; // x0
  unsigned __int64 *v14; // x8
  __int64 v15; // x1

  if ( (is_vmalloc_addr(a3) & 1) != 0 )
  {
    mutex_lock(&rbtree_lock);
    v9 = (_QWORD *)*root;
    if ( *root )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v10 = v9[3];
          if ( v10 <= a3 )
            break;
          v9 = (_QWORD *)v9[2];
          if ( !v9 )
            goto LABEL_8;
        }
        if ( v10 >= a3 )
          break;
        v9 = (_QWORD *)v9[1];
        if ( !v9 )
          goto LABEL_8;
      }
      mutex_unlock(&rbtree_lock);
      v15 = v9[4];
      if ( v15 )
        return sg_alloc_table_from_pages_segment(
                 a2,
                 v15,
                 (unsigned __int64)(a5 + 4095) >> 12,
                 0,
                 a5,
                 0xFFFFFFFFLL,
                 3264);
    }
    else
    {
LABEL_8:
      mutex_unlock(&rbtree_lock);
    }
    v11 = vmalloc_to_page(a3);
  }
  else
  {
    v11 = ((unsigned __int64)(((__int64)(a3 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
  }
  result = sg_alloc_table(a2, 1, 3264);
  if ( !(_DWORD)result )
  {
    if ( (v11 & 3) != 0 )
    {
      __break(0x800u);
      __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
      return qcom_dma_iommu_is_ready();
    }
    else
    {
      v14 = *a2;
      result = 0;
      *v14 = **a2 & 3 | v11;
      *((_DWORD *)v14 + 2) = 0;
      *((_DWORD *)v14 + 3) = (a5 + 4095) & 0xFFFFF000;
    }
  }
  return result;
}
