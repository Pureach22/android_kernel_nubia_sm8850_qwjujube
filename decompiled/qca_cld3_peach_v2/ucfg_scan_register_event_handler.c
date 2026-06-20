__int64 __fastcall ucfg_scan_register_event_handler(
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
  __int64 comp_private_obj; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w24
  __int64 v24; // x0
  __int64 v25; // x7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x23
  __int64 v35; // x8
  _DWORD *v36; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x9
  __int64 v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 *v69; // x8
  __int64 v70; // x8

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: pdev: %pK, event_cb: %pK",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_scan_register_event_handler",
      a1,
      a2);
    return 29;
  }
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: pdev: %pK, event_cb: %pK, arg: %pK\n",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ucfg_scan_register_event_handler",
    a1,
    a2,
    a3);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( !comp_private_obj )
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
  v23 = *(unsigned __int8 *)(a1 + 40);
  v24 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( !v24 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: NULL pointer, pdev: 0x%pK, scan_obj: 0x%pK",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wlan_pdev_get_pdev_scan_ev_handlers",
      a1,
      0);
    goto LABEL_21;
  }
  if ( v23 < 2 )
  {
    v34 = v24;
    v35 = v24 + 1616LL * v23;
    v36 = (_DWORD *)(v35 + 14624);
    if ( v35 != -14624 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 8);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 8);
        *(_QWORD *)(comp_private_obj + 16) |= 1uLL;
      }
      v38 = 0;
      v39 = v34 + 1616LL * v23;
      while ( *(_QWORD *)(v39 + v38 + 14632) != a2 || *(_QWORD *)(v39 + v38 + 14640) != a3 )
      {
        v38 += 16;
        if ( (_DWORD)v38 == 1600 )
        {
          v59 = (unsigned int)*v36;
          if ( (unsigned int)v59 >= 0x64 )
          {
            v60 = *(_QWORD *)(comp_private_obj + 16);
            if ( (v60 & 1) != 0 )
            {
              *(_QWORD *)(comp_private_obj + 16) = v60 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(comp_private_obj + 8);
            }
            else
            {
              raw_spin_unlock(comp_private_obj + 8);
            }
            qdf_trace_msg(
              0x15u,
              3u,
              "%s: No more registrations possible",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "ucfg_scan_register_event_handler");
            return 2;
          }
          v69 = (__int64 *)&v36[4 * v59 + 2];
          *v36 = v59 + 1;
          *v69 = a2;
          v69[1] = a3;
          v70 = *(_QWORD *)(comp_private_obj + 16);
          if ( (v70 & 1) != 0 )
          {
            *(_QWORD *)(comp_private_obj + 16) = v70 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(comp_private_obj + 8);
          }
          else
          {
            raw_spin_unlock(comp_private_obj + 8);
          }
          v49 = "%s: event_cb: 0x%pK, arg: 0x%pK";
LABEL_29:
          qdf_trace_msg(
            0x15u,
            8u,
            v49,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "ucfg_scan_register_event_handler",
            a2,
            a3);
          return 0;
        }
      }
      v40 = *(_QWORD *)(comp_private_obj + 16);
      if ( (v40 & 1) != 0 )
      {
        *(_QWORD *)(comp_private_obj + 16) = v40 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(comp_private_obj + 8);
      }
      else
      {
        raw_spin_unlock(comp_private_obj + 8);
      }
      v49 = "%s: func: %pK, arg: %pK already exists";
      goto LABEL_29;
    }
LABEL_21:
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: null pdev_ev_handler",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ucfg_scan_register_event_handler");
    return 29;
  }
  __break(0x5512u);
  if ( !v25 )
    JUMPOUT(0x12A35C);
  return ucfg_scan_unregister_event_handler();
}
