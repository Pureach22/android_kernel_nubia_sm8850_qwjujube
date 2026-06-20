__int64 __fastcall ieee80211_calc_chandef_subchan_offset(__int64 a1, unsigned __int8 a2)
{
  int v4; // w0
  __int64 v5; // x9
  int v6; // w21
  __int64 v7; // x10
  unsigned int v8; // w20
  unsigned int v9; // w22
  __int64 v11; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ieee80211_chandef_num_subchans(a1);
  v5 = *(_QWORD *)(a1 + 8);
  v6 = a2;
  v11 = *(_QWORD *)a1;
  v12 = v5;
  v7 = *(_QWORD *)(a1 + 24);
  v13 = *(_QWORD *)(a1 + 16);
  v14 = v7;
  if ( v4 <= a2 )
  {
    v8 = 0;
  }
  else
  {
    if ( (int)ieee80211_chandef_num_subchans((__int64)&v11) <= a2 )
    {
      v8 = 0;
    }
    else
    {
      v8 = 0;
      do
      {
        v9 = HIDWORD(v12);
        ieee80211_chandef_downgrade(&v11, 0);
        if ( v9 < HIDWORD(v12) )
          v8 += ieee80211_chandef_num_subchans((__int64)&v11);
      }
      while ( (int)ieee80211_chandef_num_subchans((__int64)&v11) > v6 );
    }
    if ( *(_DWORD *)(a1 + 8) == 4 && *(_DWORD *)(a1 + 16) < *(_DWORD *)(a1 + 12) )
      v8 += 4;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
