__int64 __fastcall ipa3_handle_mhi_vote_req(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 is_apq; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w3
  int v18; // w24
  int v19; // w22
  int v20; // w23
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x7
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 result; // x0
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
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v54[0]) = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v9,
                   "ipa-wan %s:%d Received QMI_IPA_MHI_CLK_VOTE_REQ_V01(%d)\n",
                   "ipa3_handle_mhi_vote_req",
                   358,
                   *a4);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v11,
                       "ipa-wan %s:%d Received QMI_IPA_MHI_CLK_VOTE_REQ_V01(%d)\n",
                       "ipa3_handle_mhi_vote_req",
                       358,
                       *a4);
  }
  HIDWORD(v54[0]) = 0;
  is_apq = ipa3_is_apq(ipc_logbuf_low);
  if ( (is_apq & 1) != 0 )
  {
    v13 = ipa3_get_ipc_logbuf(is_apq);
    if ( v13 )
    {
      v14 = ipa3_get_ipc_logbuf(v13);
      v13 = ipc_log_string(
              v14,
              "ipa-wan %s:%d Throughput(%d:%d) clk-rate(%d:%d)\n",
              "ipa3_handle_mhi_vote_req",
              368,
              a4[1],
              *((_DWORD *)a4 + 1),
              a4[8],
              *((_DWORD *)a4 + 3));
    }
    v15 = ipa3_get_ipc_logbuf_low(v13);
    if ( v15 )
    {
      v16 = ipa3_get_ipc_logbuf_low(v15);
      ipc_log_string(
        v16,
        "ipa-wan %s:%d Throughput(%d:%d) clk-rate(%d:%d)\n",
        "ipa3_handle_mhi_vote_req",
        368,
        a4[1],
        *((_DWORD *)a4 + 1),
        a4[8],
        *((_DWORD *)a4 + 3));
    }
    if ( a4[8] )
    {
      v17 = *((_DWORD *)a4 + 3);
      if ( v17 > 2 )
      {
        if ( v17 == 3 )
        {
          v18 = 690;
          goto LABEL_20;
        }
        if ( v17 == 4 )
        {
          v18 = 1200;
          goto LABEL_20;
        }
      }
      else
      {
        if ( v17 == 1 )
        {
          v19 = 0;
          v20 = 0;
          LODWORD(v54[0]) = 0;
          goto LABEL_21;
        }
        if ( v17 == 2 )
        {
          v18 = 350;
LABEL_20:
          v19 = 0;
          v20 = 0;
          LODWORD(v54[0]) = v18;
          goto LABEL_21;
        }
      }
      v49 = printk(&unk_3D0185, "ipa3_handle_mhi_vote_req");
      v50 = ipa3_get_ipc_logbuf(v49);
      if ( v50 )
      {
        v51 = ipa3_get_ipc_logbuf(v50);
        v50 = ipc_log_string(
                v51,
                "ipa-wan %s:%d Note supported clk_rate (%d)\n",
                "ipa3_handle_mhi_vote_req",
                385,
                *((_DWORD *)a4 + 3));
      }
      v52 = ipa3_get_ipc_logbuf_low(v50);
      if ( v52 )
      {
        v53 = ipa3_get_ipc_logbuf_low(v52);
        ipc_log_string(
          v53,
          "ipa-wan %s:%d Note supported clk_rate (%d)\n",
          "ipa3_handle_mhi_vote_req",
          385,
          *((_DWORD *)a4 + 3));
      }
      v20 = 1;
      v19 = 94;
      v54[0] = 0x5E000100000000LL;
LABEL_21:
      v21 = ipa3_vote_for_bus_bw((unsigned int *)v54);
      if ( (_DWORD)v21 )
      {
        v40 = printk(&unk_3BB83F, "ipa3_handle_mhi_vote_req");
        v41 = ipa3_get_ipc_logbuf(v40);
        if ( v41 )
        {
          v42 = ipa3_get_ipc_logbuf(v41);
          v41 = ipc_log_string(
                  v42,
                  "ipa-wan %s:%d Failed to vote BW (%u)\n",
                  "ipa3_handle_mhi_vote_req",
                  393,
                  LODWORD(v54[0]));
        }
        v43 = ipa3_get_ipc_logbuf_low(v41);
        if ( v43 )
        {
          v44 = ipa3_get_ipc_logbuf_low(v43);
          v43 = ipc_log_string(
                  v44,
                  "ipa-wan %s:%d Failed to vote BW (%u)\n",
                  "ipa3_handle_mhi_vote_req",
                  393,
                  LODWORD(v54[0]));
        }
        v20 = 1;
        v19 = 94;
        HIDWORD(v54[0]) = 6160385;
        v22 = ipa3_get_ipc_logbuf(v43);
        if ( !v22 )
          goto LABEL_24;
      }
      else
      {
        v22 = ipa3_get_ipc_logbuf(v21);
        if ( !v22 )
        {
LABEL_24:
          v24 = ipa3_get_ipc_logbuf_low(v22);
          if ( v24 )
          {
            v26 = ipa3_get_ipc_logbuf_low(v24);
            ipc_log_string(
              v26,
              "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
              "ipa3_handle_mhi_vote_req",
              413,
              v20,
              v19);
          }
          v27 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
                  a1,
                  a2,
                  a3,
                  59,
                  7,
                  &ipa_mhi_clk_vote_resp_msg_v01_ei,
                  (char *)v54 + 4,
                  v25,
                  v54[0]);
          if ( (v27 & 0x80000000) != 0 )
          {
            v45 = printk(&unk_3D60CB, "ipa3_handle_mhi_vote_req");
            v46 = ipa3_get_ipc_logbuf(v45);
            if ( v46 )
            {
              v47 = ipa3_get_ipc_logbuf(v46);
              v46 = ipc_log_string(
                      v47,
                      "ipa-wan %s:%d QMI_IPA_MHI_CLK_VOTE_RESP_V01 failed\n",
                      "ipa3_handle_mhi_vote_req",
                      421);
            }
            result = ipa3_get_ipc_logbuf_low(v46);
            if ( result )
            {
              v48 = ipa3_get_ipc_logbuf_low(result);
              result = ipc_log_string(
                         v48,
                         "ipa-wan %s:%d QMI_IPA_MHI_CLK_VOTE_RESP_V01 failed\n",
                         "ipa3_handle_mhi_vote_req",
                         421);
            }
          }
          else
          {
            v28 = ipa3_get_ipc_logbuf(v27);
            if ( v28 )
            {
              v29 = ipa3_get_ipc_logbuf(v28);
              v28 = ipc_log_string(
                      v29,
                      "ipa-wan %s:%d Finished senting QMI_IPA_MHI_CLK_VOTE_RESP_V01\n",
                      "ipa3_handle_mhi_vote_req",
                      423);
            }
            result = ipa3_get_ipc_logbuf_low(v28);
            if ( result )
            {
              v31 = ipa3_get_ipc_logbuf_low(result);
              result = ipc_log_string(
                         v31,
                         "ipa-wan %s:%d Finished senting QMI_IPA_MHI_CLK_VOTE_RESP_V01\n",
                         "ipa3_handle_mhi_vote_req",
                         423);
            }
          }
          goto LABEL_31;
        }
      }
      v23 = ipa3_get_ipc_logbuf(v22);
      v22 = ipc_log_string(
              v23,
              "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
              "ipa3_handle_mhi_vote_req",
              413,
              v20,
              v19);
      goto LABEL_24;
    }
    v36 = printk(&unk_3B2A5C, "ipa3_handle_mhi_vote_req");
    v37 = ipa3_get_ipc_logbuf(v36);
    if ( v37 )
    {
      v38 = ipa3_get_ipc_logbuf(v37);
      v37 = ipc_log_string(v38, "ipa-wan %s:%d clk_rate_valid is false\n", "ipa3_handle_mhi_vote_req", 400);
    }
    result = ipa3_get_ipc_logbuf_low(v37);
    if ( result )
    {
      v39 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v39, "ipa-wan %s:%d clk_rate_valid is false\n", "ipa3_handle_mhi_vote_req", 400);
    }
  }
  else
  {
    v32 = printk(&unk_3D3496, "ipa3_handle_mhi_vote_req");
    v33 = ipa3_get_ipc_logbuf(v32);
    if ( v33 )
    {
      v34 = ipa3_get_ipc_logbuf(v33);
      v33 = ipc_log_string(v34, "ipa-wan %s:%d imp handle vote req fails\n", "ipa3_handle_mhi_vote_req", 406);
    }
    result = ipa3_get_ipc_logbuf_low(v33);
    if ( result )
    {
      v35 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v35, "ipa-wan %s:%d imp handle vote req fails\n", "ipa3_handle_mhi_vote_req", 406);
    }
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
