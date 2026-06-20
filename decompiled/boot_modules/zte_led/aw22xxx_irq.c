__int64 __fastcall aw22xxx_irq(__int64 a1, _QWORD *a2)
{
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  printk(&unk_130E1, "aw22xxx_irq");
  aw22xxx_i2c_read(a2, 10, v4);
  printk(&unk_12BCB, "aw22xxx_irq");
  if ( (v4[0] & 0x10) != 0 )
    queue_work_on(32, system_wq, a2 + 74);
  printk(&unk_13BB4, "aw22xxx_irq");
  _ReadStatusReg(SP_EL0);
  return 1;
}
