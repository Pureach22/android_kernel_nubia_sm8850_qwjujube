__int64 __fastcall cfg80211_check_combinations(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v3; // w8
  unsigned int v4; // w8
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, __int64 (__fastcall *)(), int *))cfg80211_iter_combinations)(
                      a1,
                      a2,
                      cfg80211_iter_sum_ifcombs,
                      &v5);
  v3 = v5;
  _ReadStatusReg(SP_EL0);
  if ( v3 )
    v4 = 0;
  else
    v4 = -16;
  if ( (_DWORD)result )
    return (unsigned int)result;
  else
    return v4;
}
