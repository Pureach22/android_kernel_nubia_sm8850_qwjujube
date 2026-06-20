__int64 __fastcall cnss_pci_recover_link_down(__int64 a1)
{
  unsigned int v1; // w8
  bool v2; // cc
  int v3; // w8
  __int64 v6; // x6
  __int64 v7; // x7
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int64 result; // x0
  __int16 v11; // w9
  const char *v12; // x8
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned int v20; // w0
  __int64 v21; // x7
  unsigned __int64 v22; // x8
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  unsigned int v33; // w0
  __int64 v34; // x7
  unsigned int v35; // w20
  unsigned __int64 v36; // x21
  const char *v37; // x1
  __int64 v38; // x1
  __int64 v39; // x2
  __int64 v40; // x3
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  char v45; // w8
  const char *v46; // x1
  int v47; // w21
  __int64 v48; // x6
  __int64 v49; // x7
  unsigned __int64 v50; // x8
  const char *v51; // x1
  unsigned int v52; // w20
  unsigned __int64 v53; // x26
  __int64 v54; // x1
  __int64 v55; // x2
  __int64 v56; // x3
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  unsigned int exec_env; // w0
  __int64 v62; // x1
  __int64 v63; // x2
  __int64 v64; // x3
  __int64 v65; // x4
  __int64 v66; // x5
  __int64 v67; // x6
  __int64 v68; // x7
  const char *v69; // x1
  __int16 v70; // w9
  const char *v71; // x8
  __int64 v72; // x8
  __int64 v73; // x1
  char v74; // w0
  unsigned __int64 v75; // x20
  const char *v76; // x1
  __int64 v77; // x1
  __int64 v78; // x2
  __int64 v79; // x3
  __int64 v80; // x4
  __int64 v81; // x5
  __int64 v82; // x6
  __int64 v83; // x7
  __int64 v84; // x1
  __int64 v85; // x2
  __int64 v86; // x3
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  __int64 v91; // x6
  __int64 v92; // x7
  const char *v93; // x1
  char v94; // [xsp+0h] [xbp-60h]
  char v95; // [xsp+0h] [xbp-60h]

  v1 = *(_DWORD *)(a1 + 24) - 4353;
  v2 = v1 > 0x11;
  v3 = (1 << v1) & 0x32245;
  if ( v2 || v3 == 0 )
    return 4294967201LL;
  if ( !(unsigned int)wait_for_completion_timeout(a1 + 368, 1250) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v12;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_pci_recover_link_down",
      3u,
      3u,
      "Timeout waiting for wake event after link down\n",
      v6,
      v7,
      v94);
  }
  mutex_lock(a1 + 600);
  v20 = cnss_suspend_pci_link((_BYTE *)a1, v13, v14, v15, v16, v17, v18, v19);
  if ( v20 )
  {
    v22 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
    {
      v23 = "irq";
    }
    else
    {
      v24 = *(_DWORD *)(v22 + 16);
      v25 = (const char *)(v22 + 2320);
      if ( (v24 & 0xFF00) != 0 )
        v23 = "soft_irq";
      else
        v23 = v25;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v23,
      "cnss_pci_recover_link_down",
      3u,
      3u,
      "Failed to suspend PCI link, err = %d\n",
      v20,
      v21,
      v94);
  }
  mutex_unlock(a1 + 600);
  mutex_lock(a1 + 600);
  v33 = cnss_resume_pci_link((_QWORD *)a1, v26, v27, v28, v29, v30, v31, v32);
  if ( v33 )
  {
    v35 = v33;
    v36 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v36 + 16) & 0xF0000) != 0 )
    {
      v37 = "irq";
    }
    else if ( (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
    {
      v37 = "soft_irq";
    }
    else
    {
      v37 = (const char *)(v36 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v37,
      "cnss_pci_recover_link_down",
      3u,
      3u,
      "Failed to resume PCI link, err = %d\n",
      v33,
      v34,
      v94);
    v45 = timer_delete((timer_t)(a1 + 400));
    if ( (*(_DWORD *)(v36 + 16) & 0xF0000) != 0 )
    {
      v46 = "irq";
    }
    else if ( (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
    {
      v46 = "soft_irq";
    }
    else
    {
      v46 = (const char *)(v36 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v46,
      "__cnss_del_rddm_timer",
      7u,
      7u,
      "Delete RDDM timer @%s(%d), ret %d\n",
      (__int64)"cnss_pci_recover_link_down",
      7011,
      v45);
    v47 = cnss_pci_assert_host_sol(a1);
    mutex_unlock(a1 + 600);
    if ( v47 )
      return v35;
    else
      return 0;
  }
  mutex_unlock(a1 + 600);
  if ( (*(_QWORD *)(a1 + 352) & 1) == 0 )
    return 4294967274LL;
  if ( (unsigned int)cnss_pci_check_link_status(a1, v38, v39, v40, v41, v42, v43, v44) )
  {
LABEL_37:
    v50 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
    {
      v51 = "irq";
    }
    else
    {
      v70 = *(_DWORD *)(v50 + 16);
      v71 = (const char *)(v50 + 2320);
      if ( (v70 & 0xFF00) != 0 )
        v51 = "soft_irq";
      else
        v51 = v71;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v51,
      "cnss_pci_recover_link_down",
      3u,
      3u,
      "PCI Link is down, skip to recovery\n",
      v48,
      v49,
      v94);
LABEL_51:
    v72 = *(_QWORD *)a1;
    v73 = 3;
LABEL_52:
    cnss_schedule_recovery(v72 + 200, v73);
    return 0;
  }
  v52 = 1;
  v53 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    msleep(20);
    exec_env = mhi_get_exec_env(*(_QWORD *)(a1 + 344));
    if ( exec_env == 3 )
    {
      v74 = timer_delete((timer_t)(a1 + 400));
      v75 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v75 + 16) & 0xF0000) != 0 )
      {
        v76 = "irq";
      }
      else if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
      {
        v76 = "soft_irq";
      }
      else
      {
        v76 = (const char *)(v75 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v76,
        "__cnss_del_rddm_timer",
        7u,
        7u,
        "Delete RDDM timer @%s(%d), ret %d\n",
        (__int64)"cnss_pci_recover_link_down",
        7041,
        v74);
      if ( (*(_DWORD *)(v75 + 16) & 0xF0000) != 0 )
      {
        v93 = "irq";
      }
      else if ( (*(_DWORD *)(v75 + 16) & 0xFF00) != 0 )
      {
        v93 = "soft_irq";
      }
      else
      {
        v93 = (const char *)(v75 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v93,
        "cnss_pci_recover_link_down",
        6u,
        6u,
        "Device in RDDM after link recovery, try to collect dump\n",
        v91,
        v92,
        v95);
      v72 = *(_QWORD *)a1;
      v73 = 2;
      goto LABEL_52;
    }
    if ( v52 == 21 )
      break;
    v69 = "irq";
    if ( (*(_DWORD *)(v53 + 16) & 0xF0000) == 0 )
    {
      if ( (*(_DWORD *)(v53 + 16) & 0xFF00) != 0 )
        v69 = "soft_irq";
      else
        v69 = (const char *)(v53 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v69,
      "cnss_pci_recover_link_down",
      7u,
      7u,
      "Wait for RDDM after link recovery, retry #%d, Device EE: %d\n",
      v52++,
      exec_env,
      v94);
    if ( (unsigned int)cnss_pci_check_link_status(a1, v54, v55, v56, v57, v58, v59, v60) )
      goto LABEL_37;
  }
  if ( !(unsigned int)cnss_pci_check_link_status(a1, v62, v63, v64, v65, v66, v67, v68) )
    mhi_debug_reg_dump(*(_QWORD *)(a1 + 344));
  cnss_pci_bhi_debug_reg_dump(a1, v77, v78, v79, v80, v81, v82, v83);
  cnss_pci_soc_scratch_reg_dump(a1, v84, v85, v86, v87, v88, v89, v90);
  result = cnss_pci_assert_host_sol(a1);
  if ( (_DWORD)result )
    goto LABEL_51;
  return result;
}
