__int64 __fastcall gpu_set_max_level(unsigned int a1)
{
  unsigned int v1; // w19
  int v2; // w20
  __int64 (__fastcall *v3)(_QWORD); // x8

  v1 = a1;
  v2 = gpu_max_pwrlevel_ceiling;
  if ( gpu_max_pwrlevel_ceiling >= a1 )
  {
    ifas_systrace_c((unsigned int)saved_connected_pid, (unsigned int)gpu_max_pwrlevel_ceiling, "gpu:ceiling_level");
    v1 = v2;
  }
  if ( !kgsl_pwrctrl_set_max_level_fp )
    return printk(&unk_10510, "gpu_set_max_level");
  if ( ifas_log_enable )
    printk(&unk_F2DA, "gpu_set_max_level");
  ifas_systrace_c((unsigned int)saved_connected_pid, v1, "gpu:max_level");
  v3 = (__int64 (__fastcall *)(_QWORD))kgsl_pwrctrl_set_max_level_fp;
  if ( *(_DWORD *)(kgsl_pwrctrl_set_max_level_fp - 4LL) != 274542313 )
    __break(0x8228u);
  return v3(v1);
}
