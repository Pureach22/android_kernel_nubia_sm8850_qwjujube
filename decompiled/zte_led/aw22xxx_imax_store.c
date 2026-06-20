__int64 __fastcall aw22xxx_imax_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w8
  unsigned int v8; // w8
  __int64 *v9; // x20
  char v10; // w21
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  v6 = sscanf(s, "%x", &v12);
  v7 = v12;
  if ( v6 == 1 && v12 < 0xD )
  {
    *(_DWORD *)(v5 + 736) = v12;
    v8 = (unsigned __int8)aw22xxx_imax_code[v7];
    v9 = (__int64 *)(v5 - 16);
    if ( v8 >= 0xF )
      v10 = 15;
    else
      v10 = v8;
    aw22xxx_i2c_write(v9, 255, 0);
    aw22xxx_i2c_write(v9, 11, v10);
  }
  else
  {
    printk(&unk_12D0C, "aw22xxx_imax_store");
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
