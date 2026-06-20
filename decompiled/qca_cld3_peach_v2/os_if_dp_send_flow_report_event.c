__int64 __fastcall os_if_dp_send_flow_report_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x21

  if ( (a3 & 8) != 0 )
  {
    v5 = a1;
    os_if_dp_print_flow_stats(a2, a3 | 4u);
    a1 = v5;
  }
  return os_if_dp_send_flow_stats(a1, a2, 72, a3 | 4u);
}
