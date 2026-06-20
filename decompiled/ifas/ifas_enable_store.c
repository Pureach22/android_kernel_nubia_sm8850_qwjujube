__int64 __fastcall ifas_enable_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x21
  int v9; // w22
  __int64 v10; // x25
  __int64 v11; // x20
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v6 = _kmalloc_cache_noprof(ktime_get, 3520, 128);
  v8 = v6;
  v9 = 0;
  if ( (unsigned __int64)(a4 - 1) <= 0x7E && v6 )
  {
    if ( (unsigned int)scnprintf(v6, 128, "%s", a3) )
    {
      if ( (unsigned int)kstrtoint(v8, 0, &v13) )
        v9 = 0;
      else
        v9 = v13;
    }
    else
    {
      v9 = 0;
    }
  }
  kfree(v8, v7);
  set_ifas_enable(v9);
  if ( ifas_log_enable )
  {
    printk(&unk_10699, "ifas_enable_store");
    if ( v9 )
      goto LABEL_16;
  }
  else if ( v9 )
  {
    goto LABEL_16;
  }
  if ( cluster_num >= 1 )
  {
    v10 = 0;
    v11 = 0;
    do
    {
      cpufreq_set_level_max((_DWORD *)(cpufreq_dev + v10), 0, 0);
      if ( ifas_log_enable )
        printk(&unk_F639, "do_maxfreq_release");
      ++v11;
      v10 += 344;
    }
    while ( v11 < cluster_num );
  }
  update_cpu_loading_locked();
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return a4;
}
