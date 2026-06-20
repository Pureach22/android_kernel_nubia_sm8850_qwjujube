__int64 __fastcall idle_timer_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w21
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  v6 = kstrtouint(a3, 0, &v9);
  if ( v6 )
  {
    a4 = v6;
  }
  else
  {
    v7 = v9;
    if ( v7 <= (unsigned int)jiffies_to_usecs(0x3FFFFFFFFFFFFFFELL) )
      *(_QWORD *)(v5 + 10080) = v9;
    else
      a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
