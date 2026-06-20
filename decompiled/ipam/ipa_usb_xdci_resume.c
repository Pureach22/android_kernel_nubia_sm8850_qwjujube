__int64 __fastcall ipa_usb_xdci_resume(unsigned int a1, unsigned int a2, unsigned int a3)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  unsigned int v9; // w23
  __int64 v10; // x0
  __int64 v11; // x0
  const char *v12; // x4
  __int64 v13; // x0
  const char *v14; // x4
  unsigned int v15; // w22
  unsigned int v16; // w0
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x0
  long double v20; // q0
  __int64 v21; // x0
  const char *v22; // x4
  __int64 v23; // x0
  const char *v24; // x4
  const char *v25; // x19
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w0
  unsigned int v29; // w0
  __int64 v30; // x0
  __int64 ipc_logbuf; // x0
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
  long double v42; // q0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  unsigned __int8 v55[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)v55 = 0;
  mutex_lock(ipa3_usb_ctx + 544);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_xdci_resume", 2573);
  }
  if ( a3 >= 6 )
  {
    printk(&unk_3AB53C, "ipa_usb_xdci_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d bad parameters\n", "ipa_usb_xdci_resume", 2576);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v32 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v32, "ipa_usb %s:%d bad parameters\n", "ipa_usb_xdci_resume", 2576);
    }
    v15 = -22;
  }
  else
  {
    if ( a3 == 4 )
      v7 = 1;
    else
      v7 = 2 * (unsigned int)(a3 == 5);
    if ( (ipa3_usb_check_legal_op(8, v7) & 1) != 0 )
    {
      v8 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
      v9 = *(_DWORD *)(ipa3_usb_ctx + (v7 << 8) + 656);
      raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v8);
      v10 = ipa3_get_ipc_logbuf();
      if ( v9 == 6 )
      {
        if ( v10 )
        {
          v11 = ipa3_get_ipc_logbuf();
          if ( a3 == 4 )
            v12 = "DPL channel";
          else
            v12 = "Data Tethering channels";
          ipc_log_string(
            v11,
            "ipa_usb %s:%d Start resume with no remote wakeup sequence: %s\n",
            "ipa3_usb_resume_no_remote_wakeup",
            2496,
            v12);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v13 = ipa3_get_ipc_logbuf_low();
          if ( a3 == 4 )
            v14 = "DPL channel";
          else
            v14 = "Data Tethering channels";
          ipc_log_string(
            v13,
            "ipa_usb %s:%d Start resume with no remote wakeup sequence: %s\n",
            "ipa3_usb_resume_no_remote_wakeup",
            2496,
            v14);
        }
        v15 = ipa_pm_activate_sync(*(_DWORD *)(ipa3_usb_ctx + (v7 << 8) + 632));
        if ( !v15 )
        {
          v16 = ipa3_usb_connect_teth_prot(a3);
          if ( v16 )
          {
            v15 = v16;
            printk(&unk_3B3849, "ipa3_usb_resume_no_remote_wakeup");
            if ( ipa3_get_ipc_logbuf() )
            {
              v37 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v37,
                "ipa_usb %s:%d failed to connect teth protocol\n",
                "ipa3_usb_resume_no_remote_wakeup",
                2507);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v38 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v38,
                "ipa_usb %s:%d failed to connect teth protocol\n",
                "ipa3_usb_resume_no_remote_wakeup",
                2507);
            }
            goto LABEL_104;
          }
          if ( a3 != 4 )
          {
            v17 = ipa3_xdci_connect((_QWORD *)a1);
            if ( v17 )
            {
              v15 = v17;
              printk(&unk_3F0B47, "ipa3_usb_resume_no_remote_wakeup");
              if ( ipa3_get_ipc_logbuf() )
              {
                v48 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v48,
                  "ipa_usb %s:%d failed to start UL channel\n",
                  "ipa3_usb_resume_no_remote_wakeup",
                  2515);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v49 = ipa3_get_ipc_logbuf_low();
                v20 = ipc_log_string(
                        v49,
                        "ipa_usb %s:%d failed to start UL channel\n",
                        "ipa3_usb_resume_no_remote_wakeup",
                        2515);
              }
              goto LABEL_103;
            }
          }
          v15 = ipa3_xdci_connect((_QWORD *)a2);
          if ( v15 )
          {
            printk(&unk_3B9ACB, "ipa3_usb_resume_no_remote_wakeup");
            if ( ipa3_get_ipc_logbuf() )
            {
              v39 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v39,
                "ipa_usb %s:%d failed to start DL/DPL channel\n",
                "ipa3_usb_resume_no_remote_wakeup",
                2523);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v40 = ipa3_get_ipc_logbuf_low();
              v20 = ipc_log_string(
                      v40,
                      "ipa_usb %s:%d failed to start DL/DPL channel\n",
                      "ipa3_usb_resume_no_remote_wakeup",
                      2523);
            }
            goto LABEL_82;
          }
          if ( (ipa3_usb_set_state(2, 0, v7) & 1) == 0 )
          {
            printk(&unk_3E5069, "ipa3_usb_resume_no_remote_wakeup");
            if ( ipa3_get_ipc_logbuf() )
            {
              v18 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v18,
                "ipa_usb %s:%d failed to change state to connected\n",
                "ipa3_usb_resume_no_remote_wakeup",
                2537);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v19 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v19,
                "ipa_usb %s:%d failed to change state to connected\n",
                "ipa3_usb_resume_no_remote_wakeup",
                2537);
            }
            ipa3_xdci_disconnect(a2, 0, 0xFFFFFFFF);
            v15 = -14;
