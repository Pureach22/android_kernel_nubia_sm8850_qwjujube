__int64 __fastcall hdd_driver_ioctl(__int64 a1, int a2)
{
  __int64 result; // x0
  _QWORD v4[3]; // [xsp+8h] [xbp-18h] BYREF

  v4[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v4[1] = 0;
  if ( inline_copy_from_user_1((int)v4, a2, 0x10u) )
    result = 4294967282LL;
  else
    result = hdd_driver_command(a1, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
