long double ipa3_wwan_remove()
{
  __int64 ipc_logbuf; // x0
  long double v1; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  _DWORD *v5; // x19
  __int64 v6; // x24
  char v7; // w8
  __int64 v8; // x9
  char v9; // w26
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  const char *v19; // x20
  __int64 v20; // x0
  __int64 v21; // x19
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x9
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x9
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x27
  __int64 v43; // x22
  __int64 v44; // x19
  int v45; // w25
  __int64 v46; // x0
  __int64 v47; // x27
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  _BYTE *v56; // x0
  _DWORD *v57; // x19
  __int64 v58; // x23
  __int64 v59; // x24
  __int64 v60; // x8
  int v61; // w25
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x9
  __int64 v65; // x19
  __int64 v66; // x23
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x0
  long double result; // q0
  __int64 v74; // x0
  int v75; // w20
  __int64 v76; // x0
  __int64 v77; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v79; // x22
  __int64 (__fastcall *v80)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0

  printk(&unk_3F3987, "ipa3_wwan_remove");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d rmnet_ipa started deinitialization\n", "ipa3_wwan_remove", 3858);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v1 = ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d rmnet_ipa started deinitialization\n", "ipa3_wwan_remove", 3858);
  }
  ipa_teardown_pipes(v1);
  cancel_work_sync(&ipa3_tx_wakequeue_work);
  v3 = cancel_delayed_work(&ipa_tether_stats_poll_wakequeue_work);
  if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1056) )
    ipa3_wan_ioctl_deinit(v3);
  if ( *(_BYTE *)(ipa3_ctx + 48859) == 1 && (unsigned int)ipa_get_ep_mapping(121) != -1 )
  {
    v4 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
    v5 = (_DWORD *)v4;
    if ( v4 )
    {
      v6 = 0;
      v7 = 1;
      *(_BYTE *)v4 = 1;
      *(_BYTE *)(v4 + 8) = 1;
      *(_DWORD *)(v4 + 16) = -1;
      do
      {
        v8 = rmnet_ipa3_ctx;
        v5[1] = v6;
        v9 = v7;
        v5[3] = *(_DWORD *)(v8 + 8 * v6 + 540);
        if ( ipa3_get_ipc_logbuf() )
        {
          v10 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v10,
            "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
            "ipa3_del_low_lat_rt_rule",
            738,
            v5[3],
            v6);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v11 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v11,
            "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
            "ipa3_del_low_lat_rt_rule",
            738,
            v5[3],
            v6);
        }
        if ( (unsigned int)ipa3_del_rt_rule((__int64)v5) || v5[4] )
        {
          printk(&unk_3DF60E, "ipa3_del_low_lat_rt_rule");
          if ( ipa3_get_ipc_logbuf() )
          {
            v17 = ipa3_get_ipc_logbuf();
            ipc_log_string(v17, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_low_lat_rt_rule", 741);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v18 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v18, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_low_lat_rt_rule", 741);
          }
        }
        v12 = rmnet_ipa3_ctx;
        v5[1] = v6;
        v5[3] = *(_DWORD *)(v12 + 8 * v6 + 544);
        if ( ipa3_get_ipc_logbuf() )
        {
          v13 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v13,
            "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
            "ipa3_del_low_lat_rt_rule",
            738,
            v5[3],
            v6);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v14,
            "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
            "ipa3_del_low_lat_rt_rule",
            738,
            v5[3],
            v6);
        }
        if ( (unsigned int)ipa3_del_rt_rule((__int64)v5) || v5[4] )
        {
          printk(&unk_3DF60E, "ipa3_del_low_lat_rt_rule");
          if ( ipa3_get_ipc_logbuf() )
          {
            v15 = ipa3_get_ipc_logbuf();
            ipc_log_string(v15, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_low_lat_rt_rule", 741);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v16 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v16, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_low_lat_rt_rule", 741);
          }
        }
        v7 = 0;
        v6 = 1;
      }
      while ( (v9 & 1) != 0 );
      kfree(v5);
    }
  }
  if ( (unsigned int)ipa_get_ep_mapping(35) == -1 )
    goto LABEL_79;
  LODWORD(v19) = *(_DWORD *)(ipa3_ctx + 32240);
  v20 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
  v21 = v20;
  if ( v20 )
  {
LABEL_35:
    *(_DWORD *)(v21 + 4) = 0;
    *(_BYTE *)v21 = 1;
    *(_BYTE *)(v21 + 8) = 1;
    v22 = rmnet_ipa3_ctx;
    *(_DWORD *)(v21 + 16) = -1;
    *(_DWORD *)(v21 + 12) = *(_DWORD *)(v22 + 524);
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v23,
        "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
        "ipa3_del_dflt_wan_rt_tables",
        700,
        *(_DWORD *)(v21 + 12),
        0);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v24,
        "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
        "ipa3_del_dflt_wan_rt_tables",
        700,
        *(_DWORD *)(v21 + 12),
        0);
    }
    if ( (unsigned int)ipa3_del_rt_rule(v21) || *(_DWORD *)(v21 + 16) )
    {
      printk(&unk_3DF60E, "ipa3_del_dflt_wan_rt_tables");
      if ( ipa3_get_ipc_logbuf() )
      {
        v25 = ipa3_get_ipc_logbuf();
        ipc_log_string(v25, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v26 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v26, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
      }
    }
    if ( (unsigned int)v19 >= 0x15 )
    {
      v27 = rmnet_ipa3_ctx;
      *(_DWORD *)(v21 + 4) = 0;
      *(_DWORD *)(v21 + 12) = *(_DWORD *)(v27 + 528);
      if ( ipa3_get_ipc_logbuf() )
      {
        v28 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v28,
          "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
          "ipa3_del_dflt_wan_rt_tables",
          700,
          *(_DWORD *)(v21 + 12),
          0);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v29 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v29,
          "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
          "ipa3_del_dflt_wan_rt_tables",
          700,
          *(_DWORD *)(v21 + 12),
          0);
      }
      if ( (unsigned int)ipa3_del_rt_rule(v21) || *(_DWORD *)(v21 + 16) )
      {
        printk(&unk_3DF60E, "ipa3_del_dflt_wan_rt_tables");
        if ( ipa3_get_ipc_logbuf() )
        {
          v30 = ipa3_get_ipc_logbuf();
          ipc_log_string(v30, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v31 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v31, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
        }
      }
    }
    v32 = rmnet_ipa3_ctx;
    *(_DWORD *)(v21 + 4) = 1;
    *(_DWORD *)(v21 + 12) = *(_DWORD *)(v32 + 532);
    if ( ipa3_get_ipc_logbuf() )
    {
      v33 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v33,
        "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
        "ipa3_del_dflt_wan_rt_tables",
        700,
        *(_DWORD *)(v21 + 12),
        1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v34 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v34,
        "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
        "ipa3_del_dflt_wan_rt_tables",
        700,
        *(_DWORD *)(v21 + 12),
        1);
    }
    if ( (unsigned int)ipa3_del_rt_rule(v21) || *(_DWORD *)(v21 + 16) )
    {
      printk(&unk_3DF60E, "ipa3_del_dflt_wan_rt_tables");
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        ipc_log_string(v35, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v36 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v36, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
      }
    }
    if ( (unsigned int)v19 >= 0x15 )
    {
      v37 = rmnet_ipa3_ctx;
      *(_DWORD *)(v21 + 4) = 1;
      *(_DWORD *)(v21 + 12) = *(_DWORD *)(v37 + 536);
      if ( ipa3_get_ipc_logbuf() )
      {
        v38 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v38,
          "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
          "ipa3_del_dflt_wan_rt_tables",
          700,
          *(_DWORD *)(v21 + 12),
          1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v39 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v39,
          "ipa-wan %s:%d Deleting Route hdl:(0x%x) with ip type: %d\n",
          "ipa3_del_dflt_wan_rt_tables",
          700,
          *(_DWORD *)(v21 + 12),
          1);
      }
      if ( (unsigned int)ipa3_del_rt_rule(v21) || *(_DWORD *)(v21 + 16) )
      {
        printk(&unk_3DF60E, "ipa3_del_dflt_wan_rt_tables");
        if ( ipa3_get_ipc_logbuf() )
        {
          v40 = ipa3_get_ipc_logbuf();
          ipc_log_string(v40, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v41 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v41, "ipa-wan %s:%d Routing rule deletion failed\n", "ipa3_del_dflt_wan_rt_tables", 703);
        }
      }
    }
    v20 = kfree(v21);
    goto LABEL_78;
  }
  while ( 1 )
  {
LABEL_78:
    ipa3_del_a7_qmap_hdr(v20);
LABEL_79:
    v42 = rmnet_ipa3_ctx;
    if ( *(int *)(rmnet_ipa3_ctx + 1044) >= 1 )
    {
      v43 = 0;
      v19 = "ipa3_del_qmap_hdr";
      v44 = 580;
      _ReadStatusReg(SP_EL0);
      while ( v43 != 15 )
      {
        v45 = *(_DWORD *)(v42 + v44);
        if ( v45 )
        {
          v46 = _kmalloc_cache_noprof(kfree, 3520, 12);
          v47 = v46;
          if ( v46 )
          {
            *(_WORD *)v46 = 257;
            *(_DWORD *)(v46 + 4) = v45;
            if ( (unsigned int)ipa_del_hdr((_BYTE *)v46) || *(_DWORD *)(v47 + 8) )
            {
              printk(&unk_3A4C5A, "ipa3_del_qmap_hdr");
              if ( ipa3_get_ipc_logbuf() )
              {
                v50 = ipa3_get_ipc_logbuf();
                ipc_log_string(v50, "ipa-wan %s:%d ipa_del_hdr failed\n", "ipa3_del_qmap_hdr", 368);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v51 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v51, "ipa-wan %s:%d ipa_del_hdr failed\n");
              }
            }
            else
            {
              if ( ipa3_get_ipc_logbuf() )
              {
                v48 = ipa3_get_ipc_logbuf();
                ipc_log_string(v48, "ipa-wan %s:%d header deletion done\n", "ipa3_del_qmap_hdr", 370);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v49 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v49, "ipa-wan %s:%d header deletion done\n");
              }
            }
            *(_DWORD *)(rmnet_ipa3_ctx + 520) = 0;
            kfree(v47);
          }
          else
          {
            printk(&unk_3C8338, "ipa3_del_qmap_hdr");
            if ( ipa3_get_ipc_logbuf() )
            {
              v54 = ipa3_get_ipc_logbuf();
              ipc_log_string(v54, "ipa-wan %s:%d fail to alloc exception hdr_del\n", "ipa3_del_qmap_hdr", 357);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v55 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v55, "ipa-wan %s:%d fail to alloc exception hdr_del\n", "ipa3_del_qmap_hdr", 357);
            }
          }
        }
        else
        {
          printk(&unk_3AB090, "ipa3_del_qmap_hdr");
          if ( ipa3_get_ipc_logbuf() )
          {
            v52 = ipa3_get_ipc_logbuf();
            ipc_log_string(v52, "ipa-wan %s:%d Invalid hdr_hdl provided\n", "ipa3_del_qmap_hdr", 349);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v53 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v53, "ipa-wan %s:%d Invalid hdr_hdl provided\n", "ipa3_del_qmap_hdr", 349);
          }
        }
        v42 = rmnet_ipa3_ctx;
        ++v43;
        *(_DWORD *)(rmnet_ipa3_ctx + v44) = 0;
        v44 += 32;
        if ( v43 >= *(int *)(v42 + 1044) )
          goto LABEL_104;
      }
      goto LABEL_141;
    }
