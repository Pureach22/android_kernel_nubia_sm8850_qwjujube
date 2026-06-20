__int64 __fastcall dp_peer_vdev_list_remove(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x7
  __int64 v16; // x7
  _QWORD *v17; // x9
  _QWORD *v18; // t1
  __int64 v19; // x8
  __int64 v21; // x9
  _QWORD *v22; // x10
  _QWORD *v23; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 136);
  }
  else
  {
    raw_spin_lock_bh(a2 + 136);
    *(_QWORD *)(a2 + 144) |= 1uLL;
  }
  v15 = a3[3];
  v18 = *(_QWORD **)(v15 + 120);
  v16 = v15 + 120;
  v17 = v18;
  if ( v18 )
  {
    while ( v17 != a3 )
    {
      v17 = (_QWORD *)v17[7];
      if ( !v17 )
        goto LABEL_8;
    }
    v21 = a3[7];
    v22 = (_QWORD *)a3[8];
    v23 = (_QWORD *)(a3[3] + 128LL);
    if ( v21 )
      v23 = (_QWORD *)(v21 + 64);
    *v23 = v22;
    *v22 = a3[7];
    a3[7] = 0;
    a3[8] = 0;
    dp_peer_unref_delete((__int64)a3, 0xCu, v7, v8, v9, v10, v11, v12, v13, v14);
    --*(_DWORD *)(a2 + 42520);
    v19 = *(_QWORD *)(a2 + 144);
    if ( (v19 & 1) != 0 )
      goto LABEL_14;
  }
  else
  {
LABEL_8:
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: peer:%pK not found in vdev:%pK peerlist:%pK",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_peer_vdev_list_remove",
      a1,
      a3,
      a2,
      v16);
    v19 = *(_QWORD *)(a2 + 144);
    if ( (v19 & 1) != 0 )
    {
LABEL_14:
      *(_QWORD *)(a2 + 144) = v19 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a2 + 136);
    }
  }
  return raw_spin_unlock(a2 + 136);
}
