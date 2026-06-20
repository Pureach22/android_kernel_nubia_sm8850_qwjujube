_DWORD *__fastcall cnss_dev_rddm_timeout_hdlr(_DWORD *result)
{
  __int64 *v1; // x19
  _DWORD *v2; // x20
  unsigned __int64 StatusReg; // x22
  const char *v4; // x1
  __int64 *v5; // x24
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  const char *v13; // x1
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // x1
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  __int64 v35; // x8
  __int64 v36; // x1
  int exec_env; // w0
  __int64 v38; // x1
  __int64 v39; // x2
  __int64 v40; // x3
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  const char *v45; // x1
  const char *v46; // x1
  __int64 v47; // x1
  __int64 v48; // x2
  __int64 v49; // x3
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  __int64 v54; // x1
  __int64 v55; // x2
  __int64 v56; // x3
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  __int64 v61; // x6
  __int64 v62; // x7
  const char *v63; // x1
  unsigned int v70; // w21
  signed int v71; // w21
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v1 = (__int64 *)(result - 100);
  if ( result != dword_190 )
  {
    v2 = result;
    _X8 = result + 10;
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v70 = __ldxr(_X8);
      v71 = v70 + 1;
    }
    while ( __stlxr(v71, _X8) );
    __dmb(0xBu);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v4 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v4 = "soft_irq";
    }
    else
    {
      v4 = (const char *)(StatusReg + 2320);
    }
    v5 = (__int64 *)(result - 98);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v4,
      "cnss_dev_rddm_timeout_hdlr",
      3u,
      3u,
      "fatal: Timeout waiting for RDDM notification, driver state 0x%lx (%d)\n",
      *(_QWORD *)(*((_QWORD *)result - 49) + 552LL),
      (unsigned int)v71,
      vars0);
    if ( v71 >= 2 )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v13 = "soft_irq";
      }
      else
      {
        v13 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "cnss_dev_rddm_timeout_hdlr",
        3u,
        3u,
        "Trigger TIMEOUT recovery on continuous RDDM timeout\n",
        v11,
        v12,
        vars0a);
      if ( !(unsigned int)cnss_pci_check_link_status((__int64)v1, v14, v15, v16, v17, v18, v19, v20) )
        mhi_debug_reg_dump(*((_QWORD *)v2 - 7));
      cnss_pci_bhi_debug_reg_dump((__int64)v1, v21, v22, v23, v24, v25, v26, v27);
      cnss_pci_soc_scratch_reg_dump((__int64)v1, v28, v29, v30, v31, v32, v33, v34);
LABEL_20:
      v35 = *v1;
      v36 = 3;
      return cnss_schedule_recovery(v35 + 200, v36);
    }
    if ( (unsigned int)cnss_pci_check_link_status((__int64)v1, v6, v7, v8, v9, v10, v11, v12) )
    {
      result = (_DWORD *)cnss_get_host_sol_value(*v5);
      if ( (_DWORD)result == 1 )
        return (_DWORD *)cnss_driver_event_post(*v5, 0x15u, 0, 0);
    }
    else
    {
      exec_env = mhi_get_exec_env(*((_QWORD *)v2 - 7));
      if ( exec_env == 3 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v46 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v46 = "soft_irq";
        }
        else
        {
          v46 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v46,
          "cnss_dev_rddm_timeout_hdlr",
          6u,
          6u,
          "Device MHI EE is RDDM, try to collect dump\n",
          v43,
          v44,
          vars0a);
        v35 = *v1;
        v36 = 2;
        return cnss_schedule_recovery(v35 + 200, v36);
      }
      if ( !exec_env )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v45 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v45 = "soft_irq";
        }
        else
        {
          v45 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v45,
          "cnss_dev_rddm_timeout_hdlr",
          3u,
          3u,
          "Device MHI EE is PBL, unable to collect dump\n",
          v43,
          v44,
          vars0a);
      }
      if ( !(unsigned int)cnss_pci_check_link_status((__int64)v1, v38, v39, v40, v41, v42, v43, v44) )
        mhi_debug_reg_dump(*((_QWORD *)v2 - 7));
      cnss_pci_bhi_debug_reg_dump((__int64)v1, v47, v48, v49, v50, v51, v52, v53);
      cnss_pci_soc_scratch_reg_dump((__int64)v1, v54, v55, v56, v57, v58, v59, v60);
      result = (_DWORD *)cnss_pci_assert_host_sol((__int64)v1);
      if ( (_DWORD)result )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v63 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v63 = "soft_irq";
        }
        else
        {
          v63 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v63,
          "cnss_dev_rddm_timeout_hdlr",
          3u,
          3u,
          "Trigger TIMEOUT recovery\n",
          v61,
          v62,
          vars0a);
        goto LABEL_20;
      }
    }
  }
  return result;
}
