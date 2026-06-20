__int64 __fastcall lim_objmgr_update_vdev_nss(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 cmpt_obj; // x0
  __int64 v25; // x8
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 7);
  if ( !v5 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: vdev not found for id: %d",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "lim_objmgr_update_vdev_nss",
             v4);
  v14 = v5;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v5 + 1344);
  }
  else
  {
    raw_spin_lock_bh(v5 + 1344);
    *(_QWORD *)(v14 + 1352) |= 1uLL;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v14, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( cmpt_obj )
    *(_BYTE *)(cmpt_obj + 23) = a3;
  v25 = *(_QWORD *)(v14 + 1352);
  if ( (v25 & 1) != 0 )
  {
    *(_QWORD *)(v14 + 1352) = v25 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v14 + 1344);
  }
  else
  {
    raw_spin_unlock(v14 + 1344);
  }
  return wlan_objmgr_vdev_release_ref(v14, 7u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
}
