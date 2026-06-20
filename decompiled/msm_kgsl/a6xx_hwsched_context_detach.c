__int64 __fastcall a6xx_hwsched_context_detach(__int64 a1)
{
  _QWORD *v2; // x19
  int v3; // w23
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x24
  _QWORD *v8; // x8
  unsigned __int64 v9; // x9
  _BOOL4 v10; // w23
  unsigned int v17; // w9
  unsigned int v20; // w9
  unsigned int v21; // w9
  unsigned int v24; // w9
  unsigned int v27; // w9
  int v28[3]; // [xsp+Ch] [xbp-94h] BYREF
  _QWORD v29[14]; // [xsp+18h] [xbp-88h] BYREF
  unsigned __int64 v30; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v31; // [xsp+90h] [xbp-10h]
  __int64 v32; // [xsp+98h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 40);
  rt_mutex_lock(v2 + 1386);
  v3 = *(_DWORD *)(a1 + 396);
  v4 = to_a6xx_gmu((__int64)v2);
  if ( *(_BYTE *)(a1 + 288) != 1 || (*(_QWORD *)(v4 + 1296) & 2) == 0 )
  {
LABEL_3:
    kgsl_sharedmem_writel(v2[5], 40LL * *(unsigned int *)(a1 + 4), *(unsigned int *)(a1 + 392));
    kgsl_sharedmem_writel(v2[5], 40LL * *(unsigned int *)(a1 + 4) + 8, *(unsigned int *)(a1 + 392));
    adreno_profile_process_results(v2);
    *(_BYTE *)(a1 + 288) = 0;
    goto LABEL_4;
  }
  v6 = *(_DWORD *)(a1 + 4);
  v7 = v4;
  v30 = 0;
  v31 = nullptr;
  memset(v29, 0, sizeof(v29));
  v28[1] = v6;
  v28[2] = v3;
  if ( (unsigned int)adreno_active_count_get((__int64)v2) )
  {
    gmu_core_fault_snapshot(v2, 11);
    adreno_drawctxt_set_guilty(v2, a1);
    _X8 = (unsigned int *)(v2 + 3056);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 | 0x20, _X8) );
    __dmb(0xAu);
    kthread_queue_work(v2[3050], v2 + 3051);
    goto LABEL_4;
  }
  _X10 = (unsigned int *)(v7 + 36);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v20 = __ldxr(_X10);
    v21 = v20 + 1;
  }
  while ( __stlxr(v21, _X10) );
  __dmb(0xBu);
  v28[0] = (v21 << 20) | 0x381;
  add_waiter((__int64)(v2 + 3068), v28[0], v29);
  if ( (unsigned int)a6xx_hfi_cmdq_write((__int64)v2, v28, 0xCu) )
  {
    gmu_core_fault_snapshot(v2, 11);
    adreno_drawctxt_set_guilty(v2, a1);
    _X8 = (unsigned int *)(v2 + 3056);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 | 0x20, _X8) );
LABEL_24:
    __dmb(0xAu);
    kthread_queue_work(v2[3050], v2 + 3051);
    v10 = 0;
    goto LABEL_12;
  }
  if ( (unsigned int)adreno_hwsched_ctxt_unregister_wait_completion(
                       v2,
                       v2[193] + 16LL,
                       v29,
                       a6xx_hwsched_process_msgq,
                       v28) )
  {
    gmu_core_fault_snapshot(v2, 11);
    adreno_drawctxt_set_guilty(v2, a1);
    _X8 = (unsigned int *)(v2 + 3056);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 | 0x20, _X8) );
    goto LABEL_24;
  }
  v10 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *))check_ack_failure)(v2, v29) == 0;
LABEL_12:
  adreno_active_count_put((__int64)v2);
  raw_write_lock_irq((char *)v2 + 24548);
  v8 = v31;
  if ( *v31 == &v30 && (v9 = v30, *(unsigned __int64 **)(v30 + 8) == &v30) )
  {
    *(_QWORD *)(v30 + 8) = v31;
    *v8 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(&v30);
  }
  v30 = 0xDEAD000000000100LL;
  v31 = (unsigned __int64 **)0xDEAD000000000122LL;
  raw_write_unlock_irq((char *)v2 + 24548);
  if ( v10 )
    goto LABEL_3;
LABEL_4:
  result = rt_mutex_unlock(v2 + 1386);
  _ReadStatusReg(SP_EL0);
  return result;
}
