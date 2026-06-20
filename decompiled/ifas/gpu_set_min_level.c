__int64 __fastcall gpu_set_min_level(unsigned int a1)
{
  unsigned int v1; // w19
  __int64 (__fastcall *v2)(_QWORD); // x8

  if ( !kgsl_pwrctrl_set_min_level_fp )
    return printk(&unk_E99B, "gpu_set_min_level");
  if ( gpu_num_freqs <= a1 )
    v1 = gpu_num_freqs - 1;
  else
    v1 = a1;
  if ( ifas_log_enable )
    printk(&unk_F20B, "gpu_set_min_level");
  ifas_systrace_c((unsigned int)saved_connected_pid, v1, "gpu:min_level");
  v2 = (__int64 (__fastcall *)(_QWORD))kgsl_pwrctrl_set_min_level_fp;
  if ( *(_DWORD *)(kgsl_pwrctrl_set_min_level_fp - 4LL) != 274542313 )
    __break(0x8228u);
  return v2(v1);
}
