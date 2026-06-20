__int64 __fastcall aw9620x_get_err_info(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+Ch] [xbp-14h] BYREF
  int v4; // [xsp+10h] [xbp-10h] BYREF
  int v5; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v3 = 0;
  v4 = 0;
  aw9620x_i2c_write(a1, 0xFF20u, 1006694545);
  aw9620x_i2c_read(a1, 0x1C00u, &v5);
  aw9620x_i2c_read(a1, 0x4744u, &v3);
  aw9620x_i2c_read(a1, 0x4444u, &v4);
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] 0x1c00:0x%x, 0x4744:0x%x, 0x4444:0x%x\n",
    "aw9620x_get_err_info",
    887,
    v5,
    v3,
    v4);
  result = aw9620x_i2c_write(a1, 0xFF20u, 1006694417);
  _ReadStatusReg(SP_EL0);
  return result;
}
