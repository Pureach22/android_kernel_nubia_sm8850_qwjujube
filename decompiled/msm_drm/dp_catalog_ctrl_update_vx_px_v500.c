__int64 __fastcall dp_catalog_ctrl_update_vx_px_v500(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, char a4)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x25
  int v10; // w2
  __int64 v11; // x27
  __int64 v12; // x0
  unsigned int v13; // w8
  __int64 v14; // x24
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 (__fastcall *v17)(__int64, __int64, _QWORD); // x8
  __int64 v18; // x0
  unsigned int v19; // w23
  __int64 v20; // x0
  __int64 v21; // x9
  char *v22; // x8
  char *v23; // x10
  unsigned int v24; // w22
  unsigned int v25; // w21
  unsigned __int8 *v26; // x8
  unsigned int v27; // w23
  __int64 v28; // x24
  void (*v29)(void); // x8
  _DWORD *v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x24
  void (__fastcall *v34)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v35)(__int64, __int64, __int64, __int64); // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x19
  _DWORD *v40; // x8
  _DWORD *v41; // x8
  __int64 v42; // x0
  _DWORD *v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x19
  _DWORD *v47; // x8
  _DWORD *v48; // x8
  __int64 v49; // x0
  _DWORD *v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 result; // x0
  __int64 v55; // x0

  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_DWORD *)(StatusReg + 1800);
  if ( a1 && (a3 | (unsigned int)a2) < 4 )
  {
    ipc_log_string(ipc_log_context, "[d][%-4d]hw: v=%d p=%d\n", v10, a2, a3);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]hw: v=%d p=%d\n", *(_DWORD *)(StatusReg + 1800), a2, a3);
    v11 = *(_QWORD *)(a1 + 1104);
    v12 = *(_QWORD *)(v11 + 32);
    v13 = *(_DWORD *)(*(_QWORD *)(v12 + 1200) + 716LL);
    if ( v13 < 2 )
    {
      v14 = 4;
    }
    else if ( v13 == 4 )
    {
      if ( (a4 & 1) != 0 )
        v14 = 3;
      else
        v14 = 1;
    }
    else if ( v13 == 2 )
    {
      v14 = 5;
    }
    else if ( (a4 & 1) != 0 )
    {
      v14 = 2;
    }
    else
    {
      v14 = 0;
    }
    dp_catalog_get_dp_phy_version(v12);
    v15 = *(_QWORD *)(v11 + 32);
    v16 = **(_QWORD **)(v11 + 24);
    v17 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))v11;
    if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != 625732792 )
      __break(0x8228u);
    v18 = v17(v15, v16, 0);
    v19 = v18;
    v20 = get_ipc_log_context(v18);
    ipc_log_string(v20, "[d][%-4d]version: 0x%x\n", *(_DWORD *)(StatusReg + 1800), v19);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]version: 0x%x\n", *(_DWORD *)(StatusReg + 1800), v19);
    if ( v19 >= 0x10020003 && *(_BYTE *)(a1 + 48) == 1 )
    {
      v21 = a3 | (4 * (unsigned int)a2);
      if ( (a4 & 1) != 0 )
      {
        v22 = *(char **)(a1 + 16);
        v23 = *(char **)(a1 + 24);
      }
      else
      {
        v22 = *(char **)(a1 + 32);
        v23 = *(char **)(a1 + 40);
      }
    }
    else
    {
      v21 = 4LL * a2;
      v22 = (char *)&vm_voltage_swing_hbr3_hbr2 + a3;
      v23 = (char *)&vm_pre_emphasis_1 + a3;
    }
    v24 = (unsigned __int8)v22[v21];
    v25 = (unsigned __int8)v23[v21];
    v26 = (unsigned __int8 *)&ldo_config_v1;
    if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 32) + 1200LL) + 720LL) == 2 )
      v26 = (unsigned __int8 *)&ldo_config_v2;
    v27 = v26[v14];
    v28 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 40LL);
    v29 = *(void (**)(void))(v11 + 8);
    if ( *((_DWORD *)v29 - 1) != 621108289 )
      __break(0x8228u);
    v29();
    v30 = *(_DWORD **)(v11 + 8);
    v31 = *(_QWORD *)(v11 + 32);
    if ( *(v30 - 1) != 621108289 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v30)(v31, v28, 4, 0);
    v32 = *(_QWORD *)(v11 + 32);
    v33 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 48LL);
    v34 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 8);
    if ( *((_DWORD *)v34 - 1) != 621108289 )
      __break(0x8228u);
    v34(v32, v33, 20, 42);
    v35 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 8);
    v36 = *(_QWORD *)(v11 + 32);
    if ( *((_DWORD *)v35 - 1) != 621108289 )
      __break(0x8228u);
    v37 = v35(v36, v33, 4, 32);
    if ( v24 == 255 || v25 == 255 )
    {
      v55 = get_ipc_log_context(v37);
      ipc_log_string(
        v55,
        "[e][%-4d]invalid vx (0x%x=0x%x), px (0x%x=0x%x)\n",
        *(_DWORD *)(StatusReg + 1800),
        a2,
        v24,
        a3,
        v25);
      return printk(&unk_24EB4F, "dp_catalog_ctrl_update_vx_px_v500");
    }
    else
    {
      v38 = *(_QWORD *)(v11 + 32);
      v39 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 40LL);
      v40 = *(_DWORD **)(v11 + 8);
      if ( *(v40 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v40)(v38, v39, 132, v27);
      v41 = *(_DWORD **)(v11 + 8);
      v42 = *(_QWORD *)(v11 + 32);
      if ( *(v41 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v41)(v42, v39, 20, v24);
      v43 = *(_DWORD **)(v11 + 8);
      v44 = *(_QWORD *)(v11 + 32);
      if ( *(v43 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v43)(v44, v39, 4, v25);
      v45 = *(_QWORD *)(v11 + 32);
      v46 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 48LL);
      v47 = *(_DWORD **)(v11 + 8);
      if ( *(v47 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v47)(v45, v46, 132, v27);
      v48 = *(_DWORD **)(v11 + 8);
      v49 = *(_QWORD *)(v11 + 32);
      if ( *(v48 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v48)(v49, v46, 20, v24);
      v50 = *(_DWORD **)(v11 + 8);
      v51 = *(_QWORD *)(v11 + 32);
      if ( *(v50 - 1) != 621108289 )
        __break(0x8228u);
      v52 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v50)(v51, v46, 4, v25);
      v53 = get_ipc_log_context(v52);
      result = ipc_log_string(
                 v53,
                 "[d][%-4d]hw: vx_value=0x%x px_value=0x%x ldo_value=0x%x\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v24,
                 v25,
                 v27);
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]hw: vx_value=0x%x px_value=0x%x ldo_value=0x%x\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v24,
                 v25,
                 v27);
    }
  }
  else
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", v10);
    return printk(&unk_279170, "dp_catalog_ctrl_update_vx_px_v500");
  }
  return result;
}
