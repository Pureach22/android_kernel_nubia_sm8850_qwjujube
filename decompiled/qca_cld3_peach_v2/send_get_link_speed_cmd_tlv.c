__int64 __fastcall send_get_link_speed_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  _DWORD *v4; // x21
  __int64 v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // [xsp+0h] [xbp-10h] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = a2;
  v3 = wmi_buf_alloc_fl(a1, 0x14u, "send_get_link_speed_cmd_tlv", 0x10Eu);
  if ( v3 )
  {
    v4 = *(_DWORD **)(v3 + 224);
    v5 = v3;
    *v4 = 17170448;
    qdf_mem_copy(v4 + 1, &v23, 8u);
    wmi_mtrace(0x600Au, v4[4], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v5,
               0x14u,
               0x600Au,
               "send_get_link_speed_cmd_tlv",
               0x121u,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send link speed command",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "send_get_link_speed_cmd_tlv",
        v23,
        v24);
      wmi_buf_free();
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
