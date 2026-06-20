__int64 __fastcall aw9620x_reg_get(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x25
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x22
  int v8; // w24
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v5 = 0;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v7 = v6 - 56;
  do
  {
    if ( (aw9620x_reg_access[v4] & 1) != 0 )
    {
      v8 = *(unsigned __int16 *)&aw9620x_reg_access[v4 + 2];
      if ( (aw9620x_i2c_read(v7, *(_WORD *)&aw9620x_reg_access[v4 + 2], &v10) & 0x80000000) != 0 )
        v5 += snprintf((char *)(a3 + v5), 4096 - v5, "i2c read error ret = %d\n", -1);
      v5 += snprintf((char *)(a3 + v5), 4096 - v5, "0x%04x,0x%08x\n", v8, v10);
    }
    v4 += 4;
  }
  while ( v4 != 784 );
  _ReadStatusReg(SP_EL0);
  return v5;
}
