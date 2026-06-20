__int64 __fastcall hfi_f2h_main(__int64 a1)
{
  __int64 i; // x0
  __int64 should_stop; // x0
  _DWORD *v4; // x8
  _DWORD *v5; // x8
  __int64 v6; // x20
  _DWORD *v7; // x8
  _DWORD *v8; // x8
  __int64 v9; // x0
  _QWORD v11[6]; // [xsp+0h] [xbp-30h] BYREF

  v11[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  for ( i = ((__int64 (*)(void))kthread_should_stop)(); (i & 1) == 0; i = kthread_should_stop(v9) )
  {
    should_stop = kthread_should_stop(i);
    if ( (should_stop & 1) == 0 )
    {
      if ( (*(_BYTE *)(a1 + 24544) & 1) == 0
        || (should_stop = to_a6xx_gmu(a1), v4 = *(_DWORD **)(*(_QWORD *)(should_stop + 40) + 8LL), !v4[18])
        || v4[28] == v4[29] )
      {
        should_stop = gmu_core_is_trace_empty(*(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL));
        if ( (should_stop & 1) != 0 )
        {
          should_stop = to_a6xx_gmu(a1);
          v5 = *(_DWORD **)(*(_QWORD *)(should_stop + 40) + 8LL);
          if ( !v5[30] || v5[40] == v5[41] )
          {
            memset(v11, 0, 40);
            init_wait_entry(v11, 0);
            while ( 1 )
            {
              v6 = prepare_to_wait_event(a1 + 24584, v11, 1);
              if ( (((__int64 (*)(void))kthread_should_stop)() & 1) != 0 )
                break;
              if ( (*(_BYTE *)(a1 + 24544) & 1) != 0 )
              {
                v7 = *(_DWORD **)(*(_QWORD *)(to_a6xx_gmu(a1) + 40) + 8LL);
                if ( v7[18] )
                {
                  if ( v7[28] != v7[29] )
                    break;
                }
              }
              if ( (gmu_core_is_trace_empty(*(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL)) & 1) == 0 )
                break;
              should_stop = to_a6xx_gmu(a1);
              v8 = *(_DWORD **)(*(_QWORD *)(should_stop + 40) + 8LL);
              if ( v8[30] )
              {
                if ( v8[40] != v8[41] )
                  break;
              }
              if ( v6 )
                goto LABEL_20;
              schedule();
            }
            should_stop = finish_wait(a1 + 24584, v11);
          }
        }
      }
    }
LABEL_20:
    if ( (kthread_should_stop(should_stop) & 1) != 0 )
      break;
    a6xx_hwsched_process_msgq(a1);
    gmu_core_process_trace_data(a1, *(_QWORD *)(a1 + 1544) + 16LL, a1 + 8672);
    v9 = a6xx_hwsched_process_dbgq(a1, 1);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
