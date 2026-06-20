__int64 __fastcall ieee80211_roc_notify_destroy(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x1
  __int64 v7; // x8
  _QWORD *v8; // x8
  __int64 v9; // x9
  __int64 result; // x0
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[7];
  if ( v2 )
  {
    v11[0] = a1[9];
    v11[1] = 0;
    v3 = *(_QWORD *)(v2 + 224);
    v4 = *(unsigned int *)(v2 + 112);
    v11[2] = 0;
    v11[3] = v3;
    v5 = a1[2];
    v11[4] = v4;
    v11[5] = 0;
    cfg80211_mgmt_tx_status_ext(v5 + 16, v11, 3264);
    ieee80211_free_txskb(*(_QWORD *)(a1[2] + 1616LL));
  }
  v6 = a1[9];
  v7 = a1[2];
  if ( v6 )
    cfg80211_tx_mgmt_expired(v7 + 16, v6, a1[3], 3264);
  else
    cfg80211_remain_on_channel_expired(v7 + 16, a1[8], a1[3], 3264);
  v8 = (_QWORD *)a1[1];
  if ( (_QWORD *)*v8 == a1 && (v9 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
  {
    *(_QWORD *)(v9 + 8) = v8;
    *v8 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  result = kfree(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
