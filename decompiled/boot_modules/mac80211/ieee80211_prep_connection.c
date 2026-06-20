__int64 __fastcall ieee80211_prep_connection(__int64 a1, __int64 a2, int a3, __int64 a4, char a5, _QWORD *a6, char a7)
{
  __int64 v7; // x20
  __int64 v13; // x27
  __int64 result; // x0
  __int64 v16; // x1
  __int64 v17; // x22
  unsigned __int8 v18; // w21
  __int64 v19; // x25
  unsigned int v20; // w21
  __int64 v21; // x28
  char v22; // w28
  _QWORD *v23; // x21
  __int64 v24; // x26
  char v25; // w22
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 lock; // x0
  __int64 v29; // x2
  __int64 v30; // x0
  int v31; // w9
  __int64 v32; // x21
  _BYTE *v33; // x22
  __int64 elem_match; // x27
  char v35; // w9
  char v36; // w8
  unsigned int v37; // w0
  unsigned int v38; // w0
  __int64 v39; // x3
  char v40; // [xsp+4h] [xbp-Ch]
  _QWORD *v41; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(a1 + 1616);
  v13 = a4;
  if ( (a3 & 0x80) == 0 )
  {
    if ( a4 )
    {
      result = ieee80211_vif_set_links((unsigned __int16 *)a1, 1LL << a3, 0);
      if ( (_DWORD)result )
        return result;
      v41 = a6;
      if ( (unsigned __int8)a3 >= 0xFu )
      {
        __break(0x5512u);
        return ieee80211_mgd_assoc(result, v16);
      }
      v17 = (unsigned __int8)a3;
      v18 = a3;
      goto LABEL_9;
    }
LABEL_62:
    __break(0x800u);
    return 4294967274LL;
  }
  if ( a4 )
    goto LABEL_62;
  result = ieee80211_vif_set_links((unsigned __int16 *)a1, 0, 0);
  if ( (_DWORD)result )
    return result;
  v41 = a6;
  v17 = 0;
  v18 = 0;
  v13 = a2 + 72;
LABEL_9:
  v19 = *(_QWORD *)(a1 + 8 * v17 + 4568);
  if ( !v19 )
  {
    __break(0x800u);
    v20 = -67;
    goto LABEL_47;
  }
  if ( !*(_QWORD *)(a1 + 2480) && !*(_QWORD *)(a1 + 2488) )
  {
    __break(0x800u);
    v20 = -22;
    goto LABEL_47;
  }
  if ( (*(_BYTE *)(v7 + 1470) & 1) != 0 )
  {
    v20 = -16;
LABEL_47:
    ieee80211_vif_set_links((unsigned __int16 *)a1, 0, 0);
    return v20;
  }
  v40 = a5;
  if ( (a5 & 1) == 0 || (_rcu_read_lock(result, v16), v21 = sta_info_get(a1, v13), _rcu_read_unlock(v21), !v21) )
  {
    if ( (a3 & 0x80) != 0 )
    {
      v26 = sta_info_alloc(a1, v13, 3264);
      v24 = v26;
      if ( v26 )
      {
LABEL_20:
        *(_BYTE *)(v24 + 2715) = (~a3 & 0x80) != 0;
        lock = _rcu_read_lock(v26, v27);
        v29 = *(_QWORD *)(v24 + 8 * v17 + 2568);
        if ( !v29 )
        {
          __break(0x800u);
          _rcu_read_unlock(lock);
          sta_info_free(v7, v24);
          v20 = -22;
          goto LABEL_47;
        }
        v30 = ieee80211_mgd_setup_link_sta(v19, v24, v29, a2);
        v22 = v40;
        if ( (_DWORD)v30 )
        {
          v20 = v30;
          _rcu_read_unlock(v30);
          goto LABEL_46;
        }
        v31 = *(_DWORD *)(a2 + 72);
        *(_WORD *)(v19 + 540) = *(_WORD *)(a2 + 76);
        *(_DWORD *)(v19 + 536) = v31;
        *(_WORD *)(*(_QWORD *)(v19 + 944) + 50LL) = *(_WORD *)(a2 + 68);
        v32 = *(_QWORD *)(a2 + 16);
        if ( !v32 )
        {
          if ( (*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 96LL) & 0x1000000) != 0 )
          {
            *(_QWORD *)(*(_QWORD *)(v19 + 944) + 56LL) = 0;
            *(_DWORD *)(*(_QWORD *)(v19 + 944) + 64LL) = 0;
          }
          else
          {
            *(_QWORD *)(*(_QWORD *)(v19 + 944) + 56LL) = **(_QWORD **)(a2 + 24);
            *(_DWORD *)(*(_QWORD *)(v19 + 944) + 64LL) = *(_DWORD *)(a2 + 100);
          }
          v23 = v41;
          *(_BYTE *)(*(_QWORD *)(v19 + 944) + 68LL) = 0;
          goto LABEL_43;
        }
        *(_QWORD *)(*(_QWORD *)(v19 + 944) + 56LL) = *(_QWORD *)v32;
        *(_DWORD *)(*(_QWORD *)(v19 + 944) + 64LL) = *(_DWORD *)(a2 + 96);
        v33 = (_BYTE *)(*(_QWORD *)(v19 + 944) + 68LL);
        elem_match = cfg80211_find_elem_match(5, v32 + 29, *(unsigned int *)(v32 + 24), 0, 0, 0);
        v30 = cfg80211_find_elem_match(85, v32 + 29, *(unsigned int *)(v32 + 24), 0, 0, 0);
        if ( elem_match )
        {
          v23 = v41;
          if ( v33 )
          {
            if ( *(unsigned __int8 *)(elem_match + 1) >= 2u )
            {
              v35 = *(_BYTE *)(elem_match + 2);
              goto LABEL_34;
            }
LABEL_33:
            v35 = 0;
LABEL_34:
            v36 = 0;
            *v33 = v35;
            if ( !v30 )
              goto LABEL_43;
            goto LABEL_37;
          }
        }
        else
        {
          v23 = v41;
          if ( v33 )
            goto LABEL_33;
        }
        v36 = 1;
        if ( !v30 )
        {
LABEL_43:
          _rcu_read_unlock(v30);
          v25 = 0;
          goto LABEL_44;
        }
LABEL_37:
        if ( *(unsigned __int8 *)(v30 + 1) < 3u )
          v36 = 1;
        if ( (v36 & 1) == 0 )
          *v33 = *(_BYTE *)(v30 + 4);
        goto LABEL_43;
      }
    }
    else
    {
      v26 = sta_info_alloc_with_link(a1, v13, v18, a2 + 72, 3264);
      v24 = v26;
      if ( v26 )
        goto LABEL_20;
    }
    v20 = -12;
    goto LABEL_47;
  }
  v22 = v40;
  if ( (a7 & 1) == 0 )
  {
LABEL_50:
    if ( *(_DWORD *)(a2 + 72) ^ *(_DWORD *)(v19 + 536)
       | *(unsigned __int16 *)(a2 + 76) ^ *(unsigned __int16 *)(v19 + 540) )
    {
      __break(0x800u);
    }
    goto LABEL_58;
  }
  v23 = v41;
  v24 = 0;
  v25 = 1;
