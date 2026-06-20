__int64 __fastcall dp_display_hdcp_cb_work(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  _DWORD *v8; // x28
  int v9; // w8
  bool v10; // zf
  _BYTE *v11; // x19
  __int64 v12; // x26
  __int64 v13; // x8
  void (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  int v16; // w6
  int v17; // w7
  _BYTE *v18; // x22
  _BYTE *v19; // x27
  __int64 v20; // x8
  __int64 (__fastcall *v21)(_QWORD); // x9
  unsigned int v22; // w0
  int v23; // w21
  __int64 v24; // x0
  unsigned __int64 v25; // x20
  __int64 v26; // x20
  __int64 v27; // x0
  __int64 v28; // x8
  unsigned __int64 v29; // x21
  const char *v30; // x3
  __int64 v31; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v33; // x0
  unsigned __int64 v34; // x20
  __int64 v35; // x8
  const char *v36; // x4
  __int64 v37; // x8
  const char *v38; // x5
  __int64 v39; // x0
  unsigned __int64 v40; // x20
  _DWORD *v41; // x20
  __int64 v42; // x21
  __int64 v43; // x23
  unsigned int (__fastcall *v44)(__int64, __int64); // x8
  __int64 v45; // x1
  __int64 v46; // x0
  __int64 v47; // x21
  __int64 v48; // x23
  unsigned int (__fastcall *v49)(__int64, __int64); // x8
  __int64 v50; // x1
  __int64 v51; // x0
  __int64 v52; // x21
  __int64 v53; // x23
  unsigned int (__fastcall *v54)(__int64, __int64); // x8
  __int64 v55; // x1
  __int64 v56; // x0
  __int64 v57; // x21
  __int64 v58; // x23
  unsigned int (__fastcall *v59)(__int64, __int64); // x8
  __int64 v60; // x1
  __int64 v61; // x0
  __int64 *v62; // x20
  _BYTE *v63; // x8
  _BYTE *v64; // x23
  int v65; // w8
  __int64 v66; // x24
  __int64 v67; // x21
  __int64 (__fastcall *v68)(_QWORD); // x8
  __int64 v69; // x8
  __int64 v70; // x8
  const char *v71; // x6
  __int64 v72; // x20
  __int64 v73; // x11
  __int64 v74; // x25
  int v75; // w8
  int v76; // w22
  __int64 v77; // x9
  void (__fastcall *v78)(__int64, __int64); // x9
  __int64 v79; // x22
  __int64 v80; // x9
  __int64 v81; // x23
  int v82; // w24
  char v83; // w8
  unsigned __int64 v84; // x8
  unsigned __int64 v85; // x27
  __int64 (__fastcall *v86)(_QWORD); // x8
  __int64 v87; // x8
  __int64 v88; // x0
  unsigned int (__fastcall *v89)(_QWORD); // x8
  __int64 v90; // x19
  __int64 (__fastcall *v91)(_QWORD); // x8
  int v92; // w19
  __int64 v93; // x0
  __int64 (__fastcall *v94)(_QWORD); // x8
  __int64 v95; // x9
  int v96; // w8
  __int64 v97; // x0
  __int64 v98; // x8
  unsigned __int64 v99; // x21
  __int64 v100; // x8
  const char *v101; // x3
  __int64 v102; // x8
  const char *v103; // x5
  unsigned int (__fastcall *v104)(_QWORD); // x8
  __int64 v105; // x0
  __int64 (__fastcall *v106)(_QWORD); // x8
  __int64 (__fastcall *v107)(_QWORD); // x8
  __int64 (__fastcall *v108)(_QWORD); // x8
  __int64 (__fastcall *v109)(_QWORD); // x8
  char v110; // [xsp+0h] [xbp-50h]
  char v111; // [xsp+0h] [xbp-50h]
  char v112; // [xsp+0h] [xbp-50h]
  __int64 v113; // [xsp+8h] [xbp-48h]
  _BYTE *v114; // [xsp+38h] [xbp-18h]
  _BYTE v115[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v116; // [xsp+48h] [xbp-8h]

  v8 = (_DWORD *)(result - 1516);
  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(result - 1516);
  v10 = (v9 & 0x48) != 0 && (*(_DWORD *)(result - 1516) & 0x300) == 0;
  if ( !v10 )
    goto LABEL_37;
  v11 = (_BYTE *)result;
  if ( (v9 & 0x80) != 0 )
  {
    if ( !g_dp_display || (v31 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v31 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v31, "[d][%-4d]System suspending. Delay HDCP operations\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]System suspending. Delay HDCP operations\n",
        *(unsigned int *)(StatusReg + 1800));
    goto LABEL_36;
  }
  v12 = result - 1528;
  if ( *(_BYTE *)(result + 296) == 1 )
  {
    v13 = *(_QWORD *)(result - 1296);
    if ( v13 )
    {
      v14 = *(void (__fastcall **)(_QWORD))(v13 + 80);
      if ( v14 )
      {
        v15 = *(_QWORD *)(result - 1304);
        if ( *((_DWORD *)v14 - 1) != 251140989 )
          __break(0x8228u);
        v14(v15);
      }
    }
    dp_display_update_hdcp_status((__int64)(v11 - 1528), 1);
    v11[296] = 0;
  }
  v115[0] = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_hdcp_process_sink_sync", 503, 8, 4369, -1059143953, a7, a8, v110);
  v18 = v11 - 1336;
  if ( *(_BYTE *)(*((_QWORD *)v11 - 167) + 3LL) == 1 )
  {
    drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)v11 - 171) + 24LL), 517, v115, 1);
    v10 = (v115[0] & 3) == 0;
    v115[0] &= 3u;
    if ( !v10 )
    {
      msleep(6000);
      goto LABEL_17;
    }
    if ( !g_dp_display || (v39 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v39 = 0;
    v40 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v39, "[d][%-4d]Sink not synchronized. Queuing again then exiting\n", *(_DWORD *)(v40 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]Sink not synchronized. Queuing again then exiting\n",
        *(unsigned int *)(v40 + 1800));
LABEL_36:
    result = queue_delayed_work_on(32, *((_QWORD *)v11 - 1), v11, 250);
    goto LABEL_37;
  }
LABEL_17:
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_hdcp_process_sink_sync", 522, 8, 8738, -1059143953, v16, v17, v111);
  v19 = v11 - 1360;
  if ( *(_DWORD *)(*((_QWORD *)v11 - 170) + 136LL) )
    goto LABEL_18;
  if ( (*(_BYTE *)(*(_QWORD *)v18 + 2LL) & 1) != 0 )
  {
    if ( !g_dp_display || (v33 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v33 = 0;
    v34 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v33, "[d][%-4d]hdcp disabled\n", *(_DWORD *)(v34 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]hdcp disabled\n", *(_DWORD *)(v34 + 1800));
  }
  else
  {
    v41 = v11 - 1288;
    v42 = *((_QWORD *)v11 - 160);
    if ( v42 )
    {
      v43 = *((_QWORD *)v11 - 159);
      if ( v43 )
      {
        v44 = *(unsigned int (__fastcall **)(__int64, __int64))(v43 + 64);
        if ( !v44 )
          goto LABEL_199;
        v45 = (unsigned __int8)v11[304];
        v46 = *((_QWORD *)v11 - 160);
        if ( *((_DWORD *)v44 - 1) != -1297827279 )
          __break(0x8228u);
        if ( !v44(v46, v45) )
        {
LABEL_199:
          if ( (*((_DWORD *)v11 - 316) & *v41) == 0 )
          {
            v106 = *(__int64 (__fastcall **)(_QWORD))(v43 + 32);
            if ( v106 )
            {
              if ( *((_DWORD *)v106 - 1) != -2091637267 )
                __break(0x8228u);
              if ( (v106(v42) & 1) != 0 )
                *v41 |= *((_DWORD *)v11 - 316);
            }
          }
        }
      }
    }
    v47 = *((_QWORD *)v11 - 157);
    if ( v47 )
    {
      v48 = *((_QWORD *)v11 - 156);
      if ( v48 )
      {
        v49 = *(unsigned int (__fastcall **)(__int64, __int64))(v48 + 64);
        if ( !v49 )
          goto LABEL_200;
        v50 = (unsigned __int8)v11[304];
        v51 = *((_QWORD *)v11 - 157);
        if ( *((_DWORD *)v49 - 1) != -1297827279 )
          __break(0x8228u);
        if ( !v49(v51, v50) )
        {
LABEL_200:
          if ( (*((_DWORD *)v11 - 310) & *v41) == 0 )
          {
            v107 = *(__int64 (__fastcall **)(_QWORD))(v48 + 32);
            if ( v107 )
            {
              if ( *((_DWORD *)v107 - 1) != -2091637267 )
                __break(0x8228u);
              if ( (v107(v47) & 1) != 0 )
                *v41 |= *((_DWORD *)v11 - 310);
            }
          }
        }
      }
    }
    v52 = *((_QWORD *)v11 - 154);
    if ( v52 )
    {
      v53 = *((_QWORD *)v11 - 153);
      if ( v53 )
      {
        v54 = *(unsigned int (__fastcall **)(__int64, __int64))(v53 + 64);
        if ( !v54 )
          goto LABEL_201;
        v55 = (unsigned __int8)v11[304];
        v56 = *((_QWORD *)v11 - 154);
        if ( *((_DWORD *)v54 - 1) != -1297827279 )
          __break(0x8228u);
        if ( !v54(v56, v55) )
        {
LABEL_201:
          if ( (*((_DWORD *)v11 - 304) & *v41) == 0 )
          {
            v108 = *(__int64 (__fastcall **)(_QWORD))(v53 + 32);
            if ( v108 )
            {
              if ( *((_DWORD *)v108 - 1) != -2091637267 )
                __break(0x8228u);
              if ( (v108(v52) & 1) != 0 )
                *v41 |= *((_DWORD *)v11 - 304);
            }
          }
        }
      }
    }
    v57 = *((_QWORD *)v11 - 151);
    if ( v57 )
    {
      v58 = *((_QWORD *)v11 - 150);
      if ( v58 )
      {
        v59 = *(unsigned int (__fastcall **)(__int64, __int64))(v58 + 64);
        if ( !v59 )
          goto LABEL_202;
        v60 = (unsigned __int8)v11[304];
        v61 = *((_QWORD *)v11 - 151);
        if ( *((_DWORD *)v59 - 1) != -1297827279 )
          __break(0x8228u);
        if ( !v59(v61, v60) )
        {
LABEL_202:
          if ( (*((_DWORD *)v11 - 298) & *v41) == 0 )
          {
            v109 = *(__int64 (__fastcall **)(_QWORD))(v58 + 32);
            if ( v109 )
            {
              if ( *((_DWORD *)v109 - 1) != -2091637267 )
                __break(0x8228u);
              if ( (v109(v57) & 1) != 0 )
                *v41 |= *((_DWORD *)v11 - 298);
            }
          }
        }
      }
    }
    dp_display_update_hdcp_status((__int64)(v11 - 1528), 0);
  }
  dp_display_update_hdcp_status((__int64)(v11 - 1528), 1);
  v62 = (__int64 *)(v11 - 1304);
  v63 = *(_BYTE **)v18;
  v64 = v11 - 1296;
  *v62 = 0;
  v62[1] = 0;
  if ( (v63[2] & 1) == 0 && (*v63 & 1) == 0 )
  {
    v65 = *((_DWORD *)v11 - 322);
    if ( (*((_DWORD *)v11 - 304) & v65) != 0 )
    {
      v66 = *((_QWORD *)v11 - 153);
      v67 = *((_QWORD *)v11 - 154);
      v68 = *(__int64 (__fastcall **)(_QWORD))(v66 + 48);
      if ( *((_DWORD *)v68 - 1) != -2091637267 )
        __break(0x8228u);
      if ( (v68(v67) & 1) != 0 )
      {
        v69 = 296;
        goto LABEL_156;
      }
      v65 = *((_DWORD *)v11 - 322);
    }
    if ( (*((_DWORD *)v11 - 310) & v65) == 0 )
      goto LABEL_157;
    v66 = *((_QWORD *)v11 - 156);
    v67 = *((_QWORD *)v11 - 157);
    v94 = *(__int64 (__fastcall **)(_QWORD))(v66 + 48);
    if ( *((_DWORD *)v94 - 1) != -2091637267 )
      __break(0x8228u);
    if ( (v94(v67) & 1) == 0 )
      goto LABEL_157;
    v69 = 272;
LABEL_156:
    v95 = *(_QWORD *)v19;
    *v62 = v67;
    v96 = *(_DWORD *)(v12 + v69 + 16);
    *(_QWORD *)v64 = v66;
    *(_DWORD *)(v95 + 140) = v96;
LABEL_157:
    if ( !g_dp_display || (v97 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v97 = 0;
    v98 = *(_QWORD *)v19;
    v99 = _ReadStatusReg(SP_EL0);
    v100 = *(unsigned int *)(v98 + 140);
    if ( (unsigned int)v100 > 2 )
      v101 = "???";
    else
      v101 = off_283770[v100];
    ipc_log_string(v97, "[d][%-4d]HDCP version supported: %s\n", *(_DWORD *)(v99 + 1800), v101);
    if ( (_drm_debug & 4) != 0 )
    {
      v102 = *(unsigned int *)(*(_QWORD *)v19 + 140LL);
      if ( (unsigned int)v102 > 2 )
        v103 = "???";
      else
        v103 = off_283770[v102];
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]HDCP version supported: %s\n", *(_DWORD *)(v99 + 1800), v103);
    }
  }
  if ( !*(_DWORD *)(*(_QWORD *)v19 + 140LL) || !*(_QWORD *)v64 )
    goto LABEL_174;
  v104 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)v64 + 72LL);
  if ( v104 )
  {
    v105 = *v62;
    if ( *((_DWORD *)v104 - 1) != -1066802076 )
      __break(0x8228u);
    if ( v104(v105) )
      goto LABEL_174;
  }
LABEL_18:
  v20 = *((_QWORD *)v11 - 172);
  v21 = *(__int64 (__fastcall **)(_QWORD))(v20 + 256);
  if ( *((_DWORD *)v21 - 1) != -618841677 )
    __break(0x8229u);
  v22 = v21(v20 + 88);
  if ( (v22 & 0x80000000) == 0 )
  {
    v23 = (v22 >> 20) & 3;
    if ( !g_dp_display || (v24 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v24 = 0;
    v25 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v24, "[d][%-4d]hdcp auth state %d\n", *(_DWORD *)(v25 + 1800), v23);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]hdcp auth state %d\n", *(_DWORD *)(v25 + 1800), v23);
  }
  v26 = *(_QWORD *)v19;
  if ( !g_dp_display || (v27 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v27 = 0;
  v28 = *(unsigned int *)(v26 + 140);
  v29 = _ReadStatusReg(SP_EL0);
  if ( (unsigned int)v28 > 2 )
    v30 = "???";
  else
    v30 = off_283770[v28];
  v35 = *(unsigned int *)(v26 + 136);
  if ( (unsigned int)v35 > 3 )
    v36 = "???";
  else
    v36 = off_283788[v35];
  ipc_log_string(v27, "[d][%-4d]%s: %s\n", *(_DWORD *)(v29 + 1800), v30, v36);
  if ( (_drm_debug & 4) != 0 )
  {
    v37 = *(unsigned int *)(v26 + 140);
    if ( (unsigned int)v37 > 2 )
      v38 = "???";
    else
      v38 = off_283770[v37];
    v70 = *(unsigned int *)(v26 + 136);
    if ( (unsigned int)v70 > 3 )
      v71 = "???";
    else
      v71 = off_283788[v70];
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: %s\n", *(_DWORD *)(v29 + 1800), v38, v71);
  }
  dp_display_update_hdcp_status((__int64)(v11 - 1528), 0);
  v72 = *(_QWORD *)v19;
  v73 = *((_QWORD *)v11 - 162);
  v74 = *((_QWORD *)v11 - 163);
  v114 = v11 - 1296;
  v75 = *(_DWORD *)(*(_QWORD *)v19 + 136LL);
  if ( v75 == 2 )
  {
    v76 = 0;
  }
  else
  {
    v77 = *(_QWORD *)v18;
    v76 = 1;
    if ( *(_BYTE *)(v77 + 12) == 1 )
    {
      if ( v73 )
      {
        v78 = *(void (__fastcall **)(__int64, __int64))(v73 + 40);
        if ( v78 )
        {
          v79 = *((_QWORD *)v11 - 162);
          if ( *((_DWORD *)v78 - 1) != -538254584 )
            __break(0x8229u);
          v78(v74, 1);
          v75 = *(_DWORD *)(v72 + 136);
          v73 = v79;
          v76 = v75 != 2;
        }
      }
    }
  }
  v80 = *((_QWORD *)v11 - 174);
  v81 = *(unsigned int *)(v80 + 752);
  if ( (_DWORD)v81 && (unsigned __int8)v11[2928] != v76 )
  {
    v82 = *(_DWORD *)(v80 + 760);
    v113 = v73;
    v83 = 0;
    do
    {
      v84 = (-1LL << v83) & v81;
      if ( !v84 )
        break;
      v85 = __clz(__rbit64(v84));
      if ( get_cpu_device((unsigned int)v85) )
      {
        if ( v76 )
          dev_pm_qos_add_request();
        else
          dev_pm_qos_remove_request(&v11[80 * (unsigned int)v85 + 368]);
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "%s: failed to get cpu%d device\n", "dp_display_qos_request", v85);
      }
      v83 = v85 + 1;
    }
    while ( v85 < 0x1F );
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_qos_request", 359, 8, v76, v81, v82, -1059143953, v112);
    v11[2928] = v76;
    v73 = v113;
    v12 = (__int64)(v11 - 1528);
    v19 = v11 - 1360;
    v75 = *(_DWORD *)(v72 + 136);
  }
  if ( v75 == 3 )
  {
    v87 = *((_QWORD *)v11 - 175);
    if ( *(_BYTE *)(v87 + 8) != 1
      || (*v8 & 8) == 0
      || (*(_BYTE *)(*((_QWORD *)v11 - 169) + 5LL) & 1) != 0 && !*(_DWORD *)(*(_QWORD *)v19 + 8LL)
      || (*v8 & 0x40) == 0
      || (*(_BYTE *)(v87 + 10) & 1) == 0 )
    {
      if ( !g_dp_display || (v88 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v88 = 0;
      result = ipc_log_string(v88, "[d][%-4d]not reauthenticating, cable disconnected\n", *(_DWORD *)(v29 + 1800));
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]not reauthenticating, cable disconnected\n",
                   *(_DWORD *)(v29 + 1800));
      goto LABEL_37;
    }
    if ( !v73 )
    {
      result = dp_display_hdcp_register_streams(v12);
      goto LABEL_196;
    }
    v89 = *(unsigned int (__fastcall **)(_QWORD))(v73 + 72);
    v90 = v73;
    if ( !v89 )
      goto LABEL_142;
    if ( *((_DWORD *)v89 - 1) != -1066802076 )
      __break(0x8228u);
    if ( !v89(v74) )
    {
LABEL_142:
      result = dp_display_hdcp_register_streams(v12);
      v91 = *(__int64 (__fastcall **)(_QWORD))(v90 + 16);
      if ( v91 )
      {
        if ( *((_DWORD *)v91 - 1) != -1066802076 )
          __break(0x8228u);
        result = v91(v74);
        if ( (_DWORD)result )
        {
          v92 = result;
          if ( !g_dp_display || (v93 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v93 = 0;
          ipc_log_string(v93, "[e][%-4d]failed rc=%d\n", *(_DWORD *)(v29 + 1800), v92);
          result = printk(&unk_218D1B, "dp_display_hdcp_process_state");
        }
      }
      goto LABEL_196;
    }
LABEL_174:
    result = dp_display_update_hdcp_status(v12, 1);
    goto LABEL_37;
  }
  if ( v75 )
  {
    result = dp_display_hdcp_register_streams(v12);
    goto LABEL_37;
  }
  result = dp_display_hdcp_register_streams(v12);
  if ( !*(_QWORD *)v114 )
    goto LABEL_196;
  v86 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v114 + 24LL);
  if ( !v86 )
    goto LABEL_196;
  if ( *((_DWORD *)v86 - 1) != -1066802076 )
    __break(0x8228u);
  result = v86(v74);
  if ( !(_DWORD)result )
LABEL_196:
    *(_DWORD *)(v72 + 136) = 1;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
