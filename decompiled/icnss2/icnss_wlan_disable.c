__int64 __fastcall icnss_wlan_disable(__int64 a1)
{
  __int64 v1; // x2

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 1832LL);
  if ( (v1 & 0x2000) == 0 )
    return icnss_send_wlan_disable_to_fw();
  ipc_log_string(icnss_ipc_log_context, "icnss2: FW down, ignoring wlan_disable state: 0x%lx\n", v1);
  return 0;
}
