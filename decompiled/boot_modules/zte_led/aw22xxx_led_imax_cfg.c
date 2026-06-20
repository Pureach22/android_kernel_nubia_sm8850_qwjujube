__int64 __fastcall aw22xxx_led_imax_cfg(__int64 a1)
{
  aw22xxx_i2c_write(a1, 255, 0);
  aw22xxx_i2c_write(a1, 11, 7);
  *(_DWORD *)(a1 + 752) = 7;
  return printk(&unk_12EF8, "aw22xxx_led_imax_cfg");
}
