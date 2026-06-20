__int64 __fastcall aw22xxx_irq_v15(__int64 a1, __int64 a2)
{
  _BYTE v4[4]; // [xsp+Ch] [xbp-24h] BYREF
  char v5[4]; // [xsp+10h] [xbp-20h] BYREF
  char v6[4]; // [xsp+14h] [xbp-1Ch] BYREF
  char v7[4]; // [xsp+18h] [xbp-18h] BYREF
  char v8[4]; // [xsp+1Ch] [xbp-14h] BYREF
  char v9[4]; // [xsp+20h] [xbp-10h] BYREF
  char v10[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  aw22xxx_i2c_read((_QWORD *)a2, 10, v4);
  printk(&unk_12BCB, "aw22xxx_irq_v15");
  if ( (v4[0] & 1) != 0 )
  {
    printk(&unk_12DAA, "aw22xxx_irq_v15");
    aw22xxx_i2c_write((__int64 *)a2, 255, 0);
    v5[0] = 0;
    aw22xxx_i2c_read((_QWORD *)a2, 4, v5);
    v5[0] &= ~2u;
    aw22xxx_i2c_write((__int64 *)a2, 4, v5[0]);
    v6[0] = 0;
    aw22xxx_i2c_read((_QWORD *)a2, 4, v6);
    v6[0] &= ~1u;
    aw22xxx_i2c_write((__int64 *)a2, 4, v6[0]);
    printk(&unk_13C1D, "aw22xxx_chip_enable");
    v7[0] = 0;
    aw22xxx_i2c_read((_QWORD *)a2, 2, v7);
    v7[0] &= ~1u;
    aw22xxx_i2c_write((__int64 *)a2, 2, v7[0]);
    usleep_range_state(2000, 3000, 2);
    printk(&unk_12FB5, "aw22xxx_irq_v15");
    if ( (v4[0] & 0x10) == 0 )
      goto LABEL_3;
  }
  else if ( (v4[0] & 0x10) == 0 )
  {
    goto LABEL_3;
  }
  printk(&unk_130EE, "aw22xxx_irq_v15");
  aw22xxx_i2c_write((__int64 *)a2, 255, 0);
  v8[0] = 0;
  aw22xxx_i2c_read((_QWORD *)a2, 4, v8);
  v8[0] &= ~2u;
  aw22xxx_i2c_write((__int64 *)a2, 4, v8[0]);
  v9[0] = 0;
  aw22xxx_i2c_read((_QWORD *)a2, 4, v9);
  v9[0] |= 2u;
  aw22xxx_i2c_write((__int64 *)a2, 4, v9[0]);
  v10[0] = 0;
  aw22xxx_i2c_read((_QWORD *)a2, 4, v10);
  v10[0] |= 1u;
  aw22xxx_i2c_write((__int64 *)a2, 4, v10[0]);
  if ( *(_DWORD *)(a2 + 768) )
    queue_work_on(32, system_wq, a2 + 560);
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return 1;
}
