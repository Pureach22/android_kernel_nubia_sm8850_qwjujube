__int64 __fastcall ipa3_disconn_wigig_pipe_i(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int ep_mapping; // w19
  __int64 v10; // x16
  __int64 v11; // x21
  _DWORD *v12; // x21
  int v13; // t1
  __int64 v14; // x0
  __int64 v15; // x24
  unsigned int v16; // w0
  int v17; // w0
  long double v18; // q0
  long double v19; // q1
  long double v20; // q2
  long double v21; // q3
  float v22; // s4
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 result; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  unsigned int v43; // w19
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  int v47; // w24
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0

  _ReadStatusReg(SP_EL0);
  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d \n", "ipa3_disconn_wigig_pipe_i", 1405);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d \n", "ipa3_disconn_wigig_pipe_i", 1405);
  }
  ep_mapping = ipa_get_ep_mapping(a1);
  if ( ep_mapping == -1 || ep_mapping >= (unsigned int)ipa3_get_max_num_pipes() )
  {
    printk(&unk_3CD9BE, "ipa3_disconn_wigig_pipe_i");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d fail to get ep (%d) %d.\n", "ipa3_disconn_wigig_pipe_i", 1411, a1, ep_mapping);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d fail to get ep (%d) %d.\n", "ipa3_disconn_wigig_pipe_i", 1411, a1, ep_mapping);
LABEL_59:
        result = 4294967282LL;
        goto LABEL_86;
      }
    }
LABEL_60:
    result = 4294967282LL;
    goto LABEL_86;
  }
  if ( ep_mapping < 0x25 )
  {
    v11 = ipa3_ctx + 480LL * ep_mapping;
    v13 = *(_DWORD *)(v11 + 168);
    v12 = (_DWORD *)(v11 + 168);
    if ( v13 )
    {
      v14 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(a1);
      if ( v14 )
      {
        if ( v12[113] == 1 )
        {
          v15 = v14;
          ipa3_inc_client_enable_clks();
          v16 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(ep_mapping);
          if ( v16 )
          {
            v43 = v16;
            printk(&unk_3C50C9, "ipa3_disconn_wigig_pipe_i");
            v44 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v45 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v45 )
              {
                ipc_log_string(v45, "ipa %s:%d failed to deallocate channel\n", "ipa3_disconn_wigig_pipe_i", 1442);
                v44 = ipa3_ctx;
              }
              v46 = *(_QWORD *)(v44 + 34160);
              if ( v46 )
                ipc_log_string(v46, "ipa %s:%d failed to deallocate channel\n", "ipa3_disconn_wigig_pipe_i", 1442);
            }
          }
          else
          {
            v17 = ipa3_wigig_config_uc(0, a1 == 86, 0, *(_DWORD *)(v15 + 4), 0);
            if ( v17 )
            {
              v47 = v17;
              printk(&unk_3ADBF0, "ipa3_disconn_wigig_pipe_i");
              v48 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v49 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v49 )
                {
                  v18 = ipc_log_string(
                          v49,
                          "ipa %s:%d failed uC channel teardown %d\n",
                          "ipa3_disconn_wigig_pipe_i",
                          1451,
                          v47);
                  v48 = ipa3_ctx;
                }
                v50 = *(_QWORD *)(v48 + 34160);
                if ( v50 )
                  v18 = ipc_log_string(
                          v50,
                          "ipa %s:%d failed uC channel teardown %d\n",
                          "ipa3_disconn_wigig_pipe_i",
                          1451,
                          v47);
              }
              __break(0x800u);
            }
            if ( (*(_BYTE *)(ipa3_ctx + 43314) & 1) != 0 )
            {
              if ( !(a2 | a3) )
                goto LABEL_28;
              printk(&unk_3CD9E3, "ipa3_disconn_wigig_pipe_i");
              v23 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v24 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v24 )
                {
                  ipc_log_string(
                    v24,
                    "ipa %s:%d smmu input is not null %pK %pK\n",
                    "ipa3_disconn_wigig_pipe_i",
                    1488,
                    (const void *)a2,
                    (const void *)a3);
                  v23 = ipa3_ctx;
                }
                v25 = *(_QWORD *)(v23 + 34160);
                if ( v25 )
                  ipc_log_string(
                    v25,
                    "ipa %s:%d smmu input is not null %pK %pK\n",
                    "ipa3_disconn_wigig_pipe_i",
                    1488,
                    (const void *)a2,
                    (const void *)a3);
              }
              goto LABEL_21;
            }
            if ( !a2 || !a3 )
            {
              printk(&unk_3CA94C, "ipa3_disconn_wigig_pipe_i");
              v51 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v52 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v52 )
                {
                  ipc_log_string(
                    v52,
                    "ipa %s:%d smmu input is null %pK %pK\n",
                    "ipa3_disconn_wigig_pipe_i",
                    1459,
                    (const void *)a2,
                    (const void *)a3);
                  v51 = ipa3_ctx;
                }
                v53 = *(_QWORD *)(v51 + 34160);
                if ( v53 )
                  ipc_log_string(
                    v53,
                    "ipa %s:%d smmu input is null %pK %pK\n",
                    "ipa3_disconn_wigig_pipe_i",
                    1459,
                    (const void *)a2,
                    (const void *)a3);
              }
              __break(0x800u);
              if ( a1 != 86 )
                goto LABEL_28;
