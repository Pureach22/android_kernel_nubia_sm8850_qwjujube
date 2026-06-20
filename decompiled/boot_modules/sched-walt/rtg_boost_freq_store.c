__int64 __fastcall rtg_boost_freq_store(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  if ( (unsigned int)kstrtouint(a2, 10, &v6) )
    a3 = -22;
  else
    *(_DWORD *)(a1 + 188) = v6;
  _ReadStatusReg(SP_EL0);
  return a3;
}
