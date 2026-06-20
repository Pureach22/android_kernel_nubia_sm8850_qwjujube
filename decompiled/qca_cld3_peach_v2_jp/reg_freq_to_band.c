__int64 __fastcall reg_freq_to_band(unsigned int a1)
{
  if ( !a1 )
    return 3;
  if ( *(_DWORD *)channel_map <= a1 && *(_DWORD *)(channel_map + 156) >= a1 )
    return 0;
  if ( *(_DWORD *)(channel_map + 168) <= a1 && *(_DWORD *)(channel_map + 492) >= a1 )
    return 1;
  if ( *(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a1 )
    return 3;
  if ( *(_DWORD *)(channel_map + 1212) >= (unsigned int)(unsigned __int16)a1 )
    return 2;
  else
    return 3;
}
