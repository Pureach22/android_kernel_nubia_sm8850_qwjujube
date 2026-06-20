__int64 __fastcall wlan_objmgr_vdev_obj_delete(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x8
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a1 )
  {
    qdf_trace_msg(
      0x57u,
      8u,
      "%s: Logically deleting vdev %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_objmgr_vdev_obj_delete",
      *(unsigned __int8 *)(a1 + 168));
    qdf_get_pidx();
    wlan_objmgr_print_ref_ids(a1 + 244, 8u, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1344);
      v19 = *(_QWORD *)(a1 + 1352);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1344);
      v19 = *(_QWORD *)(a1 + 1352) | 1LL;
      *(_QWORD *)(a1 + 1352) = v19;
    }
    *(_DWORD *)(a1 + 1336) = 6;
    if ( (v19 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    wlan_objmgr_vdev_release_ref(a1, 0, v20, v21, v22, v23, v24, v25, v26, v27, v28);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: vdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_vdev_obj_delete");
    return 16;
  }
}
