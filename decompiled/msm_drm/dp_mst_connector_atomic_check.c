__int64 __fastcall dp_mst_connector_atomic_check(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x24
  int v7; // w7
  int v8; // w8
  __int64 v9; // x9
  __int64 v10; // x28
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x27
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x23
  unsigned __int64 private_obj_state; // x0
  unsigned __int64 v20; // x22
  int v21; // w8
  _BOOL4 v22; // w11
  __int64 v23; // x2
  __int64 (__fastcall *v24)(__int64, __int64, __int64); // x8
  int v25; // w0
  _BOOL4 v26; // w22
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v30; // x22
  __int64 v31; // x8
  __int64 v32; // x23
  _BOOL4 v33; // w28
  unsigned __int64 v34; // x0
  unsigned __int64 v35; // x27
  _DWORD *v36; // x8
  __int64 v37; // x1
  int v38; // w7
  __int64 (__fastcall *v39)(_QWORD); // x8
  unsigned int v40; // w0
  __int64 v41; // x22
  unsigned int v42; // w21
  unsigned int (__fastcall *v43)(_QWORD); // x9
  __int64 v44; // x0
  __int64 v45; // x2
  _DWORD *v46; // x8
  int v47; // w24
  __int64 v48; // x0
  unsigned __int64 v49; // x20
  __int64 v50; // x0
  __int64 v51; // x0
  unsigned __int64 v52; // x20
  __int64 v53; // x0
  int v54; // w20
  __int64 v55; // x0
  __int64 v56; // x0
  char v57; // [xsp+0h] [xbp-360h]
  char v58; // [xsp+0h] [xbp-360h]
  int v59; // [xsp+1Ch] [xbp-344h]
  _QWORD *v60; // [xsp+20h] [xbp-340h]
  _BOOL4 v61; // [xsp+2Ch] [xbp-334h]
  _BYTE s[800]; // [xsp+30h] [xbp-330h] BYREF
  __int64 v63; // [xsp+350h] [xbp-10h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 40);
  memset(s, 0, sizeof(s));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_atomic_check",
    1514,
    8,
    4369,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    v7,
    v57);
  if ( !a3
    || (v8 = *(_DWORD *)(a1 + 152), v8 >= *(_DWORD *)(a3 + 40))
    || (v9 = *(_QWORD *)(a3 + 48), (v10 = *(_QWORD *)(v9 + 40LL * v8 + 24)) == 0) )
  {
    LODWORD(v20) = 0;
    goto LABEL_31;
  }
  v11 = *(_QWORD *)(v9 + 40LL * v8 + 16);
  if ( !v11 )
    goto LABEL_32;
  v12 = *(_QWORD *)(v11 + 8);
  if ( v12 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(a3 + 32) + 56LL * *(unsigned int *)(v12 + 160) + 24);
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[d][%-4d]bridge id:%d, vcpi:%d, pbn:%d, slots:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(v6 + 1736),
      *(_DWORD *)(v6 + 2696),
      *(_DWORD *)(v6 + 2700),
      *(_DWORD *)(v6 + 2704));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]bridge id:%d, vcpi:%d, pbn:%d, slots:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(v6 + 1736),
        *(_DWORD *)(v6 + 2696),
        *(_DWORD *)(v6 + 2700),
        *(_DWORD *)(v6 + 2704));
    v16 = get_ipc_log_context();
    ipc_log_string(
      v16,
      "[d][%-4d]bridge id:%d, vcpi:%d, pbn:%d, slots:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(v6 + 3128),
      *(_DWORD *)(v6 + 4088),
      *(_DWORD *)(v6 + 4092),
      *(_DWORD *)(v6 + 4096));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]bridge id:%d, vcpi:%d, pbn:%d, slots:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(v6 + 3128),
        *(_DWORD *)(v6 + 4088),
        *(_DWORD *)(v6 + 4092),
        *(_DWORD *)(v6 + 4096));
    if ( (*(_BYTE *)(v13 + 10) & 0xE) != 0 )
    {
      v17 = *(_QWORD *)(v11 + 16);
      if ( !v17 )
        goto LABEL_73;
      v18 = *(_QWORD *)(v17 + 88);
      if ( v18 == v17 + 88 || v18 == 120 )
        goto LABEL_73;
      if ( (mutex_is_locked(*(_QWORD *)(v18 - 16) + 480LL) & 1) == 0 )
        __break(0x800u);
      private_obj_state = drm_atomic_get_private_obj_state(a3, v18 + 176);
      v20 = private_obj_state;
      if ( private_obj_state >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_66;
      v60 = (_QWORD *)(private_obj_state + 16);
      if ( *(_QWORD *)(private_obj_state + 16) != a1 )
        goto LABEL_73;
      v21 = *(_DWORD *)(private_obj_state + 32);
      v59 = v21;
      v22 = v21 > 0;
      if ( v21 >= 1 )
      {
        v23 = *(_QWORD *)(a1 + 2776);
        v61 = v21 > 0;
        v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v6 + 4128) + 32LL);
        if ( *((_DWORD *)v24 - 1) != -837387340 )
          __break(0x8228u);
        v25 = v24(a3, v6 + 32, v23);
        v22 = v61;
        if ( v25 )
        {
          v54 = v25;
          v55 = get_ipc_log_context();
          ipc_log_string(v55, "[e][%-4d]failed releasing %d vcpi slots %d\n", *(_DWORD *)(StatusReg + 1800), v59, v54);
          printk(&unk_26525D, "dp_mst_connector_atomic_check");
          LODWORD(v20) = v54;
          goto LABEL_66;
        }
      }
      *(_DWORD *)(v20 + 32) = 0;
      if ( !*(_QWORD *)(v10 + 8) && *(_DWORD *)(v6 + 4232) != 1 )
      {
        v26 = v22;
        *v60 = 0;
        v60[1] = 0;
        v27 = get_ipc_log_context();
        ipc_log_string(v27, "[d][%-4d]clear best encoder: %d\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(v18 + 280));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]clear best encoder: %d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(v18 + 280));
        v22 = v26;
        v28 = *(_QWORD *)(v10 + 8);
        if ( !v28 )
          goto LABEL_65;
        goto LABEL_36;
      }
      goto LABEL_35;
    }
