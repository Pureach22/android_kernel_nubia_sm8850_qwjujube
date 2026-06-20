__int64 __fastcall ipa3_request_gsi_channel(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int ep_mapping; // w0
  unsigned int v9; // w22
  __int64 v10; // x19
  _DWORD *v11; // x19
  int v12; // t1
  char v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w23
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w0
  __int64 v29; // x23
  int v30; // w0
  int v31; // w0
  __int64 v32; // x0
  __int64 v33; // x24
  int v34; // w0
  __int64 v35; // x8
  __int64 v36; // x9
  char *v37; // x9
  __int64 v38; // x0
  __int64 v39; // x10
  unsigned int v40; // w0
  unsigned int channel_db_addr; // w0
  char v42; // w9
  unsigned int v43; // w8
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  int v64; // w19
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  int v68; // w20
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  int v75; // w21
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  unsigned int v79; // w20
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  unsigned int v83; // w20
  __int64 v84; // x8
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x0
  __int64 v96; // x0
  const char *v97; // [xsp+8h] [xbp-28h] BYREF
  char *v98; // [xsp+10h] [xbp-20h]
  __int64 v99; // [xsp+18h] [xbp-18h]
  int v100; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v101; // [xsp+28h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ipa3_ctx;
  v100 = 0;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d entry\n", "ipa3_request_gsi_channel", 600);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d entry\n", "ipa3_request_gsi_channel", 600);
  }
  if ( !a1 || !a2 || (v7 = *(unsigned int *)(a1 + 192), (unsigned int)v7 >= 0x86) )
  {
    printk(&unk_3C95AE, "ipa3_request_gsi_channel");
    v49 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v50 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d bad parameters\n", "ipa3_request_gsi_channel", 603);
        v49 = ipa3_ctx;
      }
      v51 = *(_QWORD *)(v49 + 34160);
      if ( v51 )
        ipc_log_string(v51, "ipa %s:%d bad parameters\n", "ipa3_request_gsi_channel", 603);
    }
    goto LABEL_92;
  }
  ep_mapping = ipa_get_ep_mapping(v7);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3F4B4C, "ipa3_request_gsi_channel");
    v52 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v53 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v53 )
      {
        ipc_log_string(v53, "ipa %s:%d fail to alloc EP.\n", "ipa3_request_gsi_channel", 609);
        v52 = ipa3_ctx;
      }
      v54 = *(_QWORD *)(v52 + 34160);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d fail to alloc EP.\n", "ipa3_request_gsi_channel", 609);
LABEL_85:
        v15 = -14;
        goto LABEL_132;
      }
    }
LABEL_86:
    v15 = -14;
    goto LABEL_132;
  }
  v9 = ep_mapping;
  if ( ep_mapping >= 0x25 )
    goto LABEL_149;
  v10 = ipa3_ctx + 480LL * (int)ep_mapping;
  v12 = *(_DWORD *)(v10 + 168);
  v11 = (_DWORD *)(v10 + 168);
  if ( v12 )
  {
    printk(&unk_3F4B6B, "ipa3_request_gsi_channel");
    v55 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v56 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v56 )
      {
        ipc_log_string(v56, "ipa %s:%d EP already allocated.\n", "ipa3_request_gsi_channel", 616);
        v55 = ipa3_ctx;
      }
      v57 = *(_QWORD *)(v55 + 34160);
      if ( v57 )
      {
        ipc_log_string(v57, "ipa %s:%d EP already allocated.\n", "ipa3_request_gsi_channel", 616);
        goto LABEL_85;
      }
    }
    goto LABEL_86;
  }
  memset(v11, 0, 0x1E0u);
  v97 = "ipa3_request_gsi_channel";
  v98 = "ipa_client.c";
  v99 = 0x10000026DLL;
  ipa3_inc_client_enable_clks();
  v13 = *(_BYTE *)(a1 + 216);
  *v11 = 1;
  *((_BYTE *)v11 + 404) = v13;
  v14 = *(_DWORD *)(a1 + 192);
  v11[1] = v14;
  *((_QWORD *)v11 + 47) = *(_QWORD *)(a1 + 208);
  *((_QWORD *)v11 + 46) = *(_QWORD *)(a1 + 200);
  *((_BYTE *)v11 + 405) = *(_BYTE *)(a1 + 217);
  if ( v14 <= 0x85 && (v14 & 1) == 0 )
  {
    v15 = -14;
    if ( (v13 & 1) != 0 )
    {
LABEL_15:
      v16 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v17 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v17 )
        {
          ipc_log_string(v17, "ipa %s:%d Skipping endpoint configuration.\n", "ipa3_request_gsi_channel", 659);
          v16 = ipa3_ctx;
        }
        v18 = *(_QWORD *)(v16 + 34160);
        if ( v18 )
          ipc_log_string(v18, "ipa %s:%d Skipping endpoint configuration.\n", "ipa3_request_gsi_channel", 659);
      }
      if ( v9 == 36 )
        goto LABEL_149;
      if ( *(_DWORD *)(ipa3_ctx + 480LL * (int)v9 + 172) == 18 && (unsigned int)ipa3_cfg_ep_seq(v9, a1 + 168) )
      {
        printk(&unk_3D2432, "ipa3_request_gsi_channel");
        v19 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v20 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v20 )
          {
            ipc_log_string(v20, "ipa %s:%d fail to configure USB pipe seq\n", "ipa3_request_gsi_channel", 665);
            v19 = ipa3_ctx;
          }
          v21 = *(_QWORD *)(v19 + 34160);
          if ( v21 )
            ipc_log_string(v21, "ipa %s:%d fail to configure USB pipe seq\n", "ipa3_request_gsi_channel", 665);
        }
        goto LABEL_131;
      }
