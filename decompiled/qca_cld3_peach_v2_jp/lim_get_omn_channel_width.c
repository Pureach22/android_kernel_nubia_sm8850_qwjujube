__int64 __fastcall lim_get_omn_channel_width(__int64 a1)
{
  unsigned int v1; // w10
  unsigned int v2; // w8

  v1 = *(_BYTE *)(a1 + 1) & 3;
  if ( (*(_BYTE *)(a1 + 1) & 4) != 0 )
    v2 = 3;
  else
    v2 = 2;
  if ( v1 != 2 )
    v2 = 8;
  if ( v1 >= 2 )
    return v2;
  else
    return *(_BYTE *)(a1 + 1) & 3;
}
