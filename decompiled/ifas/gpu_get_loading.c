__int64 gpu_get_loading()
{
  __int64 (*v0)(void); // x8
  unsigned int v1; // w19

  v0 = (__int64 (*)(void))kgsl_pwrctrl_get_loading_fp;
  if ( kgsl_pwrctrl_get_loading_fp )
  {
    if ( *(_DWORD *)(kgsl_pwrctrl_get_loading_fp - 4LL) != 1874538549 )
      __break(0x8228u);
    v1 = v0();
  }
  else
  {
    printk(&unk_106BF, "gpu_get_loading");
    v1 = 0;
  }
  if ( ifas_log_enable )
    printk(&unk_F867, "gpu_get_loading");
  ifas_systrace_c((unsigned int)saved_connected_pid, v1, "gpu:loading");
  return v1;
}
