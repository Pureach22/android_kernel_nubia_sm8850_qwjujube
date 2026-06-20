size_t __fastcall freq_store(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x20
  size_t v5; // x19
  __int16 v7; // w8
  unsigned int v8; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int16 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = mAWP1921;
  v8 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v10 = 0;
  v9 = 0;
  _check_object_size(&v9, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)&v9, a2, v5) || (unsigned int)kstrtouint(&v9, 0, &v8) )
  {
    v5 = -22;
  }
  else
  {
    if ( v8 >= 0xFFFF )
      v7 = -1;
    else
      v7 = v8;
    *(_WORD *)(v4 + 2092) = v7;
    printk(&unk_8914, "freq_store", 515);
    if ( *(int *)(v4 + 2084) >= 1 )
      awp1921_i2c_write((__int64 *)v4, 0x15u, *(_WORD *)(v4 + 2092));
    printk(&unk_83C8, "freq_store", 520);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
