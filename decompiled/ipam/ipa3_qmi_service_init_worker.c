__int64 ipa3_qmi_service_init_worker()
{
  __int64 v0; // x0
  char v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  char modem_cfg_emb_pipe_flt; // w0
  __int64 v10; // x8
  __int64 v11; // x0
  int v12; // w0
  int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w19
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  int v45; // w19
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0

  ipa3_qmi_ctx = vzalloc_noprof(30184);
  if ( ipa3_qmi_ctx )
  {
    v0 = ((__int64 (*)(void))ipa3_is_apq)();
    v1 = v0;
    ipc_logbuf = ipa3_get_ipc_logbuf(v0);
    if ( (v1 & 1) != 0 )
    {
      if ( ipc_logbuf )
      {
        v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v3,
                       "ipa-wan %s:%d Only start IPA A7 QMI client\n",
                       "ipa3_qmi_service_init_worker",
                       2385);
      }
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( ipc_logbuf_low )
      {
        v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
        ipc_log_string(v5, "ipa-wan %s:%d Only start IPA A7 QMI client\n", "ipa3_qmi_service_init_worker", 2385);
      }
    }
    else
    {
      if ( ipc_logbuf )
      {
        v6 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v6,
                       "ipa-wan %s:%d IPA A7 QMI init OK :>>>>\n",
                       "ipa3_qmi_service_init_worker",
                       2390);
      }
      v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v7 )
      {
        v8 = ipa3_get_ipc_logbuf_low(v7);
        v7 = ipc_log_string(v8, "ipa-wan %s:%d IPA A7 QMI init OK :>>>>\n", "ipa3_qmi_service_init_worker", 2390);
      }
      modem_cfg_emb_pipe_flt = ipa3_get_modem_cfg_emb_pipe_flt(v7);
      v10 = ipa3_qmi_ctx + 28672;
      *(_BYTE *)(ipa3_qmi_ctx + 28860) = modem_cfg_emb_pipe_flt & 1;
      *(_DWORD *)(v10 + 216) = 0;
      v11 = vzalloc_noprof(304);
      ipa3_svc_handle = v11;
      if ( !v11 )
        goto LABEL_45;
      v12 = qmi_handle_init(v11, 22685, &server_ops, &server_handlers);
      if ( v12 < 0 )
      {
        v39 = v12;
        v40 = printk(&unk_3C756A, "ipa3_qmi_service_init_worker");
        v41 = ipa3_get_ipc_logbuf(v40);
        if ( v41 )
        {
          v42 = ipa3_get_ipc_logbuf(v41);
          v41 = ipc_log_string(
                  v42,
                  "ipa-wan %s:%d Initializing ipa_a5 svc failed %d\n",
                  "ipa3_qmi_service_init_worker",
                  2407,
                  v39);
        }
        v43 = ipa3_get_ipc_logbuf_low(v41);
        if ( v43 )
        {
          v44 = ipa3_get_ipc_logbuf_low(v43);
          ipc_log_string(
            v44,
            "ipa-wan %s:%d Initializing ipa_a5 svc failed %d\n",
            "ipa3_qmi_service_init_worker",
            2407,
            v39);
        }
        goto LABEL_44;
      }
      v13 = qmi_add_server(ipa3_svc_handle, 49, 1, 1);
      if ( v13 < 0 )
      {
        v45 = v13;
        v46 = printk(&unk_3AA1F6, "ipa3_qmi_service_init_worker");
        v47 = ipa3_get_ipc_logbuf(v46);
        if ( v47 )
        {
          v48 = ipa3_get_ipc_logbuf(v47);
          v47 = ipc_log_string(
                  v48,
                  "ipa-wan %s:%d Registering ipa_a5 svc failed %d\n",
                  "ipa3_qmi_service_init_worker",
                  2418,
                  v45);
        }
        v49 = ipa3_get_ipc_logbuf_low(v47);
        if ( v49 )
        {
          v50 = ipa3_get_ipc_logbuf_low(v49);
          ipc_log_string(
            v50,
            "ipa-wan %s:%d Registering ipa_a5 svc failed %d\n",
            "ipa3_qmi_service_init_worker",
            2418,
            v45);
        }
LABEL_42:
        if ( (((__int64 (*)(void))ipa3_is_apq)() & 1) == 0 )
          qmi_handle_release(ipa3_svc_handle);
LABEL_44:
        v11 = vfree(ipa3_qmi_ctx);
LABEL_45:
        result = ipa3_is_apq(v11);
        if ( (result & 1) == 0 )
        {
          result = vfree(ipa3_svc_handle);
          ipa3_svc_handle = 0;
        }
        ipa3_qmi_ctx = 0;
        return result;
      }
    }
    ipa_clnt_req_workqueue = alloc_workqueue("%s", (const char *)0x6000A);
    if ( ipa_clnt_req_workqueue )
    {
      v14 = vzalloc_noprof(304);
      ipa_q6_clnt = v14;
      if ( v14 )
      {
        if ( (qmi_handle_init(v14, 22685, client_ops, &client_handlers) & 0x80000000) != 0 )
        {
          v29 = printk(&unk_3E6B79, "ipa3_qmi_service_init_worker");
          v30 = ipa3_get_ipc_logbuf(v29);
          if ( v30 )
          {
            v31 = ipa3_get_ipc_logbuf(v30);
            v30 = ipc_log_string(
                    v31,
                    "ipa-wan %s:%d Creating clnt handle failed\n",
                    "ipa3_qmi_service_init_worker",
                    2442);
          }
          v32 = ipa3_get_ipc_logbuf_low(v30);
          if ( v32 )
          {
            v33 = ipa3_get_ipc_logbuf_low(v32);
            ipc_log_string(v33, "ipa-wan %s:%d Creating clnt handle failed\n", "ipa3_qmi_service_init_worker", 2442);
          }
        }
        else
        {
          v15 = qmi_add_lookup(ipa_q6_clnt, 49, 1, 2);
          if ( (v15 & 0x80000000) == 0 )
          {
            v16 = ipa3_get_ipc_logbuf(v15);
            if ( v16 )
            {
              v17 = ipa3_get_ipc_logbuf(v16);
              v16 = ipc_log_string(v17, "ipa-wan %s:%d wait service available\n", "ipa3_qmi_service_init_worker", 2457);
            }
            result = ipa3_get_ipc_logbuf_low(v16);
            if ( result )
            {
              v19 = ipa3_get_ipc_logbuf_low(result);
              return ipc_log_string(v19, "ipa-wan %s:%d wait service available\n", "ipa3_qmi_service_init_worker", 2457);
            }
            return result;
          }
          v34 = printk(&unk_3D33DC, "ipa3_qmi_service_init_worker");
          v35 = ipa3_get_ipc_logbuf(v34);
          if ( v35 )
          {
            v36 = ipa3_get_ipc_logbuf(v35);
            v35 = ipc_log_string(v36, "ipa-wan %s:%d Adding Q6 Svc failed\n", "ipa3_qmi_service_init_worker", 2452);
          }
          v37 = ipa3_get_ipc_logbuf_low(v35);
          if ( v37 )
          {
            v38 = ipa3_get_ipc_logbuf_low(v37);
            ipc_log_string(v38, "ipa-wan %s:%d Adding Q6 Svc failed\n", "ipa3_qmi_service_init_worker", 2452);
          }
          qmi_handle_release(ipa_q6_clnt);
        }
        vfree(ipa_q6_clnt);
        ipa_q6_clnt = 0;
      }
      destroy_workqueue(ipa_clnt_req_workqueue);
      ipa_clnt_req_workqueue = 0;
    }
    else
    {
      v24 = printk(&unk_3BB7D7, "ipa3_qmi_service_init_worker");
      v25 = ipa3_get_ipc_logbuf(v24);
      if ( v25 )
      {
        v26 = ipa3_get_ipc_logbuf(v25);
        v25 = ipc_log_string(
                v26,
                "ipa-wan %s:%d Creating clnt_req workqueue failed\n",
                "ipa3_qmi_service_init_worker",
                2426);
      }
      v27 = ipa3_get_ipc_logbuf_low(v25);
      if ( v27 )
      {
        v28 = ipa3_get_ipc_logbuf_low(v27);
        ipc_log_string(v28, "ipa-wan %s:%d Creating clnt_req workqueue failed\n", "ipa3_qmi_service_init_worker", 2426);
      }
    }
    goto LABEL_42;
  }
  v20 = printk(&unk_3D337A, "ipa3_qmi_service_init_worker");
  v21 = ipa3_get_ipc_logbuf(v20);
  if ( v21 )
  {
    v22 = ipa3_get_ipc_logbuf(v21);
    v21 = ipc_log_string(v22, "ipa-wan %s:%d Failed to allocate ipa3_qmi_ctx\n", "ipa3_qmi_service_init_worker", 2379);
  }
  result = ipa3_get_ipc_logbuf_low(v21);
  if ( result )
  {
    v23 = ipa3_get_ipc_logbuf_low(result);
    return ipc_log_string(v23, "ipa-wan %s:%d Failed to allocate ipa3_qmi_ctx\n", "ipa3_qmi_service_init_worker", 2379);
  }
  return result;
}
