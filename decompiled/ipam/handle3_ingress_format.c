__int64 __fastcall handle3_ingress_format(__int64 a1, __int64 a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x22
  int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  char v12; // w9
  int v13; // w10
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v17; // x8
  __int64 v18; // x9
  bool v19; // zf
  int v20; // w9
  int v21; // w10
  unsigned int v22; // w20
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w0
  unsigned int v26; // w19
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w0
  __int64 v33; // x0
  __int64 v34; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Get RMNET_IOCTL_SET_INGRESS_DATA_FORMAT\n",
      "handle3_ingress_format",
      1509);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d Get RMNET_IOCTL_SET_INGRESS_DATA_FORMAT\n",
      "handle3_ingress_format",
      1509);
  }
  if ( (unsigned int)ipa_get_ep_mapping(35) != -1 )
  {
    v6 = rmnet_ipa3_ctx;
    if ( (*(_BYTE *)(a2 + 4) & 0x10) != 0 )
    {
      if ( (int)ipa3_ctx_get_type(0) > 16 )
        v7 = 1;
      else
        v7 = 2;
      *(_DWORD *)(v6 + 416) = v7;
      if ( ipa3_get_ipc_logbuf() )
      {
        v8 = ipa3_get_ipc_logbuf();
        ipc_log_string(v8, "ipa-wan %s:%d DL chksum set\n", "handle3_ingress_format", 1525);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v9, "ipa-wan %s:%d DL chksum set\n", "handle3_ingress_format", 1525);
      }
    }
    if ( (*(_BYTE *)(a2 + 4) & 0x20) != 0 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v10,
          "ipa-wan %s:%d get AGG size %d count %d\n",
          "handle3_ingress_format",
          1531,
          *(_DWORD *)(a2 + 8),
          *(_DWORD *)(a2 + 12));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v11,
          "ipa-wan %s:%d get AGG size %d count %d\n",
          "handle3_ingress_format",
          1531,
          *(_DWORD *)(a2 + 8),
          *(_DWORD *)(a2 + 12));
      }
      if ( !(unsigned int)ipa3_disable_apps_wan_cons_deaggr() )
      {
        *(_DWORD *)(v6 + 368) = *(_DWORD *)(a2 + 8);
        *(_DWORD *)(v6 + 376) = *(_DWORD *)(a2 + 12);
      }
    }
    if ( (int)ipa3_ctx_get_type(0) >= 17 && (*(_BYTE *)(a2 + 4) & 0x10) != 0 )
    {
      v12 = 1;
      v13 = 8;
    }
    else
    {
      v12 = 0;
      v13 = 4;
    }
    v17 = rmnet_ipa3_ctx;
    *(_DWORD *)(v6 + 276) = v13;
    *(_BYTE *)(v17 + 1984) = v12;
    *(_QWORD *)(v6 + 292) = 0x200000001LL;
    *(_QWORD *)(v6 + 280) = 0x100000001LL;
    *(_WORD *)(v6 + 328) = 1;
    *(_BYTE *)(v6 + 320) = 1;
    *(_DWORD *)(v6 + 324) = 0;
    *(_DWORD *)(v6 + 316) = 0;
    *(_DWORD *)(v6 + 424) = -16777216;
    *(_DWORD *)(v6 + 456) = 35;
    v18 = *(_QWORD *)(a1 + 184);
    *(_BYTE *)(v6 + 512) = 0;
    v19 = (v18 & 0x80000000000000LL) == 0;
    if ( (v18 & 0x80000000000000LL) != 0 )
      v20 = 95;
    else
      v20 = 35;
    v21 = (unsigned __int8)byte_2018C2;
    *(_DWORD *)(v6 + 456) = v20;
    if ( v19 )
      v22 = 1;
    else
      v22 = 3;
    *(_QWORD *)(v6 + 464) = a1;
    *(_QWORD *)(v6 + 472) = apps_ipa_packet_receive_notify;
    if ( v21 == 1 )
      *(_QWORD *)(v6 + 488) = *(_QWORD *)v17 + 248LL;
    *(_DWORD *)(v6 + 460) = 8 * dword_2018C4;
    mutex_lock(v17 + 1088);
    if ( *(_DWORD *)(rmnet_ipa3_ctx + 1056) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v23 = ipa3_get_ipc_logbuf();
        ipc_log_string(v23, "ipa-wan %s:%d In SSR sequence/recovery\n", "handle3_ingress_format", 1587);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v24 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v24, "ipa-wan %s:%d In SSR sequence/recovery\n", "handle3_ingress_format", 1587);
      }
      mutex_unlock(rmnet_ipa3_ctx + 1088);
      return 4294967282LL;
    }
    v25 = ipa_setup_sys_pipe(rmnet_ipa3_ctx + 264, (unsigned int *)(rmnet_ipa3_ctx + 1084));
    if ( v25 )
    {
      v26 = v25;
      mutex_unlock(rmnet_ipa3_ctx + 1088);
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v27 = ipa3_get_ipc_logbuf();
        ipc_log_string(v27, "ipa-wan %s:%d ingress WAN pipe setup successfully\n", "handle3_ingress_format", 1598);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v28 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v28, "ipa-wan %s:%d ingress WAN pipe setup successfully\n", "handle3_ingress_format", 1598);
      }
      if ( *(_BYTE *)(ipa3_ctx + 48858) == 1 && !(unsigned int)ipa3_setup_apps_low_lat_cons_pipe(0, nullptr) )
      {
        v22 |= 4u;
        if ( ipa3_get_ipc_logbuf() )
        {
          v29 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v29,
            "ipa-wan %s:%d ingress low latency pipe setup successfully\n",
            "handle3_ingress_format",
            1606);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v30 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v30,
            "ipa-wan %s:%d ingress low latency pipe setup successfully\n",
            "handle3_ingress_format",
            1606);
        }
      }
      v31 = mutex_unlock(rmnet_ipa3_ctx + 1088);
      v26 = ipa3_setup_a7_qmap_hdr(v31);
      if ( !v26 )
      {
        v32 = ipa3_setup_dflt_wan_rt_tables();
        if ( !v32 )
        {
          ipa_send_wan_pipe_ind_to_modem(v22);
          return 0;
        }
        v26 = v32;
        ipa3_del_a7_qmap_hdr();
        ipa_send_wan_pipe_ind_to_modem(v22);
      }
    }
    if ( (unsigned int)__ratelimit(&handle3_ingress_format__rs, "handle3_ingress_format") )
    {
      printk(&unk_3C22ED, "handle3_ingress_format");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_63;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_63:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v34 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v34, "ipa-wan %s:%d failed to configure ingress\n", "handle3_ingress_format", 1623);
      }
      return v26;
    }
    v33 = ipa3_get_ipc_logbuf();
    ipc_log_string(v33, "ipa-wan %s:%d failed to configure ingress\n", "handle3_ingress_format", 1623);
    goto LABEL_63;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v14 = ipa3_get_ipc_logbuf();
    ipc_log_string(v14, "ipa-wan %s:%d Embedded datapath not supported\n", "handle3_ingress_format", 1513);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v15 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v15, "ipa-wan %s:%d Embedded datapath not supported\n", "handle3_ingress_format", 1513);
  }
  return 4294967282LL;
}
