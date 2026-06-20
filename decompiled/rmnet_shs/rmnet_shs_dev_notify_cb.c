__int64 __fastcall rmnet_shs_dev_notify_cb(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  bool v11; // cf
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x19

  v3 = *a3;
  if ( *a3 )
  {
    if ( !strncmp((const char *)(v3 + 296), "rmnet_data", 0xAu) )
    {
      if ( a2 == 1 )
      {
        if ( !byte_19491 && byte_19494 )
        {
          v14 = qword_19098;
          if ( qword_19098 )
          {
            byte_19030 = 1;
            byte_19058 = 1;
            if ( (*(_BYTE *)(qword_19098 + 11) & 0x20) != 0 )
            {
              qword_19038 = (__int64)rmnet_shs_dl_hdr_handler_v2;
              qword_19040 = (__int64)rmnet_shs_dl_trl_handler_v2;
              qword_19060 = (__int64)rmnet_shs_pb_hdr_handler;
            }
            qword_19078 = (__int64)rmnet_shs_ps_on_hdlr;
            qword_19080 = (__int64)rmnet_shs_ps_off_hdlr;
            if ( (unsigned int)rmnet_map_dl_ind_register(qword_19098) )
              printk(&unk_153F0);
            if ( (unsigned int)rmnet_map_pb_ind_register(v14, &byte_19058) )
              printk(&unk_1566C);
            if ( (unsigned int)qmi_rmnet_ps_ind_register(v14, &qword_19078) )
              printk(&unk_156EF);
            rmnet_shs_switch_disable();
            rmnet_shs_skb_entry_enable();
            rmnet_module_hook_register(&rmnet_shs_ll_entry_hook, 1);
            tracepoint_probe_register(&_tracepoint_android_vh_do_wake_up_sync, rmnet_vh_do_wake_up_sync, 0);
            byte_19491 = 1;
          }
          else
          {
            printk(&unk_15A6B);
          }
        }
      }
      else if ( a2 == 5 )
      {
        v11 = __CFADD__(rmnet_vnd_total++, 1);
        if ( !v11 && !byte_19494 )
        {
          printk(&unk_15549);
          if ( rmnet_get_port(*(_QWORD *)(v3 + 2696)) )
          {
            v12 = rmnet_shs_init(*(_QWORD *)(v3 + 2696), v3);
            v13 = rmnet_shs_wq_init(v12);
            rmnet_shs_rx_wq_init(v13);
          }
          else
          {
            printk(&unk_15BB0);
          }
        }
      }
      else if ( a2 == 6 && !--rmnet_vnd_total )
      {
        if ( byte_19494 )
        {
          printk(&unk_15B8E);
          rmnet_shs_skb_entry_disable();
          rmnet_shs_switch_disable();
          rmnet_module_hook_unregister_no_sync(&rmnet_shs_ll_entry_hook, 1);
          qmi_rmnet_ps_ind_deregister(qword_19098, &qword_19078);
          rmnet_map_dl_ind_deregister(qword_19098, &byte_19030);
          v5 = rmnet_map_pb_ind_deregister(qword_19098, &byte_19058);
          v6 = rmnet_shs_cancel_table(v5);
          v7 = rmnet_shs_ll_deinit(v6);
          v8 = rmnet_shs_rx_wq_exit(v7);
          if ( byte_19491 )
            v8 = tracepoint_probe_unregister(&_tracepoint_android_vh_do_wake_up_sync, rmnet_vh_do_wake_up_sync, 0);
          v9 = rmnet_shs_wq_exit(v8);
          rmnet_shs_exit(v9);
          trace_rmnet_shs_high();
        }
      }
    }
  }
  else
  {
    ++rmnet_shs_crit_err;
  }
  return 0;
}
