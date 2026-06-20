__int64 __fastcall dp_catalog_ctrl_send_phy_pattern(__int64 a1, int a2)
{
  __int64 v2; // x19
  _DWORD *v3; // x8
  __int64 v4; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 (__fastcall *v9)(__int64, __int64, __int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  _DWORD *v14; // x8
  void (__fastcall *v15)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v16)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v17)(__int64, __int64, __int64, __int64); // x8
  __int64 v18; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  _DWORD *v21; // x8
  void (__fastcall *v22)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v23)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v24; // x8
  int v25; // w0
  _DWORD *v26; // x8
  void (__fastcall *v27)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v28)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v29)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v30)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v31; // x8
  int v32; // w0
  __int64 ipc_log_context; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_send_phy_pattern");
  }
  v2 = *(_QWORD *)(a1 - 208);
  v3 = *(_DWORD **)(a1 - 104);
  v4 = a1 - 232;
  v7 = a1 - 232;
  if ( *(v3 - 1) != -626862723 )
    __break(0x8228u);
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v3)(v7, v2, 4, 0);
  if ( a2 > 3 )
  {
    switch ( a2 )
    {
      case 4:
        v15 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v15 - 1) != -626862723 )
          __break(0x8228u);
        v15(v4, v2, 4, 64);
        v16 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v16 - 1) != -626862723 )
          __break(0x8228u);
        v16(v4, v2, 192, 1041204192);
        v17 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v17 - 1) != -626862723 )
          __break(0x8228u);
        v17(v4, v2, 196, 260301048);
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        v10 = v4;
        v11 = v2;
        v12 = 200;
        v13 = 63550;
        goto LABEL_47;
      case 5:
        v24 = *(_DWORD **)(a1 - 112);
        if ( *(v24 - 1) != -1879227436 )
          __break(0x8228u);
        v25 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v24)(v4, v2, 0);
        v26 = *(_DWORD **)(a1 - 104);
        if ( *(v26 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v26)(v4, v2, 0, v25 & 0xFFFFFFEF);
        v27 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v27 - 1) != -626862723 )
          __break(0x8228u);
        v27(v4, v2, 84, 0x10000);
        v28 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v28 - 1) != -626862723 )
          __break(0x8228u);
        v28(v4, v2, 84, 65788);
        v29 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v29 - 1) != -626862723 )
          __break(0x8228u);
        v29(v4, v2, 68, 2);
        v30 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v30 - 1) != -626862723 )
          __break(0x8228u);
        v30(v4, v2, 4, 16);
        v31 = *(_DWORD **)(a1 - 112);
        if ( *(v31 - 1) != -1879227436 )
          __break(0x8228u);
        v32 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v31)(v4, v2, 0);
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        v13 = v32 | 1u;
        v10 = v4;
        v11 = v2;
        v12 = 0;
        goto LABEL_47;
      case 7:
        v14 = *(_DWORD **)(a1 - 104);
        if ( *(v14 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v14)(v4, v2, 0, 1);
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        v10 = v4;
        v11 = v2;
        v12 = 4;
        v13 = 8;
        goto LABEL_47;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 1:
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        v10 = v4;
        v11 = v2;
        v12 = 4;
        v13 = 1;
        goto LABEL_47;
      case 2:
        v21 = *(_DWORD **)(a1 - 104);
        if ( *(v21 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v21)(v4, v2, 84, 0);
        v22 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v22 - 1) != -626862723 )
          __break(0x8228u);
        v22(v4, v2, 84, 252);
        v23 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        if ( *((_DWORD *)v23 - 1) != -626862723 )
          __break(0x8228u);
        v23(v4, v2, 68, 2);
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        v10 = v4;
        v11 = v2;
        v12 = 4;
        v13 = 16;
        goto LABEL_47;
      case 3:
        v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
        v10 = v4;
        v11 = v2;
        v12 = 4;
        v13 = 32;
LABEL_47:
        if ( *((_DWORD *)v9 - 1) != -626862723 )
          __break(0x8228u);
        result = v9(v10, v11, v12, v13);
        __dsb(0xEu);
        return result;
    }
  }
  v18 = get_ipc_log_context(v8);
  StatusReg = _ReadStatusReg(SP_EL0);
  result = ipc_log_string(v18, "[d][%-4d]No valid test pattern requested: 0x%x\n", *(_DWORD *)(StatusReg + 1800), a2);
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]No valid test pattern requested: 0x%x\n",
             *(_DWORD *)(StatusReg + 1800),
             a2);
  return result;
}
