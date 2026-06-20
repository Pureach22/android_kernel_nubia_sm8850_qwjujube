// Alternative name is 'init_module'
__int64 msm_adreno_tz_init()
{
  return devfreq_add_governor(&msm_adreno_tz);
}
