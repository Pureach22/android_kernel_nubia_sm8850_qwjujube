__int64 cnss_utils_get_cc_source()
{
  if ( cnss_utils_priv )
    return *(unsigned int *)(cnss_utils_priv + 448);
  else
    return 4294967274LL;
}
