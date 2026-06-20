__int64 __fastcall ieee80211_chandef_num_subchans(__int64 a1)
{
  __int64 v1; // x0

  v1 = *(unsigned int *)(a1 + 8);
  if ( (_DWORD)v1 == 4 )
    return 8;
  else
    return (unsigned int)((int)nl80211_chan_width_to_mhz(v1) / 20);
}
