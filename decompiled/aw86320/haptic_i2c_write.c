__int64 __fastcall haptic_i2c_write(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 result; // x0
  __int64 v6; // x6
  __int64 v7; // x6
  __int64 v8; // x6
  __int64 v9; // x6
  __int64 v10; // x6
  unsigned int v11; // w19
  _WORD v12[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v3 = a2;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = bswap32(a3) >> 16;
  result = haptic_i2c_writes(a1, a2, v12, 2);
  if ( (result & 0x80000000) != 0 )
  {
    printk(&unk_9DA0, "aw86320", 102, "haptic_i2c_write", 0, (unsigned int)result, v6);
    result = haptic_i2c_writes(a1, v3, v12, 2);
    if ( (result & 0x80000000) != 0 )
    {
      printk(&unk_9DA0, "aw86320", 102, "haptic_i2c_write", 1, (unsigned int)result, v7);
      result = haptic_i2c_writes(a1, v3, v12, 2);
      if ( (result & 0x80000000) != 0 )
      {
        printk(&unk_9DA0, "aw86320", 102, "haptic_i2c_write", 2, (unsigned int)result, v8);
        result = haptic_i2c_writes(a1, v3, v12, 2);
        if ( (result & 0x80000000) != 0 )
        {
          printk(&unk_9DA0, "aw86320", 102, "haptic_i2c_write", 3, (unsigned int)result, v9);
          v11 = haptic_i2c_writes(a1, v3, v12, 2);
          if ( (v11 & 0x80000000) != 0 )
            printk(&unk_9DA0, "aw86320", 102, "haptic_i2c_write", 4, v11, v10);
          result = v11;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
