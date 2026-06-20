__int64 __fastcall dp_display_process_hpd_high(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v9; // w8
  __int64 v10; // x9
  int v11; // w20
  __int64 v12; // x21
  unsigned __int64 StatusReg; // x27
  int v14; // w22
  const char *v15; // x0
  int v16; // w6
  int v17; // w7
  int v18; // w21
  int v19; // w20
  const char *v20; // x0
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w10
  __int64 (*v24)(void); // x8
  unsigned int v25; // w20
  unsigned int v26; // w0
  __int64 v27; // x8
  unsigned int v28; // w20
  __int64 v29; // x21
  int v30; // w22
  const char *v31; // x0
  int v32; // w6
  int v33; // w7
  int v34; // w21
  int v35; // w20
  const char *v36; // x0
  unsigned int v37; // w0
  void (*v38)(void); // x9
  __int64 (*v39)(void); // x9
  void (*v40)(void); // x8
  void (*v41)(void); // x8
  void (*v42)(void); // x8
  __int64 v43; // x8
  int v44; // w3
  __int64 (*v45)(void); // x8
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  unsigned __int64 v51; // x20
  __int64 v52; // x0
  __int64 (*v53)(void); // x9
  unsigned int v54; // w0
  __int64 v55; // x8
  __int64 v56; // x8
  unsigned int v57; // w21
  __int64 v58; // x22
  int v59; // w23
  const char *v60; // x0
  int v61; // w6
  int v62; // w7
  int v63; // w22
  int v64; // w21
  const char *v65; // x0
  int v66; // w2
  int v68; // w8
  void (__fastcall *v69)(__int64, __int64); // x8
  __int64 v70; // x0
  unsigned __int64 v71; // x20
  __int64 v72; // x22
  __int64 v73; // x8
  unsigned __int64 v74; // x8
  unsigned __int64 v75; // x21
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x21
  int v81; // w23
  int v82; // w22
  const char *v83; // x0
  int v84; // w6
  int v85; // w7
  __int64 v86; // x0
  int v87; // w8
  __int64 v88; // x9
  unsigned int v89; // w21
  __int64 v90; // x22
  int v91; // w23
  const char *v92; // x0
  int v93; // w20
  int v94; // w21
  int v95; // w0
  __int64 v96; // x0
  __int64 v97; // x0
  int v98; // w22
  int v99; // w21
  const char *v100; // x0
  __int64 v101; // x0
  char v102; // [xsp+0h] [xbp-20h]
  char v103; // [xsp+0h] [xbp-20h]
  char v104; // [xsp+0h] [xbp-20h]
  char v105[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v106[4]; // [xsp+10h] [xbp-10h] BYREF
  char v107[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v108; // [xsp+18h] [xbp-8h]

  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_process_hpd_high",
    1337,
    8,
    4369,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    a8,
    v102);
  mutex_lock(a1 + 1728);
  v9 = *(_DWORD *)(a1 + 12);
  if ( (v9 & 8) == 0 )
  {
    v10 = g_dp_display;
    v11 = v9 | 8;
    *(_DWORD *)(a1 + 12) = v9 | 8;
    if ( !v10 || (v12 = *(_QWORD *)(v10 + 56)) == 0 )
      v12 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = *(_DWORD *)(StatusReg + 1800);
    v15 = dp_display_state_name(v11);
    ipc_log_string(v12, "[d][%-4d]%s: state (0x%x): %s\n", v14, "add DP_STATE_CONNECTED", v11, v15);
    if ( (_drm_debug & 4) != 0 )
    {
      v18 = *(_DWORD *)(a1 + 12);
      v19 = *(_DWORD *)(StatusReg + 1800);
      v20 = dp_display_state_name(v18);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v19, "add DP_STATE_CONNECTED", v18, v20);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_process_hpd_high",
      1346,
      8,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v16,
      v17,
      v103);
    v21 = *(_QWORD *)(a1 + 136);
    v22 = *(_QWORD *)(a1 + 192);
    v23 = *(_DWORD *)(v21 + 704);
    if ( v23 >= *(_DWORD *)(v22 + 8) )
      v23 = *(_DWORD *)(v22 + 8);
    *(_DWORD *)(a1 + 1204) = v23;
    if ( (*(_BYTE *)v22 & 1) != 0 )
      goto LABEL_17;
    if ( (*(_BYTE *)(a1 + 1825) & 1) != 0 )
      goto LABEL_17;
    if ( (*(_BYTE *)(v21 + 732) & 1) != 0 )
      goto LABEL_17;
    if ( !*(_QWORD *)(a1 + 32) )
      goto LABEL_17;
    v24 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 160) + 96LL);
    if ( !v24 )
      goto LABEL_17;
    if ( *((_DWORD *)v24 - 1) != 1205381171 )
      __break(0x8228u);
    v25 = v24();
    if ( !v25 )
    {
LABEL_17:
      if ( (~*(_DWORD *)(a1 + 12) & 0x401) == 0 )
      {
        v26 = dp_display_host_init(a1);
        if ( v26 )
        {
          v25 = v26;
          if ( !g_dp_display || (v86 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v86 = 0;
          ipc_log_string(v86, "[w][%-4d]Host init Failed", *(_DWORD *)(StatusReg + 1800));
          printk(&unk_27C891, "dp_display_process_hpd_high");
          v87 = *(_DWORD *)(a1 + 12);
          if ( (v87 & 0x80) != 0 )
            goto LABEL_79;
          v88 = g_dp_display;
          v89 = v87 & 0xFFFFFF77;
          *(_DWORD *)(a1 + 12) = v87 & 0xFFFFFF77;
          if ( !v88 || (v90 = *(_QWORD *)(v88 + 56)) == 0 )
            v90 = 0;
          v91 = *(_DWORD *)(StatusReg + 1800);
          v92 = dp_display_state_name(v89);
          ipc_log_string(v90, "[d][%-4d]%s: state (0x%x): %s\n", v91, "remove DP_STATE_CONNECTED", v89, v92);
          if ( (_drm_debug & 4) != 0 )
          {
            v98 = *(_DWORD *)(a1 + 12);
            v99 = *(_DWORD *)(StatusReg + 1800);
            v100 = dp_display_state_name(v98);
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
              v99,
              "remove DP_STATE_CONNECTED",
              v98,
              v100);
          }
          v66 = 1381;
LABEL_78:
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "dp_display_process_hpd_high",
            v66,
            8,
            *(_DWORD *)(a1 + 12),
            -1059143953,
            v61,
            v62,
            v104);
LABEL_79:
          mutex_unlock(a1 + 1728);
LABEL_80:
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "dp_display_process_hpd_high",
            1459,
            8,
            8738,
            *(_DWORD *)(a1 + 12),
            v25,
            -1059143953,
            v104);
          goto LABEL_81;
        }
        v27 = g_dp_display;
        v28 = *(_DWORD *)(a1 + 12) & 0xFFFFFBFF;
        *(_DWORD *)(a1 + 12) = v28;
        if ( !v27 || (v29 = *(_QWORD *)(v27 + 56)) == 0 )
          v29 = 0;
        v30 = *(_DWORD *)(StatusReg + 1800);
        v31 = dp_display_state_name(v28);
        ipc_log_string(v29, "[d][%-4d]%s: state (0x%x): %s\n", v30, "remove DP_STATE_SRC_PWRDN", v28, v31);
        if ( (_drm_debug & 4) != 0 )
        {
          v34 = *(_DWORD *)(a1 + 12);
          v35 = *(_DWORD *)(StatusReg + 1800);
          v36 = dp_display_state_name(v34);
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
            v35,
            "remove DP_STATE_SRC_PWRDN",
            v34,
            v36);
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dp_display_process_hpd_high",
          1391,
          8,
          *(_DWORD *)(a1 + 12),
          -1059143953,
          v32,
          v33,
          v104);
      }
      v37 = dp_display_host_ready(a1);
      if ( v37 )
      {
        v25 = v37;
        if ( !g_dp_display || (v80 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v80 = 0;
        v81 = *(_DWORD *)(a1 + 12);
        v82 = *(_DWORD *)(StatusReg + 1800);
        v83 = dp_display_state_name(v81);
        ipc_log_string(v80, "[e][%-4d]%s: state (0x%x): %s\n", v82, "[ready failed]", v81, v83);
        dp_display_state_name(*(_DWORD *)(a1 + 12));
        printk(&unk_24548C, "dp_display_process_hpd_high");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dp_display_process_hpd_high",
          1396,
          8,
          *(_DWORD *)(a1 + 12),
          -1059143953,
          v84,
          v85,
          v104);
      }
      else
      {
        v38 = *(void (**)(void))(*(_QWORD *)(a1 + 168) + 192LL);
        if ( *((_DWORD *)v38 - 1) != -187382708 )
          __break(0x8229u);
        v38();
        *(_BYTE *)(*(_QWORD *)(a1 + 192) + 1LL) = 0;
        if ( *(_QWORD *)(a1 + 1184) )
        {
          v39 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 1032LL);
          if ( *((_DWORD *)v39 - 1) != -571023790 )
            __break(0x8229u);
          v25 = v39();
          if ( v25 != -110 && v25 != -107 )
          {
            if ( (unsigned int)drm_dp_lttpr_count(*(_QWORD *)(a1 + 176) + 20LL) )
            {
              v40 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 1184LL);
              if ( *((_DWORD *)v40 - 1) != 1571209182 )
                __break(0x8228u);
              v40();
            }
            v41 = *(void (**)(void))(*(_QWORD *)(a1 + 168) + 152LL);
            if ( *((_DWORD *)v41 - 1) != -1720141962 )
              __break(0x8228u);
            v41();
            v42 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 1056LL);
            if ( *((_DWORD *)v42 - 1) != -219911483 )
              __break(0x8228u);
            v42();
            v43 = *(_QWORD *)(a1 + 136);
            v105[0] = 0;
            v44 = *(unsigned __int8 *)(v43 + 724);
            if ( v44 == 1 && (*(_BYTE *)(a1 + 1833) & 1) != 0 )
            {
              v45 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 1128LL);
              if ( *((_DWORD *)v45 - 1) != -1505889699 )
                __break(0x8228u);
              if ( (v45() & 1) != 0 )
              {
                drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 + 160) + 24LL), 273, v105, 1);
                v46 = *(_QWORD *)(a1 + 160);
                v106[0] = 0;
                drm_dp_dpcd_write(*(_QWORD *)(v46 + 24), 273, v106, 1);
                if ( v105[0] )
                {
                  if ( !g_dp_display || (v47 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                    v47 = 0;
                  ipc_log_string(
                    v47,
                    "[d][%-4d]MSTM_CTRL is not cleared, wait %luus\n",
                    *(_DWORD *)(StatusReg + 1800),
                    100000);
                  if ( (_drm_debug & 4) != 0 )
                    _drm_dev_dbg(
                      0,
                      0,
                      0,
                      "[msm-dp-debug][%-4d]MSTM_CTRL is not cleared, wait %luus\n",
                      *(_DWORD *)(StatusReg + 1800),
                      100000);
                  usleep_range_state(100000, 101000, 2);
                }
                v48 = *(_QWORD *)(*(_QWORD *)(a1 + 160) + 24LL);
                v107[0] = 7;
                if ( (drm_dp_dpcd_write(v48, 273, v107, 1) & 0x80000000) != 0 )
                {
                  if ( !g_dp_display || (v101 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                    v101 = 0;
                  ipc_log_string(v101, "[e][%-4d]sink mst enablement failed\n", *(_DWORD *)(StatusReg + 1800));
                  printk(&unk_22A02F, "dp_display_mst_init");
                }
                else
                {
                  v49 = *(_QWORD *)(a1 + 176);
                  *(_BYTE *)(a1 + 1832) = 1;
                  *(_BYTE *)(v49 + 971) = 1;
                }
              }
              else
              {
                if ( !g_dp_display || (v97 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                  v97 = 0;
                ipc_log_string(v97, "[d][%-4d]sink doesn't support mst\n", *(_DWORD *)(StatusReg + 1800));
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]sink doesn't support mst\n", *(_DWORD *)(StatusReg + 1800));
              }
            }
            else
            {
              if ( !g_dp_display || (v52 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                v52 = 0;
              ipc_log_string(
                v52,
                "[d][%-4d]mst not enabled. has_mst:%d, registered:%d\n",
                *(_DWORD *)(StatusReg + 1800),
                v44,
                *(unsigned __int8 *)(a1 + 1833));
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dp-debug][%-4d]mst not enabled. has_mst:%d, registered:%d\n",
                  *(_DWORD *)(StatusReg + 1800),
                  *(unsigned __int8 *)(*(_QWORD *)(a1 + 136) + 724LL),
                  *(unsigned __int8 *)(a1 + 1833));
            }
            v53 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 184) + 16LL);
            if ( *((_DWORD *)v53 - 1) != -849684263 )
              __break(0x8229u);
            v54 = v53();
            if ( !v54 )
            {
              v68 = *(unsigned __int8 *)(a1 + 1832);
              *(_BYTE *)(a1 + 1888) = 0;
              if ( v68 == 1 )
              {
                v69 = *(void (__fastcall **)(__int64, __int64))(a1 + 1864);
                if ( v69 )
                {
                  if ( *((_DWORD *)v69 - 1) != -1297827279 )
                    __break(0x8228u);
                  v69(a1 + 1168, 1);
                }
                if ( !g_dp_display || (v70 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                  v70 = 0;
                ipc_log_string(v70, "[d][%-4d]mst_mgr_state: %d\n", *(_DWORD *)(StatusReg + 1800), 1);
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst_mgr_state: %d\n", *(_DWORD *)(StatusReg + 1800), 1);
              }
              mutex_unlock(a1 + 1728);
              v71 = 0;
              v72 = 0;
              while ( (*(_BYTE *)(a1 + 1832) & 1) != 0 || (unsigned int)work_busy(a1 + 1664) != 1 )
              {
                v73 = *(_QWORD *)(a1 + 192);
                *(_DWORD *)(a1 + 96) = 0;
                v74 = *(_QWORD *)(v73 + 152);
                if ( v74 >= 5000 - v71 )
                  v75 = 5000 - v71;
                else
                  v75 = v74;
                v76 = _msecs_to_jiffies((unsigned int)v75);
                v77 = wait_for_completion_timeout(a1 + 96, v76);
                if ( v77 )
                  v78 = v77;
                else
                  v78 = v75;
                v71 += v78;
                if ( v75 < v71 )
                {
                  v72 = v77;
                  if ( v71 >> 3 < 0x271 )
                    continue;
                }
                if ( !g_dp_display || (v79 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                  v79 = 0;
                ipc_log_string(
                  v79,
                  "[d][%-4d]wait_timeout=%lu ms, time_waited=%lu ms\n",
                  *(_DWORD *)(StatusReg + 1800),
                  v75,
                  v71);
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "[msm-dp-debug][%-4d]wait_timeout=%lu ms, time_waited=%lu ms\n",
                    *(_DWORD *)(StatusReg + 1800),
                    v75,
                    v71);
                if ( (*(_BYTE *)(a1 + 13) & 1) == 0 )
                {
                  dp_display_send_hpd_notification(a1);
                  v25 = 0;
                  goto LABEL_80;
                }
                goto LABEL_128;
              }
              v93 = sde_dbg_base_evtlog;
              v94 = *(_DWORD *)(a1 + 12);
              v95 = jiffies_to_msecs(v72);
              sde_evtlog_log(v93, "dp_display_hpd_irq_pending", 1306, 8, v94, 99, v95, -1059143953, v104);
              if ( !g_dp_display || (v96 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                v96 = 0;
              ipc_log_string(v96, "[d][%-4d]Attention pending, skip HPD notification\n", *(_DWORD *)(StatusReg + 1800));
              if ( (_drm_debug & 4) == 0 )
              {
LABEL_128:
                v25 = 0;
                goto LABEL_80;
              }
              _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]Attention pending, skip HPD notification\n",
                *(_DWORD *)(StatusReg + 1800));
              v25 = 0;
              goto LABEL_80;
            }
            v55 = *(_QWORD *)(a1 + 176);
            v25 = v54;
            *(_BYTE *)(a1 + 1832) = 0;
            *(_BYTE *)(v55 + 971) = 0;
          }
        }
        else
        {
          v25 = 0;
        }
        dp_display_host_unready(a1);
      }
    }
    v56 = g_dp_display;
    v57 = *(_DWORD *)(a1 + 12) & 0xFFFFFFF7;
    *(_DWORD *)(a1 + 12) = v57;
    if ( !v56 || (v58 = *(_QWORD *)(v56 + 56)) == 0 )
      v58 = 0;
    v59 = *(_DWORD *)(StatusReg + 1800);
    v60 = dp_display_state_name(v57);
    ipc_log_string(v58, "[d][%-4d]%s: state (0x%x): %s\n", v59, "remove DP_STATE_CONNECTED", v57, v60);
    if ( (_drm_debug & 4) != 0 )
    {
      v63 = *(_DWORD *)(a1 + 12);
      v64 = *(_DWORD *)(StatusReg + 1800);
      v65 = dp_display_state_name(v63);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v64, "remove DP_STATE_CONNECTED", v63, v65);
    }
    v66 = 1455;
    goto LABEL_78;
  }
  if ( !g_dp_display || (v50 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v50 = 0;
  v51 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v50, "[d][%-4d]dp already connected, skipping hpd high\n", *(_DWORD *)(v51 + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp already connected, skipping hpd high\n", *(_DWORD *)(v51 + 1800));
  mutex_unlock(a1 + 1728);
  v25 = -106;
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return v25;
}
