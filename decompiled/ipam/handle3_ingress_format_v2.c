__int64 __fastcall handle3_ingress_format_v2(__int64 a1, int a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w20
  size_t v9; // x21
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w19

  mutex_lock(rmnet_ipa3_ctx + 2064);
  if ( inline_copy_from_user_2((int)&ingress_ioctl_v2_data, a2, 0x10u) )
  {
    if ( (unsigned int)__ratelimit(&handle3_ingress_format_v2__rs, "handle3_ingress_format_v2") )
    {
      printk(&unk_3F0452, "handle3_ingress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_5:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d failed to copy ingress extended ioctl v2 data\n",
            "handle3_ingress_format_v2",
            2155);
        }
LABEL_25:
        v14 = -14;
        goto LABEL_26;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_5;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d failed to copy ingress extended ioctl v2 data\n",
      "handle3_ingress_format_v2",
      2155);
    goto LABEL_5;
  }
  if ( HIDWORD(qword_2017B8) >= 5 )
  {
    if ( (unsigned int)__ratelimit(&handle3_ingress_format_v2__rs_616, "handle3_ingress_format_v2") )
    {
      printk(&unk_3DC9C0, "handle3_ingress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_11:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v7 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v7, "ipa-wan %s:%d Ingress pipe count mismatch\n", "handle3_ingress_format_v2", 2162);
        }
        goto LABEL_25;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_11;
    }
    v6 = ipa3_get_ipc_logbuf();
    ipc_log_string(v6, "ipa-wan %s:%d Ingress pipe count mismatch\n", "handle3_ingress_format_v2", 2162);
    goto LABEL_11;
  }
  if ( (_DWORD)qword_2017B8 != 40 )
  {
    if ( (unsigned int)__ratelimit(&handle3_ingress_format_v2__rs_619, "handle3_ingress_format_v2") )
    {
      printk(&unk_3DF56F, "handle3_ingress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_23:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v13 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v13, "ipa-wan %s:%d Ingress pipe param size mismatch\n", "handle3_ingress_format_v2", 2169);
        }
        goto LABEL_25;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_23;
    }
    v12 = ipa3_get_ipc_logbuf();
    ipc_log_string(v12, "ipa-wan %s:%d Ingress pipe param size mismatch\n", "handle3_ingress_format_v2", 2169);
    goto LABEL_23;
  }
  v8 = ingress_ioctl_v2_data;
  v9 = 40LL * HIDWORD(qword_2017B8);
  _check_object_size(&ingress_param, v9, 0);
  if ( inline_copy_from_user_2((int)&ingress_param, v8, v9) )
  {
    if ( (unsigned int)__ratelimit(&handle3_ingress_format_v2__rs_622, "handle3_ingress_format_v2") )
    {
      printk(&unk_3EA960, "handle3_ingress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_18:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v11 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v11,
            "ipa-wan %s:%d Failed to copy all ingress pipes' params\n",
            "handle3_ingress_format_v2",
            2178);
        }
        goto LABEL_25;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_18;
    }
    v10 = ipa3_get_ipc_logbuf();
    ipc_log_string(v10, "ipa-wan %s:%d Failed to copy all ingress pipes' params\n", "handle3_ingress_format_v2", 2178);
    goto LABEL_18;
  }
  if ( (cons_pipes_setup_complete & 1) == 0 )
    ((void (__fastcall *)(__int64, __int64))ipa_setup_cons_pipes)(a1, 1);
  v14 = 0;
LABEL_26:
  mutex_unlock(rmnet_ipa3_ctx + 2064);
  return v14;
}
