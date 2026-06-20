_DWORD *__fastcall _cfg80211_disconnected(_DWORD *result, __int64 a2, unsigned int a3, __int16 a4, char a5)
{
  __int64 v5; // x21
  __int64 *v6; // x22
  __int64 *v7; // x19
  __int64 v8; // x20
  int v9; // w8
  unsigned int v13; // w8
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x28
  unsigned __int64 v17; // x23
  __int64 v18; // x9
  __int64 v19; // x8
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v26; // w8
  unsigned int v27; // w8
  char v28; // w8
  __int64 v29; // x0
  void (__fastcall *v30)(__int64, __int64 *); // x8
  __int64 v31; // x8
  unsigned int v32; // w23
  char v33; // w8
  int v34; // w24
  _DWORD *v35; // x8
  _DWORD *v36; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v38; // x0
  __int64 v39; // x1
  __int64 v40; // x2
  __int64 v41; // x8
  unsigned int v48; // w8
  unsigned int v49; // w8
  unsigned int v52; // w8
  unsigned int v53; // w8

  v7 = *((__int64 **)result + 124);
  v8 = *v7;
  if ( !*v7 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v38 = _traceiter_rdev_set_qos_map(0, 0, v5, 0);
      v41 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v41;
      if ( !v41 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v38, v39, v40);
    }
LABEL_44:
    v36 = *(_DWORD **)(*v6 + 736);
    if ( *(v36 - 1) != -824243271 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v36)(v8, v5, 0);
LABEL_47:
    queue_work_on(32, system_wq, &cfg80211_disconnect_work);
    return cfg80211_schedule_channels_check(v7);
  }
  v9 = *((_DWORD *)v7 + 2);
  v5 = (__int64)result;
  if ( v9 == 2 || v9 == 8 )
  {
    v13 = *((unsigned __int16 *)v7 + 736);
    v6 = (__int64 *)(v8 - 992);
    if ( *((_WORD *)v7 + 736) && (v13 & 1) == 0 || (v14 = v7[50]) == 0 )
    {
LABEL_11:
      if ( v13 )
      {
        v16 = 59;
        v17 = 1;
        while ( 1 )
        {
          if ( ((v13 >> v17) & 1) == 0 )
            goto LABEL_19;
          v18 = v7[v16];
          if ( !v18 )
            goto LABEL_19;
          _X10 = (unsigned int *)(v18 + 80);
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v22 = __ldxr(_X10);
            v23 = v22 - 1;
          }
          while ( __stlxr(v23, _X10) );
          __dmb(0xBu);
          if ( (v23 & 0x80000000) != 0 )
          {
            __break(0x800u);
            v19 = *(_QWORD *)(v18 + 152);
            if ( v19 )
            {
LABEL_17:
              _X9 = (unsigned int *)(v19 - 32);
              __asm { PRFM            #0x11, [X9] }
              do
              {
                v26 = __ldxr(_X9);
                v27 = v26 - 1;
              }
              while ( __stlxr(v27, _X9) );
              __dmb(0xBu);
              if ( (v27 & 0x80000000) != 0 )
                __break(0x800u);
            }
          }
          else
          {
            v19 = *(_QWORD *)(v18 + 152);
            if ( v19 )
              goto LABEL_17;
          }
          cfg80211_put_bss(*v7, (_QWORD *)(v7[v16] + 112));
          v7[v16] = 0;
          v13 = *((unsigned __int16 *)v7 + 736);
LABEL_19:
          if ( v13 )
          {
            _CF = v17++ >= 0xE;
            v16 += 9;
            if ( !_CF )
              continue;
          }
          break;
        }
      }
      v28 = *((_BYTE *)v7 + 164);
      v29 = v7[11];
      *((_WORD *)v7 + 736) = 0;
      *((_BYTE *)v7 + 318) = 0;
      *((_DWORD *)v7 + 25) = 0;
      *((_BYTE *)v7 + 164) = v28 & 0xFE;
      kfree_sensitive(v29);
      v7[11] = 0;
      nl80211_send_disconnected(v8 - 992, v5, a4, a2, a3, a5 & 1);
      if ( *(_QWORD *)(*v6 + 712) && *(_DWORD *)(v8 - 344) )
      {
        *(_DWORD *)(v8 - 344) = 0;
        v30 = *(void (__fastcall **)(__int64, __int64 *))(*v6 + 712);
        if ( *((_DWORD *)v30 - 1) != 1366774891 )
          __break(0x8228u);
        v30(v8, v7);
      }
      v31 = *v6;
      if ( *(_QWORD *)(*v6 + 80) )
      {
        v32 = 0;
        v33 = *(_BYTE *)(*v7 + 117);
        _ReadStatusReg(SP_EL0);
        if ( (v33 & 0x42) != 0 )
          v34 = 8;
        else
          v34 = 6;
        do
        {
          v35 = *(_DWORD **)(*v6 + 80);
          if ( *(v35 - 1) != 1549052562 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v35)(
            v8,
            v5,
            0xFFFFFFFFLL,
            v32++,
            0,
            0);
        }
        while ( v34 != v32 );
        v31 = *v6;
      }
      if ( !*(_QWORD *)(v31 + 736) )
        goto LABEL_47;
      goto LABEL_44;
    }
    _X10 = (unsigned int *)(v14 + 80);
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v48 = __ldxr(_X10);
      v49 = v48 - 1;
    }
    while ( __stlxr(v49, _X10) );
    __dmb(0xBu);
    if ( (v49 & 0x80000000) != 0 )
    {
      __break(0x800u);
      v15 = *(_QWORD *)(v14 + 152);
      if ( !v15 )
        goto LABEL_10;
    }
    else
    {
      v15 = *(_QWORD *)(v14 + 152);
      if ( !v15 )
      {
LABEL_10:
        cfg80211_put_bss(*v7, (_QWORD *)(v7[50] + 112));
        v13 = *((unsigned __int16 *)v7 + 736);
        v7[50] = 0;
        goto LABEL_11;
      }
    }
    _X9 = (unsigned int *)(v15 - 32);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v52 = __ldxr(_X9);
      v53 = v52 - 1;
    }
    while ( __stlxr(v53, _X9) );
    __dmb(0xBu);
    if ( (v53 & 0x80000000) != 0 )
      __break(0x800u);
    goto LABEL_10;
  }
  __break(0x800u);
  return result;
}
