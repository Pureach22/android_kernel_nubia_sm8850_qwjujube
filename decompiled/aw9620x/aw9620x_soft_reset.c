__int64 __fastcall aw9620x_soft_reset(__int64 a1)
{
  __int64 v3; // x8
  int v4; // w0
  __int64 v5; // x1

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_soft_reset", 951);
  if ( (aw9620x_i2c_write(a1, 0xFF20u, 1006694801) & 0x80000000) != 0 )
  {
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] read REG_APB_ACCESS_EN err: %d\n",
      "aw9620x_soft_reset",
      955,
      0xFFFFFFFFLL);
  }
  else if ( (aw9620x_i2c_write(a1, 0x4700u, 272) & 0x80000000) != 0 )
  {
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] read REG_APB_ACCESS_EN err: %d\n",
      "aw9620x_soft_reset",
      961,
      0xFFFFFFFFLL);
  }
  else
  {
    usleep_range_state(1000, 1010, 2);
    aw9620x_i2c_write(a1, 0x4444u, 0);
    if ( (aw9620x_i2c_write(a1, 0xFF18u, 60) & 0x80000000) != 0 )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] read soft_reset err: %d\n",
        "aw9620x_soft_reset",
        972,
        0xFFFFFFFFLL);
    }
    else
    {
      msleep(25);
      if ( (unsigned int)aw9620x_i2c_write(a1, 0x4700u, 258) )
      {
        v3 = *(_QWORD *)(a1 + 40);
        if ( *(_WORD *)(v3 + 2) == 18 )
          *(_WORD *)(v3 + 2) = 19;
        v4 = aw9620x_i2c_write(a1, 0x4700u, 258);
        v5 = *(_QWORD *)(a1 + 48);
        if ( v4 < 0 )
        {
          dev_printk(
            &unk_134C0,
            v5,
            "[%s:%d] read REG_APB_ACCESS_EN err1: %d\n",
            "aw9620x_soft_reset",
            984,
            0xFFFFFFFFLL);
          return 0xFFFFFFFFLL;
        }
        dev_printk(&unk_134C0, v5, "[%s:%d] AW_REG_FLASH_WAKE_UP ok\n", "aw9620x_soft_reset", 987);
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(a1 + 48),
          "[%s:%d] i2c->addr = 0x%x\n",
          "aw9620x_soft_reset",
          988,
          *(unsigned __int16 *)(*(_QWORD *)(a1 + 40) + 2LL));
      }
      if ( (aw9620x_i2c_write(a1, 0xFF20u, 1006694417) & 0x80000000) == 0 )
        return 0;
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] write 0xff20 err: %d\n",
        "aw9620x_soft_reset",
        993,
        0xFFFFFFFFLL);
    }
  }
  return 0xFFFFFFFFLL;
}
