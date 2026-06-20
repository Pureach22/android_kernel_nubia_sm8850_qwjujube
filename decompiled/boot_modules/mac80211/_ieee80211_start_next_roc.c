__int64 __fastcall ieee80211_start_next_roc(__int64 result)
{
  __int64 v1; // x22
  __int64 *v2; // x23
  unsigned int v3; // w20
  __int64 v4; // x4
  _QWORD *v5; // x19
  __int64 *v6; // x8
  __int64 v7; // x3
  unsigned int v8; // w9
  unsigned int v9; // w10
  __int64 *j; // x8
  bool v11; // w8
  __int64 v12; // x21
  __int64 v13; // x0
  __int64 *k; // x19
  __int64 *i; // x8

  v1 = *(_QWORD *)(result + 5264);
  v2 = (__int64 *)(result + 5264);
  if ( v1 == result + 5264 || *(_BYTE *)(v1 + 32) == 1 )
  {
    __break(0x800u);
    return result;
  }
  v3 = *(_DWORD *)(v1 + 48);
  v4 = *(unsigned int *)(v1 + 80);
  v5 = (_QWORD *)result;
  v6 = *(__int64 **)(result + 5264);
  v7 = v3;
  while ( v6 == (__int64 *)v1 )
  {
LABEL_4:
    v6 = (__int64 *)*v6;
    if ( v6 == v2 )
      goto LABEL_16;
  }
  if ( v6[2] == *(_QWORD *)(v1 + 16) && v6[3] == *(_QWORD *)(v1 + 24) )
  {
    v8 = *((_DWORD *)v6 + 12);
    v9 = *((_DWORD *)v6 + 20);
    if ( v8 <= (unsigned int)v7 )
      v7 = (unsigned int)v7;
    else
      v7 = v8;
    if ( v8 < v3 )
      v3 = *((_DWORD *)v6 + 12);
    if ( v9 <= (unsigned int)v4 )
      v4 = (unsigned int)v4;
    else
      v4 = v9;
    goto LABEL_4;
  }
LABEL_16:
  if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 472LL) )
  {
    result = drv_remain_on_channel(result, *(_QWORD *)(v1 + 16), *(_QWORD *)(v1 + 24), v7, v4);
    if ( (_DWORD)result )
    {
      dev_warn(v5[9] + 392LL, "failed to start next HW ROC (%d)\n", result);
      for ( i = (__int64 *)v5[658]; i != v2; i = (__int64 *)*i )
      {
        if ( i[2] != *(_QWORD *)(v1 + 16) )
          break;
        if ( i[3] != *(_QWORD *)(v1 + 24) )
          break;
        *((_WORD *)i + 16) = 257;
      }
      return wiphy_work_queue(v5[9], v5 + 663);
    }
    else
    {
      for ( j = (__int64 *)*v2; j != v2; j = (__int64 *)*j )
      {
        if ( j[2] != *(_QWORD *)(v1 + 16) )
          break;
        if ( j[3] != *(_QWORD *)(v1 + 24) )
          break;
        *((_BYTE *)j + 32) = 1;
      }
    }
  }
  else
  {
    v11 = *(_QWORD *)(v1 + 24) == *(_QWORD *)(result + 24) && (unsigned int)(*(_DWORD *)(result + 32) - 8) < 0xFFFFFFFE;
    *(_BYTE *)(v1 + 36) = v11;
    ieee80211_recalc_idle(result);
    if ( (*(_BYTE *)(v1 + 36) & 1) == 0 )
    {
      ieee80211_offchannel_stop_vifs((__int64)v5);
      v5[622] = *(_QWORD *)(v1 + 24);
      ieee80211_hw_conf_chan((__int64)v5);
    }
    v12 = v5[9];
    v13 = _msecs_to_jiffies(v3);
    result = wiphy_delayed_work_queue(v12, v5 + 649, v13);
    for ( k = (__int64 *)v5[658]; k != v2; k = (__int64 *)*k )
    {
      if ( k[2] != *(_QWORD *)(v1 + 16) )
        break;
      if ( k[3] != *(_QWORD *)(v1 + 24) )
        break;
      *((_BYTE *)k + 36) = *(_BYTE *)(v1 + 36);
      result = ieee80211_handle_roc_started(k, jiffies);
    }
  }
  return result;
}