LABEL_45:
      *a2 = v9;
      v28 = ipa3_enable_data_path(v9);
      if ( v28 )
      {
        v15 = v28;
        printk(&unk_3B48C2, "ipa3_request_gsi_channel");
        v61 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v62 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v62 )
          {
            ipc_log_string(
              v62,
              "ipa %s:%d enable data path failed res=%d clnt=%d.\n",
              "ipa3_request_gsi_channel",
              676,
              v15,
              *a2);
            v61 = ipa3_ctx;
          }
          v63 = *(_QWORD *)(v61 + 34160);
          if ( v63 )
            ipc_log_string(
              v63,
              "ipa %s:%d enable data path failed res=%d clnt=%d.\n",
              "ipa3_request_gsi_channel",
              676,
              v15,
              *a2);
        }
        goto LABEL_131;
      }
      v29 = *(_QWORD *)(ipa3_ctx + 43296);
      v30 = gsi_alloc_evt_ring(a1 + 224, v29, v11 + 4);
      if ( v30 )
      {
        v64 = v30;
        printk(&unk_3C95F6, "ipa3_request_gsi_channel");
        v65 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v66 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v66 )
          {
            ipc_log_string(v66, "ipa %s:%d Error allocating event ring: %d\n", "ipa3_request_gsi_channel", 684, v64);
            v65 = ipa3_ctx;
          }
          v67 = *(_QWORD *)(v65 + 34160);
          if ( v67 )
            ipc_log_string(v67, "ipa %s:%d Error allocating event ring: %d\n", "ipa3_request_gsi_channel", 684, v64);
        }
      }
      else
      {
        v31 = gsi_write_evt_ring_scratch(*((_QWORD *)v11 + 2), *(_QWORD *)(a1 + 352));
        if ( v31 )
        {
          v68 = v31;
          printk(&unk_3EE9AF, "ipa3_request_gsi_channel");
          v69 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v70 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v70 )
            {
              ipc_log_string(
                v70,
                "ipa %s:%d Error writing event ring scratch: %d\n",
                "ipa3_request_gsi_channel",
                692,
                v68);
              v69 = ipa3_ctx;
            }
            v71 = *(_QWORD *)(v69 + 34160);
            if ( v71 )
              ipc_log_string(
                v71,
                "ipa %s:%d Error writing event ring scratch: %d\n",
                "ipa3_request_gsi_channel",
                692,
                v68);
          }
        }
        else
        {
          v32 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)((unsigned int)v11[1]);
          if ( v32 )
          {
            v33 = v32;
            *(_QWORD *)(a1 + 376) = *((_QWORD *)v11 + 2);
            *(_BYTE *)(a1 + 368) = *(_DWORD *)(v32 + 4);
            *(_DWORD *)(a1 + 436) = *(_DWORD *)(v32 + 20);
            *(_BYTE *)(a1 + 440) = *(_BYTE *)(v32 + 24);
            v34 = gsi_alloc_channel(a1 + 360, v29, v11 + 2);
            if ( v34 )
            {
              v75 = v34;
              printk(&unk_3E5EF8, "ipa3_request_gsi_channel");
              v76 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v77 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v77 )
                {
                  ipc_log_string(
                    v77,
                    "ipa %s:%d Error allocating channel: %d, chan_id: %d\n",
                    "ipa3_request_gsi_channel",
                    713,
                    v75,
                    *(unsigned __int8 *)(a1 + 368));
                  v76 = ipa3_ctx;
                }
                v78 = *(_QWORD *)(v76 + 34160);
                if ( v78 )
                  ipc_log_string(
                    v78,
                    "ipa %s:%d Error allocating channel: %d, chan_id: %d\n",
                    "ipa3_request_gsi_channel",
                    713,
                    v75,
                    *(unsigned __int8 *)(a1 + 368));
              }
            }
            else
            {
              v36 = *(_QWORD *)(a1 + 488);
              v35 = *(_QWORD *)(a1 + 496);
              *((_QWORD *)v11 + 11) = *(_QWORD *)(a1 + 480);
              *((_QWORD *)v11 + 12) = v36;
              *((_QWORD *)v11 + 13) = v35;
              if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
                *((_WORD *)v11 + 49) = *(_WORD *)(a1 + 384) * *(_DWORD *)(v33 + 8);
              v37 = *(char **)(a1 + 488);
              v38 = *((_QWORD *)v11 + 1);
              v39 = *(_QWORD *)(a1 + 496);
              v97 = *(const char **)(a1 + 480);
              v98 = v37;
              v99 = v39;
              v40 = gsi_write_channel_scratch(v38, &v97);
              if ( v40 )
              {
                v79 = v40;
                printk(&unk_3D5370, "ipa3_request_gsi_channel");
                v80 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v81 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v81 )
                  {
                    ipc_log_string(
                      v81,
                      "ipa %s:%d Error writing channel scratch: %d\n",
                      "ipa3_request_gsi_channel",
                      735,
                      v79);
                    v80 = ipa3_ctx;
                  }
                  v82 = *(_QWORD *)(v80 + 34160);
                  if ( v82 )
                    ipc_log_string(
                      v82,
                      "ipa %s:%d Error writing channel scratch: %d\n",
                      "ipa3_request_gsi_channel",
                      735,
                      v79);
                }
              }
              else
              {
                channel_db_addr = gsi_query_channel_db_addr(*((_QWORD *)v11 + 1), a2 + 1, a2 + 2);
                if ( !channel_db_addr )
                {
                  v11[6] = *(_DWORD *)(a1 + 236);
                  *((_QWORD *)v11 + 4) = *(_QWORD *)(a1 + 240);
                  *((_QWORD *)v11 + 5) = *(_QWORD *)(a1 + 248);
                  v11[12] = *(_DWORD *)(a1 + 388);
                  *((_QWORD *)v11 + 7) = *(_QWORD *)(a1 + 400);
                  *((_QWORD *)v11 + 8) = *(_QWORD *)(a1 + 416);
                  if ( v9 != 36 )
                  {
                    v42 = *((_BYTE *)v11 + 404);
                    *(_BYTE *)(ipa3_ctx + (int)v9 + 17448) = v42;
                    if ( (v42 & 1) == 0 )
                    {
                      v43 = *(_DWORD *)(a1 + 192);
                      if ( v43 <= 0x85 && (v43 & 1) == 0 )
                        ipa3_install_dflt_flt_rules(v9);
                    }
                    v97 = "ipa3_request_gsi_channel";
                    v98 = "ipa_client.c";
                    v99 = 0x1000002FDLL;
                    ipa3_dec_client_disable_clks();
                    v44 = ipa3_ctx;
                    if ( ipa3_ctx )
                    {
                      v45 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v45 )
                      {
                        ipc_log_string(
                          v45,
                          "ipa %s:%d client %d (ep: %d) connected\n",
                          "ipa3_request_gsi_channel",
                          767,
                          *(_DWORD *)(a1 + 192),
                          v9);
                        v44 = ipa3_ctx;
                      }
                      v46 = *(_QWORD *)(v44 + 34160);
                      if ( v46 )
                      {
                        ipc_log_string(
                          v46,
                          "ipa %s:%d client %d (ep: %d) connected\n",
                          "ipa3_request_gsi_channel",
                          767,
                          *(_DWORD *)(a1 + 192),
                          v9);
                        v44 = ipa3_ctx;
                      }
                      if ( v44 )
                      {
                        v47 = *(_QWORD *)(v44 + 34152);
                        if ( v47 )
                        {
                          ipc_log_string(v47, "ipa %s:%d exit\n", "ipa3_request_gsi_channel", 768);
                          v44 = ipa3_ctx;
                        }
                        v48 = *(_QWORD *)(v44 + 34160);
                        if ( v48 )
                          ipc_log_string(v48, "ipa %s:%d exit\n", "ipa3_request_gsi_channel", 768);
                      }
                    }
                    v15 = 0;
                    goto LABEL_132;
                  }
LABEL_149:
                  __break(0x5512u);
                }
                v83 = channel_db_addr;
                printk(&unk_3D245E, "ipa3_request_gsi_channel");
                v84 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v85 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v85 )
                  {
                    ipc_log_string(
                      v85,
                      "ipa %s:%d Error querying channel DB registers addresses: %d\n",
                      "ipa3_request_gsi_channel",
                      745,
                      v83);
                    v84 = ipa3_ctx;
                  }
                  v86 = *(_QWORD *)(v84 + 34160);
                  if ( v86 )
                    ipc_log_string(
                      v86,
                      "ipa %s:%d Error querying channel DB registers addresses: %d\n",
                      "ipa3_request_gsi_channel",
                      745,
                      v83);
                }
              }
              gsi_dealloc_channel(*((_QWORD *)v11 + 1));
            }
          }
          else
          {
            printk(&unk_3A2DC4, "ipa3_request_gsi_channel");
            v72 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v73 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v73 )
              {
                ipc_log_string(v73, "ipa %s:%d Error ipa_get_gsi_ep_info ret NULL\n", "ipa3_request_gsi_channel", 699);
                v72 = ipa3_ctx;
              }
              v74 = *(_QWORD *)(v72 + 34160);
              if ( v74 )
                ipc_log_string(v74, "ipa %s:%d Error ipa_get_gsi_ep_info ret NULL\n", "ipa3_request_gsi_channel", 699);
            }
          }
        }
        gsi_dealloc_evt_ring(*((_QWORD *)v11 + 2));
      }
      v15 = -14;
