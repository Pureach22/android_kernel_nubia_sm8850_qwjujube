__int64 __fastcall wlan_objmgr_vdev_peer_attach(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  int v5; // w8
  __int64 v6; // x22
  __int64 v7; // x8
  unsigned __int64 v8; // x8
  int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned int v12; // w9
  unsigned int v13; // w10
  int v14; // w21
  __int64 v15; // x8
  unsigned __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  unsigned int v45; // w9
  unsigned int v48; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1272);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1272);
    *(_QWORD *)(a1 + 1280) |= 1uLL;
  }
  v5 = *(_DWORD *)(a2 + 68);
  v6 = *(_QWORD *)(a1 + 152);
  if ( v5 != 8 && v5 != 11 && *(unsigned __int16 *)(a1 + 160) >= (unsigned int)*(unsigned __int16 *)(a1 + 162) )
  {
    v28 = *(_QWORD *)(a1 + 1280);
    if ( (v28 & 1) == 0 )
    {
      v11 = a1 + 1272;
      goto LABEL_43;
    }
    v38 = a1 + 1272;
    *(_QWORD *)(a1 + 1280) = v28 & 0xFFFFFFFFFFFFFFFELL;
LABEL_56:
    raw_spin_unlock_bh(v38);
    return 16;
  }
  v7 = *(_QWORD *)(a1 + 1280);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1280) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_12;
  }
  else
  {
    raw_spin_unlock(a1 + 1272);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_12;
  }
  v8 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v8 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v8 + 16) & 0xFF00) == 0 )
  {
    raw_spin_lock_bh(v6 + 1240);
    *(_QWORD *)(v6 + 1248) |= 1uLL;
    goto LABEL_13;
  }
LABEL_12:
  raw_spin_lock(v6 + 1240);
LABEL_13:
  v9 = *(_DWORD *)(a2 + 68);
  if ( v9 != 11 && v9 != 8 )
  {
    v12 = *(unsigned __int16 *)(v6 + 72);
    v13 = *(unsigned __int8 *)(v6 + 41);
    v14 = v12 - v13;
    if ( v12 >= v13 && v14 >= *(unsigned __int16 *)(v6 + 74) - *(unsigned __int8 *)(v6 + 42) )
    {
      v29 = *(_QWORD *)(v6 + 1248);
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(v6 + 1248) = v29 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v6 + 1240);
      }
      else
      {
        raw_spin_unlock(v6 + 1240);
      }
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: Peer limit reached vdev:%d peers:%d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_objmgr_vdev_peer_attach",
        *(unsigned __int8 *)(a1 + 104),
        (unsigned int)v14);
      return 16;
    }
LABEL_20:
    if ( v9 == 11 || v9 == 8 )
    {
      ++*(_WORD *)(*(_QWORD *)(a1 + 152) + 76LL);
      v15 = *(_QWORD *)(v6 + 1248);
      if ( (v15 & 1) == 0 )
        goto LABEL_23;
    }
    else
    {
      ++*(_WORD *)(*(_QWORD *)(a1 + 152) + 72LL);
      v15 = *(_QWORD *)(v6 + 1248);
      if ( (v15 & 1) == 0 )
      {
LABEL_23:
        raw_spin_unlock(v6 + 1240);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_26;
        goto LABEL_24;
      }
    }
    *(_QWORD *)(v6 + 1248) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v6 + 1240);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_26;
LABEL_24:
    v16 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v16 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v16 + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 1272);
      *(_QWORD *)(a1 + 1280) |= 1uLL;
LABEL_27:
      qdf_list_insert_back((_QWORD *)(a1 + 128), (_QWORD *)(a2 + 16));
      ++*(_WORD *)(a1 + 160);
      if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 48), (const void *)(a1 + 74), 6u) )
      {
        v25 = *(_DWORD *)(a1 + 16);
      }
      else
      {
        v25 = *(_DWORD *)(a1 + 16);
        *(_QWORD *)(a1 + 112) = a2;
        if ( v25 <= 0xB && ((1 << v25) & 0x80A) != 0 )
          *(_QWORD *)(a1 + 120) = a2;
      }
      if ( (v25 | 2) == 2 && (*(_DWORD *)(a2 + 68) & 0xFFFFFFFE) == 2 )
        *(_QWORD *)(a1 + 120) = a2;
      if ( a1 )
      {
        _X8 = (unsigned int *)(a1 + 168);
        __asm { PRFM            #0x11, [X8] }
        do
          v45 = __ldxr(_X8);
        while ( __stxr(v45 + 1, _X8) );
        _X8 = (unsigned int *)(a1 + 172);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 + 1, _X8) );
        v27 = *(_QWORD *)(a1 + 1280);
        if ( (v27 & 1) == 0 )
        {
          raw_spin_unlock(a1 + 1272);
          return 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: vdev obj is NULL for id:%d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wlan_objmgr_vdev_get_ref",
          0);
        v27 = 0x1733AC00048025LL;
      }
      *(_QWORD *)(a1 + 1280) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1272);
      return 0;
    }
LABEL_26:
    raw_spin_lock(a1 + 1272);
    goto LABEL_27;
  }
  if ( *(unsigned __int16 *)(v6 + 76) < 0x80u )
    goto LABEL_20;
  v10 = *(_QWORD *)(v6 + 1248);
  if ( (v10 & 1) != 0 )
  {
    v38 = v6 + 1240;
    *(_QWORD *)(v6 + 1248) = v10 & 0xFFFFFFFFFFFFFFFELL;
    goto LABEL_56;
  }
  v11 = v6 + 1240;
LABEL_43:
  raw_spin_unlock(v11);
  return 16;
}
