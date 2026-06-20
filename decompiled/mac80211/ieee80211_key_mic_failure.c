__int64 __fastcall ieee80211_key_mic_failure(__int64 result)
{
  if ( (unsigned int)(*(_DWORD *)(result + 8) - 1027078) <= 7 && ((1 << (*(_BYTE *)(result + 8) - 6)) & 0xE1) != 0 )
    ++*(_DWORD *)(result - 468);
  return result;
}
