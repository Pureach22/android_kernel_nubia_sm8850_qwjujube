__int64 __fastcall hal_rx_get_hal_hash(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w9
  __int64 result; // x0

  v2 = *(unsigned __int16 *)(a1 + 24);
  result = a2;
  if ( v2 <= a2 )
    return *(_WORD *)(a1 + 28) & a2;
  return result;
}
