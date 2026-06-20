__int64 __fastcall ipa3_qmi_ul_filter_request_send(_DWORD *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x22
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w10
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 result; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  _DWORD *v34; // x21
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  unsigned int v41; // w19
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  _QWORD v51[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v52[2]; // [xsp+10h] [xbp-20h] BYREF
  int v53; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+28h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v3,
                   "ipa-wan %s:%d IPACM pass %u rules to Q6\n",
                   "ipa3_qmi_ul_filter_request_send",
                   1231,
                   *a1);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa-wan %s:%d IPACM pass %u rules to Q6\n", "ipa3_qmi_ul_filter_request_send", 1231, *a1);
  }
  mutex_lock(&ipa3_qmi_lock);
  v6 = ipa3_qmi_ctx;
  if ( ipa3_qmi_ctx )
  {
    if ( (ipa3_qmi_ul_filter_request_send_cache_max_flag & 1) == 0 )
    {
      v7 = vmalloc_noprof(12044);
      v8 = *(unsigned int *)(ipa3_qmi_ctx + 26868);
      if ( (unsigned int)v8 >= 0xA )
        goto LABEL_68;
      *(_QWORD *)(ipa3_qmi_ctx + 8 * v8 + 26872) = v7;
      v6 = ipa3_qmi_ctx;
    }
    v9 = *(unsigned int *)(v6 + 26868);
    if ( (unsigned int)v9 > 9 )
LABEL_68:
      __break(0x5512u);
    if ( *(_QWORD *)(v6 + 8 * v9 + 26872) )
    {
      v10 = ipa3_qmi_ctx;
      v11 = *(unsigned int *)(ipa3_qmi_ctx + 26868);
      if ( (unsigned int)v11 <= 9 )
      {
        memcpy(*(void **)(ipa3_qmi_ctx + 8 * v11 + 26872), a1, 0x2F0Cu);
        ++*(_DWORD *)(v10 + 26868);
LABEL_18:
        v17 = *(_DWORD *)(ipa3_qmi_ctx + 26868);
        if ( v17 == 10 )
          ipa3_qmi_ul_filter_request_send_cache_max_flag = 1;
        *(_DWORD *)(ipa3_qmi_ctx + 26868) = v17 % 10;
        goto LABEL_21;
      }
      goto LABEL_68;
    }
    v12 = __ratelimit(&ipa3_qmi_ul_filter_request_send__rs, "ipa3_qmi_ul_filter_request_send");
    if ( (_DWORD)v12 )
    {
      v47 = printk(&unk_3FB90E, "ipa3_qmi_ul_filter_request_send");
      v13 = ipa3_get_ipc_logbuf(v47);
      if ( !v13 )
      {
LABEL_16:
        v15 = ipa3_get_ipc_logbuf_low(v13);
        if ( v15 )
        {
          v16 = ipa3_get_ipc_logbuf_low(v15);
          ipc_log_string(v16, "ipa-wan %s:%d  Memory Allocation  failed \n", "ipa3_qmi_ul_filter_request_send", 1244);
        }
        goto LABEL_18;
      }
    }
    else
    {
      v13 = ipa3_get_ipc_logbuf(v12);
      if ( !v13 )
        goto LABEL_16;
    }
    v14 = ipa3_get_ipc_logbuf(v13);
    v13 = ipc_log_string(v14, "ipa-wan %s:%d  Memory Allocation  failed \n", "ipa3_qmi_ul_filter_request_send", 1244);
    goto LABEL_16;
  }
