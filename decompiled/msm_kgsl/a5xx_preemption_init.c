unsigned __int64 __fastcall a5xx_preemption_init(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 global; // x8
  __int64 v4; // x20
  unsigned int v5; // w23
  unsigned __int64 *v6; // x24
  unsigned __int64 v13; // x9

  if ( (unsigned int)kgsl_mmu_get_mmutype() )
    return 4294967277LL;
  *(_QWORD *)(a1 + 20544) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 20552) = a1 + 20552;
  *(_QWORD *)(a1 + 20560) = a1 + 20552;
  global = *(_QWORD *)(a1 + 20496);
  *(_QWORD *)(a1 + 20568) = a5xx_preemption_worker;
  if ( !global || global >= 0xFFFFFFFFFFFFF001LL )
  {
    global = kgsl_allocate_global(a1, (int)(*(_DWORD *)(a1 + 19632) << 6), 0, 0, 0, "preemption_counters");
    *(_QWORD *)(a1 + 20496) = global;
  }
  if ( global >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)global;
  if ( *(_DWORD *)(a1 + 19632) )
  {
    v4 = *(_QWORD *)(global + 24);
    v5 = 0;
    v6 = (unsigned __int64 *)(a1 + 14536);
    while ( 1 )
    {
      result = *v6;
      if ( !*v6 || result >= 0xFFFFFFFFFFFFF001LL )
      {
        result = kgsl_allocate_global(a1, 0x10000, 0x4000, 0, 64, "preemption_desc");
        *v6 = result;
      }
      if ( result > 0xFFFFFFFFFFFFF000LL )
        break;
      kgsl_sharedmem_writel(result, 0, 667204348);
      kgsl_sharedmem_writel(*v6, 4, 0);
      kgsl_sharedmem_writel(*v6, 8, 0);
      kgsl_sharedmem_writel(*v6, 12, 134218252);
      kgsl_sharedmem_writel(*v6, 16, 0);
      kgsl_sharedmem_writel(*v6, 20, 0);
      kgsl_sharedmem_writeq(*v6, 24, *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *((int *)v6 - 39));
      kgsl_sharedmem_writeq(*v6, 32, *(_QWORD *)(*(v6 - 22) + 24));
      kgsl_sharedmem_writeq(*v6, 40, v4);
      ++v5;
      v4 += 64;
      v6 += 165;
      if ( v5 >= *(_DWORD *)(a1 + 19632) )
        goto LABEL_16;
    }
  }
  else
  {
LABEL_16:
    result = *(_QWORD *)(a1 + 1000);
    if ( (*(_QWORD *)(a1 + 104) & 0x40) != 0 && (!result || result >= 0xFFFFFFFFFFFFF001LL) )
    {
      result = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 64, "smmu_info");
      *(_QWORD *)(a1 + 1000) = result;
    }
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      _X8 = (unsigned __int64 *)(a1 + 14240);
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( __stxr(v13 | 0x200, _X8) );
      return 0;
    }
  }
  return result;
}
