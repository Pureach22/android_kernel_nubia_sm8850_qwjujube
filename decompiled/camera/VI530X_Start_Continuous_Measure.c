__int64 __fastcall VI530X_Start_Continuous_Measure(__int64 a1, int a2, int a3)
{
  int byte; // w0
  int v5; // w1
  int v6; // w1
  int v7; // w1
  int v8; // w1
  __int64 result; // x0
  void *v10; // x0
  int v11; // w1
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  _const_udelay("d: %u rc: %d", a2, a3);
  byte = vi530x_read_byte(a1, 2, v12);
  if ( byte == -22 )
    goto LABEL_16;
  if ( (v12[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v5, v12[0]);
  byte = vi530x_read_byte(a1, 2, v12);
  if ( byte == -22 )
    goto LABEL_16;
  if ( (v12[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v6, v12[0]);
  byte = vi530x_read_byte(a1, 2, v12);
  if ( byte == -22 )
    goto LABEL_16;
  if ( (v12[0] & 1) == 0 )
    goto LABEL_9;
  _const_udelay("d: %u rc: %d", v7, v12[0]);
  byte = vi530x_read_byte(a1, 2, v12);
  if ( byte == -22 )
  {
LABEL_16:
    printk(&unk_3E7EB1);
    goto LABEL_17;
  }
  if ( (v12[0] & 1) != 0 )
  {
    _const_udelay("d: %u rc: %d", v8, v12[0]);
    if ( (unsigned int)vi530x_read_byte(a1, 2, v12) != -22 )
    {
      if ( (v12[0] & 1) == 0
        || (_const_udelay("d: %u rc: %d", v11, v12[0]), (unsigned int)vi530x_read_byte(a1, 2, v12) != -22) )
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
    v10 = &unk_42B19B;
    goto LABEL_18;
  }
  result = vi530x_write_byte(a1, 10, 15);
  if ( (_DWORD)result )
  {
    v10 = &unk_403D94;
LABEL_18:
    printk(v10);
    result = 4294967289LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
