__int64 __fastcall gpu_max_pwrlevel_limit_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (*v4)(void); // x8
  int v5; // w3
  int v7; // w20

  v4 = (__int64 (*)(void))kgsl_pwrctrl_get_max_level_fp;
  if ( kgsl_pwrctrl_get_max_level_fp )
  {
    if ( *(_DWORD *)(kgsl_pwrctrl_get_max_level_fp - 4LL) != -605791253 )
      __break(0x8228u);
    v5 = v4();
  }
  else
  {
    printk(&unk_EE85, "gpu_get_max_level");
    v5 = 0;
  }
  if ( ifas_log_enable )
  {
    v7 = v5;
    printk(&unk_F535, "gpu_get_max_level");
    v5 = v7;
  }
  return (int)scnprintf(a3, 4096, "%d\n", v5);
}
