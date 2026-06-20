__int64 __fastcall wlan_green_ap_pdev_open(
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
  __int64 v9; // x20
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  unsigned __int64 StatusReg; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x0
  const char *v32; // x2
  const char *v34; // x2
  __int64 v35; // x8

  if ( !a1 )
  {
    v32 = "%s: pdev is NULL";
LABEL_13:
    qdf_trace_msg(0x5Du, 2u, v32, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_green_ap_pdev_open");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v32 = "%s: psoc is NULL";
    goto LABEL_13;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: green ap context obtained is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_green_ap_pdev_open");
    return 16;
  }
  v20 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 88);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 88);
    *(_QWORD *)(v20 + 96) |= 1uLL;
  }
  *(_BYTE *)(v20 + 8) = *(_BYTE *)(cfg_psoc_get_values(v9) + 760);
  *(_BYTE *)(v20 + 137) = *(_BYTE *)(cfg_psoc_get_values(v9) + 761);
  *(_DWORD *)(v20 + 140) = *(_DWORD *)(cfg_psoc_get_values(v9) + 764);
  *(_DWORD *)(v20 + 144) = *(_DWORD *)(cfg_psoc_get_values(v9) + 768);
  *(_DWORD *)(v20 + 148) = *(_DWORD *)(cfg_psoc_get_values(v9) + 772);
  v30 = *(_QWORD *)(a1 + 80);
  if ( !v30 )
  {
    v34 = "%s: psoc is NULL";
LABEL_17:
    qdf_trace_msg(0x5Du, 2u, v34, v22, v23, v24, v25, v26, v27, v28, v29, "wlan_green_ap_set_bcn_mult");
    goto LABEL_18;
  }
  v31 = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !v31 )
  {
    v34 = "%s: green ap context obtained is NULL";
    goto LABEL_17;
  }
  *(_DWORD *)(v31 + 104) = *(_DWORD *)(cfg_psoc_get_values(v30) + 776);
LABEL_18:
  *(_DWORD *)(v20 + 112) = 0;
  *(_DWORD *)(v20 + 108) = 1;
  v35 = *(_QWORD *)(v20 + 96);
  if ( (v35 & 1) != 0 )
  {
    *(_QWORD *)(v20 + 96) = v35 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 88);
  }
  else
  {
    raw_spin_unlock(v20 + 88);
  }
  return 0;
}
