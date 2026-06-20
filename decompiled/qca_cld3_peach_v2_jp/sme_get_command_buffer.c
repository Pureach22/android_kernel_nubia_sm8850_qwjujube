__int64 __fastcall sme_get_command_buffer(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 active; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x4
  const char *v15; // x2
  const char *v16; // x3
  unsigned int v17; // w1
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  int v28; // w24
  __int64 v29; // x4
  const char *v30; // x2
  __int64 v31; // x8

  v2 = csr_ll_remove_head(a1 + 12856, 1);
  if ( v2 )
  {
    v3 = v2;
    qdf_mem_set((void *)(v2 + 16), 4u, 0);
    qdf_mem_set((void *)(v3 + 24), 4u, 0);
    qdf_mem_set((void *)(v3 + 32), 0x58u, 0);
    return v3;
  }
  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( !active )
  {
    v15 = "%s: Out of command buffer.... command (0x%X) stuck";
    v16 = "sme_get_command_buffer";
    v17 = 2;
    v14 = 0;
LABEL_12:
    qdf_trace_msg(0x34u, v17, v15, v5, v6, v7, v8, v9, v10, v11, v12, v16, v14);
    goto LABEL_13;
  }
  v13 = active;
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Out of command buffer.... command (0x%X) stuck",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "sme_get_command_buffer",
    *(unsigned int *)(active + 16));
  v14 = *(unsigned int *)(v13 + 16);
  if ( (v14 & 0x10000) != 0 )
  {
    if ( (_DWORD)v14 == 65538 )
    {
      v14 = *(unsigned int *)(v13 + 32);
      v15 = "%s: WMStatusChange command type is %d";
    }
    else if ( (_DWORD)v14 == 65537 )
    {
      v14 = *(unsigned int *)(v13 + 32);
      v15 = "%s: roam command reason is %d";
    }
    else
    {
      v15 = "%s: default: Unhandled command %d";
    }
    v16 = "dump_csr_command_info";
    v17 = 8;
    goto LABEL_12;
  }
LABEL_13:
  v18 = csr_nonscan_pending_ll_peek_head(a1, 0);
  if ( v18 )
  {
    v27 = v18;
    v28 = 1;
    do
    {
      if ( v28 <= 5 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Out of command buffer.... SME pending command #%d (0x%X)",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "sme_get_command_buffer",
          (unsigned int)v28,
          *(unsigned int *)(v27 + 16));
      v29 = *(unsigned int *)(v27 + 16);
      if ( (v29 & 0x10000) != 0 )
      {
        if ( (_DWORD)v29 == 65538 )
        {
          v29 = *(unsigned int *)(v27 + 32);
          v30 = "%s: WMStatusChange command type is %d";
        }
        else if ( (_DWORD)v29 == 65537 )
        {
          v29 = *(unsigned int *)(v27 + 32);
          v30 = "%s: roam command reason is %d";
        }
        else
        {
          v30 = "%s: default: Unhandled command %d";
        }
        qdf_trace_msg(0x34u, 8u, v30, v19, v20, v21, v22, v23, v24, v25, v26, "dump_csr_command_info", v29);
      }
      v27 = csr_nonscan_pending_ll_next(a1, v27, 0);
      ++v28;
    }
    while ( v27 );
  }
  v31 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v31 + 1057) == 1 )
    cds_flush_logs(1u, 2u, 9, 0, *(_BYTE *)(v31 + 1055), v19, v20, v21, v22, v23, v24, v25, v26);
  else
    _cds_trigger_recovery(6, (__int64)"sme_get_command_buffer", 472, v19, v20, v21, v22, v23, v24, v25, v26);
  return 0;
}
