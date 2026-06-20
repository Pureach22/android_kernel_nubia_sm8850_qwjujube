__int64 __fastcall gpu_max_pwrlevel_ceiling_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x20
  int v9; // w21
  int v10; // w23
  unsigned int v11; // w22
  void (__fastcall *v12)(_QWORD); // x8
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
  v8 = v6;
  if ( !v6 )
    goto LABEL_15;
  if ( (unsigned __int64)(a4 - 1) <= 0x7E && (unsigned int)scnprintf(v6, 128, "%s", a3) )
  {
    if ( (unsigned int)kstrtoint(v8, 0, &v14) )
      goto LABEL_15;
    v9 = v14;
  }
  else
  {
    v9 = -1;
  }
  mutex_lock(&gpu_ctrl_lock);
  gpu_max_pwrlevel_ceiling = v9;
  mutex_unlock(&gpu_ctrl_lock);
  v10 = gpu_max_pwrlevel_ceiling;
  v11 = cur_gpu_max_level;
  if ( gpu_max_pwrlevel_ceiling >= (unsigned int)cur_gpu_max_level )
  {
    ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)gpu_max_pwrlevel_ceiling, "gpu:ceiling_level");
    v11 = v10;
  }
  if ( !kgsl_pwrctrl_set_max_level_fp )
  {
    printk(&unk_10510, "gpu_set_max_level");
    if ( !ifas_log_enable )
      goto LABEL_15;
LABEL_17:
    printk(&unk_F16E, "gpu_max_pwrlevel_ceiling_store");
    goto LABEL_15;
  }
  if ( ifas_log_enable )
    printk(&unk_F2DA, "gpu_set_max_level");
  ifas_systrace_c((unsigned int)saved_connected_pid, v11, "gpu:max_level");
  v12 = (void (__fastcall *)(_QWORD))kgsl_pwrctrl_set_max_level_fp;
  if ( *(_DWORD *)(kgsl_pwrctrl_set_max_level_fp - 4LL) != 274542313 )
    __break(0x8228u);
  v12(v11);
  if ( ifas_log_enable )
    goto LABEL_17;
LABEL_15:
  kfree(v8, v7);
  _ReadStatusReg(SP_EL0);
  return a4;
}
