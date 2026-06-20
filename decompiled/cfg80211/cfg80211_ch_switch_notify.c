__int64 __usercall cfg80211_ch_switch_notify@<X0>(
        __int64 updated@<X0>,
        _QWORD *a2@<X1>,
        unsigned int a3@<W2>,
        __int64 a4@<X8>)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  _QWORD *v6; // x21
  __int64 *v7; // x22
  __int64 v8; // x23
  __int64 v9; // x8
  int v10; // w9
  __int64 v11; // x11
  __int64 v12; // x12
  __int64 *v13; // x8
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x8
  __int64 v22; // x10
  __int64 v23; // x11
  unsigned __int64 StatusReg; // x24
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x9
  __int64 v29; // [xsp+8h] [xbp-8h]

  v7 = *(__int64 **)(updated + 992);
  v8 = *v7;
  if ( !*v7 )
    goto LABEL_32;
  v4 = a3;
  v5 = updated;
  v6 = a2;
  if ( a3 && !*((_WORD *)v7 + 736) )
  {
    __break(0x800u);
    v9 = *((unsigned __int16 *)v7 + 736);
    if ( *((_WORD *)v7 + 736) )
    {
LABEL_5:
      if ( ((1LL << a3) & v9) == 0 )
        __break(0x800u);
    }
  }
  else
  {
    v9 = *((unsigned __int16 *)v7 + 736);
    if ( *((_WORD *)v7 + 736) )
      goto LABEL_5;
  }
  a4 = a3;
  while ( 1 )
  {
    v10 = *((_DWORD *)v7 + 2);
    if ( v10 > 6 )
      break;
    if ( v10 == 1 )
    {
      v15 = v6[3];
      v16 = *v6;
      v17 = v6[1];
      v7[38] = v6[2];
      v7[39] = v15;
      v7[36] = v16;
      v7[37] = v17;
      goto LABEL_27;
    }
    if ( v10 == 2 )
      goto LABEL_16;
    if ( v10 != 3 )
      goto LABEL_23;
LABEL_19:
    if ( v4 <= 0xE )
    {
      v11 = *v6;
      v12 = v6[1];
      v13 = &v7[9 * (unsigned int)a4];
      v14 = v6[3];
      v13[53] = v6[2];
      v13[54] = v14;
      v13[51] = v11;
      v13[52] = v12;
      goto LABEL_24;
    }
LABEL_31:
    __break(0x5512u);
LABEL_32:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v29 = a4;
      updated = _traceiter_cfg80211_ch_switch_notify(0, v5, v6, v4);
      a4 = v29;
      v28 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v28;
      if ( !v28 || !*(_QWORD *)(StatusReg + 16) )
      {
        updated = preempt_schedule_notrace(updated, v26, v27);
        a4 = v29;
      }
    }
  }
  if ( v10 == 7 )
  {
    v18 = v6[3];
    v19 = *v6;
    v20 = v6[1];
    v7[42] = v6[2];
    v7[43] = v18;
    v7[40] = v19;
    v7[41] = v20;
    v21 = v6[3];
    v22 = *v6;
    v23 = v6[1];
    v7[38] = v6[2];
    v7[39] = v21;
    v7[36] = v22;
    v7[37] = v23;
    goto LABEL_24;
  }
  if ( v10 == 9 )
    goto LABEL_19;
  if ( v10 != 8 )
    goto LABEL_23;
LABEL_16:
  if ( v4 >= 0xF )
    goto LABEL_31;
  if ( v7[9 * (unsigned int)a4 + 50] )
  {
    updated = cfg80211_update_assoc_bss_entry(v7, v4, *v6);
    goto LABEL_24;
  }
LABEL_23:
  __break(0x800u);
LABEL_24:
  if ( *((_DWORD *)v7 + 2) == 2 && (*(_BYTE *)(*v7 + 120) & 8) != 0 )
    reg_check_channels(updated);
LABEL_27:
  cfg80211_sched_dfs_chan_update(v8 - 992);
  return nl80211_ch_switch_notify(v8 - 992, v5, v4, v6, 88, 0, 0);
}
