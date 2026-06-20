__int64 __fastcall irq_handle(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  unsigned __int16 v8; // w19
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  unsigned __int16 v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_9E3C, "aw86320", 407, "irq_handle", a5, a6, a7);
  v15 = 0;
  haptic_i2c_read(a2, 4, &v15);
  v8 = v15;
  printk(&unk_99BA, "aw86320", 385, "aw86320_get_irq_state", v15, v9, v10);
  if ( (v8 & 0x200) != 0 )
  {
    printk(&unk_A2C0, "aw86320", 388, "aw86320_get_irq_state", v11, v12, v13);
    if ( (v8 & 0x100) == 0 )
    {
LABEL_3:
      if ( (v8 & 0x80) == 0 )
        goto LABEL_4;
      goto LABEL_11;
    }
  }
  else if ( (v8 & 0x100) == 0 )
  {
    goto LABEL_3;
  }
  printk(&unk_9D30, "aw86320", 390, "aw86320_get_irq_state", v11, v12, v13);
  if ( (v8 & 0x80) == 0 )
  {
LABEL_4:
    if ( (v8 & 0x40) == 0 )
      goto LABEL_5;
    goto LABEL_12;
  }
LABEL_11:
  printk(&unk_99E4, "aw86320", 392, "aw86320_get_irq_state", v11, v12, v13);
  if ( (v8 & 0x40) == 0 )
  {
LABEL_5:
    if ( (v8 & 0x20) == 0 )
      goto LABEL_6;
    goto LABEL_13;
  }
LABEL_12:
  printk(&unk_99FF, "aw86320", 394, "aw86320_get_irq_state", v11, v12, v13);
  if ( (v8 & 0x20) == 0 )
  {
LABEL_6:
    if ( (v8 & 0x10) == 0 )
      goto LABEL_7;
LABEL_14:
    printk(&unk_A4AF, "aw86320", 398, "aw86320_get_irq_state", v11, v12, v13);
    if ( (v8 & 8) == 0 )
      goto LABEL_8;
LABEL_15:
    printk(&unk_971D, "aw86320", 400, "aw86320_get_irq_state", v11, v12, v13);
    goto LABEL_8;
  }
LABEL_13:
  printk(&unk_A610, "aw86320", 396, "aw86320_get_irq_state", v11, v12, v13);
  if ( (v8 & 0x10) != 0 )
    goto LABEL_14;
LABEL_7:
  if ( (v8 & 8) != 0 )
    goto LABEL_15;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return 1;
}
