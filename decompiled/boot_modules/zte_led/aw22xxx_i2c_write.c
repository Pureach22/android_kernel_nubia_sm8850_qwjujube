__int64 __fastcall aw22xxx_i2c_write(__int64 *a1, char a2, char a3)
{
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v9[0] = a2;
  v9[1] = a3;
  result = i2c_transfer_buffer_flags(v4, v9, 2, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v6 = gpio_to_desc(*((unsigned int *)a1 + 184));
    gpiod_get_raw_value(v6);
    printk(&unk_12AC7, "aw22xxx_i2c_write");
    msleep(1);
    result = i2c_transfer_buffer_flags(*a1, v9, 2, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v7 = gpio_to_desc(*((unsigned int *)a1 + 184));
      gpiod_get_raw_value(v7);
      printk(&unk_12AC7, "aw22xxx_i2c_write");
      v8 = gpio_to_desc(*((unsigned int *)a1 + 184));
      gpiod_direction_output_raw(v8, 1);
      printk(&unk_129E3, "aw22xxx_i2c_write");
      result = msleep(1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
