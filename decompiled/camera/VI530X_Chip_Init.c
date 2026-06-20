__int64 __fastcall VI530X_Chip_Init(__int64 a1)
{
  int v2; // w1
  int v3; // w2
  unsigned int byte; // w0
  int v5; // w1
  unsigned int inited; // w20
  int v7; // w1
  int v8; // w1
  int v9; // w1
  int v10; // w1
  __int64 v11; // x2
  __int64 v12; // x2
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x2
  void *v16; // x0
  unsigned int v18; // w9
  int v19; // w8
  unsigned int v20; // w10
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE2(v21[0]) = 0;
  LOWORD(v21[0]) = 0;
  vi530x_read_multibytes(a1, 44, v21, 3);
  printk(&unk_3F42A3);
  LOBYTE(v21[0]) = 0;
  _const_udelay("d: %u rc: %d", v2, v3);
  byte = vi530x_read_byte(a1, 2, v21);
  if ( byte == -22 )
    goto LABEL_2;
  if ( (v21[0] & 1) != 0 )
  {
    _const_udelay("d: %u rc: %d", v5, LOBYTE(v21[0]));
    byte = vi530x_read_byte(a1, 2, v21);
    if ( byte != -22 )
    {
      if ( (v21[0] & 1) == 0 )
        goto LABEL_4;
      _const_udelay("d: %u rc: %d", v7, LOBYTE(v21[0]));
      byte = vi530x_read_byte(a1, 2, v21);
      if ( byte != -22 )
      {
        if ( (v21[0] & 1) == 0 )
          goto LABEL_4;
        _const_udelay("d: %u rc: %d", v8, LOBYTE(v21[0]));
        byte = vi530x_read_byte(a1, 2, v21);
        if ( byte != -22 )
        {
          if ( (v21[0] & 1) == 0 )
            goto LABEL_4;
          _const_udelay("d: %u rc: %d", v9, LOBYTE(v21[0]));
          if ( (unsigned int)vi530x_read_byte(a1, 2, v21) != -22 )
          {
            if ( (v21[0] & 1) == 0
              || (_const_udelay("d: %u rc: %d", v10, LOBYTE(v21[0])), (unsigned int)vi530x_read_byte(a1, 2, v21) != -22) )
            {
              printk(&unk_43E66A);
              inited = -1;
              goto LABEL_21;
            }
          }
        }
      }
    }
LABEL_2:
    inited = -22;
    printk(&unk_3E7EB1);
LABEL_21:
    v16 = &unk_3E00FF;
LABEL_22:
    printk(v16);
    goto LABEL_23;
  }
LABEL_4:
  inited = byte;
  if ( byte )
    goto LABEL_21;
  LOBYTE(v21[0]) = 0;
  vi530x_read_byte(a1, 4, v21);
  v11 = LOBYTE(v21[0]) | 1u;
  LOBYTE(v21[0]) |= 1u;
  vi530x_write_byte(a1, 4, v11);
  vi530x_read_byte(a1, 4, v21);
  if ( (v21[0] & 1) != 0 )
    goto LABEL_24;
  vi530x_read_byte(a1, 4, v21);
  v12 = LOBYTE(v21[0]) | 1u;
  LOBYTE(v21[0]) |= 1u;
  vi530x_write_byte(a1, 4, v12);
  vi530x_read_byte(a1, 4, v21);
  if ( (v21[0] & 1) != 0 )
    goto LABEL_24;
  vi530x_read_byte(a1, 4, v21);
  v13 = LOBYTE(v21[0]) | 1u;
  LOBYTE(v21[0]) |= 1u;
  vi530x_write_byte(a1, 4, v13);
  vi530x_read_byte(a1, 4, v21);
  if ( (v21[0] & 1) != 0
    || (vi530x_read_byte(a1, 4, v21),
        v14 = LOBYTE(v21[0]) | 1u,
        LOBYTE(v21[0]) |= 1u,
        vi530x_write_byte(a1, 4, v14),
        vi530x_read_byte(a1, 4, v21),
        (v21[0] & 1) != 0) )
  {
LABEL_24:
    inited = VI530X_Init_FirmWare(a1);
    if ( !inited )
    {
      v21[0] = 0;
      vi530x_write_reg_offset(a1, 12, 0, 0);
      vi530x_write_reg_offset(a1, 12, 1, 8);
      vi530x_write_reg_offset(a1, 12, 2, 26);
      vi530x_write_byte(a1, 10, 9);
      _const_udelay((const char *)0x147AEB8);
      vi530x_read_multibytes(a1, 12, v21, 8);
      v18 = BYTE2(v21[0]);
      v19 = (v21[0] & 0xF) + (LOBYTE(v21[0]) >> 4) + (BYTE1(v21[0]) >> 4) + (BYTE1(v21[0]) & 0xF);
      v20 = BYTE3(v21[0]);
      LODWORD(v21[0]) = 0;
      *(_BYTE *)(a1 + 256) = v19
                           + (v18 >> 4)
                           + (v18 & 0xF)
                           + (v20 >> 4)
                           + (v20 & 0xF)
                           + (BYTE4(v21[0]) >> 4)
                           + (BYTE4(v21[0]) & 0xF)
                           + (BYTE5(v21[0]) >> 4)
                           + (BYTE5(v21[0]) & 0xF)
                           + (BYTE6(v21[0]) >> 4)
                           + (BYTE6(v21[0]) & 0xF)
                           + (HIBYTE(v21[0]) >> 4)
                           + (HIBYTE(v21[0]) & 0xF);
      vi530x_write_reg_offset(a1, 12, 0, 6);
      vi530x_write_byte(a1, 10, 9);
      _const_udelay((const char *)0x147AEB8);
      vi530x_read_multibytes(a1, 12, v21, 4);
      printk(&unk_417FA1);
      goto LABEL_23;
    }
    v16 = &unk_3D3EFA;
    goto LABEL_22;
  }
  vi530x_read_byte(a1, 4, v21);
  v15 = LOBYTE(v21[0]) | 1u;
  LOBYTE(v21[0]) |= 1u;
  vi530x_write_byte(a1, 4, v15);
  vi530x_read_byte(a1, 4, v21);
  printk(&unk_413D94);
  printk(&unk_3E41E8);
  inited = -2;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return inited;
}
