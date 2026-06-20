__int64 __fastcall ieee80211_set_ap_chanwidth(__int64 a1, __int64 a2, unsigned int a3, __int64 *a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v10; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v11[9]; // [xsp+8h] [xbp-48h] BYREF

  v11[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a4;
  v5 = a4[1];
  memset(&v11[4], 0, 32);
  v10 = 0;
  v11[0] = v4;
  v11[1] = v5;
  v6 = a4[3];
  v11[2] = a4[2];
  v11[3] = v6;
  if ( a3 >= 0xF )
    __break(0x5512u);
  v8 = *(_QWORD *)(a2 + 8LL * a3 + 7256);
  result = ieee80211_link_change_chanreq(v8, v11, &v10);
  if ( !(_DWORD)result )
  {
    ieee80211_link_info_change_notify(a2 + 2688, v8, v10);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
