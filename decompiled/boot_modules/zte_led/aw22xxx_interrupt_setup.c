__int64 __fastcall aw22xxx_interrupt_setup(__int64 *a1)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v4[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v5[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_130E1, "aw22xxx_interrupt_setup");
  v3[0] = 0;
  printk(&unk_130E1, "aw22xxx_interrupt_clear");
  aw22xxx_i2c_read(a1, 10, v3);
  printk(&unk_12BCB, "aw22xxx_interrupt_clear");
  v4[0] = 0;
  aw22xxx_i2c_read(a1, 9, v4);
  v4[0] |= 1u;
  aw22xxx_i2c_write(a1, 9, v4[0]);
  v5[0] = 0;
  aw22xxx_i2c_read(a1, 9, v5);
  result = aw22xxx_i2c_write(a1, 9, v5[0] | 0x10u);
  _ReadStatusReg(SP_EL0);
  return result;
}
