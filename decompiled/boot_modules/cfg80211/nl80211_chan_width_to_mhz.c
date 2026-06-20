__int64 __fastcall nl80211_chan_width_to_mhz(unsigned int a1)
{
  if ( a1 < 0xE )
    return dword_BA144[a1];
  __break(0x800u);
  return 0xFFFFFFFFLL;
}
