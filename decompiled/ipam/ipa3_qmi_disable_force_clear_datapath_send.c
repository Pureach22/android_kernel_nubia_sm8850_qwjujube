__int64 __fastcall ipa3_qmi_disable_force_clear_datapath_send(__int64 a1)
{
  __int64 type; // x0
  __int64 ipc_logbuf; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w19
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
  _QWORD v24[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-20h] BYREF
  int v26; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    type = ipa3_ctx_get_type(2);
    if ( (_DWORD)type == 1 || (type = ipa3_ctx_get_type(2), (_DWORD)type == 3) )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf(type);
      if ( ipc_logbuf )
      {
        v4 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v4,
                       "ipa-wan %s:%d Simulating success on emu/virt mode\n",
                       "ipa3_qmi_disable_force_clear_datapath_send",
                       1405);
      }
      result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( result )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(
          ipc_logbuf_low,
          "ipa-wan %s:%d Simulating success on emu/virt mode\n",
          "ipa3_qmi_disable_force_clear_datapath_send",
          1405);
        result = 0;
      }
    }
    else
    {
      v25[0] = 0x700000026LL;
      v25[1] = &ipa3_disable_force_clear_datapath_req_msg_data_v01_ei;
      v24[1] = &ipa3_disable_force_clear_datapath_resp_msg_data_v01_ei;
      v26 = 0;
      v24[0] = 0x700000026LL;
      if ( ipa_q6_clnt )
      {
        v7 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v25, a1, (__int64)v24, (__int64)&v26, 0x3E8u);
        if ( (v7 & 0x80000000) != 0 )
        {
          v13 = v7;
          v14 = printk(&unk_3EF59E, "ipa3_qmi_disable_force_clear_datapath_send");
          v15 = ipa3_get_ipc_logbuf(v14);
          if ( v15 )
          {
            v16 = ipa3_get_ipc_logbuf(v15);
            v15 = ipc_log_string(
                    v16,
                    "ipa-wan %s:%d send Req %d failed, rc= %d\n",
                    "ipa3_qmi_disable_force_clear_datapath_send",
                    1431,
                    38,
                    v13);
          }
          v17 = ipa3_get_ipc_logbuf_low(v15);
          if ( v17 )
          {
            v18 = ipa3_get_ipc_logbuf_low(v17);
            ipc_log_string(
              v18,
              "ipa-wan %s:%d send Req %d failed, rc= %d\n",
              "ipa3_qmi_disable_force_clear_datapath_send",
              1431,
              38,
              v13);
          }
          result = v13;
        }
        else if ( (_WORD)v26 )
        {
          v19 = printk(&unk_3F86EF, "ipa3_qmi_disable_force_clear_datapath_send");
          v20 = ipa3_get_ipc_logbuf(v19);
          if ( v20 )
          {
            v21 = ipa3_get_ipc_logbuf(v20);
            v20 = ipc_log_string(
                    v21,
                    "ipa-wan %s:%d filter_notify failed %d\n",
                    "ipa3_qmi_disable_force_clear_datapath_send",
                    1437,
                    (unsigned __int16)v26);
          }
          v22 = ipa3_get_ipc_logbuf_low(v20);
          if ( v22 )
          {
            v23 = ipa3_get_ipc_logbuf_low(v22);
            ipc_log_string(
              v23,
              "ipa-wan %s:%d filter_notify failed %d\n",
              "ipa3_qmi_disable_force_clear_datapath_send",
              1437,
              (unsigned __int16)v26);
          }
          result = (unsigned __int16)v26;
        }
        else
        {
          result = ipa3_check_qmi_response(v7, 38, 0, HIWORD(v26), "ipa_disable_force_clear_datapath");
        }
      }
      else
      {
        result = 4294967186LL;
      }
    }
  }
  else
  {
    v8 = printk(&unk_3E9D9C, "ipa3_qmi_disable_force_clear_datapath_send");
    v9 = ipa3_get_ipc_logbuf(v8);
    if ( v9 )
    {
      v10 = ipa3_get_ipc_logbuf(v9);
      v9 = ipc_log_string(v10, "ipa-wan %s:%d invalid params\n", "ipa3_qmi_disable_force_clear_datapath_send", 1399);
    }
    v11 = ipa3_get_ipc_logbuf_low(v9);
    if ( v11 )
    {
      v12 = ipa3_get_ipc_logbuf_low(v11);
      ipc_log_string(v12, "ipa-wan %s:%d invalid params\n", "ipa3_qmi_disable_force_clear_datapath_send", 1399);
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
