__int64 __fastcall audio_transport_switch_resp_tlv(__int64 a1, int a2, int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x8
  __int64 v16; // x19
  int v17; // w4
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  unsigned int v27; // w20

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "audio_transport_switch_resp_tlv", 0x58u);
  if ( !v6 )
    return 16;
  v15 = *(_DWORD **)(v6 + 224);
  v16 = v6;
  *v15 = 79822856;
  if ( a3 == 1 )
    v17 = 1;
  else
    v17 = 2 * (a3 != 0);
  v15[1] = v17;
  v15[2] = a2 != 0;
  qdf_trace_msg(0x31u, 8u, "LL_LT_SAP Audio switch type %d status %d", v7, v8, v9, v10, v11, v12, v13, v14);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0xCu,
             0x1D024u,
             "audio_transport_switch_resp_tlv",
             0x6Eu,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    v27 = result;
    wmi_buf_free();
    return v27;
  }
  return result;
}
