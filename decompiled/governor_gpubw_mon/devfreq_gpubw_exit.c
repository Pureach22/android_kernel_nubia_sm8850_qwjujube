// Alternative name is 'cleanup_module'
__int64 devfreq_gpubw_exit()
{
  __int64 result; // x0

  result = devfreq_remove_governor(&devfreq_gpubw);
  if ( (_DWORD)result )
    return printk(&unk_68A4, "devfreq_gpubw_exit", (unsigned int)result);
  return result;
}
