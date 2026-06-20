__int64 __fastcall debug_wmi_mgmt_command_tx_cmp_log_open(__int64 a1, __int64 a2)
{
  return single_open(a2, debug_wmi_mgmt_command_tx_cmp_log_show, *(_QWORD *)(a1 + 696));
}
