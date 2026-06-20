__int64 __fastcall os_if_dp_send_flow_stats_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x20
  __int64 v5; // x21

  if ( (a3 & 8) != 0 )
  {
    v4 = a1;
    v5 = a2;
    os_if_dp_print_flow_stats(a2, a3);
    a1 = v4;
    a2 = v5;
  }
  return os_if_dp_send_flow_stats(a1, a2, 71, a3);
}
