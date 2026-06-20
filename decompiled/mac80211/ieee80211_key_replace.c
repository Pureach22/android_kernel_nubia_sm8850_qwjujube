__int64 __fastcall ieee80211_key_replace(
        __int64 a1,
        unsigned __int64 *a2,
        __int64 a3,
        char a4,
        unsigned __int64 a5,
        unsigned __int64 a6)
{
  __int64 v6; // x25
  __int64 v7; // x28
  __int64 v8; // x24
  unsigned __int64 v10; // x9
  __int64 v13; // x27
  int v14; // w8
  unsigned int v15; // w2
  unsigned __int64 *v16; // x21
  int v18; // w9
  __int64 result; // x0
  __int64 v20; // x26
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x3
  unsigned __int64 v25; // x0
  __int64 v26; // x2
  unsigned __int64 *v27; // x1
  __int64 v28; // x8
  unsigned __int64 v29; // x25
  unsigned __int64 v30; // x26
  unsigned __int64 v31; // x24
  unsigned int v32; // w10
  bool v33; // w26
  char v34; // w8
  char v35; // w8
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x8
  char v38; // w8
  unsigned int v39; // w8
  unsigned __int64 v40; // x8
  char v41; // w8
  unsigned int v42; // w8
  unsigned __int64 v43; // x8
  _QWORD *v44; // x8
  __int64 *v45; // x0
  __int64 v46; // x9
  unsigned __int64 v49; // x9
  unsigned __int64 v56; // x9
  unsigned int v57; // [xsp+Ch] [xbp-4h]

  if ( a3 )
    v7 = a3 + 1640;
  else
    v7 = 0;
  if ( !(a5 | a6) )
  {
    __break(0x800u);
    return 0;
  }
  v8 = a3;
  if ( a6 )
    v10 = a6;
  else
    v10 = a5;
  v13 = *(unsigned __int8 *)(v10 + 551);
  v14 = *(_DWORD *)(v10 + 544);
  v15 = *(char *)(v10 + 554);
  v16 = a2;
  if ( a5 )
  {
    v18 = *(unsigned __int8 *)(a5 + 554);
    if ( v18 != (unsigned __int8)v15 )
    {
      _warn_printk("old link ID %d doesn't match new link ID %d\n", (char)v18, v15);
      __break(0x800u);
      return 4294967274LL;
    }
  }
  if ( (v15 & 0x80000000) != 0 )
  {
    v16 = (unsigned __int64 *)(a1 + 3616);
  }
  else
  {
    if ( !a2 )
    {
      if ( v15 >= 0xF )
        goto LABEL_128;
      v16 = *(unsigned __int64 **)(a1 + 8LL * v15 + 4568);
      if ( !v16 )
        return 4294967229LL;
    }
    if ( v8 )
    {
      if ( v15 > 0xE )
        goto LABEL_128;
      v7 = *(_QWORD *)(v8 + 8LL * v15 + 2568);
      if ( !v7 )
        return 4294967229LL;
    }
    else
    {
      v7 = 0;
    }
  }
  if ( (v14 & 0xFFFFFFFB) != 0xFAC01 )
  {
    if ( (a4 & 1) == 0 || (char)v13 <= 3 )
      goto LABEL_26;
    return 4294967274LL;
  }
  if ( (char)v13 > 3 )
    return 4294967274LL;
LABEL_26:
  if ( a5 && a6 && *(unsigned __int8 *)(a6 + 551) != *(unsigned __int8 *)(a5 + 551) )
  {
    __break(0x800u);
    v57 = v14 & 0xFFFFFFFB;
    if ( !v8 )
      goto LABEL_43;
  }
  else
  {
    v57 = v14 & 0xFFFFFFFB;
    if ( !v8 )
      goto LABEL_43;
  }
  if ( a6 && (a4 & 1) != 0 )
  {
    v20 = *(_QWORD *)a6;
    v6 = *(_QWORD *)(a6 + 16);
    if ( (*(_WORD *)(a6 + 552) & 0x200) == 0 )
    {
      if ( !a5 )
        goto LABEL_48;
      v21 = *(_DWORD *)(a5 + 40);
      if ( (v21 & 1) != 0 )
      {
        v22 = *(_QWORD *)(a6 + 16);
        *(_DWORD *)(a5 + 40) = v21 | 2;
        ieee80211_clear_fast_xmit(v22);
        if ( (*(_QWORD *)(v20 + 96) & 0x80) != 0 )
        {
          _X8 = (unsigned __int64 *)(v6 + 216);
          __asm { PRFM            #0x11, [X8] }
          do
            v56 = __ldxr(_X8);
          while ( __stxr(v56 | 0x100, _X8) );
          ieee80211_sta_tear_down_BA_sessions((_QWORD *)v6, 1u);
        }
        if ( (*(char *)(*(_QWORD *)(v20 + 72) + 115LL) & 0x80000000) == 0 )
        {
          if ( (unsigned int)__ratelimit(&ieee80211_pairwise_rekey__rs, "ieee80211_pairwise_rekey") )
            printk(&unk_B9A0B, v6 + 2688, v23, v24);
          ieee80211_flush_queues(v20, *(_QWORD *)(a5 + 8), 0);
        }
      }
      goto LABEL_44;
    }
    if ( *(_BYTE *)(v6 + 120) != 2 && (*(_QWORD *)(v20 + 96) & 0x800000000000LL) == 0 )
      goto LABEL_129;
  }
LABEL_43:
  while ( a5 )
  {
LABEL_44:
    if ( (*(_BYTE *)(a5 + 40) & 1) == 0 )
      goto LABEL_51;
    ieee80211_key_disable_hw_accel(a5);
    if ( a6 )
      goto LABEL_50;
LABEL_56:
    if ( !v8 )
      goto LABEL_72;
LABEL_57:
    if ( (a4 & 1) != 0 )
    {
      if ( (unsigned int)v13 <= 4 )
      {
        atomic_store(a6, (unsigned __int64 *)(v8 + 8 * v13 + 88));
        if ( !a6 )
          goto LABEL_120;
        if ( (*(_WORD *)(a6 + 552) & 0x200) == 0 )
          ieee80211_set_tx_key((__int64 *)a6, 1);
        goto LABEL_64;
      }
    }
    else if ( (unsigned int)v13 <= 8 )
    {
      atomic_store(a6, (unsigned __int64 *)(v7 + 8 * v13 + 40));
LABEL_64:
      if ( a5 || !a6 )
        goto LABEL_120;
      ieee80211_check_fast_rx(v8);
      return 0;
    }
LABEL_128:
    __break(0x5512u);
LABEL_129:
    _X8 = (unsigned __int64 *)(v6 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v49 = __ldxr(_X8);
    while ( __stxr(v49 | 0x100, _X8) );
    _ieee80211_stop_tx_ba_session(v6, 0, 1u);
    _ieee80211_stop_tx_ba_session(v6, 1u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 2u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 3u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 4u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 5u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 6u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 7u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 8u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 9u, 1u);
    _ieee80211_stop_tx_ba_session(v6, 0xAu, 1u);
    _ieee80211_stop_tx_ba_session(v6, 0xBu, 1u);
    _ieee80211_stop_tx_ba_session(v6, 0xCu, 1u);
    _ieee80211_stop_tx_ba_session(v6, 0xDu, 1u);
    _ieee80211_stop_tx_ba_session(v6, 0xEu, 1u);
    _ieee80211_stop_tx_ba_session(v6, 0xFu, 1u);
  }
  v20 = *(_QWORD *)a6;
LABEL_48:
  if ( (*(_BYTE *)(v20 + 1472) & 1) != 0 )
  {
    *(_DWORD *)(a6 + 40) |= 1u;
    goto LABEL_51;
  }
LABEL_50:
  result = ieee80211_key_enable_hw_accel(a6);
  if ( (_DWORD)result )
    return result;
LABEL_51:
  if ( !a6 )
    goto LABEL_56;
  v25 = a6 + 24;
  v26 = a1 + 1512;
  v27 = *(unsigned __int64 **)(a1 + 1520);
  if ( a6 + 24 != a1 + 1512 && v27 != (unsigned __int64 *)v25 && *v27 == v26 )
  {
    *(_QWORD *)(a6 + 24) = v26;
    *(_QWORD *)(a6 + 32) = v27;
    atomic_store(v25, v27);
    *(_QWORD *)(a1 + 1520) = v25;
    goto LABEL_56;
  }
  _list_add_valid_or_report(v25, v27);
  if ( v8 )
    goto LABEL_57;
LABEL_72:
  if ( a5 )
  {
    v28 = *(_QWORD *)(a1 + 1928);
    v30 = v16[14];
    v29 = v16[15];
    v31 = v16[16];
    v7 = v28 == a5;
    if ( !a6 && v28 == a5 )
      _ieee80211_set_default_key(v16, 0xFFFFFFFF, 1, 0);
    v32 = v57;
    if ( !a6 && v30 == a5 )
      atomic_store(0, v16 + 14);
    if ( !a6 && v29 == a5 )
      atomic_store(0, v16 + 15);
    v33 = v30 == a5;
    if ( a6 )
    {
      v6 = v29 == a5;
      v8 = v31 == a5;
    }
    else
    {
      v6 = v29 == a5;
      if ( v31 == a5 )
        atomic_store(0, v16 + 16);
      v8 = v31 == a5;
    }
  }
  else
  {
    v32 = v57;
    v6 = 0;
    v7 = 0;
    v33 = 0;
    v8 = 0;
  }
  if ( v32 != 1027073 && (a4 & 1) == 0 )
  {
    if ( (unsigned int)v13 <= 8 )
    {
      atomic_store(a6, &v16[v13 + 6]);
      goto LABEL_94;
    }
    goto LABEL_128;
  }
  if ( (unsigned int)v13 > 4 )
    goto LABEL_128;
  atomic_store(a6, (unsigned __int64 *)(a1 + 8 * v13 + 1896));
LABEL_94:
  v34 = v7 ^ 1;
  if ( !a6 )
    v34 = 1;
  if ( (v34 & 1) == 0 )
    _ieee80211_set_default_key(v16, *(char *)(a6 + 551), 1, 0);
  v35 = !v33;
  if ( !a6 )
    v35 = 1;
  if ( (v35 & 1) == 0 )
  {
    v36 = *(unsigned __int8 *)(a6 + 551);
    if ( v36 > 3 )
    {
      v37 = 0;
    }
    else
    {
      v37 = *(_QWORD *)(*v16 + 8 * v36 + 1896);
      if ( !v37 )
        v37 = v16[v36 + 6];
    }
    atomic_store(v37, v16 + 14);
  }
  v38 = v6 ^ 1;
  if ( !a6 )
    v38 = 1;
  if ( (v38 & 1) == 0 )
  {
    v39 = *(char *)(a6 + 551);
    if ( (v39 & 0xFFFFFFFE) == 4 )
      v40 = v16[v39 + 6];
    else
      v40 = 0;
    atomic_store(v40, v16 + 15);
  }
  v41 = v8 ^ 1;
  if ( !a6 )
    v41 = 1;
  if ( (v41 & 1) == 0 )
  {
    v42 = *(char *)(a6 + 551);
    if ( (v42 & 0xFFFFFFFE) == 6 )
      v43 = v16[v42 + 6];
    else
      v43 = 0;
    atomic_store(v43, v16 + 16);
  }
LABEL_120:
  if ( !a5 )
    return 0;
  v44 = *(_QWORD **)(a5 + 32);
  v45 = (__int64 *)(a5 + 24);
  if ( *v44 == a5 + 24 && (v46 = *v45, *(__int64 **)(*v45 + 8) == v45) )
  {
    *(_QWORD *)(v46 + 8) = v44;
    *v44 = v46;
  }
  else
  {
    _list_del_entry_valid_or_report(v45);
  }
  *(_QWORD *)(a5 + 32) = 0xDEAD000000000122LL;
  return 0;
}
