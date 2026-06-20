__int64 __fastcall sde_i2c_byte_write(__int64 a1, unsigned __int8 a2, char a3, char *a4)
{
  __int64 v4; // x0
  char v5; // w8
  int v6; // w0
  unsigned int v7; // w1
  _BYTE v9[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v10[1] = v9;
  v4 = *(_QWORD *)(a1 + 24);
  v10[0] = a2 >> 1;
  v5 = *a4;
  v9[0] = a3;
  *(_DWORD *)((char *)v10 + 2) = 0x20000;
  v9[1] = v5;
  v6 = i2c_transfer(v4, v10, 1);
  v7 = v6;
  if ( v6 <= 0 )
  {
    printk(&unk_27AA26, (unsigned int)v6);
    v7 = -13;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
