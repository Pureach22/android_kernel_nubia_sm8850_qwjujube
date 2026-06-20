__int64 __fastcall ucfg_scan_register_pno_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v34; // x2

  if ( !a1 )
  {
    v34 = "%s: null psoc";
LABEL_12:
    qdf_trace_msg(0x15u, 2u, v34, a4, a5, a6, a7, a8, a9, a10, a11, "ucfg_scan_register_pno_cb");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_register_pno_cb",
      375);
    v34 = "%s: scan object null";
    goto LABEL_12;
  }
  v22 = (_QWORD *)comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 8);
    v24 = v22[2];
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 8);
    v24 = v22[2] | 1LL;
    v22[2] = v24;
  }
  v22[2324] = a2;
  v22[2325] = a3;
  if ( (v24 & 1) != 0 )
  {
    v22[2] = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v22 + 1);
  }
  else
  {
    raw_spin_unlock(v22 + 1);
  }
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: event_cb: 0x%pK, arg: 0x%pK",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "ucfg_scan_register_pno_cb",
    a2,
    a3);
  return 0;
}
