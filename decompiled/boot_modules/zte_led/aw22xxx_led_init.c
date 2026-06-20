__int64 __fastcall aw22xxx_led_init(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w8
  char v4; // w20
  __int64 result; // x0
  char v6[4]; // [xsp+0h] [xbp-10h] BYREF
  char v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_130E1, "aw22xxx_led_init");
  aw22xxx_i2c_write((__int64 *)a1, 1, 85);
  usleep_range_state(2000, 3000, 2);
  printk(&unk_13C1D, "aw22xxx_chip_enable");
  v6[0] = 0;
  aw22xxx_i2c_read((_QWORD *)a1, 2, v6);
  v6[0] |= 1u;
  aw22xxx_i2c_write((__int64 *)a1, 2, v6[0]);
  usleep_range_state(2000, 3000, 2);
  v2 = *(unsigned int *)(a1 + 752);
  if ( (unsigned int)v2 >= 0xD )
    __break(0x5512u);
  v3 = (unsigned __int8)aw22xxx_imax_code[v2];
  if ( v3 >= 0xF )
    v4 = 15;
  else
    v4 = v3;
  aw22xxx_i2c_write((__int64 *)a1, 255, 0);
  aw22xxx_i2c_write((__int64 *)a1, 11, v4);
  printk(&unk_13C1D, "aw22xxx_chip_enable");
  v7[0] = 0;
  aw22xxx_i2c_read((_QWORD *)a1, 2, v7);
  v7[0] &= ~1u;
  aw22xxx_i2c_write((__int64 *)a1, 2, v7[0]);
  usleep_range_state(2000, 3000, 2);
  result = printk(&unk_13CF6, "aw22xxx_led_init");
  _ReadStatusReg(SP_EL0);
  return result;
}
