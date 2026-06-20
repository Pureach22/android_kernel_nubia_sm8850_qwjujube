__int64 __fastcall cfg80211_dfs_channels_update_work(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x25
  unsigned __int64 v4; // x21
  int *v5; // x28
  __int64 v6; // x26
  __int64 i; // x20
  __int64 v8; // x9
  __int64 v9; // x24
  __int64 v10; // x22
  int v11; // w8
  unsigned int v12; // w23
  __int64 v13; // x0
  __int64 v14; // x24
  __int64 v15; // x27
  __int64 result; // x0
  __int64 v17; // [xsp+8h] [xbp-38h]
  char v18; // [xsp+14h] [xbp-2Ch]
  _QWORD v19[5]; // [xsp+18h] [xbp-28h] BYREF

  v17 = a1 - 368;
  v19[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v19, 0, 32);
  v2 = rtnl_lock(a1);
  v3 = 0;
  v4 = 0;
  v18 = 0;
  do
  {
    v5 = *(int **)(a1 + 952 + 8 * v3);
    if ( v5 && v5[5] >= 1 )
    {
      v6 = 0;
      for ( i = 0; i < v5[5]; ++i )
      {
        v9 = *(_QWORD *)v5;
        v10 = *(_QWORD *)v5 + v6;
        if ( (*(_BYTE *)(v10 + 12) & 8) != 0 )
        {
          v11 = *(_DWORD *)(v10 + 44);
          if ( (unsigned int)(v11 - 1) <= 1 )
          {
            if ( v11 == 1 )
            {
              v12 = 3;
              v13 = 1800000;
              goto LABEL_18;
            }
            v2 = regulatory_pre_cac_allowed(a1 + 624);
            if ( (v2 & 1) == 0 )
            {
              v2 = cfg80211_any_wiphy_oper_chan(a1 + 624, v10);
              if ( (v2 & 1) == 0 )
              {
                v12 = 4;
                v13 = 2000;
LABEL_18:
                v14 = v9 + v6;
                v15 = *(_QWORD *)(v14 + 48);
                v2 = _msecs_to_jiffies(v13);
                if ( jiffies - (v2 + v15) < 0 )
                {
                  if ( v4 >= v2 + v15 - jiffies )
                    v8 = v2 + v15 - jiffies;
                  else
                    v8 = v4;
                  if ( (v18 & 1) != 0 )
                    v4 = v8;
                  else
                    v4 = v2 + v15 - jiffies;
                  v18 = 1;
                }
                else
                {
                  *(_DWORD *)(v10 + 44) = 0;
                  *(_QWORD *)(v14 + 48) = jiffies;
                  cfg80211_chandef_create((__int64)v19, v10, 0);
                  ((void (__fastcall *)(__int64, _QWORD *, _QWORD, _QWORD, __int64))nl80211_radar_notify)(
                    v17,
                    v19,
                    v12,
                    0,
                    2080);
                  v2 = regulatory_propagate_dfs_state(a1 + 624, v19, *(unsigned int *)(v10 + 44), v12);
                }
              }
            }
          }
        }
        v6 += 64;
      }
    }
    ++v3;
  }
  while ( v3 != 6 );
  result = rtnl_unlock(v2);
  if ( (v18 & 1) != 0 )
    result = queue_delayed_work_on(32, cfg80211_wq, a1, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
