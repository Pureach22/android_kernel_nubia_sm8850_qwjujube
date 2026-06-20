__int64 __fastcall ipa_setup_prod_pipes(__int64 a1, char a2)
{
  __int64 v3; // x24
  unsigned __int64 v4; // x27
  unsigned int v5; // w26
  unsigned __int64 v6; // x23
  char *v7; // x28
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  long double v11; // q0
  __int64 v12; // x0
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x19
  __int64 v31; // x26
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  int v36; // w8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  unsigned int v42; // w0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x19
  __int64 v56; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v58; // x9
  unsigned __int64 v59; // x9
  unsigned __int64 v65; // x8
  unsigned __int64 v66; // x8
  unsigned __int64 v68; // x9
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  char v76; // [xsp+4h] [xbp-Ch]

  mutex_lock(rmnet_ipa3_ctx + 1088);
  if ( !HIDWORD(qword_2017A8) )
  {
    v5 = 0;
    if ( (a2 & 1) != 0 )
    {
      v55 = 0;
      goto LABEL_165;
    }
    goto LABEL_178;
  }
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 28;
  v76 = a2;
  do
  {
    if ( v6 == 124 )
    {
      __break(0x5512u);
      JUMPOUT(0x151810);
    }
    if ( v6 - 24 > 0x60 )
    {
LABEL_188:
      __break(1u);
LABEL_189:
      printk(&unk_3FF241, "ipa_setup_prod_pipes");
LABEL_183:
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa-wan %s:%d Failed to setup wan prod pipes\n", "ipa_setup_prod_pipes", 2334);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d Failed to setup wan prod pipes\n", "ipa_setup_prod_pipes", 2334);
      }
      v71 = rmnet_ipa3_ctx;
      goto LABEL_177;
    }
    v7 = (char *)&egress_param + v6;
    *(_DWORD *)((char *)&egress_param + v6 - 24) = 1;
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      if ( v6 - 20 > 0x60 || v6 - 16 > 0x60 || v6 - 12 > 0x60 )
        goto LABEL_188;
      ipc_log_string(
        v8,
        "ipa-wan %s:%d cs_offload_en = %d, aggr_en = %d, ulso_en = %d\n",
        "ipa_setup_prod_pipes",
        2313,
        *(_DWORD *)((char *)&egress_param + v6 - 20),
        *(_DWORD *)((char *)&egress_param + v6 - 16),
        *(_DWORD *)((char *)&egress_param + v6 - 12));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      if ( v6 - 20 > 0x60 || v6 - 16 > 0x60 || v6 - 12 > 0x60 )
        goto LABEL_188;
      ipc_log_string(
        v9,
        "ipa-wan %s:%d cs_offload_en = %d, aggr_en = %d, ulso_en = %d\n",
        "ipa_setup_prod_pipes",
        2313,
        *(_DWORD *)((char *)&egress_param + v6 - 20),
        *(_DWORD *)((char *)&egress_param + v6 - 16),
        *(_DWORD *)((char *)&egress_param + v6 - 12));
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      if ( v6 - 8 > 0x60 || v6 - 4 > 0x60 || v6 > 0x60 )
        goto LABEL_188;
      ipc_log_string(
        v10,
        "ipa-wan %s:%d ipid_min_max_idx = %d, int_modt = %d, int_modc = %d\n",
        "ipa_setup_prod_pipes",
        2317,
        *(_DWORD *)((char *)&egress_param + v6 - 8),
        *(_DWORD *)((char *)&egress_param + v6 - 4),
        *(_DWORD *)((char *)&egress_param + v6));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      if ( v6 - 8 > 0x60 || v6 - 4 > 0x60 || v6 > 0x60 )
        goto LABEL_188;
      v11 = ipc_log_string(
              v12,
              "ipa-wan %s:%d ipid_min_max_idx = %d, int_modt = %d, int_modc = %d\n",
              "ipa_setup_prod_pipes",
              2317,
              *(_DWORD *)((char *)&egress_param + v6 - 8),
              *(_DWORD *)((char *)&egress_param + v6 - 4),
              *(_DWORD *)((char *)&egress_param + v6));
    }
    v13 = *((_DWORD *)v7 - 7);
    if ( v13 )
    {
      if ( v13 != 1 )
      {
        if ( v13 != 2 )
        {
          if ( (unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs_333, "ipa_setup_prod_pipes") )
          {
            printk(&unk_3E4ABD, "ipa_setup_prod_pipes");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_74:
              v26 = ipa3_get_ipc_logbuf();
              ipc_log_string(v26, "ipa-wan %s:%d Egress ep type not defined", "ipa_setup_prod_pipes", 2402);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_74;
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v27 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v27, "ipa-wan %s:%d Egress ep type not defined", "ipa_setup_prod_pipes", 2402);
          }
          goto LABEL_4;
        }
        if ( egress_pipe_status[0] != 0x200000002LL && qword_2018F0 != 0x200000002LL && qword_2018F8 != 0x200000002LL )
          goto LABEL_38;
        *((_DWORD *)v7 - 6) = 2;
        if ( (unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs_327, "ipa_setup_prod_pipes") )
        {
          printk(&unk_3A4BAE, "ipa_setup_prod_pipes");
          if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_36:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v15 = ipa3_get_ipc_logbuf_low();
              v11 = ipc_log_string(
                      v15,
                      "ipa-wan %s:%d Receiving egress low lat data ioctl again",
                      "ipa_setup_prod_pipes",
                      2379);
            }
LABEL_38:
            if ( *(_BYTE *)(ipa3_ctx + 48859) == 1 && *((_DWORD *)v7 - 6) == 2 )
              goto LABEL_4;
            LODWORD(egress_pipe_status[v3]) = 2;
            v16 = ipa3_setup_apps_low_lat_data_prod_pipe(v7 - 28, a1, v11);
            if ( v16 )
            {
              v5 = v16;
              printk(&unk_3BF08A, "ipa_setup_prod_pipes");
              if ( ipa3_get_ipc_logbuf() )
              {
                v37 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v37,
                  "ipa-wan %s:%d failed to setup egress low lat data endpoint\n",
                  "ipa_setup_prod_pipes",
                  2393);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v38 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v38,
                  "ipa-wan %s:%d failed to setup egress low lat data endpoint\n",
                  "ipa_setup_prod_pipes",
                  2393);
              }
