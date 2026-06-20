_QWORD *__fastcall wlan_objmgr_populate_logically_deleted_peerlist_by_mac_n_vdev(
        __int64 a1,
        unsigned __int8 a2,
        const void *a3,
        _BYTE *a4,
        unsigned int a5)
{
  unsigned __int64 StatusReg; // x8
  char v11; // w24
  unsigned __int64 v12; // x8
  _QWORD *v13; // x0
  _QWORD *v14; // x23
  __int64 v15; // x26
  _QWORD *v16; // x24
  unsigned __int64 v17; // x28
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  _QWORD *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  _QWORD v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    if ( *(_WORD *)(a1 + 58) )
      goto LABEL_5;
LABEL_44:
    v39 = *(_QWORD *)(a1 + 2824);
    if ( (v39 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v39 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    v14 = nullptr;
    goto LABEL_47;
  }
  raw_spin_lock_bh(a1 + 2816);
  *(_QWORD *)(a1 + 2824) |= 1uLL;
  if ( !*(_WORD *)(a1 + 58) )
    goto LABEL_44;
LABEL_5:
  v11 = a4[5];
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v12 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v12 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1664);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1664);
    *(_QWORD *)(a1 + 1672) |= 1uLL;
  }
  v13 = (_QWORD *)_qdf_mem_malloc(0x18u, "wlan_obj_psoc_populate_logically_del_peerlist_by_mac_n_bssid", 2018);
  v14 = v13;
  if ( !v13 )
    goto LABEL_38;
  *v13 = v13;
  v15 = a1 + 24LL * (v11 & 0x3F);
  v13[1] = v13;
  v13[2] = 0x60600000000LL;
  v41[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v15 + 128), v41) )
    goto LABEL_36;
  v16 = (_QWORD *)v41[0];
  if ( !v41[0] )
    goto LABEL_36;
  v17 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v17 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v17 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v16 + 96);
    }
    else
    {
      raw_spin_lock_bh(v16 + 96);
      *(__int64 *)((char *)&qword_308 + (_QWORD)v16) |= 1uLL;
    }
    if ( (unsigned int)qdf_mem_cmp(v16 + 6, a4, 6u)
      || *((unsigned __int8 *)&qword_30 + (_QWORD)v16 + 6) != a2
      || a3 && (unsigned int)qdf_mem_cmp((const void *)(*(__int64 *)((char *)&qword_60 + (_QWORD)v16) + 74), a3, 6u)
      || *(_DWORD *)((char *)&qword_2F8 + (_QWORD)v16) != 6
      || !*(int *)((char *)&dword_68 + (_QWORD)v16) )
    {
      v36 = *(__int64 *)((char *)&qword_308 + (_QWORD)v16);
      if ( (v36 & 1) != 0 )
      {
        *(__int64 *)((char *)&qword_308 + (_QWORD)v16) = v36 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 96);
      }
      else
      {
        raw_spin_unlock(v16 + 96);
      }
      goto LABEL_29;
    }
    wlan_objmgr_peer_get_ref((__int64)v16, a5, v18, v19, v20, v21, v22, v23, v24, v25);
    v26 = *(__int64 *)((char *)&qword_308 + (_QWORD)v16);
    if ( (v26 & 1) != 0 )
    {
      *(__int64 *)((char *)&qword_308 + (_QWORD)v16) = v26 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 96);
    }
    else
    {
      raw_spin_unlock(v16 + 96);
    }
    v27 = (_QWORD *)_qdf_mem_malloc(0x18u, "wlan_obj_psoc_populate_logically_del_peerlist_by_mac_n_bssid", 2052);
    if ( !v27 )
      break;
    v27[2] = v16;
    qdf_list_insert_front(v14, v27);
LABEL_29:
    v41[0] = 0;
    if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v15 + 128), v16, v41) )
    {
      v16 = (_QWORD *)v41[0];
      if ( v41[0] )
        continue;
    }
    goto LABEL_36;
  }
  wlan_objmgr_peer_release_ref((__int64)v16, a5, v28, v29, v30, v31, v32, v33, v34, v35);
LABEL_36:
  if ( qdf_list_empty(v14) )
  {
    _qdf_mem_free((__int64)v14);
    v14 = nullptr;
  }
LABEL_38:
  v37 = *(_QWORD *)(a1 + 1672);
  if ( (v37 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1672) = v37 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1664);
    v38 = *(_QWORD *)(a1 + 2824);
    if ( (v38 & 1) != 0 )
      goto LABEL_42;
LABEL_40:
    raw_spin_unlock(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 1664);
    v38 = *(_QWORD *)(a1 + 2824);
    if ( (v38 & 1) == 0 )
      goto LABEL_40;
LABEL_42:
    *(_QWORD *)(a1 + 2824) = v38 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v14;
}