LABEL_104:
    if ( ipa3_qmi_ctx )
    {
      if ( (*(_BYTE *)(ipa3_qmi_ctx + 28860) & 1) == 0 )
      {
        v56 = (_BYTE *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
        v57 = v56;
        v42 = rmnet_ipa3_ctx;
        if ( v56 )
        {
          *v56 = 1;
          v56[8] = 1;
          if ( *(int *)(v42 + 1040) >= 1 )
          {
            v58 = 0;
            v19 = "ipa-wan %s:%d delete-IPA rule index(%d)\n";
            v59 = 1890;
            while ( v59 != 1925 )
            {
              v60 = ipa3_qmi_ctx;
              v57[1] = *(_DWORD *)(ipa3_qmi_ctx + v58);
              v61 = *(_DWORD *)(v60 + 4 * v59);
              if ( ipa3_get_ipc_logbuf() )
              {
                v62 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v62,
                  "ipa-wan %s:%d delete-IPA rule index(%d)\n",
                  "ipa3_wwan_del_ul_flt_rule_to_ipa",
                  1115,
                  v59 - 1890);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v63 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v63,
                  "ipa-wan %s:%d delete-IPA rule index(%d)\n",
                  "ipa3_wwan_del_ul_flt_rule_to_ipa",
                  1115,
                  v59 - 1890);
              }
              v57[3] = v61;
              v57[4] = 0;
              if ( (unsigned int)ipa3_del_flt_rule((__int64)v57) )
              {
                v75 = v59 - 1890;
                printk(&unk_3B946F, "ipa3_wwan_del_ul_flt_rule_to_ipa");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v76 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v76,
                    "ipa-wan %s:%d del A7 UL filter rule(%d) failed\n",
                    "ipa3_wwan_del_ul_flt_rule_to_ipa",
                    1119,
                    v75);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v77 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v77,
                    "ipa-wan %s:%d del A7 UL filter rule(%d) failed\n",
                    "ipa3_wwan_del_ul_flt_rule_to_ipa",
                    1119,
                    v75);
                }
                goto LABEL_117;
              }
              v42 = rmnet_ipa3_ctx;
              v64 = v59 - 1889;
              ++v59;
              v58 += 216;
              if ( v64 >= *(int *)(rmnet_ipa3_ctx + 1040) )
                goto LABEL_116;
            }
            goto LABEL_141;
          }
