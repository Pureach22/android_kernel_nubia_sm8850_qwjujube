__int64 __fastcall ipa_usb_xdci_disconnect(unsigned int a1, unsigned int a2, unsigned int a3)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x23
  __int64 v8; // x0
  __int64 v9; // x19
  unsigned int v10; // w19
  int v11; // w25
  unsigned int v12; // w0
  __int64 v13; // x1
  __int64 v14; // x0
  int v15; // w25
  unsigned int v16; // w0
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 ipc_logbuf; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int128 v28; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0u;
  mutex_lock(ipa3_usb_ctx + 544);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_xdci_disconnect", 2096);
  }
  if ( a3 == 4 )
    v7 = 1;
  else
    v7 = 2 * (unsigned int)(a3 == 5);
  if ( (ipa3_usb_check_legal_op(3, v7) & 1) != 0 )
  {
    v8 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
    v9 = v8;
    if ( *(_DWORD *)(ipa3_usb_ctx + (v7 << 8) + 656) == 6 )
    {
      raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v8);
      v10 = ipa_usb_xdci_dismiss_channels(a1, a2, a3);
      goto LABEL_31;
    }
    if ( (unsigned int)ipa3_usb_check_disconnect_prot(a3) )
    {
      raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v9);
      v10 = -22;
      goto LABEL_31;
    }
    v11 = *(_DWORD *)(ipa3_usb_ctx + (v7 << 8) + 656);
    raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v9);
    if ( v11 == 5 )
    {
      *(_QWORD *)((char *)&v28 + 4) = 0;
      HIDWORD(v28) = 1;
      LODWORD(v28) = 0;
      ipa3_cfg_ep_holb(a2, &v28);
    }
    else
    {
      v12 = ipa3_xdci_disconnect(a2, 0, 0xFFFFFFFF);
      if ( v12 )
      {
        v10 = v12;
        printk(&unk_3D1356, "ipa_usb_xdci_disconnect");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipa_usb %s:%d failed to disconnect DL/DPL channel\n",
            "ipa_usb_xdci_disconnect",
            2127);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v23, "ipa_usb %s:%d failed to disconnect DL/DPL channel\n", "ipa_usb_xdci_disconnect", 2127);
        }
        goto LABEL_31;
      }
    }
    v13 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
    v14 = ipa3_usb_ctx + 524;
    v15 = *(_DWORD *)(ipa3_usb_ctx + (v7 << 8) + 656);
    if ( a3 == 4 )
    {
      raw_spin_unlock_irqrestore(v14, v13);
LABEL_19:
      v10 = ipa_usb_xdci_dismiss_channels(a1, a2, a3);
      if ( !v10 )
      {
        v10 = ((__int64 (__fastcall *)(_QWORD))ipa3_usb_disconnect_teth_prot)(a3);
        if ( !v10 )
        {
          if ( v15 != 5
            && (v17 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa3_usb_ctx
                                                                                               + (v7 << 8)
                                                                                               + 632))) != 0 )
          {
            v10 = v17;
            printk(&unk_3FCB7C, "ipa_usb_xdci_disconnect");
            if ( ipa3_get_ipc_logbuf() )
            {
              v26 = ipa3_get_ipc_logbuf();
              ipc_log_string(v26, "ipa_usb %s:%d failed to deactivate PM\n", "ipa_usb_xdci_disconnect", 2182);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v27 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v27, "ipa_usb %s:%d failed to deactivate PM\n", "ipa_usb_xdci_disconnect", 2182);
            }
          }
          else
          {
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v18 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v18, "ipa_usb %s:%d exit\n", "ipa_usb_xdci_disconnect", 2187);
            }
            v10 = 0;
          }
        }
      }
      goto LABEL_31;
    }
    raw_spin_unlock_irqrestore(v14, v13);
    if ( v15 == 5 )
      goto LABEL_19;
    v16 = ipa3_xdci_disconnect(a1, 1, *(_DWORD *)(ipa3_usb_ctx + 520));
    if ( !v16 )
    {
      ++*(_DWORD *)(ipa3_usb_ctx + 520);
      goto LABEL_19;
    }
    v10 = v16;
    printk(&unk_3C882E, "ipa_usb_xdci_disconnect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_usb %s:%d failed disconnect UL channel\n", "ipa_usb_xdci_disconnect", 2149);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v25, "ipa_usb %s:%d failed disconnect UL channel\n", "ipa_usb_xdci_disconnect", 2149);
    }
  }
  else
  {
    printk(&unk_3A5362, "ipa_usb_xdci_disconnect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_xdci_disconnect", 2101);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_xdci_disconnect", 2101);
    }
    v10 = -1;
  }
LABEL_31:
  mutex_unlock(ipa3_usb_ctx + 544);
  _ReadStatusReg(SP_EL0);
  return v10;
}
