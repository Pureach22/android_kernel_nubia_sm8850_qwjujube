__int64 __fastcall ipa3_usb_smmu_map_xdci_channel(__int64 a1, char a2)
{
  int v2; // w9
  unsigned __int64 v4; // x0
  __int64 v6; // x8
  int v7; // w9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v10; // w9
  unsigned int v11; // w0
  int v12; // w9
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w8
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w19
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

  v2 = *(_DWORD *)(a1 + 28);
  v4 = *(_DWORD *)(a1 + 8) & 0xFFFFF000;
  if ( (_DWORD)v4 == (v2 & 0xFFFFF000) )
  {
    if ( (a2 & 1) != 0 )
    {
      v6 = ipa3_usb_ctx;
      v7 = *(_DWORD *)(ipa3_usb_ctx + 1376);
      if ( v7 )
      {
        if ( *(_QWORD *)(ipa3_usb_ctx + 1384) != v4 )
        {
          printk(&unk_3A8501, "ipa3_usb_smmu_map_xdci_channel");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(
              ipc_logbuf,
              "ipa_usb %s:%d No support for map different reg\n",
              "ipa3_usb_smmu_map_xdci_channel",
              1069);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              ipc_logbuf_low,
              "ipa_usb %s:%d No support for map different reg\n",
              "ipa3_usb_smmu_map_xdci_channel",
              1069);
            return 4294967274LL;
          }
          return 4294967274LL;
        }
      }
      else
      {
        *(_QWORD *)(ipa3_usb_ctx + 1384) = v4;
        v13 = ipa3_smmu_map_peer_reg(v4, 1, 0);
        if ( v13 )
        {
          v19 = v13;
          printk(&unk_3F0C02, "ipa3_usb_smmu_map_xdci_channel");
          if ( ipa3_get_ipc_logbuf() )
          {
            v28 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v28,
              "ipa_usb %s:%d failed to map USB regs %d\n",
              "ipa3_usb_smmu_map_xdci_channel",
              1063,
              v19);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v29 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v29,
              "ipa_usb %s:%d failed to map USB regs %d\n",
              "ipa3_usb_smmu_map_xdci_channel",
              1063,
              v19);
          }
          return v19;
        }
        v6 = ipa3_usb_ctx;
        v7 = *(_DWORD *)(ipa3_usb_ctx + 1376);
      }
      v12 = v7 + 1;
    }
    else
    {
      v6 = ipa3_usb_ctx;
      if ( *(_QWORD *)(ipa3_usb_ctx + 1384) != (unsigned int)v4 )
      {
        printk(&unk_3A8501, "ipa3_usb_smmu_map_xdci_channel");
        if ( ipa3_get_ipc_logbuf() )
        {
          v24 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v24,
            "ipa_usb %s:%d No support for map different reg\n",
            "ipa3_usb_smmu_map_xdci_channel",
            1077);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v25 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v25,
            "ipa_usb %s:%d No support for map different reg\n",
            "ipa3_usb_smmu_map_xdci_channel",
            1077);
          return 4294967274LL;
        }
        return 4294967274LL;
      }
      v10 = *(_DWORD *)(ipa3_usb_ctx + 1376);
      if ( v10 == 1 )
      {
        v11 = ipa3_smmu_map_peer_reg((unsigned int)v4, 0, 0);
        if ( v11 )
        {
          v19 = v11;
          printk(&unk_3AE554, "ipa3_usb_smmu_map_xdci_channel");
          if ( ipa3_get_ipc_logbuf() )
          {
            v26 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v26,
              "ipa_usb %s:%d failed to unmap USB regs %d\n",
              "ipa3_usb_smmu_map_xdci_channel",
              1087,
              v19);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v27 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v27,
              "ipa_usb %s:%d failed to unmap USB regs %d\n",
              "ipa3_usb_smmu_map_xdci_channel",
              1087,
              v19);
          }
          return v19;
        }
        v6 = ipa3_usb_ctx;
        v10 = *(_DWORD *)(ipa3_usb_ctx + 1376);
      }
      v12 = v10 - 1;
    }
    *(_DWORD *)(v6 + 1376) = v12;
    v14 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 40), *(unsigned __int16 *)(a1 + 20), a2 & 1, *(_QWORD *)(a1 + 64), 0);
    if ( v14 )
    {
      v19 = v14;
      printk(&unk_3D435B, "ipa3_usb_smmu_map_xdci_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v20 = ipa3_get_ipc_logbuf();
        ipc_log_string(v20, "ipa_usb %s:%d failed to map Xfer ring %d\n", "ipa3_usb_smmu_map_xdci_channel", 1098, v19);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v21 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v21, "ipa_usb %s:%d failed to map Xfer ring %d\n", "ipa3_usb_smmu_map_xdci_channel", 1098, v19);
      }
    }
    else
    {
      v15 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a1 + 56), *(_DWORD *)(a1 + 48), a2 & 1, *(_QWORD *)(a1 + 72), 0);
      result = 0;
      if ( !v15 )
        return result;
      v19 = v15;
      printk(&unk_3A8533, "ipa3_usb_smmu_map_xdci_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v22 = ipa3_get_ipc_logbuf();
        ipc_log_string(v22, "ipa_usb %s:%d failed to map TRBs buff %d\n", "ipa3_usb_smmu_map_xdci_channel", 1106, v19);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v23 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v23, "ipa_usb %s:%d failed to map TRBs buff %d\n", "ipa3_usb_smmu_map_xdci_channel", 1106, v19);
      }
    }
    return v19;
  }
  printk(&unk_3DFB2E, "ipa3_usb_smmu_map_xdci_channel");
  if ( ipa3_get_ipc_logbuf() )
  {
    v17 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v17,
      "ipa_usb %s:%d No support more than 1 page map for USB regs\n",
      "ipa3_usb_smmu_map_xdci_channel",
      1050);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v18 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v18,
      "ipa_usb %s:%d No support more than 1 page map for USB regs\n",
      "ipa3_usb_smmu_map_xdci_channel",
      1050);
  }
  __break(0x800u);
  return 4294967274LL;
}
