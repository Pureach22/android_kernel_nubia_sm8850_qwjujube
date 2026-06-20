__int64 __fastcall store_use_sched_boost(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v6 = kstrtouint(a3, 10, &v8);
  if ( v6 < 0 )
    a4 = v6;
  else
    *(_DWORD *)(a1 - 296) = v8 != 0;
  _ReadStatusReg(SP_EL0);
  return a4;
}
