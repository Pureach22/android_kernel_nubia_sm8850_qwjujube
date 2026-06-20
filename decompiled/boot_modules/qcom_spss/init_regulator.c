unsigned __int64 __fastcall init_regulator(__int64 a1, __int64 a2, const char *a3)
{
  unsigned __int64 result; // x0
  __int64 v7; // x0
  unsigned __int64 v8; // x19
  int v9; // [xsp+4h] [xbp-4Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-48h] BYREF
  char s[8]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v12; // [xsp+18h] [xbp-38h]
  __int64 v13; // [xsp+20h] [xbp-30h]
  __int64 v14; // [xsp+28h] [xbp-28h]
  __int64 v15; // [xsp+30h] [xbp-20h]
  __int64 v16; // [xsp+38h] [xbp-18h]
  __int16 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  *(_QWORD *)s = 0;
  v12 = 0;
  v10 = 0;
  result = devm_regulator_get(a1, a3);
  *(_QWORD *)a2 = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    snprintf(s, 0x32u, "%s-uV-uA", a3);
    if ( of_find_property(*(_QWORD *)(a1 + 744), s, &v9) )
    {
      v7 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), s, &v10, 2, 0);
      if ( (v7 & 0x80000000) != 0 )
      {
        v8 = v7;
        dev_err(a1, "Failed to read uV-uA value(rc:%d)\n", v7);
        result = v8;
      }
      else
      {
        if ( (_DWORD)v10 )
          *(_DWORD *)(a2 + 8) = v10;
        result = 0;
        if ( HIDWORD(v10) )
          *(_DWORD *)(a2 + 12) = HIDWORD(v10);
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
