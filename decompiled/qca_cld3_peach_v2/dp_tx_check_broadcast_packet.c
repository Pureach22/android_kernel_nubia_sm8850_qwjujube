bool __fastcall dp_tx_check_broadcast_packet(__int64 a1)
{
  unsigned __int8 *v1; // x8

  v1 = *(unsigned __int8 **)(a1 + 224);
  if ( *v1 != 255 )
    return 0;
  if ( v1[1] != 255 )
    return 0;
  if ( v1[2] != 255 )
    return 0;
  if ( v1[3] != 255 )
    return 0;
  if ( v1[4] == 255 )
    return v1[5] == 255;
  return 0;
}
