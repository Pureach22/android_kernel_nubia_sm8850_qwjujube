__int64 __fastcall dp_debug_write_dump(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      if ( a3 >= 0x1F )
        v6 = 31;
      else
        v6 = a3;
      v10 = 0;
      v11 = 0;
      *(_QWORD *)s = 0;
      v9 = 0;
      _check_object_size(s, v6, 0);
      if ( !inline_copy_from_user((__int64)s, a2, v6) )
      {
        s[v6] = 0;
        if ( sscanf(s, "%31s", v4 + 64) == 1 && !strcmp((const char *)(v4 + 64), "qfprom_physical") )
          strcpy((char *)(v4 + 64), "clear");
      }
      result = v6;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
