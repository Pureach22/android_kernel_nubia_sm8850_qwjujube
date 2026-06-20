__int64 __fastcall hdd_driver_compat_ioctl(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v4; // [xsp+8h] [xbp-28h] BYREF
  int v5; // [xsp+10h] [xbp-20h]
  int v6; // [xsp+14h] [xbp-1Ch]
  __int64 v7; // [xsp+18h] [xbp-18h] BYREF
  int v8; // [xsp+20h] [xbp-10h]
  __int64 v9; // [xsp+28h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v7 = 0;
  if ( inline_copy_from_user_1((int)&v7, a2, 0xCu) )
  {
    result = 4294967282LL;
  }
  else
  {
    v4 = (unsigned int)v7;
    v5 = HIDWORD(v7);
    v6 = v8;
    result = hdd_driver_command(a1, &v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
