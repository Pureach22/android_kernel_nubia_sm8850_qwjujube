__int64 sub_436174()
{
  __int64 v0; // x10

  if ( (v0 & 0x100000000LL) != 0 )
    JUMPOUT(0x43147C);
  return sme_stats_ext_request();
}
