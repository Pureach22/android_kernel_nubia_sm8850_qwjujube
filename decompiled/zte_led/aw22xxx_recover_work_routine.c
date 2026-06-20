__int64 __fastcall aw22xxx_recover_work_routine(__int64 a1)
{
  __int64 *v2; // x20
  __int64 result; // x0
  char v4[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v5[4]; // [xsp+10h] [xbp-10h] BYREF
  char v6[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+18h] [xbp-8h]

  v2 = (__int64 *)(a1 - 592);
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_13368, "aw22xxx_recover_work_routine");
  aw22xxx_i2c_write(v2, 255, 0);
  v4[0] = 0;
  aw22xxx_i2c_read(v2, 4, v4);
  v4[0] &= ~2u;
  aw22xxx_i2c_write(v2, 4, v4[0]);
  v5[0] = 0;
  aw22xxx_i2c_read(v2, 4, v5);
  v5[0] &= ~1u;
  aw22xxx_i2c_write(v2, 4, v5[0]);
  printk(&unk_13C1D, "aw22xxx_chip_enable");
  v6[0] = 0;
  aw22xxx_i2c_read(v2, 2, v6);
  v6[0] &= ~1u;
  aw22xxx_i2c_write(v2, 2, v6[0]);
  usleep_range_state(2000, 3000, 2);
  printk(&unk_12FB5, "aw22xxx_recover_work_routine");
  aw22xxx_i2c_write(v2, 255, 0);
  aw22xxx_i2c_write(v2, 2, 1);
  aw22xxx_i2c_write(v2, 12, 0);
  aw22xxx_i2c_write(v2, 5, 1);
  aw22xxx_i2c_write(v2, 4, 1);
  aw22xxx_i2c_write(v2, 9, 17);
  aw22xxx_i2c_write(v2, 4, 3);
  aw22xxx_i2c_write(v2, 5, 65);
  msleep(200);
  printk(&unk_13909, "aw22xxx_recover_work_routine");
  *(_DWORD *)(a1 + 176) = lamp_effect;
  ((void (__fastcall *)(__int64 *))aw22xxx_cfg_recover_update_wait)(v2);
  msleep(200);
  *(_DWORD *)(a1 + 176) = fan_effect;
  result = ((__int64 (__fastcall *)(__int64 *))aw22xxx_cfg_recover_update_wait)(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
