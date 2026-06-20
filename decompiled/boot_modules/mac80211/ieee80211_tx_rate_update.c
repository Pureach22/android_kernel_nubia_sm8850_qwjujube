__int64 __fastcall ieee80211_tx_rate_update(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int16 v7; // w10
  __int64 v8; // x9
  _QWORD v9[8]; // [xsp+0h] [xbp-40h] BYREF

  v9[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = a2;
  v9[1] = a3;
  memset(&v9[2], 0, 40);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *))rate_control_tx_status)(a1, v9);
  if ( (*(_QWORD *)(a1 + 96) & 1) != 0 )
  {
    v7 = *(_WORD *)(a3 + 8);
    v8 = a2 - 296;
    *(_BYTE *)(v8 + 2) = *(_BYTE *)(a3 + 10);
    *(_WORD *)v8 = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
