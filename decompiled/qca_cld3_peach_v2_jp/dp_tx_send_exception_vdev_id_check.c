__int64 __fastcall dp_tx_send_exception_vdev_id_check(__int64 a1, unsigned __int8 a2, __int64 a3, unsigned __int16 *a4)
{
  __int64 ref_by_id_1; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  unsigned int *v18; // x8
  __int64 v19; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v21; // x24
  __int64 v22; // x8
  __int64 v23; // x10
  unsigned int *v25; // x8
  __int64 v26; // x25

  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 0x13u);
  if ( ref_by_id_1 )
  {
    v17 = ref_by_id_1;
    v18 = (unsigned int *)**(unsigned __int8 **)(a3 + 224);
    if ( ((unsigned __int8)v18 & 1) != 0 )
    {
LABEL_9:
      dp_vdev_unref_delete(a1, v17, 0x13u, v18, v9, v10, v11, v12, v13, v14, v15, v16);
      return dp_tx_send_exception(a1, a2, a3, a4);
    }
    v19 = *(_QWORD *)(*(_QWORD *)(ref_by_id_1 + 24) + 8LL);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v19 + 17576);
    }
    else
    {
      v26 = v19;
      raw_spin_lock_bh(v19 + 17576);
      *(_QWORD *)(v26 + 17584) |= 1uLL;
    }
    v21 = dp_peer_ast_hash_find_by_vdevid();
    v22 = *(_QWORD *)(*(_QWORD *)(v17 + 24) + 8LL);
    v23 = *(_QWORD *)(v22 + 17584);
    if ( (v23 & 1) != 0 )
    {
      *(_QWORD *)(v22 + 17584) = v23 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v22 + 17576);
      if ( v21 )
        goto LABEL_9;
    }
    else
    {
      raw_spin_unlock(v22 + 17576);
      if ( v21 )
        goto LABEL_9;
    }
    v25 = (unsigned int *)(unsigned int)(*(_DWORD *)(v17 + 764) + 1);
    *(_DWORD *)(v17 + 764) = (_DWORD)v25;
    dp_vdev_unref_delete(a1, v17, 0x13u, v25, v9, v10, v11, v12, v13, v14, v15, v16);
  }
  if ( is_dp_verbose_debug_enabled == 1 )
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: pkt send failed",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_tx_send_exception_vdev_id_check");
  return a3;
}
