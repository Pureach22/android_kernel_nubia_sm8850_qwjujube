__int64 __fastcall rtc6226_set_freq(__int64 a1, unsigned int a2)
{
  __int16 v2; // w20
  unsigned int v4; // w9
  __int64 result; // x0

  v2 = *(_WORD *)(a1 + 1768);
  v4 = 10 * (*(_WORD *)(a1 + 1804) & 0x7FFF);
  if ( v4 <= a2 )
    v4 = a2;
  *(_WORD *)(a1 + 1768) = (v4 / 0xA) | 0x8000;
  result = rtc6226_set_register();
  if ( (result & 0x80000000) != 0 )
  {
    *(_WORD *)(a1 + 1768) = v2 & 0x7FFF;
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 18);
    if ( (result & 0x80000000) == 0 )
    {
      result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 19);
      if ( (result & 0x80000000) == 0 )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 20);
        if ( (result & 0x80000000) == 0 )
        {
          result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 21);
          if ( (result & 0x80000000) == 0 )
          {
            result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 22);
            if ( (result & 0x80000000) == 0 )
            {
              result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 23);
              if ( (result & 0x80000000) == 0 )
              {
                result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 24);
                if ( (result & 0x80000000) == 0 )
                {
                  result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 25);
                  if ( (result & 0x80000000) == 0 )
                  {
                    result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 26);
                    if ( (result & 0x80000000) == 0 )
                    {
                      result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 27);
                      if ( (result & 0x80000000) == 0 )
                      {
                        result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 28);
                        if ( (result & 0x80000000) == 0 )
                        {
                          result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 29);
                          if ( (result & 0x80000000) == 0 )
                          {
                            result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 30);
                            if ( (result & 0x80000000) == 0 )
                              return ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(a1, 31);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
