__int64 __fastcall ipa3_enable_wdi3_pipes(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v5; // w19
  unsigned int v6; // w22
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x27
  __int64 v15; // x26
  unsigned int v16; // w9
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x23
  int v22; // w0
  __int64 v23; // x23
  int v24; // w0
  __int64 v25; // x23
  int v26; // w0
  __int64 v27; // x23
  int v28; // w0
  __int64 v29; // x23
  unsigned int v30; // w0
  unsigned int v31; // w0
  __int64 v32; // x27
  _QWORD *v33; // x27
  __int64 v34; // t1
  unsigned int started; // w0
  unsigned int v36; // w22
  unsigned int v37; // w9
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 result; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x8
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
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int128 v70; // [xsp+18h] [xbp-18h] BYREF
  __int64 v71; // [xsp+28h] [xbp-8h]

  v5 = a1;
  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0u;
  v6 = *(_DWORD *)(ipa3_ctx + 34920);
  if ( (int)ipa_get_wdi_version(a1) <= 1 )
  {
    printk(&unk_3F0090, "ipa3_enable_wdi3_pipes");
    v38 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v39 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v39 )
      {
        ipc_log_string(v39, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_enable_wdi3_pipes", 1136);
        v38 = ipa3_ctx;
      }
      v40 = *(_QWORD *)(v38 + 34160);
      if ( v40 )
        ipc_log_string(v40, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_enable_wdi3_pipes", 1136);
    }
    __break(0x800u);
    result = 4294967282LL;
    goto LABEL_115;
  }
  v7 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d ep_tx = %d\n", "ipa3_enable_wdi3_pipes", 1141, v5);
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d ep_tx = %d\n", "ipa3_enable_wdi3_pipes", 1141, v5);
      v7 = ipa3_ctx;
    }
    if ( v7 )
    {
      v10 = *(_QWORD *)(v7 + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d ep_rx = %d\n", "ipa3_enable_wdi3_pipes", 1142, a2);
        v7 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v7 + 34160);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d ep_rx = %d\n", "ipa3_enable_wdi3_pipes", 1142, a2);
        v7 = ipa3_ctx;
      }
      if ( v7 )
      {
        v12 = *(_QWORD *)(v7 + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d ep_tx1 = %d\n", "ipa3_enable_wdi3_pipes", 1143, a3);
          v7 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v7 + 34160);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d ep_tx1 = %d\n", "ipa3_enable_wdi3_pipes", 1143, a3);
          v7 = ipa3_ctx;
        }
      }
    }
  }
  if ( v5 >= 0x25 || a2 > 0x24 )
    goto LABEL_122;
  v14 = v7 + 168;
  if ( (a3 & 0x80000000) == 0 )
  {
    if ( a3 <= 0x24 )
    {
      v15 = v14 + 480LL * a3;
      goto LABEL_23;
    }
LABEL_122:
    __break(0x5512u);
  }
  v15 = 0;
LABEL_23:
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
  ipa3_inc_client_enable_clks();
  v16 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( v16 < 0x11 || v16 == 23 )
  {
LABEL_30:
    v17 = ipa3_enable_data_path(a2);
    if ( v17 )
    {
      v36 = v17;
      printk(&unk_3D29EB, "ipa3_enable_wdi3_pipes");
      v42 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v43 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v43 )
        {
          ipc_log_string(
            v43,
            "ipa %s:%d enable data path failed res=%d clnt=%d\n",
            "ipa3_enable_wdi3_pipes",
            1170,
            v36,
            a2);
          v42 = ipa3_ctx;
        }
        v44 = *(_QWORD *)(v42 + 34160);
        if ( v44 )
          ipc_log_string(
            v44,
            "ipa %s:%d enable data path failed res=%d clnt=%d\n",
            "ipa3_enable_wdi3_pipes",
            1170,
            v36,
            a2);
      }
      goto LABEL_112;
    }
    if ( *(_BYTE *)(ipa3_ctx + 32267) != 1 || !*(_DWORD *)(ipa3_ctx + 33060) )
    {
      v18 = ipa3_enable_data_path(v5);
      if ( v18 )
      {
        v36 = v18;
        printk(&unk_3D29EB, "ipa3_enable_wdi3_pipes");
        v55 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v56 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v56 )
          {
            ipc_log_string(
              v56,
              "ipa %s:%d enable data path failed res=%d clnt=%d\n",
              "ipa3_enable_wdi3_pipes",
              1179,
              v36,
              v5);
            v55 = ipa3_ctx;
          }
          v57 = *(_QWORD *)(v55 + 34160);
          if ( v57 )
            ipc_log_string(
              v57,
              "ipa %s:%d enable data path failed res=%d clnt=%d\n",
              "ipa3_enable_wdi3_pipes",
              1179,
              v36,
              v5);
        }
        goto LABEL_111;
      }
    }
    if ( (a3 & 0x80000000) == 0 )
    {
      v19 = ipa3_enable_data_path(a3);
      if ( v19 )
      {
        v36 = v19;
        printk(&unk_3D29EB, "ipa3_enable_wdi3_pipes");
        v61 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v62 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v62 )
          {
            ipc_log_string(
              v62,
              "ipa %s:%d enable data path failed res=%d clnt=%d\n",
              "ipa3_enable_wdi3_pipes",
              1189,
              v36,
              a3);
            v61 = ipa3_ctx;
          }
          v63 = *(_QWORD *)(v61 + 34160);
          if ( v63 )
            ipc_log_string(
              v63,
              "ipa %s:%d enable data path failed res=%d clnt=%d\n",
              "ipa3_enable_wdi3_pipes",
              1189,
              v36,
              a3);
        }
