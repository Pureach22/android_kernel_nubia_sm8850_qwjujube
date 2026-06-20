__int64 __fastcall cm_connect_scan_resp(__int64 *a1, _DWORD *a2, int a3)
{
  __int64 req_by_scan_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int *v14; // x1

  if ( !*a2 )
    return 16;
  req_by_scan_id = cm_get_req_by_scan_id();
  if ( !req_by_scan_id )
    return 16;
  v14 = (unsigned int *)(req_by_scan_id + 24);
  if ( a3 )
    return cm_send_connect_start_fail(a1, v14, 1);
  cm_connect_start(a1, v14, v6, v7, v8, v9, v10, v11, v12, v13);
  return 0;
}
