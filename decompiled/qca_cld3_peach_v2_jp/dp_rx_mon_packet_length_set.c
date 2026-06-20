int *__fastcall dp_rx_mon_packet_length_set(int *result, __int64 a2)
{
  int v2; // w8
  int v3; // w8

  if ( result )
  {
    if ( a2 )
    {
      v2 = ((*(_DWORD *)(a2 + 74) & 7) << 16) | *result;
      *result = v2;
      v3 = (*(_DWORD *)(a2 + 74) << 16) & 0x380000 | v2;
      *result = v3;
      *result = (*(_DWORD *)(a2 + 74) << 16) & 0x1C00000 | v3;
    }
  }
  return result;
}
