__int64 __fastcall sub_4EE9DC(__int64 a1, __int64 a2)
{
  __int64 v2; // x11

  if ( (v2 & 0x4000000000LL) == 0 )
    JUMPOUT(0x4EC824);
  return wma_ht40_stop_obss_scan(a1, a2);
}
