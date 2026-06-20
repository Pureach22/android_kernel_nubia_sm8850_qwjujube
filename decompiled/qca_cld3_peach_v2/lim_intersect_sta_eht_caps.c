void *__fastcall lim_intersect_sta_eht_caps(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  void *result; // x0

  if ( *(_BYTE *)(a4 + 68) == 1 )
  {
    v4 = *(unsigned __int8 *)(a3 + 154);
    if ( v4 <= 0xD && ((1 << v4) & 0x3001) != 0 )
      return lim_intersect_eht_caps(a2 + 3480, a4 + 932, a3);
  }
  return result;
}
