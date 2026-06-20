__int64 __fastcall pmo_core_config_forced_dtim(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w20
  __int64 comp_private_obj; // x0
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x8
  unsigned int *v9; // x8
  unsigned int updated; // w21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v2 = *(unsigned __int8 *)(a1 + 168);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v6 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1056);
    v8 = *(_QWORD *)(v6 + 1064);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1056);
    v8 = *(_QWORD *)(v6 + 1064) | 1LL;
    *(_QWORD *)(v6 + 1064) = v8;
  }
  *(_DWORD *)(v6 + 1036) = a2;
  *(_BYTE *)(v6 + 1040) = a2 != 0;
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(v6 + 1064) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v6 + 1056);
  }
  else
  {
    raw_spin_unlock(v6 + 1056);
  }
  updated = pmo_tgt_vdev_update_param_req(a1, 2, a2);
  if ( updated )
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to set forced DTIM for vdev id %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "pmo_core_config_forced_dtim",
      v2);
  wlan_objmgr_vdev_release_ref(a1, 0xAu, v9, v11, v12, v13, v14, v15, v16, v17, v18);
  return updated;
}
