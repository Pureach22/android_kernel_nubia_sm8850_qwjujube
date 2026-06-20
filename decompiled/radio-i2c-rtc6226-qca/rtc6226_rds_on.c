__int64 __fastcall rtc6226_rds_on(__int64 a1)
{
  __int64 result; // x0

  *(_WORD *)(a1 + 1770) |= 0x1000u;
  result = rtc6226_set_register(a1, 4);
  if ( (result & 0x80000000) != 0 )
    *(_WORD *)(a1 + 1770) &= ~0x1000u;
  return result;
}
