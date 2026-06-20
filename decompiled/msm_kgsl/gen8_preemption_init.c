__int64 __fastcall gen8_preemption_init(__int64 a1)
{
  unsigned int v2; // w25
  unsigned __int64 global; // x0
  int v5; // w8
  unsigned int v6; // w27
  __int64 v7; // x22
  __int64 v8; // x24
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned int v14; // w1
  unsigned __int64 v21; // x10

  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL);
  if ( (unsigned int)kgsl_mmu_get_mmutype() )
  {
    LODWORD(global) = -19;
    goto LABEL_30;
  }
  *(_QWORD *)(a1 + 20544) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 20552) = a1 + 20552;
  *(_QWORD *)(a1 + 20560) = a1 + 20552;
  v5 = *(_DWORD *)(a1 + 19632);
  *(_QWORD *)(a1 + 20568) = gen8_preemption_worker;
  if ( v5 )
  {
    v6 = 0;
    v7 = a1 + 14352;
    do
    {
      v8 = *(_QWORD *)(a1 + 24520);
      if ( *(_DWORD *)(v7 + 28) )
      {
        v9 = *(_QWORD *)(v7 + 184);
        if ( v9 )
          goto LABEL_12;
      }
      else
      {
        v8 -= *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 64LL);
        v9 = *(_QWORD *)(v7 + 184);
        if ( v9 )
        {
LABEL_12:
          if ( v9 < 0xFFFFFFFFFFFFF001LL )
            goto LABEL_14;
        }
      }
      global = kgsl_allocate_global(a1, v8, 0x4000, 0, 64, "preemption_desc");
      *(_QWORD *)(v7 + 184) = global;
      if ( global >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_30;
LABEL_14:
      v10 = *(_QWORD *)(v7 + 192);
      if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        global = kgsl_allocate_global(a1, v8, 0, 8, 64, "secure_preemption_desc");
        *(_QWORD *)(v7 + 192) = global;
        if ( global >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_30;
      }
      v11 = *(_QWORD *)(v7 + 200);
      if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
      {
        global = kgsl_allocate_global(a1, 4096, 0, 0, 64, "perfcounter_save_restore_desc");
        *(_QWORD *)(v7 + 200) = global;
        if ( global >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_30;
      }
      reset_rb_preempt_record_1(a1, v7);
      ++v6;
      v7 += 1320;
    }
    while ( v6 < *(_DWORD *)(a1 + 19632) );
  }
  v12 = *(_QWORD *)(a1 + 20496);
  if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL
    || (global = kgsl_allocate_global(a1, 4096, 0, 0, (v2 >> 5) & 0x40, "preempt_scratch"),
        *(_QWORD *)(a1 + 20496) = global,
        global < 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (*(_QWORD *)(a1 + 104) & 0x40) == 0 )
      return 0;
    v13 = *(_QWORD *)(a1 + 1000);
    if ( v13 )
    {
      if ( v13 < 0xFFFFFFFFFFFFF001LL )
        return 0;
    }
    global = kgsl_allocate_global(a1, 4096, 0, 0x1000000, 64, "smmu_info");
    v14 = 0;
    *(_QWORD *)(a1 + 1000) = global;
    if ( global < 0xFFFFFFFFFFFFF001LL )
      return v14;
  }
LABEL_30:
  _X8 = (unsigned __int64 *)(a1 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
  return (unsigned int)global;
}
