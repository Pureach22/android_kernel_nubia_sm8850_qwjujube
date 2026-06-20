__int64 __fastcall ieee80211_link_setup(__int64 result, __int64 a2)
{
  if ( *(_DWORD *)(*(_QWORD *)result + 4720LL) == 2 )
    return ((__int64 (__fastcall *)(__int64, __int64))ieee80211_mgd_setup_link)(result, a2);
  return result;
}
