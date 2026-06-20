__int64 __fastcall ipa_rm_resource_consumer_release(unsigned int *a1, int a2, char a3)
{
  __int64 ipc_logbuf_low; // x20
  const char *v7; // x0
  unsigned int v8; // w20
  unsigned int v9; // w8
  bool v10; // vf
  int v11; // w8
  int v12; // w8
  int v13; // w9
  __int64 v14; // x21
  const char *v15; // x0
  __int64 v16; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v7 = ipa_rm_resource_str(*a1);
    ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d %s state: %d\n", "ipa_rm_resource_consumer_release", 219, v7, a1[5]);
  }
  v8 = a1[5];
  a1[4] -= a2;
  if ( v8 - 1 < 2 )
  {
    v12 = a1[8];
    if ( (a3 & 1) != 0 )
    {
      v13 = v12 - 1;
      if ( v12 >= 1 )
      {
        --v12;
        a1[8] = v13;
      }
    }
    if ( !v12 )
    {
      a1[5] = 3;
      if ( v8 == 1 || (unsigned int)ipa3_suspend_resource_no_block(*a1) )
      {
        ipa_rm_wq_send_suspend_cmd(*a1, v8, a2);
        v8 = -115;
        if ( ipa3_get_ipc_logbuf_low() )
          goto LABEL_27;
      }
      else
      {
        v8 = ipa_rm_resource_consumer_release_work((__int64)a1, v8, 0);
        if ( ipa3_get_ipc_logbuf_low() )
          goto LABEL_27;
      }
      goto LABEL_28;
    }
    if ( v8 == 2 )
    {
      ipa_rm_perf_profile_change(*a1);
      v8 = 0;
      if ( ipa3_get_ipc_logbuf_low() )
        goto LABEL_27;
      goto LABEL_28;
    }
    v8 = 0;
LABEL_26:
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_28;
    goto LABEL_27;
  }
  if ( !v8 )
    goto LABEL_26;
  if ( v8 == 3 )
  {
    if ( (a3 & 1) != 0 )
    {
      v9 = a1[8];
      v10 = __OFSUB__(v9, 1);
      v11 = v9 - 1;
      if ( v11 < 0 == v10 )
      {
        a1[8] = v11;
        v8 = -115;
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_28;
LABEL_27:
        v14 = ipa3_get_ipc_logbuf_low();
        v15 = ipa_rm_resource_str(*a1);
        ipc_log_string(v14, "ipa_rm %s:%d %s new state: %d\n", "ipa_rm_resource_consumer_release", 260, v15, a1[5]);
        goto LABEL_28;
      }
    }
    v8 = -115;
    if ( ipa3_get_ipc_logbuf_low() )
      goto LABEL_27;
  }
  else
  {
    v8 = -1;
    if ( ipa3_get_ipc_logbuf_low() )
      goto LABEL_27;
  }
LABEL_28:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v16, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_resource_consumer_release", 261, v8);
  }
  return v8;
}
