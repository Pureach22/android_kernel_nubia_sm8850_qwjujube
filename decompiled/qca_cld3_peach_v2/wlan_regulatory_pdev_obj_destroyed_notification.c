__int64 __fastcall wlan_regulatory_pdev_obj_destroyed_notification(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x19
  __int64 v20; // x0
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v31; // x8
  const char *v33; // x2

  if ( !a1 )
  {
    qdf_trace_msg(0x51u, 1u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "reg_get_pdev_obj");
    goto LABEL_15;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0xDu);
  if ( !comp_private_obj )
  {
LABEL_15:
    v33 = "%s: reg pdev private obj is NULL";
LABEL_18:
    qdf_trace_msg(
      0x51u,
      2u,
      v33,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_regulatory_pdev_obj_destroyed_notification");
    return 16;
  }
  v19 = (_QWORD *)comp_private_obj;
  v20 = *(_QWORD *)(a1 + 80);
  if ( !v20 )
  {
    qdf_trace_msg(0x51u, 1u, "%s: psoc is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "reg_get_psoc_obj");
    goto LABEL_17;
  }
  if ( !wlan_objmgr_psoc_get_comp_private_obj(v20, 0xDu) )
  {
LABEL_17:
    v33 = "%s: reg psoc private obj is NULL";
    goto LABEL_18;
  }
  wlan_minidump_remove(v11, v12, v13, v14, v15, v16, v17, v18, (__int64)v19, 59016, *(_QWORD *)(a1 + 80));
  v19[7091] = 0;
  v21 = wlan_objmgr_pdev_component_obj_detach(a1, 0xDu, (__int64)v19);
  if ( v21 )
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj detach failed",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_regulatory_pdev_obj_destroyed_notification");
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: reg pdev obj deleted",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wlan_regulatory_pdev_obj_destroyed_notification");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v19 + 7273);
  }
  else
  {
    raw_spin_lock_bh(v19 + 7273);
    v19[7274] |= 1uLL;
  }
  reg_reset_reg_rules((char *)v19 + 57460);
  v31 = v19[7274];
  if ( (v31 & 1) != 0 )
  {
    v19[7274] = v31 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v19 + 7273);
  }
  else
  {
    raw_spin_unlock(v19 + 7273);
  }
  _qdf_mem_free((__int64)v19);
  return v21;
}
