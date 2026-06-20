__int64 __fastcall ipa3_qmi_add_offload_request_send(__int64 a1)
{
  void *v2; // x0
  int v3; // w21
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x9
  _BYTE *v17; // x10
  __int64 v18; // x0
  unsigned int v19; // w0
  unsigned __int64 v20; // x20
  __int64 v21; // x13
  _DWORD *v22; // x23
  int v23; // w21
  __int64 v24; // x17
  __int64 v25; // x15
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 result; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int v40; // w19
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  _QWORD v66[2]; // [xsp+8h] [xbp-238h] BYREF
  _QWORD v67[2]; // [xsp+18h] [xbp-228h] BYREF
  _DWORD s[131]; // [xsp+2Ch] [xbp-214h] BYREF
  __int64 v69; // [xsp+238h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = memset(s, 0, sizeof(s));
  if ( ipa3_qmi_modem_init_fin != 1 || !ipa_q6_clnt )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf(v2);
    if ( ipc_logbuf )
    {
      v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v9,
                     "ipa-wan %s:%d modem QMI haven't up yet\n",
                     "ipa3_qmi_add_offload_request_send",
                     983);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v11, "ipa-wan %s:%d modem QMI haven't up yet\n", "ipa3_qmi_add_offload_request_send", 983);
    }
    goto LABEL_48;
  }
  v3 = *(_DWORD *)(a1 + 284);
  v4 = ipa3_get_ipc_logbuf(v2);
  if ( v3 )
  {
    if ( v4 )
    {
      v5 = ipa3_get_ipc_logbuf(v4);
      v4 = ipc_log_string(
             v5,
             "ipa-wan %s:%d IPACM pass %u rules to Q6\n",
             "ipa3_qmi_add_offload_request_send",
             995,
             *(_DWORD *)(a1 + 284));
    }
    v6 = ipa3_get_ipc_logbuf_low(v4);
    if ( v6 )
    {
      v7 = ipa3_get_ipc_logbuf_low(v6);
      v6 = ipc_log_string(
             v7,
             "ipa-wan %s:%d IPACM pass %u rules to Q6\n",
             "ipa3_qmi_add_offload_request_send",
             995,
             *(_DWORD *)(a1 + 284));
    }
  }
  else
  {
    if ( v4 )
    {
      v12 = ipa3_get_ipc_logbuf(v4);
      v4 = ipc_log_string(v12, "ipa-wan %s:%d IPACM pass zero rules to Q6\n", "ipa3_qmi_add_offload_request_send", 992);
    }
    v6 = ipa3_get_ipc_logbuf_low(v4);
    if ( v6 )
    {
      v13 = ipa3_get_ipc_logbuf_low(v6);
      v6 = ipc_log_string(v13, "ipa-wan %s:%d IPACM pass zero rules to Q6\n", "ipa3_qmi_add_offload_request_send", 992);
    }
  }
  v14 = *(_DWORD *)(ipa3_qmi_ctx + 28888);
  if ( v14 < 0 || (v15 = *(unsigned int *)(a1 + 284), (unsigned int)v15 >= 64 - v14) )
  {
    v31 = ipa3_get_ipc_logbuf(v6);
    if ( v31 )
    {
      v32 = ipa3_get_ipc_logbuf(v31);
      v31 = ipc_log_string(
              v32,
              "ipa-wan %s:%d cur(%d), req(%d), exceed limit (%d)\n",
              "ipa3_qmi_add_offload_request_send",
              1007,
              *(_DWORD *)(ipa3_qmi_ctx + 28888),
              *(_DWORD *)(a1 + 284),
              64);
    }
    v33 = ipa3_get_ipc_logbuf_low(v31);
    if ( v33 )
    {
      v34 = ipa3_get_ipc_logbuf_low(v33);
      ipc_log_string(
        v34,
        "ipa-wan %s:%d cur(%d), req(%d), exceed limit (%d)\n",
        "ipa3_qmi_add_offload_request_send",
        1007,
        *(_DWORD *)(ipa3_qmi_ctx + 28888),
        *(_DWORD *)(a1 + 284),
        64);
    }
LABEL_48:
    result = 4294967274LL;
    goto LABEL_49;
  }
  if ( (_DWORD)v15 )
  {
    v16 = 0;
    v17 = (_BYTE *)(a1 + 488);
    do
    {
      if ( v16 == 64 )
LABEL_78:
        __break(0x5512u);
      if ( (unsigned int)(*((_DWORD *)v17 - 50) - 1) > 1
        || !*v17
        || (unsigned int)(*((_DWORD *)v17 - 3) - 5) < 0xFFFFFFFC )
      {
        goto LABEL_48;
      }
      ++v16;
      v17 += 216;
    }
    while ( v15 != v16 );
  }
  v67[1] = &ipa_add_offload_connection_req_msg_v01_ei;
  v67[0] = 65;
  memset(s, 0, sizeof(s));
  v66[0] = 0x20B00000041LL;
  v66[1] = &ipa_add_offload_connection_resp_msg_v01_ei;
  v18 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v67, a1, (__int64)v66, (__int64)s, 0x2710u);
  if ( (v18 & 0x80000000) != 0 )
  {
    v40 = v18;
    v41 = printk(&unk_3CCE82, "ipa3_qmi_add_offload_request_send");
    v42 = ipa3_get_ipc_logbuf(v41);
    if ( v42 )
    {
      v43 = ipa3_get_ipc_logbuf(v42);
      v42 = ipc_log_string(
              v43,
              "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
              "ipa3_qmi_add_offload_request_send",
              1046,
              65,
              v40);
    }
    v44 = ipa3_get_ipc_logbuf_low(v42);
    if ( v44 )
    {
      v45 = ipa3_get_ipc_logbuf_low(v44);
      ipc_log_string(
        v45,
        "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
        "ipa3_qmi_add_offload_request_send",
        1046,
        65,
        v40);
LABEL_63:
      result = v40;
      goto LABEL_49;
    }
LABEL_72:
    result = v40;
    goto LABEL_49;
  }
  v19 = ipa3_check_qmi_response(v18, 65, LOWORD(s[0]), HIWORD(s[0]), "ipa_add_offload_connection");
  if ( v19 )
  {
    v40 = v19;
    v46 = printk(&unk_3A3E7D, "ipa3_qmi_add_offload_request_send");
    v47 = ipa3_get_ipc_logbuf(v46);
    if ( v47 )
    {
      v48 = ipa3_get_ipc_logbuf(v47);
      v47 = ipc_log_string(
              v48,
              "ipa-wan %s:%d QMI get Response %d failed, rc= %d\n",
              "ipa3_qmi_add_offload_request_send",
              1057,
              65,
              v40);
    }
    v49 = ipa3_get_ipc_logbuf_low(v47);
    if ( v49 )
    {
      v50 = ipa3_get_ipc_logbuf_low(v49);
      ipc_log_string(
        v50,
        "ipa-wan %s:%d QMI get Response %d failed, rc= %d\n",
        "ipa3_qmi_add_offload_request_send",
        1057,
        65,
        v40);
      goto LABEL_63;
    }
    goto LABEL_72;
  }
  if ( !LOBYTE(s[1]) )
  {
    v51 = printk(&unk_3D32B5, "ipa3_qmi_add_offload_request_send");
    v52 = ipa3_get_ipc_logbuf(v51);
    if ( v52 )
    {
      v53 = ipa3_get_ipc_logbuf(v52);
      v52 = ipc_log_string(
              v53,
              "ipa-wan %s:%d QMI resp invalid %d failed\n",
              "ipa3_qmi_add_offload_request_send",
              1064,
              LOBYTE(s[1]));
    }
    v54 = ipa3_get_ipc_logbuf_low(v52);
    if ( v54 )
    {
      v55 = ipa3_get_ipc_logbuf_low(v54);
      ipc_log_string(
        v55,
        "ipa-wan %s:%d QMI resp invalid %d failed\n",
        "ipa3_qmi_add_offload_request_send",
        1064,
        LOBYTE(s[1]));
      result = 4294967262LL;
      goto LABEL_49;
    }
LABEL_73:
    result = 4294967262LL;
    goto LABEL_49;
  }
  if ( s[2] != *(_DWORD *)(a1 + 284) )
  {
    v56 = printk(&unk_3AD320, "ipa3_qmi_add_offload_request_send");
    v57 = ipa3_get_ipc_logbuf(v56);
    if ( v57 )
    {
      v58 = ipa3_get_ipc_logbuf(v57);
      v57 = ipc_log_string(
              v58,
              "ipa-wan %s:%d QMI resp invalid size %d req %d\n",
              "ipa3_qmi_add_offload_request_send",
              1072,
              s[2],
              *(_DWORD *)(a1 + 284));
    }
    v59 = ipa3_get_ipc_logbuf_low(v57);
    if ( v59 )
    {
      v60 = ipa3_get_ipc_logbuf_low(v59);
      ipc_log_string(
        v60,
        "ipa-wan %s:%d QMI resp invalid size %d req %d\n",
        "ipa3_qmi_add_offload_request_send",
        1072,
        s[2],
        *(_DWORD *)(a1 + 284));
      result = 4294967262LL;
      goto LABEL_49;
    }
    goto LABEL_73;
  }
  mutex_lock(&ipa3_qmi_lock);
  if ( *(_DWORD *)(a1 + 284) )
  {
    v20 = 0;
    while ( 1 )
    {
      if ( v20 == 64 )
        goto LABEL_78;
      v21 = 2 * v20;
      if ( 8 * v20 == 512 )
        goto LABEL_79;
      v22 = (_DWORD *)(a1 + 288 + 216 * v20);
      v23 = s[2 * v20 + 3];
      if ( v22[52] != v23 )
        break;
      v24 = 64;
      v25 = 28904;
      while ( *(_BYTE *)(ipa3_qmi_ctx + v25 - 8) == 1 )
      {
        --v24;
        v25 += 16;
        if ( !v24 )
        {
          v35 = printk(&unk_3FE419, "ipa3_qmi_add_offload_request_send");
          v36 = ipa3_get_ipc_logbuf(v35);
          if ( v36 )
          {
            v37 = ipa3_get_ipc_logbuf(v36);
            v36 = ipc_log_string(
                    v37,
                    "ipa-wan %s:%d can't find free spot for rule-id %d\n",
                    "ipa3_qmi_add_offload_request_send",
                    1097,
                    v23);
          }
          v38 = ipa3_get_ipc_logbuf_low(v36);
          if ( v38 )
          {
            v39 = ipa3_get_ipc_logbuf_low(v38);
            ipc_log_string(
              v39,
              "ipa-wan %s:%d can't find free spot for rule-id %d\n",
              "ipa3_qmi_add_offload_request_send",
              1097,
              v23);
          }
          goto LABEL_54;
        }
      }
      *(_DWORD *)(ipa3_qmi_ctx + v25 - 4) = v23;
      if ( (unsigned __int64)(v21 * 4 - 509) < 0xFFFFFFFFFFFFFDF3LL )
      {
LABEL_79:
        __break(1u);
        JUMPOUT(0xFFFFFFFFFAE6ABC8LL);
      }
      ++v20;
      *(_DWORD *)(ipa3_qmi_ctx + v25) = s[v21 + 4];
      *(_BYTE *)(ipa3_qmi_ctx + v25 - 8) = 1;
      *(_DWORD *)(ipa3_qmi_ctx + v25 - 12) = *v22;
      ++*(_DWORD *)(ipa3_qmi_ctx + 28888);
      if ( v20 >= *(unsigned int *)(a1 + 284) )
        goto LABEL_40;
    }
    v61 = printk(&unk_3FB93B, "ipa3_qmi_add_offload_request_send");
    v62 = ipa3_get_ipc_logbuf(v61);
    if ( v62 )
    {
      v63 = ipa3_get_ipc_logbuf(v62);
      v62 = ipc_log_string(
              v63,
              "ipa-wan %s:%d QMI error (%d)st-(%d) rule-id (%d)\n",
              "ipa3_qmi_add_offload_request_send",
              1085,
              v20,
              v23,
              v22[52]);
    }
    v64 = ipa3_get_ipc_logbuf_low(v62);
    if ( v64 )
    {
      v65 = ipa3_get_ipc_logbuf_low(v64);
      ipc_log_string(
        v65,
        "ipa-wan %s:%d QMI error (%d)st-(%d) rule-id (%d)\n",
        "ipa3_qmi_add_offload_request_send",
        1085,
        v20,
        v23,
        v22[52]);
    }
LABEL_54:
    mutex_unlock(&ipa3_qmi_lock);
    goto LABEL_48;
  }
LABEL_40:
  v26 = mutex_unlock(&ipa3_qmi_lock);
  v27 = ipa3_get_ipc_logbuf(v26);
  if ( v27 )
  {
    v28 = ipa3_get_ipc_logbuf(v27);
    v27 = ipc_log_string(
            v28,
            "ipa-wan %s:%d Update cached conntrack entries (%d)\n",
            "ipa3_qmi_add_offload_request_send",
            1114,
            *(_DWORD *)(ipa3_qmi_ctx + 28888));
  }
  result = ipa3_get_ipc_logbuf_low(v27);
  if ( result )
  {
    v30 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(
      v30,
      "ipa-wan %s:%d Update cached conntrack entries (%d)\n",
      "ipa3_qmi_add_offload_request_send",
      1114,
      *(_DWORD *)(ipa3_qmi_ctx + 28888));
    result = 0;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
