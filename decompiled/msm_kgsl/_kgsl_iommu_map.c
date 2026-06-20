__int64 __fastcall kgsl_iommu_map(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w10
  __int64 v6; // x1
  unsigned int v7; // w21
  __int64 v8; // x2
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x1
  __int64 v13; // x28
  __int64 v14; // x8
  unsigned __int64 v15; // x1
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x26
  __int64 v18; // x23
  __int64 v19; // x27
  unsigned __int64 v20; // x8
  __int64 i; // x25
  __int64 v22; // x8
  unsigned __int64 v23; // x1
  unsigned __int64 v24; // [xsp+8h] [xbp-28h]
  __int64 v25; // [xsp+18h] [xbp-18h] BYREF
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_QWORD *)(a3 + 72) & 0x1000000LL) != 0 )
    v5 = 9;
  else
    v5 = 11;
  v6 = *(_QWORD *)(a3 + 96);
  if ( (*(_DWORD *)(a3 + 48) & 0x80) != 0 )
    v7 = v5 & 0xFFFFFFE7
       | (*(_DWORD *)(a3 + 48) >> 1) & 0x20
       | (4 * ((unsigned int)*(_QWORD *)(a3 + 72) >> 31)) & 0xFFFFFFE7;
  else
    v7 = v5 | (*(_DWORD *)(a3 + 48) >> 1) & 0x20 | (4 * ((unsigned int)*(_QWORD *)(a3 + 72) >> 31));
  if ( !v6 )
  {
    v14 = *(_QWORD *)(a3 + 24);
    if ( (v14 & 0x1000000000000LL) != 0 )
      v15 = v14 | 0xFFFF000000000000LL;
    else
      v15 = *(_QWORD *)(a3 + 24);
    v13 = kgsl_mmu_map_sg(a2, v15, **(_QWORD **)(a3 + 56), *(unsigned int *)(*(_QWORD *)(a3 + 56) + 12LL), v7);
    if ( !v13 )
      goto LABEL_44;
    goto LABEL_18;
  }
  v8 = *(unsigned int *)(a3 + 104);
  v9 = *(_QWORD *)(a3 + 40);
  v25 = 0;
  v26 = 0;
  result = sg_alloc_table_from_pages_segment(&v25, v6, v8, 0, v9, 0xFFFFFFFFLL, 3264);
  if ( !(_DWORD)result )
  {
    v11 = *(_QWORD *)(a3 + 24);
    if ( (v11 & 0x1000000000000LL) != 0 )
      v12 = v11 | 0xFFFF000000000000LL;
    else
      v12 = *(_QWORD *)(a3 + 24);
    v13 = kgsl_mmu_map_sg(a2, v12, v25, HIDWORD(v26), v7);
    sg_free_table(&v25);
    if ( !v13 )
    {
LABEL_44:
      result = 4294967284LL;
      goto LABEL_45;
    }
LABEL_18:
    if ( (*(_DWORD *)(a3 + 48) & 1) != 0 )
      v16 = (*(_QWORD *)(a3 + 40) + 0x1FFFLL) & 0xFFFFFFFFFFFFF000LL;
    else
      v16 = *(_QWORD *)(a3 + 40);
    v17 = v16 - v13;
    if ( v16 == v13 )
    {
LABEL_22:
      result = 0;
      goto LABEL_45;
    }
    if ( a3 && (*(_DWORD *)(a3 + 48) & 0x10) != 0 )
    {
      v18 = kgsl_secure_guard_page;
      if ( !kgsl_secure_guard_page )
      {
        v18 = kgsl_alloc_secure_page();
        kgsl_secure_guard_page = v18;
        if ( !v18 )
        {
LABEL_39:
          if ( a2 )
          {
            v22 = *(_QWORD *)(a3 + 24);
            if ( (v22 & 0x1000000000000LL) != 0 )
              v23 = v22 | 0xFFFF000000000000LL;
            else
              v23 = *(_QWORD *)(a3 + 24);
            iommu_unmap(a2, v23, v13);
          }
          goto LABEL_44;
        }
      }
    }
    else
    {
      v18 = kgsl_guard_page;
      if ( !kgsl_guard_page )
      {
        v18 = _alloc_pages_noprof(69058, 0, 0, 0);
        kgsl_guard_page = v18;
        if ( !v18 )
          goto LABEL_39;
      }
    }
    v19 = *(_QWORD *)(a3 + 24) + v13;
    v20 = v19 | 0xFFFF000000000000LL;
    if ( (v19 & 0x1000000000000LL) == 0 )
      v20 = *(_QWORD *)(a3 + 24) + v13;
    if ( v17 )
    {
      v24 = v20;
      for ( i = 0; i != v17; i += 4096 )
      {
        if ( (unsigned int)iommu_map(
                             a2,
                             v19 + i,
                             ((v18 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL,
                             4096,
                             v7 & 0x2D,
                             3264) )
        {
          iommu_unmap(a2, v24, i);
          goto LABEL_39;
        }
      }
      if ( i )
        goto LABEL_22;
    }
    goto LABEL_39;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
