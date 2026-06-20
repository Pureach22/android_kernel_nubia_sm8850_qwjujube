__int64 __fastcall nan_handle_pasn_peer_create_rsp(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x0
  const char *v28; // x2

  if ( a3 )
  {
    v13 = *a3;
    v14 = a3[1];
    v15 = a3[2];
    v16 = a3[5];
  }
  else
  {
    v15 = 0;
    v13 = 0;
    v14 = 0;
    v16 = 0;
  }
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: Received peer create response for %02x:%02x:%02x:**:**:%02x and vdev id %d with status:%d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "nan_handle_pasn_peer_create_rsp",
    v13,
    v14,
    v15,
    v16,
    a2,
    a4);
  if ( !a1 )
  {
    v28 = "%s: psoc is NULL";
    return qdf_trace_msg(0x53u, 2u, v28, v17, v18, v19, v20, v21, v22, v23, v24, "nan_handle_pasn_peer_create_rsp");
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !result )
  {
    v28 = "%s: psoc_nan_obj is NULL";
    return qdf_trace_msg(0x53u, 2u, v28, v17, v18, v19, v20, v21, v22, v23, v24, "nan_handle_pasn_peer_create_rsp");
  }
  v26 = *(__int64 (__fastcall **)(_QWORD))(result + 32);
  if ( v26 )
  {
    v27 = *(_QWORD *)(result + 304);
    if ( *((_DWORD *)v26 - 1) != 251140989 )
      __break(0x8228u);
    return v26(v27);
  }
  return result;
}
