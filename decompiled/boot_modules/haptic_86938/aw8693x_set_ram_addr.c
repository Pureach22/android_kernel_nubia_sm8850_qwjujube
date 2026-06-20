__int64 __fastcall aw8693x_set_ram_addr(__int64 a1)
{
  __int64 result; // x0
  __int16 v2; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = bswap32(*(unsigned __int16 *)(a1 + 1112)) >> 16;
  result = i2c_w_bytes(a1, 64, &v2, 2);
  _ReadStatusReg(SP_EL0);
  return result;
}
