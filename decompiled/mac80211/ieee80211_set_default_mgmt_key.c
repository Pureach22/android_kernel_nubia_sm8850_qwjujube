__int64 __fastcall ieee80211_set_default_mgmt_key(__int64 result, unsigned int a2)
{
  unsigned __int64 v2; // x8

  if ( (a2 & 0xFFFFFFFE) == 4 )
    v2 = *(_QWORD *)(result + 8LL * a2 + 48);
  else
    v2 = 0;
  atomic_store(v2, (unsigned __int64 *)(result + 120));
  return result;
}
