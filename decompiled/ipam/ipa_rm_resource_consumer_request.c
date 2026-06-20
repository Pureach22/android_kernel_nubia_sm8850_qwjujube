__int64 __fastcall ipa_rm_resource_consumer_request(unsigned int *a1, int a2, char a3, char a4)
{
  __int64 ipc_logbuf_low; // x22
  const char *v9; // x0
  unsigned int v10; // w8
  int v11; // w22
  unsigned int v12; // w21
  unsigned int v13; // w0
  __int64 v14; // x23
  const char *v15; // x0
  char v16; // w4
  __int64 v17; // x0
  int v18; // w1
  __int64 v19; // x20
  const char *v20; // x0
  __int64 v21; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v9 = ipa_rm_resource_str(*a1);
    ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d %s state: %d\n", "ipa_rm_resource_consumer_request", 153, v9, a1[5]);
  }
  v10 = a1[4];
  v11 = a1[5];
  a1[4] = v10 + a2;
  if ( v11 <= 1 )
  {
    if ( v11 )
    {
      if ( v11 == 1 )
      {
        v12 = -115;
        goto LABEL_20;
      }
LABEL_14:
      a1[4] = v10;
      v12 = -1;
      goto LABEL_22;
    }
    goto LABEL_9;
  }
  if ( v11 != 2 )
  {
    if ( v11 != 3 )
      goto LABEL_14;
LABEL_9:
    v13 = *a1;
    a1[5] = 1;
    a1[10] = 0;
    ipa_rm_resource_str(v13);
    if ( v11 == 3 || (unsigned int)ipa3_inc_client_enable_clks_no_block() )
    {
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        v15 = ipa_rm_resource_str(*a1);
        ipc_log_string(v14, "ipa_rm %s:%d async resume work for %s\n", "ipa_rm_resource_consumer_request", 167, v15);
      }
      ipa_rm_wq_send_resume_cmd(*a1, v11, a2, a3 & 1);
      v12 = -115;
      goto LABEL_20;
    }
    v16 = a3 & 1;
    v17 = (__int64)a1;
    v18 = v11;
    goto LABEL_19;
  }
  if ( (a4 & 1) == 0 )
  {
    ipa_rm_perf_profile_change(*a1);
    v12 = 0;
    goto LABEL_20;
  }
  v16 = a3 & 1;
  v17 = (__int64)a1;
  v18 = 2;
LABEL_19:
  v12 = ipa_rm_resource_consumer_request_work(v17, v18, a2, 0, v16);
LABEL_20:
  if ( (a3 & 1) != 0 )
    ++a1[8];
LABEL_22:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v19 = ipa3_get_ipc_logbuf_low();
    v20 = ipa_rm_resource_str(*a1);
    ipc_log_string(v19, "ipa_rm %s:%d %s new state: %d\n", "ipa_rm_resource_consumer_request", 203, v20, a1[5]);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v21 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v21, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_resource_consumer_request", 204, v12);
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
