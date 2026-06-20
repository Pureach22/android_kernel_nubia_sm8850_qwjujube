__int64 __fastcall aw8693x_get_irq_state(__int64 a1)
{
  int v2; // w8
  char v3; // w8
  unsigned int v4; // w9
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 17);
  v6[0] = 0;
  if ( v2 == 1 )
    *(_WORD *)(*(_QWORD *)(a1 + 808) + 2LL) = 91;
  i2c_r_bytes(a1, 2, v6, 1);
  if ( *(_BYTE *)(a1 + 17) == 1 )
    *(_WORD *)(*(_QWORD *)(a1 + 808) + 2LL) = 0;
  v3 = v6[0];
  if ( (v6[0] & 0x80000000) != 0 )
  {
    *(_BYTE *)(a1 + 29) = 0;
    printk(&unk_16477, "haptic_hv", 1131, "aw8693x_get_irq_state");
    v3 = v6[0];
    v4 = 3;
    if ( (v6[0] & 0x40) == 0 )
    {
LABEL_7:
      if ( (v3 & 0x20) == 0 )
        goto LABEL_8;
      goto LABEL_18;
    }
  }
  else
  {
    v4 = -1;
    if ( (v6[0] & 0x40) == 0 )
      goto LABEL_7;
  }
  *(_BYTE *)(a1 + 29) = 0;
  printk(&unk_162FC, "haptic_hv", 1137, "aw8693x_get_irq_state");
  v3 = v6[0];
  v4 = 4;
  if ( (v6[0] & 0x20) == 0 )
  {
LABEL_8:
    if ( (v3 & 4) == 0 )
      goto LABEL_9;
    goto LABEL_19;
  }
LABEL_18:
  *(_BYTE *)(a1 + 29) = 0;
  printk(&unk_169AC, "haptic_hv", 1143, "aw8693x_get_irq_state");
  v3 = v6[0];
  v4 = 5;
  if ( (v6[0] & 4) == 0 )
  {
LABEL_9:
    if ( (v3 & 2) == 0 )
      goto LABEL_10;
    goto LABEL_20;
  }
LABEL_19:
  *(_BYTE *)(a1 + 29) = 0;
  printk(&unk_16753, "haptic_hv", 1149, "aw8693x_get_irq_state");
  v3 = v6[0];
  v4 = 6;
  if ( (v6[0] & 2) == 0 )
  {
LABEL_10:
    if ( (v3 & 1) == 0 )
      goto LABEL_11;
LABEL_21:
    *(_BYTE *)(a1 + 29) = 0;
    printk(&unk_15464, "haptic_hv", 1161, "aw8693x_get_irq_state");
    v3 = v6[0];
    v4 = 10;
    if ( (v6[0] & 8) == 0 )
      goto LABEL_12;
    goto LABEL_22;
  }
LABEL_20:
  *(_BYTE *)(a1 + 29) = 0;
  printk(&unk_1631F, "haptic_hv", 1155, "aw8693x_get_irq_state");
  v3 = v6[0];
  v4 = 7;
  if ( (v6[0] & 1) != 0 )
    goto LABEL_21;
LABEL_11:
  if ( (v3 & 8) == 0 )
    goto LABEL_12;
LABEL_22:
  printk(&unk_158C7, "haptic_hv", 1166, "aw8693x_get_irq_state");
  v3 = v6[0];
  v4 = 2;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  if ( (v3 & 0x10) != 0 )
    return 0;
  else
    return v4;
}
