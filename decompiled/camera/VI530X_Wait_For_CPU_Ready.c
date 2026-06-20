__int64 __fastcall VI530X_Wait_For_CPU_Ready(__int64 a1, int a2, int a3)
{
  __int64 result; // x0
  int v5; // w1
  int v6; // w1
  int v7; // w1
  int v8; // w1
  int v9; // w1
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  _const_udelay("d: %u rc: %d", a2, a3);
  result = vi530x_read_byte(a1, 2, v10);
  if ( (_DWORD)result == -22 )
    goto LABEL_14;
  if ( (v10[0] & 1) != 0 )
  {
    _const_udelay("d: %u rc: %d", v5, v10[0]);
    result = vi530x_read_byte(a1, 2, v10);
    if ( (_DWORD)result == -22 )
      goto LABEL_14;
    if ( (v10[0] & 1) != 0 )
    {
      _const_udelay("d: %u rc: %d", v6, v10[0]);
      result = vi530x_read_byte(a1, 2, v10);
      if ( (_DWORD)result == -22 )
        goto LABEL_14;
      if ( (v10[0] & 1) != 0 )
      {
        _const_udelay("d: %u rc: %d", v7, v10[0]);
        result = vi530x_read_byte(a1, 2, v10);
        if ( (_DWORD)result != -22 )
        {
          if ( (v10[0] & 1) == 0 )
            goto LABEL_9;
          _const_udelay("d: %u rc: %d", v8, v10[0]);
          if ( (unsigned int)vi530x_read_byte(a1, 2, v10) != -22 )
          {
            if ( (v10[0] & 1) == 0
              || (_const_udelay("d: %u rc: %d", v9, v10[0]), (unsigned int)vi530x_read_byte(a1, 2, v10) != -22) )
            {
              printk(&unk_43E66A);
              result = 0xFFFFFFFFLL;
              goto LABEL_9;
            }
          }
        }
LABEL_14:
        printk(&unk_3E7EB1);
        result = 4294967274LL;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
