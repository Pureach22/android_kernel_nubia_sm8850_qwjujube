__int64 __fastcall ieee80211_build_data_template(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x8
  unsigned __int64 v7; // x0
  __int64 v8; // x19
  unsigned __int64 v10; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v11[6]; // [xsp+10h] [xbp-50h] BYREF
  unsigned __int64 v12; // [xsp+40h] [xbp-20h]
  __int64 v13; // [xsp+48h] [xbp-18h]
  __int64 v14; // [xsp+50h] [xbp-10h]
  __int64 v15; // [xsp+58h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 1616);
  v13 = 0;
  v14 = 0;
  v11[5] = a1;
  v12 = 0;
  memset(v11, 0, 32);
  v11[4] = v6;
  v10 = 0;
  _rcu_read_lock(a1, a2);
  if ( (unsigned int)ieee80211_lookup_ra_sta(a1, a2, &v10) )
  {
    v7 = sk_skb_reason_drop(0);
    v8 = -22;
LABEL_6:
    _rcu_read_unlock(v7);
    goto LABEL_7;
  }
  v7 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, unsigned __int64, __int64, _QWORD))ieee80211_build_hdr)(
         a1,
         a2,
         a3,
         v10,
         4026531840LL,
         0);
  v8 = v7;
  if ( v7 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_6;
  v12 = sta_info_get(a1, (const void *)(*(_QWORD *)(v7 + 224) + 4LL));
  v11[0] = v8;
  v7 = ieee80211_tx_h_select_key(v11);
  if ( !(_DWORD)v7 )
    goto LABEL_6;
  _rcu_read_unlock(v7);
  sk_skb_reason_drop(0);
  v8 = -22;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v8;
}
