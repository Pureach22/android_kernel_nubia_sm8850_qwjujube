__int64 __fastcall cpu_max_freq_ceiling_update(unsigned int a1, const char *a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x20
  int v9; // w22
  __int64 v10; // x28
  unsigned int v11; // w27
  unsigned int v12; // w26
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( cluster_num > (int)a1 )
  {
    v14 = 0;
    v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
    v8 = v6;
    if ( v6 )
    {
      if ( (unsigned __int64)(a3 - 1) > 0x7E || !(unsigned int)scnprintf(v6, 128, "%s", a2) )
      {
        v9 = 0;
        goto LABEL_8;
      }
      if ( !(unsigned int)kstrtoint(v8, 0, &v14) )
      {
        v9 = v14 + 1;
LABEL_8:
        ifas_systrace_c(
          (unsigned int)saved_connected_pid,
          (unsigned int)(1000 * v9),
          "cpu:clus%d:userset_ceiling_freq",
          a1);
        v10 = cpufreq_dev + 344LL * a1;
        if ( ifas_log_enable )
          printk(&unk_F4D2, "find_freq_index");
        v11 = *(_DWORD *)(v10 + 24);
        v12 = 0;
        while ( (unsigned int)(1000 * v9) < *(_DWORD *)(*(_QWORD *)(v10 + 32) + 4LL * (int)v12) )
        {
          if ( ++v12 > v11 )
            goto LABEL_21;
        }
        if ( v12 == -1 )
        {
LABEL_21:
          printk(&unk_10605, "find_freq_index");
          v12 = v11;
          if ( (v11 & 0x80000000) != 0 )
            goto LABEL_22;
        }
        else if ( (v12 & 0x80000000) != 0 )
        {
          goto LABEL_22;
        }
        if ( v12 <= *(_DWORD *)(cpufreq_dev + 344LL * a1 + 24) )
        {
          mutex_lock(&cpu_ctrl_lock);
          *(_DWORD *)(cpufreq_dev + 344LL * a1 + 20) = v12;
          mutex_unlock(&cpu_ctrl_lock);
          if ( ifas_log_enable )
            printk(&unk_104BE, "cpu_max_freq_ceiling_update");
          if ( v12 > *(_DWORD *)(cpufreq_dev + 344LL * a1 + 12) )
          {
            mutex_lock(&cpu_ctrl_lock);
            mutex_unlock(&cpu_ctrl_lock);
            cpufreq_set_level_max((_DWORD *)(cpufreq_dev + 344LL * a1), v12, 1);
          }
          goto LABEL_23;
        }
LABEL_22:
        printk(&unk_EF12, "cpu_max_freq_ceiling_update");
      }
    }
LABEL_23:
    kfree(v8, v7);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
