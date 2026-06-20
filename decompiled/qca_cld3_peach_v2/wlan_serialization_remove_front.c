__int64 __fastcall wlan_serialization_remove_front(_DWORD *a1, _QWORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( !qdf_list_empty(a1) )
    return qdf_list_remove_front(a1, a2);
  qdf_trace_msg(0x4Cu, 2u, "%s: The list is empty", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_serialization_remove_front");
  return 13;
}
