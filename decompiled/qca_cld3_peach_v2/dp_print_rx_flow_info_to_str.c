__int64 __fastcall dp_print_rx_flow_info_to_str(unsigned __int8 a1, __int64 a2)
{
  __int64 v3; // x8

  v3 = **(_QWORD **)(dp_get_context() + 1480) + 336LL * a1;
  scnprintf(
    a2,
    256,
    "%u %u %llu",
    *(unsigned __int8 *)(v3 + 322),
    *(unsigned __int8 *)(v3 + 323),
    *(_QWORD *)(v3 + 248));
  return a2;
}
