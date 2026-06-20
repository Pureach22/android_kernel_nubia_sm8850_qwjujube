__int64 __fastcall i2c_addr_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v7[0] = 0;
  if ( v4 && *(_QWORD *)(v4 + 168) )
  {
    if ( (unsigned int)kstrtoll(a3, 10, v7) )
    {
      result = -22;
    }
    else
    {
      mutex_lock(v4 + 24);
      *(_WORD *)(*(_QWORD *)(v4 + 168) + 2LL) = v7[0];
      mutex_unlock(v4 + 24);
      result = a4;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
