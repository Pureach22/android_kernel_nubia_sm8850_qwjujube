__int64 __fastcall gsi_setup(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x8
  int v4; // w22
  int v5; // w24
  unsigned int v6; // w20
  __int64 v7; // x27
  __int64 v8; // x21
  int v9; // w26
  int v11; // w8
  __int64 (__fastcall *v12)(); // x8
  size_t v13; // x25
  __int64 v14; // x26
  const void *v15; // x1
  __int64 v16; // x26
  const void *v17; // t1
  unsigned int v18; // w8
  __int64 (__fastcall *v19)(); // x8
  int v20; // w3
  char v21; // w22
  int v22; // w8
  _DWORD *next_response; // x0
  int v25; // w8
  int v26; // w8
  _DWORD n[3]; // [xsp+4h] [xbp-Ch] BYREF

  *(_QWORD *)&n[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 48);
  n[0] = 0;
  v4 = *((unsigned __int16 *)a2 + 2);
  v5 = *((unsigned __int16 *)a2 + 1);
  v6 = *((unsigned __int16 *)a2 + 3);
  v7 = *(_QWORD *)(v3 + 48);
  v8 = *(_QWORD *)(v7 + 8);
  if ( !*(_DWORD *)(a1 + 272) )
  {
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1344), "usb cable is not connected");
    LODWORD(v13) = -107;
    goto LABEL_87;
  }
  v9 = *(_DWORD *)(a1 + 228);
  if ( v9 == -19 )
    v9 = *(_DWORD *)(a1 + 232);
  v11 = __rev16(*(unsigned __int16 *)a2);
  if ( v11 <= 8581 )
  {
    if ( v11 <= 8481 )
    {
      if ( v11 != 8448 )
      {
        if ( v11 == 8453 )
        {
          if ( a1 )
            ipc_log_string(*(_QWORD *)(a1 + 1344), "USB_CDC_RESET_FUNCTION");
          v12 = gsi_ctrl_reset_cmd_complete;
          LODWORD(v13) = 0;
LABEL_60:
          *(_QWORD *)(v8 + 48) = v12;
          *(_QWORD *)(v8 + 56) = a1;
          goto LABEL_79;
        }
        goto LABEL_51;
      }
      if ( a1 )
        ipc_log_string(*(_QWORD *)(a1 + 1344), "USB_CDC_SEND_ENCAPSULATED_COMMAND");
      if ( !v5 && v9 == v4 )
      {
        *(_QWORD *)(v8 + 56) = a1;
        if ( *(_DWORD *)(a1 + 224) )
          v19 = gsi_ctrl_cmd_complete;
        else
          v19 = gsi_rndis_command_complete;
        *(_QWORD *)(v8 + 48) = v19;
        LODWORD(v13) = v6;
        goto LABEL_79;
      }
LABEL_51:
      if ( a1 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1344), "inval ctrl req%02x.%02x v%04x i%04x l%d", *a2, a2[1], v5, v4, v6);
        printk(&unk_10608, *a2);
        LODWORD(v13) = -95;
        goto LABEL_87;
      }
      goto LABEL_52;
    }
    if ( v11 == 8482 )
    {
      v20 = v5 & 1;
      if ( *(_DWORD *)(a1 + 224) == 2 )
        *(_BYTE *)(a1 + 1352) = v20;
      if ( a1 )
        ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: USB_CDC_REQ_SET_CONTROL_LINE_STATE DTR:%d\n", "gsi_setup", v20);
      gsi_ctrl_send_cpkt_tomodem(a1, 0, 0);
      LODWORD(v13) = 0;
    }
    else
    {
      if ( v11 != 8515 || *((_WORD *)a2 + 3) || v9 != v4 )
        goto LABEL_51;
      if ( a1 )
        ipc_log_string(*(_QWORD *)(a1 + 1344), "packet filter %02x", v5);
      LODWORD(v13) = 0;
      *(_WORD *)(a1 + 550) = v5;
    }
LABEL_79:
    if ( a1 )
      goto LABEL_80;
LABEL_82:
    v21 = 1;