LABEL_62:
              if ( (unsigned __int64)(v3 * 8 + 4) > 0x18 )
                goto LABEL_188;
              HIDWORD(egress_pipe_status[v3]) = 1;
              goto LABEL_4;
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v17 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v17,
                "ipa-wan %s:%d Egress LOW LAT DATA pipe setup successfully\n",
                "ipa_setup_prod_pipes",
                2397);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v18 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v18,
                "ipa-wan %s:%d Egress LOW LAT DATA pipe setup successfully\n",
                "ipa_setup_prod_pipes",
                2397);
            }
            goto LABEL_81;
          }
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
          goto LABEL_36;
        }
        v14 = ipa3_get_ipc_logbuf();
        ipc_log_string(v14, "ipa-wan %s:%d Receiving egress low lat data ioctl again", "ipa_setup_prod_pipes", 2379);
        goto LABEL_36;
      }
      if ( egress_pipe_status[0] != 0x200000001LL && qword_2018F0 != 0x200000001LL && qword_2018F8 != 0x200000001LL )
      {
LABEL_53:
        if ( *(_BYTE *)(ipa3_ctx + 48858) == 1 && *((_DWORD *)v7 - 6) == 2 )
          goto LABEL_4;
        LODWORD(egress_pipe_status[v3]) = 1;
        v21 = ipa3_setup_apps_low_lat_prod_pipe(1, (_DWORD *)v7 - 7);
        if ( v21 )
        {
          v5 = v21;
          if ( (unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs_323, "ipa_setup_prod_pipes") )
            printk(&unk_3C5326, "ipa_setup_prod_pipes");
          if ( ipa3_get_ipc_logbuf() )
          {
            v22 = ipa3_get_ipc_logbuf();
            ipc_log_string(v22, "ipa-wan %s:%d failed to setup egress low lat endpoint\n", "ipa_setup_prod_pipes", 2362);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v23 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v23, "ipa-wan %s:%d failed to setup egress low lat endpoint\n", "ipa_setup_prod_pipes", 2362);
          }
          goto LABEL_62;
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v28 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v28,
            "ipa-wan %s:%d Egress LOW LAT CTRL pipe setup successfully\n",
            "ipa_setup_prod_pipes",
            2366);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v29 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v29,
            "ipa-wan %s:%d Egress LOW LAT CTRL pipe setup successfully\n",
            "ipa_setup_prod_pipes",
            2366);
        }
        goto LABEL_81;
      }
      *((_DWORD *)v7 - 6) = 2;
      if ( (unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs_320, "ipa_setup_prod_pipes") )
      {
        printk(&unk_3E4A88, "ipa_setup_prod_pipes");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_51:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v20 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v20, "ipa-wan %s:%d Receiving egress low lat ioctl again", "ipa_setup_prod_pipes", 2347);
          }
          goto LABEL_53;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_51;
      }
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa-wan %s:%d Receiving egress low lat ioctl again", "ipa_setup_prod_pipes", 2347);
      goto LABEL_51;
    }
    if ( egress_pipe_status[0] == 0x200000000LL || qword_2018F0 == 0x200000000LL || qword_2018F8 == 0x200000000LL )
    {
      if ( (unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs, "ipa_setup_prod_pipes") )
      {
        printk(&unk_3DC829, "ipa_setup_prod_pipes");
        if ( ipa3_get_ipc_logbuf() )
        {
LABEL_69:
          v24 = ipa3_get_ipc_logbuf();
          ipc_log_string(v24, "ipa-wan %s:%d Receiving egress default ioctl again", "ipa_setup_prod_pipes", 2323);
        }
      }
      else if ( ipa3_get_ipc_logbuf() )
      {
        goto LABEL_69;
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v25 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v25, "ipa-wan %s:%d Receiving egress default ioctl again", "ipa_setup_prod_pipes", 2323);
      }
      v5 = 0;
      *((_DWORD *)v7 - 6) = 2;
      goto LABEL_4;
    }
    if ( *((_DWORD *)v7 - 6) == 2 )
      goto LABEL_84;
    if ( (unsigned int)ipa_get_ep_mapping(34) == -1 )
    {
      printk(&unk_3CDD4E, "ipa3_setup_apps_wan_prod_pipes");
      if ( ipa3_get_ipc_logbuf() )
      {
        v45 = ipa3_get_ipc_logbuf();
        ipc_log_string(v45, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_setup_apps_wan_prod_pipes", 2210);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
      {
LABEL_84:
        v5 = 0;
        goto LABEL_4;
      }
      v46 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v46, "ipa-wan %s:%d Embedded datapath not supported\n", "ipa3_setup_apps_wan_prod_pipes", 2210);
      goto LABEL_146;
    }
    if ( v6 - 20 > 0x60 )
      goto LABEL_188;
    if ( *(_DWORD *)((char *)&egress_param + v6 - 20) )
    {
      v30 = rmnet_ipa3_ctx;
      v31 = rmnet_ipa3_ctx + 8;
      if ( (*(_BYTE *)(a1 + 184) & 0x12) != 0 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v32 = ipa3_get_ipc_logbuf();
          ipc_log_string(v32, "ipa-wan %s:%d UL Chksum set\n", "ipa3_setup_apps_wan_prod_pipes", 2223);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v33 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v33, "ipa-wan %s:%d UL Chksum set\n", "ipa3_setup_apps_wan_prod_pipes", 2223);
        }
        *(_DWORD *)(v30 + 20) = 8;
        *(_DWORD *)(v30 + 160) = 1;
        *(_BYTE *)(v30 + 164) = 1;
        if ( v6 - 12 > 0x60 )
          goto LABEL_188;
        if ( *(_DWORD *)((char *)&egress_param + v6 - 12) && (*(_DWORD *)(a1 + 184) & 0x1D0001) != 0 )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v34 = ipa3_get_ipc_logbuf();
            ipc_log_string(v34, "ipa-wan %s:%d ULSO set\n", "ipa3_setup_apps_wan_prod_pipes", 2231);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v35 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v35, "ipa-wan %s:%d ULSO set\n", "ipa3_setup_apps_wan_prod_pipes", 2231);
          }
          if ( v6 - 8 > 0x60 )
            goto LABEL_188;
          v36 = *(_DWORD *)((char *)&egress_param + v6 - 8);
          *(_BYTE *)(v30 + 188) = 1;
          *(_DWORD *)(v30 + 184) = v36;
        }
        goto LABEL_118;
      }
    }
    else
    {
      if ( v6 - 12 > 0x60 )
        goto LABEL_188;
      if ( *(_DWORD *)((char *)&egress_param + v6 - 12) )
      {
        printk(&unk_3F9441, "ipa3_setup_apps_wan_prod_pipes");
        if ( ipa3_get_ipc_logbuf() )
        {
          v53 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v53,
            "ipa-wan %s:%d ULSO enabled but cs_offload not enabled\n",
            "ipa3_setup_apps_wan_prod_pipes",
            2216);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v54 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v54,
            "ipa-wan %s:%d ULSO enabled but cs_offload not enabled\n",
            "ipa3_setup_apps_wan_prod_pipes",
            2216);
        }
        if ( (unsigned __int64)(v3 * 8 + 4) > 0x18 )
          goto LABEL_188;
        v5 = 0;
        HIDWORD(egress_pipe_status[v3]) = 1;
        goto LABEL_4;
      }
      v30 = rmnet_ipa3_ctx;
      v31 = rmnet_ipa3_ctx + 8;
    }
    *(_DWORD *)(v30 + 160) = 0;
    *(_DWORD *)(v30 + 20) = 4;
