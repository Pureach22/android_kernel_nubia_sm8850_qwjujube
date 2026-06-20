__int64 __fastcall nl80211_notify_radar_detection(__int64 a1, _QWORD *a2)
{
  _QWORD *v3; // x19
  __int64 v4; // x22
  __int64 v5; // x21
  unsigned int v6; // w0
  const char *v7; // x19
  unsigned int v8; // w21
  const char **v9; // x20
  __int64 result; // x0
  const char *v11; // x19
  const char **v12; // x20
  __int64 v13; // x9
  __int64 v14; // x1
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 v17; // [xsp+8h] [xbp-28h] BYREF
  __int64 v18; // [xsp+10h] [xbp-20h]
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)a2[6];
  v4 = *(_QWORD *)(a2[7] + 992LL);
  v5 = *(_QWORD *)v4;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  if ( (unsigned int)reg_get_dfs_region(v5) )
  {
    v6 = nl80211_parse_chandef((__int64)v3, (__int64)a2, 0, (__int64)&v17);
    if ( v6 )
    {
      v7 = "Unable to extract chandef info";
LABEL_4:
      v8 = v6;
      v9 = (const char **)a2[8];
      do_trace_netlink_extack(v7);
      if ( v9 )
        *v9 = v7;
      result = v8;
      goto LABEL_17;
    }
    v6 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))cfg80211_chandef_dfs_required)(
           v5,
           &v17,
           *(unsigned int *)(v4 + 8));
    if ( (v6 & 0x80000000) != 0 )
    {
      v7 = "chandef is invalid";
      goto LABEL_4;
    }
    if ( v6 )
    {
      if ( *(_DWORD *)(v17 + 44) != 1 )
      {
        cfg80211_set_dfs_state(v5, (__int64)&v17, 1);
        cfg80211_sched_dfs_chan_update((__int64)v3);
        v13 = v18;
        v14 = cfg80211_wq;
        v3[94] = v17;
        v15 = v19;
        v16 = v20;
        v3[95] = v13;
        v3[96] = v15;
        v3[97] = v16;
        queue_work_on(32, v14, v3 + 98);
      }
      result = 0;
      goto LABEL_17;
    }
    v11 = "Unexpected Radar indication for chandef/iftype";
  }
  else
  {
    v11 = "DFS Region is not set. Unexpected Radar indication";
  }
  v12 = (const char **)a2[8];
  do_trace_netlink_extack(v11);
  if ( v12 )
    *v12 = v11;
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
