__int64 __fastcall cm_if_mgr_inform_connect_complete(__int64 a1, int a2)
{
  _DWORD *v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20

  v4 = (_DWORD *)_qdf_mem_malloc(0x30u, "cm_if_mgr_inform_connect_complete", 1765);
  if ( !v4 )
    return 2;
  *v4 = a2;
  v13 = (__int64)v4;
  if_mgr_deliver_event(a1, 1u, (__int64)v4, v5, v6, v7, v8, v9, v10, v11, v12);
  _qdf_mem_free(v13);
  return 0;
}
