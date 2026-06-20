__int64 __fastcall send_wow_enable_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  int v15; // w9
  const char *v16; // x4
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  unsigned int v26; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_wow_enable_cmd_tlv", 0xC5Cu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 7798796;
  v13[1] = *a2;
  v15 = a2[1];
  v13[2] = v15 ^ 1;
  if ( v15 )
    v16 = "WOW_IFACE_PAUSE_ENABLED";
  else
    v16 = "WOW_IFACE_PAUSE_DISABLED";
  v13[3] = *((_DWORD *)a2 + 1);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: suspend type: %s flag is 0x%x",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_wow_enable_cmd_tlv",
    v16);
  qdf_mtrace(49, 100, 0x984u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x10u,
             0x13004u,
             "send_wow_enable_cmd_tlv",
             0xC73u,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24);
  if ( (_DWORD)result )
  {
    v26 = result;
    wmi_buf_free();
    return v26;
  }
  return result;
}
