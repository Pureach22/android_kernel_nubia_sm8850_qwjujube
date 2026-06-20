__int64 __fastcall csa_event_status_ind_tlv(__int64 a1, __int16 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned int v24; // w20

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "csa_event_status_ind_tlv", 0x22u);
  if ( !v4 )
    return 16;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 79036424;
  v13[1] = (unsigned __int8)a2;
  v13[2] = HIBYTE(a2);
  qdf_trace_msg(0x31u, 8u, "%s: vdev_id: %d status: %d ", v5, v6, v7, v8, v9, v10, v11, v12, "csa_event_status_ind_tlv");
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0xCu,
             0x5036u,
             "csa_event_status_ind_tlv",
             0x32u,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    v24 = result;
    wmi_buf_free();
    return v24;
  }
  return result;
}
