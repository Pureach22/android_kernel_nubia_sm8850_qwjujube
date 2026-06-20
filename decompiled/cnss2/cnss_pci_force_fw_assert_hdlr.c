__int64 __fastcall cnss_pci_force_fw_assert_hdlr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x21
  __int64 sync; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  unsigned int *v26; // x8
  unsigned int v27; // w20
  __int64 v29; // x6
  __int64 v30; // x7
  unsigned int v31; // w20
  __int64 v32; // x8
  unsigned __int64 v33; // x22
  const char *v34; // x1
  unsigned __int64 StatusReg; // x8
  const char *v36; // x1
  __int16 v37; // w9
  const char *v38; // x8
  __int64 v39; // x21
  unsigned int *v40; // x19
  __int64 v41; // x2
  __int64 v42; // x3
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  __int64 v47; // x6
  __int64 v48; // x7
  const char *v49; // x1
  char v50; // [xsp+0h] [xbp+0h]
  char v51; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v8 = *(_QWORD *)(a1 + 8);
  if ( !v8 )
    return 4294967277LL;
  if ( (*(_QWORD *)(a1 + 352) & 4) == 0 || (*(_QWORD *)(a1 + 352) & 8) != 0 )
    return 4294967274LL;
  sync = cnss_pci_pm_runtime_get_sync((unsigned int *)a1, 0, a3, a4, a5, a6, a7, a8);
  if ( (sync & 0x80000000) != 0 )
  {
    v27 = sync;
    goto LABEL_30;
  }
  v18 = a1;
  if ( (*(_BYTE *)(a1 + 698) & 1) == 0 )
  {
    cnss_pci_mhi_reg_dump(a1);
    v18 = a1;
  }
  if ( (unsigned int)cnss_pci_check_link_status(v18, v11, v12, v13, v14, v15, v16, v17) )
  {
    sync = cnss_pci_link_down(*(_QWORD *)a1 + 200LL, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_10;
  }
  sync = cnss_pci_set_mhi_state(a1, 8);
  if ( (_DWORD)sync )
  {
    v31 = sync;
    v32 = a1;
    if ( *(_BYTE *)(a1 + 698) == 1 )
    {
      cnss_pci_mhi_reg_dump(a1);
      v32 = a1;
      *(_BYTE *)(a1 + 698) = 0;
    }
    if ( (*(_QWORD *)(v32 + 352) & 4) == 0 || (*(_QWORD *)(v32 + 352) & 8) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v36 = "irq";
      }
      else
      {
        v37 = *(_DWORD *)(StatusReg + 16);
        v38 = (const char *)(StatusReg + 2320);
        if ( (v37 & 0xFF00) != 0 )
          v36 = "soft_irq";
        else
          v36 = v38;
      }
      sync = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v36,
               "cnss_pci_force_fw_assert_hdlr",
               7u,
               7u,
               "MHI is not powered on, ignore RDDM failure\n",
               v29,
               v30,
               v50);
    }
    else
    {
      v33 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v33 + 16) & 0xF0000) != 0 )
      {
        v34 = "irq";
      }
      else if ( (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
      {
        v34 = "soft_irq";
      }
      else
      {
        v34 = (const char *)(v33 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v34,
        "cnss_pci_force_fw_assert_hdlr",
        3u,
        3u,
        "fatal: Failed to trigger RDDM, err = %d\n",
        v31,
        v30,
        v50);
      sync = cnss_pci_assert_host_sol(a1);
      if ( (_DWORD)sync )
      {
        if ( (*(_DWORD *)(v33 + 16) & 0xF0000) != 0 )
        {
          v49 = "irq";
        }
        else if ( (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
        {
          v49 = "soft_irq";
        }
        else
        {
          v49 = (const char *)(v33 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v49,
          "cnss_pci_force_fw_assert_hdlr",
          7u,
          7u,
          "Sending Host Reset Req\n",
          v47,
          v48,
          v51);
        sync = cnss_mhi_force_reset(a1);
        if ( (_DWORD)sync )
        {
          cnss_pci_dump_debug_reg(a1);
          sync = (__int64)cnss_schedule_recovery(*(_QWORD *)a1 + 200LL, 0);
          goto LABEL_10;
        }
        goto LABEL_44;
      }
    }
    v27 = 0;
LABEL_30:
    v26 = (unsigned int *)a1;
    goto LABEL_31;
  }
LABEL_44:
  v26 = (unsigned int *)a1;
  if ( *(_BYTE *)(a1 + 698) == 1 )
  {
    sync = cnss_pci_mhi_reg_dump(a1);
    v26 = (unsigned int *)a1;
    *(_BYTE *)(a1 + 698) = 0;
  }
  if ( (*(_QWORD *)(v8 + 552) & 0x800) != 0 )
    goto LABEL_11;
  sync = _cnss_start_rddm_timer(a1, (__int64)"cnss_pci_force_fw_assert_hdlr", 0x1BE9u);
LABEL_10:
  v26 = (unsigned int *)a1;
LABEL_11:
  v27 = 0;
LABEL_31:
  v39 = *(_QWORD *)v26;
  v40 = v26;
  *(_QWORD *)(v39 + 720) = ktime_get_mono_fast_ns(sync);
  cnss_pci_pm_runtime_put_autosuspend(v40, 0, v41, v42, v43, v44, v45, v46);
  return v27;
}
