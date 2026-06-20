__int64 __fastcall reg_show(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 *v7; // x23
  __int64 result; // x0
  int v9; // w24
  unsigned __int64 v10; // x22
  int v11; // w0
  _WORD v12[2]; // [xsp+0h] [xbp-520h] BYREF
  char s[1300]; // [xsp+4h] [xbp-51Ch] BYREF
  __int64 v14; // [xsp+518h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = (__int64 *)mAWP1921;
  v12[0] = 0;
  memset(s, 0, sizeof(s));
  if ( *a4 )
  {
    result = 0;
  }
  else
  {
    v9 = 0;
    v10 = 0;
    do
    {
      awp1921_i2c_read(v7, v9, v12);
      if ( v10 >= 0x515 )
        __break(0x5512u);
      v11 = snprintf(&s[v10], 4096 - v10, "reg:0x%02x=0x%04x\n", v9++, v12[0]);
      v10 += v11;
    }
    while ( v9 != 31 );
    printk(&unk_866A, "reg_show", 444);
    result = simple_read_from_buffer(a2, a3, a4, s, v10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
