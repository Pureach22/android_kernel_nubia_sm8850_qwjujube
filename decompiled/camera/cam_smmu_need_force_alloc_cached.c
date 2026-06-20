__int64 __fastcall cam_smmu_need_force_alloc_cached(_BYTE *a1)
{
  char v2; // w25
  __int64 v3; // x7
  __int64 v4; // x8
  int v5; // w9
  unsigned int v6; // w22
  __int64 v7; // x10
  int v8; // w21
  __int64 v10; // x8
  const char *v11; // x5
  __int64 v12; // x4
  unsigned int v13; // [xsp+Ch] [xbp-4h]

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_need_force_alloc_cached",
      503,
      "Invalid arg");
    return 4294967274LL;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    3,
    "cam_smmu_need_force_alloc_cached",
    508,
    "force_cache_allocs=%d",
    (unsigned __int8)byte_3940F8);
  if ( !dword_394060 )
  {
LABEL_19:
    *a1 = byte_3940F8;
    return 0;
  }
  v2 = 0;
  v3 = 0;
  v4 = iommu_cb_set;
  v5 = 0;
  while ( 1 )
  {
    v7 = v4 + 14280LL * v5;
    v8 = v5;
    if ( (*(_BYTE *)(v7 + 80) & 1) != 0 )
      goto LABEL_4;
    v6 = *(_DWORD *)(v7 + 8648);
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    {
      v13 = v3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_need_force_alloc_cached",
        556,
        "[%s] : curr_mode=%d",
        *(const char **)(v7 + 32),
        v6);
      v3 = v13;
      v4 = iommu_cb_set;
      if ( v6 != 1 )
      {
LABEL_10:
        if ( !v6 && byte_3940F8 == 1 )
        {
          v10 = v4 + 14280LL * v8;
          v11 = "[%s] Can't force alloc cache with no coherency";
          v12 = 562;
          goto LABEL_24;
        }
        goto LABEL_15;
      }
    }
    else if ( v6 != 1 )
    {
      goto LABEL_10;
    }
    if ( (byte_3940F8 & 1) == 0 )
      break;
LABEL_15:
    if ( (v2 & 1) == 0 )
    {
      v2 = 1;
      goto LABEL_5;
    }
    if ( v6 != (_DWORD)v3 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_need_force_alloc_cached",
        579,
        "[%s] CBs having different coherency modes final=%d, curr=%d",
        *(_QWORD *)(v4 + 14280LL * v8 + 32));
      return 4294967274LL;
    }
    v2 = 1;
LABEL_4:
    v6 = v3;
LABEL_5:
    v5 = v8 + 1;
    v3 = v6;
    if ( v8 + 1 >= (unsigned int)dword_394060 )
      goto LABEL_19;
  }
  v10 = v4 + 14280LL * v8;
  v11 = "[%s] Must force cache allocs for dma coherent device";
  v12 = 569;
LABEL_24:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_need_force_alloc_cached",
    v12,
    v11,
    *(_QWORD *)(v10 + 32),
    v3);
  return 4294967274LL;
}
