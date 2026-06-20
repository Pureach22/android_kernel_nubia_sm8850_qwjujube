__int64 __fastcall dp_catalog_ctrl_update_vx_px_v420(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, char a4)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x24
  int v10; // w2
  __int64 v11; // x26
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 (__fastcall *v14)(__int64, __int64, _QWORD); // x8
  __int64 v15; // x0
  unsigned int v16; // w23
  __int64 v17; // x0
  __int64 v18; // x9
  char *v19; // x8
  char *v20; // x10
  __int64 v21; // x0
  int v22; // w22
  void (__fastcall *v23)(__int64, __int64, __int64, __int64); // x8
  int v24; // w23
  __int64 v25; // x21
  void (__fastcall *v26)(__int64, __int64, __int64, __int64); // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x21
  void (__fastcall *v30)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v31)(__int64, __int64, __int64, __int64); // x8
  __int64 v32; // x0
  __int64 v33; // x0
  unsigned int v34; // w21
  unsigned int v35; // w22
  __int64 v36; // x0
  __int64 v37; // x19
  _DWORD *v38; // x8
  _DWORD *v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x19
  _DWORD *v43; // x8
  _DWORD *v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 result; // x0
  __int64 v49; // x0

  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_DWORD *)(StatusReg + 1800);
  if ( a1 && (a3 | (unsigned int)a2) < 4 )
  {
    ipc_log_string(ipc_log_context, "[d][%-4d]hw: v=%d p=%d, high=%d\n", v10, a2, a3, a4 & 1);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]hw: v=%d p=%d, high=%d\n",
        *(_DWORD *)(StatusReg + 1800),
        a2,
        a3,
        a4 & 1);
    v11 = *(_QWORD *)(a1 + 1104);
    dp_catalog_get_dp_phy_version(*(_QWORD *)(v11 + 32));
    v12 = *(_QWORD *)(v11 + 32);
    v13 = **(_QWORD **)(v11 + 24);
    v14 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))v11;
    if ( *(_DWORD *)(*(_QWORD *)v11 - 4LL) != 625732792 )
      __break(0x8228u);
    v15 = v14(v12, v13, 0);
    v16 = v15;
    v17 = get_ipc_log_context(v15);
    ipc_log_string(v17, "[d][%-4d]version: 0x%x\n", *(_DWORD *)(StatusReg + 1800), v16);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]version: 0x%x\n", *(_DWORD *)(StatusReg + 1800), v16);
    if ( v16 >= 0x10020003 && *(_BYTE *)(a1 + 48) == 1 )
    {
      v18 = a3 | (4 * (unsigned int)a2);
      if ( (a4 & 1) != 0 )
      {
        v19 = *(char **)(a1 + 16);
        v20 = *(char **)(a1 + 24);
      }
      else
      {
        v19 = *(char **)(a1 + 32);
        v20 = *(char **)(a1 + 40);
      }
    }
    else
    {
      v18 = 4LL * a2;
      v19 = (char *)&vm_voltage_swing_0 + a3;
      v20 = (char *)&vm_pre_emphasis_0 + a3;
    }
    v21 = *(_QWORD *)(v11 + 32);
    v22 = (unsigned __int8)v19[v18];
    v23 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 8);
    v24 = (unsigned __int8)v20[v18];
    v25 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 40LL);
    if ( *((_DWORD *)v23 - 1) != 621108289 )
      __break(0x8228u);
    v23(v21, v25, 20, 42);
    v26 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 8);
    v27 = *(_QWORD *)(v11 + 32);
    if ( *((_DWORD *)v26 - 1) != 621108289 )
      __break(0x8228u);
    v26(v27, v25, 12, 32);
    v28 = *(_QWORD *)(v11 + 32);
    v29 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 48LL);
    v30 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 8);
    if ( *((_DWORD *)v30 - 1) != 621108289 )
      __break(0x8228u);
    v30(v28, v29, 20, 42);
    v31 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 8);
    v32 = *(_QWORD *)(v11 + 32);
    if ( *((_DWORD *)v31 - 1) != 621108289 )
      __break(0x8228u);
    v33 = v31(v32, v29, 12, 32);
    v34 = v22 | 0x20;
    v35 = v24 | 0x20;
    if ( v34 == 255 || v35 == 255 )
    {
      v49 = get_ipc_log_context(v33);
      ipc_log_string(
        v49,
        "[e][%-4d]invalid vx (0x%x=0x%x), px (0x%x=0x%x\n",
        *(_DWORD *)(StatusReg + 1800),
        a2,
        v34,
        a3,
        v35);
      return printk(&unk_210E62, "dp_catalog_ctrl_update_vx_px_v420");
    }
    else
    {
      v36 = *(_QWORD *)(v11 + 32);
      v37 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 40LL);
      v38 = *(_DWORD **)(v11 + 8);
      if ( *(v38 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v38)(v36, v37, 20, v34);
      v39 = *(_DWORD **)(v11 + 8);
      v40 = *(_QWORD *)(v11 + 32);
      if ( *(v39 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v39)(v40, v37, 12, v35);
      v41 = *(_QWORD *)(v11 + 32);
      v42 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 48LL);
      v43 = *(_DWORD **)(v11 + 8);
      if ( *(v43 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v43)(v41, v42, 20, v34);
      v44 = *(_DWORD **)(v11 + 8);
      v45 = *(_QWORD *)(v11 + 32);
      if ( *(v44 - 1) != 621108289 )
        __break(0x8228u);
      v46 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v44)(v45, v42, 12, v35);
      v47 = get_ipc_log_context(v46);
      result = ipc_log_string(
                 v47,
                 "[d][%-4d]hw: vx_value=0x%x px_value=0x%x\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v34,
                 v35);
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]hw: vx_value=0x%x px_value=0x%x\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v34,
                 v35);
    }
  }
  else
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", v10);
    return printk(&unk_275B6D, "dp_catalog_ctrl_update_vx_px_v420");
  }
  return result;
}