LABEL_116:
          *(_BYTE *)(v42 + 1049) = 0;
          *(_DWORD *)(v42 + 1040) = 0;
LABEL_117:
          kfree(v57);
          v42 = rmnet_ipa3_ctx;
        }
      }
    }
    if ( *(int *)(v42 + 1044) < 1 )
      break;
    v65 = 0;
    v19 = "ipa-wan %s:%d de-register device %s(%d) success\n";
    v66 = 577;
    while ( v65 != 15 )
    {
      if ( *(_BYTE *)(v42 + v66) == 1 )
      {
        if ( (((__int64 (__fastcall *)(__int64))ipa_deregister_intf)(v42 + v66 - 17) & 0x80000000) != 0 )
        {
          printk(&unk_3DCA06, "ipa3_cleanup_deregister_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v69 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v69,
              "ipa-wan %s:%d de-register device %s(%d) failed\n",
              "ipa3_cleanup_deregister_intf",
              1329,
              (const char *)(v42 + v66 - 17),
              v65);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v70 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v70,
              "ipa-wan %s:%d de-register device %s(%d) failed\n",
              "ipa3_cleanup_deregister_intf",
              1329,
              (const char *)(v42 + v66 - 17),
              v65);
          }
          goto LABEL_132;
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v67 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v67,
            "ipa-wan %s:%d de-register device %s(%d) success\n",
            "ipa3_cleanup_deregister_intf",
            1334,
            (const char *)(v42 + v66 - 17),
            v65);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v68 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v68,
            "ipa-wan %s:%d de-register device %s(%d) success\n",
            "ipa3_cleanup_deregister_intf",
            1334,
            (const char *)(v42 + v66 - 17),
            v65);
        }
      }
      v42 = rmnet_ipa3_ctx;
      ++v65;
      *(_BYTE *)(rmnet_ipa3_ctx + v66) = 0;
      v66 += 32;
      if ( v65 >= *(int *)(v42 + 1044) )
        goto LABEL_132;
    }
