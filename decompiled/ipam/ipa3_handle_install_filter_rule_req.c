__int64 __fastcall ipa3_handle_install_filter_rule_req(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  void *v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w8
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  __int64 v18; // x11
  _DWORD *v19; // x11
  int *v20; // x12
  unsigned __int64 v21; // x13
  int v22; // w14
  int v23; // w15
  int *v24; // x11
  int v25; // t1
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x7
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 result; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
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
  _QWORD v53[100]; // [xsp+0h] [xbp-320h] BYREF

  v53[99] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = memset((char *)v53 + 4, 0, 0x314u);
  ipc_logbuf = ipa3_get_ipc_logbuf(v8);
  if ( ipc_logbuf )
  {
    v10 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v10,
                   "ipa-wan %s:%d Received install filter Request\n",
                   "ipa3_handle_install_filter_rule_req",
                   166);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v12 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v12, "ipa-wan %s:%d Received install filter Request\n", "ipa3_handle_install_filter_rule_req", 166);
  }
  v13 = ipa3_copy_ul_filter_rule_to_ipa(a4);
  if ( !(_DWORD)v13 )
  {
    WORD2(v53[0]) = 0;
    if ( *(_BYTE *)(a4 + 13864) == 1 )
    {
      v14 = *(_DWORD *)(a4 + 13868);
      LOBYTE(v53[66]) = 1;
      if ( v14 >= 0x24 )
      {
        HIDWORD(v53[66]) = 35;
        v44 = printk(&unk_3F58C4, "ipa3_handle_install_filter_rule_req");
        v45 = ipa3_get_ipc_logbuf(v44);
        if ( v45 )
        {
          v46 = ipa3_get_ipc_logbuf(v45);
          v45 = ipc_log_string(
                  v46,
                  "ipa-wan %s:%d installed (%d) max Q6-UL rules ",
                  "ipa3_handle_install_filter_rule_req",
                  182,
                  35);
        }
        v47 = ipa3_get_ipc_logbuf_low(v45);
        if ( v47 )
        {
          v48 = ipa3_get_ipc_logbuf_low(v47);
          ipc_log_string(
            v48,
            "ipa-wan %s:%d installed (%d) max Q6-UL rules ",
            "ipa3_handle_install_filter_rule_req",
            182,
            35);
        }
        v49 = printk(&unk_3B8863, "ipa3_handle_install_filter_rule_req");
        v50 = ipa3_get_ipc_logbuf(v49);
        if ( v50 )
        {
          v51 = ipa3_get_ipc_logbuf(v50);
          v50 = ipc_log_string(
                  v51,
                  "ipa-wan %s:%d but modem gives total (%u)\n",
                  "ipa3_handle_install_filter_rule_req",
                  184,
                  *(_DWORD *)(a4 + 13868));
        }
        v13 = ipa3_get_ipc_logbuf_low(v50);
        if ( v13 )
        {
          v52 = ipa3_get_ipc_logbuf_low(v13);
          v13 = ipc_log_string(
                  v52,
                  "ipa-wan %s:%d but modem gives total (%u)\n",
                  "ipa3_handle_install_filter_rule_req",
                  184,
                  *(_DWORD *)(a4 + 13868));
        }
        v14 = 35;
LABEL_9:
        if ( v14 >= 3 )
        {
          v16 = v14 - 1LL;
          if ( v16 >= 0x40 )
            v16 = 64;
          v17 = v16 + 1;
          v18 = v17 & 1;
          if ( (v17 & 1) == 0 )
            v18 = 2;
          v15 = v17 - v18;
          v19 = (_DWORD *)&v53[67] + 1;
          v20 = (int *)(a4 + 14296);
          v21 = v15;
          do
          {
            v22 = *(v20 - 54);
            v23 = *v20;
            v21 -= 2LL;
            v20 += 108;
            *(v19 - 1) = v22;
            *v19 = v23;
            v19 += 2;
          }
          while ( v21 );
        }
        else
        {
          v15 = 0;
        }
        v24 = (int *)(a4 + 216 * v15 + 14080);
        do
        {
          if ( v15 == 64 )
          {
            __break(0x5512u);
LABEL_50:
            __break(1u);
          }
          if ( (v15 & 0x3FFFFFFFFFFFFFFFLL) == 0x40 )
            goto LABEL_50;
          v25 = *v24;
          v24 += 54;
          *((_DWORD *)&v53[67] + v15++) = v25;
        }
        while ( v14 != v15 );
        goto LABEL_22;
      }
      HIDWORD(v53[66]) = v14;
      if ( v14 )
        goto LABEL_9;
    }
    else
    {
      LOBYTE(v53[66]) = 0;
      HIDWORD(v53[66]) = 0;
    }
LABEL_22:
    v26 = ipa3_get_ipc_logbuf(v13);
    if ( v26 )
    {
      v27 = ipa3_get_ipc_logbuf(v26);
      v26 = ipc_log_string(
              v27,
              "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
              "ipa3_handle_install_filter_rule_req",
              201,
              WORD2(v53[0]),
              HIWORD(v53[0]));
    }
    v28 = ipa3_get_ipc_logbuf_low(v26);
    if ( v28 )
    {
      v30 = ipa3_get_ipc_logbuf_low(v28);
      ipc_log_string(
        v30,
        "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
        "ipa3_handle_install_filter_rule_req",
        201,
        WORD2(v53[0]),
        HIWORD(v53[0]));
    }
    v31 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
            a1,
            a2,
            a3,
            35,
            783,
            &ipa3_install_fltr_rule_resp_msg_data_v01_ei,
            (char *)v53 + 4,
            v29,
            v53[0]);
    if ( (v31 & 0x80000000) != 0 )
    {
      v40 = printk(&unk_3FE5F0, "ipa3_handle_install_filter_rule_req");
      v41 = ipa3_get_ipc_logbuf(v40);
      if ( v41 )
      {
        v42 = ipa3_get_ipc_logbuf(v41);
        v41 = ipc_log_string(
                v42,
                "ipa-wan %s:%d install filter rules failed\n",
                "ipa3_handle_install_filter_rule_req",
                209);
      }
      result = ipa3_get_ipc_logbuf_low(v41);
      if ( result )
      {
        v43 = ipa3_get_ipc_logbuf_low(result);
        result = ipc_log_string(
                   v43,
                   "ipa-wan %s:%d install filter rules failed\n",
                   "ipa3_handle_install_filter_rule_req",
                   209);
      }
    }
    else
    {
      v32 = ipa3_get_ipc_logbuf(v31);
      if ( v32 )
      {
        v33 = ipa3_get_ipc_logbuf(v32);
        v32 = ipc_log_string(
                v33,
                "ipa-wan %s:%d Replied to install filter request\n",
                "ipa3_handle_install_filter_rule_req",
                211);
      }
      result = ipa3_get_ipc_logbuf_low(v32);
      if ( result )
      {
        v35 = ipa3_get_ipc_logbuf_low(result);
        result = ipc_log_string(
                   v35,
                   "ipa-wan %s:%d Replied to install filter request\n",
                   "ipa3_handle_install_filter_rule_req",
                   211);
      }
    }
    goto LABEL_31;
  }
  v36 = printk(&unk_3BB80B, "ipa3_handle_install_filter_rule_req");
  v37 = ipa3_get_ipc_logbuf(v36);
  if ( v37 )
  {
    v38 = ipa3_get_ipc_logbuf(v37);
    v37 = ipc_log_string(
            v38,
            "ipa-wan %s:%d copy UL rules from modem is failed\n",
            "ipa3_handle_install_filter_rule_req",
            172);
  }
  result = ipa3_get_ipc_logbuf_low(v37);
  if ( result )
  {
    v39 = ipa3_get_ipc_logbuf_low(result);
    result = ipc_log_string(
               v39,
               "ipa-wan %s:%d copy UL rules from modem is failed\n",
               "ipa3_handle_install_filter_rule_req",
               172);
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
