void *__fastcall aw8693x_get_wav_seq(__int64 a1, unsigned int a2)
{
  __int64 v3; // x8
  size_t v4; // x20
  void *result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 8 )
    v4 = 8;
  else
    v4 = a2;
  v7[1] = v3;
  v7[0] = 0;
  result = (void *)i2c_r_bytes(a1, 10, v7, (unsigned int)v4);
  if ( a2 )
    result = memcpy((void *)(a1 + 30), v7, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