LABEL_110:
        ipa3_disable_data_path(v5);
LABEL_111:
        ipa3_disable_data_path(a2);
LABEL_112:
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
        ipa3_dec_client_disable_clks();
        result = v36;
        goto LABEL_115;
      }
      v20 = ipa3_ctx;
      *(_QWORD *)((char *)&v70 + 4) = 0;
      HIDWORD(v70) = 1;
      LODWORD(v70) = *(_DWORD *)(ipa3_ctx + 50148);
      if ( ipa3_ctx )
      {
        v21 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v21 )
        {
          v22 = ipa3_cfg_ep_holb(v5, &v70);
          ipc_log_string(v21, "ipa %s:%d Configuring HOLB TO on tx return = %d\n", "ipa3_enable_wdi3_pipes", 1196, v22);
          v20 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v20 + 34160);
        if ( v23 )
        {
          v24 = ipa3_cfg_ep_holb(v5, &v70);
          ipc_log_string(v23, "ipa %s:%d Configuring HOLB TO on tx return = %d\n", "ipa3_enable_wdi3_pipes", 1196, v24);
          v20 = ipa3_ctx;
        }
        LODWORD(v70) = *(_DWORD *)(v20 + 50144);
        if ( v20 )
        {
          v25 = *(_QWORD *)(v20 + 34152);
          if ( v25 )
          {
            v26 = ipa3_cfg_ep_holb(a3, &v70);
            ipc_log_string(
              v25,
              "ipa %s:%d Configuring HOLB TO on tx1 return = %d\n",
              "ipa3_enable_wdi3_pipes",
              1199,
              v26);
            v20 = ipa3_ctx;
          }
          v27 = *(_QWORD *)(v20 + 34160);
          if ( v27 )
          {
            v28 = ipa3_cfg_ep_holb(a3, &v70);
            ipc_log_string(
              v27,
              "ipa %s:%d Configuring HOLB TO on tx1 return = %d\n",
              "ipa3_enable_wdi3_pipes",
              1199,
              v28);
          }
        }
      }
      else
      {
        LODWORD(v70) = dword_C3E0;
      }
    }
    v29 = v14 + 480LL * v5;
    if ( *(_BYTE *)(ipa3_ctx + 32267) == 1 && *(_DWORD *)(ipa3_ctx + 33060)
      || (v30 = gsi_start_channel(*(_QWORD *)(v29 + 8))) == 0 )
    {
      if ( (a3 & 0x80000000) == 0 && (v31 = gsi_start_channel(*(_QWORD *)(v15 + 8))) != 0 )
      {
        v36 = v31;
        printk(&unk_3FEE8A, "ipa3_enable_wdi3_pipes");
        v64 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v65 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v65 )
          {
            ipc_log_string(v65, "ipa %s:%d failed to start gsi tx1 channel\n", "ipa3_enable_wdi3_pipes", 1216);
            v64 = ipa3_ctx;
          }
          v66 = *(_QWORD *)(v64 + 34160);
          if ( v66 )
            ipc_log_string(v66, "ipa %s:%d failed to start gsi tx1 channel\n", "ipa3_enable_wdi3_pipes", 1216);
        }
      }
      else
      {
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))ipa3_uc_client_add_holb_monitor)(
                             *(unsigned __int16 *)(v29 + 8),
                             3,
                             v6,
                             0) )
        {
          printk(&unk_3C68A9, "ipa3_enable_wdi3_pipes");
          v49 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v50 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v50 )
            {
              ipc_log_string(
                v50,
                "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
                "ipa3_enable_wdi3_pipes",
                1226,
                *(_QWORD *)(v29 + 8));
              v49 = ipa3_ctx;
            }
            v51 = *(_QWORD *)(v49 + 34160);
            if ( v51 )
              ipc_log_string(
                v51,
                "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
                "ipa3_enable_wdi3_pipes",
                1226,
                *(_QWORD *)(v29 + 8));
          }
        }
        v32 = v14 + 480LL * a2;
        v34 = *(_QWORD *)(v32 + 8);
        v33 = (_QWORD *)(v32 + 8);
        started = gsi_start_channel(v34);
        if ( !started )
        {
          ipa3_check_wdi_opt_chn_empty(a2);
          v36 = 0;
          v37 = *(_DWORD *)(ipa3_ctx + 32240);
          if ( v37 >= 0x11 && v37 != 23 )
          {
            *(_BYTE *)(ipa3_ctx + 45293) = *v33;
            *(_BYTE *)(ipa3_ctx + 45292) = 1;
            *(_BYTE *)(ipa3_ctx + 45295) = *(_QWORD *)(v29 + 8);
            *(_BYTE *)(ipa3_ctx + 45294) = 0;
            if ( (a3 & 0x80000000) == 0 )
            {
              *(_BYTE *)(ipa3_ctx + 45297) = *(_QWORD *)(v15 + 8);
              *(_BYTE *)(ipa3_ctx + 45296) = 0;
            }
            ipa3_uc_debug_stats_alloc(
              *(_QWORD *)(ipa3_ctx + 45288),
              *(unsigned int *)(ipa3_ctx + 45296) | ((unsigned __int64)*(unsigned __int16 *)(ipa3_ctx + 45300) << 32));
            v36 = 0;
          }
          goto LABEL_112;
        }
        v36 = started;
        printk(&unk_3B32BA, "ipa3_enable_wdi3_pipes");
        v52 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v53 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v53 )
          {
            ipc_log_string(v53, "ipa %s:%d failed to start gsi rx channel\n", "ipa3_enable_wdi3_pipes", 1231);
            v52 = ipa3_ctx;
          }
          v54 = *(_QWORD *)(v52 + 34160);
          if ( v54 )
            ipc_log_string(v54, "ipa %s:%d failed to start gsi rx channel\n", "ipa3_enable_wdi3_pipes", 1231);
        }
        if ( (a3 & 0x80000000) == 0 )
          gsi_stop_channel(*(_QWORD *)(v15 + 8));
      }
      gsi_stop_channel(*(_QWORD *)(v29 + 8));
    }
    else
    {
      v36 = v30;
      printk(&unk_3DB57A, "ipa3_enable_wdi3_pipes");
      v58 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v59 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v59 )
        {
          ipc_log_string(v59, "ipa %s:%d failed to start gsi tx channel\n", "ipa3_enable_wdi3_pipes", 1207);
          v58 = ipa3_ctx;
        }
        v60 = *(_QWORD *)(v58 + 34160);
        if ( v60 )
          ipc_log_string(v60, "ipa %s:%d failed to start gsi tx channel\n", "ipa3_enable_wdi3_pipes", 1207);
      }
    }
    if ( (a3 & 0x80000000) == 0 )
      ipa3_disable_data_path(a3);
    goto LABEL_110;
  }
  if ( *(_BYTE *)(ipa3_ctx + 34657) != 1 || (*(_BYTE *)(ipa3_ctx + 34856) & 1) != 0 )
  {
    printk(&unk_3E74D4, "ipa3_enable_wdi3_pipes");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(
          v46,
          "ipa %s:%d uc-loaded %d, ring-valid %d\n",
          "ipa3_enable_wdi3_pipes",
          1163,
          *(unsigned __int8 *)(ipa3_ctx + 34657),
          *(unsigned __int8 *)(ipa3_ctx + 34856));
        v45 = ipa3_ctx;
      }
      v47 = v45 + 0x8000;
      v48 = *(_QWORD *)(v47 + 1392);
      if ( v48 )
        ipc_log_string(
          v48,
          "ipa %s:%d uc-loaded %d, ring-valid %d\n",
          "ipa3_enable_wdi3_pipes",
          1163,
          *(unsigned __int8 *)(v47 + 1889),
          *(unsigned __int8 *)(v47 + 2088));
    }
    goto LABEL_30;
  }
  if ( !(unsigned int)ipa3_uc_setup_event_ring() )
    goto LABEL_30;
  printk(&unk_3AAAFA, "ipa3_enable_wdi3_pipes");
  v67 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v68 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v68 )
    {
      ipc_log_string(v68, "ipa %s:%d failed to set uc_event ring\n", "ipa3_enable_wdi3_pipes", 1157);
      v67 = ipa3_ctx;
    }
    v69 = *(_QWORD *)(v67 + 34160);
    if ( v69 )
      ipc_log_string(v69, "ipa %s:%d failed to set uc_event ring\n", "ipa3_enable_wdi3_pipes", 1157);
  }
  result = 4294967282LL;
LABEL_115:
  _ReadStatusReg(SP_EL0);
  return result;
}
