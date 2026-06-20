__int64 __fastcall haptic_i2c_write_bits(__int64 a1, unsigned int a2, int a3, int a4)
{
  unsigned int v8; // w0
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 result; // x0
  __int64 v12; // x4
  void *v13; // x0
  __int64 v14; // x2
  __int16 v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v8 = haptic_i2c_read(a1, a2, &v15);
  if ( (v8 & 0x80000000) != 0 )
  {
    v12 = v8;
    v13 = &unk_A1EE;
    v14 = 175;
LABEL_6:
    result = printk(v13, "aw86320", v14, "haptic_i2c_write_bits", v12, v9, v10);
    goto LABEL_3;
  }
  result = haptic_i2c_write(a1, a2, (unsigned __int16)(v15 & a3) | a4 & (unsigned int)~a3);
  if ( (result & 0x80000000) != 0 )
  {
    v12 = (unsigned int)result;
    v13 = &unk_A45E;
    v14 = 184;
    goto LABEL_6;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
