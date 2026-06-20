__int64 __fastcall sub_48F028(__int64 a1, __int64 a2)
{
  __int64 v2; // x10

  if ( (v2 & 0x100000000LL) != 0 )
    JUMPOUT(0x48A330);
  return sme_stats_ext_request(a1, a2);
}
