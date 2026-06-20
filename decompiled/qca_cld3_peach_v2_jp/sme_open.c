__int64 __fastcall sme_open(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int inited; // w19
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  unsigned int v21; // w0
  unsigned int v22; // w0

  *(_DWORD *)(a1 + 12768) = 0;
  if ( (unsigned int)qdf_mutex_create(a1 + 12776) )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Init lock failed", v2, v3, v4, v5, v6, v7, v8, v9, "sme_open");
    return 16;
  }
  else
  {
    v11 = csr_open(a1);
    if ( v11 )
    {
      inited = v11;
      v20 = "%s: csr_open failed, status: %d";
    }
    else
    {
      v21 = sme_ps_open(a1);
      if ( v21 )
      {
        inited = v21;
        v20 = "%s: sme_ps_open failed with status: %d";
      }
      else
      {
        v22 = sme_qos_open(a1);
        if ( v22 )
        {
          inited = v22;
          v20 = "%s: Qos open, status: %d";
        }
        else
        {
          inited = init_sme_cmd_list(a1);
          if ( inited )
            return inited;
          inited = rrm_open(a1);
          if ( !inited )
          {
            sme_trace_init(a1);
            ((void (__fastcall *)(__int64, __int64 (__fastcall *)()))qdf_register_debug_callback)(
              52,
              sme_state_info_dump);
            sme_register_power_debug_stats_cb(a1);
            *(_QWORD *)(a1 + 14624) = sme_vdev_delete;
            return inited;
          }
          v20 = "%s: rrm_open failed, status: %d";
        }
      }
    }
    qdf_trace_msg(0x34u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "sme_open", inited);
  }
  return inited;
}
