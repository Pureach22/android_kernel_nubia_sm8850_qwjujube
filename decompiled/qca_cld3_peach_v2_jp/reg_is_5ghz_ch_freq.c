bool __fastcall reg_is_5ghz_ch_freq(unsigned int a1)
{
  return *(_DWORD *)(channel_map + 168) <= a1 && *(_DWORD *)(channel_map + 492) >= a1;
}
