__int64 __fastcall VI530X_Config_XTalk_Parameter(__int64 a1, int a2, int a3)
{
  int byte; // w0
  int v5; // w1
  int v6; // w1
  int v7; // w1
  int v8; // w1
  __int64 result; // x0
  int v10; // w1
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  _const_udelay("d: %u rc: %d", a2, a3);
  byte = vi530x_read_byte(a1, 2, v11);
  if ( byte == -22 )
    goto LABEL_15;
  if ( (v11[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v5, v11[0]);
  byte = vi530x_read_byte(a1, 2, v11);
  if ( byte == -22 )
    goto LABEL_15;
  if ( (v11[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v6, v11[0]);
  byte = vi530x_read_byte(a1, 2, v11);
  if ( byte == -22 )
    goto LABEL_15;
  if ( (v11[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v7, v11[0]);
  byte = vi530x_read_byte(a1, 2, v11);
  if ( byte == -22 )
  {
LABEL_15:
    printk(&unk_3E7EB1);
    goto LABEL_16;
  }
  if ( (v11[0] & 1) != 0 )
  {
    _const_udelay("d: %u rc: %d", v8, v11[0]);
    if ( (unsigned int)vi530x_read_byte(a1, 2, v11) != -22 )
    {
      if ( (v11[0] & 1) == 0
        || (_const_udelay("d: %u rc: %d", v10, v11[0]), (unsigned int)vi530x_read_byte(a1, 2, v11) != -22) )
      {
        printk(&unk_43E66A);
        goto LABEL_16;
      }
    }
    goto LABEL_15;
  }
LABEL_9:
  if ( byte )
  {
LABEL_16:
    printk(&unk_3F83F3);
    result = 4294967291LL;
    goto LABEL_17;
  }
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 1);
  vi530x_write_reg_offset(a1, 12, 2, 38);
  vi530x_write_reg_offset(a1, 12, 3, *(unsigned __int8 *)(a1 + 46));
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 1);
  vi530x_write_reg_offset(a1, 12, 2, 37);
  vi530x_write_reg_offset(a1, 12, 3, *(unsigned __int8 *)(a1 + 47));
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
