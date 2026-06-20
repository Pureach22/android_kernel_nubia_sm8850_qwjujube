__int64 __fastcall wlan_serialization_destroy_cmd_pool(
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
  __int64 v10; // x5
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned int *)(a1 + 64);
  v20[0] = 0;
  qdf_trace_msg(
    0x4Cu,
    8u,
    "%s: Destroy cmd pool list %pK, size %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_serialization_destroy_cmd_pool",
    a1 + 48,
    v10);
  while ( 1 )
  {
    result = qdf_list_empty((_QWORD *)(a1 + 48));
    if ( (result & 1) != 0 )
      break;
    qdf_list_remove_front((_DWORD *)(a1 + 48), v20);
    _qdf_mem_free(v20[0]);
  }
  if ( *(_DWORD *)(a1 + 64) )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: list length not equal to zero",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "qdf_list_destroy");
  _ReadStatusReg(SP_EL0);
  return result;
}
