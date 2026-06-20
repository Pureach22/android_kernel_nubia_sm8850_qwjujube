__int64 __fastcall aw9620x_read_ack_irq(__int64 a1)
{
  int v2; // w8
  int v3; // w24
  int v4; // w0
  int v5; // w26
  int v6; // w27
  __int64 v7; // x1
  __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 36);
  v9 = 0;
  if ( v2 == 3 )
    v3 = 100;
  else
    v3 = 10;
  while ( 1 )
  {
    v4 = aw9620x_i2c_read(a1, 0x4410u, &v9);
    v5 = v9;
    v6 = v4;
    dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] REG_HOSTIRQSRC :0x%x\n", "aw9620x_read_ack_irq", 1855, v9);
    if ( v6 )
    {
      dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] read REG_HOSTIRQSRC err\n", "aw9620x_read_ack_irq", 1857);
      goto LABEL_9;
    }
    v7 = *(_QWORD *)(a1 + 48);
    if ( (v5 & 0x20000000) != 0 )
      break;
    dev_printk(&unk_134C0, v7, "[%s:%d] REG_HOSTIRQSRC val: 0x%x cnt: %d\n", "aw9620x_read_ack_irq", 1864, v5, v3);
    usleep_range_state(1000, 1010, 2);
    if ( --v3 == -1 )
    {
      dev_printk(
        &unk_142BB,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] irq_stat != 0 cmd send err!\n",
        "aw9620x_read_ack_irq",
        1869);
LABEL_9:
      result = 0xFFFFFFFFLL;
      goto LABEL_11;
    }
  }
  dev_printk(&unk_142BB, v7, "[%s:%d] irq_stat bit29 = 1  cmd send success!\n", "aw9620x_read_ack_irq", 1861);
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
