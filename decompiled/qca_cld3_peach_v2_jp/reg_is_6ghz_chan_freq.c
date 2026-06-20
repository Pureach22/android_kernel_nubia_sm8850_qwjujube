bool __fastcall reg_is_6ghz_chan_freq(unsigned __int16 a1)
{
  return *(_DWORD *)(channel_map + 504) <= (unsigned int)a1 && *(_DWORD *)(channel_map + 1212) >= (unsigned int)a1;
}
