unsigned __int8 *__fastcall cfg80211_find_vendor_elem(int a1, int a2, unsigned __int8 *a3, unsigned int a4)
{
  size_t v4; // x20
  unsigned __int64 v5; // x9
  unsigned __int8 *v6; // x19
  unsigned __int8 *v7; // x21
  __int64 v8; // x8
  unsigned __int8 *result; // x0
  _BYTE s2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  s2[0] = BYTE2(a1);
  s2[1] = BYTE1(a1);
  if ( a2 < 0 )
    v4 = 3;
  else
    v4 = 4;
  s2[2] = a1;
  s2[3] = a2;
  if ( a2 >= 256 )
  {
    result = nullptr;
    __break(0x800u);
  }
  else
  {
    if ( a4 >= 2 )
    {
      v5 = a4;
      v6 = a3;
      v7 = &a3[a4];
      do
      {
        v8 = v6[1];
        if ( v5 < (unsigned int)(v8 + 2) )
          break;
        if ( (unsigned int)v4 <= (unsigned int)v8 && *v6 == 221 )
        {
          if ( !bcmp(v6 + 2, s2, v4) )
          {
            if ( !v6 )
              break;
            if ( v6[1] >= 4u )
              result = v6;
            else
              result = nullptr;
            goto LABEL_18;
          }
          v8 = v6[1];
        }
        v6 += v8 + 2;
        v5 = v7 - v6;
      }
      while ( v7 - v6 > 1 );
    }
    result = nullptr;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
