__int64 __fastcall pmo_core_get_mc_addr_list_count(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 comp_private_obj; // x0
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  unsigned int v16; // w21
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
  if ( !v2 )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: vdev is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "pmo_core_get_mc_addr_list_count");
    return (unsigned int)-1;
  }
  v11 = v2;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v2, 4u);
  v13 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v15 = *(_QWORD *)(v13 + 1064) | 1LL;
      *(_QWORD *)(v13 + 1064) = v15;
      v16 = *(unsigned __int8 *)(v13 + 673);
      if ( (v15 & 1) == 0 )
        goto LABEL_6;
LABEL_11:
      *(_QWORD *)(v13 + 1064) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 1056);
      goto LABEL_7;
    }
  }
  raw_spin_lock(comp_private_obj + 1056);
  v15 = *(_QWORD *)(v13 + 1064);
  v16 = *(unsigned __int8 *)(v13 + 673);
  if ( (v15 & 1) != 0 )
    goto LABEL_11;
LABEL_6:
  raw_spin_unlock(v13 + 1056);
LABEL_7:
  wlan_objmgr_vdev_release_ref(v11, 0xAu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  return v16;
}
