__int64 __fastcall wlan_objmgr_pdev_obj_delete(
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

  if ( a1 )
  {
    qdf_trace_msg(
      0x57u,
      8u,
      "%s: Logically deleting pdev %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_objmgr_pdev_obj_delete",
      *(unsigned __int8 *)(a1 + 40));
    qdf_get_pidx();
    wlan_objmgr_print_ref_ids(a1 + 92, 8u, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1248);
      v19 = *(_QWORD *)(a1 + 1256);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1248);
      v19 = *(_QWORD *)(a1 + 1256) | 1LL;
      *(_QWORD *)(a1 + 1256) = v19;
    }
    *(_DWORD *)(a1 + 1232) = 6;
    if ( (v19 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
    wlan_objmgr_pdev_release_ref(a1, 0);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_pdev_obj_delete");
    return 16;
  }
}
