__int64 waltgov_register()
{
  return cpufreq_register_governor(walt_gov);
}
