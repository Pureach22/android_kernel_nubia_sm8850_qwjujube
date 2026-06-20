__int64 __fastcall ieee80211_max_num_channels(__int64 a1, int a2)
{
  __int64 result; // x0
  unsigned int v4; // [xsp+0h] [xbp-50h] BYREF
  int v5; // [xsp+4h] [xbp-4Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-48h]
  __int64 v7; // [xsp+10h] [xbp-40h]
  __int64 v8; // [xsp+18h] [xbp-38h]
  __int64 v9; // [xsp+20h] [xbp-30h]
  __int64 v10; // [xsp+28h] [xbp-28h]
  __int64 v11; // [xsp+30h] [xbp-20h]
  __int64 v12; // [xsp+38h] [xbp-18h]
  __int64 v13; // [xsp+40h] [xbp-10h]
  __int64 v14; // [xsp+48h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 1;
  v5 = a2;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  v6 = 0;
  v7 = 0;
  ((void (__fastcall *)(__int64, int *, _QWORD, _QWORD))ieee80211_fill_ifcomb_params)(a1, &v5, 0, 0);
  LODWORD(result) = cfg80211_iter_combinations(*(_QWORD *)(a1 + 72), &v5, ieee80211_iter_max_chans, &v4);
  _ReadStatusReg(SP_EL0);
  if ( (int)result >= 0 )
    return v4;
  else
    return (unsigned int)result;
}
