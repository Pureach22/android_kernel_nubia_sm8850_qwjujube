__int64 icnss_is_pdr()
{
  if ( penv )
    return (*(_QWORD *)(penv + 1832) >> 18) & 1LL;
  else
    return 0;
}