LABEL_131:
      memset((void *)(ipa3_ctx + 480LL * (int)v9 + 168), 0, 0x1E0u);
      v97 = "ipa3_request_gsi_channel";
      v98 = "ipa_client.c";
      v99 = 0x10000030ALL;
      ipa3_dec_client_disable_clks();
      goto LABEL_132;
    }
LABEL_38:
    if ( (unsigned int)ipa3_cfg_ep(v9, a1) )
    {
      printk(&unk_3D5322, "ipa3_request_gsi_channel");
      v88 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v89 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v89 )
        {
          ipc_log_string(v89, "ipa %s:%d fail to configure EP.\n", "ipa3_request_gsi_channel", 648);
          v88 = ipa3_ctx;
        }
        v90 = *(_QWORD *)(v88 + 34160);
        if ( v90 )
          ipc_log_string(v90, "ipa %s:%d fail to configure EP.\n", "ipa3_request_gsi_channel", 648);
      }
      goto LABEL_131;
    }
    v100 = 0;
    if ( (unsigned int)ipa3_cfg_ep_status(v9, &v100) )
    {
      printk(&unk_3A6426, "ipa3_request_gsi_channel");
      v94 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v95 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v95 )
        {
          ipc_log_string(v95, "ipa %s:%d fail to configure status of EP.\n", "ipa3_request_gsi_channel", 654);
          v94 = ipa3_ctx;
        }
        v96 = *(_QWORD *)(v94 + 34160);
        if ( v96 )
          ipc_log_string(v96, "ipa %s:%d fail to configure status of EP.\n", "ipa3_request_gsi_channel", 654);
      }
      goto LABEL_131;
    }
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d ep configuration successful\n", "ipa3_request_gsi_channel", 657);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d ep configuration successful\n", "ipa3_request_gsi_channel", 657);
    }
    goto LABEL_45;
  }
  v22 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v23 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v23 )
    {
      ipc_log_string(v23, "ipa %s:%d Configuring QMB on USB CONS pipe\n", "ipa3_request_gsi_channel", 633);
      v22 = ipa3_ctx;
    }
    v24 = *(_QWORD *)(v22 + 34160);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d Configuring QMB on USB CONS pipe\n", "ipa3_request_gsi_channel", 633);
      v22 = ipa3_ctx;
    }
  }
  if ( v9 >= *(_DWORD *)(v22 + 34308) )
    goto LABEL_87;
  if ( v9 == 36 )
    goto LABEL_149;
  if ( !*(_DWORD *)(v22 + 480LL * (int)v9 + 168) )
  {
LABEL_87:
    printk(&unk_3F1C1D, "ipa3_request_gsi_channel");
    v58 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v59 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v59 )
      {
        ipc_log_string(v59, "ipa %s:%d bad parm.\n", "ipa3_request_gsi_channel", 636);
        v58 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v58 + 34160);
      if ( v60 )
        ipc_log_string(v60, "ipa %s:%d bad parm.\n", "ipa3_request_gsi_channel", 636);
    }
LABEL_92:
    v15 = -22;
    goto LABEL_132;
  }
  v15 = ipa3_cfg_ep_cfg(v9, a1 + 148);
  if ( !v15 )
  {
    if ( (v11[101] & 1) != 0 )
      goto LABEL_15;
    goto LABEL_38;
  }
  printk(&unk_3EBE91, "ipa3_request_gsi_channel");
  v91 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v92 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v92 )
    {
      ipc_log_string(v92, "ipa %s:%d fail to configure QMB.\n", "ipa3_request_gsi_channel", 641);
      v91 = ipa3_ctx;
    }
    v93 = *(_QWORD *)(v91 + 34160);
    if ( v93 )
      ipc_log_string(v93, "ipa %s:%d fail to configure QMB.\n", "ipa3_request_gsi_channel", 641);
  }
LABEL_132:
  _ReadStatusReg(SP_EL0);
  return v15;
}
