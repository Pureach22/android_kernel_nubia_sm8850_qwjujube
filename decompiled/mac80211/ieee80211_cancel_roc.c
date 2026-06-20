__int64 __fastcall ieee80211_cancel_roc(__int64 a1, __int64 a2, char a3)
{
  __int64 *v6; // x20
  __int64 v7; // x23
  __int64 *v8; // x8
  __int64 result; // x0
  __int64 *v10; // x0
  __int64 *v11; // x21
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x20

  if ( !a2 )
    return 4294967294LL;
  wiphy_work_flush(*(_QWORD *)(a1 + 72), a1 + 5280);
  v6 = *(__int64 **)(a1 + 5264);
  v7 = a1 + 5264;
  if ( v6 == (__int64 *)(a1 + 5264) )
    return 4294967294LL;
  while ( 1 )
  {
    v8 = (__int64 *)*v6;
    if ( (a3 & 1) != 0 )
      break;
    if ( v6[8] == a2 )
      goto LABEL_8;
LABEL_5:
    v6 = (__int64 *)*v6;
    if ( v8 == (__int64 *)v7 )
      return 4294967294LL;
  }
  if ( v6[9] != a2 )
    goto LABEL_5;
LABEL_8:
  if ( !v6 )
    return 4294967294LL;
  if ( (v6[4] & 1) == 0 )
  {
    ieee80211_roc_notify_destroy(v6);
    return 0;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 472LL) )
  {
    v12 = 0;
    *((_BYTE *)v6 + 33) = 1;
    v13 = *(_QWORD *)(a1 + 72);
    v14 = a1 + 5192;
    goto LABEL_28;
  }
  result = drv_cancel_remain_on_channel(a1, v6[2]);
  if ( (_DWORD)result )
  {
    __break(0x800u);
  }
  else
  {
    wiphy_work_cancel(*(_QWORD *)(a1 + 72), a1 + 5304);
    v10 = *(__int64 **)(a1 + 5264);
    if ( v10 == (__int64 *)v7 )
      goto LABEL_33;
    do
    {
      if ( *((_BYTE *)v10 + 32) != 1 )
        break;
      v11 = (__int64 *)*v10;
      if ( v10 == v6 )
        v6 = nullptr;
      ieee80211_roc_notify_destroy(v10);
      v10 = v11;
    }
    while ( v11 != (__int64 *)v7 );
    if ( v6 )
LABEL_33:
      __break(0x800u);
    if ( *(_QWORD *)v7 == v7 )
    {
      ieee80211_run_deferred_scan(a1);
      return 0;
    }
    if ( (*(_BYTE *)(a1 + 1470) & 1) != 0 )
      return 0;
    if ( *(_BYTE *)(*(_QWORD *)v7 + 32LL) == 1 )
    {
      __break(0x800u);
      return 0;
    }
    else
    {
      if ( *(_QWORD *)(*(_QWORD *)(a1 + 464) + 472LL) )
      {
        ieee80211_start_next_roc(a1);
        return 0;
      }
      v15 = *(_QWORD *)(a1 + 72);
      v12 = round_jiffies_relative(125);
      v14 = a1 + 5192;
      v13 = v15;
LABEL_28:
      wiphy_delayed_work_queue(v13, v14, v12);
      return 0;
    }
  }
  return result;
}
