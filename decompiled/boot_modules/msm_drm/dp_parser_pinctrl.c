unsigned __int64 __fastcall dp_parser_pinctrl(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned int v5; // w19
  __int64 v6; // x0
  unsigned __int64 result; // x0
  __int64 v8; // x0
  unsigned __int64 StatusReg; // x19
  unsigned __int64 v10; // x19
  __int64 ipc_log_context; // x0

  v2 = devm_pinctrl_get(*a1 + 16LL);
  a1[44] = v2;
  if ( v2 && v2 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = ((__int64 (*)(void))pinctrl_lookup_state)();
    a1[45] = v3;
    if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      v10 = v3;
      ipc_log_context = get_ipc_log_context(v3);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]failed to get pinctrl active state, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v10);
      printk(&unk_27C1FE, "dp_parser_pinctrl");
      return v10;
    }
    v4 = pinctrl_lookup_state(a1[44], "mdss_dp_sleep");
    a1[49] = v4;
    if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = v4;
      v6 = get_ipc_log_context(v4);
      ipc_log_string(
        v6,
        "[e][%-4d]failed to get pinctrl suspend state, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v5);
      printk(&unk_260E7B, "dp_parser_pinctrl");
      return v5;
    }
  }
  else
  {
    v8 = get_ipc_log_context(v2);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v8, "[d][%-4d]failed to get pinctrl, rc=%d\n", *(_DWORD *)(StatusReg + 1800), 0);
    result = 0;
    if ( (_drm_debug & 4) == 0 )
      return result;
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]failed to get pinctrl, rc=%d\n", *(_DWORD *)(StatusReg + 1800), 0);
  }
  return 0;
}
