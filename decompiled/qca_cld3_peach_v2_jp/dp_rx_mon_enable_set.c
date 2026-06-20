_DWORD *__fastcall dp_rx_mon_enable_set(_DWORD *result, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w9

  if ( result && a2 )
  {
    v2 = (*(_DWORD *)(a2 + 74) << 13) & 0x10000000 | *result;
    *result = v2;
    if ( (*(_QWORD *)a2 & 0xE0000LL) != 0 )
      v3 = 0x20000000;
    else
      v3 = ((unsigned int)*(_QWORD *)a2 << 9) & 0x20000000;
    *result = v3 | v2;
  }
  return result;
}
