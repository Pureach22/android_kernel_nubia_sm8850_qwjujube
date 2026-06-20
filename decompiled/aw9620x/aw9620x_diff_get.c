__int64 __fastcall aw9620x_diff_get(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w21
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x3
  int v9; // w8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v5 = 0;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  v7 = v6 - 56;
  do
  {
    aw9620x_i2c_read(v7, 84 * v4 + 6788, &v11);
    v8 = v4;
    if ( v11 >= 0 )
      v9 = v11;
    else
      v9 = v11 + 1023;
    ++v4;
    v5 += snprintf((char *)(a3 + v5), 4096 - v5, "(ch%d):%d\n", v8, (unsigned int)(v9 >> 10));
  }
  while ( v4 != 8 );
  _ReadStatusReg(SP_EL0);
  return v5;
}
