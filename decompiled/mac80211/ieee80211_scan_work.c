__int64 __fastcall ieee80211_scan_work(__int64 result, __int64 a2)
{
  char v2; // w8
  __int64 v3; // x8
  __int64 v4; // x20
  unsigned __int64 v5; // x19
  __int64 v6; // x24
  _QWORD *v7; // x28
  __int64 v9; // x2
  __int64 v10; // x23
  __int64 v11; // x21
  __int16 v12; // w8
  int v13; // w0
  unsigned int v14; // w9
  _QWORD *v15; // x21
  char v16; // w8
  __int64 v17; // x27
  __int64 lock; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  bool v21; // w23
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x8
  __int64 v25; // x9
  int v26; // w8
  __int64 v27; // x9
  __int64 v28; // x10
  unsigned __int64 v30; // x9
  int v31; // w8
  unsigned __int64 v32; // x0
  unsigned __int64 v39; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v47; // x10
  unsigned __int64 v49; // x8
  _QWORD *v50; // [xsp+0h] [xbp-20h]
  _QWORD *v51; // [xsp+8h] [xbp-18h]
  _QWORD v52[2]; // [xsp+10h] [xbp-10h] BYREF

  v52[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a2 - 3426);
  v52[0] = 0;
  if ( (v2 & 1) != 0 || (*(_BYTE *)(a2 - 3428) & 1) != 0 || (*(_BYTE *)(a2 - 3431) & 1) != 0 )
  {
LABEL_4:
    LODWORD(v3) = 1;
    goto LABEL_5;
  }
  v4 = *(_QWORD *)(a2 + 72);
  v5 = *(_QWORD *)(a2 - 144);
  if ( (*(_QWORD *)(a2 - 200) & 4) != 0 )
  {
    _X9 = (unsigned __int64 *)(a2 - 200);
    __asm { PRFM            #0x11, [X9] }
    do
      v42 = __ldxr(_X9);
    while ( __stlxr(v42 & 0xFFFFFFFFFFFFFFEFLL, _X9) );
LABEL_87:
    __dmb(0xBu);
    v3 = (v42 >> 4) & 1;
LABEL_5:
    result = _ieee80211_scan_completed(a2 - 4896, (unsigned int)v3);
    goto LABEL_6;
  }
  _X9 = (unsigned __int64 *)(a2 - 200);
  __asm { PRFM            #0x11, [X9] }
  do
    v39 = __ldxr(_X9);
  while ( __stlxr(v39 & 0xFFFFFFFFFFFFFFF7LL, _X9) );
  __dmb(0xBu);
  if ( (v39 & 8) != 0 )
  {
    _X9 = (unsigned __int64 *)(a2 - 200);
    __asm { PRFM            #0x11, [X9] }
    do
      v42 = __ldxr(_X9);
    while ( __stlxr(v42 & 0xFFFFFFFFFFFFFFEFLL, _X9) );
    goto LABEL_87;
  }
  if ( !v4 || !v5 )
    goto LABEL_6;
  v6 = a2;
  if ( !*(_QWORD *)(a2 - 200) )
  {
    *(_QWORD *)(a2 - 144) = 0;
    *(_QWORD *)(a2 + 72) = 0;
    result = _ieee80211_start_scan(v4, v5);
    if ( (_DWORD)result )
    {
      atomic_store(v5, (unsigned __int64 *)(v6 - 144));
      a2 = v6;
      LODWORD(v3) = 1;
      goto LABEL_5;
    }
    goto LABEL_6;
  }
  _X8 = (unsigned __int64 *)(a2 - 200);
  __asm { PRFM            #0x11, [X8] }
  do
    v47 = __ldxr(_X8);
  while ( __stxr(v47 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
  v7 = (_QWORD *)(a2 - 280);
  _X25 = (unsigned __int64 *)(a2 - 200);
  v50 = (_QWORD *)(a2 - 128);
  v51 = (_QWORD *)(a2 - 4872);
LABEL_16:
  if ( (*(_QWORD *)(v4 + 1632) & 1) == 0 )
    goto LABEL_4;
  __asm { PRFM            #0x11, [X25] }
  do
    v30 = __ldxr(_X25);
  while ( __stlxr(v30 & 0xFFFFFFFFFFFFFF7FLL, _X25) );
  __dmb(0xBu);
  v31 = *(_DWORD *)(a2 - 8);
  if ( (v30 & 0x80) != 0 && !v31 )
  {
    *(_DWORD *)(a2 - 8) = 2;
    goto LABEL_14;
  }
  v9 = 0;
  if ( v31 > 1 )
  {
    if ( v31 > 3 )
    {
      if ( v31 == 4 )
      {
        result = ieee80211_offchannel_stop_vifs(a2 - 4896);
        a2 = v6;
        if ( *(_QWORD *)(*(_QWORD *)(v6 - 4432) + 432LL) )
        {
          result = ieee80211_flush_queues(v6 - 4896, 0, 0);
          a2 = v6;
          v9 = 0;
        }
        else
        {
          v9 = 25;
        }
        v52[0] = v9;
        v24 = jiffies;
        *(_DWORD *)(a2 - 8) = 1;
        *(_QWORD *)(a2 - 16) = v24;
        goto LABEL_15;
      }
      if ( v31 != 5 )
        goto LABEL_15;
      goto LABEL_4;
    }
    if ( v31 != 2 )
    {
      *(_QWORD *)(a2 - 128) = 0;
      ieee80211_hw_conf_chan(a2 - 4896);
      ieee80211_offchannel_return(v6 - 4896);
      a2 = v6;
      v9 = 50;
      *(_DWORD *)(v6 - 8) = 4;
      goto LABEL_82;
    }
LABEL_14:
    result = ieee80211_scan_state_send_probe(a2 - 4896, v52);
    v9 = v52[0];
    a2 = v6;
    goto LABEL_15;
  }
  if ( !v31 )
  {
    v14 = *(_DWORD *)(a2 - 92);
    if ( v14 >= *(_DWORD *)(v5 + 12) )
    {
      LODWORD(v3) = 0;
      goto LABEL_5;
    }
    v15 = (_QWORD *)*v7;
    if ( (_QWORD *)*v7 == v7 )
    {
      v16 = 0;
      goto LABEL_53;
    }
    v16 = 0;
    while ( 1 )
    {
      if ( (v15[204] & 1) != 0 && *((_DWORD *)v15 + 1180) == 2 && (*((_BYTE *)v15 + 2477) & 8) != 0 )
      {
        v17 = v15[201];
        lock = _rcu_read_lock(result, a2);
        v19 = *(unsigned int *)(v17 + 1096);
        if ( (_DWORD)v19 )
        {
          v20 = 0;
          v21 = 0;
          v22 = *(_QWORD *)(v17 + 24) + 8LL;
          while ( 1 )
          {
            v23 = *(_QWORD *)v22;
            if ( (*(_BYTE *)(*(_QWORD *)v22 + 16LL) & 0x20) != 0 )
            {
              if ( (*(_QWORD *)(v23 + 216) & 0xCLL) != 0 )
              {
LABEL_33:
                result = _rcu_read_unlock(lock);
                if ( v21 )
                  goto LABEL_34;
                a2 = v6;
                if ( (*(_BYTE *)(*(_QWORD *)(v6 - 144) + 36LL) & 1) != 0 )
                  v26 = 5;
                else
                  v26 = 3;
LABEL_58:
                v9 = 0;
                *(_DWORD *)(a2 - 8) = v26;
                v52[0] = 0;
LABEL_15:
                if ( v9 )
                  goto LABEL_82;
                goto LABEL_16;
              }
            }
            else if ( *(_DWORD *)(v23 + 168) )
            {
              goto LABEL_33;
            }
            ++v20;
            v22 += 384;
            v21 = v20 >= v19;
            if ( v19 == v20 )
              goto LABEL_33;
          }
        }
        result = _rcu_read_unlock(lock);
LABEL_34:
        v16 = 1;
        a2 = v6;
      }
      v15 = (_QWORD *)*v15;
      if ( v15 == v7 )
      {
        v14 = *(_DWORD *)(a2 - 92);
LABEL_53:
        _ZF = (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a2 - 144) + 8LL * (int)v14 + 160) + 12LL) & 0xA) == 0;
        v25 = -27;
        if ( _ZF )
          v25 = -14;
        if ( ((unsigned __int8)v16 & (*(_QWORD *)(a2 - 16) - jiffies + v25 + 31 < 0)) != 0 )
          v26 = 3;
        else
          v26 = 1;
        goto LABEL_58;
      }
    }
  }
  if ( v31 != 1 )
    goto LABEL_15;
  v10 = *(_QWORD *)(a2 - 144);
  v11 = *(_QWORD *)(v10 + 8LL * *(int *)(a2 - 92) + 160);
  *(_QWORD *)(a2 - 128) = v11;
  *(_DWORD *)(a2 - 116) = *(_DWORD *)(v11 + 4);
  v12 = *(_WORD *)(v11 + 8);
  *(_DWORD *)(a2 - 112) = 0;
  *(_WORD *)(a2 - 100) = v12;
  if ( *(_DWORD *)v11 == 4 )
  {
    v13 = ieee80211_s1g_channel_width(v11);
    a2 = v6;
    *(_DWORD *)(v6 - 120) = v13;
  }
  else if ( v11 == *v51 )
  {
    v27 = v51[1];
    *v50 = *v51;
    v50[1] = v27;
    v28 = v51[3];
    v50[2] = v51[2];
    v50[3] = v28;
  }
  else
  {
    *(_DWORD *)(a2 - 120) = 0;
  }
  result = ieee80211_hw_conf_chan(a2 - 4896);
  a2 = v6;
  ++*(_DWORD *)(v6 - 92);
  if ( (_DWORD)result )
  {
    v9 = 0;
    *(_DWORD *)(v6 - 8) = 0;
    goto LABEL_15;
  }
  if ( (*(_BYTE *)(v11 + 12) & 0xA) != 0 || !*(_DWORD *)(v10 + 8) )
  {
    v32 = _msecs_to_jiffies(*(unsigned __int16 *)(v10 + 32));
    *(_DWORD *)(v6 - 8) = 0;
    a2 = v6;
    if ( v32 <= 0x1B )
      v9 = 27;
    else
      v9 = v32;
    if ( *(_DWORD *)(v10 + 8) )
    {
      __asm { PRFM            #0x11, [X25] }
      do
        v49 = __ldxr(_X25);
      while ( __stxr(v49 | 0x40, _X25) );
    }
  }
  else
  {
    v9 = 7;
    *(_DWORD *)(v6 - 8) = 2;
  }
LABEL_82:
  result = wiphy_delayed_work_queue(*(_QWORD *)(a2 - 4824), a2, v9);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
