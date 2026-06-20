__int64 __fastcall aw22xxx_task_work(_BYTE *a1)
{
  __int64 *v2; // x19
  __int64 result; // x0
  char v4; // w21
  char v5[4]; // [xsp+4h] [xbp-1Ch] BYREF
  char v6[4]; // [xsp+8h] [xbp-18h] BYREF
  char v7[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v8[4]; // [xsp+10h] [xbp-10h] BYREF
  char v9[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v2 = (__int64 *)(a1 - 496);
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_130E1, "aw22xxx_task_work");
  aw22xxx_i2c_write(v2, 5, 255);
  v5[0] = 0;
  aw22xxx_i2c_read(v2, 4, v5);
  v5[0] &= ~2u;
  aw22xxx_i2c_write(v2, 4, v5[0]);
  printk(&unk_13C1D, "aw22xxx_chip_enable");
  v6[0] = 0;
  aw22xxx_i2c_read(v2, 2, v6);
  v6[0] &= ~1u;
  aw22xxx_i2c_write(v2, 2, v6[0]);
  result = usleep_range_state(2000, 3000, 2);
  if ( a1[268] )
  {
    printk(&unk_13C1D, "aw22xxx_chip_enable");
    v7[0] = 0;
    aw22xxx_i2c_read(v2, 2, v7);
    v7[0] |= 1u;
    aw22xxx_i2c_write(v2, 2, v7[0]);
    usleep_range_state(2000, 3000, 2);
    v8[0] = 0;
    aw22xxx_i2c_read(v2, 4, v8);
    v8[0] |= 1u;
    aw22xxx_i2c_write(v2, 4, v8[0]);
    if ( (unsigned __int8)a1[256] >= 0xFu )
      v4 = 15;
    else
      v4 = a1[256];
    aw22xxx_i2c_write(v2, 255, 0);
    aw22xxx_i2c_write(v2, 11, v4);
    aw22xxx_i2c_write(v2, 33, 225);
    aw22xxx_i2c_write(v2, 34, 0);
    aw22xxx_i2c_write(v2, 32, 2);
    aw22xxx_i2c_write(v2, 35, 61);
    aw22xxx_i2c_write(v2, 32, 0);
    aw22xxx_i2c_write(v2, 5, a1[268]);
    aw22xxx_i2c_write(v2, 6, a1[269]);
    v9[0] = 0;
    aw22xxx_i2c_read(v2, 4, v9);
    v9[0] |= 2u;
    result = aw22xxx_i2c_write(v2, 4, v9[0]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
