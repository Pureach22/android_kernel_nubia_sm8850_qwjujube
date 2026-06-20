__int64 __fastcall atomic_pool_expand(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v5; // w9
  unsigned int v6; // w19
  __int64 v7; // x2
  __int64 v8; // x0
  __int64 v9; // x9
  __int64 v10; // x21
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x10
  _QWORD *v13; // x9
  unsigned __int64 v14; // x11
  bool v15; // cf
  unsigned __int64 v16; // x11
  __int64 result; // x0
  __int64 v18; // x22
  __int64 v19; // x22
  __int64 v20; // x2
  __int64 v21; // x0
  unsigned __int64 v22; // x23
  unsigned int v23; // w20

  _ReadStatusReg(SP_EL0);
  v5 = 64 - __clz((unsigned __int64)(a2 - 1) >> 12);
  if ( v5 >= 9 )
    v5 = 9;
  if ( (unsigned __int64)(a2 - 1) >= 0x1000 )
    v6 = v5;
  else
    v6 = 0;
  while ( !qcom_dma_contiguous_default_area )
  {
    v8 = _alloc_pages_noprof(a3, v6, 0, 0);
    if ( v8 )
      goto LABEL_15;
LABEL_13:
    if ( --v6 == -1 )
      return 4294967284LL;
  }
  if ( v6 >= 8 )
    v7 = 8;
  else
    v7 = v6;
  v8 = cma_alloc(qcom_dma_contiguous_default_area, 1 << v6, v7, 0);
  if ( !v8 )
    goto LABEL_13;
LABEL_15:
  v9 = *(_QWORD *)(qcom_dma_iommu_dev + 664);
  v10 = 1 << (v6 + 12);
  v11 = (v8 + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
  if ( v9 )
  {
    v12 = *(_QWORD *)(v9 + 16);
    if ( v12 )
    {
      v13 = (_QWORD *)(v9 + 8);
      while ( 1 )
      {
        v14 = *(v13 - 1);
        v15 = v11 >= v14;
        v16 = v11 - v14;
        if ( v15 && v16 < v12 )
          break;
        v12 = v13[4];
        v13 += 3;
        if ( !v12 )
          goto LABEL_23;
      }
      v11 = *v13 + v16;
    }
    else
    {
LABEL_23:
      v11 = -1;
    }
  }
  if ( (*(_BYTE *)(qcom_dma_iommu_dev + 844) & 0x40) == 0 )
  {
    v18 = v8;
    _dma_sync_single_for_device(qcom_dma_iommu_dev, v11, v10, 1);
    v8 = v18;
  }
  v19 = v8;
  if ( arm64_use_ng_mappings )
    v20 = 0x68000000000F0BLL;
  else
    v20 = 0x6800000000070BLL;
  v21 = qcom_dma_common_contiguous_remap(v8, v10, v20);
  if ( v21 )
  {
    v22 = v21;
    result = gen_pool_add_owner(
               a1,
               v21,
               (v19 + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6,
               v10,
               0xFFFFFFFFLL,
               0);
    if ( (_DWORD)result )
    {
      v23 = result;
      qcom_dma_common_free_remap(v22);
      goto LABEL_33;
    }
    current_pool_size += v10;
  }
  else
  {
    v23 = -12;
LABEL_33:
    if ( (cma_release(qcom_dma_contiguous_default_area, v19, 1 << v6) & 1) == 0 )
      _free_pages(v19, v6);
    return v23;
  }
  return result;
}
