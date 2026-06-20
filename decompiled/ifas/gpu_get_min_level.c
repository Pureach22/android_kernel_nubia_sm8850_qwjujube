__int64 gpu_get_min_level()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0
  unsigned int v2; // w19
  unsigned int v3; // w19

  v0 = (__int64 (*)(void))kgsl_pwrctrl_get_min_level_fp;
  if ( kgsl_pwrctrl_get_min_level_fp )
  {
    if ( *(_DWORD *)(kgsl_pwrctrl_get_min_level_fp - 4LL) != -605791253 )
      __break(0x8228u);
    result = v0();
  }
  else
  {
    v2 = gpu_num_freqs - 1;
    printk(&unk_F009, "gpu_get_min_level");
    result = v2;
  }
  if ( ifas_log_enable )
  {
    v3 = result;
    printk(&unk_F6C4, "gpu_get_min_level");
    return v3;
  }
  return result;
}
