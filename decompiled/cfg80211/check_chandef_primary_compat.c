__int64 __fastcall check_chandef_primary_compat(__int64 a1, __int64 a2, int a3)
{
  int v6; // w22
  __int64 result; // x0
  _WORD v8[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v8[0] = 0;
  v6 = cfg80211_chandef_primary(a1, a3, &v9);
  if ( v6 == (unsigned int)cfg80211_chandef_primary(a2, a3, v8) && v9 == v8[0] )
  {
    if ( *(_DWORD *)(a1 + 8) == a3 )
      result = a2;
    else
      result = 0;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
