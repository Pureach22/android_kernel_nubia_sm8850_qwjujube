__int64 __fastcall dot11f_get_packed_ie_reduced_neighbor_report(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8

  if ( *a2 )
  {
    v3 = *a3;
    *a3 += 4;
    if ( (unsigned __int8)(a2[2] - 1) <= 0xFu && ((0x9DF3u >> (a2[2] - 1)) & 1) != 0 )
      *a3 = v3 + dword_A16070[(unsigned __int8)(a2[2] - 1)];
  }
  return 0;
}
