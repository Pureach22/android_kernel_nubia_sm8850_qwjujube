__int64 __fastcall ipa3_usb_set_state(int a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 v6; // x19
  unsigned __int64 v7; // x8
  __int64 v8; // x24
  char v9; // w26
  unsigned int v10; // w20
  __int64 v11; // x0
  const char *v12; // x4
  const char *v13; // x5
  __int64 v14; // x0
  const char *v15; // x4
  const char *v16; // x5
  unsigned __int64 v17; // x8
  __int64 ipc_logbuf; // x0
  const char *v19; // x4
  const char *v20; // x5
  __int64 ipc_logbuf_low; // x0
  const char *v22; // x4
  const char *v23; // x5

  v6 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
  v7 = ipa3_usb_ctx + ((unsigned __int64)a3 << 8);
  v8 = *(unsigned int *)(v7 + 656);
  v9 = *(_BYTE *)(v7 + 660);
  if ( a1 > 3 )
  {
    if ( a1 > 5 )
    {
      if ( a1 == 6 )
      {
        if ( (_DWORD)v8 != 2 )
          goto LABEL_54;
        goto LABEL_35;
      }
      if ( a1 == 7 && (_DWORD)v8 == 5 )
        goto LABEL_35;
    }
    else
    {
      if ( a1 == 4 )
      {
        if ( (_DWORD)v8 != 2 )
          goto LABEL_54;
        goto LABEL_35;
      }
      v9 = 0;
      if ( (_DWORD)v8 == 4 || (a2 & ((_DWORD)v8 == 7)) != 0 )
        goto LABEL_35;
    }
LABEL_54:
    printk(&unk_3F3E74, "ipa3_usb_set_state");
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_61;
    ipc_logbuf = ipa3_get_ipc_logbuf();
    if ( (unsigned int)v8 > 7 )
    {
      v19 = "UNSUPPORTED";
      if ( (unsigned int)a1 > 7 )
        goto LABEL_57;
    }
    else
    {
      v19 = off_1E52B8[v8];
      if ( (unsigned int)a1 > 7 )
      {
LABEL_57:
        v20 = "UNSUPPORTED";
LABEL_60:
        ipc_log_string(ipc_logbuf, "ipa_usb %s:%d invalid state change %s -> %s\n", "ipa3_usb_set_state", 383, v19, v20);
LABEL_61:
        if ( !ipa3_get_ipc_logbuf_low() )
        {
LABEL_68:
          v10 = 0;
          goto LABEL_69;
        }
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        if ( (unsigned int)v8 > 7 )
        {
          v22 = "UNSUPPORTED";
          if ( (unsigned int)a1 > 7 )
            goto LABEL_64;
        }
        else
        {
          v22 = off_1E52B8[v8];
          if ( (unsigned int)a1 > 7 )
          {
LABEL_64:
            v23 = "UNSUPPORTED";
LABEL_67:
            ipc_log_string(
              ipc_logbuf_low,
              "ipa_usb %s:%d invalid state change %s -> %s\n",
              "ipa3_usb_set_state",
              383,
              v22,
              v23);
            goto LABEL_68;
          }
        }
        v23 = off_1E52B8[a1];
        goto LABEL_67;
      }
    }
    v20 = off_1E52B8[a1];
    goto LABEL_60;
  }
  if ( a1 > 1 )
  {
    if ( a1 != 2 )
    {
      if ( (int)v8 <= 3 )
      {
        if ( (_DWORD)v8 != 2 )
          goto LABEL_54;
      }
      else if ( (unsigned int)(v8 - 5) >= 2 )
      {
        goto LABEL_54;
      }
      goto LABEL_35;
    }
    if ( (unsigned int)v8 <= 7 && ((1 << v8) & 0xCA) != 0 || (a2 & 1) != 0 && (_DWORD)v8 == 4 )
      goto LABEL_35;
    goto LABEL_54;
  }
  if ( a1 )
  {
    if ( a1 != 1 || (_DWORD)v8 && (_DWORD)v8 != 3 && (a3 == 1 || (_DWORD)v8 != 1) )
      goto LABEL_54;
  }
  else if ( (_DWORD)v8 != 1 )
  {
    goto LABEL_54;
  }
LABEL_35:
  if ( (_DWORD)v8 == a1 )
  {
    v10 = 1;
  }
  else
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      if ( a3 == 1 )
        v12 = (const char *)&unk_3AB5A6;
      else
        v12 = (const char *)&unk_3B7A49;
      if ( (unsigned int)v8 > 7 )
        v13 = "UNSUPPORTED";
      else
        v13 = off_1E52B8[v8];
      ipc_log_string(
        v11,
        "ipa_usb %s:%d ipa_usb %s state changed %s -> %s\n",
        "ipa3_usb_set_state",
        375,
        v12,
        v13,
        off_1E52B8[a1]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      if ( a3 == 1 )
        v15 = (const char *)&unk_3AB5A6;
      else
        v15 = (const char *)&unk_3B7A49;
      if ( (unsigned int)v8 > 7 )
        v16 = "UNSUPPORTED";
      else
        v16 = off_1E52B8[v8];
      ipc_log_string(
        v14,
        "ipa_usb %s:%d ipa_usb %s state changed %s -> %s\n",
        "ipa3_usb_set_state",
        375,
        v15,
        v16,
        off_1E52B8[a1]);
    }
    v17 = ipa3_usb_ctx + ((unsigned __int64)a3 << 8);
    *(_DWORD *)(v17 + 656) = a1;
    v10 = 1;
    *(_BYTE *)(v17 + 660) = v9;
  }
LABEL_69:
  raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v6);
  return v10;
}
