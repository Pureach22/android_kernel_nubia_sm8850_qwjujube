__int64 __fastcall sub_5B4174(__int64 a1, __int64 a2)
{
  __int64 v2; // x11

  if ( (v2 & 0x200000000000LL) == 0 )
    JUMPOUT(0x5B4344);
  return dbglog_set_log_lvl(a1, a2);
}
