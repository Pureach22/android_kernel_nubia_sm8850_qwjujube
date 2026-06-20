__int64 __fastcall ipa3_usb_release_xdci_channel(unsigned int a1, int a2, unsigned int a3)
{
  __int64 ipc_logbuf_low; // x0
  unsigned int v7; // w0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x20
  _QWORD **v12; // x20
  __int64 v13; // t1
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w19
  __int64 ipc_logbuf; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa3_usb_release_xdci_channel", 1310);
  }
  if ( (ipa3_usb_check_legal_op(4, a3) & 1) != 0 )
  {
    v7 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(a1);
    if ( v7 )
    {
      v18 = v7;
      printk(&unk_3A857D, "ipa3_usb_release_xdci_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_usb %s:%d failed to deallocate channel\n",
          "ipa3_usb_release_xdci_channel",
          1324);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v20, "ipa_usb %s:%d failed to deallocate channel\n", "ipa3_usb_release_xdci_channel", 1324);
      }
      return v18;
    }
    else
    {
      v8 = ipa3_usb_ctx + ((unsigned __int64)a3 << 8);
      v9 = v8 + 664;
      v10 = v8 + 744;
      if ( a2 )
        v11 = v10;
      else
        v11 = v9;
      ipa3_usb_smmu_map_xdci_channel(v11, 0);
      if ( *(_QWORD *)(v11 + 64) )
        ipa_smmu_free_sgt((_QWORD **)(v11 + 64));
      v13 = *(_QWORD *)(v11 + 72);
      v12 = (_QWORD **)(v11 + 72);
      if ( v13 )
        ipa_smmu_free_sgt(v12);
      if ( (ipa3_usb_set_state(1, 0, a3) & 1) == 0 )
      {
        printk(&unk_3B9A33, "ipa3_usb_release_xdci_channel");
        if ( ipa3_get_ipc_logbuf() )
        {
          v21 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v21,
            "ipa_usb %s:%d failed to change state to initialized\n",
            "ipa3_usb_release_xdci_channel",
            1342);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v22 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v22,
            "ipa_usb %s:%d failed to change state to initialized\n",
            "ipa3_usb_release_xdci_channel",
            1342);
        }
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v15 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v15, "ipa_usb %s:%d exit\n", "ipa3_usb_release_xdci_channel", 1344);
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_3A5362, "ipa3_usb_release_xdci_channel");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_release_xdci_channel", 1317);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_release_xdci_channel", 1317);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
