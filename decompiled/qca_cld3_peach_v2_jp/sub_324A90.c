__int64 __fastcall sub_324A90(__int64 a1, __int64 a2)
{
  __int64 v2; // x12

  if ( (v2 & 0x100000000000000LL) == 0 )
    JUMPOUT(0x324DD0);
  return _wlan_hdd_validate_context(a1, a2);
}
