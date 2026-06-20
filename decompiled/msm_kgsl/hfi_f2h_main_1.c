__int64 __fastcall hfi_f2h_main_1(__int64 a1)
{
  __int64 v2; // x21
  __int64 should_stop; // x0
  __int64 is_trace_empty; // x0
  _DWORD *v5; // x8
  _DWORD *v6; // x8
  __int64 v7; // x20
  _DWORD *v8; // x8
  _DWORD *v9; // x8
  __int64 v10; // x0
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1544);
  should_stop = kthread_should_stop(a1);
  if ( (should_stop & 1) == 0 )
  {
    while ( 1 )
    {
      is_trace_empty = kthread_should_stop(should_stop);
      if ( (is_trace_empty & 1) != 0 )
        goto LABEL_23;
      if ( (*(_BYTE *)(a1 + 24616) & 1) == 0
        || (is_trace_empty = to_gen8_gmu(a1), v5 = *(_DWORD **)(*(_QWORD *)(is_trace_empty + 48) + 8LL), !v5[18])
        || v5[28] == v5[29] )
      {
        is_trace_empty = gmu_core_is_trace_empty(*(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL));
        if ( (is_trace_empty & 1) == 0 )
          goto LABEL_23;
        is_trace_empty = to_gen8_gmu(a1);
        v6 = *(_DWORD **)(*(_QWORD *)(is_trace_empty + 48) + 8LL);
        if ( !v6[30] || v6[40] == v6[41] )
        {
          memset(v12, 0, 40);
          init_wait_entry(v12, 0);
          while ( 1 )
          {
            v7 = prepare_to_wait_event(a1 + 24656, v12, 1);
            if ( (kthread_should_stop(v7) & 1) != 0 )
              break;
            if ( (*(_BYTE *)(a1 + 24616) & 1) != 0 )
            {
              v8 = *(_DWORD **)(*(_QWORD *)(to_gen8_gmu(a1) + 48) + 8LL);
              if ( v8[18] )
              {
                if ( v8[28] != v8[29] )
                  goto LABEL_21;
              }
            }
            if ( (gmu_core_is_trace_empty(*(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL)) & 1) == 0 )
              break;
            is_trace_empty = to_gen8_gmu(a1);
            v9 = *(_DWORD **)(*(_QWORD *)(is_trace_empty + 48) + 8LL);
            if ( v9[30] )
            {
              if ( v9[40] != v9[41] )
              {
LABEL_21:
                __dsb(0xDu);
                break;
              }
            }
            if ( v7 )
              goto LABEL_23;
            schedule(is_trace_empty);
          }
          is_trace_empty = finish_wait(a1 + 24656, v12);
          goto LABEL_23;
        }
      }
      __dsb(0xDu);
LABEL_23:
      if ( (kthread_should_stop(is_trace_empty) & 1) == 0 )
      {
        gen8_hwsched_process_msgq(a1);
        gmu_core_process_trace_data(a1, v2 + 16, a1 + 8672);
        v10 = gen8_hwsched_process_dbgq(a1, 1);
        should_stop = kthread_should_stop(v10);
        if ( (should_stop & 1) == 0 )
          continue;
      }
      break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
