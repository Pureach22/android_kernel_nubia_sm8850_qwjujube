__int64 __fastcall target_if_green_ap_enable_egap(
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
  __int64 *v9; // x8
  __int64 v10; // x20
  __int64 comp_private_obj; // x0
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  const char *v24; // x2
  __int64 v25; // x8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_green_ap_enable_egap");
    return 4;
  }
  v9 = *(__int64 **)(a1 + 1240);
  if ( !v9 || (v10 = *v9) == 0 )
  {
    v24 = "%s: null wmi_hdl";
LABEL_14:
    qdf_trace_msg(0x5Du, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_green_ap_enable_egap");
    return 16;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    v24 = "%s: green ap context obtained is NULL";
    goto LABEL_14;
  }
  v12 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 88);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 88);
    *(_QWORD *)(v12 + 96) |= 1uLL;
  }
  if ( (wlan_is_egap_enabled(v12) & 1) != 0 )
  {
    v22 = *(_QWORD *)(v12 + 96);
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 96) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 88);
    }
    else
    {
      raw_spin_unlock(v12 + 88);
    }
    return wmi_unified_egap_conf_params_cmd(v10);
  }
  else
  {
    qdf_trace_msg(
      0x5Du,
      4u,
      "%s: enhanced green ap support is not present",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_green_ap_enable_egap");
    v25 = *(_QWORD *)(v12 + 96);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 96) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 88);
    }
    else
    {
      raw_spin_unlock(v12 + 88);
    }
    return 0;
  }
}
