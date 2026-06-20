__int64 __fastcall ucfg_scan_unregister_event_handler(
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 comp_private_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  unsigned int v32; // w25
  __int64 result; // x0
  int v34; // w1
  int v35; // w2
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x22
  __int64 v45; // x8
  unsigned int *v46; // x26
  unsigned __int64 StatusReg; // x8
  unsigned int v48; // w23
  __int64 v49; // x8
  const char *v50; // x24
  __int64 v51; // x10
  unsigned int *v52; // x9
  unsigned int v53; // w11
  __int64 v54; // x8
  const char *v55; // x2
  const char *v56; // x3
  unsigned int v57; // w1
  const char *v58; // x4
  __int64 v59; // x5
  const char *v60; // x2
  unsigned int v61; // w1
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x8

  qdf_trace_msg(
    0x15u,
    8u,
    "%s: pdev: %pK, event_cb: 0x%pK, arg: 0x%pK",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ucfg_scan_unregister_event_handler",
    a1,
    a2,
    a3);
  if ( !a1 )
  {
    v60 = "%s: null pdev";
    v61 = 2;
    return qdf_trace_msg(0x15u, v61, v60, v14, v15, v16, v17, v18, v19, v20, v21, "ucfg_scan_unregister_event_handler");
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( !comp_private_obj )
  {
    v55 = "%s: %s:%u, Failed to get scan object";
    v56 = "wlan_psoc_get_scan_obj_fl";
    v58 = "wlan_pdev_get_scan_obj";
    v57 = 2;
    v59 = 764;
    return qdf_trace_msg(0x15u, v57, v55, v23, v24, v25, v26, v27, v28, v29, v30, v56, v58, v59);
  }
  v31 = comp_private_obj;
  v32 = *(unsigned __int8 *)(a1 + 40);
  result = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( result )
  {
    if ( v32 >= 2 )
    {
LABEL_31:
      __break(0x5512u);
      return ucfg_scan_init_ssid_params(result, v34, v35);
    }
    else
    {
      v44 = result;
      v45 = result + 1616LL * v32;
      v46 = (unsigned int *)(v45 + 14624);
      if ( v45 != -14624 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          LODWORD(result) = raw_spin_lock(v31 + 8);
          v48 = *v46;
          if ( *v46 )
            goto LABEL_10;
        }
        else
        {
          LODWORD(result) = raw_spin_lock_bh(v31 + 8);
          *(_QWORD *)(v31 + 16) |= 1uLL;
          v48 = *v46;
          if ( *v46 )
          {
LABEL_10:
            v49 = 0;
            v50 = "not found";
            v51 = v44 + 1616LL * v32;
            while ( *(_QWORD *)(v51 + v49 + 14632) != a2 || *(_QWORD *)(v51 + v49 + 14640) != a3 )
            {
              v49 += 16;
              if ( (_DWORD)v49 == 1600 )
                goto LABEL_16;
            }
            if ( v48 >= 0x66 )
              goto LABEL_31;
            v52 = &v46[4 * --v48 + 2];
            v50 = "removed";
            *(_QWORD *)(v44 + 1616LL * v32 + v49 + 14632) = *(_QWORD *)v52;
            v53 = *v46;
            *(_QWORD *)(v44 + 1616LL * v32 + v49 + 14640) = *((_QWORD *)v52 + 1);
            *(_QWORD *)v52 = 0;
            *((_QWORD *)v52 + 1) = 0;
            *v46 = v53 - 1;
LABEL_16:
            v54 = *(_QWORD *)(v31 + 16);
            if ( (v54 & 1) != 0 )
            {
              *(_QWORD *)(v31 + 16) = v54 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v31 + 8);
            }
            else
            {
              raw_spin_unlock(v31 + 8);
            }
            v55 = "%s: event handler %s, remaining handlers: %d";
            v56 = "ucfg_scan_unregister_event_handler";
            v57 = 8;
            v58 = v50;
            v59 = v48;
            return qdf_trace_msg(0x15u, v57, v55, v23, v24, v25, v26, v27, v28, v29, v30, v56, v58, v59);
          }
        }
        v70 = *(_QWORD *)(v31 + 16);
        if ( (v70 & 1) != 0 )
        {
          *(_QWORD *)(v31 + 16) = v70 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v31 + 8);
        }
        else
        {
          raw_spin_unlock(v31 + 8);
        }
        v60 = "%s: No event handlers registered";
        v61 = 4;
        return qdf_trace_msg(
                 0x15u,
                 v61,
                 v60,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "ucfg_scan_unregister_event_handler");
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    return qdf_trace_msg(
             0x15u,
             2u,
             "%s: NULL pointer, pdev: 0x%pK, scan_obj: 0x%pK",
             v62,
             v63,
             v64,
             v65,
             v66,
             v67,
             v68,
             v69,
             "wlan_pdev_get_pdev_scan_ev_handlers",
             a1,
             0);
  }
  return result;
}
