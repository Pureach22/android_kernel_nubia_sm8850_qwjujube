__int64 __fastcall policy_mgr_update_connection_info(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned int v14; // w24
  __int64 v15; // x0
  unsigned int connection_table_entry_info; // w0
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  unsigned int v27; // w22
  unsigned int opmode_from_vdev_id; // w0
  unsigned int v29; // w23
  unsigned int v30; // w25
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _BOOL4 v47; // w26
  unsigned int v48; // w27
  bool is_24ghz_ch_freq; // w0
  unsigned __int8 *v50; // x8
  unsigned int bw; // w0
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x24
  const char *v62; // x2
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  char updated; // w0
  __int64 v72; // x1
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _BYTE v81[4]; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v82[4]; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v83; // [xsp+28h] [xbp-28h] BYREF
  __int64 v84; // [xsp+30h] [xbp-20h]
  __int64 v85; // [xsp+38h] [xbp-18h]
  int v86; // [xsp+40h] [xbp-10h]
  int v87; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v88; // [xsp+48h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82[0] = 0;
  v81[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_update_connection_info");
    result = 16;
    goto LABEL_46;
  }
  v13 = context;
  qdf_mutex_acquire(context + 56);
  if ( BYTE4(qword_81C458) != 1 )
    goto LABEL_45;
  if ( (_DWORD)qword_81C458 == a2 )
  {
    v14 = 0;
    goto LABEL_5;
  }
  if ( BYTE4(qword_81C47C) != 1 )
    goto LABEL_45;
  if ( (_DWORD)qword_81C47C == a2 )
  {
    v14 = 1;
    goto LABEL_5;
  }
  if ( BYTE4(qword_81C4A0) != 1 )
    goto LABEL_45;
  if ( (_DWORD)qword_81C4A0 == a2 )
  {
    v14 = 2;
    goto LABEL_5;
  }
  if ( BYTE4(qword_81C4C4) != 1 )
    goto LABEL_45;
  if ( (_DWORD)qword_81C4C4 == a2 )
  {
    v14 = 3;
    goto LABEL_5;
  }
  if ( BYTE4(qword_81C4E8) != 1 || (_DWORD)qword_81C4E8 != a2 )
  {
LABEL_45:
    qdf_mutex_release(v13 + 56);
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: can't find vdev_id %d in pm_conc_connection_list",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "policy_mgr_update_connection_info",
      a2);
    result = 28;
    goto LABEL_46;
  }
  v14 = 4;
LABEL_5:
  v15 = *(_QWORD *)(v13 + 8);
  v86 = 0;
  v84 = 0;
  v85 = 0;
  v83 = 0;
  connection_table_entry_info = policy_mgr_get_connection_table_entry_info(v15, a2, (__int64)&v83);
  if ( !connection_table_entry_info )
  {
    v27 = *((_DWORD *)&pm_conc_connection_list + 9 * v14 + 1);
    opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(v13 + 8), a2);
    v29 = policy_mgr_qdf_opmode_to_pm_con_mode(a1, opmode_from_vdev_id, a2);
    v30 = HIDWORD(v84);
    if ( (unsigned int)policy_mgr_get_nss_for_vdev(a1, v29, v82, v81) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Error in getting nss",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "policy_mgr_update_connection_info");
      v47 = 0;
      v48 = 0;
    }
    else
    {
      v47 = wlan_reg_is_24ghz_ch_freq(v30) && v82[0] > 1u || wlan_reg_is_5ghz_ch_freq(v30) && v81[0] > 1u;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v30);
      v50 = v81;
      if ( is_24ghz_ch_freq )
        v50 = v82;
      v48 = *v50;
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: update PM connection table for vdev:%d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "policy_mgr_update_connection_info",
      a2);
    bw = policy_mgr_get_bw((unsigned int)v85);
    policy_mgr_update_conc_list(a1, v14, v29, v30, bw, HIDWORD(v85), v47, v48, a2, 1, 1, (_WORD)v86);
    policy_mgr_dump_current_concurrency(a1);
    qdf_mutex_release(v13 + 56);
    if ( v29 <= 3 )
      policy_mgr_update_dfs_master_dynamic_enabled(a1, 0, 0);
    v87 = 0;
    v52 = policy_mgr_get_context(a1);
    if ( v52 )
    {
      v61 = v52;
      if ( !(unsigned int)policy_mgr_need_opportunistic_upgrade(a1, &v87)
        || (qdf_mc_timer_stop(v61 + 120), !(unsigned int)qdf_mc_timer_start(v61 + 120, 0x1388u)) )
      {
LABEL_31:
        if ( (policy_mgr_is_conc_sap_present_on_sta_freq(a1, v29, v27) & 1) == 0
          || (policy_mgr_update_indoor_concurrency(a1, a2, 0, 4) & 1) == 0 )
        {
          updated = policy_mgr_update_indoor_concurrency(a1, a2, v27, 3);
          v72 = *(_QWORD *)(v13 + 8);
          if ( (updated & 1) != 0 )
          {
LABEL_37:
            wlan_reg_recompute_current_chan_list(a1, v72, v63, v64, v65, v66, v67, v68, v69, v70);
LABEL_38:
            result = 0;
            goto LABEL_46;
          }
          if ( (wlan_reg_get_keep_6ghz_sta_cli_connection(*(_QWORD *)(v13 + 8), v63, v64, v65, v66, v67, v68, v69, v70)
              & 1) == 0
            || (v29 | 2) != 2 )
          {
            goto LABEL_38;
          }
        }
        v72 = *(_QWORD *)(v13 + 8);
        goto LABEL_37;
      }
      v62 = "%s: Failed to start dbs opportunistic timer";
    }
    else
    {
      v62 = "%s: PM ctx not valid. Oppurtunistic timer cannot start";
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      v62,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "policy_mgr_check_n_start_opportunistic_timer");
    goto LABEL_31;
  }
  v17 = connection_table_entry_info;
  qdf_mutex_release(v13 + 56);
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: can't find vdev_id %d in connection table",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "policy_mgr_update_connection_info",
    a2);
  result = v17;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
