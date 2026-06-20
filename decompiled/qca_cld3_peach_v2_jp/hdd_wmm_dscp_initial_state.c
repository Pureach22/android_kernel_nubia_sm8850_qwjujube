__int64 __fastcall hdd_wmm_dscp_initial_state(
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
  __int64 v9; // x10
  _DWORD *v10; // x8
  int *v11; // x11
  int v12; // w12
  __int64 v13; // x0
  __int64 result; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( **(_QWORD **)(a1 + 24) )
  {
    v9 = 0;
    v10 = (_DWORD *)(a1 + 41828);
    v11 = (int *)(a1 + 41828);
    do
    {
      v12 = (unsigned __int8)v9 >> 3;
      v9 += 2;
      *(v11 - 1) = v12;
      *v11 = v12;
      v11 += 2;
    }
    while ( v9 != 64 );
    v13 = *(_QWORD *)(a1 + 52824);
    v10[45] = 6;
    v10[17] = 3;
    v10[19] = 3;
    v10[21] = 3;
    v10[43] = 6;
    v10[9] = 0;
    v10[11] = 0;
    v10[13] = 0;
    v10[15] = 0;
    v10[23] = 4;
    v10[25] = 4;
    v10[27] = 4;
    v10[29] = 4;
    v10[47] = 7;
    result = _hdd_objmgr_get_vdev_by_user(v13, 0x46u, (__int64)"hdd_send_dscp_up_map_to_fw");
    if ( result )
    {
      _hdd_objmgr_put_vdev_by_user(
        result,
        0x46u,
        (__int64)"hdd_send_dscp_up_map_to_fw",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid psoc handle", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wmm_dscp_initial_state");
    return 16;
  }
  return result;
}
