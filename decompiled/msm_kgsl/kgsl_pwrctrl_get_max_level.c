__int64 kgsl_pwrctrl_get_max_level()
{
  char *device; // x0
  char *v1; // x21
  unsigned int v2; // w19

  device = (char *)kgsl_get_device(0);
  if ( device )
  {
    v1 = device;
    rt_mutex_lock(device + 11088);
    v2 = *((_DWORD *)v1 + 2514);
    rt_mutex_unlock(v1 + 11088);
  }
  else
  {
    return (unsigned int)-19;
  }
  return v2;
}
