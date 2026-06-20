__int64 __fastcall ieee80211_key_replay(__int64 result)
{
  unsigned int v1; // w8

  v1 = *(_DWORD *)(result + 8) - 1027076;
  if ( v1 <= 9 && ((0x3F5u >> v1) & 1) != 0 )
    ++*(_DWORD *)(result + qword_C02A8[v1]);
  return result;
}
