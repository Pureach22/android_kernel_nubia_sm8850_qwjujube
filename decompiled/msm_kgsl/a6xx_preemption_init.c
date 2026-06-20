unsigned __int64 __fastcall a6xx_preemption_init(__int64 a1)
{
  unsigned int v2; // w25
  unsigned __int64 result; // x0
  int v4; // w8
  unsigned int v5; // w26
  _QWORD *v6; // x21
  unsigned __int64 v7; // x8
  __int64 v8; // x23
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int64 v14; // x8
  unsigned __int64 v20; // x9

  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL);
  if ( (unsigned int)kgsl_mmu_get_mmutype() )
    return 4294967277LL;
  *(_QWORD *)(a1 + 20544) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 20552) = a1 + 20552;
  *(_QWORD *)(a1 + 20560) = a1 + 20552;
  v4 = *(_DWORD *)(a1 + 19632);
  *(_QWORD *)(a1 + 20568) = a6xx_preemption_worker;
  if ( v4 )
  {
    v5 = 0;
    v6 = (_QWORD *)(a1 + 14352);
    while ( 1 )
    {
      v7 = v6[23];
      v8 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 184LL) ? *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 184LL) : 2162688LL;
      if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
      {
        result = kgsl_allocate_global(a1, v8, 0x4000, 0, 64, "preemption_desc");
        v6[23] = result;
        if ( result >= 0xFFFFFFFFFFFFF001LL && (_DWORD)result != 0 )
          break;
      }
      v10 = v6[24];
      if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        result = kgsl_allocate_global(a1, v8, 0, 8, 64, "preemption_desc");
        v6[24] = result;
        if ( result >= 0xFFFFFFFFFFFFF001LL )
          break;
      }
      v11 = v6[25];
      if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
      {
        result = kgsl_allocate_global(a1, 4096, 0, 0, 64, "perfcounter_save_restore_desc");
        v6[25] = result;
        if ( result >= 0xFFFFFFFFFFFFF001LL )
          break;
      }
      reset_rb_preempt_record(a1, (__int64)v6);
      ++v5;
      v6 += 165;
      if ( v5 >= *(_DWORD *)(a1 + 19632) )
        goto LABEL_24;
    }
  }
  else
  {
LABEL_24:
    v12 = *(_QWORD *)(a1 + 20496);
    if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL
      || (result = kgsl_allocate_global(a1, 4096, 0, 0, (v2 >> 5) & 0x40, "preempt_scratch"),
          *(_QWORD *)(a1 + 20496) = result,
          result < 0xFFFFFFFFFFFFF001LL) )
    {
      if ( (*(_QWORD *)(a1 + 104) & 0x40) == 0
        || (v13 = *(_QWORD *)(a1 + 1000)) != 0 && v13 < 0xFFFFFFFFFFFFF001LL
        || (result = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 64, "smmu_info"),
            *(_QWORD *)(a1 + 1000) = result,
            result < 0xFFFFFFFFFFFFF001LL) )
      {
        if ( (*(_BYTE *)(a1 + 23968) & 1) == 0 )
        {
          v14 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 8LL);
          *(_QWORD *)(v14 + 800) = 0x140050E01LL;
          *(_QWORD *)(v14 + 808) = 0x370BC8006LL;
          *(_QWORD *)(v14 + 816) = 1295;
          *(_QWORD *)(v14 + 824) = 0x100000001LL;
          *(_DWORD *)(v14 + 832) = 0;
          *(_DWORD *)(a1 + 20588) = 9;
        }
        _X8 = (unsigned __int64 *)(a1 + 14240);
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 | 0x200, _X8) );
        return 0;
      }
    }
  }
  return result;
}
