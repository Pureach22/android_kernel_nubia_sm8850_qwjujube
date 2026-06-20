__int64 __fastcall ipa_usb_xdci_suspend(unsigned int a1, unsigned int a2, unsigned int a3, char a4)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x23
  __int64 v10; // x0
  const char *v11; // x4
  __int64 v12; // x0
  const char *v13; // x4
  unsigned int v14; // w0
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 v19; // x0
  const char *v20; // x4
  __int64 v21; // x0
  const char *v22; // x4
  unsigned int v23; // w0
  unsigned int v24; // w0
  __int64 ipc_logbuf; // x0
  __int64 v26; // x0
  unsigned int v27; // w0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0

  mutex_lock(ipa3_usb_ctx + 544);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_xdci_suspend", 2411);
  }
  if ( a3 >= 6 )
  {
    printk(&unk_3AB53C, "ipa_usb_xdci_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d bad parameters\n", "ipa_usb_xdci_suspend", 2414);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_usb %s:%d bad parameters\n", "ipa_usb_xdci_suspend", 2414);
      v18 = -22;
      goto LABEL_93;
    }
    goto LABEL_38;
  }
  if ( a3 == 4 )
    v9 = 1;
  else
    v9 = 2 * (unsigned int)(a3 == 5);
  if ( (a4 & 1) == 0 )
  {
    if ( (ipa3_usb_check_legal_op(7, v9) & 1) == 0 )
    {
      printk(&unk_3A5362, "ipa3_usb_suspend_no_remote_wakeup");
      if ( ipa3_get_ipc_logbuf() )
      {
        v31 = ipa3_get_ipc_logbuf();
        ipc_log_string(v31, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_suspend_no_remote_wakeup", 2330);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v32 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v32, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_suspend_no_remote_wakeup", 2330);
        goto LABEL_64;
      }
LABEL_88:
      v18 = -1;
      goto LABEL_93;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      if ( a3 == 4 )
        v20 = "DPL channel";
      else
        v20 = "Data Tethering channels";
      ipc_log_string(
        v19,
        "ipa_usb %s:%d Start suspend with no remote wakeup sequence: %s\n",
        "ipa3_usb_suspend_no_remote_wakeup",
        2337,
        v20);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      if ( a3 == 4 )
        v22 = "DPL channel";
      else
        v22 = "Data Tethering channels";
      ipc_log_string(
        v21,
        "ipa_usb %s:%d Start suspend with no remote wakeup sequence: %s\n",
        "ipa3_usb_suspend_no_remote_wakeup",
        2337,
        v22);
    }
    if ( (unsigned int)ipa3_usb_check_disconnect_prot(a3) )
    {
LABEL_38:
      v18 = -22;
      goto LABEL_93;
    }
    v23 = ipa3_xdci_disconnect(a2, 0, 0xFFFFFFFF);
    if ( v23 )
    {
      v18 = v23;
      printk(&unk_3D1356, "ipa3_usb_suspend_no_remote_wakeup");
      if ( ipa3_get_ipc_logbuf() )
      {
        v43 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v43,
          "ipa_usb %s:%d failed to disconnect DL/DPL channel\n",
          "ipa3_usb_suspend_no_remote_wakeup",
          2347);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v44 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v44,
          "ipa_usb %s:%d failed to disconnect DL/DPL channel\n",
          "ipa3_usb_suspend_no_remote_wakeup",
          2347);
      }
      goto LABEL_93;
    }
    if ( a3 != 4 )
    {
      v24 = ipa3_xdci_disconnect(a1, 1, *(_DWORD *)(ipa3_usb_ctx + 520));
      if ( v24 )
      {
        v18 = v24;
        printk(&unk_3C882E, "ipa3_usb_suspend_no_remote_wakeup");
        if ( ipa3_get_ipc_logbuf() )
        {
          v46 = ipa3_get_ipc_logbuf();
          ipc_log_string(v46, "ipa_usb %s:%d failed disconnect UL channel\n", "ipa3_usb_suspend_no_remote_wakeup", 2356);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v47 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v47, "ipa_usb %s:%d failed disconnect UL channel\n", "ipa3_usb_suspend_no_remote_wakeup", 2356);
        }
        goto LABEL_46;
      }
      ++*(_DWORD *)(ipa3_usb_ctx + 520);
    }
    v18 = ((__int64 (__fastcall *)(_QWORD))ipa3_usb_disconnect_teth_prot)(a3);
    if ( v18 )
    {
      if ( a3 != 4 )
LABEL_45:
        ipa3_xdci_connect((_QWORD *)a1);
    }
    else
    {
      v27 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa3_usb_ctx + (v9 << 8) + 632));
      if ( !v27 )
      {
        if ( (ipa3_usb_set_state(6, 0, v9) & 1) == 0 )
        {
          printk(&unk_3AB618, "ipa3_usb_suspend_no_remote_wakeup");
          if ( ipa3_get_ipc_logbuf() )
          {
            v50 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v50,
              "ipa_usb %s:%d failed to change state to suspend no rwakeup\n",
              "ipa3_usb_suspend_no_remote_wakeup",
              2385);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v51 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v51,
              "ipa_usb %s:%d failed to change state to suspend no rwakeup\n",
              "ipa3_usb_suspend_no_remote_wakeup",
              2385);
          }
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v28 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v28, "ipa_usb %s:%d exit\n", "ipa3_usb_suspend_no_remote_wakeup", 2387);
          goto LABEL_25;
        }
