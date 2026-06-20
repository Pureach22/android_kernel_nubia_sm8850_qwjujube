__int64 __fastcall dp_power_clk_set_rate(_QWORD *a1, unsigned int a2, char a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned int v5; // w9
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w19
  __int64 v9; // x0
  void *v10; // x0
  __int64 v13; // x0
  __int64 ipc_log_context; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22992C, "dp_power_clk_set_rate");
    return 4294967274LL;
  }
  v3 = *a1 + 48LL * a2;
  v4 = *(_QWORD *)(v3 + 56);
  v5 = *(_DWORD *)(v3 + 48);
  if ( (a3 & 1) != 0 )
  {
    v6 = msm_dss_clk_set_rate(*(_QWORD *)(v3 + 56), v5);
    if ( (_DWORD)v6 )
    {
      v8 = v6;
      v15 = get_ipc_log_context(v6);
      ipc_log_string(v15, "[e][%-4d]failed to set clks rate.\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v10 = &unk_24EA27;
      goto LABEL_12;
    }
    result = msm_dss_enable_clk(*(_QWORD *)(v3 + 56), *(unsigned int *)(v3 + 48), 1);
    if ( (_DWORD)result )
    {
      v8 = result;
      v9 = get_ipc_log_context(result);
      ipc_log_string(v9, "[e][%-4d]failed to enable clks\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v10 = &unk_24815F;
LABEL_12:
      printk(v10, "dp_power_clk_set_rate");
      return v8;
    }
  }
  else
  {
    v13 = msm_dss_enable_clk(v4, v5, 0);
    if ( (_DWORD)v13 )
    {
      v8 = v13;
      v16 = get_ipc_log_context(v13);
      ipc_log_string(v16, "[e][%-4d]failed to disable clks\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v10 = &unk_260F78;
      goto LABEL_12;
    }
    dp_power_park_module(a1, a2);
    return 0;
  }
  return result;
}
