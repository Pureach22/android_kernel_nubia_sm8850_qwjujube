bool __fastcall reg_is_24ghz_ch_freq(unsigned int a1)
{
  return *(_DWORD *)channel_map <= a1 && *(_DWORD *)(channel_map + 156) >= a1;
}
