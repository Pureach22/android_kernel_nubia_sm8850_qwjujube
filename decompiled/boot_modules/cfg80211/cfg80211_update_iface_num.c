__int64 __fastcall cfg80211_update_iface_num(__int64 result, int a2, int a3)
{
  *(_DWORD *)(result + 164) += a3;
  if ( a2 == 6 )
    *(_DWORD *)(result + 168) += a3;
  return result;
}
