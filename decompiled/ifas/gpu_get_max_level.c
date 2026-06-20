__int64 gpu_get_max_level()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0
  unsigned int v2; // w19

  v0 = (__int64 (*)(void))kgsl_pwrctrl_get_max_level_fp;
  if ( kgsl_pwrctrl_get_max_level_fp )
  {
    if ( *(_DWORD *)(kgsl_pwrctrl_get_max_level_fp - 4LL) != -605791253 )
      __break(0x8228u);
    result = v0();
  }
  else
  {
    printk(&unk_EE85, "gpu_get_max_level");
    result = 0;
  }
  if ( ifas_log_enable )
  {
    v2 = result;
    printk(&unk_F535, "gpu_get_max_level");
    return v2;
  }
  return result;
}
