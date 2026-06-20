__int64 icnss_is_fw_ready()
{
  if ( penv )
    return (*(_QWORD *)(penv + 1832) >> 2) & 1LL;
  else
    return 0;
}
