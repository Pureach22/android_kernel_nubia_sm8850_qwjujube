__int64 notify_tcp_param_change()
{
  int v1; // w21

  if ( !(unsigned int)param_set_int() )
  {
    v1 = tcp_output_debug;
    if ( tcp_output_debug )
    {
      printk(&unk_A709);
      if ( (gIsNfNetHookRegistered & 1) == 0 )
      {
        nf_register_net_hooks(&init_net, &packet_in_nf_ops, 2);
        nf_register_net_hooks(&init_net, &packet_out_nf_ops, 2);
LABEL_9:
        gIsNfNetHookRegistered = v1 != 0;
        return 0;
      }
    }
    else
    {
      printk(&unk_99C5);
      if ( gIsNfNetHookRegistered == 1 )
      {
        nf_unregister_net_hooks(&init_net, &packet_in_nf_ops, 2);
        nf_unregister_net_hooks(&init_net, &packet_out_nf_ops, 2);
        goto LABEL_9;
      }
    }
    return 0;
  }
  return 0xFFFFFFFFLL;
}
