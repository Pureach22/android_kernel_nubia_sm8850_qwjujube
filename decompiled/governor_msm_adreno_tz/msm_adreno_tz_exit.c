// Alternative name is 'cleanup_module'
__int64 msm_adreno_tz_exit()
{
  __int64 result; // x0

  result = devfreq_remove_governor(&msm_adreno_tz);
  if ( (_DWORD)result )
    return printk(&unk_6DB6);
  return result;
}
