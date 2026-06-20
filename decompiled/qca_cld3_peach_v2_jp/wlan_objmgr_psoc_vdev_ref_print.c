__int64 __fastcall wlan_objmgr_psoc_vdev_ref_print(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  unsigned int v5; // w20
  unsigned int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 1272);
    v4 = *(_QWORD *)(a2 + 1280);
  }
  else
  {
    raw_spin_lock_bh(a2 + 1272);
    v4 = *(_QWORD *)(a2 + 1280) | 1LL;
    *(_QWORD *)(a2 + 1280) = v4;
  }
  v5 = *(unsigned __int8 *)(a2 + 104);
  v6 = *(_DWORD *)(a2 + 1264);
  if ( (v4 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 1280) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 1272);
  }
  else
  {
    raw_spin_unlock(a2 + 1272);
  }
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Vdev ID is %d, state %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "wlan_objmgr_psoc_vdev_ref_print",
    v5,
    v6);
  return wlan_objmgr_print_ref_ids(a2 + 172, 1u, v15, v16, v17, v18, v19, v20, v21, v22);
}
