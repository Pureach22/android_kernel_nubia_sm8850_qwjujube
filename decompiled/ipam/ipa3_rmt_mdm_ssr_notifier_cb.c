__int64 __fastcall ipa3_rmt_mdm_ssr_notifier_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x20
  int type; // w0
  __int64 v12; // x20
  int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v18; // x0
  __int64 v19; // x0

  if ( (ipa3_rmnet_ctx & 1) != 0 )
  {
    if ( (*(_BYTE *)(rmnet_ipa3_ctx + 1992) & 1) != 0 )
    {
      if ( a2 > 1 )
      {
        if ( a2 == 3 )
        {
          printk(&unk_3A4DE2, "ipa3_rmt_mdm_ssr_notifier_cb");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(
              ipc_logbuf,
              "ipa-wan %s:%d IPA Received RMT MPSS AFTER_SHUTDOWN\n",
              "ipa3_rmt_mdm_ssr_notifier_cb",
              4200);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              ipc_logbuf_low,
              "ipa-wan %s:%d IPA Received RMT MPSS AFTER_SHUTDOWN\n",
              "ipa3_rmt_mdm_ssr_notifier_cb",
              4200);
          }
        }
        else
        {
          if ( a2 != 2 )
          {
LABEL_12:
            if ( ipa3_get_ipc_logbuf() )
            {
              v5 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v5,
                "ipa-wan %s:%d IPA received RMT MPSS event %lu",
                "ipa3_rmt_mdm_ssr_notifier_cb",
                4217,
                a2);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v6 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v6,
                "ipa-wan %s:%d IPA received RMT MPSS event %lu",
                "ipa3_rmt_mdm_ssr_notifier_cb",
                4217,
                a2);
            }
            return 0;
          }
          printk(&unk_3FC794, "ipa3_rmt_mdm_ssr_notifier_cb");
          if ( ipa3_get_ipc_logbuf() )
          {
            v18 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v18,
              "ipa-wan %s:%d IPA received RMT MPSS BEFORE_SHUTDOWN\n",
              "ipa3_rmt_mdm_ssr_notifier_cb",
              4193);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v19 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v19,
              "ipa-wan %s:%d IPA received RMT MPSS BEFORE_SHUTDOWN\n",
              "ipa3_rmt_mdm_ssr_notifier_cb",
              4193);
          }
        }
      }
      else
      {
        if ( a2 )
        {
          if ( a2 == 1 )
          {
            printk(&unk_3A7FA2, "ipa3_rmt_mdm_ssr_notifier_cb");
            if ( ipa3_get_ipc_logbuf() )
            {
              v3 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v3,
                "ipa-wan %s:%d IPA received RMT MPSS AFTER_POWERUP\n",
                "ipa3_rmt_mdm_ssr_notifier_cb",
                4214);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v4 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v4,
                "ipa-wan %s:%d IPA received RMT MPSS AFTER_POWERUP\n",
                "ipa3_rmt_mdm_ssr_notifier_cb",
                4214);
            }
            return 0;
          }
          goto LABEL_12;
        }
        printk(&unk_3F054D, "ipa3_rmt_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v14 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v14,
            "ipa-wan %s:%d IPA received RMT MPSS BEFORE_POWERUP\n",
            "ipa3_rmt_mdm_ssr_notifier_cb",
            4207);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v15 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v15,
            "ipa-wan %s:%d IPA received RMT MPSS BEFORE_POWERUP\n",
            "ipa3_rmt_mdm_ssr_notifier_cb",
            4207);
        }
      }
    }
    else
    {
      ipa3_ctx_get_type(1);
      printk(&unk_3E7A84, "ipa3_rmt_mdm_ssr_notifier_cb");
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        type = ipa3_ctx_get_type(1);
        ipc_log_string(
          v10,
          "ipa-wan %s:%d Remote mdm SSR event=%lu on non-APQ platform=%d\n",
          "ipa3_rmt_mdm_ssr_notifier_cb",
          4183,
          a2,
          type);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v12 = ipa3_get_ipc_logbuf_low();
        v13 = ipa3_ctx_get_type(1);
        ipc_log_string(
          v12,
          "ipa-wan %s:%d Remote mdm SSR event=%lu on non-APQ platform=%d\n",
          "ipa3_rmt_mdm_ssr_notifier_cb",
          4183,
          a2,
          v13);
      }
    }
  }
  else
  {
    printk(&unk_3ED52A, "ipa3_rmt_mdm_ssr_notifier_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa-wan %s:%d SSR event=%lu while not enabled\n", "ipa3_rmt_mdm_ssr_notifier_cb", 4177, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipa-wan %s:%d SSR event=%lu while not enabled\n", "ipa3_rmt_mdm_ssr_notifier_cb", 4177, a2);
    }
  }
  return 0;
}
