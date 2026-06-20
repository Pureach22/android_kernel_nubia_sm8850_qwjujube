__int64 __fastcall aw8693x_misc_para_init(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w9
  unsigned int v4; // w8
  int v5; // w9
  __int64 v6; // x9
  __int64 v7; // x3
  __int64 result; // x0
  char v9[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v10[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 808);
  v11[0] = 0;
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(v2 + 2);
  LOBYTE(v11[0]) = *(_BYTE *)(v2 + 2);
  i2c_w_bytes(a1, 71, v11, 1);
  if ( *(_DWORD *)(a1 + 1128) >= 0x708u )
    v3 = 1990;
  else
    v3 = 1809;
  v4 = v3 * *(_DWORD *)(a1 + 1220) / 0x9C40u;
  if ( v4 >= 0x7F )
    LOBYTE(v4) = 127;
  v5 = *(unsigned __int8 *)(a1 + 1123);
  *(_BYTE *)(a1 + 1179) = v4;
  *(_DWORD *)(a1 + 48) = v5;
  i2c_r_bytes(a1, 7, v11, 1);
  *(_DWORD *)(a1 + 52) = LOBYTE(v11[0]);
  i2c_r_bytes(a1, 10, v11, 8);
  v6 = v11[0];
  v7 = *(unsigned __int8 *)(a1 + 1217);
  *(_DWORD *)(a1 + 68) = LOBYTE(v11[0]);
  *(_QWORD *)(a1 + 30) = v6;
  i2c_w_bits(a1, 70, 4294967294LL, v7);
  i2c_w_bits(a1, 24, 4294967167LL, *(unsigned __int8 *)(a1 + 1219) << 7);
  i2c_w_bits(a1, 28, 4294967280LL, *(unsigned __int8 *)(a1 + 1183));
  i2c_w_bytes(a1, 33, a1 + 1181, 1);
  v10[0] = 50;
  i2c_w_bits(a1, 72, 4294967167LL, 0);
  printk(&unk_16079, "haptic_hv", 742, "aw8693x_protect_config");
  v9[0] = -65;
  i2c_w_bytes(a1, 74, v9, 1);
  i2c_w_bytes(a1, 75, v10, 1);
  printk(&unk_14A18, "haptic_hv", 525, "aw8693x_vbat_ref_config");
  i2c_w_bits(a1, 77, 4294967183LL, 64);
  LODWORD(v11[0]) = -2147283428;
  WORD2(v11[0]) = 9537;
  v10[0] = 125;
  i2c_w_bytes(a1, 94, v10, 1);
  i2c_w_bits(a1, 86, 4294967292LL, *(unsigned __int8 *)(a1 + 1218));
  i2c_w_bytes(a1, 111, v11, 2);
  i2c_w_bytes(a1, 114, (char *)v11 + 2, 1);
  i2c_w_bytes(a1, 119, (char *)v11 + 3, 1);
  i2c_w_bytes(a1, 125, (char *)v11 + 4, 1);
  i2c_w_bytes(a1, 107, (char *)v11 + 5, 1);
  v10[0] = 0;
  result = i2c_w_bytes(a1, 94, v10, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
