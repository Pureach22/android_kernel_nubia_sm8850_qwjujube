__int64 __fastcall drv_cmd_set_suspend_mode(
        unsigned __int8 *a1,
        _QWORD *a2,
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
  __int64 v11; // x22
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  char is_configure_apf_per_screen_state; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  unsigned int v42; // w1
  __int64 vdev_by_user; // x0
  __int64 v44; // x21
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char v53; // w8
  _BYTE v54[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)a1;
  v54[0] = 0;
  if ( !*(_DWORD *)(v11 + 40) )
  {
    if ( (kstrtou8(a3 + 15, 10, v54) & 0x80000000) != 0 )
    {
      v41 = "%s: Range validation failed";
    }
    else
    {
      v23 = v54[0];
      is_configure_apf_per_screen_state = ucfg_pmo_is_configure_apf_per_screen_state(*a2);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: idle_monitor:%d, configure apf per screen state = %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "drv_cmd_set_suspend_mode",
        v23,
        is_configure_apf_per_screen_state & 1);
      if ( (sme_get_dhcp_status(a2[2], a1[8]) & 1) != 0 )
      {
        qdf_trace_msg(0x33u, 8u, "DHCP in progress. Ignore SETSUSPEND command", v33, v34, v35, v36, v37, v38, v39, v40);
        result = 0;
        goto LABEL_21;
      }
      if ( (ucfg_pmo_is_configure_apf_per_screen_state(*a2) & 1) == 0 )
        goto LABEL_18;
      if ( v54[0] != 1 )
      {
        if ( !v54[0] )
        {
          sme_disable_active_apf_mode_ind(
            *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL),
            *(unsigned int *)(*(_QWORD *)a1 + 40LL),
            *(_QWORD *)a1 + 1617LL,
            a1[8]);
          *(_BYTE *)(v11 + 71201) = 0;
        }
LABEL_18:
        result = ucfg_pmo_tgt_psoc_send_idle_roam_suspend_mode(*a2, v54[0]);
        if ( !(_DWORD)result )
          goto LABEL_21;
        v41 = "%s: Send suspend mode to fw failed";
        v42 = 8;
LABEL_20:
        qdf_trace_msg(0x33u, v42, v41, v15, v16, v17, v18, v19, v20, v21, v22, "drv_cmd_set_suspend_mode");
        result = 4294967274LL;
        goto LABEL_21;
      }
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "drv_cmd_set_suspend_mode");
      if ( vdev_by_user )
      {
        v44 = vdev_by_user;
        if ( ucfg_cm_is_vdev_connected(vdev_by_user, v15, v16, v17, v18, v19, v20, v21, v22) )
        {
          sme_enable_active_apf_mode_ind(
            *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL),
            *(unsigned int *)(*(_QWORD *)a1 + 40LL),
            *(_QWORD *)a1 + 1617LL,
            a1[8]);
          v53 = 0;
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev:%d not in connected state",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "drv_cmd_set_suspend_mode",
            a1[8]);
          v53 = 1;
        }
        *(_BYTE *)(v11 + 71201) = v53;
        _hdd_objmgr_put_vdev_by_user(v44, 6, "drv_cmd_set_suspend_mode");
        goto LABEL_18;
      }
      v41 = "%s: vdev is NULL";
    }
    v42 = 2;
    goto LABEL_20;
  }
  qdf_trace_msg(0x33u, 8u, "%s: Non-STA interface", a4, a5, a6, a7, a8, a9, a10, a11, "drv_cmd_set_suspend_mode");
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
