__int64 __fastcall ipa3_qmi_filter_request_ex_send(char *a1)
{
  _QWORD *v1; // x22
  void *v3; // x0
  int v4; // w20
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned __int8 *v20; // x20
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
  __int64 v37; // x8
  __int64 v38; // x9
  char *v39; // x10
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x9
  __int64 v45; // x23
  __int64 v46; // x8
  __int64 v47; // x8
  int v48; // w9
  __int64 v49; // x0
  unsigned int v50; // w20
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  unsigned int v55; // w0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  unsigned int v64; // w19
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v71; // x24
  __int64 v72; // [xsp+8h] [xbp-238h] BYREF
  void *v73; // [xsp+10h] [xbp-230h]
  __int64 v74; // [xsp+18h] [xbp-228h] BYREF
  void *v75; // [xsp+20h] [xbp-220h]
  _WORD s[262]; // [xsp+2Ch] [xbp-214h] BYREF
  __int64 v77; // [xsp+238h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = memset(s, 0, sizeof(s));
  v74 = 0;
  v75 = nullptr;
  v72 = 0;
  v73 = nullptr;
  if ( ipa3_qmi_indication_fin != 1 || ipa3_qmi_modem_init_fin != 1 || !ipa_q6_clnt )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf(v3);
    if ( ipc_logbuf )
    {
      v10 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v10,
                     "ipa-wan %s:%d modem QMI haven't up yet\n",
                     "ipa3_qmi_filter_request_ex_send",
                     852);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v12 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v12, "ipa-wan %s:%d modem QMI haven't up yet\n", "ipa3_qmi_filter_request_ex_send", 852);
    }
    goto LABEL_13;
  }
  v4 = *((_DWORD *)a1 + 1);
  v5 = ipa3_get_ipc_logbuf(v3);
  if ( v4 )
  {
    if ( v5 )
    {
      v6 = ipa3_get_ipc_logbuf(v5);
      v5 = ipc_log_string(
             v6,
             "ipa-wan %s:%d IPACM pass %u rule to Q6\n",
             "ipa3_qmi_filter_request_ex_send",
             861,
             *((_DWORD *)a1 + 1));
    }
    v7 = ipa3_get_ipc_logbuf_low(v5);
    if ( v7 )
    {
      v8 = ipa3_get_ipc_logbuf_low(v7);
      v7 = ipc_log_string(
             v8,
             "ipa-wan %s:%d IPACM pass %u rule to Q6\n",
             "ipa3_qmi_filter_request_ex_send",
             861,
             *((_DWORD *)a1 + 1));
    }
  }
  else
  {
    if ( v5 )
    {
      v14 = ipa3_get_ipc_logbuf(v5);
      v5 = ipc_log_string(v14, "ipa-wan %s:%d IPACM pass zero rules to Q6\n", "ipa3_qmi_filter_request_ex_send", 858);
    }
    v7 = ipa3_get_ipc_logbuf_low(v5);
    if ( v7 )
    {
      v15 = ipa3_get_ipc_logbuf_low(v7);
      v7 = ipc_log_string(v15, "ipa-wan %s:%d IPACM pass zero rules to Q6\n", "ipa3_qmi_filter_request_ex_send", 858);
    }
  }
  if ( *a1 && *((_DWORD *)a1 + 1) >= 0x81u )
  {
    v16 = ipa3_get_ipc_logbuf(v7);
    if ( v16 )
    {
      v17 = ipa3_get_ipc_logbuf(v16);
      v16 = ipc_log_string(
              v17,
              "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
              "ipa3_qmi_filter_request_ex_send",
              866);
    }
    v18 = ipa3_get_ipc_logbuf_low(v16);
    if ( v18 )
    {
      v19 = ipa3_get_ipc_logbuf_low(v18);
      ipc_log_string(
        v19,
        "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
        "ipa3_qmi_filter_request_ex_send",
        866);
    }
    goto LABEL_13;
  }
  v20 = (unsigned __int8 *)(a1 + 27656);
  if ( a1[27656] )
  {
    v21 = ipa3_get_ipc_logbuf(v7);
    if ( v21 )
    {
      v22 = ipa3_get_ipc_logbuf(v21);
      v21 = ipc_log_string(
              v22,
              "ipa-wan %s:%d IPACM passes source_pipe_index_valid not zero 0 !=%d\n",
              "ipa3_qmi_filter_request_ex_send",
              871,
              *v20);
    }
    v23 = ipa3_get_ipc_logbuf_low(v21);
    if ( v23 )
    {
      v24 = ipa3_get_ipc_logbuf_low(v23);
      ipc_log_string(
        v24,
        "ipa-wan %s:%d IPACM passes source_pipe_index_valid not zero 0 !=%d\n",
        "ipa3_qmi_filter_request_ex_send",
        871,
        *v20);
    }
    goto LABEL_13;
  }
  if ( a1[27680] && *((_DWORD *)a1 + 6921) >= 0x81u )
  {
    v25 = ipa3_get_ipc_logbuf(v7);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf(v25);
      v25 = ipc_log_string(
              v26,
              "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
              "ipa3_qmi_filter_request_ex_send",
              878);
    }
    v27 = ipa3_get_ipc_logbuf_low(v25);
    if ( v27 )
    {
      v28 = ipa3_get_ipc_logbuf_low(v27);
      ipc_log_string(
        v28,
        "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
        "ipa3_qmi_filter_request_ex_send",
        878);
    }
    goto LABEL_13;
  }
  if ( a1[28200] && *((_DWORD *)a1 + 7051) >= 0x41u )
  {
    v29 = ipa3_get_ipc_logbuf(v7);
    if ( v29 )
    {
      v30 = ipa3_get_ipc_logbuf(v29);
      v29 = ipc_log_string(
              v30,
              "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
              "ipa3_qmi_filter_request_ex_send",
              884);
    }
    v31 = ipa3_get_ipc_logbuf_low(v29);
    if ( v31 )
    {
      v32 = ipa3_get_ipc_logbuf_low(v31);
      ipc_log_string(
        v32,
        "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
        "ipa3_qmi_filter_request_ex_send",
        884);
    }
    goto LABEL_13;
  }
  if ( a1[42032] && *((_DWORD *)a1 + 10509) >= 0x41u )
  {
    v33 = ipa3_get_ipc_logbuf(v7);
    if ( v33 )
    {
      v34 = ipa3_get_ipc_logbuf(v33);
      v33 = ipc_log_string(
              v34,
              "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
              "ipa3_qmi_filter_request_ex_send",
              890);
    }
    v35 = ipa3_get_ipc_logbuf_low(v33);
    if ( v35 )
    {
      v36 = ipa3_get_ipc_logbuf_low(v35);
      ipc_log_string(
        v36,
        "ipa-wan %s:%d IPACM pass the number of filtering rules exceed limit\n",
        "ipa3_qmi_filter_request_ex_send",
        890);
    }
    goto LABEL_13;
  }
  v37 = *((unsigned int *)a1 + 1);
  if ( (_DWORD)v37 )
  {
    v38 = 0;
    v39 = a1 + 196;
    while ( 1 )
    {
      if ( v38 == 128 )
        goto LABEL_88;
      if ( (unsigned int)(*((_DWORD *)v39 - 47) - 1) > 1 || !v39[12] || (unsigned int)(*(_DWORD *)v39 - 5) < 0xFFFFFFFC )
        break;
      ++v38;
      v39 += 216;
      if ( v37 == v38 )
        goto LABEL_56;
    }
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
LABEL_56:
  mutex_lock(&ipa3_qmi_lock);
  v1 = &unk_200000;
  v40 = ipa3_qmi_ctx;
  if ( !ipa3_qmi_ctx )
    goto LABEL_68;
  v20 = (unsigned __int8 *)&unk_200000;
  if ( (ipa3_qmi_filter_request_ex_send_cache_filter_max_flag & 1) != 0 )
    goto LABEL_61;
  v41 = vmalloc_noprof(42296);
  while ( 1 )
  {
    v42 = v1[229];
    v43 = *(unsigned int *)(v42 + 7700);
    if ( (unsigned int)v43 > 9 )
      goto LABEL_88;
    *(_QWORD *)(v42 + 8 * v43 + 7704) = v41;
    v40 = v1[229];
LABEL_61:
    v44 = *(unsigned int *)(v40 + 7700);
    if ( (unsigned int)v44 > 9 )
      goto LABEL_88;
    if ( !*(_QWORD *)(v40 + 8 * v44 + 7704) )
      break;
    v45 = v1[229];
    v46 = *(unsigned int *)(v45 + 7700);
    if ( (unsigned int)v46 <= 9 )
    {
      memcpy(*(void **)(v45 + 8 * v46 + 7704), a1, 0xA538u);
      ++*(_DWORD *)(v45 + 7700);
      goto LABEL_65;
    }
LABEL_88:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v71 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipa3_qmi_filter_request_ex_send__alloc_tag;
    v41 = vmalloc_noprof(42296);
    *(_QWORD *)(StatusReg + 80) = v71;
  }
  v59 = printk(&unk_3FB90E, "ipa3_qmi_filter_request_ex_send");
  v60 = ipa3_get_ipc_logbuf(v59);
  if ( v60 )
  {
    v61 = ipa3_get_ipc_logbuf(v60);
    v60 = ipc_log_string(v61, "ipa-wan %s:%d  Memory Allocation  failed \n", "ipa3_qmi_filter_request_ex_send", 919);
  }
  v62 = ipa3_get_ipc_logbuf_low(v60);
  if ( v62 )
  {
    v63 = ipa3_get_ipc_logbuf_low(v62);
    ipc_log_string(v63, "ipa-wan %s:%d  Memory Allocation  failed \n", "ipa3_qmi_filter_request_ex_send", 919);
  }
LABEL_65:
  v47 = v1[229];
  v48 = *(_DWORD *)(v47 + 7700);
  if ( v48 == 10 )
    v20[1769] = 1;
  *(_DWORD *)(v47 + 7700) = v48 % 10;
LABEL_68:
  mutex_unlock(&ipa3_qmi_lock);
  v49 = ipa3_qmi_filter_request_ex_calc_length(a1);
  v50 = v49;
  HIDWORD(v74) = v49;
  v51 = ipa3_get_ipc_logbuf(v49);
  if ( (v50 & 0x80000000) != 0 )
  {
    if ( v51 )
    {
      v56 = ipa3_get_ipc_logbuf(v51);
      v51 = ipc_log_string(
              v56,
              "ipa-wan %s:%d QMI send request length = %d\n",
              "ipa3_qmi_filter_request_ex_send",
              937,
              v50);
    }
    v57 = ipa3_get_ipc_logbuf_low(v51);
    if ( v57 )
    {
      v58 = ipa3_get_ipc_logbuf_low(v57);
      ipc_log_string(v58, "ipa-wan %s:%d QMI send request length = %d\n", "ipa3_qmi_filter_request_ex_send", 937, v50);
    }
    goto LABEL_13;
  }
  if ( v51 )
  {
    v52 = ipa3_get_ipc_logbuf(v51);
    v51 = ipc_log_string(
            v52,
            "ipa-wan %s:%d QMI send request length = %d\n",
            "ipa3_qmi_filter_request_ex_send",
            941,
            v50);
  }
  v53 = ipa3_get_ipc_logbuf_low(v51);
  if ( v53 )
  {
    v54 = ipa3_get_ipc_logbuf_low(v53);
    ipc_log_string(v54, "ipa-wan %s:%d QMI send request length = %d\n", "ipa3_qmi_filter_request_ex_send", 941, v50);
  }
  LOWORD(v74) = 55;
  v75 = &ipa3_install_fltr_rule_req_ex_msg_data_v01_ei;
  memset(s, 0, sizeof(s));
  HIDWORD(v72) = 523;
  LOWORD(v72) = 55;
  v73 = &ipa3_install_fltr_rule_resp_ex_msg_data_v01_ei;
  v55 = ipa3_qmi_send_req_wait(ipa_q6_clnt, &v74, a1, &v72, s, 10000);
  if ( (v55 & 0x80000000) != 0 )
  {
    v64 = v55;
    v65 = printk(&unk_3CCE82, "ipa3_qmi_filter_request_ex_send");
    v66 = ipa3_get_ipc_logbuf(v65);
    if ( v66 )
    {
      v67 = ipa3_get_ipc_logbuf(v66);
      v66 = ipc_log_string(
              v67,
              "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
              "ipa3_qmi_filter_request_ex_send",
              961,
              55,
              v64);
    }
    v68 = ipa3_get_ipc_logbuf_low(v66);
    if ( v68 )
    {
      v69 = ipa3_get_ipc_logbuf_low(v68);
      ipc_log_string(
        v69,
        "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
        "ipa3_qmi_filter_request_ex_send",
        961,
        55,
        v64);
    }
    result = v64;
  }
  else
  {
    result = ipa3_check_qmi_response();
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
