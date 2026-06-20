__int64 __fastcall drm_dp_pcon_dsc_max_slices(__int64 a1)
{
  unsigned int v1; // w8

  if ( (*(_BYTE *)(a1 + 10) & 4) != 0 )
    return 24;
  if ( (*(_BYTE *)(a1 + 10) & 2) != 0 )
    return 20;
  if ( (*(_BYTE *)(a1 + 10) & 1) != 0 )
    return 16;
  v1 = *(unsigned __int8 *)(a1 + 4);
  if ( (v1 & 0x80) != 0 )
    return 12;
  if ( v1 > 0x3F )
    return 10;
  if ( v1 > 0x1F )
    return 8;
  if ( v1 > 0xF )
    return 6;
  if ( v1 > 7 )
    return 4;
  if ( (v1 & 2) != 0 )
    return 2;
  return v1 & 1;
}
