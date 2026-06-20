__int64 __fastcall rmnet_aps_change_flow(unsigned __int64 *a1, __int64 *a2)
{
  unsigned __int64 *v3; // x20
  unsigned __int64 *v4; // x8
  unsigned __int64 *v5; // x20
  unsigned int v6; // w21
  int v7; // w8
  unsigned __int64 v8; // x11
  unsigned __int64 v9; // x12
  int v10; // w8
  int v11; // w9
  unsigned __int64 v12; // x10
  int v13; // w8
  unsigned __int64 *v15; // x21
  __int64 v16; // x0
  int v17; // w10
  __int64 v18; // x11
  __int64 v19; // x12
  int v20; // w8
  int v21; // w9
  unsigned __int64 v22; // x11
  unsigned int v23; // w10
  bool v24; // zf
  int v25; // w8
  int v26; // w9
  __int64 v27; // x8
  unsigned __int64 v28; // x2
  unsigned __int64 v29; // x8
  void *v30; // x2
  void *v31; // x8
  __int64 v32; // x1
  __int64 v33; // x9
  __int64 v34; // x9

  v3 = a1;
  while ( 1 )
  {
    v3 = (unsigned __int64 *)*v3;
    if ( v3 == a1 )
      break;
    if ( *((_DWORD *)v3 + 9) == *((_DWORD *)a2 + 1) )
    {
      v4 = v3 - 2;
      if ( *(_DWORD *)a2 == 3 )
      {
        if ( v3 != qword_10 )
          rmnet_aps_remove_flow(v3 - 2);
        return 0;
      }
      if ( v3 == qword_10 || *(_DWORD *)a2 != 2 )
      {
        if ( v3 != qword_10 )
        {
          v6 = -1687355392;
          raw_spin_lock_bh(&rmnet_aps_lock);
          v7 = *((_DWORD *)a2 + 4);
          v8 = *a2;
          v9 = a2[1];
          *((_DWORD *)v3 + 12) = v7;
          v10 = BYTE1(v7);
          v11 = *((unsigned __int8 *)v3 + 50);
          v12 = *((unsigned __int8 *)v3 + 48);
          v3[4] = v8;
          v3[5] = v9;
          *((_BYTE *)v3 + 88) = v10 != 0;
          *((_BYTE *)v3 + 89) = v11 != 0;
          if ( v12 <= 4 )
            v6 = aps2linux_prio_map[v12] | 0x9B6D0000;
          if ( v10 )
            v13 = v6 | 0x100;
          else
            v13 = v6;
          if ( v11 )
            v13 |= 0x200u;
          *((_DWORD *)v3 + 16) = v13;
          raw_spin_unlock_bh(&rmnet_aps_lock);
          return 0;
        }
      }
      else
      {
        v5 = a1;
        rmnet_aps_remove_flow(v4);
        a1 = v5;
      }
      goto LABEL_21;
    }
  }
  if ( *(_DWORD *)a2 == 3 )
    return 0;
LABEL_21:
  if ( (unsigned int)rmnet_aps_flow_cnt > 0xFE )
    return 4294967274LL;
  v15 = a1;
  v16 = _kmalloc_cache_noprof(mod_timer, 3520, 112);
  if ( v16 )
  {
    v17 = *((_DWORD *)a2 + 4);
    v18 = *a2;
    v19 = a2[1];
    v20 = BYTE1(v17);
    v21 = BYTE2(v17);
    *(_DWORD *)(v16 + 64) = v17;
    *(_QWORD *)(v16 + 48) = v18;
    *(_QWORD *)(v16 + 56) = v19;
    v22 = (unsigned __int8)v17;
    v23 = -1687355392;
    *(_BYTE *)(v16 + 104) = v20 != 0;
    *(_BYTE *)(v16 + 105) = v21 != 0;
    if ( v22 <= 4 )
      v23 = aps2linux_prio_map[v22] | 0x9B6D0000;
    v24 = v20 == 0;
    v25 = *((_DWORD *)a2 + 2);
    if ( !v24 )
      v23 |= 0x100u;
    if ( v21 )
      v26 = v23 | 0x200;
    else
      v26 = v23;
    *(_DWORD *)(v16 + 80) = v26;
    if ( v25 )
    {
      v27 = (unsigned int)(250 * v25);
      *(_DWORD *)(v16 + 84) = v27;
      *(_QWORD *)(v16 + 88) = jiffies + v27;
    }
    v28 = *v15;
    v29 = v16 + 16;
    if ( *(unsigned __int64 **)(*v15 + 8) != v15 || (unsigned __int64 *)v29 == v15 || v28 == v29 )
    {
      _list_add_valid_or_report(v16 + 16, v15);
      v16 = v33;
    }
    else
    {
      *(_QWORD *)(v16 + 16) = v28;
      *(_QWORD *)(v16 + 24) = v15;
      atomic_store(v29, v15);
      *(_QWORD *)(v28 + 8) = v29;
    }
    v30 = aps_flow_list;
    v31 = (void *)(v16 + 32);
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)aps_flow_list) != &aps_flow_list || aps_flow_list == v31 )
    {
      _list_add_valid_or_report(v16 + 32, &aps_flow_list);
      v16 = v34;
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)aps_flow_list) = v31;
      *(_QWORD *)(v16 + 32) = v30;
      *(_QWORD *)(v16 + 40) = &aps_flow_list;
      aps_flow_list = (_UNKNOWN *)(v16 + 32);
    }
    v32 = *(_QWORD *)(v16 + 88);
    ++rmnet_aps_flow_cnt;
    if ( v32 && (!qword_288 || v32 - qword_290 < 0) )
      mod_timer(&rmnet_aps_timer);
    return 0;
  }
  return 4294967284LL;
}
