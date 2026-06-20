__int64 __fastcall rtc6226_power_down(_WORD *a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w20

  mutex_lock(a1 + 936);
  a1[885] &= 0x2FFFu;
  v2 = rtc6226_set_register(a1, 4);
  if ( (v2 & 0x80000000) == 0 )
  {
    a1[883] &= ~0x4000u;
    rtc6226_set_register(a1, 2);
    a1[887] = a1[887] & 0x3FFF | 0x4000;
    rtc6226_set_register(a1, 6);
    a1[881] = 5802;
    v2 = rtc6226_set_register(a1, 0);
  }
  v3 = v2;
  mutex_unlock(a1 + 936);
  return v3;
}
