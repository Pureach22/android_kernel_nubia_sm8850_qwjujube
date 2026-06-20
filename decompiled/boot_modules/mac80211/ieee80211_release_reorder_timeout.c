__int64 __fastcall ieee80211_release_reorder_timeout(__int64 result, unsigned int a2)
{
  unsigned __int64 v2; // x9
  __int64 v3; // x8
  int v4; // w10
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x11
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 v10; // x23
  __int16 v11; // w22
  _QWORD v12[2]; // [xsp+0h] [xbp-90h] BYREF
  __int16 v13; // [xsp+10h] [xbp-80h]
  __int16 v14; // [xsp+12h] [xbp-7Eh]
  int v15; // [xsp+14h] [xbp-7Ch]
  _QWORD v16[2]; // [xsp+18h] [xbp-78h] BYREF
  __int64 v17; // [xsp+28h] [xbp-68h]
  __int64 v18; // [xsp+30h] [xbp-60h]
  __int64 v19; // [xsp+38h] [xbp-58h]
  __int64 v20; // [xsp+40h] [xbp-50h]
  __int64 v21; // [xsp+48h] [xbp-48h]
  __int64 v22; // [xsp+50h] [xbp-40h]
  __int64 v23; // [xsp+58h] [xbp-38h]
  unsigned __int64 v24; // [xsp+60h] [xbp-30h]
  __int64 v25; // [xsp+68h] [xbp-28h]
  _QWORD *v26; // [xsp+70h] [xbp-20h] BYREF
  _QWORD **v27; // [xsp+78h] [xbp-18h]
  __int64 v28; // [xsp+80h] [xbp-10h]
  __int64 v29; // [xsp+88h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(result + 2872);
  v23 = 0;
  v24 = 0;
  v27 = nullptr;
  v28 = 0;
  v26 = nullptr;
  v25 = 0;
  v3 = __clz(__rbit32(v2));
  v21 = 0;
  v22 = 0;
  if ( (_DWORD)v2 )
    v4 = v3;
  else
    v4 = -1;
  v17 = 0;
  v18 = 0;
  v16[0] = 0;
  v16[1] = 0;
  HIDWORD(v23) = a2;
  v24 = __PAIR64__(v4, a2);
  v19 = 0;
  v20 = result;
  if ( result )
  {
    v5 = *(_QWORD *)(result + 80);
    v21 = result + 1640;
    v6 = *(_QWORD *)(v5 + 1616);
    v17 = v6;
    v18 = v5;
    if ( (_DWORD)v2 )
    {
      HIDWORD(v24) = v3;
      v7 = *(_QWORD *)(v5 + 8LL * (unsigned int)v3 + 4568);
      v19 = v7;
      if ( ((v2 >> v3) & 1) == 0 )
        goto LABEL_20;
      v8 = *(_QWORD *)(result + 8 * v3 + 2568);
      v21 = v8;
      if ( !v7 || !v8 )
        goto LABEL_20;
      goto LABEL_15;
    }
LABEL_14:
    v19 = v5 + 3616;
    goto LABEL_15;
  }
  if ( !(_DWORD)v2 )
  {
    v5 = 0;
    v6 = 0;
    goto LABEL_14;
  }
  HIDWORD(v24) = v3;
  v19 = qword_11D8[(unsigned int)v3];
  if ( !v19 )
  {
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v5 = 0;
  v6 = 0;
LABEL_15:
  if ( a2 < 0x11 )
  {
    v9 = *(_QWORD *)(result + 8LL * a2 + 696);
    if ( v9 )
    {
      v10 = result;
      v11 = a2;
      v26 = &v26;
      v27 = &v26;
      LODWORD(v28) = 0;
      raw_spin_lock(v9 + 16);
      ieee80211_sta_reorder_release(v9, &v26);
      raw_spin_unlock(v9 + 16);
      if ( v26 != &v26 )
      {
        v12[0] = 3;
        v12[1] = v10 + 2688;
        v13 = v11;
        v14 = 0;
        v15 = 0;
        drv_event_callback_0(v6, v5, v12);
      }
      result = ieee80211_rx_handlers(v16, &v26);
    }
    goto LABEL_20;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))ieee80211_sta_reorder_release)();
}
