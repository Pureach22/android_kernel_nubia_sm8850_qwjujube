__int64 __fastcall register_soc_wake_notif(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  const char **node_by_name; // x0
  const char **v4; // x20
  unsigned int byname; // w20
  int v6; // w0
  int v7; // w21

  v1 = *(_QWORD *)(result + 152);
  if ( v1 )
  {
    v2 = result;
    node_by_name = (const char **)of_find_node_by_name(0, "qcom,smp2p_map_wlan_2_in");
    if ( !node_by_name )
    {
      printk("%sicnss2: Failed to get smp2p node for soc-wake-ack\n", byte_130B32);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Failed to get smp2p node for soc-wake-ack\n",
               (const char *)&unk_12DBF3);
    }
    v4 = node_by_name;
    ipc_log_string(icnss_ipc_log_context, "icnss2: smp2p node->name=%s\n", *node_by_name);
    if ( !strcmp("qcom,smp2p_map_wlan_2_in", *v4) )
    {
      byname = of_irq_get_byname(v4, "qcom,smp2p-soc-wake-ack");
      if ( (byname & 0x80000000) != 0 )
      {
        printk("%sicnss2: Unable to get soc wake ack irq %d\n", byte_130B32, byname);
        return ipc_log_string(
                 icnss_ipc_log_context,
                 "%sicnss2: Unable to get soc wake ack irq %d\n",
                 (const char *)&unk_12DBF3,
                 byname);
      }
    }
    else
    {
      byname = 0;
    }
    v6 = devm_request_threaded_irq(v2, byname, 0, fw_soc_wake_ack_handler, 8195, "wlanfw-soc-wake-ack", v1);
    if ( v6 < 0 )
    {
      v7 = v6;
      printk("%sicnss2: Unable to register for SOC Wake ACK IRQ handler %d ret = %d", byte_130B32, byname, v6);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Unable to register for SOC Wake ACK IRQ handler %d ret = %d",
               (const char *)&unk_12DBF3,
               byname,
               v7);
    }
    else
    {
      result = ipc_log_string(icnss_ipc_log_context, "icnss2: FW SOC Wake ACK handler registered irq = %d\n", byname);
      *(_DWORD *)(v1 + 5840) = byname;
    }
  }
  return result;
}
