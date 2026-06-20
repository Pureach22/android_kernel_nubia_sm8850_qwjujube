__int64 __fastcall wlan_objmgr_peer_component_obj_detach(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  int v22; // w8
  int v23; // w20
  __int64 v24; // x8
  int v25; // w8
  int v26; // w8
  int v27; // w8
  __int64 v28; // [xsp+8h] [xbp-28h]

  if ( a2 > 0x35 )
    return 38;
  v28 = v4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 768);
  }
  else
  {
    raw_spin_lock_bh(a1 + 768);
    *(_QWORD *)(a1 + 776) |= 1uLL;
  }
  if ( *(_QWORD *)(a1 + 112 + 8LL * a2) != a3 )
  {
    *(_DWORD *)(a1 + 4LL * a2 + 544) = 16;
    v10 = *(_QWORD *)(a1 + 776);
    if ( (v10 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 776) = v10 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 768);
    }
    else
    {
      raw_spin_unlock(a1 + 768);
    }
    return 16;
  }
  *(_QWORD *)(a1 + 112 + 8LL * a2) = 0;
  *(_DWORD *)(a1 + 4LL * a2 + 544) = 0;
  v11 = *(_QWORD *)(a1 + 776);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 776) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 768);
  }
  else
  {
    raw_spin_unlock(a1 + 768);
  }
  if ( (*(_DWORD *)(a1 + 760) & 0xFFFFFFFE) != 4 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v12 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v12 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 768);
  }
  else
  {
    raw_spin_lock_bh(a1 + 768);
    *(_QWORD *)(a1 + 776) |= 1uLL;
  }
  v21 = 0;
  while ( 1 )
  {
    v22 = *(_DWORD *)(a1 + 4 * v21 + 544);
    if ( v22 != 40 )
    {
      if ( v22 == 2 || v22 == 16 )
      {
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: Peer comp object(id:%d) alloc fail",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_objmgr_peer_object_status",
          v3,
          v28);
        v23 = 16;
        goto LABEL_27;
      }
      goto LABEL_20;
    }
    if ( !*(_QWORD *)(a1 + 8 * v21 + 112) )
      break;
LABEL_20:
    if ( ++v21 == 54 )
    {
      v23 = 0;
      goto LABEL_27;
    }
  }
  v23 = 40;
LABEL_27:
  v24 = *(_QWORD *)(a1 + 776);
  if ( (v24 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 776) = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 768);
    if ( v23 == 16 )
      goto LABEL_39;
LABEL_29:
    if ( v23 )
      return 0;
    v25 = *(_DWORD *)(a1 + 760);
    if ( v25 != 2 )
    {
      if ( v25 == 5 )
        goto LABEL_43;
      if ( v25 != 4 )
        return 0;
      *(_DWORD *)(a1 + 760) = 2;
    }
    return wlan_objmgr_peer_obj_free(a1);
  }
  raw_spin_unlock(a1 + 768);
  if ( v23 != 16 )
    goto LABEL_29;
LABEL_39:
  v26 = *(_DWORD *)(a1 + 760);
  if ( v26 == 5 )
  {
LABEL_43:
    v27 = 1;
LABEL_44:
    *(_DWORD *)(a1 + 760) = v27;
    return 0;
  }
  if ( v26 == 4 )
  {
    v27 = 8;
    goto LABEL_44;
  }
  return 0;
}