LABEL_44:
  *(_QWORD *)(v19 + 552) = *v23;
  v37 = ieee80211_prep_channel(a1, v19, a2, (a3 & 0x80) == 0, v19 + 552);
  if ( v37 )
  {
    v20 = v37;
    if ( (v25 & 1) != 0 )
      goto LABEL_47;
LABEL_46:
    sta_info_free(v7, v24);
    goto LABEL_47;
  }
  *v23 = *(_QWORD *)(v19 + 552);
  if ( (v25 & 1) != 0 )
    goto LABEL_50;
  ieee80211_link_info_change_notify(a1, v19, 224);
  if ( (v22 & 1) != 0 )
  {
    if ( (*(_QWORD *)(v24 + 216) & 0x100000) != 0 )
      __break(0x800u);
    if ( (unsigned int)sta_info_move_state(v24, 2) )
      __break(0x800u);
  }
  v38 = sta_info_insert(v24);
  if ( v38 )
  {
    v20 = v38;
    printk(&unk_BBD30, a1 + 1640, v38, v39);
    ieee80211_link_release_channel((__int64 *)v19);
    goto LABEL_47;
  }
LABEL_58:
  if ( *(_QWORD *)(v7 + 4696) )
    ieee80211_scan_cancel(v7);
  return 0;
}
