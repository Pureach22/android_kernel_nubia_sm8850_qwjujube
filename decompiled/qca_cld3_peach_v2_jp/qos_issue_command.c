__int64 __fastcall qos_issue_command(__int64 a1, unsigned __int8 a2, unsigned int a3, __int64 a4, int a5, char a6)
{
  __int64 command_buffer; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x20
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x11
  __int64 v26; // x8
  __int64 v27; // x9
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  command_buffer = csr_get_command_buffer(a1);
  if ( !command_buffer )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: fail to get command buffer for command %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "qos_issue_command",
      a3);
    return 1;
  }
  v21 = (_DWORD *)command_buffer;
  *(_DWORD *)(command_buffer + 16) = a3;
  *(_DWORD *)(command_buffer + 24) = a2;
  if ( a3 == 262145 )
  {
    if ( !a4 )
    {
      qdf_trace_msg(0x34u, 2u, "%s: NULL pointer passed", v13, v14, v15, v16, v17, v18, v19, v20, "qos_issue_command");
      qdf_mem_set(v21 + 8, 0x54u, 0);
      csr_release_command(a1, v21, v29, v30, v31, v32, v33, v34, v35, v36);
      return 4;
    }
    v22 = *(_QWORD *)(a4 + 8);
    *(_QWORD *)(command_buffer + 32) = *(_QWORD *)a4;
    *(_QWORD *)(command_buffer + 40) = v22;
    v23 = *(_QWORD *)(a4 + 40);
    v24 = *(_QWORD *)(a4 + 16);
    v25 = *(_QWORD *)(a4 + 24);
    *(_QWORD *)(command_buffer + 64) = *(_QWORD *)(a4 + 32);
    *(_QWORD *)(command_buffer + 72) = v23;
    *(_QWORD *)(command_buffer + 48) = v24;
    *(_QWORD *)(command_buffer + 56) = v25;
    v27 = *(_QWORD *)(a4 + 56);
    v26 = *(_QWORD *)(a4 + 64);
    LODWORD(v25) = *(_DWORD *)(a4 + 72);
    *(_QWORD *)(command_buffer + 80) = *(_QWORD *)(a4 + 48);
    *(_QWORD *)(command_buffer + 88) = v27;
    *(_QWORD *)(command_buffer + 96) = v26;
    *(_DWORD *)(command_buffer + 104) = v25;
    *(_DWORD *)(command_buffer + 108) = a5;
  }
  else
  {
    *(_DWORD *)(command_buffer + 108) = a5;
    *(_BYTE *)(command_buffer + 112) = a6;
  }
  csr_queue_sme_command(a1, (_DWORD *)command_buffer, 0, v13, v14, v15, v16, v17, v18, v19, v20);
  return 0;
}
