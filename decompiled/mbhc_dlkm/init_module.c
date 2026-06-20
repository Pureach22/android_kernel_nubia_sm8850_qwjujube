__int64 init_module()
{
  _mutex_init(&hphl_pa_lock, "&hphl_pa_lock", &mbhc_init___key);
  _mutex_init(&hphr_pa_lock, "&hphr_pa_lock", &mbhc_init___key_59);
  return 0;
}
