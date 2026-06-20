__int64 __fastcall dp_parser_msm_hdcp_dev(__int64 a1)
{
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v4; // x0
  __int64 v5; // x0

  if ( !of_find_compatible_node(0, 0, "qcom,msm-hdcp") )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(
      ipc_log_context,
      "[w][%-4d]couldn't find msm-hdcp node\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v4 = &unk_21BD8C;
    return printk(v4, "dp_parser_msm_hdcp_dev");
  }
  result = of_find_device_by_node();
  if ( !result )
  {
    v5 = get_ipc_log_context(0);
    ipc_log_string(v5, "[w][%-4d]couldn't find msm-hdcp pdev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v4 = &unk_23A8DB;
    return printk(v4, "dp_parser_msm_hdcp_dev");
  }
  *(_QWORD *)(a1 + 8) = result + 16;
  return result;
}
