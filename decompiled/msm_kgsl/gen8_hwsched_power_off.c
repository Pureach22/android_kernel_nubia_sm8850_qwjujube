__int64 __fastcall gen8_hwsched_power_off(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x20
  unsigned int v5; // w23
  __int64 next; // x0
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x21
  _QWORD *v10; // x8
  _QWORD *v11; // x28
  _QWORD *v12; // x22
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x0
  unsigned __int64 v22; // x10
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen8_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1040) & 2) == 0 )
  {
    result = 0;
    goto LABEL_34;
  }
  v4 = v2;
  kgsl_pwrctrl_request_state(a1, 128);
  v5 = gen8_gmu_oob_set(a1, 0);
  if ( !v5 )
  {
    kgsl_pwrscale_update_stats(a1);
    adreno_coresight_stop(a1);
    adreno_irqctrl(a1, 0);
  }
  gen8_gmu_oob_clear(a1, 0);
  kgsl_pwrctrl_irq(a1, 0);
  if ( (*(_QWORD *)(a1 + 22496) & 0x10) != 0 )
  {
    raw_read_lock(a1 + 11208);
    v23 = 0;
    next = idr_get_next(a1 + 11184, &v23);
    if ( next )
    {
      v7 = next;
      while ( *(_BYTE *)(v7 + 288) != 1 || !(unsigned int)gen8_hwsched_check_context_inflight_hw_fences(a1) )
      {
        ++v23;
        v7 = idr_get_next(a1 + 11184, &v23);
        if ( !v7 )
          goto LABEL_19;
      }
      raw_read_unlock(a1 + 11208);
      gmu_core_fault_snapshot(a1, 14);
      gen8_hwsched_gmu_power_off(a1);
      raw_read_lock(a1 + 11208);
      v23 = 0;
      v8 = idr_get_next(a1 + 11184, &v23);
      if ( v8 )
      {
        v9 = v8;
        do
        {
          if ( *(_BYTE *)(v9 + 288) == 1 )
          {
            raw_spin_lock(v9 + 404);
            v10 = *(_QWORD **)(v9 + 2072);
            if ( v10 != (_QWORD *)(v9 + 2072) )
            {
              do
              {
                v11 = (_QWORD *)*v10;
                v12 = v10 - 8;
                kgsl_hw_fence_trigger_cpu(a1, *(v10 - 2));
                adreno_hwsched_remove_hw_fence_entry(a1, v12);
                v10 = v11;
              }
              while ( v11 != (_QWORD *)(v9 + 2072) );
            }
            raw_spin_unlock(v9 + 404);
          }
          ++v23;
          v9 = idr_get_next(a1 + 11184, &v23);
        }
        while ( v9 );
      }
      raw_read_unlock(a1 + 11208);
      goto LABEL_21;
    }
LABEL_19:
    raw_read_unlock(a1 + 11208);
  }
  gen8_hwsched_gmu_power_off(a1);
LABEL_21:
  adreno_hwsched_unregister_contexts(a1);
  if ( *(_BYTE *)(a1 + 20832) == 1 )
  {
    v13 = *(_QWORD *)(a1 + 20824);
    if ( v13 )
    {
      if ( v13 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20848) == 1 )
  {
    v14 = *(_QWORD *)(a1 + 20840);
    if ( v14 )
    {
      if ( v14 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20864) == 1 )
  {
    v15 = *(_QWORD *)(a1 + 20856);
    if ( v15 )
    {
      if ( v15 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = (unsigned __int64 *)(v4 + 1040);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  timer_delete_sync(a1 + 8792);
  kgsl_pwrscale_sleep(a1);
  kgsl_pwrctrl_clear_l3_vote(a1);
  gen8_hwsched_soccp_vote(a1);
  kgsl_pwrctrl_set_state(a1, 128);
  result = v5;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
