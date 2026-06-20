__int64 __fastcall VI530X_Start_XTalk_Calibration(__int64 a1, int a2, int a3)
{
  int byte; // w0
  int v5; // w1
  int v6; // w1
  int v7; // w1
  int v8; // w1
  int v9; // w2
  __int64 result; // x0
  void *v11; // x0
  int v12; // w1
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  _const_udelay("d: %u rc: %d", a2, a3);
  byte = vi530x_read_byte(a1, 2, v13);
  if ( byte == -22 )
    goto LABEL_16;
  if ( (v13[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v5, v13[0]);
  byte = vi530x_read_byte(a1, 2, v13);
  if ( byte == -22 )
    goto LABEL_16;
  if ( (v13[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v6, v13[0]);
  byte = vi530x_read_byte(a1, 2, v13);
  if ( byte == -22 )
    goto LABEL_16;
  if ( (v13[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v7, v13[0]);
  byte = vi530x_read_byte(a1, 2, v13);
  if ( byte == -22 )
  {
LABEL_16:
    printk(&unk_3E7EB1);
    goto LABEL_17;
  }
  if ( (v13[0] & 1) != 0 )
  {
    _const_udelay("d: %u rc: %d", v8, v13[0]);
    if ( (unsigned int)vi530x_read_byte(a1, 2, v13) != -22 )
    {
      if ( (v13[0] & 1) == 0
        || (_const_udelay("d: %u rc: %d", v12, v13[0]), (unsigned int)vi530x_read_byte(a1, 2, v13) != -22) )
      {
        printk(&unk_43E66A);
        goto LABEL_17;
      }
    }
    goto LABEL_16;
  }
LABEL_9:
  if ( byte )
  {
LABEL_17:
    v11 = &unk_442506;
    goto LABEL_18;
  }
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 1);
  vi530x_write_reg_offset(a1, 12, 2, 36);
  vi530x_write_reg_offset(a1, 12, 3, 0);
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  v9 = vi530x_write_byte(a1, 10, 13);
  result = 0;
  if ( v9 )
  {
    v11 = &unk_41F864;
LABEL_18:
    printk(v11);
    result = 4294967293LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
