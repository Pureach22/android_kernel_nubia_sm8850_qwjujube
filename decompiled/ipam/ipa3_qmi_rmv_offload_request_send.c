__int64 __fastcall ipa3_qmi_rmv_offload_request_send(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  int *v16; // x15
  __int64 v17; // x14
  int v18; // w20
  __int64 v19; // x17
  int v20; // w10
  __int64 v21; // x11
  __int64 i; // x9
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 result; // x0
  __int64 v29; // x0
  unsigned int v30; // w19
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // [xsp+0h] [xbp-30h] BYREF
  void *v45; // [xsp+8h] [xbp-28h]
  _QWORD v46[2]; // [xsp+10h] [xbp-20h] BYREF
  int v47; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v48; // [xsp+24h] [xbp-Ch]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v47 = 0;
  if ( ipa3_qmi_modem_init_fin != 1 || ipa_q6_clnt == 0 )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf(a1);
    if ( ipc_logbuf )
    {
      v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v3,
                     "ipa-wan %s:%d modem QMI haven't up yet\n",
                     "ipa3_qmi_rmv_offload_request_send",
                     1131);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v5, "ipa-wan %s:%d modem QMI haven't up yet\n", "ipa3_qmi_rmv_offload_request_send", 1131);
    }
    goto LABEL_40;
  }
  if ( !*(_BYTE *)(a1 + 520) && !*(_DWORD *)(a1 + 4) )
  {
    v35 = ipa3_get_ipc_logbuf(a1);
    if ( v35 )
    {
      v36 = ipa3_get_ipc_logbuf(v35);
      v35 = ipc_log_string(v36, "ipa-wan %s:%d IPACM deleted zero rules !\n", "ipa3_qmi_rmv_offload_request_send", 1137);
    }
    v37 = ipa3_get_ipc_logbuf_low(v35);
    if ( v37 )
    {
      v38 = ipa3_get_ipc_logbuf_low(v37);
      ipc_log_string(v38, "ipa-wan %s:%d IPACM deleted zero rules !\n", "ipa3_qmi_rmv_offload_request_send", 1137);
    }
    goto LABEL_40;
  }
  v7 = ipa3_get_ipc_logbuf(a1);
  if ( v7 )
  {
    v8 = ipa3_get_ipc_logbuf(v7);
    v7 = ipc_log_string(
           v8,
           "ipa-wan %s:%d IPACM pass (%d) rules handles to Q6, cur (%d)\n",
           "ipa3_qmi_rmv_offload_request_send",
           1143,
           *(_DWORD *)(a1 + 4),
           *(_DWORD *)(ipa3_qmi_ctx + 28888));
  }
  v9 = ipa3_get_ipc_logbuf_low(v7);
  if ( v9 )
  {
    v10 = ipa3_get_ipc_logbuf_low(v9);
    v9 = ipc_log_string(
           v10,
           "ipa-wan %s:%d IPACM pass (%d) rules handles to Q6, cur (%d)\n",
           "ipa3_qmi_rmv_offload_request_send",
           1143,
           *(_DWORD *)(a1 + 4),
           *(_DWORD *)(ipa3_qmi_ctx + 28888));
  }
  if ( *(_DWORD *)(a1 + 4) > *(_DWORD *)(ipa3_qmi_ctx + 28888) )
  {
    v11 = ipa3_get_ipc_logbuf(v9);
    if ( v11 )
    {
      v12 = ipa3_get_ipc_logbuf(v11);
      v11 = ipc_log_string(
              v12,
              "ipa-wan %s:%d cur(%d), req_rmv(%d)\n",
              "ipa3_qmi_rmv_offload_request_send",
              1151,
              *(_DWORD *)(ipa3_qmi_ctx + 28888),
              *(_DWORD *)(a1 + 4));
    }
    v13 = ipa3_get_ipc_logbuf_low(v11);
    if ( v13 )
    {
      v14 = ipa3_get_ipc_logbuf_low(v13);
      ipc_log_string(
        v14,
        "ipa-wan %s:%d cur(%d), req_rmv(%d)\n",
        "ipa3_qmi_rmv_offload_request_send",
        1151,
        *(_DWORD *)(ipa3_qmi_ctx + 28888),
        *(_DWORD *)(a1 + 4));
    }
LABEL_40:
    result = 4294967274LL;
LABEL_41:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  mutex_lock(&ipa3_qmi_lock);
  if ( !*(_DWORD *)(a1 + 4) )
  {
LABEL_30:
    v45 = nullptr;
    v46[0] = 0;
    v44 = 0;
    mutex_unlock(&ipa3_qmi_lock);
    v20 = *(unsigned __int8 *)(a1 + 521);
    HIDWORD(v46[0]) = 520;
    LOWORD(v46[0]) = 66;
    v46[1] = &ipa_remove_offload_connection_req_msg_v01_ei;
    if ( v20 )
    {
      v21 = ipa3_qmi_ctx;
      for ( i = 0; i != 1024; i += 16 )
      {
        if ( *(_BYTE *)(v21 + 28896 + i) == 1 )
        {
          *(_BYTE *)(v21 + 28896 + i) = 0;
          v21 = ipa3_qmi_ctx;
        }
      }
    }
    LOWORD(v44) = 66;
    v48 = 0;
    v47 = 0;
    HIDWORD(v44) = 7;
    v45 = &ipa_remove_offload_connection_resp_msg_v01_ei;
    v29 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v46, a1, (__int64)&v44, (__int64)&v47, 0x2710u);
    v30 = v29;
    if ( (v29 & 0x80000000) != 0 )
    {
      v39 = printk(&unk_3CCE82, "ipa3_qmi_rmv_offload_request_send");
      v40 = ipa3_get_ipc_logbuf(v39);
      if ( v40 )
      {
        v41 = ipa3_get_ipc_logbuf(v40);
        v40 = ipc_log_string(
                v41,
                "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                "ipa3_qmi_rmv_offload_request_send",
                1210,
                66,
                v30);
      }
      v42 = ipa3_get_ipc_logbuf_low(v40);
      if ( v42 )
      {
        v43 = ipa3_get_ipc_logbuf_low(v42);
        ipc_log_string(
          v43,
          "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
          "ipa3_qmi_rmv_offload_request_send",
          1210,
          66,
          v30);
      }
      result = v30;
    }
    else
    {
      v31 = ipa3_get_ipc_logbuf(v29);
      if ( v31 )
      {
        v32 = ipa3_get_ipc_logbuf(v31);
        v31 = ipc_log_string(
                v32,
                "ipa-wan %s:%d left cached conntrack entries (%d)\n",
                "ipa3_qmi_rmv_offload_request_send",
                1214,
                *(_DWORD *)(ipa3_qmi_ctx + 28888));
      }
      v33 = ipa3_get_ipc_logbuf_low(v31);
      if ( v33 )
      {
        v34 = ipa3_get_ipc_logbuf_low(v33);
        ipc_log_string(
          v34,
          "ipa-wan %s:%d left cached conntrack entries (%d)\n",
          "ipa3_qmi_rmv_offload_request_send",
          1214,
          *(_DWORD *)(ipa3_qmi_ctx + 28888));
      }
      result = ipa3_check_qmi_response(v30, 66, HIWORD(v47), v48, "ipa_rmv_offload_connection");
    }
    goto LABEL_41;
  }
  v15 = 0;
  while ( 2 )
  {
    if ( v15 != 64 )
    {
      v16 = (int *)(a1 + 8 + 8 * v15);
      v17 = 0;
      v18 = *v16;
      v19 = ipa3_qmi_ctx + 28900;
      while ( *(_BYTE *)(v19 + v17 - 4) != 1 || *(_DWORD *)(v19 + v17) != v18 )
      {
        v17 += 16;
        if ( v17 == 1024 )
        {
          v23 = printk(&unk_3BE509, "ipa3_qmi_rmv_offload_request_send");
          v24 = ipa3_get_ipc_logbuf(v23);
          if ( v24 )
          {
            v25 = ipa3_get_ipc_logbuf(v24);
            v24 = ipc_log_string(
                    v25,
                    "ipa-wan %s:%d can't find rule-id %d\n",
                    "ipa3_qmi_rmv_offload_request_send",
                    1168,
                    v18);
          }
          v26 = ipa3_get_ipc_logbuf_low(v24);
          if ( v26 )
          {
            v27 = ipa3_get_ipc_logbuf_low(v26);
            ipc_log_string(v27, "ipa-wan %s:%d can't find rule-id %d\n", "ipa3_qmi_rmv_offload_request_send", 1168, v18);
          }
          mutex_unlock(&ipa3_qmi_lock);
          goto LABEL_40;
        }
      }
      ++v15;
      v16[1] = *(_DWORD *)(ipa3_qmi_ctx + v17 + 28904);
      *(_BYTE *)(ipa3_qmi_ctx + v17 + 28896) = 0;
      --*(_DWORD *)(ipa3_qmi_ctx + 28888);
      if ( v15 < *(unsigned int *)(a1 + 4) )
        continue;
      goto LABEL_30;
    }
    break;
  }
  __break(0x5512u);
  return ipa3_qmi_ul_filter_request_send((unsigned int)dword_1D388);
}
