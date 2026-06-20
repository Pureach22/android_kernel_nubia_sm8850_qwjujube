__int64 __fastcall ipa3_xdci_suspend(unsigned int a1, unsigned int a2, char a3, unsigned int a4, char a5)
{
  __int64 v10; // x8
  unsigned int v11; // w21
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x20
  __int64 v17; // x26
  int gsi_chan_info; // w0
  unsigned int v19; // w20
  __int64 result; // x0
  unsigned int v21; // w28
  char v22; // w27
  __int64 reg_n; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  char v27; // w0
  __int64 v28; // x8
  int v29; // w20
  unsigned int v30; // w8
  int v31; // w0
  int ep_bit; // w25
  unsigned int ep_reg_idx; // w0
  int v34; // w0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  int v45; // w20
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  int v49; // w22
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned int v53; // w8
  unsigned int v54; // w8
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int128 v58; // [xsp+18h] [xbp-78h] BYREF
  _WORD v59[2]; // [xsp+2Ch] [xbp-64h] BYREF
  _QWORD v60[5]; // [xsp+30h] [xbp-60h] BYREF
  _QWORD v61[5]; // [xsp+58h] [xbp-38h] BYREF
  _BYTE v62[4]; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+88h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = ipa3_ctx;
  v62[0] = 0;
  memset(v61, 0, sizeof(v61));
  memset(v60, 0, sizeof(v60));
  v59[0] = 0;
  v11 = *(_DWORD *)(ipa3_ctx + 34924);
  v58 = 0u;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d entry\n", "ipa3_xdci_suspend", 1698);
      v10 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v10 + 34160);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d entry\n", "ipa3_xdci_suspend", 1698);
      v10 = ipa3_ctx;
    }
  }
  v14 = *(_DWORD *)(v10 + 34308);
  if ( v14 <= a2 )
    goto LABEL_34;
  if ( a2 >= 0x24 )
    goto LABEL_105;
  v15 = v10 + 168;
  v16 = v15 + 480LL * a2;
  if ( !*(_DWORD *)v16 )
    goto LABEL_34;
  if ( (a5 & 1) != 0 )
  {
    v17 = 0;
    goto LABEL_14;
  }
  if ( v14 <= a1 )
  {
LABEL_34:
    printk(&unk_3F1C01, "ipa3_xdci_suspend");
    v24 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_40;
    v25 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_suspend", 1703);
      v24 = ipa3_ctx;
    }
    v26 = *(_QWORD *)(v24 + 34160);
    if ( v26 )
    {
      ipc_log_string(v26, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_suspend", 1703);
      result = 4294967274LL;
    }
    else
    {
LABEL_40:
      result = 4294967274LL;
    }
    goto LABEL_20;
  }
  if ( a1 > 0x23 )
LABEL_105:
    __break(0x5512u);
  v17 = v15 + 480LL * a1;
  if ( !*(_DWORD *)v17 )
    goto LABEL_34;
LABEL_14:
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  ipa3_inc_client_enable_clks();
  gsi_chan_info = ipa3_get_gsi_chan_info(v60, *(_QWORD *)(v16 + 8));
  if ( gsi_chan_info )
    goto LABEL_17;
  if ( (a5 & 1) == 0 )
  {
    gsi_chan_info = ipa3_get_gsi_chan_info(v61, *(_QWORD *)(v17 + 8));
    if ( gsi_chan_info )
      goto LABEL_17;
  }
  v21 = 0;
  do
  {
    gsi_chan_info = ipa3_is_xdci_channel_empty(v16, v62);
    if ( gsi_chan_info )
      goto LABEL_17;
    if ( v62[0] != 1 )
      goto LABEL_69;
    if ( (a5 & 1) != 0 )
    {
      v22 = 0;
    }
    else
    {
      gsi_chan_info = ipa3_is_xdci_channel_empty(v17, v62);
      if ( gsi_chan_info )
        goto LABEL_17;
      v22 = v62[0] ^ 1;
    }
    _const_udelay(85900);
    if ( v21 > 0x30 )
      break;
    ++v21;
  }
  while ( (v22 & 1) != 0 );
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
    reg_n = ipahal_read_reg_n(29, 0);
  else
    reg_n = ipahal_read_ep_reg(132, a2);
  v27 = ipahal_test_ep_bit(reg_n, a2);
  v28 = ipa3_ctx;
  if ( (v27 & 1) != 0 )
  {
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d DL/DPL data pending due to open aggr. frame\n", "ipa3_xdci_suspend", 1759);
        v28 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v28 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d DL/DPL data pending due to open aggr. frame\n", "ipa3_xdci_suspend", 1759);
    }
