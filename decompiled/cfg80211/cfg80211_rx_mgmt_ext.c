__int64 __fastcall cfg80211_rx_mgmt_ext(__int64 *a1, __int64 a2)
{
  __int64 *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  unsigned __int16 *v6; // x24
  __int16 v7; // w25
  __int64 v8; // x23
  __int64 v9; // x22
  __int64 v10; // x21
  unsigned int v11; // w24
  int v12; // w28
  __int64 *v13; // x27
  const void *v14; // x22
  __int64 v15; // x23
  int v16; // w25
  int v17; // w24
  size_t v18; // x2
  unsigned int v19; // w19
  unsigned __int64 StatusReg; // x26
  __int64 v22; // x0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x8

  v8 = *a1;
  if ( *a1 )
  {
    v6 = *(unsigned __int16 **)(a2 + 16);
    v4 = *(_QWORD *)(v8 + 72);
    v2 = a1;
    v5 = *((unsigned int *)a1 + 2);
    v3 = a2;
    v7 = *v6;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v22 = _traceiter_cfg80211_rx_mgmt(0, v2, v3);
      v25 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v25;
      if ( !v25 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v22, v23, v24);
    }
  }
  if ( (((unsigned __int64)*(unsigned __int16 *)(v4 + 4 * v5 + 2) >> ((unsigned __int8)*v6 >> 4)) & 1) != 0 )
  {
    v9 = *(_QWORD *)(v3 + 16);
    v10 = v8 - 80;
    v11 = ieee80211_hdrlen(*v6);
    v12 = *(_DWORD *)(v3 + 24);
    raw_spin_lock_bh(v8 - 80);
    v13 = (__int64 *)v2[6];
    if ( v13 == v2 + 6 )
    {
LABEL_12:
      v19 = 0;
    }
    else
    {
      v14 = (const void *)(v9 + v11);
      v15 = v8 - 992;
      v16 = v7 & 0xFC;
      v17 = v12 - v11;
      while ( 1 )
      {
        if ( *((unsigned __int16 *)v13 + 16) == v16 )
        {
          v18 = *((int *)v13 + 7);
          if ( (int)v18 <= v17
            && !bcmp((char *)v13 + 35, v14, v18)
            && !(unsigned int)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, __int64, __int64))nl80211_send_mgmt)(
                                v15,
                                v2,
                                *((unsigned int *)v13 + 6),
                                v3,
                                2080) )
          {
            break;
          }
        }
        v13 = (__int64 *)*v13;
        if ( v13 == v2 + 6 )
          goto LABEL_12;
      }
      v19 = 1;
    }
    raw_spin_unlock_bh(v10);
  }
  else
  {
    return 0;
  }
  return v19;
}
