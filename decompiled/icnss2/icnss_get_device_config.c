__int64 icnss_get_device_config()
{
  if ( penv )
    return *(_QWORD *)(penv + 5960);
  else
    return 0;
}
