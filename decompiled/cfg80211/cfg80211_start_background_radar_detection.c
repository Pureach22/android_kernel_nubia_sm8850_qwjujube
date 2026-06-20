__int64 __fastcall cfg80211_start_background_radar_detection(_QWORD *a1, __int64 a2, __int64 *a3)
{
  unsigned int v3; // w8
  __int64 v4; // x8
  _QWORD *v5; // x22
  _DWORD *v8; // x8
  _QWORD *v9; // x0
  _QWORD *v10; // x24
  unsigned int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x11
  unsigned int v16; // w20
  __int64 v17; // x3
  __int64 v18; // x19
  __int64 v19; // x0

  if ( (*((_BYTE *)a1 + 1111) & 0x10) != 0 )
  {
    v4 = a1[59];
    if ( v4 && v4 != a2 || v4 == a2 && (a1[64] & 1) != 0 )
    {
      return (unsigned int)-16;
    }
    else
    {
      v5 = a1;
      v8 = *(_DWORD **)(*a1 + 952LL);
      if ( v8 )
      {
        v9 = a1 + 124;
        if ( *(v8 - 1) != 699476211 )
          __break(0x8228u);
        v3 = ((__int64 (__fastcall *)(_QWORD *, __int64 *))v8)(v9, a3);
        a1 = v5;
      }
      else
      {
        v3 = -95;
      }
      if ( !v3 )
      {
        v10 = a1;
        v11 = cfg80211_chandef_dfs_cac_time((__int64)(a1 + 124), (__int64)a3);
        v13 = a3[2];
        v12 = a3[3];
        v15 = *a3;
        v14 = a3[1];
        v10[59] = a2;
        v10[62] = v13;
        v10[63] = v12;
        if ( v11 )
          v16 = v11;
        else
          v16 = 60000;
        v10[60] = v15;
        v10[61] = v14;
        if ( (cfg80211_chandef_valid(a3) & 1) != 0 && v5[59] )
        {
          if ( a2 )
            v17 = *(_QWORD *)(a2 + 32);
          else
            v17 = 0;
          ((void (__fastcall *)(_QWORD *, __int64 *, __int64, __int64, __int64))nl80211_radar_notify)(
            v5,
            a3,
            5,
            v17,
            3264);
        }
        v18 = cfg80211_wq;
        v19 = _msecs_to_jiffies(v16);
        queue_delayed_work_on(32, v18, v5 + 64, v19);
        return 0;
      }
    }
  }
  else
  {
    return (unsigned int)-95;
  }
  return v3;
}
