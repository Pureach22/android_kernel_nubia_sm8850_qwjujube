__int64 __fastcall gen7_preemption_trigger(__int64 result, char a2)
{
  unsigned int *v2; // x19
  __int64 v3; // x24
  __int64 v4; // x23
  unsigned int v6; // w26
  __int64 v7; // x20
  __int64 v8; // x21
  int rptr; // w0
  int v10; // w27
  int v11; // w22
  __int64 v12; // x21
  int v13; // w8
  int v14; // w8
  unsigned int v15; // w21
  __int64 v16; // x8
  unsigned int v23; // w8
  unsigned int v26; // w9
  unsigned int v29; // w9
  unsigned int v30; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF

  v2 = (unsigned int *)result;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(result + 14264);
  v4 = result + 19632;
  v31 = 0;
  v32[0] = 0;
  v30 = 0;
  _X10 = (unsigned int *)(result + 20488);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v23 = __ldxr(_X10);
    if ( v23 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v23 )
    goto LABEL_33;
  if ( !*(_DWORD *)v4 )
    goto LABEL_32;
  v6 = 0;
  v7 = result + 14352;
  while ( 1 )
  {
    v8 = raw_spin_lock_irqsave(v7 + 1292);
    rptr = adreno_get_rptr(v7);
    v10 = *(_DWORD *)(v7 + 20);
    v11 = rptr;
    result = raw_spin_unlock_irqrestore(v7 + 1292, v8);
    if ( v11 != v10 )
      break;
    ++v6;
    v7 += 1320;
    if ( v6 >= *(_DWORD *)v4 )
      goto LABEL_32;
  }
  if ( !v7 )
  {
LABEL_32:
    __dmb(0xAu);
    *(_DWORD *)(v4 + 856) = 0;
    __dmb(0xAu);
    goto LABEL_33;
  }
  if ( v7 == *((_QWORD *)v2 + 2455) )
  {
    update_wptr_0(v2, 0, a2 & 1);
    result = mod_timer(v2 + 4954);
    goto LABEL_32;
  }
  timer_delete(v2 + 4954);
  v12 = raw_spin_lock_irqsave(v7 + 1292);
  kgsl_sharedmem_readq(*((_QWORD *)v2 + 6), v32, (32LL * *(int *)(v7 + 28)) | 0x10);
  kgsl_sharedmem_readl(*((_QWORD *)v2 + 6), &v30, (32LL * *(int *)(v7 + 28)) | 0x18);
  kgsl_sharedmem_writel(*(_QWORD *)(v7 + 184), 24, *(unsigned int *)(v7 + 20));
  raw_spin_unlock_irqrestore(v7 + 1292, v12);
  if ( (*((_QWORD *)v2 + 13) & 0x40) != 0 )
  {
    kgsl_sharedmem_writeq(*((_QWORD *)v2 + 125), 8, v32[0]);
    kgsl_sharedmem_writel(*((_QWORD *)v2 + 125), 20, v30);
  }
  kgsl_sharedmem_readq(*((_QWORD *)v2 + 2562), &v31, 8LL * *(int *)(v7 + 28));
  gmu_core_regwrite(v2, 129220, 1);
  if ( (unsigned int)gen7_fenced_write(v2, 2211, *(_DWORD *)(*(_QWORD *)(v7 + 184) + 24LL), 2)
    || (a2 & 1) == 0 && (unsigned int)gmu_core_dev_wait_for_active_transition(v2)
    || (unsigned int)gen7_fenced_write(v2, 2212, *(_DWORD *)(*(_QWORD *)(v7 + 184) + 28LL), 2)
    || (unsigned int)gen7_fenced_write(v2, 2213, *(_DWORD *)(*(_QWORD *)(v7 + 192) + 24LL), 2)
    || (unsigned int)gen7_fenced_write(v2, 2214, *(_DWORD *)(*(_QWORD *)(v7 + 192) + 28LL), 2)
    || (unsigned int)gen7_fenced_write(v2, 2215, v31, 2)
    || (unsigned int)gen7_fenced_write(v2, 2216, HIDWORD(v31), 2) )
  {
    goto LABEL_29;
  }
  *((_QWORD *)v2 + 2456) = v7;
  mod_timer(v2 + 5126);
  if ( *(_BYTE *)(v4 + 948) )
    v13 = 513;
  else
    v13 = 1;
  v14 = v13 | (*(_DWORD *)(v4 + 944) << 6);
  if ( *(_BYTE *)(v4 + 949) )
    v15 = v14 | 0x100;
  else
    v15 = v14;
  trace_adreno_preempt_trigger_0(
    *(unsigned int *)(*((_QWORD *)v2 + 2455) + 28LL),
    *(unsigned int *)(*((_QWORD *)v2 + 2456) + 28LL),
    v15);
  __dmb(0xAu);
  *(_DWORD *)(v4 + 856) = 2;
  __dmb(0xAu);
  v16 = *(_QWORD *)(v3 + 232);
  if ( v16 )
    kgsl_sharedmem_writel(*((_QWORD *)v2 + 2562), 32, *(unsigned int *)(v16 + 4LL * *(int *)(v7 + 28)));
  result = gen7_fenced_write(v2, 2208, v15, 2);
  if ( (_DWORD)result )
  {
    *((_QWORD *)v2 + 2456) = 0;
    timer_delete(v2 + 5126);
LABEL_29:
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
    {
      _X8 = v2 + 6112;
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 | 0x20, _X8) );
    }
    else
    {
      gmu_core_fault_snapshot(v2, 0);
      _X8 = v2 + 6112;
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 | 0x80, _X8) );
    }
    __dmb(0xAu);
    kthread_queue_work(*((_QWORD *)v2 + 3050), v2 + 6102);
    __dmb(0xAu);
    *(_DWORD *)(v4 + 856) = 0;
    __dmb(0xAu);
    result = gmu_core_regwrite(v2, 129220, 0);
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