LABEL_55:
        v18 = 0;
        goto LABEL_93;
      }
      v18 = v27;
      printk(&unk_3FCB7C, "ipa3_usb_suspend_no_remote_wakeup");
      if ( ipa3_get_ipc_logbuf() )
      {
        v48 = ipa3_get_ipc_logbuf();
        ipc_log_string(v48, "ipa_usb %s:%d failed to deactivate PM\n", "ipa3_usb_suspend_no_remote_wakeup", 2379);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v49 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v49, "ipa_usb %s:%d failed to deactivate PM\n", "ipa3_usb_suspend_no_remote_wakeup", 2379);
      }
      ipa3_usb_connect_teth_prot(a3);
      if ( a3 != 4 )
        goto LABEL_45;
    }
LABEL_46:
    ipa3_xdci_connect((_QWORD *)a2);
    goto LABEL_93;
  }
  if ( (ipa3_usb_check_legal_op(6, v9) & 1) == 0 )
  {
    printk(&unk_3A5362, "ipa_usb_xdci_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v29 = ipa3_get_ipc_logbuf();
      ipc_log_string(v29, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_xdci_suspend", 2429);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v30 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v30, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_xdci_suspend", 2429);
LABEL_64:
      v18 = -1;
      goto LABEL_93;
    }
    goto LABEL_88;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v10 = ipa3_get_ipc_logbuf();
    if ( a3 == 4 )
      v11 = "DPL channel";
    else
      v11 = "Data Tethering channels";
    ipc_log_string(v10, "ipa_usb %s:%d Start suspend sequence: %s\n", "ipa_usb_xdci_suspend", 2436, v11);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    if ( a3 == 4 )
      v13 = "DPL channel";
    else
      v13 = "Data Tethering channels";
    ipc_log_string(v12, "ipa_usb %s:%d Start suspend sequence: %s\n", "ipa_usb_xdci_suspend", 2436, v13);
  }
  if ( (ipa3_usb_set_state(4, 0, v9) & 1) != 0 )
  {
    v14 = ipa3_xdci_suspend(a1, a2, 1, *(_DWORD *)(ipa3_usb_ctx + 520), a3 == 4);
    if ( v14 )
    {
      v18 = v14;
      printk(&unk_3A53A6, "ipa_usb_xdci_suspend");
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        ipc_log_string(v35, "ipa_usb %s:%d failed to suspend\n", "ipa_usb_xdci_suspend", 2451);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v36 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v36, "ipa_usb %s:%d failed to suspend\n", "ipa_usb_xdci_suspend", 2451);
      }
    }
    else
    {
      v15 = *(unsigned int *)(ipa3_usb_ctx + (v9 << 8) + 632);
      ++*(_DWORD *)(ipa3_usb_ctx + 520);
      v16 = ((__int64 (__fastcall *)(__int64))ipa_pm_deactivate_sync)(v15);
      if ( !v16 )
      {
        if ( (ipa3_usb_set_state(5, 0, v9) & 1) == 0 )
        {
          printk(&unk_3EAE54, "ipa_usb_xdci_suspend");
          if ( ipa3_get_ipc_logbuf() )
          {
            v41 = ipa3_get_ipc_logbuf();
            ipc_log_string(v41, "ipa_usb %s:%d failed to change state to suspended\n", "ipa_usb_xdci_suspend", 2465);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v42 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v42, "ipa_usb %s:%d failed to change state to suspended\n", "ipa_usb_xdci_suspend", 2465);
          }
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v17 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v17, "ipa_usb %s:%d exit\n", "ipa_usb_xdci_suspend", 2468);
LABEL_25:
          v18 = 0;
          goto LABEL_93;
        }
        goto LABEL_55;
      }
      v18 = v16;
      printk(&unk_3EDA94, "ipa_usb_xdci_suspend");
      if ( ipa3_get_ipc_logbuf() )
      {
        v37 = ipa3_get_ipc_logbuf();
        ipc_log_string(v37, "ipa_usb %s:%d failed to deactivate PM IPA client\n", "ipa_usb_xdci_suspend", 2459);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v38 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v38, "ipa_usb %s:%d failed to deactivate PM IPA client\n", "ipa_usb_xdci_suspend", 2459);
      }
      ipa3_xdci_resume(a1, a2, a3 == 4);
    }
    if ( (ipa3_usb_set_state(2, 1u, v9) & 1) == 0 )
    {
      printk(&unk_3B9A91, "ipa_usb_xdci_suspend");
      if ( ipa3_get_ipc_logbuf() )
      {
        v39 = ipa3_get_ipc_logbuf();
        ipc_log_string(v39, "ipa_usb %s:%d failed to change state back to connected\n", "ipa_usb_xdci_suspend", 2478);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v40 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v40, "ipa_usb %s:%d failed to change state back to connected\n", "ipa_usb_xdci_suspend", 2478);
      }
    }
  }
  else
  {
    printk(&unk_3F3E03, "ipa_usb_xdci_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v33 = ipa3_get_ipc_logbuf();
      ipc_log_string(v33, "ipa_usb %s:%d fail changing state to suspend_req\n", "ipa_usb_xdci_suspend", 2441);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v34 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v34, "ipa_usb %s:%d fail changing state to suspend_req\n", "ipa_usb_xdci_suspend", 2441);
    }
    v18 = -14;
  }
LABEL_93:
  mutex_unlock(ipa3_usb_ctx + 544);
  return v18;
}
