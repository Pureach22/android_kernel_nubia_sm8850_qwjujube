void cnss_utils_increment_driver_load_cnt()
{
  if ( cnss_utils_priv )
    ++*(_DWORD *)(cnss_utils_priv + 388);
}
