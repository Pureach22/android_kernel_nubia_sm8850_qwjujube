bool __fastcall rmnet_map_v5_csum_buggy(unsigned int *a1)
{
  unsigned int v1; // w8
  int v2; // w9
  _BOOL8 result; // x0

  v1 = *a1;
  result = false;
  if ( (*a1 & 0x7000) == 0x1000 && *((_BYTE *)a1 + 7) == 1 )
  {
    v2 = HIWORD(v1) & 0xF;
    if ( v2 == 4 || v2 == 3 && ((v1 >> 20) & 0xF) - 1 < 3 )
      return true;
  }
  return result;
}
