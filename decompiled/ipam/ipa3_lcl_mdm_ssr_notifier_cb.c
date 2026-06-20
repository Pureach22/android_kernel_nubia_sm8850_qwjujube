__int64 __fastcall ipa3_lcl_mdm_ssr_notifier_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x1
  _QWORD *v24; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 *v30; // x8
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  _QWORD *v37; // x8
  __int64 v38; // x8
  _QWORD *v39; // x9
  __int64 v40; // x0
  __int64 v41; // x0

  if ( ipa3_rmnet_ctx != 1 )
    return 0;
  if ( !ipa3_ctx )
  {
    if ( (unsigned int)__ratelimit(&ipa3_lcl_mdm_ssr_notifier_cb__rs, "ipa3_lcl_mdm_ssr_notifier_cb") )
    {
      printk(&unk_3BC3C3, "ipa3_lcl_mdm_ssr_notifier_cb");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_21:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d ipa3_ctx was not initialized\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4066);
        }
        return 0;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_21;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d ipa3_ctx was not initialized\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4066);
    goto LABEL_21;
  }
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) != 1 )
  {
    if ( a2 <= 1 )
    {
      if ( !a2 )
      {
        printk(&unk_3A7F70, "ipa3_lcl_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v16 = ipa3_get_ipc_logbuf();
          ipc_log_string(v16, "ipa-wan %s:%d IPA received MPSS BEFORE_POWERUP\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4139);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v17 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v17, "ipa-wan %s:%d IPA received MPSS BEFORE_POWERUP\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4139);
        }
        v18 = rmnet_ipa3_ctx;
        if ( *(_DWORD *)(rmnet_ipa3_ctx + 1056) )
        {
          ipa3_qmi_service_exit();
          ipa3_q6_pre_powerup_cleanup();
          v18 = rmnet_ipa3_ctx;
        }
        ipa3_proxy_clk_vote(*(_DWORD *)(v18 + 1056) != 0);
        ipa3_reset_freeze_vote();
        printk(&unk_3ED4F1, "ipa3_lcl_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v19 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v19,
            "ipa-wan %s:%d IPA BEFORE_POWERUP handling is complete\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4148);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v20 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v20,
            "ipa-wan %s:%d IPA BEFORE_POWERUP handling is complete\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4148);
        }
        goto LABEL_29;
      }
      if ( a2 == 1 )
      {
        printk(&unk_3F051C, "ipa3_lcl_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v4 = ipa3_get_ipc_logbuf();
          ipc_log_string(v4, "ipa-wan %s:%d IPA received MPSS AFTER_POWERUP\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4155);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v5 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v5, "ipa-wan %s:%d IPA received MPSS AFTER_POWERUP\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4155);
        }
        if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1052) && *(_DWORD *)(rmnet_ipa3_ctx + 1056) )
          _platform_driver_register(rmnet_ipa_driver, &_this_module);
        ipa3_odl_pipe_open_from_ssr();
        printk(&unk_3DCA38, "ipa3_lcl_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v6 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v6,
            "ipa-wan %s:%d IPA AFTER_POWERUP handling is complete\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4160);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v7 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v7,
            "ipa-wan %s:%d IPA AFTER_POWERUP handling is complete\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4160);
        }
LABEL_29:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v12 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v12, "ipa-wan %s:%d Exit\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4168);
        }
        return 0;
      }
