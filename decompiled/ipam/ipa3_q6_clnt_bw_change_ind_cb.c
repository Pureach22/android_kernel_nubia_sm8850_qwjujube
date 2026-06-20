__int64 __fastcall ipa3_q6_clnt_bw_change_ind_cb(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 ipc_logbuf; // x0
  __int64 v6; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w20
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
  unsigned int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( ipa_q6_clnt == a1 )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf(a1);
    if ( ipc_logbuf )
    {
      v6 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v6,
                     "ipa-wan %s:%d Q6 BW change UL valid(%d):(%d)Kbps\n",
                     "ipa3_q6_clnt_bw_change_ind_cb",
                     1668,
                     *a4,
                     *((_DWORD *)a4 + 1));
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v8 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_logbuf_low = ipc_log_string(
                         v8,
                         "ipa-wan %s:%d Q6 BW change UL valid(%d):(%d)Kbps\n",
                         "ipa3_q6_clnt_bw_change_ind_cb",
                         1668,
                         *a4,
                         *((_DWORD *)a4 + 1));
    }
    v9 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
    if ( v9 )
    {
      v10 = ipa3_get_ipc_logbuf(v9);
      v9 = ipc_log_string(
             v10,
             "ipa-wan %s:%d Q6 BW change DL valid(%d):(%d)Kbps\n",
             "ipa3_q6_clnt_bw_change_ind_cb",
             1672,
             a4[1],
             *((_DWORD *)a4 + 2));
    }
    v11 = ipa3_get_ipc_logbuf_low(v9);
    if ( v11 )
    {
      v12 = ipa3_get_ipc_logbuf_low(v11);
      v11 = ipc_log_string(
              v12,
              "ipa-wan %s:%d Q6 BW change DL valid(%d):(%d)Kbps\n",
              "ipa3_q6_clnt_bw_change_ind_cb",
              1672,
              a4[1],
              *((_DWORD *)a4 + 2));
    }
    if ( *a4 )
    {
      v13 = *((_DWORD *)a4 + 1) / 0x3E8u;
      v27 = v13;
      if ( !a4[1] )
      {
LABEL_13:
        v14 = ipa3_get_ipc_logbuf(v11);
        if ( v14 )
        {
          v15 = ipa3_get_ipc_logbuf(v14);
          v14 = ipc_log_string(v15, "ipa-wan %s:%d vote modem BW (%u)\n", "ipa3_q6_clnt_bw_change_ind_cb", 1680, v13);
        }
        v16 = ipa3_get_ipc_logbuf_low(v14);
        if ( v16 )
        {
          v17 = ipa3_get_ipc_logbuf_low(v16);
          ipc_log_string(v17, "ipa-wan %s:%d vote modem BW (%u)\n", "ipa3_q6_clnt_bw_change_ind_cb", 1680, v13);
        }
        result = ipa3_vote_for_bus_bw(&v27);
        if ( (_DWORD)result )
        {
          v23 = printk(&unk_3BB83F, "ipa3_q6_clnt_bw_change_ind_cb");
          v24 = ipa3_get_ipc_logbuf(v23);
          if ( v24 )
          {
            v25 = ipa3_get_ipc_logbuf(v24);
            v24 = ipc_log_string(
                    v25,
                    "ipa-wan %s:%d Failed to vote BW (%u)\n",
                    "ipa3_q6_clnt_bw_change_ind_cb",
                    1682,
                    v27);
          }
          result = ipa3_get_ipc_logbuf_low(v24);
          if ( result )
          {
            v26 = ipa3_get_ipc_logbuf_low(result);
            result = ipc_log_string(
                       v26,
                       "ipa-wan %s:%d Failed to vote BW (%u)\n",
                       "ipa3_q6_clnt_bw_change_ind_cb",
                       1682,
                       v27);
          }
        }
        goto LABEL_18;
      }
    }
    else
    {
      v13 = 0;
      if ( !a4[1] )
        goto LABEL_13;
    }
    v13 += *((_DWORD *)a4 + 2) / 0x3E8u;
    v27 = v13;
    goto LABEL_13;
  }
  v19 = printk(&unk_3D01E5, "ipa3_q6_clnt_bw_change_ind_cb");
  v20 = ipa3_get_ipc_logbuf(v19);
  if ( v20 )
  {
    v21 = ipa3_get_ipc_logbuf(v20);
    v20 = ipc_log_string(v21, "ipa-wan %s:%d Wrong client\n", "ipa3_q6_clnt_bw_change_ind_cb", 1660);
  }
  result = ipa3_get_ipc_logbuf_low(v20);
  if ( result )
  {
    v22 = ipa3_get_ipc_logbuf_low(result);
    result = ipc_log_string(v22, "ipa-wan %s:%d Wrong client\n", "ipa3_q6_clnt_bw_change_ind_cb", 1660);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
