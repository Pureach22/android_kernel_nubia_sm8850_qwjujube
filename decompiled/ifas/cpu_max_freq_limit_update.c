__int64 __fastcall cpu_max_freq_limit_update(unsigned int a1, const char *a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x20
  int v9; // w22
  __int64 v10; // x28
  unsigned int v11; // w25
  unsigned int v12; // w26
  unsigned int v13; // w27
  unsigned __int64 v14; // x21
  unsigned __int64 v15; // x1
  int v16; // w2
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( accept_userset_freq_max && cluster_num > (int)a1 )
  {
    v18 = 0;
    v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
    v8 = v6;
    if ( v6 )
    {
      if ( (unsigned __int64)(a3 - 1) > 0x7E || !(unsigned int)scnprintf(v6, 128, "%s", a2) )
      {
        v9 = -1;
        goto LABEL_9;
      }
      if ( !(unsigned int)kstrtoint(v8, 0, &v18) )
      {
        v9 = v18;
LABEL_9:
        ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)(1000 * v9), "cpu:clus%d:userset_max_freq", a1);
        v10 = cpufreq_dev + 344LL * a1;
        v11 = a1;
        if ( ifas_log_enable )
          printk(&unk_F4D2, "find_freq_index");
        v12 = *(_DWORD *)(v10 + 24);
        v13 = 0;
        while ( (unsigned int)(1000 * v9) < *(_DWORD *)(*(_QWORD *)(v10 + 32) + 4LL * (int)v13) )
        {
          if ( ++v13 > v12 )
            goto LABEL_25;
        }
        if ( v13 == -1 )
        {
LABEL_25:
          printk(&unk_10605, "find_freq_index");
          v13 = v12;
          if ( (v12 & 0x80000000) != 0 )
            goto LABEL_26;
        }
        else if ( (v13 & 0x80000000) != 0 )
        {
          goto LABEL_26;
        }
        if ( v13 <= *(_DWORD *)(cpufreq_dev + 344LL * a1 + 24) )
        {
          mutex_lock(&cpu_ctrl_lock);
          *(_DWORD *)(cpufreq_dev + 344LL * a1 + 12) = v13;
          mutex_unlock(&cpu_ctrl_lock);
          if ( ifas_log_enable )
            printk(&unk_1001F, "cpu_max_freq_limit_update");
          if ( v13 <= *(_DWORD *)(cpufreq_dev + 344LL * a1 + 16) )
          {
            mutex_lock(&cpu_ctrl_lock);
            v14 = *(unsigned int *)(cpufreq_dev + 344LL * a1 + 12);
            mutex_unlock(&cpu_ctrl_lock);
            if ( (_DWORD)v14 )
            {
              v15 = v14;
              v16 = 1;
            }
            else
            {
              v15 = 0;
              v16 = 0;
            }
            cpufreq_set_level_max((_DWORD *)(cpufreq_dev + 344LL * v11), v15, v16);
          }
          goto LABEL_27;
        }
LABEL_26:
        printk(&unk_FD26, "cpu_max_freq_limit_update");
      }
    }
LABEL_27:
    kfree(v8, v7);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
