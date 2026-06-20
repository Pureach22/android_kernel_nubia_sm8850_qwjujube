bool __fastcall reg_is_6ghz_unii5_chan_freq(int a1)
{
  if ( *(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a1 )
    return 0;
  if ( *(_DWORD *)(channel_map + 1212) >= (unsigned int)(unsigned __int16)a1 )
    return (unsigned int)(a1 - 5935) < 0x1E1;
  return 0;
}