LABEL_118:
    if ( v6 - 16 > 0x60 )
      goto LABEL_188;
    if ( *(_DWORD *)((char *)&egress_param + v6 - 16) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v39 = ipa3_get_ipc_logbuf();
        ipc_log_string(v39, "ipa-wan %s:%d WAN UL Aggr enabled\n", "ipa3_setup_apps_wan_prod_pipes", 2243);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v40 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v40, "ipa-wan %s:%d WAN UL Aggr enabled\n", "ipa3_setup_apps_wan_prod_pipes", 2243);
      }
      *(_BYTE *)(v30 + 137) = 0;
      *(_WORD *)(v30 + 72) = 1;
      *(_QWORD *)(v30 + 104) = 0x600000002LL;
      *(_DWORD *)(v30 + 40) = 2;
      *(_DWORD *)(v30 + 68) = 0;
      *(_QWORD *)(v30 + 56) = 2;
      *(_BYTE *)(v30 + 64) = 1;
    }
    else
    {
      printk(&unk_3EA7DA, "ipa3_setup_apps_wan_prod_pipes");
      if ( ipa3_get_ipc_logbuf() )
      {
        v47 = ipa3_get_ipc_logbuf();
        ipc_log_string(v47, "ipa-wan %s:%d WAN UL Aggregation disabled\n", "ipa3_setup_apps_wan_prod_pipes", 2259);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v48 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v48, "ipa-wan %s:%d WAN UL Aggregation disabled\n", "ipa3_setup_apps_wan_prod_pipes", 2259);
      }
      *(_DWORD *)(v30 + 104) = 0;
    }
    *(_QWORD *)(v30 + 24) = 1;
    *(_QWORD *)(v30 + 96) = 0x2200000000LL;
    *(_BYTE *)(v30 + 256) = 1;
    *(_QWORD *)(v30 + 200) = 0x100000000022LL;
    *(_QWORD *)(v30 + 208) = a1;
    *(_QWORD *)(v30 + 216) = apps_ipa_tx_complete_notify;
    if ( v6 - 4 > 0x60 )
      goto LABEL_188;
    *(_DWORD *)(v30 + 244) = *(_DWORD *)((char *)&egress_param + v6 - 4);
    if ( v6 > 0x60 )
      goto LABEL_188;
    v41 = rmnet_ipa3_ctx;
    *(_DWORD *)(v30 + 248) = *(_DWORD *)((char *)&egress_param + v6);
    if ( *(_DWORD *)(v41 + 1056) )
    {
      printk(&unk_3E78B5, "ipa3_setup_apps_wan_prod_pipes");
      if ( ipa3_get_ipc_logbuf() )
      {
        v49 = ipa3_get_ipc_logbuf();
        ipc_log_string(v49, "ipa-wan %s:%d In SSR sequence/recovery\n", "ipa3_setup_apps_wan_prod_pipes", 2277);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_84;
      v50 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v50, "ipa-wan %s:%d In SSR sequence/recovery\n", "ipa3_setup_apps_wan_prod_pipes", 2277);
LABEL_146:
      v5 = 0;
      goto LABEL_4;
    }
    LODWORD(egress_pipe_status[v3]) = 0;
    v42 = ipa_setup_sys_pipe(v31, (unsigned int *)(v41 + 1080));
    if ( !v42 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v43 = ipa3_get_ipc_logbuf();
        ipc_log_string(v43, "ipa-wan %s:%d Egress WAN pipe setup successful\n", "ipa3_setup_apps_wan_prod_pipes", 2292);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v44 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v44, "ipa-wan %s:%d Egress WAN pipe setup successful\n", "ipa3_setup_apps_wan_prod_pipes", 2292);
      }
