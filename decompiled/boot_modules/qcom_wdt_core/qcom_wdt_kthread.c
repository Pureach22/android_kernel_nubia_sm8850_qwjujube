__int64 __fastcall qcom_wdt_kthread(__int64 a1)
{
  __int64 v2; // x0
  __int64 v4; // x27
  __int64 unlock; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  char v8; // w8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  bool v11; // cf
  char v12; // w9
  int v13; // w8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x23
  __int64 v16; // x0
  char v17; // w8
  int v18; // w9
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x0
  __int64 should_stop; // x0
  int v22; // w23
  int v23; // w24
  __int64 v24; // x0
  __int64 v25; // [xsp+0h] [xbp-40h]
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h]
  __int64 v28; // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  struct sched_param param; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  param.__sched_priority = 99;
  v2 = sched_setscheduler(_ReadStatusReg(SP_EL0), 1, &param);
  if ( (kthread_should_stop(v2) & 1) == 0 )
  {
    v4 = a1 + 312;
    v25 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( (*(_BYTE *)(a1 + 288) & 1) != 0 )
        {
          v6 = 0;
        }
        else
        {
          v29 = 0;
          v30 = 0;
          v27 = 0;
          v28 = 0;
          v26 = 0;
          init_wait_entry(&v26, 0);
          v6 = prepare_to_wait_event(a1 + 264, &v26, 1);
          if ( (*(_BYTE *)(a1 + 288) & 1) != 0 )
          {
LABEL_10:
            finish_wait(a1 + 264, &v26);
            v6 = 0;
          }
          else
          {
            while ( !v6 )
            {
              schedule();
              v6 = prepare_to_wait_event(a1 + 264, &v26, 1);
              if ( *(_BYTE *)(a1 + 288) == 1 )
                goto LABEL_10;
            }
          }
        }
        if ( zte_trigger_wdt < 1 )
          break;
        v16 = *(_QWORD *)(a1 + 8);
        *(_BYTE *)(a1 + 288) = 0;
        dev_err(v16, "ztedbg stop wdt pet\n");
      }
      if ( !(_DWORD)v6 )
      {
        v7 = sched_clock(v6);
        v8 = 0;
        *(_QWORD *)(a1 + 304) = v7;
        do
        {
          v9 = (unsigned int)(-1LL << v8) & _cpu_present_mask;
          if ( !(_DWORD)v9 )
            break;
          v10 = __clz(__rbit64(v9));
          *(_QWORD *)(a1 + 568 + 8 * v10) = 0;
          v11 = v10 >= 0x1F;
          *(_QWORD *)(v4 + 8 * v10) = 0;
          v8 = v10 + 1;
        }
        while ( !v11 );
        if ( *(_BYTE *)(a1 + 36) == 1 )
        {
          *(_QWORD *)(a1 + 48) = 0;
          v12 = 0;
          __dmb(0xBu);
          v13 = _cpu_online_mask;
          do
          {
            v14 = v13 & (unsigned int)(-1LL << v12);
            if ( !(_DWORD)v14 )
              break;
            v15 = __clz(__rbit64(v14));
            if ( !*(_DWORD *)(a1 + 824 + 4 * v15) )
            {
              *(_QWORD *)(v4 + 8 * v15) = sched_clock(v7);
              v7 = smp_call_function_single((unsigned int)v15, qcom_wdt_keep_alive_response, a1, 1);
              v13 = _cpu_online_mask;
            }
            v12 = v15 + 1;
          }
          while ( v15 < 0x1F );
        }
        while ( (*(_BYTE *)(a1 + 289) & 1) == 0 )
        {
          v29 = 0;
          v30 = 0;
          v27 = 0;
          v28 = 0;
          v26 = 0;
          init_wait_entry(&v26, 0);
          v7 = prepare_to_wait_event(a1 + 264, &v26, 1);
          if ( (*(_BYTE *)(a1 + 289) & 1) != 0 )
          {
LABEL_29:
            v7 = finish_wait(a1 + 264, &v26);
            break;
          }
          while ( !v7 )
          {
            schedule();
            v7 = prepare_to_wait_event(a1 + 264, &v26, 1);
            if ( *(_BYTE *)(a1 + 289) == 1 )
              goto LABEL_29;
          }
          if ( !(_DWORD)v7 )
            break;
        }
        v17 = *(_BYTE *)(a1 + 209);
        v18 = *(unsigned __int8 *)(a1 + 208);
        *(_BYTE *)(a1 + 288) = 0;
        *(_BYTE *)(a1 + 289) = v17 ^ 1;
        if ( v18 == 1 )
        {
          v25 = _msecs_to_jiffies(*(unsigned int *)(a1 + 24));
          v19 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 16) + 16LL);
          if ( *((_DWORD *)v19 - 1) != 2060914831 )
            __break(0x8228u);
          v20 = v19(a1);
          v7 = sched_clock(v20);
          *(_QWORD *)(a1 + 40) = v7;
        }
        should_stop = kthread_should_stop(v7);
        if ( (should_stop & 1) == 0 )
        {
          raw_spin_lock(a1 + 956);
          if ( (*(_BYTE *)(a1 + 952) & 1) == 0 )
            mod_timer(a1 + 224, jiffies + v25);
          should_stop = raw_spin_unlock(a1 + 956);
        }
        v22 = nr_ipi_get(should_stop);
        _rcu_read_lock();
        if ( nr_irqs >= 1 )
        {
          v23 = 0;
          do
          {
            if ( v23 > v22 )
            {
              v24 = irq_to_desc((unsigned int)v23);
              if ( v24 )
                *(_QWORD *)(v24 + 472) = (unsigned int)kstat_irqs_usr((unsigned int)v23);
            }
            ++v23;
          }
          while ( v23 < nr_irqs );
        }
        unlock = _rcu_read_unlock();
        if ( (kthread_should_stop(unlock) & 1) != 0 )
          break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
