__int64 __fastcall ipa3_eth_disconnect(__int64 a1, unsigned int a2)
{
  unsigned int prot; // w0
  signed int ep_mapping; // w0
  unsigned int v6; // w20
  __int64 v7; // x22
  int v8; // w0
  int v9; // w26
  unsigned int v10; // w9
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x27
  unsigned int v14; // w22
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  long double v18; // q0
  long double v19; // q1
  long double v20; // q2
  long double v21; // q3
  float v22; // s4
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w8
  unsigned int v27; // w20
  unsigned int *v28; // x8
  unsigned int v29; // w9
  unsigned __int64 v30; // x10
  __int64 v31; // x8
  char *v32; // x10
  char *v33; // x9
  char v34; // w8
  unsigned int *v35; // x10
  unsigned int v36; // w9
  unsigned __int64 v37; // x10
  unsigned int inited; // w0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned int v42; // w19
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 result; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  int v50; // w21
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  unsigned int v70; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v71; // [xsp+28h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  prot = ipa3_eth_get_prot(a1, (int *)&v70);
  if ( prot )
  {
    v42 = prot;
    printk(&unk_3D5926, "ipa3_eth_disconnect");
    v43 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_90;
    v44 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d Could not determine protocol\n", "ipa3_eth_disconnect", 1308);
      v43 = ipa3_ctx;
    }
    v45 = *(_QWORD *)(v43 + 34160);
    if ( v45 )
    {
      ipc_log_string(v45, "ipa %s:%d Could not determine protocol\n", "ipa3_eth_disconnect", 1308);
      result = v42;
    }
    else
    {
LABEL_90:
      result = v42;
    }
  }
  else
  {
    ipa3_inc_client_enable_clks();
    ep_mapping = ipa_get_ep_mapping(a2);
    if ( ep_mapping == -1 || (v6 = ep_mapping, ep_mapping >= 31) )
    {
      printk(&unk_3FDEC5, "ipa3_eth_disconnect");
      v47 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v48 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v48 )
        {
          ipc_log_string(v48, "ipa %s:%d undefined client_type\n", "ipa3_eth_disconnect", 1315);
          v47 = ipa3_ctx;
        }
        v49 = *(_QWORD *)(v47 + 34160);
        if ( v49 )
          ipc_log_string(v49, "ipa %s:%d undefined client_type\n", "ipa3_eth_disconnect", 1315);
      }
    }
    else
    {
      if ( (unsigned int)ep_mapping >= 0x25 )
        goto LABEL_96;
      v7 = ipa3_ctx;
      v8 = ipa3_disable_data_path(ep_mapping);
      if ( !v8 )
      {
        v9 = *(_DWORD *)(a1 + 16);
        v10 = *(_DWORD *)(ipa3_ctx + 32240);
        if ( v10 >= 0x11 && v10 != 23 )
        {
          if ( v70 > 0xA )
            goto LABEL_96;
          v11 = 14LL * v70;
          v12 = 2LL * (v9 == 0);
          *(_BYTE *)(ipa3_ctx + v11 + v12 + 45237) = -1;
          *(_BYTE *)(ipa3_ctx + v11 + v12 + 45236) = *(_DWORD *)(a1 + 16);
          ipa3_uc_debug_stats_alloc(
            *(_QWORD *)(ipa3_ctx + 45232 + v11),
            *(unsigned int *)(ipa3_ctx + 45232 + v11 + 8)
          | ((unsigned __int64)*(unsigned __int16 *)(ipa3_ctx + 45232 + v11 + 12) << 32));
        }
        if ( (unsigned int)ipa_stop_gsi_channel(v6) )
        {
          v54 = printk(&unk_3E96F2, "ipa3_eth_disconnect");
          v55 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v56 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v56 )
            {
              ipc_log_string(v56, "ipa %s:%d failed to stop gsi channel %d\n", "ipa3_eth_disconnect", 1342, v6);
              v55 = ipa3_ctx;
            }
            v54 = *(_QWORD *)(v55 + 34160);
            if ( v54 )
              v54 = ipc_log_string(v54, "ipa %s:%d failed to stop gsi channel %d\n", "ipa3_eth_disconnect", 1342, v6);
          }
          ((void (__fastcall *)(__int64))ipa_assert)(v54);
          v27 = -14;
          goto LABEL_83;
        }
        v13 = v7 + 480LL * v6;
        v14 = v70;
        if ( *(_DWORD *)(ipa3_ctx + 32240) == 17 || v70 == 9 )
        {
          if ( (unsigned int)ipa3_eth_config_uc(0, v70, *(_DWORD *)(a1 + 16) == 0, *(_BYTE *)(v13 + 176), 0) )
          {
            printk(&unk_3C3E43, "ipa3_eth_disconnect");
            v67 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v68 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v68 )
              {
                ipc_log_string(v68, "ipa %s:%d failed to config uc\n", "ipa3_eth_disconnect", 1356);
                v67 = ipa3_ctx;
              }
              v69 = *(_QWORD *)(v67 + 34160);
              if ( v69 )
                ipc_log_string(v69, "ipa %s:%d failed to config uc\n", "ipa3_eth_disconnect", 1356);
            }
          }
        }
        v15 = ipa3_reset_gsi_channel((_QWORD *)v6);
        if ( v15 )
        {
          v27 = v15;
          v57 = printk(&unk_3C0CD0, "ipa3_eth_disconnect");
          v58 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v59 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v59 )
            {
              ipc_log_string(v59, "ipa %s:%d failed to reset gsi channel: %d.\n", "ipa3_eth_disconnect", 1362, v27);
              v58 = ipa3_ctx;
            }
            v57 = *(_QWORD *)(v58 + 34160);
            if ( v57 )
              v57 = ipc_log_string(
                      v57,
                      "ipa %s:%d failed to reset gsi channel: %d.\n",
                      "ipa3_eth_disconnect",
                      1362,
                      v27);
          }
        }
        else
        {
          v16 = gsi_reset_evt_ring(*(_QWORD *)(v13 + 184));
          if ( v16 )
          {
            v27 = v16;
            v57 = printk(&unk_3D85C0, "ipa3_eth_disconnect");
            v60 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v61 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v61 )
              {
                ipc_log_string(v61, "ipa %s:%d failed to reset evt ring: %d.\n", "ipa3_eth_disconnect", 1368, v27);
                v60 = ipa3_ctx;
              }
              v57 = *(_QWORD *)(v60 + 34160);
              if ( v57 )
                v57 = ipc_log_string(v57, "ipa %s:%d failed to reset evt ring: %d.\n", "ipa3_eth_disconnect", 1368, v27);
            }
          }
          else
          {
            v17 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(v6);
            if ( !v17 )
            {
              memset((void *)(v13 + 168), 0, 0x1E0u);
              v23 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v24 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v24 )
                {
                  ipc_log_string(v24, "ipa %s:%d client (ep: %d) disconnected\n", "ipa3_eth_disconnect", 1379, v6);
                  v23 = ipa3_ctx;
                }
                v25 = *(_QWORD *)(v23 + 34160);
                if ( v25 )
                {
                  ipc_log_string(v25, "ipa %s:%d client (ep: %d) disconnected\n", "ipa3_eth_disconnect", 1379, v6);
                  v23 = ipa3_ctx;
                }
              }
              v26 = *(_DWORD *)(v23 + 32240);
              if ( v26 >= 0x11 && v26 != 23 )
                ipa3_uc_debug_stats_dealloc(v14);
              if ( a2 <= 0x85 && (a2 & 1) == 0 )
                v18 = ((long double (__fastcall *)(_QWORD))ipa3_delete_dflt_flt_rules)(v6);
              v27 = ipa3_smmu_map_eth_pipes(a1, a2, 0, v18, v19, v20, v21, v22);
              if ( v27 )
              {
                printk(&unk_3BDF5B, "ipa3_eth_disconnect");
                v64 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v65 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v65 )
                  {
                    ipc_log_string(v65, "ipa %s:%d failed to unmap SMMU %d\n", "ipa3_eth_disconnect", 1388, v27);
                    v64 = ipa3_ctx;
                  }
                  v66 = *(_QWORD *)(v64 + 34160);
                  if ( v66 )
                    ipc_log_string(v66, "ipa %s:%d failed to unmap SMMU %d\n", "ipa3_eth_disconnect", 1388, v27);
                }
              }
              v28 = *(unsigned int **)(a1 + 160);
              v29 = *v28;
              if ( *v28 < 6 )
              {
                v30 = *((unsigned __int8 *)v28 + 4);
                if ( v30 <= 2 )
                {
                  v31 = ipa3_ctx;
                  v32 = (char *)(ipa3_ctx + 208LL * v29 + 104LL * (unsigned int)v30 + 48880);
                  v33 = &v32[20 * (v9 == 0)];
                  if ( v33[20] == 1 )
                  {
                    v34 = *v32;
                    *(_QWORD *)(v33 + 4) = 0;
                    *(_QWORD *)(v33 + 12) = 0;
                    v33[20] = 0;
                    *v32 = v34 - 1;
                    v31 = ipa3_ctx;
                  }
                  if ( *(_DWORD *)(v31 + 32240) != 17 || v14 != 1 )
                    goto LABEL_83;
                  v35 = *(unsigned int **)(a1 + 160);
                  v36 = *v35;
                  if ( *v35 <= 5 )
                  {
                    v37 = *((unsigned __int8 *)v35 + 4);
                    if ( v37 <= 2 )
                    {
                      if ( !*(_BYTE *)(v31 + 208LL * v36 + 104LL * (unsigned int)v37 + 48880) )
                      {
                        inited = ipa3_eth_uc_init_peripheral(0, 0);
                        v27 = 0;
                        if ( inited )
                        {
                          v27 = inited;
                          printk(&unk_3C9AD4, "ipa3_eth_disconnect");
                          v39 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v40 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v40 )
                            {
                              ipc_log_string(
                                v40,
                                "ipa %s:%d failed to de-init peripheral %d\n",
                                "ipa3_eth_disconnect",
                                1404,
                                v27);
                              v39 = ipa3_ctx;
                            }
                            v41 = *(_QWORD *)(v39 + 34160);
                            if ( v41 )
                              ipc_log_string(
                                v41,
                                "ipa %s:%d failed to de-init peripheral %d\n",
                                "ipa3_eth_disconnect",
                                1404,
                                v27);
                          }
                        }
                      }
                      goto LABEL_83;
                    }
                  }
                }
              }
