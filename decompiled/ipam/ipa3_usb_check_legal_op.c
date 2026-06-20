__int64 __fastcall ipa3_usb_check_legal_op(int a1, unsigned int a2)
{
  __int64 v4; // x19
  __int64 v5; // x24
  unsigned int v6; // w22
  bool v8; // w8
  const char *v11; // x21
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 ipc_logbuf; // x0
  const char *v15; // x5
  __int64 ipc_logbuf_low; // x0
  const char *v17; // x5

  if ( ipa3_usb_ctx )
  {
    v4 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
    v5 = *(unsigned int *)(ipa3_usb_ctx + ((unsigned __int64)a2 << 8) + 656);
    if ( a1 <= 3 )
    {
      if ( a1 > 1 )
      {
        if ( a1 == 2 )
        {
          if ( (v5 & 0xFFFFFFFD) != 1 )
            goto LABEL_42;
          goto LABEL_37;
        }
        if ( (unsigned int)v5 <= 6 )
        {
          v6 = 1;
          if ( ((1 << v5) & 0x64) != 0 )
            goto LABEL_38;
        }
        goto LABEL_42;
      }
      if ( a1 )
      {
        if ( (_DWORD)v5 != 1 )
          goto LABEL_42;
        goto LABEL_37;
      }
      v6 = 1;
      v8 = a2 != 1 && (_DWORD)v5 == 1;
      if ( !(_DWORD)v5 )
        goto LABEL_38;
    }
    else
    {
      if ( a1 > 5 )
      {
        if ( a1 == 6 || a1 == 7 )
        {
          if ( (_DWORD)v5 != 2 )
            goto LABEL_42;
          goto LABEL_37;
        }
        if ( (unsigned int)(v5 - 5) < 2 )
        {
LABEL_37:
          v6 = 1;
          goto LABEL_38;
        }
LABEL_42:
        if ( a2 == 1 )
          v11 = (const char *)&unk_3AB5A6;
        else
          v11 = (const char *)&unk_3B7A49;
        printk(&unk_3E509E, "ipa3_usb_check_legal_op");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          if ( (unsigned int)v5 > 7 )
            v15 = "UNSUPPORTED";
          else
            v15 = off_1E52B8[v5];
          ipc_log_string(
            ipc_logbuf,
            "ipa_usb %s:%d Illegal %s operation: state=%s operation=%s\n",
            "ipa3_usb_check_legal_op",
            465,
            v11,
            v15,
            off_1E51D8[a1]);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          if ( (unsigned int)v5 > 7 )
            v17 = "UNSUPPORTED";
          else
            v17 = off_1E52B8[v5];
          ipc_log_string(
            ipc_logbuf_low,
            "ipa_usb %s:%d Illegal %s operation: state=%s operation=%s\n",
            "ipa3_usb_check_legal_op",
            465,
            v11,
            v17,
            off_1E51D8[a1]);
        }
        v6 = 0;
        goto LABEL_38;
      }
      if ( a1 != 4 )
      {
        v6 = 1;
        if ( a2 != 1 || (_DWORD)v5 == 1 )
          goto LABEL_38;
        goto LABEL_42;
      }
      v6 = 1;
      v8 = a2 != 1 && (_DWORD)v5 == 1;
      if ( (_DWORD)v5 == 3 )
        goto LABEL_38;
    }
    if ( !v8 )
      goto LABEL_42;
LABEL_38:
    raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v4);
    return v6;
  }
  printk(&unk_3B9B13, "ipa3_usb_check_legal_op");
  if ( ipa3_get_ipc_logbuf() )
  {
    v12 = ipa3_get_ipc_logbuf();
    ipc_log_string(v12, "ipa_usb %s:%d ipa_usb_ctx is not initialized!\n", "ipa3_usb_check_legal_op", 399);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v13 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v13, "ipa_usb %s:%d ipa_usb_ctx is not initialized!\n", "ipa3_usb_check_legal_op", 399);
  }
  return 0;
}
