__int64 __fastcall rtc6226_stop(_WORD *a1)
{
  __int64 result; // x0

  a1[885] &= 0x2FFFu;
  result = rtc6226_set_register(a1, 4);
  if ( (result & 0x80000000) == 0 )
  {
    a1[883] &= ~0x4000u;
    rtc6226_set_register(a1, 2);
    a1[887] = a1[887] & 0x3FFF | 0x4000;
    rtc6226_set_register(a1, 6);
    a1[881] = 5802;
    return rtc6226_set_register(a1, 0);
  }
  return result;
}
