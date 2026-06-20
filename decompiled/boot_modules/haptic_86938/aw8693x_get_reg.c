__int64 __fastcall aw8693x_get_reg(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 i; // x21
  _QWORD v8[18]; // [xsp+0h] [xbp-90h] BYREF

  v8[17] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v8, 0, 131);
  i2c_r_bytes(a1, 0, v8, 50);
  i2c_r_bytes(a1, 51, (char *)&v8[6] + 3, 15);
  i2c_r_bytes(a1, 67, (char *)&v8[8] + 3, 64);
  for ( i = 0; i != 131; ++i )
  {
    if ( (unsigned __int8)i != 50 && (unsigned __int8)i != 66 )
      a2 += snprintf((char *)(a3 + a2), 4096 - a2, "reg:0x%02X=0x%02X\n", i, *((unsigned __int8 *)v8 + i));
  }
  _ReadStatusReg(SP_EL0);
  return a2;
}
