__int64 __fastcall ipa3_uc_send_ntn_setup_pipe_cmd(unsigned int *a1, char a2)
{
  int ep_mapping; // w0
  int v5; // w21
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x1
  _BYTE *v29; // x0
  __int64 v30; // x8
  _BYTE *v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x9
  char v35; // w9
  unsigned int v36; // w19
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  _BYTE *v47; // [xsp+0h] [xbp-20h]
  __int64 v48; // [xsp+8h] [xbp-18h] BYREF
  __int64 v49; // [xsp+10h] [xbp-10h]
  __int64 v50; // [xsp+18h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v49 = 0;
  if ( a1 )
  {
    ep_mapping = ipa_get_ep_mapping(*a1);
    if ( ep_mapping == -1 )
    {
      printk(&unk_3B03AB, "ipa3_uc_send_ntn_setup_pipe_cmd");
      v41 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_85;
      v42 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v42 )
      {
        ipc_log_string(v42, "ipa %s:%d fail to get ep idx.\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 208);
        v41 = ipa3_ctx;
      }
      v43 = *(_QWORD *)(v41 + 34160);
      if ( v43 )
      {
        ipc_log_string(v43, "ipa %s:%d fail to get ep idx.\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 208);
        v36 = -14;
      }
      else
      {
LABEL_85:
        v36 = -14;
      }
    }
    else
    {
      v5 = ep_mapping;
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(v7, "ipa %s:%d client=%d ep=%d\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 212, *a1, v5);
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d client=%d ep=%d\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 212, *a1, v5);
          v6 = ipa3_ctx;
        }
        if ( v6 )
        {
          v9 = *(_QWORD *)(v6 + 34152);
          if ( v9 )
          {
            ipc_log_string(v9, "ipa %s:%d ring_base_pa = 0x%pa\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 215, a1 + 2);
            v6 = ipa3_ctx;
          }
          v10 = *(_QWORD *)(v6 + 34160);
          if ( v10 )
          {
            ipc_log_string(v10, "ipa %s:%d ring_base_pa = 0x%pa\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 215, a1 + 2);
            v6 = ipa3_ctx;
          }
          if ( v6 )
          {
            v11 = *(_QWORD *)(v6 + 34152);
            if ( v11 )
            {
              ipc_log_string(v11, "ipa %s:%d ring_base_iova = 0x%pa\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 217, a1 + 4);
              v6 = ipa3_ctx;
            }
            v12 = *(_QWORD *)(v6 + 34160);
            if ( v12 )
            {
              ipc_log_string(v12, "ipa %s:%d ring_base_iova = 0x%pa\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 217, a1 + 4);
              v6 = ipa3_ctx;
            }
            if ( v6 )
            {
              v13 = *(_QWORD *)(v6 + 34152);
              if ( v13 )
              {
                ipc_log_string(v13, "ipa %s:%d ntn_ring_size = %d\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 218, a1[8]);
                v6 = ipa3_ctx;
              }
              v14 = *(_QWORD *)(v6 + 34160);
              if ( v14 )
              {
                ipc_log_string(v14, "ipa %s:%d ntn_ring_size = %d\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 218, a1[8]);
                v6 = ipa3_ctx;
              }
              if ( v6 )
              {
                v15 = *(_QWORD *)(v6 + 34152);
                if ( v15 )
                {
                  ipc_log_string(
                    v15,
                    "ipa %s:%d buff_pool_base_pa = 0x%pa\n",
                    "ipa3_uc_send_ntn_setup_pipe_cmd",
                    219,
                    a1 + 10);
                  v6 = ipa3_ctx;
                }
                v16 = *(_QWORD *)(v6 + 34160);
                if ( v16 )
                {
                  ipc_log_string(
                    v16,
                    "ipa %s:%d buff_pool_base_pa = 0x%pa\n",
                    "ipa3_uc_send_ntn_setup_pipe_cmd",
                    219,
                    a1 + 10);
                  v6 = ipa3_ctx;
                }
                if ( v6 )
                {
                  v17 = *(_QWORD *)(v6 + 34152);
                  if ( v17 )
                  {
                    ipc_log_string(
                      v17,
                      "ipa %s:%d buff_pool_base_iova = 0x%pa\n",
                      "ipa3_uc_send_ntn_setup_pipe_cmd",
                      220,
                      a1 + 12);
                    v6 = ipa3_ctx;
                  }
                  v18 = *(_QWORD *)(v6 + 34160);
                  if ( v18 )
                  {
                    ipc_log_string(
                      v18,
                      "ipa %s:%d buff_pool_base_iova = 0x%pa\n",
                      "ipa3_uc_send_ntn_setup_pipe_cmd",
                      220,
                      a1 + 12);
                    v6 = ipa3_ctx;
                  }
                  if ( v6 )
                  {
                    v19 = *(_QWORD *)(v6 + 34152);
                    if ( v19 )
                    {
                      ipc_log_string(
                        v19,
                        "ipa %s:%d num_buffers = %d\n",
                        "ipa3_uc_send_ntn_setup_pipe_cmd",
                        221,
                        a1[18]);
                      v6 = ipa3_ctx;
                    }
                    v20 = *(_QWORD *)(v6 + 34160);
                    if ( v20 )
                    {
                      ipc_log_string(
                        v20,
                        "ipa %s:%d num_buffers = %d\n",
                        "ipa3_uc_send_ntn_setup_pipe_cmd",
                        221,
                        a1[18]);
                      v6 = ipa3_ctx;
                    }
                    if ( v6 )
                    {
                      v21 = *(_QWORD *)(v6 + 34152);
                      if ( v21 )
                      {
                        ipc_log_string(
                          v21,
                          "ipa %s:%d data_buff_size = %d\n",
                          "ipa3_uc_send_ntn_setup_pipe_cmd",
                          222,
                          a1[19]);
                        v6 = ipa3_ctx;
                      }
                      v22 = *(_QWORD *)(v6 + 34160);
                      if ( v22 )
                      {
                        ipc_log_string(
                          v22,
                          "ipa %s:%d data_buff_size = %d\n",
                          "ipa3_uc_send_ntn_setup_pipe_cmd",
                          222,
                          a1[19]);
                        v6 = ipa3_ctx;
                      }
                      if ( v6 )
                      {
                        v23 = *(_QWORD *)(v6 + 34152);
                        if ( v23 )
                        {
                          ipc_log_string(
                            v23,
                            "ipa %s:%d tail_ptr_base_pa = 0x%pa\n",
                            "ipa3_uc_send_ntn_setup_pipe_cmd",
                            223,
                            a1 + 20);
                          v6 = ipa3_ctx;
                        }
                        v24 = *(_QWORD *)(v6 + 34160);
                        if ( v24 )
                        {
                          ipc_log_string(
                            v24,
                            "ipa %s:%d tail_ptr_base_pa = 0x%pa\n",
                            "ipa3_uc_send_ntn_setup_pipe_cmd",
                            223,
                            a1 + 20);
                          v6 = ipa3_ctx;
                        }
                        if ( v6 )
                        {
                          v25 = *(_QWORD *)(v6 + 34152);
                          if ( v25 )
                          {
                            ipc_log_string(
                              v25,
                              "ipa %s:%d db_mode = %d\n",
                              "ipa3_uc_send_ntn_setup_pipe_cmd",
                              224,
                              *((unsigned __int8 *)a1 + 88));
                            v6 = ipa3_ctx;
                          }
                          v26 = *(_QWORD *)(v6 + 34160);
                          if ( v26 )
                          {
                            ipc_log_string(
                              v26,
                              "ipa %s:%d db_mode = %d\n",
                              "ipa3_uc_send_ntn_setup_pipe_cmd",
                              224,
                              *((unsigned __int8 *)a1 + 88));
                            v6 = ipa3_ctx;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v27 = v6 + 32240;
      if ( *(_DWORD *)v27 <= 0xDu )
        v28 = 25;
      else
        v28 = 28;
      LODWORD(v49) = v28;
      v29 = (_BYTE *)dma_alloc_attrs(*(_QWORD *)(v27 + 1984), v28, &v48, 3264, 0);
      v47 = v29;
      if ( v29 )
      {
        if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
        {
          *v29 = 5;
          v30 = 1;
        }
        else
        {
          *(_DWORD *)v29 = 5;
          v30 = 4;
        }
        v31 = &v29[v30];
        v32 = 4;
        if ( !*((_BYTE *)a1 + 4) )
          v32 = 2;
        v33 = 10;
        v34 = *(_QWORD *)&a1[v32];
        if ( *((_BYTE *)a1 + 4) )
          v33 = 12;
        *(_DWORD *)v31 = v34;
        *((_DWORD *)v31 + 1) = *(_QWORD *)&a1[v33];
        *((_WORD *)v31 + 4) = a1[8];
        *((_WORD *)v31 + 5) = a1[18];
        *((_DWORD *)v31 + 3) = *((_QWORD *)a1 + 10);
        *((_WORD *)v31 + 9) = a1[19];
        v35 = *((_BYTE *)a1 + 88);
        v31[16] = v5;
        v31[17] = a2;
        v31[20] = v35;
        if ( (unsigned int)ipa3_uc_send_cmd((unsigned int)v48, 0xC1u, 0xC0u, 0, 2500) )
          v36 = -14;
        else
          v36 = 0;
        dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v49, v47, v48, 0);
      }
      else
      {
        printk(&unk_3A6C3A, "ipa3_uc_send_ntn_setup_pipe_cmd");
        v44 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
        v45 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v45 )
        {
          ipc_log_string(v45, "ipa %s:%d fail to get DMA memory.\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 232);
          v44 = ipa3_ctx;
        }
        v46 = *(_QWORD *)(v44 + 34160);
        if ( v46 )
        {
          ipc_log_string(v46, "ipa %s:%d fail to get DMA memory.\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 232);
          v36 = -12;
        }
        else
        {
LABEL_86:
          v36 = -12;
        }
      }
    }
  }
  else
  {
    printk(&unk_3DB00B, "ipa3_uc_send_ntn_setup_pipe_cmd");
    v38 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_84;
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d invalid input\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 202);
      v38 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v38 + 34160);
    if ( v40 )
    {
      ipc_log_string(v40, "ipa %s:%d invalid input\n", "ipa3_uc_send_ntn_setup_pipe_cmd", 202);
      v36 = -22;
    }
    else
    {
LABEL_84:
      v36 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v36;
}
