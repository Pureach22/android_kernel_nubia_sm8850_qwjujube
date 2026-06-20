__int64 __fastcall wlan_objmgr_print_ref_ids(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 i; // x22

  result = qdf_trace_msg(
             0x57u,
             a2,
             "%s: Pending references of object",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_objmgr_print_ref_ids");
  for ( i = 0; i != 109; ++i )
  {
    if ( *(_DWORD *)(a1 + 4 * i) )
      result = qdf_trace_msg(
                 0x57u,
                 a2,
                 "%s: %s(%d) -- %d",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "wlan_objmgr_print_ref_ids",
                 string_from_dbgid_strings[i],
                 (unsigned int)i);
  }
  return result;
}
