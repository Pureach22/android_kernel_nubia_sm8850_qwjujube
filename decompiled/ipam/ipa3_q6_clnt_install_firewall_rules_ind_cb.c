__int64 __fastcall ipa3_q6_clnt_install_firewall_rules_ind_cb(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  int v4; // w19
  int v5; // w20
  __int64 ipc_logbuf; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0

  v5 = *a4;
  v4 = a4[1];
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v7 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v7,
                   "ipa-wan %s:%d UL firewall rules install indication on Q6",
                   "ipa3_q6_clnt_install_firewall_rules_ind_cb",
                   1637);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v9 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v9,
                       "ipa-wan %s:%d UL firewall rules install indication on Q6",
                       "ipa3_q6_clnt_install_firewall_rules_ind_cb",
                       1637);
  }
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      v18 = printk(&unk_3F5966, "ipa3_q6_clnt_install_firewall_rules_ind_cb");
      v19 = ipa3_get_ipc_logbuf(v18);
      if ( v19 )
      {
        v20 = ipa3_get_ipc_logbuf(v19);
        v19 = ipc_log_string(v20, "ipa-wan %s:%d : Failure\n", "ipa3_q6_clnt_install_firewall_rules_ind_cb", 1645);
      }
      result = ipa3_get_ipc_logbuf_low(v19);
      if ( result )
      {
        v21 = ipa3_get_ipc_logbuf_low(result);
        return ipc_log_string(v21, "ipa-wan %s:%d : Failure\n", "ipa3_q6_clnt_install_firewall_rules_ind_cb", 1645);
      }
    }
    else
    {
      v22 = printk(&unk_3E9E8C, "ipa3_q6_clnt_install_firewall_rules_ind_cb");
      v23 = ipa3_get_ipc_logbuf(v22);
      if ( v23 )
      {
        v24 = ipa3_get_ipc_logbuf(v23);
        v23 = ipc_log_string(
                v24,
                "ipa-wan %s:%d : Unexpected Result",
                "ipa3_q6_clnt_install_firewall_rules_ind_cb",
                1647);
      }
      result = ipa3_get_ipc_logbuf_low(v23);
      if ( result )
      {
        v25 = ipa3_get_ipc_logbuf_low(result);
        return ipc_log_string(
                 v25,
                 "ipa-wan %s:%d : Unexpected Result",
                 "ipa3_q6_clnt_install_firewall_rules_ind_cb",
                 1647);
      }
    }
  }
  else
  {
    v10 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf(v10);
      v10 = ipc_log_string(v11, "ipa-wan %s:%d  : Success\n", "ipa3_q6_clnt_install_firewall_rules_ind_cb", 1640);
    }
    v12 = ipa3_get_ipc_logbuf_low(v10);
    if ( v12 )
    {
      v13 = ipa3_get_ipc_logbuf_low(v12);
      v12 = ipc_log_string(v13, "ipa-wan %s:%d  : Success\n", "ipa3_q6_clnt_install_firewall_rules_ind_cb", 1640);
    }
    v14 = ipa3_get_ipc_logbuf(v12);
    if ( v14 )
    {
      v15 = ipa3_get_ipc_logbuf(v14);
      v14 = ipc_log_string(v15, "ipa-wan %s:%d Mux ID : %d\n", "ipa3_q6_clnt_install_firewall_rules_ind_cb", 1642, v4);
    }
    result = ipa3_get_ipc_logbuf_low(v14);
    if ( result )
    {
      v17 = ipa3_get_ipc_logbuf_low(result);
      return ipc_log_string(v17, "ipa-wan %s:%d Mux ID : %d\n", "ipa3_q6_clnt_install_firewall_rules_ind_cb", 1642, v4);
    }
  }
  return result;
}
