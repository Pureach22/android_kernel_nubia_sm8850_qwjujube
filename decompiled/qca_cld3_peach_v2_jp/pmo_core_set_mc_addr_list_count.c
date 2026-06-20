__int64 __fastcall pmo_core_set_mc_addr_list_count(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 comp_private_obj; // x0
  __int64 v15; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v17; // x8
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
  if ( v4 )
  {
    v13 = v4;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 4u);
    v15 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      v17 = *(_QWORD *)(v15 + 1064);
      *(_BYTE *)(v15 + 673) = a3;
      if ( (v17 & 1) == 0 )
      {
LABEL_6:
        raw_spin_unlock(v15 + 1056);
        return wlan_objmgr_vdev_release_ref(v13, 0xAu, v18, v19, v20, v21, v22, v23, v24, v25, v26);
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v17 = *(_QWORD *)(v15 + 1064) | 1LL;
      *(_QWORD *)(v15 + 1064) = v17;
      *(_BYTE *)(v15 + 673) = a3;
      if ( (v17 & 1) == 0 )
        goto LABEL_6;
    }
    *(_QWORD *)(v15 + 1064) = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v15 + 1056);
    return wlan_objmgr_vdev_release_ref(v13, 0xAu, v18, v19, v20, v21, v22, v23, v24, v25, v26);
  }
  return qdf_trace_msg(
           0x4Du,
           2u,
           "%s: vdev is NULL",
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           "pmo_core_set_mc_addr_list_count");
}
