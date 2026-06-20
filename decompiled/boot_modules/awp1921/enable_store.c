size_t __fastcall enable_store(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v4; // x20
  size_t v5; // x19
  int v7; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  __int16 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = mAWP1921;
  v7 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v9 = 0;
  v8 = 0;
  _check_object_size(&v8, v5, 0);
  if ( (unsigned int)inline_copy_from_user((int)&v8, a2, v5) || (unsigned int)kstrtouint(&v8, 0, &v7) )
  {
    v5 = -22;
  }
  else
  {
    printk(&unk_8914, "enable_store", 347);
    enableMicroPump(v4, v7 != 0);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
