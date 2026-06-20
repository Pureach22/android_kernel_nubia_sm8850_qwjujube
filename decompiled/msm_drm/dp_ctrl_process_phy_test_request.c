__int64 __fastcall dp_ctrl_process_phy_test_request(__int64 a1)
{
  int v2; // w21
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  int v5; // w2
  void (*v6)(void); // x8
  void (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x1
  void (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x1
  void (__fastcall *v11)(_QWORD); // x8
  void (*v12)(void); // x8
  _DWORD *v13; // x8
  __int64 v14; // x3
  __int64 v15; // x2
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x1
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 result; // x0
  __int64 v23; // x0
  __int64 v24; // x0

  if ( a1 )
  {
    v2 = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 120LL);
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(_DWORD *)(StatusReg + 1800);
    if ( v2 )
    {
      ipc_log_string(ipc_log_context, "[d][%-4d]start\n", v5);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]start\n", *(_DWORD *)(StatusReg + 1800));
      v6 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 104LL);
      if ( *((_DWORD *)v6 - 1) != -91942776 )
        __break(0x8228u);
      v6();
      v7 = *(void (__fastcall **)(__int64, __int64))(a1 + 88);
      v8 = *(_QWORD *)(a1 + 144);
      if ( *((_DWORD *)v7 - 1) != 1909714074 )
        __break(0x8228u);
      v7(a1, v8);
      v9 = *(void (__fastcall **)(__int64, __int64))(a1 + 80);
      v10 = *(_QWORD *)(a1 + 144);
      if ( *((_DWORD *)v9 - 1) != 1909714074 )
        __break(0x8228u);
      v9(a1, v10);
      v11 = *(void (__fastcall **)(_QWORD))(a1 + 24);
      if ( *((_DWORD *)v11 - 1) != 1576769688 )
        __break(0x8228u);
      v11(a1);
      v12 = *(void (**)(void))(*(_QWORD *)(a1 + 136) + 56LL);
      if ( *((_DWORD *)v12 - 1) != 1808488031 )
        __break(0x8228u);
      v12();
      v13 = *(_DWORD **)(a1 + 16);
      v14 = *(unsigned __int8 *)(a1 + 260);
      v15 = *(unsigned __int8 *)(a1 + 259);
      v16 = *(unsigned __int8 *)(a1 + 258);
      if ( *(v13 - 1) != -849684263 )
        __break(0x8228u);
      v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v13)(a1, v16, v15, v14, 0);
      if ( (_DWORD)v17 )
      {
        v24 = get_ipc_log_context(v17);
        ipc_log_string(v24, "[e][%-4d]failed to enable DP controller\n", *(_DWORD *)(StatusReg + 1800));
        printk(&unk_21144A, "dp_ctrl_process_phy_test_request");
      }
      v18 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 72);
      v19 = *(_QWORD *)(a1 + 144);
      if ( *((_DWORD *)v18 - 1) != 1569445852 )
        __break(0x8228u);
      v20 = v18(a1, v19);
      v21 = get_ipc_log_context(v20);
      result = ipc_log_string(v21, "[d][%-4d]end\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]end\n", *(unsigned int *)(StatusReg + 1800));
    }
    else
    {
      result = ipc_log_string(ipc_log_context, "[d][%-4d]no test pattern selected by sink\n", v5);
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]no test pattern selected by sink\n",
                 *(unsigned int *)(StatusReg + 1800));
    }
  }
  else
  {
    v23 = get_ipc_log_context(0);
    ipc_log_string(v23, "[e][%-4d]Invalid input data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_23AC6D, "dp_ctrl_process_phy_test_request");
  }
  return result;
}
