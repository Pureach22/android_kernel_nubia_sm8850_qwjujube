__int64 __fastcall dp_peer_vdev_list_remove(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  __int64 v7; // x21
  unsigned __int64 StatusReg; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x7
  __int64 v18; // x7
  __int64 v19; // x9
  __int64 v20; // t1
  __int64 v21; // x8
  __int64 v22; // x9
  _QWORD *v23; // x10
  _QWORD *v24; // x8
  __int64 v25; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(a3 + 408) != 2 )
  {
    v25 = v4;
    v7 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 144);
    }
    else
    {
      raw_spin_lock_bh(a2 + 144);
      *(_QWORD *)(a2 + 152) |= 1uLL;
    }
    v17 = *(_QWORD *)(a3 + 24);
    v20 = *(_QWORD *)(v17 + 128);
    v18 = v17 + 128;
    v19 = v20;
    if ( v20 )
    {
      while ( v19 != a3 )
      {
        v19 = *(_QWORD *)(v19 + 56);
        if ( !v19 )
          goto LABEL_9;
      }
      v22 = *(_QWORD *)(a3 + 56);
      v23 = *(_QWORD **)(a3 + 64);
      v24 = (_QWORD *)(*(_QWORD *)(a3 + 24) + 136LL);
      if ( v22 )
        v24 = (_QWORD *)(v22 + 64);
      *v24 = v23;
      *v23 = *(_QWORD *)(a3 + 56);
      *(_QWORD *)(a3 + 56) = 0;
      *(_QWORD *)(a3 + 64) = 0;
      dp_peer_unref_delete(a3, 0xCu, v9, v10, v11, v12, v13, v14, v15, v16);
      --*(_DWORD *)(a2 + 43344);
      v21 = *(_QWORD *)(a2 + 152);
      if ( (v21 & 1) != 0 )
        goto LABEL_15;
    }
    else
    {
LABEL_9:
      qdf_trace_msg(
        0x81u,
        8u,
        "%s: %pK: peer:%pK not found in vdev:%pK peerlist:%pK",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_peer_vdev_list_remove",
        v7,
        a3,
        a2,
        v18,
        v3,
        v25);
      v21 = *(_QWORD *)(a2 + 152);
      if ( (v21 & 1) != 0 )
      {
LABEL_15:
        *(_QWORD *)(a2 + 152) = v21 & 0xFFFFFFFFFFFFFFFELL;
        return raw_spin_unlock_bh(a2 + 144);
      }
    }
    return raw_spin_unlock(a2 + 144);
  }
  return result;
}
