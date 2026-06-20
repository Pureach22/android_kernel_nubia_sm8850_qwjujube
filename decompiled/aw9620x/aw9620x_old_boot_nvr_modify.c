__int64 __fastcall aw9620x_old_boot_nvr_modify(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x8
  int v4; // w5
  int v5; // w20
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v7 = 0;
  dev_printk(&unk_142BB, v2, "[%s:%d] enter\n", "aw9620x_old_boot_nvr_modify", 4140);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] i2c addr0: 0x%x\n",
    "aw9620x_old_boot_nvr_modify",
    4143,
    *(unsigned __int16 *)(*(_QWORD *)(a1 + 40) + 2LL));
  if ( !(unsigned int)aw9620x_i2c_write(a1, 0x4444u, 0x10000) )
    goto LABEL_5;
  v3 = *(_QWORD *)(a1 + 40);
  v4 = 18;
  if ( *(_WORD *)(v3 + 2) != 18 )
  {
    *(_WORD *)(v3 + 2) = 18;
    v4 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 40) + 2LL);
  }
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] i2c addr0: 0x%x\n", "aw9620x_old_boot_nvr_modify", 4149, v4);
  if ( (unsigned int)aw9620x_i2c_write(a1, 0x4444u, 0x10000) )
  {
    dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] REG_MCFG00 err!\n", "aw9620x_old_boot_nvr_modify", 4152);
    result = 0xFFFFFFFFLL;
  }
  else
  {
LABEL_5:
    aw9620x_i2c_write(a1, 0xFF20u, 1023410175);
    aw9620x_i2c_read(a1, 0x4748u, &v7);
    v5 = v7;
    dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] 0x4748 = 0x%08x\n", "aw9620x_old_boot_nvr_modify", 4159, v7);
    if ( v5 )
    {
      aw9620x_i2c_write(a1, 0x4748u, 0);
      aw9620x_i2c_write(a1, 0x4788u, 1516468514);
      aw9620x_i2c_write(a1, 0x4820u, 6);
      aw9620x_i2c_write(a1, 0x4700u, 272);
      aw9620x_i2c_write(a1, 0x4734u, 18000);
      aw9620x_i2c_write(a1, 0x4704u, 16640);
      aw9620x_i2c_write(a1, 0x4710u, 37);
      aw9620x_i2c_write(a1, 0x472Cu, 240);
      aw9620x_i2c_write(a1, 0x4714u, 1);
      usleep_range_state(5000, 5010, 2);
      aw9620x_i2c_write(a1, 0x4704u, 16640);
      aw9620x_i2c_write(a1, 0x4708u, 0);
      aw9620x_i2c_write(a1, 0x4710u, 44);
      aw9620x_i2c_write(a1, 0x4714u, 1);
      result = 0;
    }
    else
    {
      aw9620x_i2c_write(a1, 0x4444u, 0);
      aw9620x_i2c_write(a1, 0xFF18u, 60);
      msleep(25);
      result = 1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
