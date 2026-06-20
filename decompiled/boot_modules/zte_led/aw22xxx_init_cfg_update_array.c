__int64 __fastcall aw22xxx_init_cfg_update_array(__int64 a1)
{
  __int64 v2; // x2
  __int64 result; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_13012, "aw22xxx_init_cfg_update_array");
  printk(&unk_13C1D, "aw22xxx_chip_enable");
  v4[0] = 0;
  aw22xxx_i2c_read(a1, 2, v4);
  v2 = v4[0] | 1u;
  v4[0] |= 1u;
  aw22xxx_i2c_write(a1, 2, v2);
  usleep_range_state(2000, 3000, 2);
  aw22xxx_i2c_write(a1, 255, 0);
  aw22xxx_i2c_write(a1, 2, 1);
  aw22xxx_i2c_write(a1, 12, 0);
  aw22xxx_i2c_write(a1, 11, 5);
  aw22xxx_i2c_write(a1, 5, 1);
  aw22xxx_i2c_write(a1, 4, 1);
  aw22xxx_i2c_write(a1, 9, 1);
  aw22xxx_i2c_write(a1, 4, 3);
  result = aw22xxx_i2c_write(a1, 5, 65);
  _ReadStatusReg(SP_EL0);
  return result;
}