LABEL_21:
  v18 = mutex_unlock(&ipa3_qmi_lock);
  if ( ipa3_qmi_indication_fin != 1 || ipa3_qmi_modem_init_fin != 1 || !ipa_q6_clnt )
  {
    v25 = ipa3_get_ipc_logbuf(v18);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf(v25);
      v25 = ipc_log_string(
              v26,
              "ipa-wan %s:%d modem QMI service is not up yet\n",
              "ipa3_qmi_ul_filter_request_send",
              1266);
    }
    v27 = ipa3_get_ipc_logbuf_low(v25);
    if ( v27 )
    {
      v28 = ipa3_get_ipc_logbuf_low(v27);
      ipc_log_string(v28, "ipa-wan %s:%d modem QMI service is not up yet\n", "ipa3_qmi_ul_filter_request_send", 1266);
    }
    goto LABEL_35;
  }
  LODWORD(v19) = *a1;
  if ( *a1 )
  {
    if ( (unsigned int)v19 > 0x3F )
      goto LABEL_26;
  }
  else
  {
    v30 = ipa3_get_ipc_logbuf(v18);
    if ( v30 )
    {
      v31 = ipa3_get_ipc_logbuf(v30);
      v30 = ipc_log_string(v31, "ipa-wan %s:%d IPACM passed 0 rules to Q6\n", "ipa3_qmi_ul_filter_request_send", 1272);
    }
    v32 = ipa3_get_ipc_logbuf_low(v30);
    if ( v32 )
    {
      v33 = ipa3_get_ipc_logbuf_low(v32);
      ipc_log_string(v33, "ipa-wan %s:%d IPACM passed 0 rules to Q6\n", "ipa3_qmi_ul_filter_request_send", 1272);
    }
    LODWORD(v19) = *a1;
    if ( *a1 > 0x3Fu )
    {
LABEL_26:
      v20 = __ratelimit(&ipa3_qmi_ul_filter_request_send__rs_41, "ipa3_qmi_ul_filter_request_send");
      if ( (_DWORD)v20 )
      {
        v48 = printk(&unk_3A7247, "ipa3_qmi_ul_filter_request_send");
        v21 = ipa3_get_ipc_logbuf(v48);
        if ( !v21 )
        {
LABEL_29:
          v23 = ipa3_get_ipc_logbuf_low(v21);
          if ( v23 )
          {
            v24 = ipa3_get_ipc_logbuf_low(v23);
            ipc_log_string(
              v24,
              "ipa-wan %s:%d Number of rules passed by IPACM, %d, exceed limit %d\n",
              "ipa3_qmi_ul_filter_request_send",
              1278,
              *a1,
              64);
          }
LABEL_35:
          result = 4294967274LL;
          goto LABEL_36;
        }
      }
      else
      {
        v21 = ipa3_get_ipc_logbuf(v20);
        if ( !v21 )
          goto LABEL_29;
      }
      v22 = ipa3_get_ipc_logbuf(v21);
      v21 = ipc_log_string(
              v22,
              "ipa-wan %s:%d Number of rules passed by IPACM, %d, exceed limit %d\n",
              "ipa3_qmi_ul_filter_request_send",
              1278,
              *a1,
              64);
      goto LABEL_29;
    }
  }
  if ( (_DWORD)v19 )
  {
    v34 = a1 + 1;
    v19 = (unsigned int)v19;
    while ( (unsigned int)(*v34 - 1) < 2 )
    {
      --v19;
      v34 += 47;
      if ( !v19 )
        goto LABEL_46;
    }
    v36 = __ratelimit(&ipa3_qmi_ul_filter_request_send__rs_44, "ipa3_qmi_ul_filter_request_send");
    if ( (_DWORD)v36 )
    {
      v49 = printk(&unk_3E4048, "ipa3_qmi_ul_filter_request_send");
      v37 = ipa3_get_ipc_logbuf(v49);
      if ( !v37 )
      {
LABEL_51:
        v39 = ipa3_get_ipc_logbuf_low(v37);
        if ( v39 )
        {
          v40 = ipa3_get_ipc_logbuf_low(v39);
          ipc_log_string(v40, "ipa-wan %s:%d Invalid IP type %d\n", "ipa3_qmi_ul_filter_request_send", 1289, *v34);
        }
        goto LABEL_35;
      }
    }
    else
    {
      v37 = ipa3_get_ipc_logbuf(v36);
      if ( !v37 )
        goto LABEL_51;
    }
    v38 = ipa3_get_ipc_logbuf(v37);
    v37 = ipc_log_string(v38, "ipa-wan %s:%d Invalid IP type %d\n", "ipa3_qmi_ul_filter_request_send", 1289, *v34);
    goto LABEL_51;
  }
LABEL_46:
  v52[0] = 0x26930000003ALL;
  v52[1] = &ipa3_configure_ul_firewall_rules_req_msg_data_v01_ei;
  v51[1] = &ipa3_configure_ul_firewall_rules_resp_msg_data_v01_ei;
  v53 = 0;
  v51[0] = 0x70000003ALL;
  v35 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v52, (__int64)a1, (__int64)v51, (__int64)&v53, 0x2710u);
  if ( (v35 & 0x80000000) == 0 )
  {
    result = ipa3_check_qmi_response(v35, 58, (unsigned __int16)v53, HIWORD(v53), "ipa_received_ul_firewall_filter");
    goto LABEL_36;
  }
  v41 = v35;
  v42 = __ratelimit(&ipa3_qmi_ul_filter_request_send__rs_47, "ipa3_qmi_ul_filter_request_send");
  if ( (_DWORD)v42 )
  {
    v50 = printk(&unk_3EF59E, "ipa3_qmi_ul_filter_request_send");
    v43 = ipa3_get_ipc_logbuf(v50);
    if ( !v43 )
      goto LABEL_56;
    goto LABEL_55;
  }
  v43 = ipa3_get_ipc_logbuf(v42);
  if ( v43 )
  {
LABEL_55:
    v44 = ipa3_get_ipc_logbuf(v43);
    v43 = ipc_log_string(
            v44,
            "ipa-wan %s:%d send Req %d failed, rc= %d\n",
            "ipa3_qmi_ul_filter_request_send",
            1314,
            58,
            v41);
  }
LABEL_56:
  v45 = ipa3_get_ipc_logbuf_low(v43);
  if ( v45 )
  {
    v46 = ipa3_get_ipc_logbuf_low(v45);
    ipc_log_string(v46, "ipa-wan %s:%d send Req %d failed, rc= %d\n", "ipa3_qmi_ul_filter_request_send", 1314, 58, v41);
  }
  result = v41;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
