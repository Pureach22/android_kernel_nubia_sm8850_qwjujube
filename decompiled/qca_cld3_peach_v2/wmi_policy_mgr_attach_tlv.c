__int64 __fastcall wmi_policy_mgr_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 1536LL) = send_pdev_set_dual_mac_config_cmd_tlv;
  return result;
}
