__int64 __fastcall aw882xx_i2c_write_bits(__int64 a1, char a2, int a3, int a4)
{
  unsigned int v8; // w0
  __int64 result; // x0
  __int64 v10; // x1
  unsigned int v11; // w19
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v8 = aw882xx_i2c_read(a1, a2, &v12);
  if ( (v8 & 0x80000000) != 0
    || (v8 = aw882xx_i2c_write(a1, a2, v12 & a3 | a4 & (unsigned int)~a3), (v8 & 0x80000000) != 0) )
  {
    v10 = *(_QWORD *)(a1 + 144);
    if ( !v10 )
      v10 = *(_QWORD *)(a1 + 32);
    v11 = v8;
    printk(&unk_263DF, v10, "aw882xx_i2c_write_bits");
    result = v11;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
