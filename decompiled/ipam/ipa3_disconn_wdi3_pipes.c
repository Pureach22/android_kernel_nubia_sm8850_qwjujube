__int64 __fastcall ipa3_disconn_wdi3_pipes(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v5; // w19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int max_num_pipes; // w0
  __int64 v14; // x26
  int v15; // w22
  int v16; // w23
  __int64 v17; // x27
  unsigned int v18; // w0
  __int64 v19; // x27
  unsigned int v20; // w0
  unsigned int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w0
  __int64 v26; // x26
  unsigned int v27; // w0
  unsigned int v28; // w0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  unsigned int v33; // w0
  unsigned int v34; // w0
  unsigned int v35; // w0
  __int64 v36; // x0
  unsigned int v37; // w8
  long double v38; // q0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned int v42; // w20
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 result; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // [xsp+18h] [xbp-18h] BYREF
  __int64 v78; // [xsp+20h] [xbp-10h]
  __int64 v79; // [xsp+28h] [xbp-8h]

  v5 = a1;
  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  v78 = 0;
  if ( (int)ipa_get_wdi_version(a1) <= 1 )
  {
    printk(&unk_3F0090, "ipa3_disconn_wdi3_pipes");
    v47 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v48 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v48 )
      {
        ipc_log_string(v48, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_disconn_wdi3_pipes", 1011);
        v47 = ipa3_ctx;
      }
      v49 = *(_QWORD *)(v47 + 34160);
      if ( v49 )
        ipc_log_string(v49, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_disconn_wdi3_pipes", 1011);
    }
    __break(0x800u);
    result = 4294967282LL;
  }
  else
  {
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d ep_tx = %d\n", "ipa3_disconn_wdi3_pipes", 1016, v5);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d ep_tx = %d\n", "ipa3_disconn_wdi3_pipes", 1016, v5);
        v6 = ipa3_ctx;
      }
      if ( v6 )
      {
        v9 = *(_QWORD *)(v6 + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d ep_rx = %d\n", "ipa3_disconn_wdi3_pipes", 1017, a2);
          v6 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v6 + 34160);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d ep_rx = %d\n", "ipa3_disconn_wdi3_pipes", 1017, a2);
          v6 = ipa3_ctx;
        }
        if ( v6 )
        {
          v11 = *(_QWORD *)(v6 + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d ep_tx1 = %d\n", "ipa3_disconn_wdi3_pipes", 1018, a3);
            v6 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v6 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d ep_tx1 = %d\n", "ipa3_disconn_wdi3_pipes", 1018, a3);
        }
      }
    }
    if ( (v5 & 0x80000000) == 0 )
    {
      max_num_pipes = ipa3_get_max_num_pipes();
      if ( (a2 & 0x80000000) == 0 && max_num_pipes > v5 && (unsigned int)ipa3_get_max_num_pipes() > a2 )
      {
        if ( v5 < 0x25 && a2 <= 0x24 )
        {
          v14 = ipa3_ctx;
          v15 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
          v16 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
          ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5) <= 0x85 )
            ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v5);
          ipa3_inc_client_enable_clks();
          if ( (a3 & 0x80000000) != 0 )
            goto LABEL_35;
          if ( a3 <= 0x24 )
          {
            v17 = ipa3_ctx;
            v18 = ipa3_reset_gsi_channel((_QWORD *)a3);
            if ( v18 )
            {
              v42 = v18;
              printk(&unk_3C0CD0, "ipa3_disconn_wdi3_pipes");
              v68 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v69 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v69 )
                {
                  v38 = ipc_log_string(
                          v69,
                          "ipa %s:%d failed to reset gsi channel: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1038,
                          v42);
                  v68 = ipa3_ctx;
                }
                v70 = *(_QWORD *)(v68 + 34160);
                if ( v70 )
                  v38 = ipc_log_string(
                          v70,
                          "ipa %s:%d failed to reset gsi channel: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1038,
                          v42);
              }
              goto LABEL_124;
            }
            v19 = v17 + 480LL * a3;
            v20 = gsi_reset_evt_ring(*(_QWORD *)(v19 + 184));
            if ( v20 )
            {
              v42 = v20;
              printk(&unk_3D85C0, "ipa3_disconn_wdi3_pipes");
              v71 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v72 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v72 )
                {
                  v38 = ipc_log_string(
                          v72,
                          "ipa %s:%d failed to reset evt ring: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1043,
                          v42);
                  v71 = ipa3_ctx;
                }
                v73 = *(_QWORD *)(v71 + 34160);
                if ( v73 )
                  v38 = ipc_log_string(
                          v73,
                          "ipa %s:%d failed to reset evt ring: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1043,
                          v42);
              }
              goto LABEL_124;
            }
            v21 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(a3);
            if ( v21 )
            {
              v42 = v21;
              printk(&unk_3E6530, "ipa3_disconn_wdi3_pipes");
              v74 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v75 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v75 )
                {
                  v38 = ipc_log_string(
                          v75,
                          "ipa %s:%d failed to release gsi channel: %d\n",
                          "ipa3_disconn_wdi3_pipes",
                          1048,
                          v42);
                  v74 = ipa3_ctx;
                }
                v76 = *(_QWORD *)(v74 + 34160);
                if ( v76 )
                  v38 = ipc_log_string(
                          v76,
                          "ipa %s:%d failed to release gsi channel: %d\n",
                          "ipa3_disconn_wdi3_pipes",
                          1048,
                          v42);
              }
              goto LABEL_124;
            }
            ((void (__fastcall *)(__int64))ipa3_release_wdi3_gsi_smmu_mappings)(2);
            memset((void *)(v19 + 168), 0, 0x1E0u);
            v22 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v23 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v23 )
              {
                ipc_log_string(v23, "ipa %s:%d tx client (ep: %d) disconnected\n", "ipa3_disconn_wdi3_pipes", 1054, a3);
                v22 = ipa3_ctx;
              }
              v24 = *(_QWORD *)(v22 + 34160);
              if ( v24 )
                ipc_log_string(v24, "ipa %s:%d tx client (ep: %d) disconnected\n", "ipa3_disconn_wdi3_pipes", 1054, a3);
            }
