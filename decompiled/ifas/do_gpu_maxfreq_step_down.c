__int64 do_gpu_maxfreq_step_down()
{
  __int64 (*v0)(void); // x8
  int v1; // w0
  __int64 (*v2)(void); // x8
  int v3; // w19
  __int64 v4; // x0
  __int64 (__fastcall *v5)(__int64); // x8
  int v6; // w19
  int v7; // w8
  __int64 result; // x0
  unsigned int v9; // w19
  int v10; // w20
  __int64 (__fastcall *v11)(_QWORD); // x8

  if ( (gpu_num_freqs_inited & 1) == 0 )
  {
    v0 = (__int64 (*)(void))kgsl_gpu_num_freqs_fp;
    if ( kgsl_gpu_num_freqs_fp )
    {
      if ( *(_DWORD *)(kgsl_gpu_num_freqs_fp - 4LL) != 1874538549 )
        __break(0x8228u);
      v1 = v0();
      if ( v1 )
        gpu_num_freqs = v1;
      if ( !ifas_log_enable )
        goto LABEL_8;
    }
    else
    {
      printk(&unk_10124, "gpu_get_num_freqs");
      if ( !ifas_log_enable )
      {
LABEL_8:
        gpu_num_freqs_inited = 1;
        goto LABEL_9;
      }
    }
    printk(&unk_10700, "gpu_get_num_freqs");
    goto LABEL_8;
  }
LABEL_9:
  v2 = (__int64 (*)(void))kgsl_pwrctrl_get_max_level_fp;
  if ( !kgsl_pwrctrl_get_max_level_fp )
  {
    printk(&unk_EE85, "gpu_get_max_level");
    v3 = 0;
    if ( !ifas_log_enable )
      goto LABEL_13;
    goto LABEL_37;
  }
  if ( *(_DWORD *)(kgsl_pwrctrl_get_max_level_fp - 4LL) != -605791253 )
    __break(0x8228u);
  v3 = v2();
  if ( ifas_log_enable )
LABEL_37:
    printk(&unk_F535, "gpu_get_max_level");
LABEL_13:
  mutex_lock(&gpu_ctrl_lock);
  cur_gpu_max_level = v3;
  v4 = mutex_unlock(&gpu_ctrl_lock);
  v5 = (__int64 (__fastcall *)(__int64))kgsl_pwrctrl_get_loading_fp;
  if ( !kgsl_pwrctrl_get_loading_fp )
  {
    printk(&unk_106BF, "gpu_get_loading");
    v6 = 0;
    if ( !ifas_log_enable )
      goto LABEL_17;
    goto LABEL_39;
  }
  if ( *(_DWORD *)(kgsl_pwrctrl_get_loading_fp - 4LL) != 1874538549 )
    __break(0x8228u);
  v6 = v5(v4);
  if ( ifas_log_enable )
LABEL_39:
    printk(&unk_F867, "gpu_get_loading");
LABEL_17:
  ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)v6, "gpu:loading");
  mutex_lock(&gpu_ctrl_lock);
  if ( v6 <= gpu_loading_high )
  {
    v7 = gpu_num_freqs - 1;
    if ( cur_gpu_max_level == gpu_num_freqs - 1 )
    {
      if ( ifas_log_enable )
        printk(&unk_ED1D, "do_gpu_maxfreq_step_down");
      return mutex_unlock(&gpu_ctrl_lock);
    }
    if ( cur_gpu_max_level + rescue_gpu_level_down + 1 < gpu_num_freqs )
      v7 = cur_gpu_max_level + rescue_gpu_level_down + 1;
    cur_gpu_max_level = v7;
    if ( ifas_log_enable )
      printk(&unk_E91F, "do_gpu_maxfreq_step_down");
  }
  result = mutex_unlock(&gpu_ctrl_lock);
  v9 = cur_gpu_max_level;
  if ( (cur_gpu_max_level & 0x80000000) == 0 )
  {
    v10 = gpu_max_pwrlevel_ceiling;
    if ( gpu_max_pwrlevel_ceiling >= (unsigned int)cur_gpu_max_level )
    {
      ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)gpu_max_pwrlevel_ceiling, "gpu:ceiling_level");
      v9 = v10;
    }
    if ( kgsl_pwrctrl_set_max_level_fp )
    {
      if ( ifas_log_enable )
        printk(&unk_F2DA, "gpu_set_max_level");
      ifas_systrace_c((unsigned int)saved_connected_pid, v9, "gpu:max_level");
      v11 = (__int64 (__fastcall *)(_QWORD))kgsl_pwrctrl_set_max_level_fp;
      if ( *(_DWORD *)(kgsl_pwrctrl_set_max_level_fp - 4LL) != 274542313 )
        __break(0x8228u);
      return v11(v9);
    }
    else
    {
      return printk(&unk_10510, "gpu_set_max_level");
    }
  }
  return result;
}
