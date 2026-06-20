__int64 cnss_get_wifi_kobj()
{
  if ( plat_env )
    return *(_QWORD *)(plat_env + 7744);
  else
    return 0;
}
