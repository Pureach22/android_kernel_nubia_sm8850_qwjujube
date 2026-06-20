__int64 __fastcall aw9620x_send_stop_cmd(__int64 a1)
{
  int v2; // w24
  int v3; // w0
  int v4; // w26
  int v5; // w27
  __int64 v6; // x1
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_send_stop_cmd", 1991);
  aw9620x_i2c_write(a1, 0x4444u, 0x10000);
  aw9620x_i2c_write(a1, 0xFF20u, 1006698495);
  v8 = 0;
  aw9620x_i2c_read(a1, 0x4744u, &v8);
  aw9620x_i2c_write(a1, 0x4744u, v8 & 0xFFFFFF);
  aw9620x_i2c_write(a1, 0xFF20u, 1006694417);
  aw9620x_i2c_write(a1, 0x4444u, 0);
  msleep(25);
  v2 = 10;
  v8 = 0;
  while ( 1 )
  {
    v3 = aw9620x_i2c_read(a1, 0x4410u, &v8);
    v4 = v8;
    v5 = v3;
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] REG_HOSTIRQSRC :0x%x\n",
      "aw9620x_read_init_comp_irq",
      1884,
      v8);
    if ( v5 )
    {
      dev_printk(
        &unk_142BB,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] read REG_HOSTIRQSRC err\n",
        "aw9620x_read_init_comp_irq",
        1886);
      goto LABEL_7;
    }
    v6 = *(_QWORD *)(a1 + 48);
    if ( v4 == 1 )
      break;
    dev_printk(&unk_134C0, v6, "[%s:%d] REG_HOSTIRQSRC val: 0x%x cnt: %d\n", "aw9620x_read_init_comp_irq", 1894, v4, v2);
    usleep_range_state(1000, 1010, 2);
    if ( --v2 == -1 )
    {
      dev_printk(
        &unk_142BB,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] irq_stat != 0 cmd send err!\n",
        "aw9620x_read_init_comp_irq",
        1900);
LABEL_7:
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] stop read_ack_irq err\n", "aw9620x_send_stop_cmd", 2004);
      result = 0xFFFFFFFFLL;
      goto LABEL_9;
    }
  }
  dev_printk(&unk_142BB, v6, "[%s:%d] stop_flag irq_stat = 1 cmd send success!\n", "aw9620x_read_init_comp_irq", 1891);
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
