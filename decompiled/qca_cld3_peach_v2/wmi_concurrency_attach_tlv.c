__int64 __fastcall wmi_concurrency_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[84] = send_set_enable_disable_mcc_adaptive_scheduler_cmd_tlv;
  v1[83] = send_set_mcc_channel_time_latency_cmd_tlv;
  v1[82] = send_set_mcc_channel_time_quota_cmd_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 680LL) = &extract_mcc_quota_ev_param_tlv;
  return result;
}