LABEL_32:
    v22 = 0;
    v28 = *(_QWORD *)(v10 + 8);
    if ( !v28 )
      goto LABEL_65;
    goto LABEL_36;
  }
  v22 = 0;
LABEL_35:
  v28 = *(_QWORD *)(v10 + 8);
  if ( !v28 )
    goto LABEL_65;
LABEL_36:
  v30 = *(_QWORD *)(*(_QWORD *)(a3 + 32) + 56LL * *(unsigned int *)(v28 + 160) + 24);
  if ( (*(_BYTE *)(v30 + 10) & 0xE) == 0 || *(_BYTE *)(v30 + 9) != 1 )
    goto LABEL_65;
  v31 = *(_QWORD *)(v10 + 16);
  if ( !v31 )
    goto LABEL_73;
  v32 = *(_QWORD *)(v31 + 88);
  if ( v32 == v31 + 88 || v32 == 120 )
    goto LABEL_73;
  v33 = v22;
  if ( (mutex_is_locked(*(_QWORD *)(v32 - 16) + 480LL) & 1) == 0 )
    __break(0x800u);
  v34 = drm_atomic_get_private_obj_state(a3, v32 + 176);
  v35 = v34;
  if ( v34 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(_QWORD *)(v34 + 16) != a1 )
      goto LABEL_73;
    if ( !v33 )
    {
      if ( !*(_DWORD *)(v34 + 32) )
      {
        v36 = *(_DWORD **)(a2 + 272);
        v37 = *(_QWORD *)(a1 + 2768);
        if ( *(v36 - 1) != 271107547 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _BYTE *))v36)(a2, v37, v30 + 144, s);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_dp_mst_compute_config",
          506,
          8,
          4369,
          *(_DWORD *)(a1 + 64),
          -1059143953,
          v38,
          v58);
        v39 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 4128) + 40LL);
        if ( *((_DWORD *)v39 - 1) != -143676487 )
          __break(0x8228u);
        v40 = v39(s);
        v41 = *(_QWORD *)(v6 + 120);
        v42 = v40;
        v43 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 4120) + 312LL);
        v44 = *(_QWORD *)(v6 + 4120);
        if ( *((_DWORD *)v43 - 1) != 1970643636 )
          __break(0x8229u);
        *(_DWORD *)(v41 + 76) = v43(v44) << 12;
        v45 = *(_QWORD *)(a1 + 2776);
        v46 = **(_DWORD ***)(v6 + 4128);
        if ( *(v46 - 1) != -299062620 )
          __break(0x8228u);
        v47 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v46)(a3, v6 + 32, v45, v42);
        if ( v47 < 0 )
        {
          v53 = get_ipc_log_context();
          ipc_log_string(
            v53,
            "[e][%-4d]conn:%d failed to find vcpi slots. pbn:%d, rc:%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 64),
            v42,
            v47);
          printk(&unk_226D4D, "_dp_mst_compute_config");
          LODWORD(v20) = v47;
        }
        else
        {
          LODWORD(v20) = drm_dp_mst_atomic_check(a3);
          if ( !(_DWORD)v20 )
          {
LABEL_60:
            v48 = get_ipc_log_context();
            v49 = _ReadStatusReg(SP_EL0);
            ipc_log_string(
              v48,
              "[d][%-4d]conn:%d pbn:%d slots:%d rc:%d\n",
              *(_DWORD *)(v49 + 1800),
              *(_DWORD *)(a1 + 64),
              v42,
              v47,
              v20);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]conn:%d pbn:%d slots:%d rc:%d\n",
                *(_DWORD *)(v49 + 1800),
                *(_DWORD *)(a1 + 64),
                v42,
                v47,
                v20);
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_dp_mst_compute_config",
              548,
              8,
              8738,
              *(_DWORD *)(a1 + 64),
              v42,
              v47,
              v20);
            if ( (v20 & 0x80000000) == 0 )
            {
              LODWORD(v20) = 0;
              *(_DWORD *)(v35 + 32) = v47;
            }
            goto LABEL_66;
          }
          v56 = get_ipc_log_context();
          ipc_log_string(
            v56,
            "[e][%-4d]conn:%d mst atomic check failed: rc=%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 64),
            v20);
          printk(&unk_245C47, "_dp_mst_compute_config");
        }
        v47 = 0;
        goto LABEL_60;
      }
LABEL_73:
      __break(0x800u);
      LODWORD(v20) = -22;
      goto LABEL_66;
    }
    v50 = get_ipc_log_context();
    ipc_log_string(
      v50,
      "[w][%-4d]skipping allocation since vcpi was released in the same state\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26C063, "dp_mst_connector_atomic_check");
LABEL_65:
    LODWORD(v20) = 0;
    goto LABEL_66;
  }
  LODWORD(v20) = v34;
LABEL_66:
  v51 = get_ipc_log_context();
  v52 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v51,
    "[d][%-4d]mst connector:%d atomic check ret %d\n",
    *(_DWORD *)(v52 + 1800),
    *(_DWORD *)(a1 + 64),
    v20);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst connector:%d atomic check ret %d\n",
      *(_DWORD *)(v52 + 1800),
      *(_DWORD *)(a1 + 64),
      v20);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_atomic_check",
    1650,
    8,
    8738,
    *(_DWORD *)(a1 + 64),
    v20,
    -1059143953,
    v58);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v20;
}
