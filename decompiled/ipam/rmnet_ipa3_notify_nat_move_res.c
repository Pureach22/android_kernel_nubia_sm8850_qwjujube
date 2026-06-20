__int64 __fastcall rmnet_ipa3_notify_nat_move_res(__int64 a1)
{
  char v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w19
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v3,
                   "ipa-wan %s:%d send nat table move indication to modem (%d)\n",
                   "rmnet_ipa3_notify_nat_move_res",
                   1559,
                   v1 & 1);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v5,
                       "ipa-wan %s:%d send nat table move indication to modem (%d)\n",
                       "rmnet_ipa3_notify_nat_move_res",
                       1559,
                       v1 & 1);
  }
  if ( nat_move_qmi_disabled == 1 )
  {
    v6 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
    if ( v6 )
    {
      v7 = ipa3_get_ipc_logbuf(v6);
      v6 = ipc_log_string(
             v7,
             "ipa-wan %s:%d not sending nat table move indication, nat_move_qmi_disabled is true",
             "rmnet_ipa3_notify_nat_move_res",
             1564);
    }
    v8 = ipa3_get_ipc_logbuf_low(v6);
    if ( v8 )
    {
      v9 = ipa3_get_ipc_logbuf_low(v8);
      ipc_log_string(
        v9,
        "ipa-wan %s:%d not sending nat table move indication, nat_move_qmi_disabled is true",
        "rmnet_ipa3_notify_nat_move_res",
        1564);
    }
LABEL_16:
    v15 = 0;
    goto LABEL_17;
  }
  v27 = v1 & 1;
  if ( ipa3_svc_handle )
  {
    v10 = qmi_send_indication(
            ipa3_svc_handle,
            ipa3_qmi_ctx + 28864,
            70,
            7,
            &ipa_move_nat_table_complt_ind_msg_v01_ei,
            &v27);
    if ( !(_DWORD)v10 )
    {
      v11 = ipa3_get_ipc_logbuf(v10);
      if ( v11 )
      {
        v12 = ipa3_get_ipc_logbuf(v11);
        v11 = ipc_log_string(
                v12,
                "ipa-wan %s:%d qmi indication sent succesfully\n",
                "rmnet_ipa3_notify_nat_move_res",
                1590);
      }
      v13 = ipa3_get_ipc_logbuf_low(v11);
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf_low(v13);
        ipc_log_string(v14, "ipa-wan %s:%d qmi indication sent succesfully\n", "rmnet_ipa3_notify_nat_move_res", 1590);
      }
      goto LABEL_16;
    }
    v15 = v10;
    v17 = printk(&unk_3A3ED1, "rmnet_ipa3_notify_nat_move_res");
    v18 = ipa3_get_ipc_logbuf(v17);
    if ( v18 )
    {
      v19 = ipa3_get_ipc_logbuf(v18);
      v18 = ipc_log_string(
              v19,
              "ipa-wan %s:%d qmi indication not succesfull %d\n",
              "rmnet_ipa3_notify_nat_move_res",
              1588,
              v15);
    }
    v20 = ipa3_get_ipc_logbuf_low(v18);
    if ( v20 )
    {
      v21 = ipa3_get_ipc_logbuf_low(v20);
      ipc_log_string(
        v21,
        "ipa-wan %s:%d qmi indication not succesfull %d\n",
        "rmnet_ipa3_notify_nat_move_res",
        1588,
        v15);
    }
  }
  else
  {
    v22 = printk(&unk_3A728D, "rmnet_ipa3_notify_nat_move_res");
    v23 = ipa3_get_ipc_logbuf(v22);
    if ( v23 )
    {
      v24 = ipa3_get_ipc_logbuf(v23);
      v23 = ipc_log_string(
              v24,
              "ipa-wan %s:%d Invalid svc handle.Ignore sending ind.\n",
              "rmnet_ipa3_notify_nat_move_res",
              1577);
    }
    v25 = ipa3_get_ipc_logbuf_low(v23);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf_low(v25);
      ipc_log_string(
        v26,
        "ipa-wan %s:%d Invalid svc handle.Ignore sending ind.\n",
        "rmnet_ipa3_notify_nat_move_res",
        1577);
    }
    v15 = -14;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v15;
}
