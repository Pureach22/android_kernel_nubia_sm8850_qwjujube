__int64 __fastcall lpg_pattern_single_set(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x8
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v1 = a1 - 8;
  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = lpg_pattern_set(a1 - 8);
  if ( (result & 0x80000000) == 0 )
  {
    v4 = *(_QWORD *)(a1 - 8);
    v5[0] = 0xFF00000000LL;
    v5[1] = 0;
    mutex_lock(v4 + 16);
    lpg_brightness_set(v1, a1, v5);
    mutex_unlock(*(_QWORD *)(a1 - 8) + 16LL);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
