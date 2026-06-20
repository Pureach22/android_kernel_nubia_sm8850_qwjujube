__int64 __fastcall rndis_ipa_init(__int64 *a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x19
  __int64 v4; // x0
  _QWORD *v5; // x20
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 dir; // x0
  __int64 v11; // x0
  __int64 v12; // x25
  long double v13; // q0
  unsigned int v14; // w22
  double v15; // d0
  double v16; // d0
  int v17; // w8
  __int64 v18; // x0
  char is_ulso_supported; // w8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x24
  unsigned int v24; // w0
  __int64 v25; // x0
  long double v26; // q0
  unsigned int *v27; // x22
  unsigned int v28; // w0
  unsigned int v29; // w0
  long double v30; // q0
  unsigned int v31; // w0
  __int64 v32; // x1
  __int64 v33; // x0
  long double v34; // q0
  __int64 v35; // x0
  __int64 v36; // x0

  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_init", 570);
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d %s initializing\n", "rndis_ipa_init", 571, "RNDIS_IPA");
  }
  if ( a1 )
  {
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d host_ethaddr=%pM, device_ethaddr=%pM\n",
        "rndis_ipa_init",
        580,
        a1 + 3,
        (char *)a1 + 30);
    v2 = alloc_etherdev_mqs(232, 1, 1);
    if ( v2 )
    {
      v3 = (_QWORD *)v2;
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d network device was successfully allocated\n",
          "rndis_ipa_init",
          588);
      v4 = ipa_rndis_logbuf;
      v5 = v3 + 336;
      v3[364] = 0;
      v3[363] = 0;
      v3[362] = 0;
      v3[361] = 0;
      v3[360] = 0;
      v3[359] = 0;
      v3[358] = 0;
      v3[357] = 0;
      v3[356] = 0;
      v3[355] = 0;
      v3[354] = 0;
      v3[353] = 0;
      v3[352] = 0;
      v3[351] = 0;
      v3[350] = 0;
      v3[349] = 0;
      v3[348] = 0;
      v3[347] = 0;
      v3[346] = 0;
      v3[345] = 0;
      v3[344] = 0;
      v3[343] = 0;
      v3[342] = 0;
      v3[341] = 0;
      v3[340] = 0;
      v3[339] = 0;
      v3[338] = 0;
      v3[337] = 0;
      v3[336] = 0;
      if ( v4 )
        ipc_log_string(v4, "RNDIS_IPA %s:%d rndis_ipa_ctx (private)=%pK\n", "rndis_ipa_init", 597, v3 + 336);
      *((_DWORD *)v3 + 722) = 0;
      *((_WORD *)v3 + 1356) = 256;
      v3[336] = v3;
      *((_BYTE *)v3 + 2696) = 0;
      *((_DWORD *)v3 + 675) = 0;
      *((_DWORD *)v3 + 677) = 0;
      *((_WORD *)v3 + 1352) = 0;
      *((_BYTE *)v3 + 2714) = 0;
      *(_QWORD *)((char *)v3 + 2748) = 0x2000000040LL;
      *((_DWORD *)v3 + 686) = 0;
      v6 = *(_DWORD *)((char *)a1 + 30);
      *((_WORD *)v3 + 1387) = *((_WORD *)a1 + 17);
      *(_DWORD *)((char *)v3 + 2770) = v6;
      LOWORD(v6) = *((_WORD *)a1 + 14);
      *((_DWORD *)v3 + 691) = *((_DWORD *)a1 + 6);
      v3[348] = 0xFFFFFFFE00000LL;
      *((_WORD *)v3 + 1384) = v6;
      v3[349] = v3 + 349;
      v3[350] = v3 + 349;
      v3[351] = rndis_ipa_xmit_error_aftercare_wq;
      init_timer_key(v3 + 352, &delayed_work_timer_fn, 0x200000, 0, 0);
      v7 = ipa_rndis_logbuf;
      *((_DWORD *)v3 + 689) = 500;
      if ( v7 )
        ipc_log_string(v7, "RNDIS_IPA %s:%d internal data structures were set\n", "rndis_ipa_init", 624);
      v8 = *a1;
      if ( !*a1 )
      {
        if ( ipa_rndis_logbuf )
        {
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d device_ready_notify() was not supplied\n",
            "rndis_ipa_init",
            627);
          v8 = *a1;
        }
        else
        {
          v8 = 0;
        }
      }
      v3[347] = v8;
      snprintf((char *)v3 + 296, 0x10u, "%s%%d", "rndis");
      if ( ipa_rndis_logbuf )
      {
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d Setting network interface driver name to: %s\n",
          "rndis_ipa_init",
          633,
          (const char *)v3 + 296);
        v9 = ipa_rndis_logbuf;
        v3[1] = &rndis_ipa_netdev_ops;
        *((_DWORD *)v3 + 324) = 1250;
        *((_WORD *)v3 + 30) = 44;
        if ( v9 )
        {
          ipc_log_string(v9, "RNDIS_IPA %s:%d Needed headroom for RNDIS header set to %d\n", "rndis_ipa_init", 641, 44);
          if ( ipa_rndis_logbuf )
            ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_debugfs_init", 2361);
        }
      }
      else
      {
        v3[1] = &rndis_ipa_netdev_ops;
        *((_DWORD *)v3 + 324) = 1250;
        *((_WORD *)v3 + 30) = 44;
      }
      dir = debugfs_create_dir("rndis_ipa", 0);
      v3[340] = dir;
      if ( dir )
      {
        debugfs_create_bool("tx_filter", 438, dir, v3 + 337);
        debugfs_create_bool("rx_filter", 438, v3[340], (char *)v3 + 2705);
        debugfs_create_bool("icmp_filter", 438, v3[340], (char *)v3 + 2713);
        debugfs_create_u32("outstanding_high", 438, v3[340], (char *)v3 + 2748);
        debugfs_create_u32("outstanding_low", 438, v3[340], v3 + 344);
        if ( !debugfs_create_file("outstanding", 292, v3[340], v3 + 336, &rndis_ipa_debugfs_atomic_ops) )
        {
          _ReadStatusReg(SP_EL0);
          printk(&unk_3EB801, "rndis_ipa_debugfs_init");
          if ( ipa_rndis_logbuf )
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d could not create outstanding file\n",
              "rndis_ipa_debugfs_init",
              2399);
          goto LABEL_44;
        }
        debugfs_create_u8("state", 292, v3[340], v3 + 345);
        debugfs_create_u32("tx_dropped", 292, v3[340], (char *)v3 + 2700);
        debugfs_create_u32("rx_dropped", 292, v3[340], (char *)v3 + 2708);
        v11 = debugfs_create_dir("rndis_ipa_aggregation", v3[340]);
        if ( v11 )
        {
          v12 = v11;
          if ( debugfs_create_file("aggr_value_set", 146, v11, v3 + 336, &rndis_ipa_aggr_ops) )
          {
            debugfs_create_u8("aggr_enable", 438, v12, &dword_419B8);
            debugfs_create_u8("aggr_type", 438, v12, &unk_419BC);
            debugfs_create_u32("aggr_byte_limit", 438, v12, &dword_419C0);
            debugfs_create_u32("aggr_time_limit", 438, v12, &dword_419C4);
            debugfs_create_u32("aggr_pkt_limit", 438, v12, &dword_419C8);
            debugfs_create_bool("tx_dump_enable", 438, v3[340], v3 + 338);
            debugfs_create_bool("rx_dump_enable", 438, v3[340], v3 + 339);
            debugfs_create_bool("deaggregation_enable", 438, v3[340], (char *)v3 + 2714);
            debugfs_create_u32("error_msec_sleep_time", 438, v3[340], (char *)v3 + 2756);
            debugfs_create_bool("during_xmit_error", 292, v3[340], (char *)v3 + 2715);
            debugfs_create_bool("is_vlan_mode", 292, v3[340], v3 + 362);
            if ( ipa_rndis_logbuf )
            {
              v13 = ipc_log_string(
                      ipa_rndis_logbuf,
                      "RNDIS_IPA %s:%d debugfs entries were created\n",
                      "rndis_ipa_debugfs_init",
                      2484);
              if ( ipa_rndis_logbuf )
                ipc_log_string(
                  ipa_rndis_logbuf,
                  "RNDIS_IPA %s:%d end\n",
                  "rndis_ipa_debugfs_init",
                  2485,
                  *(double *)&v13);
            }
            goto LABEL_45;
          }
          _ReadStatusReg(SP_EL0);
          printk(&unk_3BFF9D, "rndis_ipa_debugfs_init");
          if ( ipa_rndis_logbuf )
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d could not create aggr_value_set file\n",
              "rndis_ipa_debugfs_init",
              2428);
