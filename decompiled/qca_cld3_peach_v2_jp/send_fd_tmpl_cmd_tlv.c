__int64 __fastcall send_fd_tmpl_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v2 = *((_DWORD *)a2 + 2);
  v5 = wmi_buf_alloc_fl(a1, v2 + 16, "send_fd_tmpl_cmd_tlv", 0xF06u);
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 224);
    v7 = v5;
    *v6 = 54788104;
    v6[1] = *a2;
    v6[2] = *((_DWORD *)a2 + 1);
    v6[3] = *((unsigned __int16 *)a2 + 4) | 0x110000;
    qdf_mem_copy(v6 + 4, *((const void **)a2 + 2), *((unsigned int *)a2 + 1));
    qdf_mtrace(49, 100, 0x38Eu, v6[1], 0);
    v16 = wmi_unified_cmd_send_fl(
            a1,
            v7,
            v2 + 16,
            0x700Eu,
            "send_fd_tmpl_cmd_tlv",
            0xF19u,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15);
    if ( v16 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send fd tmpl: %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "send_fd_tmpl_cmd_tlv",
        v16);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v16;
}
