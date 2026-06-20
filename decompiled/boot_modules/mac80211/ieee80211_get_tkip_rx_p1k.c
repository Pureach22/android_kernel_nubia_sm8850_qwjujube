__int64 __fastcall ieee80211_get_tkip_rx_p1k(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  __int16 v6; // w9
  __int64 v7; // [xsp+0h] [xbp-20h] BYREF
  __int64 v8; // [xsp+8h] [xbp-18h]
  int v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v7 = 0;
  v8 = 0;
  result = tkip_mixing_phase1(a1 + 20, &v7, a2, a3);
  v6 = v8;
  *(_QWORD *)a4 = v7;
  *(_WORD *)(a4 + 8) = v6;
  _ReadStatusReg(SP_EL0);
  return result;
}