LABEL_81:
      *((_DWORD *)v7 - 6) = 0;
      if ( (unsigned __int64)(v3 * 8 + 4) > 0x18 )
        goto LABEL_188;
      v5 = 0;
      HIDWORD(egress_pipe_status[v3]) = 2;
      goto LABEL_4;
    }
    v5 = v42;
    printk(&unk_3CDDA2, "ipa3_setup_apps_wan_prod_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v51 = ipa3_get_ipc_logbuf();
      ipc_log_string(v51, "ipa-wan %s:%d failed to setup egress default pipe\n", "ipa3_setup_apps_wan_prod_pipes", 2287);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v52 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v52, "ipa-wan %s:%d failed to setup egress default pipe\n", "ipa3_setup_apps_wan_prod_pipes", 2287);
    }
    if ( (unsigned __int64)(v3 * 8 + 4) > 0x18 )
      goto LABEL_188;
    HIDWORD(egress_pipe_status[v3]) = 1;
    if ( v5 == -14 )
    {
      if ( !(unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs_317, "ipa_setup_prod_pipes") )
        goto LABEL_183;
      goto LABEL_189;
    }
LABEL_4:
    ++v4;
    ++v3;
    v6 += 32LL;
  }
  while ( v4 < HIDWORD(qword_2017A8) );
  if ( (v76 & 1) == 0 )
    goto LABEL_178;
  v55 = 32LL * HIDWORD(qword_2017A8);
  if ( HIDWORD(qword_2017A8) >= 4 )
  {
    _copy_overflow(96, 32LL * HIDWORD(qword_2017A8));
    goto LABEL_171;
  }
