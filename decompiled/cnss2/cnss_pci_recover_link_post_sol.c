__int64 __fastcall cnss_pci_recover_link_post_sol(_QWORD *a1)
{
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  __int64 v6; // x5
  __int64 v7; // x6
  __int64 v8; // x7
  unsigned int v9; // w0
  __int64 v10; // x7
  unsigned int v11; // w20
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x6
  __int64 v22; // x7
  unsigned __int64 v23; // x8
  const char *v24; // x1
  __int16 v25; // w9
  const char *v26; // x8
  unsigned int v27; // w21
  unsigned int v28; // w20
  unsigned __int64 v29; // x26
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  unsigned int exec_env; // w0
  __int64 v38; // x1
  __int64 v39; // x2
  __int64 v40; // x3
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  const char *v45; // x1
  __int16 v46; // w9
  const char *v47; // x8
  char v49; // w0
  unsigned __int64 v50; // x20
  const char *v51; // x1
  __int64 v52; // x6
  __int64 v53; // x7
  const char *v54; // x1
  char v55; // [xsp+0h] [xbp-10h]
  char v56; // [xsp+0h] [xbp-10h]

  mutex_lock(a1 + 75);
  v9 = cnss_resume_pci_link(a1, v2, v3, v4, v5, v6, v7, v8);
  if ( v9 )
  {
    v11 = v9;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v25 = *(_DWORD *)(StatusReg + 16);
      v26 = (const char *)(StatusReg + 2320);
      if ( (v25 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v26;
    }
    v27 = 3;
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_recover_link_post_sol",
      3u,
      3u,
      "Failed to resume PCI link post host sol, err= %d\n",
      v9,
      v10,
      v55);
    mutex_unlock(a1 + 75);
  }
  else
  {
    mutex_unlock(a1 + 75);
    if ( (unsigned int)cnss_pci_check_link_status((__int64)a1, v14, v15, v16, v17, v18, v19, v20) )
    {
LABEL_5:
      v23 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v23 + 16) & 0xF0000) != 0 )
      {
        v24 = "irq";
      }
      else
      {
        v46 = *(_DWORD *)(v23 + 16);
        v47 = (const char *)(v23 + 2320);
        if ( (v46 & 0xFF00) != 0 )
          v24 = "soft_irq";
        else
          v24 = v47;
      }
      v27 = 3;
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v24,
        "cnss_pci_recover_link_post_sol",
        3u,
        3u,
        "PCI Link is down, skip to recovery\n",
        v21,
        v22,
        v55);
      v11 = 0;
    }
    else
    {
      v28 = 1;
      v29 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        msleep(20);
        exec_env = mhi_get_exec_env(a1[43]);
        if ( exec_env == 3 )
        {
          v49 = timer_delete(a1 + 50);
          v50 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
          {
            v51 = "irq";
          }
          else if ( (*(_DWORD *)(v50 + 16) & 0xFF00) != 0 )
          {
            v51 = "soft_irq";
          }
          else
          {
            v51 = (const char *)(v50 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v51,
            "__cnss_del_rddm_timer",
            7u,
            7u,
            "Delete RDDM timer @%s(%d), ret %d\n",
            (__int64)"cnss_pci_recover_link_post_sol",
            6952,
            v49);
          if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
          {
            v54 = "irq";
          }
          else if ( (*(_DWORD *)(v50 + 16) & 0xFF00) != 0 )
          {
            v54 = "soft_irq";
          }
          else
          {
            v54 = (const char *)(v50 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v54,
            "cnss_pci_recover_link_post_sol",
            6u,
            6u,
            "Device in RDDM after link recovery, try to collect dump\n",
            v52,
            v53,
            v56);
          v11 = 0;
          v27 = 2;
          goto LABEL_23;
        }
        if ( v28 == 21 )
          break;
        v45 = "irq";
        if ( (*(_DWORD *)(v29 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
            v45 = "soft_irq";
          else
            v45 = (const char *)(v29 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v45,
          "cnss_pci_recover_link_post_sol",
          7u,
          7u,
          "Wait for RDDM after link recovery, retry #%d, Device EE: %d\n",
          v28++,
          exec_env,
          v55);
        if ( (unsigned int)cnss_pci_check_link_status((__int64)a1, v30, v31, v32, v33, v34, v35, v36) )
          goto LABEL_5;
      }
      if ( !(unsigned int)cnss_pci_check_link_status((__int64)a1, v38, v39, v40, v41, v42, v43, v44) )
        mhi_debug_reg_dump(a1[43]);
      cnss_pci_bhi_debug_reg_dump(a1);
      cnss_pci_soc_scratch_reg_dump(a1);
      v11 = 0;
      v27 = 3;
    }
  }
LABEL_23:
  cnss_schedule_recovery(*a1 + 200LL, v27);
  return v11;
}