LABEL_25:
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v10,
          "ipa-wan %s:%d Unsupported subsys notification, IPA received: %lu",
          "ipa3_lcl_mdm_ssr_notifier_cb",
          4164,
          a2);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v11,
          "ipa-wan %s:%d Unsupported subsys notification, IPA received: %lu",
          "ipa3_lcl_mdm_ssr_notifier_cb",
          4164,
          a2);
      }
      goto LABEL_29;
    }
    if ( a2 != 3 )
    {
      if ( a2 == 2 )
      {
        printk(&unk_3D3F2F, "ipa3_lcl_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v26 = ipa3_get_ipc_logbuf();
          ipc_log_string(v26, "ipa-wan %s:%d IPA received MPSS BEFORE_SHUTDOWN\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4082);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v27 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v27, "ipa-wan %s:%d IPA received MPSS BEFORE_SHUTDOWN\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4082);
        }
        v28 = ipa3_proxy_clk_vote(*(_DWORD *)(rmnet_ipa3_ctx + 1056) != 0);
        if ( *(_BYTE *)(a3 + 8) == 1 )
          ipa3_handle_modem_minidump(v28);
        ipa3_set_modem_up(0);
        rmnet_ipa_send_ssr_notification(0);
        *(_DWORD *)(rmnet_ipa3_ctx + 1056) = 1;
        v29 = ipa3_q6_pre_shutdown_cleanup();
        if ( rmnet_ipa3_ctx )
        {
          v30 = *(__int64 **)rmnet_ipa3_ctx;
          if ( *(_QWORD *)rmnet_ipa3_ctx )
          {
            v29 = *v30;
            if ( *v30 )
              v29 = netif_device_detach(v29);
          }
        }
        v31 = ipa3_qmi_stop_workqueues(v29);
        ipa3_wan_ioctl_stop_qmi_messages(v31);
        cancel_delayed_work(&ipa_tether_stats_poll_wakequeue_work);
        v32 = rmnet_ipa3_ctx;
        qword_201788 = 0;
        if ( *(_DWORD *)(rmnet_ipa3_ctx + 1052) )
        {
          platform_driver_unregister(rmnet_ipa_driver);
          v32 = rmnet_ipa3_ctx;
        }
        if ( *(_DWORD *)(v32 + 1056) && (int)ipa3_ctx_get_type(0) >= 14 )
          ipa3_q6_post_shutdown_cleanup();
        ipa3_odl_pipe_cleanup_from_ssr();
        printk(&unk_3C231E, "ipa3_lcl_mdm_ssr_notifier_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v33 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v33,
            "ipa-wan %s:%d IPA BEFORE_SHUTDOWN handling is complete\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4106);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v34 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v34,
            "ipa-wan %s:%d IPA BEFORE_SHUTDOWN handling is complete\n",
            "ipa3_lcl_mdm_ssr_notifier_cb",
            4106);
        }
        goto LABEL_29;
      }
      goto LABEL_25;
    }
    printk(&unk_3BC5D6, "ipa3_lcl_mdm_ssr_notifier_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa-wan %s:%d IPA Received MPSS AFTER_SHUTDOWN\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4113);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa-wan %s:%d IPA Received MPSS AFTER_SHUTDOWN\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4113);
    }
    ipa3_proxy_clk_unvote();
    printk(&unk_3CDFEE, "ipa3_lcl_mdm_ssr_notifier_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v35 = ipa3_get_ipc_logbuf();
      ipc_log_string(v35, "ipa-wan %s:%d rmnet_ipa unregister_netdev\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4118);
      if ( !ipa3_get_ipc_logbuf_low() )
      {
LABEL_52:
        v24 = (_QWORD *)rmnet_ipa3_ctx;
        if ( !rmnet_ipa3_ctx )
        {
LABEL_80:
          ipa3_wwan_deregister_netdev_pm_client();
          v38 = rmnet_ipa3_ctx;
          if ( rmnet_ipa3_ctx )
          {
            v39 = *(_QWORD **)rmnet_ipa3_ctx;
            if ( *(_QWORD *)rmnet_ipa3_ctx )
            {
              if ( *v39 )
              {
                free_netdev(*v39);
                v38 = rmnet_ipa3_ctx;
              }
            }
          }
          *(_QWORD *)v38 = 0;
          if ( *(_DWORD *)(v38 + 1056) && (int)ipa3_ctx_get_type(0) <= 13 )
            ipa3_q6_post_shutdown_cleanup();
          if ( (ipa3_ctx_get_flag(0) & 1) != 0 )
            ipa3_client_prod_post_shutdown_cleanup();
          printk(&unk_3E2173, "ipa3_lcl_mdm_ssr_notifier_cb");
          if ( ipa3_get_ipc_logbuf() )
          {
            v40 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v40,
              "ipa-wan %s:%d IPA AFTER_SHUTDOWN handling is complete\n",
              "ipa3_lcl_mdm_ssr_notifier_cb",
              4132);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v41 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v41,
              "ipa-wan %s:%d IPA AFTER_SHUTDOWN handling is complete\n",
              "ipa3_lcl_mdm_ssr_notifier_cb",
              4132);
          }
          goto LABEL_29;
        }
LABEL_77:
        v37 = (_QWORD *)*v24;
        if ( v37 && *v37 )
          unregister_netdev(*v37, v23);
        goto LABEL_80;
      }
    }
    else if ( !ipa3_get_ipc_logbuf_low() )
    {
      goto LABEL_52;
    }
    v36 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v36, "ipa-wan %s:%d rmnet_ipa unregister_netdev\n", "ipa3_lcl_mdm_ssr_notifier_cb", 4118);
    v24 = (_QWORD *)rmnet_ipa3_ctx;
    if ( !rmnet_ipa3_ctx )
      goto LABEL_80;
    goto LABEL_77;
  }
  printk(&unk_3AB0BA, "ipa3_lcl_mdm_ssr_notifier_cb");
  if ( ipa3_get_ipc_logbuf() )
  {
    v14 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v14,
      "ipa-wan %s:%d Local modem SSR event=%lu on APQ platform\n",
      "ipa3_lcl_mdm_ssr_notifier_cb",
      4072,
      a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v15 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v15,
      "ipa-wan %s:%d Local modem SSR event=%lu on APQ platform\n",
      "ipa3_lcl_mdm_ssr_notifier_cb",
      4072,
      a2);
  }
  return 0;
}