LABEL_69:
    printk(&unk_3DAED0, "ipa3_xdci_suspend");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d DL/DPL data pending, can't suspend\n", "ipa3_xdci_suspend", 1764);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(v41, "ipa %s:%d DL/DPL data pending, can't suspend\n", "ipa3_xdci_suspend", 1764);
    }
    gsi_chan_info = -14;
    goto LABEL_17;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
  {
    v59[0] = 1;
    ipa_cfg_ep_ctrl(a2, v59);
  }
  gsi_chan_info = ipa3_is_xdci_channel_empty(v16, v62);
  if ( gsi_chan_info )
  {
LABEL_46:
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
    {
      v29 = gsi_chan_info;
      v59[0] = 0;
      ipa_cfg_ep_ctrl(a2, v59);
      gsi_chan_info = v29;
    }
LABEL_17:
    v19 = gsi_chan_info;
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
    ipa3_dec_client_disable_clks();
    result = v19;
    goto LABEL_20;
  }
  if ( (v62[0] & 1) == 0 )
  {
    printk(&unk_3DAED0, "ipa3_xdci_suspend");
    v42 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v43 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d DL/DPL data pending, can't suspend\n", "ipa3_xdci_suspend", 1784);
        v42 = ipa3_ctx;
      }
      v44 = *(_QWORD *)(v42 + 34160);
      if ( v44 )
      {
        ipc_log_string(v44, "ipa %s:%d DL/DPL data pending, can't suspend\n", "ipa3_xdci_suspend", 1784);
        gsi_chan_info = -14;
        goto LABEL_46;
      }
    }
LABEL_85:
    gsi_chan_info = -14;
    goto LABEL_46;
  }
  v30 = *(_DWORD *)(v16 + 4);
  if ( v30 <= 0x85 && (v30 & 1) != 0 && (a5 & 1) == 0 )
  {
    HIDWORD(v58) = 1;
    *(_QWORD *)((char *)&v58 + 4) = 0;
    LODWORD(v58) = 31;
    ipa3_cfg_ep_holb(a2, &v58);
  }
  v31 = ipa_stop_gsi_channel(a2);
  if ( v31 )
  {
    v45 = v31;
    printk(&unk_3C965E, "ipa3_xdci_suspend");
    v46 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v47 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d Error stopping DL/DPL channel: %d\n", "ipa3_xdci_suspend", 1800, v45);
        v46 = ipa3_ctx;
      }
      v48 = *(_QWORD *)(v46 + 34160);
      if ( v48 )
      {
        ipc_log_string(v48, "ipa %s:%d Error stopping DL/DPL channel: %d\n", "ipa3_xdci_suspend", 1800, v45);
        gsi_chan_info = -14;
        goto LABEL_46;
      }
    }
    goto LABEL_85;
  }
  if ( (a5 & 1) == 0 )
  {
    ep_bit = ipahal_get_ep_bit(a1);
    ep_reg_idx = ipahal_get_ep_reg_idx(a1);
    v34 = ipa3_stop_ul_chan_with_data_drain((_QWORD *)a4, ep_bit, ep_reg_idx, a3 & 1, a1, 0);
    if ( v34 )
    {
      v49 = v34;
      printk(&unk_3FD8C0, "ipa3_xdci_suspend");
      v50 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v51 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v51 )
        {
          ipc_log_string(v51, "ipa %s:%d Error stopping UL channel: result = %d\n", "ipa3_xdci_suspend", 1814, v49);
          v50 = ipa3_ctx;
        }
        v52 = *(_QWORD *)(v50 + 34160);
        if ( v52 )
          ipc_log_string(v52, "ipa %s:%d Error stopping UL channel: result = %d\n", "ipa3_xdci_suspend", 1814, v49);
      }
      gsi_start_channel(*(_QWORD *)(v16 + 8));
      v53 = *(_DWORD *)(v16 + 4);
      if ( v53 - 87 <= 6 && ((1 << (v53 - 87)) & 0x55) != 0 || v53 <= 0x13 && ((1 << v53) & 0x82800) != 0 )
      {
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))ipa3_uc_client_add_holb_monitor)(
                             *(unsigned __int16 *)(v16 + 8),
                             3,
                             v11,
                             0) )
        {
          printk(&unk_3C68A9, "ipa3_xdci_suspend");
          v55 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v56 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v56 )
            {
              ipc_log_string(
                v56,
                "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
                "ipa3_xdci_suspend",
                1832,
                *(_QWORD *)(v16 + 8));
              v55 = ipa3_ctx;
            }
            v57 = *(_QWORD *)(v55 + 34160);
            if ( v57 )
              ipc_log_string(
                v57,
                "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
                "ipa3_xdci_suspend",
                1832,
                *(_QWORD *)(v16 + 8));
          }
        }
      }
      ipa3_start_gsi_debug_monitor(a2);
      v54 = *(_DWORD *)(v16 + 4);
      if ( v54 <= 0x85 && (v54 & 1) != 0 )
      {
        v58 = 0u;
        ipa3_cfg_ep_holb(a2, &v58);
      }
      gsi_chan_info = v49;
      goto LABEL_46;
    }
  }
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  ipa3_dec_client_disable_clks();
  v35 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_63:
    result = 0;
    goto LABEL_20;
  }
  v36 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v36 )
  {
    ipc_log_string(v36, "ipa %s:%d exit\n", "ipa3_xdci_suspend", 1821);
    v35 = ipa3_ctx;
  }
  result = *(_QWORD *)(v35 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_xdci_suspend", 1821);
    goto LABEL_63;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
