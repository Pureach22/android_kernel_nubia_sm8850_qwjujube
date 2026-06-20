_QWORD *__fastcall dp_catalog_ctrl_update_vx_px(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, char a4)
{
  unsigned int v6; // w22
  __int64 v7; // x21
  __int64 v8; // x20
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v11; // x1
  _DWORD *v12; // x8
  int v13; // w0
  _QWORD *v14; // x4
  __int64 v15; // x5
  unsigned int v16; // w8
  bool v17; // zf
  __int64 v18; // x10
  char *v19; // x8
  char *v20; // x9
  char *v21; // x11
  unsigned __int64 v22; // x9
  char *v23; // x8
  char *v24; // x10
  __int64 v25; // x23
  int v26; // w24
  void (__fastcall *v27)(__int64, __int64, __int64, __int64); // x8
  int v28; // w27
  void (__fastcall *v29)(__int64, __int64, __int64, __int64); // x8
  __int64 v30; // x23
  void (__fastcall *v31)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v32)(__int64, __int64, __int64, __int64); // x8
  __int64 v33; // x0
  unsigned int v34; // w23
  unsigned int v35; // w24
  __int64 v36; // x21
  _DWORD *v37; // x8
  _DWORD *v38; // x8
  __int64 v39; // x21
  _DWORD *v40; // x8
  _DWORD *v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  _QWORD *result; // x0
  __int64 ipc_log_context; // x0
  __int64 v46; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return (_QWORD *)printk(&unk_275B6D, "dp_catalog_ctrl_update_vx_px");
  }
  v6 = a2;
  v7 = a3;
  v8 = a1 - 232;
  v9 = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v9, "[d][%-4d]hw: v=%d p=%d\n", *(_DWORD *)(StatusReg + 1800), v6, v7);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]hw: v=%d p=%d\n", *(_DWORD *)(StatusReg + 1800), v6, v7);
  v11 = *(_QWORD *)(a1 - 224);
  v12 = *(_DWORD **)(a1 - 112);
  if ( *(v12 - 1) != -1879227436 )
    __break(0x8228u);
  v13 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v12)(v8, v11, 0);
  v16 = v6 | v7;
  if ( v13 == 268566532 )
  {
    if ( (a4 & 1) != 0 )
    {
      v17 = v16 == 4;
      if ( v16 >= 4 )
        goto LABEL_39;
      v18 = 4LL * v6;
      v19 = (char *)&vm_voltage_swing_hbr3_hbr2 + v7;
      v20 = (char *)&vm_pre_emphasis_hbr3_hbr2;
    }
    else
    {
      v17 = v16 == 3;
      if ( v16 > 3 )
        goto LABEL_39;
      v18 = 4LL * v6;
      v19 = (char *)&vm_voltage_swing_hbr_rbr + v7;
      v20 = (char *)&vm_pre_emphasis_hbr_rbr;
    }
  }
  else
  {
    v17 = v16 == 3;
    if ( v16 > 3 )
      goto LABEL_39;
    v18 = 4LL * v6;
    v19 = (char *)&vm_voltage_swing + v7;
    v20 = (char *)&vm_pre_emphasis;
  }
  v21 = &v20[v7];
  v22 = v18 | v7;
  v23 = &v19[v18];
  v24 = &v21[v18];
  v17 = v22 == 15;
  if ( v22 > 0xF )
  {
    __break(1u);
LABEL_39:
    __break(0x5512u);
    if ( v17 )
      return dp_catalog_ctrl_get_interrupt((_QWORD *)~v15);
    else
      return dp_catalog_ctrl_get_interrupt(v14);
  }
  v25 = *(_QWORD *)(a1 - 184);
  v26 = (unsigned __int8)*v23;
  v27 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
  v28 = (unsigned __int8)*v24;
  if ( *((_DWORD *)v27 - 1) != -626862723 )
    __break(0x8228u);
  v27(v8, v25, 28, 42);
  v29 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
  if ( *((_DWORD *)v29 - 1) != -626862723 )
    __break(0x8228u);
  v29(v8, v25, 12, 32);
  v30 = *(_QWORD *)(a1 - 176);
  v31 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
  if ( *((_DWORD *)v31 - 1) != -626862723 )
    __break(0x8228u);
  v31(v8, v30, 28, 42);
  v32 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
  if ( *((_DWORD *)v32 - 1) != -626862723 )
    __break(0x8228u);
  v33 = v32(v8, v30, 12, 32);
  v34 = v26 | 0x20;
  v35 = v28 | 0x20;
  if ( v34 == 255 || v35 == 255 )
  {
    v46 = get_ipc_log_context(v33);
    ipc_log_string(
      v46,
      "[e][%-4d]invalid vx (0x%x=0x%x), px (0x%x=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      v6,
      v34,
      v7,
      v35);
    return (_QWORD *)printk(&unk_210E62, "dp_catalog_ctrl_update_vx_px");
  }
  else
  {
    v36 = *(_QWORD *)(a1 - 184);
    v37 = *(_DWORD **)(a1 - 104);
    if ( *(v37 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v37)(v8, v36, 28, v34);
    v38 = *(_DWORD **)(a1 - 104);
    if ( *(v38 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v38)(v8, v36, 12, v35);
    v39 = *(_QWORD *)(a1 - 176);
    v40 = *(_DWORD **)(a1 - 104);
    if ( *(v40 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v40)(v8, v39, 28, v34);
    v41 = *(_DWORD **)(a1 - 104);
    if ( *(v41 - 1) != -626862723 )
      __break(0x8228u);
    v42 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v41)(v8, v39, 12, v35);
    v43 = get_ipc_log_context(v42);
    result = (_QWORD *)ipc_log_string(
                         v43,
                         "[d][%-4d]hw: vx_value=0x%x px_value=0x%x\n",
                         *(_DWORD *)(StatusReg + 1800),
                         v34,
                         v35);
    if ( (_drm_debug & 4) != 0 )
      return (_QWORD *)_drm_dev_dbg(
                         0,
                         0,
                         0,
                         "[msm-dp-debug][%-4d]hw: vx_value=0x%x px_value=0x%x\n",
                         *(_DWORD *)(StatusReg + 1800),
                         v34,
                         v35);
  }
  return result;
}