LABEL_141:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v79 = *(_QWORD *)(StatusReg + 80);
    v80 = of_property_read_variable_u32_array;
    *(_QWORD *)(StatusReg + 80) = &ipa3_del_dflt_wan_rt_tables__alloc_tag;
    v20 = _kmalloc_cache_noprof(v80, 3520, 20);
    v21 = v20;
    *(_QWORD *)(StatusReg + 80) = v79;
    if ( v20 )
      goto LABEL_35;
  }
LABEL_132:
  v71 = rmnet_ipa3_ctx;
  *(_BYTE *)(rmnet_ipa3_ctx + 1984) = 0;
  *(_DWORD *)(v71 + 1052) = 0;
  egress_ioctl_v2_data = 0;
  qword_2017A8 = 0;
  ingress_ioctl_v2_data = 0;
  qword_2017B8 = 0;
  egress_param = 0;
  qword_2017C8 = 0;
  qword_2017D0 = 0;
  qword_2017D8 = 0;
  qword_2017E0 = 0;
  qword_2017E8 = 0;
  qword_2017F0 = 0;
  qword_2017F8 = 0;
  qword_201800 = 0;
  qword_201808 = 0;
  qword_201810 = 0;
  qword_201818 = 0;
  qword_2018B0 = 0;
  qword_2018B8 = 0;
  qword_2018A0 = 0;
  qword_2018A8 = 0;
  qword_201890 = 0;
  qword_201898 = 0;
  qword_201880 = 0;
  qword_201888 = 0;
  qword_201870 = 0;
  qword_201878 = 0;
  qword_201860 = 0;
  qword_201868 = 0;
  qword_201850 = 0;
  qword_201858 = 0;
  qword_201840 = 0;
  qword_201848 = 0;
  qword_201830 = 0;
  qword_201838 = 0;
  ingress_param = 0;
  qword_201828 = 0;
  printk(&unk_3F0491, "ipa3_wwan_remove");
  if ( ipa3_get_ipc_logbuf() )
  {
    v72 = ipa3_get_ipc_logbuf();
    ipc_log_string(v72, "ipa-wan %s:%d rmnet_ipa completed deinitialization\n", "ipa3_wwan_remove", 3898);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v74 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(v74, "ipa-wan %s:%d rmnet_ipa completed deinitialization\n", "ipa3_wwan_remove", 3898);
  }
  return result;
}