LABEL_26:
              if ( smmu_reg_addr_list != (_UNKNOWN *)&smmu_reg_addr_list )
              {
                printk(&unk_3B90CC, "ipa3_disconn_wigig_pipe_i");
                v57 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v58 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v58 )
                  {
                    ipc_log_string(v58, "ipa %s:%d smmu_reg_addr_list not empty\n", "ipa3_disconn_wigig_pipe_i", 1477);
                    v57 = ipa3_ctx;
                  }
                  v59 = *(_QWORD *)(v57 + 34160);
                  if ( v59 )
                    ipc_log_string(v59, "ipa %s:%d smmu_reg_addr_list not empty\n", "ipa3_disconn_wigig_pipe_i", 1477);
                }
                __break(0x800u);
              }
              if ( smmu_ring_addr_list == (_UNKNOWN *)&smmu_ring_addr_list )
                goto LABEL_28;
              printk(&unk_3BC20A, "ipa3_disconn_wigig_pipe_i");
              v60 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v61 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v61 )
                {
                  ipc_log_string(v61, "ipa %s:%d smmu_ring_addr_list not empty\n", "ipa3_disconn_wigig_pipe_i", 1482);
                  v60 = ipa3_ctx;
                }
                v62 = *(_QWORD *)(v60 + 34160);
                if ( v62 )
                  ipc_log_string(v62, "ipa %s:%d smmu_ring_addr_list not empty\n", "ipa3_disconn_wigig_pipe_i", 1482);
              }
LABEL_21:
              __break(0x800u);
              goto LABEL_28;
            }
            if ( !(unsigned int)ipa3_wigig_smmu_map_channel(a1 == 86, a2, a3, 0, v18, v19, v20, v21, v22) )
            {
              if ( a1 != 86 )
              {
LABEL_28:
                memset(v12, 0, 0x1E0u);
                ipa3_dec_client_disable_clks();
                v26 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v27 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v27 )
                  {
                    ipc_log_string(
                      v27,
                      "ipa %s:%d client (ep: %d) disconnected\n",
                      "ipa3_disconn_wigig_pipe_i",
                      1498,
                      ep_mapping);
                    v26 = ipa3_ctx;
                  }
                  v28 = *(_QWORD *)(v26 + 34160);
                  if ( v28 )
                  {
                    ipc_log_string(
                      v28,
                      "ipa %s:%d client (ep: %d) disconnected\n",
                      "ipa3_disconn_wigig_pipe_i",
                      1498,
                      ep_mapping);
                    v26 = ipa3_ctx;
                  }
                  if ( v26 )
                  {
                    v29 = *(_QWORD *)(v26 + 34152);
                    if ( v29 )
                    {
                      ipc_log_string(v29, "ipa %s:%d exit\n", "ipa3_disconn_wigig_pipe_i", 1500);
                      v26 = ipa3_ctx;
                    }
                    result = *(_QWORD *)(v26 + 34160);
                    if ( !result )
                      goto LABEL_86;
                    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_disconn_wigig_pipe_i", 1500);
                  }
                }
                result = 0;
