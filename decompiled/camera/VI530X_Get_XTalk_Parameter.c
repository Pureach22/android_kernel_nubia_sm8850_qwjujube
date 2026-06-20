__int64 __fastcall VI530X_Get_XTalk_Parameter(__int64 a1)
{
  __int16 v2; // w9
  unsigned int v3; // w20
  char v4; // w10
  _BYTE v6[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v7; // [xsp+10h] [xbp-10h] BYREF
  char v8; // [xsp+14h] [xbp-Ch]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v8 = 0;
  v7 = 0;
  if ( (unsigned int)vi530x_read_byte(a1, 8, v6) || v6[0] != 170 )
  {
    printk(&unk_413DBF);
LABEL_8:
    v3 = -3;
    goto LABEL_5;
  }
  if ( (unsigned int)vi530x_read_multibytes(a1, 12, &v7, 4) )
  {
    printk(&unk_3FC6BC);
    goto LABEL_8;
  }
  v2 = *(_WORD *)((char *)&v7 + 1);
  v3 = 0;
  v4 = HIBYTE(v7);
  *(_BYTE *)(a1 + 36) = v7;
  *(_WORD *)(a1 + 38) = v2;
  *(_BYTE *)(a1 + 40) = v4;
LABEL_5:
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 1);
  vi530x_write_reg_offset(a1, 12, 2, 36);
  vi530x_write_reg_offset(a1, 12, 3, 1);
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  _ReadStatusReg(SP_EL0);
  return v3;
}
