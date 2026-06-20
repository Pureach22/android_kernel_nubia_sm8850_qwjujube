__int64 __fastcall gpu_min_pwrlevel_limit_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x20
  unsigned int v9; // w21
  void (__fastcall *v10)(_QWORD); // x8
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( accept_userset_gpu_freq_min )
  {
    v12 = 0;
    v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
    v8 = v6;
    if ( v6 )
    {
      if ( (unsigned __int64)(a4 - 1) > 0x7E || !(unsigned int)scnprintf(v6, 128, "%s", a3) )
      {
        v9 = -1;
        goto LABEL_8;
      }
      if ( !(unsigned int)kstrtoint(v8, 0, &v12) )
      {
        v9 = v12;
LABEL_8:
        if ( ifas_log_enable )
          printk(&unk_10A47, "gpu_min_pwrlevel_limit_store");
        if ( kgsl_pwrctrl_set_min_level_fp )
        {
          if ( gpu_num_freqs <= v9 )
            v9 = gpu_num_freqs - 1;
          if ( ifas_log_enable )
            printk(&unk_F20B, "gpu_set_min_level");
          ifas_systrace_c((unsigned int)saved_connected_pid, v9, "gpu:min_level");
          v10 = (void (__fastcall *)(_QWORD))kgsl_pwrctrl_set_min_level_fp;
          if ( *(_DWORD *)(kgsl_pwrctrl_set_min_level_fp - 4LL) != 274542313 )
            __break(0x8228u);
          v10(v9);
        }
        else
        {
          printk(&unk_E99B, "gpu_set_min_level");
        }
      }
    }
    kfree(v8, v7);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
