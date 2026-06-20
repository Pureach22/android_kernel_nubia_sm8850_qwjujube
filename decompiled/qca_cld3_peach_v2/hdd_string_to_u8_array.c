__int64 __fastcall hdd_string_to_u8_array(char *s, __int64 a2, _BYTE *a3, unsigned __int16 a4)
{
  __int64 result; // x0
  unsigned int v8; // w23
  char *v9; // x8
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  result = 4;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( s && a2 && a3 )
  {
    v8 = a4;
    *a3 = 0;
    while ( (unsigned __int8)*a3 < v8 )
    {
      v10 = 0;
      if ( sscanf(s, "%d", &v10) == 1 )
        *(_BYTE *)(a2 + (unsigned __int8)(*a3)++) = v10;
      v9 = strchr(s, 44);
      result = 0;
      if ( v9 )
      {
        s = v9 + 1;
        if ( v9 != (char *)-1LL )
          continue;
      }
      goto LABEL_12;
    }
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
