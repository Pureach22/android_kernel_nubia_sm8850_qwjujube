__int64 __fastcall sub_54B5F0(__int64 a1, __int64 a2)
{
  __int64 v2; // x11

  if ( (v2 & 0x200000000000LL) == 0 )
    JUMPOUT(0x54B7C0);
  return dbglog_set_log_lvl(a1, a2);
}
