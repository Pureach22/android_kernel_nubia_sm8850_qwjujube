__int64 __fastcall hdd_check_for_net_dev_ref_leak(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x23
  __int64 v10; // x25
  int v11; // w26
  char *v12; // x22

  v9 = 0;
  v10 = result + 52524;
  do
  {
    v11 = 50;
    while ( *(_DWORD *)(v10 + 4 * v9) )
    {
      v12 = net_dev_ref_debug_string_from_id_strings[v9];
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: net_dev held for debug id %s",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "hdd_check_for_net_dev_ref_leak",
        v12);
      result = qdf_sleep();
      if ( !--v11 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: net_dev hold reference leak detected for debug id: %s",
                   a2,
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   "hdd_check_for_net_dev_ref_leak",
                   v12);
        break;
      }
    }
    ++v9;
  }
  while ( v9 != 68 );
  return result;
}
