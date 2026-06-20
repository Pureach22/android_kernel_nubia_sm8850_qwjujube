__int64 __fastcall full_cache_threshold_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v5 = kstrtouint(a3, 0, &v7);
  if ( v5 )
    a4 = v5;
  else
    dword_3A8F8 = v7;
  _ReadStatusReg(SP_EL0);
  return a4;
}
