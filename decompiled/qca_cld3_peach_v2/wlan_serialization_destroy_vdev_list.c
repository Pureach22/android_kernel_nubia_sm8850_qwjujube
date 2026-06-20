__int64 __fastcall wlan_serialization_destroy_vdev_list(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  for ( result = qdf_list_empty((_QWORD *)a1); (result & 1) == 0; result = qdf_list_empty((_QWORD *)a1) )
  {
    if ( qdf_list_empty((_QWORD *)a1) )
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: The list is empty",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_serialization_remove_front",
        v19,
        v20);
    else
      qdf_list_remove_front((_DWORD *)a1, &v19);
  }
  if ( *(_DWORD *)(a1 + 16) )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: list length not equal to zero",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "qdf_list_destroy");
  _ReadStatusReg(SP_EL0);
  return result;
}
