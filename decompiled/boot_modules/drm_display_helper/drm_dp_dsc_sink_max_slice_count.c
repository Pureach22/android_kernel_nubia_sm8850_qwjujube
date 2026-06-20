__int64 __fastcall drm_dp_dsc_sink_max_slice_count(__int64 a1, char a2)
{
  unsigned int v2; // w8

  v2 = *(unsigned __int8 *)(a1 + 4);
  if ( (a2 & 1) != 0 )
  {
    if ( (v2 & 8) == 0 )
    {
      if ( (v2 & 2) == 0 )
        return (v2 & 1) != 0;
      return 2;
    }
    return 4;
  }
  if ( (*(_BYTE *)(a1 + 13) & 4) != 0 )
    return 24;
  if ( (*(_BYTE *)(a1 + 13) & 2) != 0 )
    return 20;
  if ( (*(_BYTE *)(a1 + 13) & 1) != 0 )
    return 16;
  if ( (v2 & 0x80) != 0 )
    return 12;
  if ( v2 > 0x3F )
    return 10;
  if ( v2 > 0x1F )
    return 8;
  if ( v2 <= 0xF )
  {
    if ( v2 <= 7 )
    {
      if ( (v2 & 2) == 0 )
        return (v2 & 1) != 0;
      return 2;
    }
    return 4;
  }
  return 6;
}