LABEL_44:
          debugfs_remove(v3[340]);
          goto LABEL_45;
        }
        _ReadStatusReg(SP_EL0);
        printk(&unk_3E8A4E, "rndis_ipa_debugfs_init");
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d could not create debugfs aggr entry\n",
            "rndis_ipa_debugfs_init",
            2419,
            v16);
      }
      else
      {
        _ReadStatusReg(SP_EL0);
        printk(&unk_3BA4C4, "rndis_ipa_debugfs_init");
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d could not create debugfs directory entry\n",
            "rndis_ipa_debugfs_init",
            2368,
            v15);
      }
LABEL_45:
      v17 = *(_DWORD *)((char *)v3 + 2770);
      if ( (v17 & 1) != 0 || !(v17 | *((unsigned __int16 *)v3 + 1387)) )
      {
        _ReadStatusReg(SP_EL0);
        printk(&unk_3F453E, "rndis_ipa_init");
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d set device MAC failed\n", "rndis_ipa_init", 648);
        v14 = -22;
        goto LABEL_54;
      }
      *((_BYTE *)v3 + 824) = 6;
      dev_addr_mod(v3, 0, (char *)v3 + 2770, 6);
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d Device Ethernet address set %pM\n",
          "rndis_ipa_init",
          651,
          (const void *)v3[126]);
      if ( (unsigned int)ipa_is_vlan_mode(3u, (unsigned __int8 *)v3 + 2896) )
      {
        if ( (unsigned int)__ratelimit(&rndis_ipa_init__rs, "rndis_ipa_init") )
        {
          _ReadStatusReg(SP_EL0);
          printk(&unk_3DA6AB, "rndis_ipa_init");
          v18 = ipa_rndis_logbuf;
          if ( !ipa_rndis_logbuf )
            goto LABEL_53;
        }
        else
        {
          v18 = ipa_rndis_logbuf;
          if ( !ipa_rndis_logbuf )
          {
LABEL_53:
            v14 = 0;
LABEL_54:
            debugfs_remove(v3[340]);
            free_netdev(v3);
            return v14;
          }
        }
        ipc_log_string(v18, "RNDIS_IPA %s:%d couldn't acquire vlan mode, is ipa ready?\n", "rndis_ipa_init", 655);
        goto LABEL_53;
      }
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d is_vlan_mode %d\n",
          "rndis_ipa_init",
          658,
          *((unsigned __int8 *)v3 + 2896));
      is_ulso_supported = ipa3_is_ulso_supported();
      v21 = ipa_rndis_logbuf;
      *((_BYTE *)v3 + 2912) = is_ulso_supported & 1;
      if ( v21 )
      {
        ipc_log_string(v21, "RNDIS_IPA %s:%d is_ulso_mode=%d\n", "rndis_ipa_init", 661, is_ulso_supported & 1);
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_hdrs_cfg", 1775);
      }
      v22 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
      v23 = v22;
      if ( !v22 )
      {
        v14 = -12;
        goto LABEL_103;
      }
      ((void (__fastcall *)(__int64, const char *, __int64, __int64 *, char *, _QWORD))rndis_ipa_prepare_header_insertion)(
        2048,
        "rndis_eth_ipv4",
        v22 + 4,
        a1 + 3,
        (char *)a1 + 30,
        *((unsigned __int8 *)v3 + 2896));
      ((void (__fastcall *)(__int64, const char *, __int64, __int64 *, char *, _QWORD))rndis_ipa_prepare_header_insertion)(
        34525,
        "rndis_eth_ipv6",
        v23 + 312,
        a1 + 3,
        (char *)a1 + 30,
        *((unsigned __int8 *)v3 + 2896));
      *(_WORD *)v23 = 513;
      v24 = ipa_add_hdr(v23);
      if ( v24 )
      {
        v14 = v24;
        _ReadStatusReg(SP_EL0);
        printk(&unk_3AECCD, "rndis_ipa_hdrs_cfg");
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d Fail on Header-Insertion(%d)\n",
            "rndis_ipa_hdrs_cfg",
            1795,
            v14);
        kfree(v23);
        goto LABEL_103;
      }
      if ( *(_DWORD *)(v23 + 304) )
      {
        _ReadStatusReg(SP_EL0);
        v27 = (unsigned int *)(v23 + 304);
        printk(&unk_3F6E27, "rndis_ipa_hdrs_cfg");
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d Fail on Header-Insertion ipv4(%d)\n",
            "rndis_ipa_hdrs_cfg",
            1800,
            *v27);
      }
      else
      {
        if ( !*(_DWORD *)(v23 + 612) )
        {
          v25 = ipa_rndis_logbuf;
          *((_DWORD *)v3 + 682) = *(_DWORD *)(v23 + 300);
          *((_DWORD *)v3 + 683) = *(_DWORD *)(v23 + 608);
          if ( v25 )
            ipc_log_string(v25, "RNDIS_IPA %s:%d end\n", "rndis_ipa_hdrs_cfg", 1813);
          kfree(v23);
          goto LABEL_85;
        }
        _ReadStatusReg(SP_EL0);
        v27 = (unsigned int *)(v23 + 612);
        printk(&unk_3D79AC, "rndis_ipa_hdrs_cfg");
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d Fail on Header-Insertion ipv6(%d)\n",
            "rndis_ipa_hdrs_cfg",
            1806,
            *v27);
      }
      v14 = *v27;
      kfree(v23);
      if ( v14 )
      {
LABEL_103:
        _ReadStatusReg(SP_EL0);
        printk(&unk_3BFEC7, "rndis_ipa_init");
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d fail on ipa hdrs set\n", "rndis_ipa_init", 666);
        goto LABEL_54;
      }
