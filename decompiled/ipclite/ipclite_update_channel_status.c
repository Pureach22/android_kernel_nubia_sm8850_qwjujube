void ipclite_update_channel_status()
{
  __int16 v0; // w9
  __int64 v1; // x8

  v0 = enabled_hosts;
  v1 = ipclite;
  if ( (enabled_hosts & 1) != 0 )
    **(_DWORD **)(ipclite + 696) = *(_DWORD *)(ipclite + 704);
  if ( (v0 & 2) != 0 && *(_DWORD *)(v1 + 1408) )
  {
    **(_DWORD **)(v1 + 1400) = 1;
    *(_DWORD *)(v1 + 1408) = 1;
  }
  if ( (v0 & 4) != 0 && *(_DWORD *)(v1 + 2112) )
  {
    **(_DWORD **)(v1 + 2104) = 1;
    *(_DWORD *)(v1 + 2112) = 1;
  }
  if ( (v0 & 8) != 0 && *(_DWORD *)(v1 + 2816) )
  {
    **(_DWORD **)(v1 + 2808) = 1;
    *(_DWORD *)(v1 + 2816) = 1;
  }
  if ( (v0 & 0x10) != 0 && *(_DWORD *)(v1 + 3520) )
  {
    **(_DWORD **)(v1 + 3512) = 1;
    *(_DWORD *)(v1 + 3520) = 1;
  }
  if ( (v0 & 0x20) != 0 && *(_DWORD *)(v1 + 4224) )
  {
    **(_DWORD **)(v1 + 4216) = 1;
    *(_DWORD *)(v1 + 4224) = 1;
  }
  if ( (v0 & 0x40) != 0 && *(_DWORD *)(v1 + 4928) )
  {
    **(_DWORD **)(v1 + 4920) = 1;
    *(_DWORD *)(v1 + 4928) = 1;
  }
  if ( (v0 & 0x80) != 0 && *(_DWORD *)(v1 + 5632) )
  {
    **(_DWORD **)(v1 + 5624) = 1;
    *(_DWORD *)(v1 + 5632) = 1;
  }
  if ( (v0 & 0x100) != 0 )
  {
    if ( *(_DWORD *)(v1 + 6336) )
    {
      **(_DWORD **)(v1 + 6328) = 1;
      *(_DWORD *)(v1 + 6336) = 1;
    }
  }
}