LABEL_82:
            if ( a3 != 4 )
            {
              ipa3_xdci_disconnect(a1, 1, *(_DWORD *)(ipa3_usb_ctx + 520));
              ++*(_DWORD *)(ipa3_usb_ctx + 520);
            }
LABEL_103:
            ((void (__fastcall *)(_QWORD, long double))ipa3_usb_disconnect_teth_prot)(a3, v20);
LABEL_104:
            ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa3_usb_ctx + (v7 << 8) + 632));
          }
        }
      }
      else
      {
        if ( v10 )
        {
          v21 = ipa3_get_ipc_logbuf();
          if ( a3 == 4 )
            v22 = "DPL channel";
          else
            v22 = "Data Tethering channels";
          ipc_log_string(v21, "ipa_usb %s:%d Start resume sequence: %s\n", "ipa_usb_xdci_resume", 2600, v22);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          if ( a3 == 4 )
            v24 = "DPL channel";
          else
            v24 = "Data Tethering channels";
          ipc_log_string(v23, "ipa_usb %s:%d Start resume sequence: %s\n", "ipa_usb_xdci_resume", 2600, v24);
        }
        if ( (ipa3_usb_set_state(7, 0, v7) & 1) != 0 )
        {
          v15 = ipa_pm_activate_sync(*(_DWORD *)(ipa3_usb_ctx + (v7 << 8) + 632));
          if ( !v15 )
          {
            if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
            {
              *(_WORD *)v55 = 0;
              ipa_cfg_ep_ctrl(a2, v55);
            }
            if ( a3 != 4 && (v28 = ((__int64 (__fastcall *)(_QWORD))ipa3_start_gsi_channel)(a1)) != 0 )
            {
              v15 = v28;
              printk(&unk_3F0B47, "ipa_usb_xdci_resume");
              if ( ipa3_get_ipc_logbuf() )
              {
                v51 = ipa3_get_ipc_logbuf();
                ipc_log_string(v51, "ipa_usb %s:%d failed to start UL channel\n", "ipa_usb_xdci_resume", 2626);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v52 = ipa3_get_ipc_logbuf_low();
                v42 = ipc_log_string(v52, "ipa_usb %s:%d failed to start UL channel\n", "ipa_usb_xdci_resume", 2626);
              }
            }
            else
            {
              v29 = ((__int64 (__fastcall *)(_QWORD))ipa3_start_gsi_channel)(a2);
              if ( v29 )
              {
                v15 = v29;
                printk(&unk_3B9ACB, "ipa_usb_xdci_resume");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v41 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v41, "ipa_usb %s:%d failed to start DL/DPL channel\n", "ipa_usb_xdci_resume", 2634);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v43 = ipa3_get_ipc_logbuf_low();
                  v42 = ipc_log_string(
                          v43,
                          "ipa_usb %s:%d failed to start DL/DPL channel\n",
                          "ipa_usb_xdci_resume",
                          2634);
                }
              }
              else
              {
                if ( (ipa3_usb_set_state(2, 0, v7) & 1) != 0 )
                {
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v30 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v30, "ipa_usb %s:%d exit\n", "ipa_usb_xdci_resume", 2645);
                  }
                  v15 = 0;
                  goto LABEL_105;
                }
                printk(&unk_3E5069, "ipa_usb_xdci_resume");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v44 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v44,
                    "ipa_usb %s:%d failed to change state to connected\n",
                    "ipa_usb_xdci_resume",
                    2640);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v45 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v45,
                    "ipa_usb %s:%d failed to change state to connected\n",
                    "ipa_usb_xdci_resume",
                    2640);
                }
                v15 = ipa_stop_gsi_channel(a2);
                if ( v15 )
                {
                  printk(&unk_3DCFAB, "ipa_usb_xdci_resume");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v53 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v53,
                      "ipa_usb %s:%d Error stopping DL/DPL channel: %d\n",
                      "ipa_usb_xdci_resume",
                      2653,
                      v15);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v54 = ipa3_get_ipc_logbuf_low();
                    v42 = ipc_log_string(
                            v54,
                            "ipa_usb %s:%d Error stopping DL/DPL channel: %d\n",
                            "ipa_usb_xdci_resume",
                            2653,
                            v15);
                  }
                }
              }
              if ( a3 != 4 )
              {
                v15 = ipa_stop_gsi_channel(a1);
                if ( v15 )
                {
                  printk(&unk_3CB160, "ipa_usb_xdci_resume");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v46 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v46,
                      "ipa_usb %s:%d Error stopping UL channel: %d\n",
                      "ipa_usb_xdci_resume",
                      2658,
                      v15);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v47 = ipa3_get_ipc_logbuf_low();
                    v42 = ipc_log_string(
                            v47,
                            "ipa_usb %s:%d Error stopping UL channel: %d\n",
                            "ipa_usb_xdci_resume",
                            2658,
                            v15);
                  }
                }
              }
            }
            ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)(
              *(unsigned int *)(ipa3_usb_ctx + (v7 << 8) + 632),
              v42);
          }
          if ( (ipa3_usb_set_state(v9, 1u, v7) & 1) == 0 )
          {
            v25 = (const char *)ipa3_usb_state_to_string(v9);
            printk(&unk_3A53C9, "ipa_usb_xdci_resume");
            if ( ipa3_get_ipc_logbuf() )
            {
              v26 = ipa3_get_ipc_logbuf();
              ipc_log_string(v26, "ipa_usb %s:%d failed to change state back to %s\n", "ipa_usb_xdci_resume", 2667, v25);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v27 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v27, "ipa_usb %s:%d failed to change state back to %s\n", "ipa_usb_xdci_resume", 2667, v25);
            }
          }
          goto LABEL_105;
        }
        printk(&unk_3EAEB2, "ipa_usb_xdci_resume");
        if ( ipa3_get_ipc_logbuf() )
        {
          v35 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v35,
            "ipa_usb %s:%d failed to change state to resume_in_progress\n",
            "ipa_usb_xdci_resume",
            2604);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v36 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v36,
            "ipa_usb %s:%d failed to change state to resume_in_progress\n",
            "ipa_usb_xdci_resume",
            2604);
        }
        v15 = -14;
      }
    }
    else
    {
      printk(&unk_3A5362, "ipa_usb_xdci_resume");
      if ( ipa3_get_ipc_logbuf() )
      {
        v33 = ipa3_get_ipc_logbuf();
        ipc_log_string(v33, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_xdci_resume", 2584);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v34 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v34, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_xdci_resume", 2584);
      }
      v15 = -1;
    }
  }
LABEL_105:
  mutex_unlock(ipa3_usb_ctx + 544);
  _ReadStatusReg(SP_EL0);
  return v15;
}
