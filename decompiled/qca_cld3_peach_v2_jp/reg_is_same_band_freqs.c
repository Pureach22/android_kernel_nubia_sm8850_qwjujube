__int64 __fastcall reg_is_same_band_freqs(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w9
  unsigned int v7; // w10
  unsigned int v8; // w8

  v2 = 0;
  if ( !a1 || !a2 )
    return v2;
  v3 = *(_DWORD *)(channel_map + 504);
  if ( v3 > (unsigned __int16)a1
    || (v4 = *(_DWORD *)(channel_map + 1212), v4 < (unsigned __int16)a1)
    || v3 > (unsigned __int16)a2
    || v4 < (unsigned __int16)a2 )
  {
    v5 = *(_DWORD *)(channel_map + 168);
    if ( v5 <= a1 )
    {
      v7 = *(_DWORD *)(channel_map + 492);
      if ( v7 >= a2 && v5 <= a2 && v7 >= a1 )
        return 1;
    }
    if ( *(_DWORD *)channel_map > a1 )
      return 0;
    v8 = *(_DWORD *)(channel_map + 156);
    return v8 >= a1 && v8 >= a2 && *(_DWORD *)channel_map <= a2;
  }
  return 1;
}
