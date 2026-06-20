__int64 __fastcall send_dbglog_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x19
  unsigned int v7; // w9
  _DWORD *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  unsigned int v18; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x50u, "send_dbglog_cmd_tlv", 0xD0Au);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 12451848;
  v5[1] = *(_DWORD *)a2;
  v5[2] = *(_DWORD *)(a2 + 4);
  v5[3] = 1048640;
  if ( *(_QWORD *)(a2 + 8) && *(_DWORD *)(a2 + 16) )
  {
    v7 = 0;
    v8 = v5 + 4;
    do
    {
      v8[v7] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL * (int)v7);
      ++v7;
    }
    while ( v7 < *(_DWORD *)(a2 + 16) );
  }
  qdf_mtrace(49, 100, 0xE83u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x50u,
             0x1D003u,
             "send_dbglog_cmd_tlv",
             0xD29u,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16);
  if ( (_DWORD)result )
  {
    v18 = result;
    wmi_buf_free();
    return v18;
  }
  return result;
}
