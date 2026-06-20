__int64 cnss_utils_get_driver_load_cnt()
{
  if ( cnss_utils_priv )
    return *(unsigned int *)(cnss_utils_priv + 388);
  else
    return 4294967274LL;
}
