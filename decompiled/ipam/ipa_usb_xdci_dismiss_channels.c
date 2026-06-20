__int64 __fastcall ipa_usb_xdci_dismiss_channels(unsigned int a1, unsigned int a2, int a3)
{
  unsigned int v6; // w22
  unsigned int v7; // w20
  __int64 ipc_logbuf_low; // x0
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned int v14; // w0
  __int64 result; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 ipc_logbuf; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0

  v6 = 2 * (a3 == 5);
  if ( a3 == 4 )
    v7 = 1;
  else
    v7 = 2 * (a3 == 5);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_xdci_dismiss_channels", 2028);
  }
  v9 = ipa3_reset_gsi_channel((_QWORD *)a2);
  if ( v9 )
  {
    v17 = v9;
    printk(&unk_3F9D13, "ipa_usb_xdci_dismiss_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d failed to reset DL channel\n", "ipa_usb_xdci_dismiss_channels", 2033);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipa_usb %s:%d failed to reset DL channel\n", "ipa_usb_xdci_dismiss_channels", 2033);
    }
    return v17;
  }
  v10 = ((__int64 (__fastcall *)(_QWORD))ipa3_reset_gsi_event_ring)(a2);
  if ( v10 )
  {
    v17 = v10;
    printk(&unk_3FCC6E, "ipa_usb_xdci_dismiss_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(v20, "ipa_usb %s:%d failed to reset DL event ring\n", "ipa_usb_xdci_dismiss_channels", 2040);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v21, "ipa_usb %s:%d failed to reset DL event ring\n", "ipa_usb_xdci_dismiss_channels", 2040);
    }
    return v17;
  }
  if ( a3 != 4 )
  {
    ((void (__fastcall *)(_QWORD))ipa3_xdci_ep_delay_rm)(a1);
    v11 = ipa3_reset_gsi_channel((_QWORD *)a1);
    if ( v11 )
    {
      v17 = v11;
      printk(&unk_3AB5EC, "ipa_usb_xdci_dismiss_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v26 = ipa3_get_ipc_logbuf();
        ipc_log_string(v26, "ipa_usb %s:%d failed to reset UL channel\n", "ipa_usb_xdci_dismiss_channels", 2049);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v27 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v27, "ipa_usb %s:%d failed to reset UL channel\n", "ipa_usb_xdci_dismiss_channels", 2049);
      }
      return v17;
    }
    v12 = ((__int64 (__fastcall *)(_QWORD))ipa3_reset_gsi_event_ring)(a1);
    if ( v12 )
    {
      v17 = v12;
      printk(&unk_3D43A6, "ipa_usb_xdci_dismiss_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v30 = ipa3_get_ipc_logbuf();
        ipc_log_string(v30, "ipa_usb %s:%d failed to reset UL event ring\n", "ipa_usb_xdci_dismiss_channels", 2056);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v31 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v31, "ipa_usb %s:%d failed to reset UL event ring\n", "ipa_usb_xdci_dismiss_channels", 2056);
      }
      return v17;
    }
  }
  if ( (ipa3_usb_set_state(3, 0, v7) & 1) == 0 )
  {
    printk(&unk_3B10B9, "ipa_usb_xdci_dismiss_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      ipc_log_string(v22, "ipa_usb %s:%d failed to change state to stopped\n", "ipa_usb_xdci_dismiss_channels", 2063);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v23, "ipa_usb %s:%d failed to change state to stopped\n", "ipa_usb_xdci_dismiss_channels", 2063);
    }
  }
  if ( a3 != 4 )
  {
    v13 = ipa3_usb_release_xdci_channel(a1, 0, v6);
    if ( v13 )
    {
      v17 = v13;
      printk(&unk_3EDB7A, "ipa_usb_xdci_dismiss_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v28 = ipa3_get_ipc_logbuf();
        ipc_log_string(v28, "ipa_usb %s:%d failed to release UL channel\n", "ipa_usb_xdci_dismiss_channels", 2069);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v29 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v29, "ipa_usb %s:%d failed to release UL channel\n", "ipa_usb_xdci_dismiss_channels", 2069);
      }
      return v17;
    }
  }
  v14 = ipa3_usb_release_xdci_channel(a2, 1, v7);
  if ( v14 )
  {
    v17 = v14;
    printk(&unk_3D43D5, "ipa_usb_xdci_dismiss_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_usb %s:%d failed to release DL channel\n", "ipa_usb_xdci_dismiss_channels", 2077);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v25, "ipa_usb %s:%d failed to release DL channel\n", "ipa_usb_xdci_dismiss_channels", 2077);
    }
    return v17;
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v16, "ipa_usb %s:%d exit\n", "ipa_usb_xdci_dismiss_channels", 2081);
    return 0;
  }
  return result;
}
