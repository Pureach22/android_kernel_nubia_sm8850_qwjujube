__int64 __fastcall ieee80211_chan_width_to_rx_bw(unsigned int a1)
{
  if ( a1 < 0xE && ((0x203Fu >> a1) & 1) != 0 )
    return dword_C0F88[a1];
  __break(0x800u);
  return 0;
}
