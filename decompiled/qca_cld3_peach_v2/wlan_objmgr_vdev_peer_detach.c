__int64 __fastcall wlan_objmgr_vdev_peer_detach(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned __int64 v9; // x8
  int v10; // w8
  __int64 v11; // x8
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
    if ( !*(_WORD *)(a1 + 224) )
      goto LABEL_12;
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
    if ( !*(_WORD *)(a1 + 224) )
      goto LABEL_12;
  }
  if ( *(_QWORD *)(a1 + 176) == a2 )
    *(_QWORD *)(a1 + 176) = 0;
  if ( *(_QWORD *)(a1 + 184) != a2 )
  {
    if ( !a2 )
      goto LABEL_12;
LABEL_11:
    if ( (unsigned int)qdf_list_remove_node(a1 + 192, (_QWORD *)(a2 + 16)) )
      goto LABEL_12;
    v7 = *(_QWORD *)(a1 + 1352);
    v8 = *(_QWORD *)(a1 + 216);
    --*(_WORD *)(a1 + 224);
    if ( (v7 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_19;
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_19;
    }
    v9 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v9 + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v8 + 1248);
      *(_QWORD *)(v8 + 1256) |= 1uLL;
      goto LABEL_20;
    }
LABEL_19:
    raw_spin_lock(v8 + 1248);
LABEL_20:
    v10 = *(_DWORD *)(a2 + 68);
    if ( v10 == 11 || v10 == 8 )
    {
      --*(_WORD *)(v8 + 76);
      v11 = *(_QWORD *)(v8 + 1256);
      if ( (v11 & 1) == 0 )
      {
LABEL_23:
        raw_spin_unlock(v8 + 1248);
LABEL_24:
        wlan_objmgr_vdev_release_ref(a1, 0, v12, v13, v14, v15, v16, v17, v18, v19, v20);
        return 0;
      }
    }
    else
    {
      --*(_WORD *)(v8 + 72);
      v11 = *(_QWORD *)(v8 + 1256);
      if ( (v11 & 1) == 0 )
        goto LABEL_23;
    }
    *(_QWORD *)(v8 + 1256) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v8 + 1248);
    goto LABEL_24;
  }
  *(_QWORD *)(a1 + 184) = 0;
  if ( a2 )
    goto LABEL_11;
LABEL_12:
  v5 = *(_QWORD *)(a1 + 1352);
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
  return 16;
}
