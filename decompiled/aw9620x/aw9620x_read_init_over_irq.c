__int64 __fastcall aw9620x_read_init_over_irq(__int64 a1)
{
  __int64 v2; // x1
  int v3; // w20
  __int64 v4; // x1
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v6 = 0;
  dev_printk(&unk_142BB, v2, "[%s:%d] enter\n", "aw9620x_read_init_over_irq", 1038);
  v3 = 100;
  while ( 1 )
  {
    if ( (aw9620x_i2c_read(a1, 0x4410u, &v6) & 0x80000000) != 0 )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] read init irq reg err: %d cnt: %d\n",
        "aw9620x_read_init_over_irq",
        1043,
        -1,
        v3);
      result = 0xFFFFFFFFLL;
      goto LABEL_8;
    }
    v4 = *(_QWORD *)(a1 + 48);
    if ( (v6 & 1) != 0 )
      break;
    dev_printk(&unk_134C0, v4, "[%s:%d] init over irq no ok cnt: %d\n", "aw9620x_read_init_over_irq", 1050, v3);
    usleep_range_state(1000, 1010, 2);
    if ( --v3 == -1 )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] init over irq err!\n", "aw9620x_read_init_over_irq", 1055);
      result = 4294967293LL;
      goto LABEL_8;
    }
  }
  dev_printk(&unk_142BB, v4, "[%s:%d] init over irq ok cnt: %d\n", "aw9620x_read_init_over_irq", 1047, v3);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
