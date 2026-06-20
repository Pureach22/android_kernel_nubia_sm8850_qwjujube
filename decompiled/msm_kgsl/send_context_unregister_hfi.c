__int64 __fastcall send_context_unregister_hfi(_QWORD *a1, __int64 a2, int a3)
{
  __int64 v6; // x22
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x23
  __int64 v10; // x0
  _QWORD *v11; // x21
  _QWORD **v12; // x22
  _QWORD *v13; // x8
  _QWORD *v14; // x21
  _QWORD *v15; // x20
  __int64 v16; // x21
  _QWORD *v17; // x24
  _QWORD *v18; // t1
  __int64 v19; // x23
  unsigned int v20; // w0
  unsigned int v21; // w21
  __int64 result; // x0
  int v23; // w24
  unsigned __int64 *v24; // x1
  unsigned int v25; // w0
  unsigned int v26; // w22
  _QWORD *v27; // x8
  unsigned __int64 v28; // x9
  unsigned int v35; // w8
  unsigned int v36; // w8
  __int64 v37; // [xsp+8h] [xbp-98h] BYREF
  int v38; // [xsp+10h] [xbp-90h]
  __int64 v39; // [xsp+18h] [xbp-88h] BYREF
  __int64 v40; // [xsp+20h] [xbp-80h]
  __int64 v41; // [xsp+28h] [xbp-78h]
  __int64 v42; // [xsp+30h] [xbp-70h]
  __int64 v43; // [xsp+38h] [xbp-68h]
  __int64 v44; // [xsp+40h] [xbp-60h]
  __int64 v45; // [xsp+48h] [xbp-58h]
  __int64 v46; // [xsp+50h] [xbp-50h]
  __int64 v47; // [xsp+58h] [xbp-48h]
  __int64 v48; // [xsp+60h] [xbp-40h]
  __int64 v49; // [xsp+68h] [xbp-38h]
  __int64 v50; // [xsp+70h] [xbp-30h] BYREF
  __int64 v51; // [xsp+78h] [xbp-28h]
  __int64 v52; // [xsp+80h] [xbp-20h]
  unsigned __int64 v53; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v54; // [xsp+90h] [xbp-10h]
  __int64 v55; // [xsp+98h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[193];
  v7 = to_gen8_gmu((__int64)a1);
  v8 = *(unsigned __int8 *)(a2 + 288);
  v9 = *(_QWORD *)(a2 + 24);
  v53 = 0;
  v54 = nullptr;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 0;
  v37 = 0;
  if ( v8 == 1 && (*(_QWORD *)(v7 + 1040) & 2) != 0 )
  {
    v19 = v7;
    HIDWORD(v37) = *(_DWORD *)(a2 + 4);
    v38 = a3;
    v20 = adreno_active_count_get((__int64)a1);
    if ( v20 )
    {
      v21 = v20;
      gmu_core_fault_snapshot(a1, 11);
      move_detached_context_hardware_fences_0(a1, a2);
      gen8_hwsched_fault((__int64)a1, 32);
      result = v21;
    }
    else
    {
      _X9 = (unsigned int *)(v19 + 44);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v35 = __ldxr(_X9);
        v36 = v35 + 1;
      }
      while ( __stlxr(v36, _X9) );
      __dmb(0xBu);
      v23 = (v36 << 20) | 0x381;
      v39 = 0;
      v40 = 0;
      LODWORD(v37) = v23;
      v41 = 0;
      v42 = 0;
      v43 = 0;
      v44 = 0;
      v45 = 0;
      v46 = 0;
      v47 = 0;
      v48 = 0;
      v49 = 0;
      v50 = 0;
      v51 = 0;
      v52 = 0;
      v53 = 0;
      v54 = nullptr;
      _init_swait_queue_head(&v50, "&x->wait", &init_completion___key_3);
      raw_write_lock_irq((char *)a1 + 24620);
      v24 = (unsigned __int64 *)a1[3080];
      if ( &v53 == a1 + 3079 || &v53 == v24 || (_QWORD *)*v24 != a1 + 3079 )
      {
        _list_add_valid_or_report(&v53, v24);
      }
      else
      {
        a1[3080] = &v53;
        v53 = (unsigned __int64)(a1 + 3079);
        v54 = (unsigned __int64 **)v24;
        *v24 = (unsigned __int64)&v53;
      }
      raw_write_unlock_irq((char *)a1 + 24620);
      LODWORD(v39) = v23;
      v25 = gen8_hfi_cmdq_write((__int64)a1, (int *)&v37, 0xCu);
      if ( v25
        || (v25 = adreno_hwsched_ctxt_unregister_wait_completion(a1, v6 + 16, &v39, gen8_hwsched_process_msgq, &v37)) != 0 )
      {
        v26 = v25;
        gmu_core_fault_snapshot(a1, 11);
        move_detached_context_hardware_fences_0(a1, a2);
        gen8_hwsched_fault((__int64)a1, 32);
      }
      else
      {
        v26 = check_detached_context_hardware_fences_0(a1, a2);
        if ( !v26 )
          v26 = ((__int64 (__fastcall *)(_QWORD *, __int64 *))check_ack_failure_1)(a1, &v39);
      }
      adreno_active_count_put((__int64)a1);
      raw_write_lock_irq((char *)a1 + 24620);
      v27 = v54;
      if ( *v54 == &v53 && (v28 = v53, *(unsigned __int64 **)(v53 + 8) == &v53) )
      {
        *(_QWORD *)(v53 + 8) = v54;
        *v27 = v28;
      }
      else
      {
        _list_del_entry_valid_or_report(&v53);
      }
      v53 = 0xDEAD000000000100LL;
      v54 = (unsigned __int64 **)0xDEAD000000000122LL;
      raw_write_unlock_irq((char *)a1 + 24620);
      result = v26;
    }
  }
  else
  {
    v10 = to_gen8_gmu((__int64)a1);
    v11 = *(_QWORD **)(a2 + 2056);
    v12 = (_QWORD **)(a2 + 2056);
    if ( v11 != (_QWORD *)(a2 + 2056) )
    {
      if ( (*(_QWORD *)(v10 + 1040) & 2) != 0 )
      {
        while ( 1 )
        {
          v18 = (_QWORD *)*v11;
          v16 = (__int64)(v11 - 8);
          v17 = v18;
          if ( (unsigned int)gen8_send_hw_fence_hfi_wait_ack((__int64)a1, v16, 1) )
            break;
          adreno_hwsched_remove_hw_fence_entry(a1, v16);
          v11 = v17;
          if ( v17 == v12 )
            goto LABEL_14;
        }
        move_detached_context_hardware_fences_0(a1, a2);
        gmu_core_fault_snapshot(a1, 14);
        gen8_hwsched_fault((__int64)a1, 32);
      }
      else
      {
        gen8_hwsched_soccp_vote((__int64)a1);
        v13 = *v12;
        if ( *v12 != v12 )
        {
          do
          {
            v14 = (_QWORD *)*v13;
            v15 = v13 - 8;
            kgsl_hw_fence_trigger_cpu(a1, *(v13 - 2));
            adreno_hwsched_remove_hw_fence_entry(a1, v15);
            v13 = v14;
          }
          while ( v14 != v12 );
        }
        gen8_hwsched_soccp_vote((__int64)a1);
      }
    }
LABEL_14:
    result = 0;
    *(_BYTE *)(v9 + 688) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
