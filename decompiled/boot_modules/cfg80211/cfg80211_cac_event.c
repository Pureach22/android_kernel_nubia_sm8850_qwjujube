__int64 __fastcall cfg80211_cac_event(__int64 result, _QWORD *a2, __int64 a3, unsigned int a4, __int64 a5)
{
  unsigned int v5; // w19
  __int64 v6; // x20
  __int64 v7; // x22
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x24
  __int64 v11; // x23
  _QWORD *v12; // x22
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  char v16; // w8
  unsigned __int64 StatusReg; // x23
  _QWORD *v18; // x24
  __int64 v19; // x25
  __int64 v20; // x8
  unsigned int v21; // [xsp+Ch] [xbp-4h]

  v7 = *(_QWORD *)(result + 992);
  v8 = *(_QWORD *)v7;
  if ( !*(_QWORD *)v7 )
    goto LABEL_18;
  v5 = a4;
  v6 = result;
  if ( *(_WORD *)(v7 + 1472) && ((1LL << a5) & *(unsigned __int16 *)(v7 + 1472)) == 0 )
    goto LABEL_16;
  while ( (unsigned int)a5 >= 0xF )
  {
    __break(0x5512u);
LABEL_18:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v18 = a2;
      v19 = a5;
      ++*(_DWORD *)(StatusReg + 16);
      v21 = a3;
      result = _traceiter_cfg80211_cac_event(0, v6, (unsigned int)a3, (unsigned int)a5);
      a3 = v21;
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || (a5 = v19, a2 = v18, !*(_QWORD *)(StatusReg + 16)) )
      {
        result = preempt_schedule_notrace(result, a2, v21);
        a3 = v21;
        a5 = v19;
        a2 = v18;
      }
    }
  }
  v9 = v7 + 72LL * (unsigned int)a5;
  if ( (_DWORD)a3 != 5 && (*(_BYTE *)(v9 + 440) & 1) == 0 )
    goto LABEL_16;
  v10 = v9 + 392;
  switch ( (_DWORD)a3 )
  {
    case 5:
      v16 = 1;
      goto LABEL_15;
    case 2:
      v16 = 0;
LABEL_15:
      *(_BYTE *)(v10 + 48) = v16;
      return ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, _QWORD))nl80211_radar_notify)(
               v8 - 992,
               a2,
               a3,
               v6,
               v5);
    case 1:
      v11 = *(_QWORD *)(v9 + 448);
      v12 = a2;
      if ( jiffies - v11 - _msecs_to_jiffies(*(unsigned int *)(v9 + 456)) < 0 )
        __break(0x800u);
      cfg80211_set_dfs_state(v8, (__int64)v12, 2);
      v13 = v12[3];
      v14 = *v12;
      v15 = v12[1];
      *(_QWORD *)(v8 - 160) = v12[2];
      *(_QWORD *)(v8 - 152) = v13;
      *(_QWORD *)(v8 - 176) = v14;
      *(_QWORD *)(v8 - 168) = v15;
      queue_work_on(32, cfg80211_wq, v8 - 144);
      cancel_delayed_work(v8 - 624);
      queue_delayed_work_on(32, cfg80211_wq, v8 - 624, 0);
      a2 = v12;
      v16 = 0;
      a3 = 1;
      goto LABEL_15;
  }
LABEL_16:
  __break(0x800u);
  return result;
}
