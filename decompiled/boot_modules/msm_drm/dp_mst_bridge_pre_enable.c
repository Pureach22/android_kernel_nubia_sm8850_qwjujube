__int64 __fastcall dp_mst_bridge_pre_enable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 ipc_log_context; // x0
  void *v9; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 result; // x0
  _QWORD *v14; // x20
  __int64 v15; // x26
  _DWORD *v16; // x8
  __int64 v17; // x1
  int v18; // w0
  _DWORD *v19; // x8
  __int64 v20; // x1
  int v21; // w0
  int v22; // w7
  __int64 v23; // x23
  __int64 v24; // x8
  __int64 v25; // x21
  __int64 v26; // x25
  int v27; // w5
  int v28; // w21
  __int64 v29; // x0
  void *v30; // x0
  int v31; // w21
  __int64 v32; // x0
  int v33; // w7
  __int64 v34; // x8
  int v35; // w5
  void (__fastcall *v36)(__int64, __int64); // x8
  _DWORD *v37; // x8
  int v38; // w8
  __int64 v39; // x1
  int v40; // w4
  __int64 (__fastcall *v41)(_QWORD); // x8
  unsigned int v42; // w23
  _DWORD *v43; // x8
  int v44; // w24
  __int64 v45; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v47; // x8
  int v48; // w3
  _DWORD *v49; // x8
  void (*v50)(void); // x8
  __int64 v51; // x23
  __int64 mst_payload_state; // x0
  __int64 v53; // x24
  __int64 v54; // x0
  __int64 v55; // x8
  int v56; // w3
  int v57; // w25
  __int64 v58; // x0
  void *v59; // x0
  unsigned int (__fastcall *v60)(__int64, __int64, __int64); // x8
  __int64 v61; // x0
  __int64 v62; // x8
  int v63; // w3
  __int64 (__fastcall *v64)(__int64, __int64, __int64); // x8
  __int64 v65; // x0
  __int64 v66; // x8
  int v67; // w3
  __int64 (__fastcall *v68)(__int64, __int64, __int64); // x8
  _DWORD *v69; // x8
  __int64 v70; // x1
  int v71; // w0
  __int64 v72; // x0
  unsigned __int64 v73; // x23
  __int64 v74; // x8
  int v75; // w20
  __int64 v76; // x21
  int v77; // w22
  int v78; // w21
  __int64 v79; // x0
  _DWORD *v80; // x8
  __int64 v81; // x1
  int v82; // w0
  unsigned int v83; // w20
  __int64 v84; // x0
  __int64 v85; // x8
  int v86; // w3
  char v87; // [xsp+0h] [xbp-30h]
  int v88; // [xsp+0h] [xbp-30h]
  __int64 v89; // [xsp+18h] [xbp-18h]
  _QWORD v90[2]; // [xsp+20h] [xbp-10h] BYREF

  v90[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_21CA0C;
LABEL_7:
    result = printk(v9, "dp_mst_bridge_pre_enable");
    goto LABEL_25;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  v11 = *(_QWORD *)(a1 + 1344);
  if ( !v11 )
  {
    v12 = get_ipc_log_context();
    ipc_log_string(v12, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2344C7;
    goto LABEL_7;
  }
  v14 = *(_QWORD **)(a1 + 408);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_bridge_pre_enable",
    909,
    8,
    4369,
    *(_DWORD *)(v11 + 64),
    -1059143953,
    a8,
    v87);
  v15 = v14[5];
  mutex_lock(v15 + 4136);
  v16 = (_DWORD *)v14[14];
  v17 = *(_QWORD *)(a1 + 1352);
  if ( *(v16 - 1) != -723972362 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v16)(v14, v17, a1 + 544);
  if ( v18 )
  {
    v28 = v18;
    v29 = get_ipc_log_context();
    ipc_log_string(
      v29,
      "[e][%-4d][%d] failed to perform a mode set, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 400),
      v28);
    v30 = &unk_21FFB1;
  }
  else
  {
    v19 = (_DWORD *)v14[17];
    v20 = *(_QWORD *)(a1 + 1352);
    if ( *(v19 - 1) != -1533774139 )
      __break(0x8228u);
    v21 = ((__int64 (__fastcall *)(_QWORD *, __int64))v19)(v14, v20);
    if ( !v21 )
    {
      v23 = *(_QWORD *)(a1 + 408);
      v24 = *(_QWORD *)(a1 + 1344);
      v25 = *(_QWORD *)(v23 + 40);
      v26 = *(_QWORD *)(v24 + 2776);
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        v24 = *(_QWORD *)(a1 + 1344);
      }
      if ( v24 )
        v27 = *(_DWORD *)(v24 + 64);
      else
        v27 = 0;
      sde_evtlog_log(sde_dbg_base_evtlog, "_dp_mst_bridge_pre_enable_part1", 685, 8, 4369, v27, -1059143953, v22, v88);
      if ( *(_DWORD *)(v25 + 4232) == 1 )
      {
        v36 = *(void (__fastcall **)(__int64, __int64))(v23 + 288);
        if ( *((_DWORD *)v36 - 1) != 169801067 )
          __break(0x8228u);
        v36(v23, 1);
        drm_dp_send_power_updown_phy(v25 + 32, v26, 1);
        v37 = *(_DWORD **)(v23 + 288);
        if ( *(v37 - 1) != 169801067 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v37)(v23, 0);
        v38 = *(_DWORD *)(v25 + 4232);
        v90[0] = 0;
        if ( v38 == 1 )
        {
          v39 = *(unsigned int *)(a1 + 1360);
          if ( (_DWORD)v39 )
          {
            v49 = *(_DWORD **)(*(_QWORD *)(v25 + 4128) + 96LL);
            if ( *(v49 - 1) != -1189901681 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, char *, _QWORD *))v49)(v25 + 32, v39, (char *)v90 + 4, v90);
            v40 = v90[0];
          }
          else
          {
            v40 = 0;
          }
          *(_DWORD *)(a1 + 1368) = v40;
          v50 = *(void (**)(void))(*(_QWORD *)(v25 + 4120) + 264LL);
          if ( *((_DWORD *)v50 - 1) != -133057824 )
            __break(0x8228u);
          v50();
        }
        goto LABEL_75;
      }
      v41 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v25 + 4128) + 40LL);
      if ( *((_DWORD *)v41 - 1) != -143676487 )
        __break(0x8228u);
      v42 = v41(a1 + 544);
      v43 = *(_DWORD **)(*(_QWORD *)(v25 + 4128) + 48LL);
      if ( *(v43 - 1) != -98629839 )
        __break(0x8228u);
      v44 = ((__int64 (__fastcall *)(__int64, _QWORD))v43)(v25 + 32, v42);
      v45 = get_ipc_log_context();
      StatusReg = _ReadStatusReg(SP_EL0);
      v47 = *(_QWORD *)(a1 + 1344);
      if ( v47 )
        v48 = *(_DWORD *)(v47 + 64);
      else
        v48 = 0;
      ipc_log_string(v45, "[i][%-4d]conn:%d pbn:%d, slots:%d\n", *(_DWORD *)(StatusReg + 1800), v48, v42, v44);
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_22DB4A, *(unsigned int *)(StatusReg + 1800));
      else
        printk(&unk_25A349, "_dp_mst_bridge_pre_enable_part1");
      v51 = *(_QWORD *)(v25 + 120);
      mst_payload_state = drm_atomic_get_mst_payload_state(v51, v26);
      if ( mst_payload_state && (v53 = mst_payload_state, *(int *)(mst_payload_state + 12) > 0) )
      {
        v89 = v26;
        drm_dp_mst_update_slots(v51, 1);
        v60 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v25 + 4128) + 8LL);
        if ( *((_DWORD *)v60 - 1) != -744863488 )
          __break(0x8228u);
        if ( !v60(v25 + 32, v51, v53) )
          goto LABEL_74;
        v61 = get_ipc_log_context();
        v62 = *(_QWORD *)(a1 + 1344);
        if ( v62 )
          v63 = *(_DWORD *)(v62 + 64);
        else
          v63 = 0;
        ipc_log_string(
          v61,
          "[w][%-4d]payload allocation failure for conn:%d, retries:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          v63,
          1);
        printk(&unk_26FA62, "_dp_mst_bridge_pre_enable_part1");
        msleep(100);
        v64 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v25 + 4128) + 8LL);
        if ( *((_DWORD *)v64 - 1) != -744863488 )
          __break(0x8228u);
        v57 = v64(v25 + 32, v51, v53);
        if ( v57 )
        {
          v65 = get_ipc_log_context();
          v66 = *(_QWORD *)(a1 + 1344);
          if ( v66 )
            v67 = *(_DWORD *)(v66 + 64);
          else
            v67 = 0;
          ipc_log_string(
            v65,
            "[w][%-4d]payload allocation failure for conn:%d, retries:%d\n",
            *(_DWORD *)(StatusReg + 1800),
            v67,
            2);
          printk(&unk_26FA62, "_dp_mst_bridge_pre_enable_part1");
          msleep(100);
          v68 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v25 + 4128) + 8LL);
          if ( *((_DWORD *)v68 - 1) != -744863488 )
            __break(0x8228u);
          v57 = v68(v25 + 32, v51, v53);
        }
        if ( !v57 )
        {
LABEL_74:
          dp_mst_update_timeslots(v25, a1, v89);
LABEL_75:
          v69 = (_DWORD *)v14[10];
          v70 = *(_QWORD *)(a1 + 1352);
          if ( *(v69 - 1) != -1533774139 )
            __break(0x8228u);
          v71 = ((__int64 (__fastcall *)(_QWORD *, __int64))v69)(v14, v70);
          if ( !v71 )
          {
            dp_mst_bridge_pre_enable_part2(a1);
            v72 = get_ipc_log_context();
            v73 = _ReadStatusReg(SP_EL0);
            v74 = *(_QWORD *)(a1 + 1344);
            v75 = *(_DWORD *)(v73 + 1800);
            v76 = v72;
            if ( v74 )
              v77 = *(_DWORD *)(v74 + 64);
            else
              v77 = 0;
            v82 = drm_mode_vrefresh(a1 + 424);
            ipc_log_string(
              v76,
              "[i][%-4d]conn:%d mode:%s fps:%d dsc:%d vcpi:%d slots:%d to %d\n",
              v75,
              v77,
              (const char *)(a1 + 504),
              v82,
              *(unsigned __int8 *)(a1 + 608),
              *(_DWORD *)(a1 + 1360),
              *(_DWORD *)(a1 + 1372),
              *(_DWORD *)(a1 + 1368) + *(_DWORD *)(a1 + 1372));
            v83 = *(_DWORD *)(v73 + 1800);
            if ( (_drm_debug & 4) != 0 )
            {
              drm_mode_vrefresh(a1 + 424);
              v88 = *(_DWORD *)(a1 + 1368) + *(_DWORD *)(a1 + 1372);
              printk(&unk_261A11, v83);
            }
            else
            {
              drm_mode_vrefresh(a1 + 424);
              v88 = *(_DWORD *)(a1 + 1372);
              printk(&unk_27673E, "dp_mst_bridge_pre_enable");
            }
            goto LABEL_21;
          }
          v78 = v71;
          v79 = get_ipc_log_context();
          ipc_log_string(
            v79,
            "[e][%-4d][%d] DP display enable failed, rc=%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 400),
            v78);
          v59 = &unk_230FDA;
LABEL_81:
          printk(v59, "dp_mst_bridge_pre_enable");
          v80 = (_DWORD *)v14[18];
          v81 = *(_QWORD *)(a1 + 1352);
          if ( *(v80 - 1) != -1533774139 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, __int64))v80)(v14, v81);
          goto LABEL_21;
        }
        v84 = get_ipc_log_context();
        v85 = *(_QWORD *)(a1 + 1344);
        if ( v85 )
          v86 = *(_DWORD *)(v85 + 64);
        else
          v86 = 0;
        ipc_log_string(v84, "[e][%-4d]payload allocation failure for conn:%d\n", *(_DWORD *)(StatusReg + 1800), v86);
        printk(&unk_22031A, "_dp_mst_bridge_pre_enable_part1");
      }
      else
      {
        v54 = get_ipc_log_context();
        v55 = *(_QWORD *)(a1 + 1344);
        if ( v55 )
          v56 = *(_DWORD *)(v55 + 64);
        else
          v56 = 0;
        ipc_log_string(v54, "[e][%-4d]time slots not allocated for conn:%d\n", *(_DWORD *)(StatusReg + 1800), v56);
        printk(&unk_261A62, "_dp_mst_bridge_pre_enable_part1");
        v57 = -22;
      }
      v58 = get_ipc_log_context();
      ipc_log_string(
        v58,
        "[e][%-4d][%d] DP display pre-enable failed, rc=%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 400),
        v57);
      v59 = &unk_223BE3;
      goto LABEL_81;
    }
    v31 = v21;
    v32 = get_ipc_log_context();
    ipc_log_string(
      v32,
      "[e][%-4d][%d] DP display prepare failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 400),
      v31);
    v30 = &unk_252DF9;
  }
  printk(v30, "dp_mst_bridge_pre_enable");
LABEL_21:
  v34 = *(_QWORD *)(a1 + 1344);
  if ( v34 )
    v35 = *(_DWORD *)(v34 + 64);
  else
    v35 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_pre_enable", 953, 8, 8738, v35, -1059143953, v33, v88);
  result = mutex_unlock(v15 + 4136);
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
