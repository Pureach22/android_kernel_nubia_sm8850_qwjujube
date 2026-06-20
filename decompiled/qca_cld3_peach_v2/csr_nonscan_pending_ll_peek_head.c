__int64 __fastcall csr_nonscan_pending_ll_peek_head(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x1

  result = wlan_serialization_peek_head_pending_cmd_using_psoc(
             *(_QWORD *)(a1 + 21624),
             0,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  if ( result )
  {
    v19 = result;
    while ( *(_DWORD *)(v19 + 16) )
    {
      result = wlan_serialization_get_pending_list_next_node_using_psoc(
                 *(_QWORD *)(a1 + 21624),
                 v19,
                 0,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18);
      v19 = result;
      if ( !result )
        return result;
    }
    return *(_QWORD *)(v19 + 40);
  }
  return result;
}
