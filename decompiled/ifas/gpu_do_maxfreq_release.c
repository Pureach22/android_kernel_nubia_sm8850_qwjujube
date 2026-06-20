__int64 gpu_do_maxfreq_release()
{
  void (__fastcall *v0)(_QWORD); // x8
  __int64 result; // x0

  v0 = (void (__fastcall *)(_QWORD))kgsl_pwrctrl_set_max_level_fp;
  if ( *(_DWORD *)(kgsl_pwrctrl_set_max_level_fp - 4LL) != 274542313 )
    __break(0x8228u);
  v0(0);
  result = ifas_systrace_c((unsigned int)saved_connected_pid, 0, "gpu:gpu_do_maxfreq_release");
  if ( ifas_log_enable )
    return printk(&unk_EB6A, "gpu_do_maxfreq_release");
  return result;
}
