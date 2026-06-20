__int64 __fastcall smmu_alloc_and_map_for_drv(_QWORD *a1, __int64 *a2, unsigned __int64 a3, __int64 *a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x8
  _QWORD *v15; // x24
  unsigned int v16; // w25
  __int64 v17; // x26
  __int64 v18; // x3
  __int64 v19; // x4

  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v15 = a1;
    v16 = a5;
    v17 = v5;
    printk(&unk_1E83A, "smmu_alloc_and_map_for_drv", 126, a4, a5);
    a1 = v15;
    v5 = v17;
    a5 = v16;
    if ( v15 )
      goto LABEL_3;
LABEL_14:
    printk(&unk_19CD1, "smmu_alloc_and_map_for_drv", 129, v5, a5);
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_14;
LABEL_3:
  if ( !a4 || !a2 || !*a1 )
    goto LABEL_14;
  if ( a3 >= 0x3D0901 )
  {
    printk(&unk_1B732, "smmu_alloc_and_map_for_drv", 135, v5, a3);
    return 4294967274LL;
  }
  else if ( (_DWORD)a5 == 1 )
  {
    v9 = alloc_pages_exact_noprof(a3, 3264);
    *a4 = v9;
    if ( v9 )
    {
      v10 = v9 << 8 >> 8;
      v11 = (unsigned __int64)(v10 + 0x8000000000LL) >> 38;
      v12 = memstart_addr + v10 + 0x8000000000LL;
      v13 = v10 - kimage_voffset;
      if ( !v11 )
        v13 = v12;
      *a2 = v13;
      _memset_io(*a4, 0, a3);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      {
        printk(&unk_1D333, "smmu_alloc_and_map_for_drv", 154, *a2, a3);
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1C28B, "smmu_alloc_and_map_for_drv", 156, v18, v19);
      }
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_1DBFB, "smmu_alloc_and_map_for_drv", 142, v5, a5);
    return 4294967274LL;
  }
}
