__int64 __fastcall gen7_hwsched_context_detach(__int64 a1)
{
  _QWORD *v2; // x19
  int v3; // w21
  __int64 v4; // x0
  int v5; // w8
  _QWORD *v6; // x8
  _QWORD *v7; // x24
  _QWORD *v8; // x21
  __int64 result; // x0
  __int64 v10; // x23
  int v11; // w24
  unsigned __int64 *v12; // x1
  _BOOL4 v13; // w24
  _QWORD *v14; // x8
  unsigned __int64 v15; // x9
  unsigned int v22; // w8
  unsigned int v23; // w8
  __int64 v24; // [xsp+8h] [xbp-98h] BYREF
  int v25; // [xsp+10h] [xbp-90h]
  __int64 v26; // [xsp+18h] [xbp-88h] BYREF
  __int64 v27; // [xsp+20h] [xbp-80h]
  __int64 v28; // [xsp+28h] [xbp-78h]
  __int64 v29; // [xsp+30h] [xbp-70h]
  __int64 v30; // [xsp+38h] [xbp-68h]
  __int64 v31; // [xsp+40h] [xbp-60h]
  __int64 v32; // [xsp+48h] [xbp-58h]
  __int64 v33; // [xsp+50h] [xbp-50h]
  __int64 v34; // [xsp+58h] [xbp-48h]
  __int64 v35; // [xsp+60h] [xbp-40h]
  __int64 v36; // [xsp+68h] [xbp-38h]
  __int64 v37; // [xsp+70h] [xbp-30h] BYREF
  __int64 v38; // [xsp+78h] [xbp-28h]
  __int64 v39; // [xsp+80h] [xbp-20h]
  unsigned __int64 v40; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v41; // [xsp+90h] [xbp-10h]
  __int64 v42; // [xsp+98h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 40);
  rt_mutex_lock(v2 + 1386);
  v3 = *(_DWORD *)(a1 + 396);
  v4 = to_gen7_gmu((__int64)v2);
  v5 = *(unsigned __int8 *)(a1 + 288);
  v40 = 0;
  v41 = nullptr;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  v24 = 0;
  if ( v5 != 1 || (*(_QWORD *)(v4 + 1096) & 2) == 0 )
  {
    v6 = *(_QWORD **)(a1 + 2056);
    if ( v6 != (_QWORD *)(a1 + 2056) )
    {
      do
      {
        v7 = (_QWORD *)*v6;
        v8 = v6 - 8;
        kgsl_hw_fence_trigger_cpu(v2, *(v6 - 2));
        adreno_hwsched_remove_hw_fence_entry(v2, v8);
        v6 = v7;
      }
      while ( v7 != (_QWORD *)(a1 + 2056) );
    }
LABEL_5:
    kgsl_sharedmem_writel(v2[5], 40LL * *(unsigned int *)(a1 + 4), *(unsigned int *)(a1 + 392));
    kgsl_sharedmem_writel(v2[5], 40LL * *(unsigned int *)(a1 + 4) + 8, *(unsigned int *)(a1 + 392));
    adreno_profile_process_results(v2);
    *(_BYTE *)(a1 + 288) = 0;
    goto LABEL_6;
  }
  v10 = v4;
  HIDWORD(v24) = *(_DWORD *)(a1 + 4);
  v25 = v3;
  if ( (unsigned int)adreno_active_count_get((__int64)v2) )
  {
    gmu_core_fault_snapshot(v2, 11);
    move_detached_context_hardware_fences(v2, a1);
    gen7_hwsched_fault((__int64)v2, 32);
    goto LABEL_6;
  }
  _X9 = (unsigned int *)(v10 + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v22 = __ldxr(_X9);
    v23 = v22 + 1;
  }
  while ( __stlxr(v23, _X9) );
  __dmb(0xBu);
  v11 = (v23 << 20) | 0x381;
  v26 = 0;
  v27 = 0;
  LODWORD(v24) = v11;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = nullptr;
  _init_swait_queue_head(&v37, "&x->wait", &init_completion___key_2);
  raw_write_lock_irq((char *)v2 + 24556);
  v12 = (unsigned __int64 *)v2[3072];
  if ( &v40 == v2 + 3071 || &v40 == v12 || (_QWORD *)*v12 != v2 + 3071 )
  {
    _list_add_valid_or_report(&v40, v12);
  }
  else
  {
    v2[3072] = &v40;
    v40 = (unsigned __int64)(v2 + 3071);
    v41 = (unsigned __int64 **)v12;
    *v12 = (unsigned __int64)&v40;
  }
  raw_write_unlock_irq((char *)v2 + 24556);
  LODWORD(v26) = v11;
  if ( (unsigned int)gen7_hfi_cmdq_write((__int64)v2, (int *)&v24, 0xCu)
    || (unsigned int)adreno_hwsched_ctxt_unregister_wait_completion(
                       v2,
                       v2[193] + 16LL,
                       &v26,
                       gen7_hwsched_process_msgq,
                       &v24) )
  {
    gmu_core_fault_snapshot(v2, 11);
    move_detached_context_hardware_fences(v2, a1);
    gen7_hwsched_fault((__int64)v2, 32);
  }
  else if ( !(unsigned int)check_detached_context_hardware_fences(v2, a1) )
  {
    v13 = ((__int64 (__fastcall *)(_QWORD *, __int64 *))check_ack_failure_0)(v2, &v26) == 0;
    goto LABEL_18;
  }
  v13 = 0;
LABEL_18:
  adreno_active_count_put((__int64)v2);
  raw_write_lock_irq((char *)v2 + 24556);
  v14 = v41;
  if ( *v41 == &v40 && (v15 = v40, *(unsigned __int64 **)(v40 + 8) == &v40) )
  {
    *(_QWORD *)(v40 + 8) = v41;
    *v14 = v15;
  }
  else
  {
    _list_del_entry_valid_or_report(&v40);
  }
  v40 = 0xDEAD000000000100LL;
  v41 = (unsigned __int64 **)0xDEAD000000000122LL;
  raw_write_unlock_irq((char *)v2 + 24556);
  if ( v13 )
    goto LABEL_5;
LABEL_6:
  result = rt_mutex_unlock(v2 + 1386);
  _ReadStatusReg(SP_EL0);
  return result;
}
