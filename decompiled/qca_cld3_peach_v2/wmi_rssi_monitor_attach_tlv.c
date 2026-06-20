__int64 __fastcall wmi_rssi_monitor_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 728LL) = send_set_rssi_monitoring_cmd_tlv;
  return result;
}