LABEL_35:
            v25 = ipa3_reset_gsi_channel((_QWORD *)v5);
            if ( v25 )
            {
              v42 = v25;
              printk(&unk_3C0CD0, "ipa3_disconn_wdi3_pipes");
              v50 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v51 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v51 )
                {
                  v38 = ipc_log_string(
                          v51,
                          "ipa %s:%d failed to reset gsi channel: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1059,
                          v42);
                  v50 = ipa3_ctx;
                }
                v52 = *(_QWORD *)(v50 + 34160);
                if ( v52 )
                  v38 = ipc_log_string(
                          v52,
                          "ipa %s:%d failed to reset gsi channel: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1059,
                          v42);
              }
              goto LABEL_124;
            }
            v26 = v14 + 168;
            v27 = gsi_reset_evt_ring(*(_QWORD *)(v26 + 480LL * v5 + 16));
            if ( v27 )
            {
              v42 = v27;
              printk(&unk_3D85C0, "ipa3_disconn_wdi3_pipes");
              v53 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v54 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v54 )
                {
                  v38 = ipc_log_string(
                          v54,
                          "ipa %s:%d failed to reset evt ring: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1064,
                          v42);
                  v53 = ipa3_ctx;
                }
                v55 = *(_QWORD *)(v53 + 34160);
                if ( v55 )
                  v38 = ipc_log_string(
                          v55,
                          "ipa %s:%d failed to reset evt ring: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1064,
                          v42);
              }
              goto LABEL_124;
            }
            v28 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(v5);
            if ( v28 )
            {
              v42 = v28;
              printk(&unk_3E6530, "ipa3_disconn_wdi3_pipes");
              v56 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v57 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v57 )
                {
                  v38 = ipc_log_string(
                          v57,
                          "ipa %s:%d failed to release gsi channel: %d\n",
                          "ipa3_disconn_wdi3_pipes",
                          1069,
                          v42);
                  v56 = ipa3_ctx;
                }
                v58 = *(_QWORD *)(v56 + 34160);
                if ( v58 )
                  v38 = ipc_log_string(
                          v58,
                          "ipa %s:%d failed to release gsi channel: %d\n",
                          "ipa3_disconn_wdi3_pipes",
                          1069,
                          v42);
              }
              goto LABEL_124;
            }
            if ( v16 == 13 )
              v29 = 1;
            else
              v29 = 4;
            ((void (__fastcall *)(__int64))ipa3_release_wdi3_gsi_smmu_mappings)(v29);
            memset((void *)(v26 + 480LL * v5), 0, 0x1E0u);
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v31 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v31 )
              {
                ipc_log_string(v31, "ipa %s:%d tx client (ep: %d) disconnected\n", "ipa3_disconn_wdi3_pipes", 1078, v5);
                v30 = ipa3_ctx;
              }
              v32 = *(_QWORD *)(v30 + 34160);
              if ( v32 )
              {
                ipc_log_string(v32, "ipa %s:%d tx client (ep: %d) disconnected\n", "ipa3_disconn_wdi3_pipes", 1078, v5);
                v30 = ipa3_ctx;
              }
            }
            if ( *(_BYTE *)(v30 + 32267) == 1
              && (((__int64 (__fastcall *)(_QWORD))ipa_wdi_opt_dpath_ctrl_enabled)(0) & 1) != 0 )
            {
              ((void (__fastcall *)(_QWORD))ipa3_delete_dl_opt_wdi_dpath_flt_rules)(a2);
            }
            v33 = ipa3_reset_gsi_channel((_QWORD *)a2);
            if ( v33 )
            {
              v42 = v33;
              printk(&unk_3C0CD0, "ipa3_disconn_wdi3_pipes");
              v59 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v60 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v60 )
                {
                  v38 = ipc_log_string(
                          v60,
                          "ipa %s:%d failed to reset gsi channel: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1087,
                          v42);
                  v59 = ipa3_ctx;
                }
                v61 = *(_QWORD *)(v59 + 34160);
                if ( v61 )
                  v38 = ipc_log_string(
                          v61,
                          "ipa %s:%d failed to reset gsi channel: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1087,
                          v42);
              }
              goto LABEL_124;
            }
            v34 = gsi_reset_evt_ring(*(_QWORD *)(v26 + 480LL * a2 + 16));
            if ( v34 )
            {
              v42 = v34;
              printk(&unk_3D85C0, "ipa3_disconn_wdi3_pipes");
              v62 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v63 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v63 )
                {
                  v38 = ipc_log_string(
                          v63,
                          "ipa %s:%d failed to reset evt ring: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1092,
                          v42);
                  v62 = ipa3_ctx;
                }
                v64 = *(_QWORD *)(v62 + 34160);
                if ( v64 )
                  v38 = ipc_log_string(
                          v64,
                          "ipa %s:%d failed to reset evt ring: %d.\n",
                          "ipa3_disconn_wdi3_pipes",
                          1092,
                          v42);
              }
              goto LABEL_124;
            }
            v35 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(a2);
            if ( v35 )
            {
              v42 = v35;
              printk(&unk_3E6530, "ipa3_disconn_wdi3_pipes");
              v65 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v66 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v66 )
                {
                  v38 = ipc_log_string(
                          v66,
                          "ipa %s:%d failed to release gsi channel: %d\n",
                          "ipa3_disconn_wdi3_pipes",
                          1097,
                          v42);
                  v65 = ipa3_ctx;
                }
                v67 = *(_QWORD *)(v65 + 34160);
                if ( v67 )
                  v38 = ipc_log_string(
                          v67,
                          "ipa %s:%d failed to release gsi channel: %d\n",
                          "ipa3_disconn_wdi3_pipes",
                          1097,
                          v42);
              }
              goto LABEL_124;
            }
            if ( v15 == 12 )
              v36 = 3;
            else
              v36 = 5;
            ((void (__fastcall *)(__int64))ipa3_release_wdi3_gsi_smmu_mappings)(v36);
            v37 = *(_DWORD *)(ipa3_ctx + 32240);
            if ( v37 >= 0x11 && v37 != 23 )
              ipa3_uc_debug_stats_dealloc(4);
            ((void (__fastcall *)(_QWORD))ipa3_delete_dflt_flt_rules)(a2);
            memset((void *)(v26 + 480LL * a2), 0, 0x1E0u);
            v39 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v40 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v40 )
              {
                v38 = ipc_log_string(
                        v40,
                        "ipa %s:%d rx client (ep: %d) disconnected\n",
                        "ipa3_disconn_wdi3_pipes",
                        1110,
                        a2);
                v39 = ipa3_ctx;
              }
              v41 = *(_QWORD *)(v39 + 34160);
              if ( v41 )
              {
                v38 = ipc_log_string(
                        v41,
                        "ipa %s:%d rx client (ep: %d) disconnected\n",
                        "ipa3_disconn_wdi3_pipes",
                        1110,
                        a2);
                v39 = ipa3_ctx;
              }
            }
            if ( *(_BYTE *)(v39 + 32267) == 1 )
            {
              v42 = 0;
              if ( (((__int64 (__fastcall *)(_QWORD))ipa_wdi_opt_dpath_ctrl_enabled)(0) & 1) == 0 )
              {
LABEL_124:
                ((void (__fastcall *)(_QWORD, long double))ipa3_get_client_by_pipe)(v5, v38);
                if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v5) <= 0x85 )
                  ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v5);
                ipa3_dec_client_disable_clks();
                result = v42;
                goto LABEL_127;
              }
              v77 = 0;
              v78 = 0;
              ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req((__int64)&v77, nullptr);
            }
            v42 = 0;
            goto LABEL_124;
          }
        }
        __break(0x5512u);
      }
    }
    printk(&unk_3D92B3, "ipa3_disconn_wdi3_pipes");
    v43 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_72;
    v44 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d invalid ipa ep index\n", "ipa3_disconn_wdi3_pipes", 1023);
      v43 = ipa3_ctx;
    }
    v45 = *(_QWORD *)(v43 + 34160);
    if ( v45 )
    {
      ipc_log_string(v45, "ipa %s:%d invalid ipa ep index\n", "ipa3_disconn_wdi3_pipes", 1023);
      result = 4294967274LL;
    }
    else
    {
LABEL_72:
      result = 4294967274LL;
    }
  }
LABEL_127:
  _ReadStatusReg(SP_EL0);
  return result;
}