LABEL_86:
                _ReadStatusReg(SP_EL0);
                return result;
              }
              goto LABEL_26;
            }
            printk(&unk_3D6A50, "ipa3_disconn_wigig_pipe_i");
            v54 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v55 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v55 )
              {
                ipc_log_string(
                  v55,
                  "ipa %s:%d failed to unmap pipe smmu %d (ep %d)\n",
                  "ipa3_disconn_wigig_pipe_i",
                  1469,
                  a1,
                  ep_mapping);
                v54 = ipa3_ctx;
              }
              v56 = *(_QWORD *)(v54 + 34160);
              if ( v56 )
                ipc_log_string(
                  v56,
                  "ipa %s:%d failed to unmap pipe smmu %d (ep %d)\n",
                  "ipa3_disconn_wigig_pipe_i",
                  1469,
                  a1,
                  ep_mapping);
            }
            v43 = -14;
          }
          ipa3_dec_client_disable_clks();
          result = v43;
          goto LABEL_86;
        }
        printk(&unk_3D935D, "ipa3_disconn_wigig_pipe_i");
        v40 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v41 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v41 )
          {
            ipc_log_string(
              v41,
              "ipa %s:%d client in bad state(client %d) 0x%X\n",
              "ipa3_disconn_wigig_pipe_i",
              1430,
              a1,
              v12[113]);
            v40 = ipa3_ctx;
          }
          v42 = *(_QWORD *)(v40 + 34160);
          if ( v42 )
          {
            ipc_log_string(
              v42,
              "ipa %s:%d client in bad state(client %d) 0x%X\n",
              "ipa3_disconn_wigig_pipe_i",
              1430,
              a1,
              (unsigned int)v12[113]);
            goto LABEL_59;
          }
        }
      }
      else
      {
        printk(&unk_3CC819, "ipa3_disconn_wigig_pipe_i");
        v37 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v38 )
          {
            ipc_log_string(
              v38,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_disconn_wigig_pipe_i",
              1424,
              a1);
            v37 = ipa3_ctx;
          }
          v39 = *(_QWORD *)(v37 + 34160);
          if ( v39 )
          {
            ipc_log_string(
              v39,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_disconn_wigig_pipe_i",
              1424,
              a1);
            result = 4294967282LL;
            goto LABEL_86;
          }
        }
      }
    }
    else
    {
      printk(&unk_3DC47E, "ipa3_disconn_wigig_pipe_i");
      v34 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v35 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v35 )
        {
          ipc_log_string(v35, "ipa %s:%d Invalid EP\n", "ipa3_disconn_wigig_pipe_i", 1417);
          v34 = ipa3_ctx;
        }
        v36 = *(_QWORD *)(v34 + 34160);
        if ( v36 )
        {
          ipc_log_string(v36, "ipa %s:%d Invalid EP\n", "ipa3_disconn_wigig_pipe_i", 1417);
          result = 4294967282LL;
          goto LABEL_86;
        }
      }
    }
    goto LABEL_60;
  }
  __break(0x5512u);
  __arm_mte_set_tag((void *)(v10 + 3408), &off_1F7000);
  __arm_mte_set_tag((void *)(v10 + 3424), &off_1F7000);
  return ipa3_wigig_uc_msi_init();
}
