_QWORD *__fastcall osif_dp_register_stc_callbacks(_QWORD *result)
{
  result[44] = os_if_dp_send_flow_stats_event;
  result[45] = os_if_dp_send_flow_report_event;
  result[46] = os_if_dp_send_flow_status_event;
  return result;
}
