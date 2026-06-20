__int64 gpu_get_num_freqs()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))kgsl_gpu_num_freqs_fp;
  if ( kgsl_gpu_num_freqs_fp )
  {
    if ( *(_DWORD *)(kgsl_gpu_num_freqs_fp - 4LL) != 1874538549 )
      __break(0x8228u);
    result = v0();
    if ( (_DWORD)result )
      gpu_num_freqs = result;
  }
  else
  {
    result = printk(&unk_10124, "gpu_get_num_freqs");
  }
  if ( ifas_log_enable )
    return printk(&unk_10700, "gpu_get_num_freqs");
  return result;
}