LABEL_83:
    v22 = *(_DWORD *)(v8 + 40);
    *(_DWORD *)(v8 + 8) = v13;
    *(_DWORD *)(v8 + 40) = v22 & 0xFFFBFFFF | (((unsigned int)v13 < v6) << 18);
    LODWORD(v13) = usb_ep_queue(*(_QWORD *)(*(_QWORD *)v7 + 48LL), v8, 2080);
    if ( (v13 & 0x80000000) != 0 )
    {
      if ( (v21 & 1) == 0 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1344), "response on err %d", v13);
        printk(&unk_11269, (unsigned int)v13);
      }
    }
    else
    {
      *(_BYTE *)(v7 + 488) |= 1u;
    }
    goto LABEL_87;
  }
  if ( v11 <= 41343 )
  {
    if ( v11 == 8582 )
    {
      if ( a1 )
        ipc_log_string(*(_QWORD *)(a1 + 1344), "USB_CDC_SET_NTB_INPUT_SIZE");
      if ( v6 == 4 || v6 == 8 )
      {
        LODWORD(v13) = -95;
        if ( v5 || v9 != v4 )
          goto LABEL_87;
        v12 = gsi_ctrl_set_ntb_cmd_complete;
        LODWORD(v13) = v6;
        *(_DWORD *)(v8 + 8) = v6;
        goto LABEL_60;
      }
      if ( a1 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1344), "wrong NTB length %d", v6);
        printk(&unk_103BE, v6);
        LODWORD(v13) = -95;
        goto LABEL_87;
      }
    }
    else
    {
      if ( v11 != 41217 )
        goto LABEL_51;
      if ( a1 )
        ipc_log_string(*(_QWORD *)(a1 + 1344), "USB_CDC_GET_ENCAPSULATED_RESPONSE");
      if ( v5 || v9 != v4 )
        goto LABEL_51;
      if ( *(_DWORD *)(a1 + 224) )
      {
        raw_spin_lock(a1 + 1304);
        v14 = *(_QWORD *)(a1 + 1280);
        if ( v14 != a1 + 1280 )
        {
          list_del(*(_QWORD **)(a1 + 1280));
          ++*(_DWORD *)(a1 + 1336);
          raw_spin_unlock(a1 + 1304);
          v17 = *(const void **)(v14 - 16);
          v16 = v14 - 16;
          v15 = v17;
          v18 = *(_DWORD *)(v16 + 8);
          if ( v18 >= v6 )
            v13 = v6;
          else
            v13 = v18;
          memcpy(*(void **)v8, v15, v13);
          gsi_ctrl_pkt_free((_QWORD *)v16);
          *(_QWORD *)(v8 + 48) = gsi_ctrl_send_response_complete;
          *(_QWORD *)(v8 + 56) = a1;
          if ( !a1 )
            goto LABEL_82;
          ipc_log_string(*(_QWORD *)(a1 + 1344), "copied encap_resp %d bytes", v13);
          goto LABEL_80;
        }
        if ( a1 )
          ipc_log_string(*(_QWORD *)(a1 + 1344), "ctrl resp queue empty");
        raw_spin_unlock(a1 + 1304);
        LODWORD(v13) = -95;
        goto LABEL_87;
      }
      next_response = (_DWORD *)rndis_get_next_response(*(_QWORD *)(a1 + 264), n);
      if ( next_response )
      {
        v13 = (size_t)next_response;
        if ( *next_response == -2147483646 )
        {
          if ( a1 )
          {
            ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: max_pkt_per_xfer : %d", "gsi_setup", 15);
            v25 = 15 * *(_DWORD *)(v13 + 36);
            *(_DWORD *)(v13 + 32) = 15;
            *(_DWORD *)(v13 + 36) = v25;
            ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: pkt_alignment_factor : %d", "gsi_setup", 4);
          }
          else
          {
            v26 = next_response[9];
            next_response[8] = 15;
            next_response[9] = 15 * v26;
          }
          *(_DWORD *)(v13 + 40) = 4;
        }
        memcpy(*(void **)v8, (const void *)v13, n[0]);
        rndis_free_response(*(_QWORD *)(a1 + 264), v13);
        LODWORD(v13) = n[0];
        if ( (n[0] & 0x80000000) == 0 )
          goto LABEL_79;
        goto LABEL_87;
      }
    }
LABEL_52:
    LODWORD(v13) = -95;
    goto LABEL_87;
  }
  if ( v11 == 41344 )
  {
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1344), "USB_CDC_GET_NTB_PARAMETERS");
    LODWORD(v13) = -95;
    if ( v6 && !v5 && v9 == v4 )
    {
      if ( v6 >= 0x1C )
        v13 = 28;
      else
        v13 = v6;
      memcpy(*(void **)v8, &mbim_gsi_ntb_parameters, v13);
      goto LABEL_79;
    }
  }
  else
  {
    if ( v11 != 41349 )
      goto LABEL_51;
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1344), "USB_CDC_GET_NTB_INPUT_SIZE");
    LODWORD(v13) = -95;
    if ( v6 >= 4 && !v5 && v9 == v4 )
    {
      **(_DWORD **)v8 = *(_DWORD *)(a1 + 564);
      if ( !a1 )
      {
        LODWORD(v13) = 4;
        goto LABEL_82;
      }
      ipc_log_string(*(_QWORD *)(a1 + 1344), "Reply to host INPUT SIZE %d", *(_DWORD *)(a1 + 564));
      LODWORD(v13) = 4;
LABEL_80:
      ipc_log_string(*(_QWORD *)(a1 + 1344), "req%02x.%02x v%04x i%04x l%d", *a2, a2[1], v5, v4, v6);
      v21 = 0;
      goto LABEL_83;
    }
  }
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v13;
}
