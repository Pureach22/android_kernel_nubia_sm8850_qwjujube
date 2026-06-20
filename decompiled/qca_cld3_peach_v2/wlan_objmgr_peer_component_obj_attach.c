__int64 __fastcall wlan_objmgr_peer_component_obj_attach(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 v4; // x29
  __int64 v5; // x30
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  int v24; // w8
  unsigned int v25; // w20
  __int64 v26; // x8
  int v27; // w9
  __int64 v28; // x22
  __int64 v29; // x8
  _DWORD *v30; // x9
  __int64 v31; // x1
  __int64 v32; // [xsp+8h] [xbp-28h]

  if ( a2 > 0x35 )
    return 38;
  v32 = v5;
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
  if ( *(_QWORD *)(a1 + 112 + 8LL * a2) )
  {
    v12 = *(_QWORD *)(a1 + 776);
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 776) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 768);
    }
    else
    {
      raw_spin_unlock(a1 + 768);
    }
    return 16;
  }
  *(_QWORD *)(a1 + 112 + 8LL * a2) = a3;
  *(_DWORD *)(a1 + 4LL * a2 + 544) = a4;
  v13 = *(_QWORD *)(a1 + 776);
  if ( (v13 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 776) = v13 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 768);
  }
  else
  {
    raw_spin_unlock(a1 + 768);
  }
  if ( *(_DWORD *)(a1 + 760) != 3 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v14 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v14 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 768);
  }
  else
  {
    raw_spin_lock_bh(a1 + 768);
    *(_QWORD *)(a1 + 776) |= 1uLL;
  }
  v23 = 0;
  while ( 1 )
  {
    v24 = *(_DWORD *)(a1 + 4 * v23 + 544);
    if ( v24 != 40 )
    {
      if ( v24 == 2 || v24 == 16 )
      {
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: Peer comp object(id:%d) alloc fail",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_objmgr_peer_object_status",
          v4,
          v32);
        v25 = 16;
        goto LABEL_27;
      }
      goto LABEL_20;
    }
    if ( !*(_QWORD *)(a1 + 8 * v23 + 112) )
      break;
LABEL_20:
    if ( ++v23 == 54 )
    {
      v25 = 0;
      goto LABEL_27;
    }
  }
  v25 = 40;
LABEL_27:
  v26 = *(_QWORD *)(a1 + 776);
  if ( (v26 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 776) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 768);
    if ( !v25 )
      goto LABEL_35;
LABEL_29:
    if ( v25 == 16 )
    {
      v27 = 7;
      goto LABEL_36;
    }
  }
  else
  {
    raw_spin_unlock(a1 + 768);
    if ( v25 )
      goto LABEL_29;
LABEL_35:
    v27 = 1;
LABEL_36:
    v28 = -432;
    *(_DWORD *)(a1 + 760) = v27;
    v29 = g_umac_glb_obj;
    do
    {
      v30 = *(_DWORD **)(v29 + v28 + 10416);
      if ( v30 )
      {
        v31 = *(_QWORD *)(v29 + v28 + 10848);
        if ( *(v30 - 1) != -202286667 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v30)(a1, v31, v25);
        v29 = g_umac_glb_obj;
      }
      v28 += 8;
    }
    while ( v28 );
  }
  return 0;
}
