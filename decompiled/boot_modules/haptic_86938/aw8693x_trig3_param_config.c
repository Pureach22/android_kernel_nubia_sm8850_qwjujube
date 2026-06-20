__int64 __fastcall aw8693x_trig3_param_config(_BYTE *a1)
{
  unsigned int v2; // w9
  __int64 v3; // x3
  __int64 result; // x0
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1[1538] )
    v2 = ((a1[1537] != 0) << 6) | 0xFFFFFF80;
  else
    v2 = (a1[1537] != 0) << 6;
  if ( a1[1535] )
    v2 |= 0x20u;
  if ( a1[1536] )
    v3 = v2 | 0x10;
  else
    v3 = v2;
  i2c_w_bits(a1, 58, 4294967055LL, v3);
  v5[0] = a1[1541] | ((a1[1539] != 0) << 7);
  i2c_w_bytes(a1, 53, v5, 1);
  v5[0] = a1[1542] | ((a1[1540] != 0) << 7);
  result = i2c_w_bytes(a1, 56, v5, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