LABEL_96:
              __break(0x5512u);
            }
            v27 = v17;
            v57 = printk(&unk_3E6530, "ipa3_eth_disconnect");
            v62 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v63 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v63 )
              {
                ipc_log_string(v63, "ipa %s:%d failed to release gsi channel: %d\n", "ipa3_eth_disconnect", 1374, v27);
                v62 = ipa3_ctx;
              }
              v57 = *(_QWORD *)(v62 + 34160);
              if ( v57 )
                v57 = ipc_log_string(
                        v57,
                        "ipa %s:%d failed to release gsi channel: %d\n",
                        "ipa3_eth_disconnect",
                        1374,
                        v27);
            }
          }
        }
        ((void (__fastcall *)(__int64))ipa_assert)(v57);
LABEL_83:
        ipa3_dec_client_disable_clks();
        result = v27;
        goto LABEL_84;
      }
      v50 = v8;
      printk(&unk_3B48C2, "ipa3_eth_disconnect");
      v51 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v52 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v52 )
        {
          ipc_log_string(
            v52,
            "ipa %s:%d enable data path failed res=%d clnt=%d.\n",
            "ipa3_eth_disconnect",
            1324,
            v50,
            v6);
          v51 = ipa3_ctx;
        }
        v53 = *(_QWORD *)(v51 + 34160);
        if ( v53 )
          ipc_log_string(
            v53,
            "ipa %s:%d enable data path failed res=%d clnt=%d.\n",
            "ipa3_eth_disconnect",
            1324,
            v50,
            v6);
      }
    }
    ipa3_dec_client_disable_clks();
    result = 4294967282LL;
  }
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return result;
}
