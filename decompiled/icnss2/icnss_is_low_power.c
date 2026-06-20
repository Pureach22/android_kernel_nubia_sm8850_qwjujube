__int64 icnss_is_low_power()
{
  if ( penv )
    return (*(_QWORD *)(penv + 1832) >> 26) & 1LL;
  else
    return 0;
}
