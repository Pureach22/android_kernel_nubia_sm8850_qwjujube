__int64 __fastcall aw8693x_upload_lra(__int64 a1, int a2)
{
  char v3; // w8
  __int64 result; // x0
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  if ( a2 == 2 )
  {
    printk(&unk_153C4, "haptic_hv", 710, "aw8693x_upload_lra");
    v3 = *(_BYTE *)(a1 + 152);
LABEL_9:
    v5[0] = v3 & 0x7F;
    goto LABEL_10;
  }
  if ( a2 == 1 )
  {
    printk(&unk_1456D, "haptic_hv", 706, "aw8693x_upload_lra");
LABEL_8:
    v3 = *(_BYTE *)(a1 + 136);
    goto LABEL_9;
  }
  if ( a2 )
  {
    printk(&unk_15AC0, "haptic_hv", 714, "aw8693x_upload_lra");
    goto LABEL_8;
  }
  printk(&unk_15DF7, "haptic_hv", 703, "aw8693x_upload_lra");
LABEL_10:
  result = i2c_w_bytes(a1, 93, v5, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
