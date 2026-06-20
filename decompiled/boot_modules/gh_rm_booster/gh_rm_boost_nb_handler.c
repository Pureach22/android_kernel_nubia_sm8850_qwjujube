__int64 __fastcall gh_rm_boost_nb_handler(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v4; // x2
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  __int64 v12; // x8
  unsigned int v13; // w19
  __int64 v14; // x0
  __int64 v21; // x0
  const char *v22; // x1
  __int64 v23; // x0
  int v24; // w9
  __int64 v26; // [xsp+0h] [xbp-10h]
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1443889160 )
  {
    v3 = *(unsigned __int8 *)(a3 + 4);
    if ( v3 == 3 || v3 == 8 )
    {
      v23 = mutex_lock(&rm_booster_lock);
      if ( *(_DWORD *)rm_status )
      {
        v24 = *(_DWORD *)rm_status - 1;
        *(_DWORD *)rm_status = v24;
        if ( !v24 )
        {
          gh_resume_rm_status(v23);
          mutex_unlock(&rm_booster_lock);
          cancel_delayed_work_sync(rm_status + 128);
          goto LABEL_17;
        }
      }
      goto LABEL_16;
    }
    if ( v3 == 6 )
    {
      cancel_delayed_work_sync(rm_status + 128);
      mutex_lock(&rm_booster_lock);
      v4 = rm_status;
      ++*(_DWORD *)rm_status;
      queue_delayed_work_on(32, system_wq, v4 + 128, 1250);
      v12 = rm_status;
      if ( *(_DWORD *)rm_status >= 2u )
        goto LABEL_16;
      v13 = target_cpu;
      if ( target_cpu != *(_DWORD *)(rm_status + 8) )
      {
        v14 = *(_QWORD *)(rm_status + 232);
        if ( v14 == -1 )
        {
          v13 = *(_DWORD *)(rm_status + 8);
        }
        else
        {
          v5 = *(_QWORD *)(rm_status + 24);
          v6 = 0;
          v7 = 0;
          v8 = 0;
          v9 = 0;
          v10 = 0;
          v11 = 0;
          __asm { HVC             #0x603D }
          v26 = 0;
          if ( (_DWORD)v14 == 1 )
          {
            v5 = target_cpu;
            v6 = -1;
            v7 = 0;
            v8 = 0;
            v14 = *(_QWORD *)(rm_status + 232);
            v9 = 0;
            v10 = 0;
            v11 = 0;
            __asm { HVC             #0x603D }
            v26 = 0;
          }
          if ( !(_DWORD)v14 )
            goto LABEL_11;
          dev_err(*(_QWORD *)(rm_status + 32), "gh set RM affinity fail\n");
          v12 = rm_status;
          v13 = *(_DWORD *)(rm_status + 8);
        }
        dev_info(*(_QWORD *)(v12 + 32), "Fallback to boost the frequency of RM current cpu - CPU%d\n", v13);
      }
LABEL_11:
      v21 = cpufreq_cpu_get(v13, v5, v6, v7, v8, v9, v10, v11, v26, v27);
      if ( !v21 )
      {
        v22 = "Failed to get RM cpufreq policy\n";
        goto LABEL_20;
      }
      if ( (freq_qos_add_request(v21 + 144, rm_status + 40, 1, *(unsigned int *)(v21 + 56)) & 0x80000000) != 0 )
      {
        v22 = "Failed to boost RM freq\n";
LABEL_20:
        dev_err(*(_QWORD *)(rm_status + 32), v22);
      }
LABEL_16:
      mutex_unlock(&rm_booster_lock);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return 0;
}
