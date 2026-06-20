__int64 __fastcall hfi_f2h_main_0(__int64 a1)
{
  __int64 should_stop; // x0
  __int64 is_trace_empty; // x0
  _DWORD *v4; // x8
  _DWORD *v5; // x8
  __int64 v6; // x20
  _DWORD *v7; // x8
  _DWORD *v8; // x8
  __int64 v9; // x0
  _QWORD v11[6]; // [xsp+0h] [xbp-30h] BYREF

  v11[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  should_stop = kthread_should_stop(a1);
  if ( (should_stop & 1) == 0 )
  {
    while ( 1 )
    {
      is_trace_empty = kthread_should_stop(should_stop);
      if ( (is_trace_empty & 1) != 0 )
        goto LABEL_23;
      if ( (*(_BYTE *)(a1 + 24552) & 1) == 0
        || (is_trace_empty = to_gen7_gmu(a1), v4 = *(_DWORD **)(*(_QWORD *)(is_trace_empty + 48) + 8LL), !v4[18])
        || v4[28] == v4[29] )
      {
        is_trace_empty = gmu_core_is_trace_empty(*(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL));
        if ( (is_trace_empty & 1) == 0 )
          goto LABEL_23;
        is_trace_empty = to_gen7_gmu(a1);
        v5 = *(_DWORD **)(*(_QWORD *)(is_trace_empty + 48) + 8LL);
        if ( !v5[30] || v5[40] == v5[41] )
        {
          memset(v11, 0, 40);
          init_wait_entry(v11, 0);
          while ( 1 )
          {
            v6 = prepare_to_wait_event(a1 + 24592, v11, 1);
            if ( (kthread_should_stop(v6) & 1) != 0 )
              break;
            if ( (*(_BYTE *)(a1 + 24552) & 1) != 0 )
            {
              v7 = *(_DWORD **)(*(_QWORD *)(to_gen7_gmu(a1) + 48) + 8LL);
              if ( v7[18] )
              {
                if ( v7[28] != v7[29] )
                  goto LABEL_21;
              }
            }
            if ( (gmu_core_is_trace_empty(*(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL)) & 1) == 0 )
              break;
            is_trace_empty = to_gen7_gmu(a1);
            v8 = *(_DWORD **)(*(_QWORD *)(is_trace_empty + 48) + 8LL);
            if ( v8[30] )
            {
              if ( v8[40] != v8[41] )
              {
LABEL_21:
                __dsb(0xDu);
                break;
              }
            }
            if ( v6 )
              goto LABEL_23;
            schedule();
          }
          is_trace_empty = finish_wait(a1 + 24592, v11);
          goto LABEL_23;
        }
      }
      __dsb(0xDu);
LABEL_23:
      if ( (kthread_should_stop(is_trace_empty) & 1) == 0 )
      {
        gen7_hwsched_process_msgq(a1);
        gmu_core_process_trace_data(a1, *(_QWORD *)(a1 + 1544) + 16LL, a1 + 8672);
        v9 = gen7_hwsched_process_dbgq(a1, 1);
        should_stop = kthread_should_stop(v9);
        if ( (should_stop & 1) == 0 )
          continue;
      }
      break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