LABEL_165:
  v56 = egress_ioctl_v2_data;
  _check_object_size(&egress_param, v55, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v58 = v56, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v58 = v56 & (v56 << 8 >> 8);
  if ( 0x8000000000LL - v55 >= v58 )
  {
    v59 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v65 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v65 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v65);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v59);
    v55 = _arch_copy_to_user(v56 & 0xFF7FFFFFFFFFFFFFLL, &egress_param, v55);
    v66 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v68 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v68 - 4096);
    _WriteStatusReg(TTBR1_EL1, v68);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v66);
  }
  if ( !v55 )
  {
LABEL_178:
    prod_pipes_setup_complete = 1;
    mutex_unlock(rmnet_ipa3_ctx + 1088);
    *(_BYTE *)(rmnet_ipa3_ctx + 1048) = 1;
    return v5;
  }
LABEL_171:
  if ( (unsigned int)__ratelimit(&ipa_setup_prod_pipes__rs_336, "ipa_setup_prod_pipes") )
  {
    printk(&unk_3D6CBF, "ipa_setup_prod_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
LABEL_173:
      v69 = ipa3_get_ipc_logbuf();
      ipc_log_string(v69, "ipa-wan %s:%d Egress copy to user failed\n", "ipa_setup_prod_pipes", 2410);
    }
  }
  else if ( ipa3_get_ipc_logbuf() )
  {
    goto LABEL_173;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v70 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v70, "ipa-wan %s:%d Egress copy to user failed\n", "ipa_setup_prod_pipes", 2410);
  }
  v71 = rmnet_ipa3_ctx;
LABEL_177:
  mutex_unlock(v71 + 1088);
  return (unsigned int)-14;
}
