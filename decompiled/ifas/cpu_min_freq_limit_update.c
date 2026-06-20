__int64 __fastcall cpu_min_freq_limit_update(unsigned int a1, const char *a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x20
  int v9; // w22
  __int64 v10; // x28
  unsigned int v11; // w24
  unsigned int v12; // w8
  __int64 v13; // x10
  unsigned int v14; // w23
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned __int64 v17; // x22
  _DWORD *v18; // x22
  unsigned int v19; // w8
  unsigned int v20; // w9
  __int64 v21; // x21
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( accept_userset_freq_min && cluster_num > (int)a1 )
  {
    v23 = 0;
    v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
    v8 = v6;
    if ( v6 )
    {
      if ( (unsigned __int64)(a3 - 1) > 0x7E || !(unsigned int)scnprintf(v6, 128, "%s", a2) )
      {
        v9 = -1;
        goto LABEL_9;
      }
      if ( !(unsigned int)kstrtoint(v8, 0, &v23) )
      {
        v9 = v23;
LABEL_9:
        ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)(1000 * v9), "cpu:clus%d:userset_min_freq", a1);
        v10 = cpufreq_dev + 344LL * a1;
        if ( ifas_log_enable )
          printk(&unk_F4D2, "find_freq_index");
        v11 = *(_DWORD *)(v10 + 24);
        v12 = 0;
        while ( (unsigned int)(1000 * v9) < *(_DWORD *)(*(_QWORD *)(v10 + 32) + 4LL * (int)v12) )
        {
          if ( ++v12 > v11 )
            goto LABEL_30;
        }
        if ( v12 == -1 )
        {
LABEL_30:
          printk(&unk_10605, "find_freq_index");
          v12 = v11;
          if ( (v11 & 0x80000000) != 0 )
            goto LABEL_31;
        }
        else if ( (v12 & 0x80000000) != 0 )
        {
          goto LABEL_31;
        }
        v13 = cpufreq_dev + 344LL * a1;
        if ( v12 <= *(_DWORD *)(v13 + 24) )
        {
          *(_DWORD *)(v13 + 16) = v12;
          if ( ifas_log_enable )
            printk(&unk_100B9, "cpu_min_freq_limit_update");
          mutex_lock(&cpu_ctrl_lock);
          v14 = *(_DWORD *)(cpufreq_dev + 344LL * a1 + 12);
          mutex_unlock(&cpu_ctrl_lock);
          v15 = cpufreq_dev;
          if ( v14 > *(_DWORD *)(cpufreq_dev + 344LL * a1 + 16) )
          {
            mutex_lock(&cpu_ctrl_lock);
            v16 = cpufreq_dev + 344LL * a1;
            v17 = *(unsigned int *)(v16 + 16);
            *(_DWORD *)(v16 + 12) = v17;
            mutex_unlock(&cpu_ctrl_lock);
            cpufreq_set_level_max((_DWORD *)(cpufreq_dev + 344LL * a1), v17, 1);
            v15 = cpufreq_dev;
          }
          v18 = (_DWORD *)(v15 + 344LL * a1);
          v19 = v18[4];
          v20 = v18[6];
          if ( v20 >= v19 )
            v21 = v19;
          else
            v21 = v20;
          if ( ifas_log_enable )
            printk(&unk_FA78, "cpufreq_set_level_min");
          ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)v21, "cpu:clus%d:min_level", *v18);
          ifas_systrace_c(
            (unsigned int)saved_connected_pid,
            *(unsigned int *)(*((_QWORD *)v18 + 4) + 4 * v21),
            "cpu:clus%d:min_freq",
            *v18);
          freq_qos_update_request(*((_QWORD *)v18 + 9), *(unsigned int *)(*((_QWORD *)v18 + 4) + 4 * v21));
          goto LABEL_28;
        }
LABEL_31:
        printk(&unk_F0F8, "cpu_min_freq_limit_update");
      }
    }
LABEL_28:
    kfree(v8, v7);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
