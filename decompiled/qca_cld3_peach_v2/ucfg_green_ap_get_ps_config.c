__int64 __fastcall ucfg_green_ap_get_ps_config(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
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
  __int64 v30; // x8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
    if ( comp_private_obj )
    {
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
      if ( !wlan_is_egap_enabled(v20, v22, v23, v24, v25, v26, v27, v28, v29) )
        *a2 = *(_BYTE *)(v20 + 8);
      v30 = *(_QWORD *)(v20 + 96);
      if ( (v30 & 1) != 0 )
      {
        *(_QWORD *)(v20 + 96) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v20 + 88);
      }
      else
      {
        raw_spin_unlock(v20 + 88);
      }
      return 0;
    }
    else
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
        "ucfg_green_ap_get_ps_config");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_green_ap_get_ps_config");
    return 4;
  }
}