LABEL_85:
      if ( ipa_rndis_logbuf )
        v26 = ipc_log_string(
                ipa_rndis_logbuf,
                "RNDIS_IPA %s:%d IPA header-insertion configured for Ethernet\n",
                "rndis_ipa_init",
                669);
      if ( *((_BYTE *)v3 + 2912) == 1 )
      {
        v28 = rndis_ipa_hdrs_hpc_cfg(v3 + 336, v26);
        if ( v28 )
        {
          v14 = v28;
          _ReadStatusReg(SP_EL0);
          printk(&unk_3F6D1E, "rndis_ipa_init");
          if ( ipa_rndis_logbuf )
            ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d fail on ipa hdrs hpc set\n", "rndis_ipa_init", 674);
          goto LABEL_114;
        }
        if ( ipa_rndis_logbuf )
          v26 = ipc_log_string(
                  ipa_rndis_logbuf,
                  "RNDIS_IPA %s:%d IPA header-insertion configured for RNDIS\n",
                  "rndis_ipa_init",
                  677);
        *(_QWORD *)(*v5 + 496LL) = 0x10000000000LL;
        *(_QWORD *)(*v5 + 496LL) |= 0x12uLL;
        *(_QWORD *)(*v5 + 496LL) |= 1uLL;
        *(_QWORD *)(*v5 + 496LL) |= 0x80000000000000uLL;
        *(_QWORD *)(*v5 + 496LL) |= 0x200000000uLL;
        *(_QWORD *)(*v5 + 496LL) |= 0x1D0000uLL;
        *(_DWORD *)(*v5 + 44LL) = 64000;
      }
      v29 = rndis_ipa_register_properties(*((unsigned __int8 *)v3 + 2896), v26);
      if ( v29 )
      {
        v14 = v29;
        _ReadStatusReg(SP_EL0);
        printk(&unk_3B7196, "rndis_ipa_init");
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d fail on properties set\n", "rndis_ipa_init", 692);
      }
      else
      {
        if ( ipa_rndis_logbuf )
          v30 = ipc_log_string(
                  ipa_rndis_logbuf,
                  "RNDIS_IPA %s:%d 2 TX and 2 RX properties were registered\n",
                  "rndis_ipa_init",
                  695);
        netif_carrier_off(v3, v30);
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d set carrier off until pipes are connected\n",
            "rndis_ipa_init",
            698);
        v31 = register_netdev(v3);
        if ( !v31 )
        {
          if ( ipa_rndis_logbuf )
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d netdev:%s registration succeeded, index=%d\n",
              "rndis_ipa_init",
              707,
              (const char *)v3 + 296,
              *((_DWORD *)v3 + 56));
          if ( (ipa_get_lan_rx_napi() & 1) != 0 )
          {
            v33 = ipa_rndis_logbuf;
            v3[363] = &netif_receive_skb;
            if ( v33 )
              ipc_log_string(v33, "RNDIS_IPA %s:%d LAN RX NAPI enabled = True", "rndis_ipa_init", 711);
          }
          else
          {
            v35 = ipa_rndis_logbuf;
            v3[363] = &netif_rx;
            if ( v35 )
              ipc_log_string(v35, "RNDIS_IPA %s:%d LAN RX NAPI enabled = False", "rndis_ipa_init", 718);
          }
          if ( *((_BYTE *)v3 + 2896) == 1 )
            qmap_template_hdr = qmap_template_hdr & 0xFFFFE0FFFFFFFFFFLL | 0x40000000000LL;
          rndis_ipa = (__int64)(v3 + 336);
          v36 = ipa_rndis_logbuf;
          a1[1] = (__int64)rndis_ipa_packet_receive_notify;
          a1[2] = (__int64)rndis_ipa_tx_complete_notify;
          a1[5] = (__int64)v5;
          *((_BYTE *)a1 + 48) = 0;
          *((_DWORD *)v3 + 690) = 1;
          if ( v36 )
            ipc_log_string(v36, "RNDIS_IPA %s:%d Driver state: %s\n", "rndis_ipa_init", 731, "RNDIS_IPA_INITIALIZED");
          printk(&unk_3A5CE3, v32);
          if ( ipa_rndis_logbuf )
            ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_init", 734);
          return 0;
        }
        v14 = v31;
        _ReadStatusReg(SP_EL0);
        printk(&unk_3CEE1B, "rndis_ipa_init");
        if ( ipa_rndis_logbuf )
          v34 = ipc_log_string(
                  ipa_rndis_logbuf,
                  "RNDIS_IPA %s:%d register_netdev failed: %d\n",
                  "rndis_ipa_init",
                  702,
                  v14);
        rndis_ipa_deregister_properties(v3 + 37, v34);
      }
      if ( *((_BYTE *)v3 + 2912) == 1 )
        ipa_hdrs_hpc_destroy(*((_DWORD *)v3 + 729));
LABEL_114:
      rndis_ipa_hdrs_destroy(v3 + 336);
      goto LABEL_54;
    }
    _ReadStatusReg(SP_EL0);
    printk(&unk_3BA3F6, "rndis_ipa_init");
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d fail to allocate Ethernet device\n", "rndis_ipa_init", 585);
    return (unsigned int)-12;
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3E01BA, "rndis_ipa_init");
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d null pointer #ptr\n", "rndis_ipa_init", 573);
    return (unsigned int)-22;
  }
}
