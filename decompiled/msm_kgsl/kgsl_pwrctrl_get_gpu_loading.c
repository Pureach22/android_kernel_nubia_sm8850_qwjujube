__int64 kgsl_pwrctrl_get_gpu_loading()
{
  _DWORD *device; // x0
  unsigned int v1; // w8

  device = kgsl_get_device(0);
  if ( !device )
    return 4294967277LL;
  v1 = device[2591];
  if ( v1 )
    return 100 * device[2590] / v1;
  else
    return 0;
}
