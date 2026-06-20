__int64 icnss_is_rejuvenate()
{
  if ( penv )
    return (*(_QWORD *)(penv + 1832) >> 15) & 1LL;
  else
    return 0;
}
