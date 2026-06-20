__int64 __fastcall aw9620x_reg_set(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v8; // [xsp+0h] [xbp-10h] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( sscanf(s, "%x %x", &v8, (char *)&v8 + 4) == 2 )
  {
    v6 = 0;
    while ( *(unsigned __int16 *)&aw9620x_reg_access[v6 + 2] != (unsigned __int16)v8 )
    {
      v6 += 4;
      if ( v6 == 784 )
        goto LABEL_8;
    }
    if ( (aw9620x_reg_access[v6] & 2) != 0 )
      aw9620x_i2c_write(v5 - 56, v8, SHIDWORD(v8));
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
