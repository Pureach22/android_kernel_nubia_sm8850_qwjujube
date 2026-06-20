__int64 __fastcall up_rate_limit_us_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x20
  _QWORD *v6; // x22
  _QWORD *v7; // t1
  __int64 v8; // x8
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( (unsigned int)kstrtouint(a2, 10, &v10) )
  {
    a3 = -22;
  }
  else
  {
    v7 = *(_QWORD **)(a1 + 96);
    v5 = a1 + 96;
    v6 = v7;
    for ( *(_DWORD *)(v5 + 72) = v10; v6 != (_QWORD *)v5; v6 = (_QWORD *)*v6 )
    {
      v6[16] = 1000LL * v10;
      mutex_lock(&min_rate_lock);
      v8 = v6[16];
      if ( v8 >= v6[17] )
        v8 = v6[17];
      v6[15] = v8;
      mutex_unlock(&min_rate_lock);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
