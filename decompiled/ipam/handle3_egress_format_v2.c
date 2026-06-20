__int64 __fastcall handle3_egress_format_v2(__int64 a1, int a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x0
  size_t v9; // x21
  int v10; // w20
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v16; // x0
  __int64 v17; // x0

  mutex_lock(rmnet_ipa3_ctx + 2064);
  if ( inline_copy_from_user_2((int)&egress_ioctl_v2_data, a2, 0x10u) )
  {
    if ( (unsigned int)__ratelimit(&handle3_egress_format_v2__rs, "handle3_egress_format_v2") )
    {
      printk(&unk_3F0414, "handle3_egress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_5:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d failed to copy egress extended ioctl v2 data\n",
            "handle3_egress_format_v2",
            2438);
LABEL_7:
          v6 = -14;
          goto LABEL_27;
        }
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
      "ipa-wan %s:%d failed to copy egress extended ioctl v2 data\n",
      "handle3_egress_format_v2",
      2438);
    goto LABEL_5;
  }
  if ( HIDWORD(qword_2017A8) >= 4 )
  {
    if ( (unsigned int)__ratelimit(&handle3_egress_format_v2__rs_604, "handle3_egress_format_v2") )
    {
      printk(&unk_3A7F06, "handle3_egress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_12:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v8 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v8,
            "ipa-wan %s:%d Egress pipe count mismatch = %d\n",
            "handle3_egress_format_v2",
            2446,
            HIDWORD(qword_2017A8));
        }
        goto LABEL_26;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_12;
    }
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v7,
      "ipa-wan %s:%d Egress pipe count mismatch = %d\n",
      "handle3_egress_format_v2",
      2446,
      HIDWORD(qword_2017A8));
    goto LABEL_12;
  }
  if ( (_DWORD)qword_2017A8 != 32 )
  {
    if ( (unsigned int)__ratelimit(&handle3_egress_format_v2__rs_607, "handle3_egress_format_v2") )
    {
      printk(&unk_3F62B9, "handle3_egress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_24:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v14, "ipa-wan %s:%d Egress pipe param size mismatch\n", "handle3_egress_format_v2", 2453);
          goto LABEL_7;
        }
        goto LABEL_26;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_24;
    }
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(v13, "ipa-wan %s:%d Egress pipe param size mismatch\n", "handle3_egress_format_v2", 2453);
    goto LABEL_24;
  }
  v9 = 32LL * HIDWORD(qword_2017A8);
  v10 = egress_ioctl_v2_data;
  _check_object_size(&egress_param, v9, 0);
  if ( inline_copy_from_user_2((int)&egress_param, v10, v9) )
  {
    if ( (unsigned int)__ratelimit(&handle3_egress_format_v2__rs_610, "handle3_egress_format_v2") )
    {
      printk(&unk_3ADFDA, "handle3_egress_format_v2");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_19:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v12 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v12,
            "ipa-wan %s:%d Failed to copy all egress pipes' params\n",
            "handle3_egress_format_v2",
            2462);
          goto LABEL_7;
        }
LABEL_26:
        v6 = -14;
        goto LABEL_27;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_19;
    }
    v11 = ipa3_get_ipc_logbuf();
    ipc_log_string(v11, "ipa-wan %s:%d Failed to copy all egress pipes' params\n", "handle3_egress_format_v2", 2462);
    goto LABEL_19;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v16 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v16,
      "ipa-wan %s:%d egress_ioctl_v2_data.number_of_eps = %d\n",
      "handle3_egress_format_v2",
      2468,
      HIDWORD(qword_2017A8));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v17 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v17,
      "ipa-wan %s:%d egress_ioctl_v2_data.number_of_eps = %d\n",
      "handle3_egress_format_v2",
      2468,
      HIDWORD(qword_2017A8));
  }
  if ( (prod_pipes_setup_complete & 1) != 0 )
    v6 = 0;
  else
    v6 = ipa_setup_prod_pipes(a1, 1);
LABEL_27:
  mutex_unlock(rmnet_ipa3_ctx + 2064);
  return v6;
}
