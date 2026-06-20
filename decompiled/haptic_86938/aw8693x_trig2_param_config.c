__int64 __fastcall aw8693x_trig2_param_config(_BYTE *a1)
{
  int v2; // w9
  unsigned int v3; // w8
  __int64 v4; // x3
  __int64 result; // x0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1[1525] )
    v2 = (4 * (a1[1524] != 0)) | 8;
  else
    v2 = 4 * (a1[1524] != 0);
  if ( a1[1522] )
    v3 = v2 | 2;
  else
    v3 = v2;
  if ( a1[1523] )
    v4 = v3 + 1;
  else
    v4 = v3;
  i2c_w_bits(a1, 57, 4294967280LL, v4);
  v6[0] = a1[1528] | ((a1[1526] != 0) << 7);
  i2c_w_bytes(a1, 52, v6, 1);
  v6[0] = a1[1529] | ((a1[1527] != 0) << 7);
  result = i2c_w_bytes(a1, 55, v6, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
