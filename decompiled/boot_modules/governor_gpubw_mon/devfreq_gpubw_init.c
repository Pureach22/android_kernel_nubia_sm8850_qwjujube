// Alternative name is 'init_module'
__int64 devfreq_gpubw_init()
{
  return devfreq_add_governor(&devfreq_gpubw);
}
