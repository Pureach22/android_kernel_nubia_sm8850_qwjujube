__int64 __fastcall aw22xxx_i2c_read(_QWORD *a1, char a2, _BYTE *a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  void *v7; // x0
  void *v8; // x8
  unsigned int v9; // w19
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v10[0] = a2;
  if ( (i2c_transfer_buffer_flags(v5, v10, 1, 0) & 0x80000000) != 0 )
  {
    v7 = &unk_13925;
    goto LABEL_6;
  }
  result = i2c_transfer_buffer_flags(*a1, a3, 1, 1);
  if ( (result & 0x80000000) != 0 )
  {
    *a3 = result;
    v7 = &unk_12F1B;
LABEL_6:
    printk(v7, "aw22xxx_i2c_read");
    msleep(1);
    LODWORD(result) = i2c_transfer_buffer_flags(*a1, v10, 1, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v8 = &unk_13925;
    }
    else
    {
      result = i2c_transfer_buffer_flags(*a1, a3, 1, 1);
      if ( (result & 0x80000000) == 0 )
        goto LABEL_3;
      *a3 = result;
      v8 = &unk_12F1B;
    }
    v9 = result;
    printk(v8, "aw22xxx_i2c_read");
    msleep(1);
    result = v9;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
