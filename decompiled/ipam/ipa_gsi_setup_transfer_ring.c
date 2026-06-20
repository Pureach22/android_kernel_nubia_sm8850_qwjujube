__int64 __fastcall ipa_gsi_setup_transfer_ring(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  unsigned int v8; // w0
  unsigned int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0
  char v12; // w8
  __int64 v13; // x21
  __int64 v14; // x9
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x9
  unsigned int v19; // w8
  bool v20; // cf
  __int64 (__fastcall *v21)(__int64); // x11
  char v22; // w14
  __int64 v23; // x9
  unsigned int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 result; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned int v31; // w20
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned int v38; // w20
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  _QWORD v42[3]; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v43; // [xsp+18h] [xbp-88h] BYREF
  __int64 v44; // [xsp+20h] [xbp-80h]
  __int64 v45; // [xsp+28h] [xbp-78h]
  __int64 v46; // [xsp+30h] [xbp-70h]
  __int64 v47; // [xsp+38h] [xbp-68h]
  __int64 v48; // [xsp+40h] [xbp-60h]
  __int64 v49; // [xsp+48h] [xbp-58h]
  __int64 v50; // [xsp+50h] [xbp-50h]
  _BOOL8 v51; // [xsp+58h] [xbp-48h]
  __int64 v52; // [xsp+60h] [xbp-40h]
  __int64 v53; // [xsp+68h] [xbp-38h]
  __int64 (__fastcall *v54)(); // [xsp+70h] [xbp-30h]
  __int64 (__fastcall *v55)(__int64); // [xsp+78h] [xbp-28h]
  __int64 (__fastcall *v56)(); // [xsp+80h] [xbp-20h]
  __int64 v57; // [xsp+88h] [xbp-18h]
  _QWORD v58[2]; // [xsp+90h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(a1 + 4);
  v56 = nullptr;
  v57 = 0;
  v54 = nullptr;
  v55 = nullptr;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  if ( ((v8 - 95) & 0xFFFFFFDF) != 0 )
    v9 = 2;
  else
    v9 = 5;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v43 = v9;
  if ( v8 > 0x85 || (v8 & 1) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 472);
    if ( v10 )
      LOWORD(v47) = *(_DWORD *)(v10 + 164);
  }
  else
  {
    HIDWORD(v43) = 1;
    if ( (unsigned __int8)v8 == 32 || (unsigned __int8)v8 == 120 || (unsigned __int8)v8 == 34 )
      BYTE1(v53) = *(_BYTE *)(ipa3_ctx + 45392);
  }
  v58[0] = 0;
  v11 = ((__int64 (*)(void))ipa_get_gsi_ep_info)();
  if ( !v11 )
  {
    printk(&unk_3CC819, "ipa_gsi_setup_transfer_ring");
    v28 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_56;
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(
        v29,
        "ipa %s:%d Failed getting GSI EP info for client=%d\n",
        "ipa_gsi_setup_transfer_ring",
        6985,
        *(_DWORD *)(a1 + 4));
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( v30 )
    {
      ipc_log_string(
        v30,
        "ipa %s:%d Failed getting GSI EP info for client=%d\n",
        "ipa_gsi_setup_transfer_ring",
        6985,
        *(_DWORD *)(a1 + 4));
      result = 4294967274LL;
    }
    else
    {
LABEL_56:
      result = 4294967274LL;
    }
    goto LABEL_57;
  }
  v12 = *(_DWORD *)(v11 + 4);
  v13 = v11;
  v14 = *(_QWORD *)(a1 + 16);
  v15 = *(_QWORD *)(ipa3_ctx + 34216);
  LOBYTE(v44) = v12;
  v45 = v14;
  LODWORD(v46) = 16;
  HIDWORD(v46) = a2;
  v16 = ipa3_ring_alloc(v15, a2, v58, a4);
  v17 = v58[0];
  v18 = ipa3_ctx;
  *(_DWORD *)(a1 + 48) = a2;
  v50 = v16;
  v48 = v17;
  *(_QWORD *)(a1 + 56) = v17;
  *(_QWORD *)(a1 + 64) = v16;
  v19 = *(_DWORD *)(a1 + 4);
  v51 = *(_DWORD *)(v18 + 32240) < 0xEu;
  if ( v19 == 36 )
  {
    LOBYTE(v52) = 15;
    LOBYTE(v49) = 1;
  }
  else
  {
    LOBYTE(v52) = 1;
    LOBYTE(v49) = 1;
    if ( (v19 & 0xFFFFFFFE) == 0x78 )
      BYTE1(v49) = 1;
  }
  v20 = (v19 & 1) != 0 || v19 >= 0x86;
  HIDWORD(v52) = *(_DWORD *)(v13 + 20);
  v21 = ipa_gsi_irq_tx_notify_cb;
  v22 = *(_BYTE *)(v13 + 24);
  if ( v20 )
    v21 = (__int64 (__fastcall *)(__int64))ipa_gsi_irq_rx_notify_cb;
  v23 = v18 + 43296;
  v57 = a3;
  LOBYTE(v53) = v22;
  v54 = (__int64 (__fastcall *)())v21;
  v55 = ipa_gsi_chan_err_cb;
  if ( (v19 | 2) == 0x2F )
    v54 = ipa_dma_gsi_irq_rx_notify_cb;
  if ( v19 <= 0x85 && (v19 & 1) != 0 )
    v56 = free_rx_pkt;
  if ( *(_BYTE *)(v23 + 2090) == 1 && (v19 == 35 || v19 == 121 || v19 == 95) )
    v56 = free_rx_page;
  v24 = gsi_alloc_channel(&v43, *(_QWORD *)v23, a1 + 8);
  if ( v24 )
  {
    v31 = v24;
    printk(&unk_3AF800, "ipa_gsi_setup_transfer_ring");
    v32 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v33 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d Failed to alloc GSI chan.\n", "ipa_gsi_setup_transfer_ring", 7045);
        v32 = ipa3_ctx;
      }
      v34 = *(_QWORD *)(v32 + 34160);
      if ( v34 )
        ipc_log_string(v34, "ipa %s:%d Failed to alloc GSI chan.\n", "ipa_gsi_setup_transfer_ring", 7045);
    }
    goto LABEL_55;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0xDu )
    v25 = 0;
  else
    v25 = (unsigned int)(*(_DWORD *)(v13 + 8) << 20) | 0x20000000000000LL;
  v26 = *(_QWORD *)(a1 + 8);
  v42[0] = 0;
  v42[1] = v25;
  v42[2] = 0;
  result = gsi_write_channel_scratch(v26, v42);
  if ( (_DWORD)result )
  {
    v31 = result;
    printk(&unk_3C6CEC, "ipa_gsi_setup_transfer_ring");
    v35 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v36 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v36 )
      {
        ipc_log_string(v36, "ipa %s:%d failed to write scratch %d\n", "ipa_gsi_setup_transfer_ring", 7066, v31);
        v35 = ipa3_ctx;
      }
      v37 = *(_QWORD *)(v35 + 34160);
      if ( v37 )
        ipc_log_string(v37, "ipa %s:%d failed to write scratch %d\n", "ipa_gsi_setup_transfer_ring", 7066, v31);
    }
    if ( (unsigned int)gsi_dealloc_channel(*(_QWORD *)(a1 + 8)) )
    {
      printk(&unk_3FDE65, "ipa_gsi_setup_transfer_ring");
      v39 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v40 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v40 )
        {
          ipc_log_string(v40, "ipa %s:%d Failed to dealloc GSI chan.\n", "ipa_gsi_setup_transfer_ring", 7074);
          v39 = ipa3_ctx;
        }
        v41 = *(_QWORD *)(v39 + 34160);
        if ( v41 )
          ipc_log_string(v41, "ipa %s:%d Failed to dealloc GSI chan.\n", "ipa_gsi_setup_transfer_ring", 7074);
      }
      __break(0x800u);
    }
LABEL_55:
    dma_free_attrs(
      *(_QWORD *)(ipa3_ctx + 34216),
      *(unsigned int *)(a1 + 48),
      *(_QWORD *)(a1 + 64),
      *(_QWORD *)(a1 + 56),
      0);
    result = v31;
LABEL_57:
    if ( *(_QWORD *)(a1 + 16) != -1 )
    {
      v38 = result;
      gsi_dealloc_evt_ring(*(_QWORD *)(a1 + 16));
      result = v38;
      *(_QWORD *)(a1 + 16) = -1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
