__int64 __fastcall ipa_mhi_start(unsigned int *a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w0
  int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w11
  unsigned int v19; // w9
  unsigned int inited; // w0
  __int64 v21; // x0
  __int64 result; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned int v30; // w19
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  long double v36; // q0
  __int64 v37; // x0
  __int64 v38; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v39; // [xsp+10h] [xbp-30h]
  __int64 v40; // [xsp+18h] [xbp-28h]
  __int64 v41; // [xsp+20h] [xbp-20h]
  void *v42; // [xsp+28h] [xbp-18h]
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = nullptr;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_start", 661);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_start", 661);
  }
  if ( a1 )
  {
    if ( ipa_mhi_client_ctx )
    {
      if ( !(unsigned int)((__int64 (__fastcall *)(__int64, long double))ipa_mhi_set_state)(2, v3) )
      {
        v5 = ipa_mhi_client_ctx;
        *(_DWORD *)(ipa_mhi_client_ctx + 1272) = *a1;
        *(_DWORD *)(v5 + 1276) = a1[1];
        *(_QWORD *)(v5 + 1280) = *((_QWORD *)a1 + 1);
        *(_QWORD *)(v5 + 1288) = *((_QWORD *)a1 + 2);
        if ( ipa3_get_ipc_logbuf() )
        {
          v6 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v6,
            "ipa_mhi_client %s:%d host_ctrl_addr 0x%x\n",
            "ipa_mhi_start",
            686,
            *(_DWORD *)(ipa_mhi_client_ctx + 1272));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v7 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v7,
            "ipa_mhi_client %s:%d host_ctrl_addr 0x%x\n",
            "ipa_mhi_start",
            686,
            *(_DWORD *)(ipa_mhi_client_ctx + 1272));
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v8 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v8,
            "ipa_mhi_client %s:%d host_data_addr 0x%x\n",
            "ipa_mhi_start",
            688,
            *(_DWORD *)(ipa_mhi_client_ctx + 1276));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v9 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v9,
            "ipa_mhi_client %s:%d host_data_addr 0x%x\n",
            "ipa_mhi_start",
            688,
            *(_DWORD *)(ipa_mhi_client_ctx + 1276));
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v10 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v10,
            "ipa_mhi_client %s:%d channel_context_array_addr 0x%llx\n",
            "ipa_mhi_start",
            690,
            *(_QWORD *)(ipa_mhi_client_ctx + 1280));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v11 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v11,
            "ipa_mhi_client %s:%d channel_context_array_addr 0x%llx\n",
            "ipa_mhi_start",
            690,
            *(_QWORD *)(ipa_mhi_client_ctx + 1280));
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v12 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v12,
            "ipa_mhi_client %s:%d event_context_array_addr 0x%llx\n",
            "ipa_mhi_start",
            692,
            *(_QWORD *)(ipa_mhi_client_ctx + 1288));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v13 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v13,
            "ipa_mhi_client %s:%d event_context_array_addr 0x%llx\n",
            "ipa_mhi_start",
            692,
            *(_QWORD *)(ipa_mhi_client_ctx + 1288));
        }
        v14 = ipa_pm_activate_sync(*(_DWORD *)(ipa_mhi_client_ctx + 1308));
        if ( v14 )
        {
          v30 = v14;
          printk(&unk_3DCCE9, "ipa_mhi_start");
          if ( ipa3_get_ipc_logbuf() )
          {
            v31 = ipa3_get_ipc_logbuf();
            ipc_log_string(v31, "ipa_mhi_client %s:%d failed activate client %d\n", "ipa_mhi_start", 696, v30);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v32 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v32, "ipa_mhi_client %s:%d failed activate client %d\n", "ipa_mhi_start", 696, v30);
          }
        }
        else
        {
          v15 = ipa_pm_activate_sync(*(_DWORD *)(ipa_mhi_client_ctx + 1312));
          if ( v15 )
          {
            v30 = v15;
            printk(&unk_3A5128, "ipa_mhi_start");
            if ( ipa3_get_ipc_logbuf() )
            {
              v33 = ipa3_get_ipc_logbuf();
              ipc_log_string(v33, "ipa_mhi_client %s:%d failed activate modem client %d\n", "ipa_mhi_start", 701, v30);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v34 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v34, "ipa_mhi_client %s:%d failed activate modem client %d\n", "ipa_mhi_start", 701, v30);
            }
          }
          else
          {
            v16 = *(_DWORD *)(ipa_mhi_client_ctx + 1268);
            HIDWORD(v40) = *(_DWORD *)(ipa_mhi_client_ctx + 1264);
            LODWORD(v41) = v16;
            v18 = *a1;
            v17 = a1[1];
            LODWORD(v43) = HIDWORD(v40);
            LODWORD(v40) = v17;
            v19 = *(_DWORD *)(ipa_mhi_client_ctx + 1260);
            v38 = ipa_mhi_client_ctx + 1244;
            v39 = __PAIR64__(v18, v19);
            v42 = &ipa_cached_dl_ul_sync_info;
            inited = ipa3_mhi_init_engine((__int64)&v38);
            if ( !inited )
            {
              if ( ipa3_get_ipc_logbuf() )
              {
                v21 = ipa3_get_ipc_logbuf();
                ipc_log_string(v21, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_start", 726);
              }
              result = ipa3_get_ipc_logbuf_low();
              if ( result )
              {
                v23 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v23, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_start", 726);
                result = 0;
              }
              goto LABEL_61;
            }
            v30 = inited;
            printk(&unk_3D6FC9, "ipa_mhi_start");
            if ( ipa3_get_ipc_logbuf() )
            {
              v35 = ipa3_get_ipc_logbuf();
              ipc_log_string(v35, "ipa_mhi_client %s:%d IPA core failed to start MHI %d\n", "ipa_mhi_start", 722, v30);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v37 = ipa3_get_ipc_logbuf_low();
              v36 = ipc_log_string(
                      v37,
                      "ipa_mhi_client %s:%d IPA core failed to start MHI %d\n",
                      "ipa_mhi_start",
                      722,
                      v30);
            }
            ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)(
              *(unsigned int *)(ipa_mhi_client_ctx + 1312),
              v36);
          }
          ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_mhi_client_ctx + 1308));
        }
        ((void (__fastcall *)(_QWORD))ipa_mhi_set_state)(0);
        result = v30;
        goto LABEL_61;
      }
      printk(&unk_3E7CF1, "ipa_mhi_start");
      if ( ipa3_get_ipc_logbuf() )
      {
        v28 = ipa3_get_ipc_logbuf();
        ipc_log_string(v28, "ipa_mhi_client %s:%d ipa_mhi_set_state %d\n", "ipa_mhi_start", 675, -1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v29 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v29, "ipa_mhi_client %s:%d ipa_mhi_set_state %d\n", "ipa_mhi_start", 675, -1);
        result = 0xFFFFFFFFLL;
        goto LABEL_61;
      }
    }
    else
    {
      printk(&unk_3F0946, "ipa_mhi_start");
      if ( ipa3_get_ipc_logbuf() )
      {
        v26 = ipa3_get_ipc_logbuf();
        ipc_log_string(v26, "ipa_mhi_client %s:%d not initialized\n", "ipa_mhi_start", 669);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v27 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v27, "ipa_mhi_client %s:%d not initialized\n", "ipa_mhi_start", 669);
        result = 0xFFFFFFFFLL;
        goto LABEL_61;
      }
    }
    result = 0xFFFFFFFFLL;
    goto LABEL_61;
  }
  printk(&unk_3CE387, "ipa_mhi_start");
  if ( ipa3_get_ipc_logbuf() )
  {
    v24 = ipa3_get_ipc_logbuf();
    ipc_log_string(v24, "ipa_mhi_client %s:%d null args\n", "ipa_mhi_start", 664);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v25 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v25, "ipa_mhi_client %s:%d null args\n", "ipa_mhi_start", 664);
  }
  result = 4294967274LL;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
