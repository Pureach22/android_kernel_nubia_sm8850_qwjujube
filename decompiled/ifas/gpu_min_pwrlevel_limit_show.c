__int64 __fastcall gpu_min_pwrlevel_limit_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (*v4)(void); // x8
  int v5; // w3
  int v7; // w20
  int v8; // w20

  v4 = (__int64 (*)(void))kgsl_pwrctrl_get_min_level_fp;
  if ( kgsl_pwrctrl_get_min_level_fp )
  {
    if ( *(_DWORD *)(kgsl_pwrctrl_get_min_level_fp - 4LL) != -605791253 )
      __break(0x8228u);
    v5 = v4();
  }
  else
  {
    v7 = gpu_num_freqs - 1;
    printk(&unk_F009, "gpu_get_min_level");
    v5 = v7;
  }
  if ( ifas_log_enable )
  {
    v8 = v5;
    printk(&unk_F6C4, "gpu_get_min_level");
    v5 = v8;
  }
  return (int)scnprintf(a3, 4096, "%d\n", v5);
}
