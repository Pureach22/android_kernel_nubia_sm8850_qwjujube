size_t __fastcall reg_store(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 *v4; // x20
  size_t v5; // x19
  __int16 v7; // w21
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  char s[16]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (__int64 *)mAWP1921;
  *(_QWORD *)&s[7] = 0;
  if ( a3 >= 0xE )
    v5 = 14;
  else
    v5 = a3;
  v8 = 0;
  *(_QWORD *)s = 0;
  printk(&unk_845A, "reg_store", 459);
  _check_object_size(s, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)s, a2, v5) )
  {
    v5 = -22;
  }
  else if ( sscanf(s, "%x %x", &v8, (char *)&v8 + 4) == 2 )
  {
    v7 = WORD2(v8);
    printk(&unk_8686, "reg_store", 467);
    awp1921_i2c_write(v4, v8, v7);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
