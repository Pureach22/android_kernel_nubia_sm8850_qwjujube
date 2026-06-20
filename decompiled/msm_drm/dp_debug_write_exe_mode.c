__int64 __fastcall dp_debug_write_exe_mode(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  int v8; // w8
  void (*v9)(void); // x8
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
      v12 = 0;
      v13 = 0;
      *(_QWORD *)s = 0;
      v11 = 0;
      _check_object_size(s, v6, 0);
      if ( !inline_copy_from_user((__int64)s, a2, v6) )
      {
        s[v6] = 0;
        if ( sscanf(s, "%3s", v4 + 32) == 1 )
        {
          if ( ((v8 = *(unsigned __int8 *)(v4 + 32), v8 == 115) || v8 == 104)
            && *(_BYTE *)(v4 + 33) == 119
            && !*(_BYTE *)(v4 + 34)
            || !strcmp((const char *)(v4 + 32), "all") )
          {
            v9 = *(void (**)(void))(*(_QWORD *)(v4 + 136) + 1208LL);
            if ( *((_DWORD *)v9 - 1) != -1750319539 )
              __break(0x8228u);
            v9();
          }
        }
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
