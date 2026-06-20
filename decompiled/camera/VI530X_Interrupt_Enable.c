__int64 __fastcall VI530X_Interrupt_Enable(__int64 a1)
{
  __int64 v2; // x2
  __int64 result; // x0
  __int64 v4; // x2
  __int64 v5; // x2
  __int64 v6; // x2
  __int64 v7; // x2
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  vi530x_read_byte(a1, 4, v8);
  v2 = v8[0] | 1u;
  v8[0] |= 1u;
  vi530x_write_byte(a1, 4, v2);
  vi530x_read_byte(a1, 4, v8);
  result = 0;
  if ( (v8[0] & 1) == 0 )
  {
    vi530x_read_byte(a1, 4, v8);
    v4 = v8[0] | 1u;
    v8[0] |= 1u;
    vi530x_write_byte(a1, 4, v4);
    vi530x_read_byte(a1, 4, v8);
    if ( (v8[0] & 1) != 0 )
      goto LABEL_5;
    vi530x_read_byte(a1, 4, v8);
    v5 = v8[0] | 1u;
    v8[0] |= 1u;
    vi530x_write_byte(a1, 4, v5);
    vi530x_read_byte(a1, 4, v8);
    if ( (v8[0] & 1) != 0
      || (vi530x_read_byte(a1, 4, v8),
          v6 = v8[0] | 1u,
          v8[0] |= 1u,
          vi530x_write_byte(a1, 4, v6),
          vi530x_read_byte(a1, 4, v8),
          (v8[0] & 1) != 0) )
    {
LABEL_5:
      result = 0;
    }
    else
    {
      vi530x_read_byte(a1, 4, v8);
      v7 = v8[0] | 1u;
      v8[0] |= 1u;
      vi530x_write_byte(a1, 4, v7);
      vi530x_read_byte(a1, 4, v8);
      printk(&unk_413D94);
      result = 4294967294LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
