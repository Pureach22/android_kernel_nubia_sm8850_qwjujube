__int64 __fastcall gpu_max_pwrlevel_limit_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x20
  unsigned int v9; // w21
  unsigned int v10; // w22
  int v11; // w23
  void (__fastcall *v12)(_QWORD); // x8
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( accept_userset_gpu_freq_max )
  {
    v14 = 0;
    v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
    v8 = v6;
    if ( v6 )
    {
      if ( (unsigned __int64)(a4 - 1) <= 0x7E && (unsigned int)scnprintf(v6, 128, "%s", a3) )
      {
        if ( (unsigned int)kstrtoint(v8, 0, &v14) )
          goto LABEL_16;
        v9 = v14;
      }
      else
      {
        v9 = -1;
      }
      mutex_lock(&gpu_ctrl_lock);
      cur_gpu_max_level = v9;
      mutex_unlock(&gpu_ctrl_lock);
      v10 = v9;
      v11 = gpu_max_pwrlevel_ceiling;
      if ( gpu_max_pwrlevel_ceiling >= v9 )
      {
        ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)gpu_max_pwrlevel_ceiling, "gpu:ceiling_level");
        v10 = v11;
      }
      if ( kgsl_pwrctrl_set_max_level_fp )
      {
        if ( ifas_log_enable )
          printk(&unk_F2DA, "gpu_set_max_level");
        ifas_systrace_c((unsigned int)saved_connected_pid, v10, "gpu:max_level");
        v12 = (void (__fastcall *)(_QWORD))kgsl_pwrctrl_set_max_level_fp;
        if ( *(_DWORD *)(kgsl_pwrctrl_set_max_level_fp - 4LL) != 274542313 )
          __break(0x8228u);
        v12(v10);
        if ( !ifas_log_enable )
          goto LABEL_16;
        goto LABEL_19;
      }
      printk(&unk_10510, "gpu_set_max_level");
      if ( ifas_log_enable )
LABEL_19:
        printk(&unk_F89B, "gpu_max_pwrlevel_limit_store");
    }
LABEL_16:
    kfree(v8, v7);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
