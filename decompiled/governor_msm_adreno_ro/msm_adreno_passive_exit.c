// Alternative name is 'cleanup_module'
__int64 msm_adreno_passive_exit()
{
  __int64 result; // x0

  result = devfreq_remove_governor(&msm_adreno_ro);
  if ( (_DWORD)result )
    return printk(&unk_6138, "msm_adreno_passive_exit", (unsigned int)result);
  return result;
}
