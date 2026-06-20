__int64 __fastcall cpufreq_set_level_max(_DWORD *a1, unsigned __int64 a2, int a3)
{
  unsigned __int64 v3; // x22
  unsigned __int64 v6; // x20
  __int64 result; // x0
  unsigned __int64 v8; // x20

  v3 = (unsigned int)a1[4];
  if ( v3 >= a2 )
  {
    if ( a3 )
    {
      v6 = (unsigned int)a1[5];
      v3 = a2;
      if ( v6 >= a2 )
      {
        ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)v6, "cpu:ceiling_level");
        v3 = v6;
      }
    }
    else
    {
      v3 = a2;
    }
  }
  result = get_ifas_enable();
  if ( (_DWORD)result )
    v8 = v3;
  else
    v8 = 0;
  if ( !a3 || v8 != a1[3] )
  {
    if ( ifas_log_enable )
      printk(&unk_EFA9, "cpufreq_set_level_max");
    mutex_lock(&cpu_ctrl_lock);
    a1[3] = v8;
    mutex_unlock(&cpu_ctrl_lock);
    ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)v8, "cpu:clus%d:max_level", *a1);
    ifas_systrace_c(
      (unsigned int)saved_connected_pid,
      *(unsigned int *)(*((_QWORD *)a1 + 4) + 4 * v8),
      "cpu:clus%d:max_freq",
      *a1);
    freq_qos_update_request(*((_QWORD *)a1 + 9), *(unsigned int *)(*((_QWORD *)a1 + 4) + 4LL * (unsigned int)a1[6]));
    if ( ifas_log_enable )
      printk(&unk_E8A6, "cpufreq_set_level_max");
    return freq_qos_update_request(*((_QWORD *)a1 + 8), *(unsigned int *)(*((_QWORD *)a1 + 4) + 4 * v8));
  }
  return result;
}
