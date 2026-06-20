__int64 __fastcall gen7_preemption_init(__int64 a1)
{
  unsigned int v2; // w25
  unsigned __int64 global; // x0
  int v5; // w8
  unsigned int v6; // w27
  _QWORD *v7; // x21
  unsigned __int64 v8; // x8
  __int64 v9; // x24
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned int v15; // w1
  unsigned __int64 v21; // x10

  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL);
  if ( (unsigned int)kgsl_mmu_get_mmutype() )
  {
    LODWORD(global) = -19;
  }
  else
  {
    *(_QWORD *)(a1 + 20544) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 20552) = a1 + 20552;
    *(_QWORD *)(a1 + 20560) = a1 + 20552;
    v5 = *(_DWORD *)(a1 + 19632);
    *(_QWORD *)(a1 + 20568) = gen7_preemption_worker;
    if ( v5 )
    {
      v6 = 0;
      v7 = (_QWORD *)(a1 + 14352);
      while ( 1 )
      {
        v8 = v7[23];
        v9 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 192LL) ? *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 192LL) : 4292608LL;
        if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
        {
          global = kgsl_allocate_global(a1, v9, 0x4000, 0, 64, "preemption_desc");
          v7[23] = global;
          if ( global >= 0xFFFFFFFFFFFFF001LL && (_DWORD)global != 0 )
            break;
        }
        v11 = v7[24];
        if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
        {
          global = kgsl_allocate_global(a1, v9, 0, 8, 64, "secure_preemption_desc");
          v7[24] = global;
          if ( global >= 0xFFFFFFFFFFFFF001LL )
            break;
        }
        v12 = v7[25];
        if ( !v12 || v12 >= 0xFFFFFFFFFFFFF001LL )
        {
          global = kgsl_allocate_global(a1, 4096, 0, 0, 64, "perfcounter_save_restore_desc");
          v7[25] = global;
          if ( global >= 0xFFFFFFFFFFFFF001LL )
            break;
        }
        reset_rb_preempt_record_0(a1, (__int64)v7);
        ++v6;
        v7 += 165;
        if ( v6 >= *(_DWORD *)(a1 + 19632) )
          goto LABEL_25;
      }
    }
    else
    {
LABEL_25:
      v13 = *(_QWORD *)(a1 + 20496);
      if ( v13 && v13 < 0xFFFFFFFFFFFFF001LL
        || (global = kgsl_allocate_global(a1, 4096, 0, 0, (v2 >> 5) & 0x40, "preempt_scratch"),
            *(_QWORD *)(a1 + 20496) = global,
            global < 0xFFFFFFFFFFFFF001LL) )
      {
        if ( (*(_QWORD *)(a1 + 104) & 0x40) == 0 )
          return 0;
        v14 = *(_QWORD *)(a1 + 1000);
        if ( v14 )
        {
          if ( v14 < 0xFFFFFFFFFFFFF001LL )
            return 0;
        }
        global = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 64, "smmu_info");
        v15 = 0;
        *(_QWORD *)(a1 + 1000) = global;
        if ( global < 0xFFFFFFFFFFFFF001LL )
          return v15;
      }
    }
  }
  _X8 = (unsigned __int64 *)(a1 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
  return (unsigned int)global;
}
