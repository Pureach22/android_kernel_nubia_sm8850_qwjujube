__int64 kgsl_gpu_num_freqs()
{
  unsigned int *device; // x0

  device = (unsigned int *)kgsl_get_device(0);
  if ( device )
    return device[2517];
  else
    return 4294967277LL;
}
