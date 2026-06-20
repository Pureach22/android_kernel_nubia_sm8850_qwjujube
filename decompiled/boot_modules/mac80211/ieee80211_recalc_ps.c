__int64 __fastcall ieee80211_recalc_ps(__int64 result, __int64 a2)
{
  __int64 *v2; // x8
  __int64 *v3; // x19
  int v4; // w10
  int v5; // w11
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x22
  int v9; // w8
  unsigned int v10; // w9
  char v11; // w8
  int v12; // w8
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 v16; // x1
  int v17; // w9
  int v18; // w8

  if ( (*(_QWORD *)(result + 96) & 0x100) == 0 || (*(_QWORD *)(result + 96) & 0x400) != 0 )
  {
    *(_QWORD *)(result + 5008) = 0;
    return result;
  }
  v2 = *(__int64 **)(result + 4616);
  if ( v2 == (__int64 *)(result + 4616) )
    goto LABEL_32;
  v3 = nullptr;
  v4 = 0;
  do
  {
    if ( (v2[204] & 1) != 0 )
    {
      v5 = *((_DWORD *)v2 + 1180);
      if ( v5 == 2 )
      {
        ++v4;
        v3 = v2;
      }
      else if ( v5 == 3 )
      {
        goto LABEL_32;
      }
    }
    v2 = (__int64 *)*v2;
  }
  while ( v2 != (__int64 *)(result + 4616) );
  if ( v4 != 1
    || *((_BYTE *)v3 + 2496) != 1
    || (*((_BYTE *)v3 + 2497) & 1) != 0
    || (*((_BYTE *)v3 + 2477) & 8) == 0
    || (*((_BYTE *)v3 + 2500) & 2) != 0
    || (*(_BYTE *)(*(_QWORD *)(v3[202] + 72) + 100LL) & 2) == 0 && *((_BYTE *)v3 + 4179) != 1 )
  {
    goto LABEL_32;
  }
  v6 = result;
  _rcu_read_lock(result, a2);
  v7 = sta_info_get(v3, (char *)v3 + 4802);
  if ( !v7 )
  {
    _rcu_read_unlock(0);
    result = v6;
    goto LABEL_32;
  }
  v8 = *(_QWORD *)(v7 + 216);
  _rcu_read_unlock(v7);
  result = v6;
  if ( (v8 & 8) == 0 )
  {
LABEL_32:
    *(_QWORD *)(result + 5008) = 0;
LABEL_33:
    if ( (*(_DWORD *)result & 2) != 0 )
    {
      v15 = result;
      *(_DWORD *)result &= ~2u;
      ieee80211_hw_config(result, 16);
      timer_delete_sync(v15 + 5064);
      return wiphy_work_cancel(*(_QWORD *)(v15 + 72), v15 + 5016);
    }
    return result;
  }
  v9 = *(_DWORD *)(v6 + 5152);
  v10 = *((unsigned __int8 *)v3 + 4158);
  *(_QWORD *)(v6 + 5008) = v3;
  if ( v9 < 0 )
    v9 = 100;
  *(_DWORD *)(v6 + 8) = v9;
  if ( v10 <= 1 )
    v11 = 1;
  else
    v11 = v10;
  *(_BYTE *)(v6 + 14) = v11;
  if ( !v3 )
    goto LABEL_33;
  if ( !*(_QWORD *)(v6 + 4696) )
  {
    v12 = *(_DWORD *)(v6 + 8);
    if ( v12 < 1 || (*(_QWORD *)(v6 + 96) & 0x400) != 0 )
    {
      if ( (*(_QWORD *)(v6 + 96) & 0x200) != 0 )
      {
        v16 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, bool))ieee80211_nullfunc_get)(
                v6,
                v3 + 590,
                0xFFFFFFFFLL,
                (*(_QWORD *)(v6 + 96) & 0x10000000000LL) == 0);
        result = v6;
        if ( v16 )
        {
          **(_WORD **)(v16 + 224) |= 0x1000u;
          v17 = *(_DWORD *)(v16 + 40);
          v18 = v17 | 0x12000;
          *(_DWORD *)(v16 + 40) = v17 | 0x12000;
          if ( (*(_QWORD *)(v6 + 96) & 0x10000) != 0 )
          {
            v18 = v17 | 0x12001;
            *(_DWORD *)(v16 + 40) = v17 | 0x12001;
          }
          if ( (*((_BYTE *)v3 + 2500) & 2) != 0 )
            *(_DWORD *)(v16 + 40) = v18 | 0x20000000;
          ieee80211_tx_skb_tid(v3, v16, 7, 0xFFFFFFFFLL);
          result = v6;
        }
      }
      if ( (*(_QWORD *)(result + 96) & 0x200) == 0 || (*(_QWORD *)(result + 96) & 0x10000) == 0 )
      {
        *(_DWORD *)result |= 2u;
        return ieee80211_hw_config(result, 16);
      }
    }
    else
    {
      v13 = jiffies;
      v14 = _msecs_to_jiffies((unsigned int)v12);
      return mod_timer(v6 + 5064, v14 + v13);
    }
  }
  return result;
}
