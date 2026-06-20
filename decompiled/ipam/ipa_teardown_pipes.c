__int64 ipa_teardown_pipes()
{
  __int64 v0; // x9
  __int64 v1; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  __int64 v10; // x0

  mutex_lock(rmnet_ipa3_ctx + 1088);
  if ( *(_BYTE *)(ipa3_ctx + 48858) == 1 && (ipa3_teardown_apps_low_lat_pipes() & 0x80000000) != 0 )
  {
    printk(&unk_3FF361, "ipa_teardown_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d Failed to teardown IPA->APPS qmap pipe\n", "ipa_teardown_pipes", 2106);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d Failed to teardown IPA->APPS qmap pipe\n",
        "ipa_teardown_pipes",
        2106);
    }
  }
  if ( *(_BYTE *)(ipa3_ctx + 48859) == 1 && (ipa3_teardown_apps_low_lat_data_pipes() & 0x80000000) != 0 )
  {
    printk(&unk_3B0B30, "ipa_teardown_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(v9, "ipa-wan %s:%d Failed to teardown IPA->APPS LL pipe\n", "ipa_teardown_pipes", 2111);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v10, "ipa-wan %s:%d Failed to teardown IPA->APPS LL pipe\n", "ipa_teardown_pipes", 2111);
    }
  }
  if ( (ipa_teardown_sys_pipe(*(_DWORD *)(rmnet_ipa3_ctx + 1084)) & 0x80000000) != 0 )
  {
    printk(&unk_3EA8C4, "ipa_teardown_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v3 = ipa3_get_ipc_logbuf();
      ipc_log_string(v3, "ipa-wan %s:%d Failed to teardown IPA->APPS pipe\n", "ipa_teardown_pipes", 2115);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v4 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v4, "ipa-wan %s:%d Failed to teardown IPA->APPS pipe\n", "ipa_teardown_pipes", 2115);
    }
  }
  else
  {
    *(_DWORD *)(rmnet_ipa3_ctx + 1084) = -1;
  }
  if ( (ipa_teardown_sys_pipe(*(_DWORD *)(rmnet_ipa3_ctx + 1080)) & 0x80000000) != 0 )
  {
    printk(&unk_3B6443, "ipa_teardown_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v5 = ipa3_get_ipc_logbuf();
      ipc_log_string(v5, "ipa-wan %s:%d Failed to teardown APPS->IPA pipe\n", "ipa_teardown_pipes", 2120);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa-wan %s:%d Failed to teardown APPS->IPA pipe\n", "ipa_teardown_pipes", 2120);
    }
  }
  else
  {
    *(_DWORD *)(rmnet_ipa3_ctx + 1080) = -1;
  }
  v0 = rmnet_ipa3_ctx;
  qword_2018D8 = 0;
  qword_2018E0 = 0;
  ingress_pipe_status = 0;
  qword_2018D0 = 0;
  egress_pipe_status[0] = 0;
  qword_2018F0 = 0;
  v1 = rmnet_ipa3_ctx + 1088;
  qword_2018F8 = 0;
  prod_pipes_setup_complete = 0;
  *(_DWORD *)(rmnet_ipa3_ctx + 2056) = 0;
  *(_BYTE *)(v0 + 2060) = 0;
  cons_pipes_setup_complete = 0;
  return mutex_unlock(v1);
}
