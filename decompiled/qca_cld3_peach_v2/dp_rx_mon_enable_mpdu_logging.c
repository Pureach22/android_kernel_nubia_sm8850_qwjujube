int *__fastcall dp_rx_mon_enable_mpdu_logging(int *result, __int64 a2)
{
  int v2; // w8
  int v3; // w8
  int v4; // w8
  int v5; // w8

  if ( result && a2 )
  {
    v2 = *(_DWORD *)(a2 + 74);
    if ( (v2 & 7) != 0 )
    {
      v3 = *result | 0x20000;
      *result = v3;
      *result = (*(_DWORD *)(a2 + 74) << 8) & 0x100000 | v3;
      v2 = *(_DWORD *)(a2 + 74);
    }
    if ( (v2 & 0x38) != 0 )
    {
      v4 = *result | 0x40000;
      *result = v4;
      *result = (*(_DWORD *)(a2 + 74) << 8) & 0x200000 | v4;
      v2 = *(_DWORD *)(a2 + 74);
    }
    if ( (v2 & 0x1C0) != 0 )
    {
      v5 = *result | 0x80000;
      *result = v5;
      *result = (*(_DWORD *)(a2 + 74) << 8) & 0x400000 | v5;
    }
  }
  return result;
}
