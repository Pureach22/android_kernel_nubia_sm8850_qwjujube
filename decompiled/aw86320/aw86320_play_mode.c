__int64 __fastcall aw86320_play_mode(_BYTE *a1, char a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 result; // x0

  if ( a2 )
  {
    result = printk(&unk_9D7D, "aw86320", 297, "aw86320_play_mode", a5, a6, a7);
    if ( a1[838] == 1 )
      a1[1] = 1;
    if ( a1[837] == 1 )
      a1[1] = 2;
  }
  else
  {
    printk(&unk_96B7, "aw86320", 291, "aw86320_play_mode", a5, a6, a7);
    haptic_i2c_write(a1, 27, 3598);
    haptic_i2c_write(a1, 37, 0);
    return _const_udelay(12885000);
  }
  return result;
}
