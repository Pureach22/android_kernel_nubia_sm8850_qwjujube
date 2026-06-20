__int64 __fastcall kgsl_iommu_reserve_global_gpuaddr(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v5; // x20
  unsigned int v6; // w21
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x22
  unsigned __int64 v10; // x20
  unsigned int v11; // w8
  __int64 v12; // x21
  int next_zero_area_off; // w0
  int v15; // w21

  if ( *(_QWORD *)(a2 + 24) )
    return 4294967274LL;
  if ( (*(_BYTE *)(a2 + 72) & 8) != 0 )
  {
    result = kgsl_iommu_get_gpuaddr(a1[3], a2);
    if ( (_DWORD)result )
      __break(0x800u);
    return result;
  }
  v5 = *(_QWORD *)(a2 + 40);
  if ( !a1[1634] )
  {
    v6 = a3;
    v7 = a2;
    v8 = _kmalloc_cache_noprof(socinfo_get_partinfo_vulkan_id, 3520, 2880);
    a2 = v7;
    a3 = v6;
    a1[1634] = v8;
    if ( !v8 )
      return 4294967268LL;
  }
  v9 = a2;
  v10 = (v5 + (unsigned __int64)a3) >> 12;
  if ( (*(_DWORD *)(a2 + 48) & 0x100) == 0 )
  {
    v11 = 0;
    goto LABEL_11;
  }
  v11 = (unsigned int)get_random_u32() % (23040 - (int)v10);
  if ( (v11 & 0x80000000) != 0 )
  {
LABEL_15:
    __break(0x800u);
    return 4294967268LL;
  }
LABEL_11:
  v12 = v11;
  while ( 1 )
  {
    next_zero_area_off = bitmap_find_next_zero_area_off(a1[1634], 23040, v12, (unsigned int)v10, 0, 0);
    if ( next_zero_area_off < 23040 )
      break;
    if ( v12-- < 1 )
      goto LABEL_15;
  }
  v15 = next_zero_area_off;
  _bitmap_set(a1[1634], (unsigned int)next_zero_area_off, (unsigned int)v10);
  *(_QWORD *)(v9 + 24) = *(_QWORD *)(a1[2] + 184LL) + (v15 << 12);
  return 0;
}
