__int64 __fastcall dp_rx_set_link_id_be(__int64 result, unsigned int a2)
{
  int v2; // w8

  if ( ((a2 >> 22) & 0xC) != 0 )
    v2 = 0;
  else
    v2 = ((a2 >> 22) & 0xF) + 1;
  *(_DWORD *)(result + 48) = (*(_DWORD *)(result + 48) & 0xFFC3FFFF) + (v2 << 18);
  return result;
}
